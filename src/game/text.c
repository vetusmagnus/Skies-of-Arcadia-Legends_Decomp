/* The text queue and the game font (see include/game/text.h and docs/ui.md). The file name is
 * ours. */

#include "game/text.h"
#include "game/util.h"
#include "ninja.h"
#include <dolphin/os.h>
#include <stdarg.h>

extern void fn_8029CB74(void);
extern void fn_80296F28(void);
extern f32 fn_801DBD9C(f32 z);
extern void fn_80235270(void* str, void* image, s32 pos, s32 stride, s32* width);
extern void fn_80234F3C(void* font, void* tmp);
extern void fn_8024FDD0(GXTexObj* obj, void* image, u16 w, u16 h, u32 fmt, u32 ws, u32 wt, u8 mip);
extern void fn_802504A4(GXTexObj* obj, u32 id);
extern void fn_801CC598(void);
extern s32 fn_8023A818(char* path, DVDFileInfo* info);
extern void fn_8023A8E0(DVDFileInfo* info);
extern void fn_8023AB88(DVDFileInfo* info, void* addr, s32 len, s32 offset, void (*cb)(void), s32 prio);
extern void* memcpy(void* dst, const void* src, u32 n);
extern void* memset(void* dst, s32 c, u32 n);
extern void DCStoreRange(void* p, u32 n);
extern s32 fn_8025CC04(char* buf, const char* fmt, va_list ap);
extern void* fn_80005B50(void* heap, s32 size);
extern void fn_80005AD8(void* heap, void* p);
extern s32 strlen(const char* s);

/* These were inlined into their callers (the game is built without auto-inlining). */
inline void TextResetInline(void) {
    text_state.colour = 0xFFC0C0C0;
    text_state.sy = 1.0f;
    text_state.sx = 1.0f;
    text_state.clip_x0 = 0.0f;
    text_state.clip_x1 = screen_width;
    text_state.clip_y0 = 0.0f;
    text_state.clip_y1 = screen_height;
    text_state.z = -1.0699999f;
    text_tail = NULL;
    text_head = NULL;
    text_count = 0;
    text_color_depth = 0;
    memset(text_color_stack, 0, sizeof(text_color_stack));
}

inline void TextColorToGX(volatile GXColor* dst, volatile u8* src) {
    dst->r = src[1];
    dst->g = src[2];
    dst->b = src[3];
    dst->a = src[0];
}

inline u8 TextNextByte(const u8** pp) {
    u8 b = **pp;
    (*pp)++;
    return b;
}

inline u16 TextGetChar(const u8** pp) {
    u16 c;
    u16 code;
    c = **pp;
    code = c;
    if (c < 0x80) {
        (*pp)++;
    } else if (c >= 0x81 && c <= 0x98) {
        (*pp)++;
        code = TextNextByte(pp);
        code |= (u16)(c << 8);
    } else {
        code = 0x8197;
    }
    return code;
}

inline s32 TextCountChars(const u8* str, s32 n) {
    s32 i;
    s32 count;
    const u8* s;
    count = 0;
    s = str;
    for (i = count; i < n; i++) {
        if (*s >= 0x80) {
            i++;
            s++;
        }
        count++;
        s++;
    }
    return count;
}

inline void TextStoreChars(TextNode* node, const u8* p, s32 count) {
    u16* out;
    s32 i;
    node->len = count;
    out = node->text;
    for (i = 0; i < count; i++) {
        *out++ = TextGetChar(&p);
    }
}

inline void TextAppend(TextNode* node) {
    if (text_count != 0) {
        text_tail->next = node;
        text_tail = node;
    } else {
        text_tail = node;
        text_head = node;
    }
    node->next = NULL;
    text_count++;
}

inline TextNode* TextPrintInline(s16 x, s16 y, const char* str) {
    TextNode* node;
    if (str == NULL) {
        return NULL;
    }
    node = TextNodeNew(str);
    if (node != NULL) {
        node->cont = 0;
        node->st = text_state;
        node->st.x = x;
        node->st.y = y;
        TextAppend(node);
    }
    return node;
}

void TextFlush(void) {
    s32 n;
    TextNode* cur;
    TextNode* node;
    if (text_count != 0) {
        n = text_count;
        node = text_head;
        text_pen_x = 0.0f;
        text_pen_y = 0.0f;
        text_line_x = 0.0f;
        njColorBlendingMode(0, 8);
        njColorBlendingMode(1, 6);
        fn_8029CB74();
        GXClearVtxDesc();
        GXSetVtxDesc(9, 1);
        GXSetVtxDesc(0xD, 1);
        GXSetVtxAttrFmt(7, 9, 1, 4, 0);
        GXSetVtxAttrFmt(7, 0xD, 1, 4, 0);
        do {
            cur = node;
            TextDrawNode(node);
            node = node->next;
            fn_80005AD8(heap_main, cur);
        } while (--n > 0);
        fn_80296F28();
        text_count = 0;
        text_state.z = -1.0699999f;
    }
}

void TextDrawGlyph(u16 code, f32* pos, f32* outx, f32* outy) {
    f32 z;
    u8* img;
    void* data;
    s32 rle;
    u8 buf[3];
    s32 width;
    GXColor c;
    f32* q;
    f32 i;
    z = fn_801DBD9C(pos[2]);
    img = glyph_ring + glyph_ring_pos * 0x120;
    if (font_state >= 3) {
        TextGlyphQuad(0, code, 24.0f, 24.0f, pos, glyph_quad, outx, outy);
        data = FontFindGlyph(code, &rle);
        if (data == NULL) {
            return;
        }
        if (rle) {
            FontExpandRle(img, data);
        } else {
            memcpy(img, data, 0x120);
        }
    } else {
        if (code < 0x80) {
            buf[0] = code;
            buf[1] = 0;
        } else {
            *(u16*)buf = code;
        }
        buf[2] = 0;
        memset(img, 0, 0x120);
        fn_80235270(buf, img, 0, 6, &width);
        TextGlyphQuad(1, code, width, 24.0f, pos, glyph_quad, outx, outy);
    }
    fn_8024FDD0(&glyph_texobj, img, 24, 24, 0, 0, 0, 0);
    fn_802504A4(&glyph_texobj, 7);
    DCStoreRange(img, 0x120);
    GXSetNumChans(0);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetTevDirect(0);
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
    GXSetTevOrder(0, 0, 7, 0xFF);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevColorIn(0, 0xF, 2, 8, 4);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 1, 4, 2);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetChanCtrl(4, 0, 0, 0, 0, 2, 2);
    GXSetTevColor(1, text_last_gxcolour);
    GXSetTevColor(2, lbl_80346830);
    q = (f32*)glyph_quad;
    GXBegin(0x80, 7, 4);
    for (i = 0.0f; i < 4.0f; i += 1.0f) {
        GXPosition3f32(q[0], q[1], z);
        GXTexCoord2f32(q[2], q[3]);
        q += 4;
    }
    glyph_ring_pos++;
    glyph_ring_pos &= 0x1FF;
}

void TextDrawNode(TextNode* node) {
    TextGeom g;
    f32 tmp;
    u16* p;
    s32 n;
    u8* src;
    u8* dst;
    s32 i;
    if (text_last_colour != node->st.colour) {
        text_last_colour = node->st.colour;
        TextColorToGX(&text_last_gxcolour, (u8*)&text_last_colour);
    }
    g = *(TextGeom*)&node->st.x;
    if (node->cont == 0) {
        text_line_x = g.x;
        text_pen_x = g.x;
        text_pen_y = g.y;
    } else {
        g.x = text_pen_x;
        g.y = text_pen_y;
    }
    n = node->len;
    p = node->text;
    while (n > 0) {
        if (*p == '\n') {
            g.y = 24.0f * g.sy + g.y;
            g.x = text_line_x;
        } else if (*p == ' ') {
            g.x = 12.0f * g.sx + g.x;
        } else if (*p != 0xFFFF && *p < 0x8890) {
            TextDrawGlyph(*p, &g.x, &g.x, &tmp);
        }
        p++;
        n--;
    }
    text_pen_x = g.x;
    text_pen_y = g.y;
}

void TextGlyphQuad(s32 os, u16 code, f32 w, f32 h, f32* pos, GlyphVtx* v, f32* outx, f32* outy) {
    if (os == 0 && code < 0x80) {
        f32 ch = 24.0f;
        v->x = pos[0];
        v->y = pos[1];
        v->u = code % 2 == 0 ? 0.0f : 0.5f;
        v->v = 0.0f;
        v++;
        v->x = pos[0] + ch * 0.5f;
        v->y = pos[1];
        v->u = 0.5f + v[-1].u;
        v->v = 0.0f;
        v++;
        v->x = v[-1].x;
        v->y = pos[1] + ch;
        v->u = v[-1].u;
        v->v = 1.0f;
        v++;
        v->x = pos[0];
        v->y = v[-1].y;
        v->u = v[-3].u;
        v->v = 1.0f;
    } else {
        f32 u = w / 24.0f;
        v->x = pos[0];
        v->y = pos[1];
        v->u = 0.0f;
        v->v = 0.0f;
        v++;
        v->x = pos[0] + w;
        v->y = pos[1];
        v->u = u;
        v->v = 0.0f;
        v++;
        v->x = v[-1].x;
        v->y = pos[1] + h;
        v->u = u;
        v->v = 1.0f;
        v++;
        v->x = pos[0];
        v->y = v[-1].y;
        v->u = 0.0f;
        v->v = 1.0f;
    }
    *outx = v[-1].x;
    *outy = v[-1].y;
}

void FontExpandRle(u8* dst, u8* src) {
    u32 n;
    u32 j;
    u8 val;
    u8 count;
    for (n = 0; n < 0x120;) {
        count = src[1];
        val = src[0];
        src += 2;
        for (j = 0; j < count; j++) {
            *dst++ = val;
            n++;
        }
    }
}

void* FontFindGlyph(u16 code, s32* rle) {
    FontGlyph* g;
    FontTable* t = font_file->tables;
    u32 i;
    FontRange* r;
    s32 found;
    FontSpecial* sp;
    if (code >= 0x20 && code < 0x80) {
        g = t[0].glyphs + (code - 0x20) / 2;
    } else {
        i = 0;
        r = font_ranges;
        found = 0;
        do {
            if (r->first <= code && code <= r->last) {
                found = 1;
                g = t[r->table].glyphs + (r->base + (code - r->first));
            } else {
                i++;
                r++;
            }
        } while (i < 4 && !found);
        if (!found) {
            i = 0;
            sp = font_specials;
            do {
                if (code == sp->code) {
                    found = 1;
                    g = t[1].glyphs + sp->index;
                } else {
                    i++;
                    sp++;
                }
            } while (i < 15 && !found);
        }
    }
    *rle = g->rle != 0;
    return g->data;
}

TextNode* TextNodeNewN(const char* str, s16 n) {
    s32 count;
    const u8* p;
    u16 code;
    TextNode* node;
    count = 0;
    p = (const u8*)str;
    while ((code = TextGetChar(&p)) != 0) {
        if (code != 0x0A) {
            if (--n <= 0) {
                break;
            }
        }
        count++;
    }
    if (count == 0) {
        return NULL;
    }
    node = fn_80005B50(heap_main, ((count + 1) / 2) * 4 + 0x34);
    if (node == NULL) {
        return NULL;
    }
    TextStoreChars(node, (const u8*)str, count);
    return node;
}

TextNode* TextNodeNew(const char* str) {
    s32 count;
    TextNode* node;
    if (str == NULL) {
        return NULL;
    }
    count = TextCountChars((const u8*)str, strlen(str));
    if (count == 0) {
        return NULL;
    }
    node = fn_80005B50(heap_main, ((count + 1) / 2) * 4 + 0x34);
    if (node == NULL) {
        return NULL;
    }
    TextStoreChars(node, (const u8*)str, count);
    return node;
}

TextNode* TextContinueN(const char* str, s16 n) {
    TextNode* node;
    if (str == NULL) {
        node = NULL;
    } else {
        node = TextNodeNewN(str, n);
        if (node != NULL) {
            node->cont = 0;
            node->st = text_state;
            node->st.x = 0.0f;
            node->st.y = 0.0f;
            TextAppend(node);
        }
    }
    if (node != NULL) {
        node->cont = 1;
    }
    return node;
}

TextNode* TextPrintNumber(s16 x, s16 y, u32 value, u16 flags) {
    char buf[16];
    char* p;
    s32 i;
    u32 div;
    s32 first;
    s32 width;
    s32 start;
    s32 k;
    width = flags & 0x3FFF;
    div = 1000000000;
    p = buf;
    first = -1;
    i = 0;
    for (; div != 0; div /= 10) {
        *p = value / div + '0';
        if (*p != '0' && first < 0) {
            first = i;
        }
        value %= div;
        p++;
        i++;
    }
    if (first < 0) {
        first = i - 1;
    }
    buf[i] = 0;
    start = flags & 0x8000;
    if (start != 0) {
        if (flags & 0x4000) {
            start = i - width;
            if (start < 0) {
                start = 0;
            }
            for (k = start; k < first; k++) {
                buf[k] = ' ';
            }
            if (first < start) {
                start = first;
            }
        } else {
            start = first;
        }
    } else {
        start = i - width;
        if (start < 0) {
            start = 0;
        } else if (first < start) {
            start = first;
        }
    }
    return TextPrintInline(x, y, buf + start);
}

TextNode* TextPrintN(s16 x, s16 y, const char* str, s16 n) {
    TextNode* node;
    if (str == NULL) {
        return NULL;
    }
    node = TextNodeNewN(str, n);
    if (node != NULL) {
        node->cont = 0;
        node->st = text_state;
        node->st.x = x;
        node->st.y = y;
        TextAppend(node);
    }
    return node;
}

TextNode* TextPrint(s16 x, s16 y, const char* str) {
    TextNode* node;
    if (str == NULL) {
        return NULL;
    }
    node = TextNodeNew(str);
    if (node != NULL) {
        node->cont = 0;
        node->st = text_state;
        node->st.x = x;
        node->st.y = y;
        TextAppend(node);
    }
    return node;
}

TextNode* TextPrintf(s16 x, s16 y, const char* fmt, ...) {
    va_list ap;
    char buf[256];
    TextNode* node;
    va_start(ap, fmt);
    fn_8025CC04(buf, fmt, ap);
    if (buf == NULL) {
        return NULL;
    }
    node = TextNodeNew(buf);
    if (node != NULL) {
        node->cont = 0;
        node->st = text_state;
        node->st.x = x;
        node->st.y = y;
        TextAppend(node);
    }
    return node;
}

u8* TextCopyN(u8* dst, const u8* p, s16 n) {
    u16 c;
    u16 code;
    s32 i;
    i = n;
    if (i <= 0) return dst;
    do {
        c = *p;
        code = c;
        if (c < 0x80) {
            p++;
        } else if (c >= 0x81 && c <= 0x98) {
            code = (u8)p[1];
            code |= (u16)(c << 8);
            p += 2;
        } else {
            code = 0x8197;
        }
        if (code >= 0x100) {
            *dst++ = code >> 8;
            *dst++ = code;
        } else {
            *dst++ = code;
        }
        i--;
        if (code == 0) return dst;
    } while (i > 0);
    return dst;
}

s32 TextStrlen(const char* s) {
    return strlen(s);
}

u16 TextReadChar(const u8** pp) {
    u16 code;
    u16 c;
    c = **pp;
    code = c;
    if (c < 0x80) {
        (*pp)++;
    } else if (c >= 0x81 && c <= 0x98) {
        (*pp)++;
        code = TextNextByte(pp);
        code |= (u16)(c << 8);
    } else {
        code = 0x8197;
    }
    return code;
}

void TextGetState(TextState* out) {
    *out = text_state;
}

void TextSetScale(f32 sx, f32 sy) {
    text_state.sx = sx;
    text_state.sy = sy;
}

void TextSetZ(f32 z) {
    text_state.z = z;
}

f32 TextGetZ(void) {
    return text_state.z;
}

void TextSetColor(u32 colour) {
    text_state.colour = colour;
}

void TextPopColor(s32 n) {
    if (n <= 0) {
        return;
    }
    if (text_color_depth - n < 0) {
        return;
    }
    text_color_depth -= n;
    text_state.colour = text_color_stack[text_color_depth];
}

void TextPushColor(void) {
    if (text_color_depth >= 8) {
        return;
    }
    text_color_stack[text_color_depth] = text_state.colour;
    text_color_depth++;
}

void FontRelocate(FontFile* f) {
    u8 magic[4] = {'A', 'F', 'N', 'T'};
    s32 ok;
    u32 i, j;
    FontTable* t;
    FontGlyph* g;
    if (f->magic[0] != magic[0]) {
        ok = 0;
    } else if (f->magic[1] != magic[1]) {
        ok = 0;
    } else if (f->magic[2] != magic[2]) {
        ok = 0;
    } else if (f->magic[3] != magic[3]) {
        ok = 0;
    } else {
        ok = 1;
    }
    if (ok) {
        f->tables = (FontTable*)((u32)f->tables + (u32)f);
        t = f->tables;
        for (i = 0; i < f->ntables; i++) {
            t->glyphs = (FontGlyph*)((u32)t->glyphs + (u32)f);
            g = t->glyphs;
            for (j = 0; j < t->count; j++) {
                g->data = (void*)((u32)g->data + (u32)f);
                g++;
            }
            t++;
        }
    }
}

s32 FontIsReady(void) {
    return font_state >= 3;
}

void TextReset(void) {
    TextResetInline();
}

void FontFree(void) {
    if (font_file != NULL) {
        fn_80005AD8(heap_main, font_file);
        font_file = NULL;
    }
    if (glyph_ring != NULL) {
        fn_80005AD8(heap_main, glyph_ring);
        glyph_ring = NULL;
    }
    if (sdk_font != NULL) {
        fn_80005AD8(heap_font, sdk_font);
        sdk_font = NULL;
    }
    glyph_ring_pos = 0;
    font_state = 0;
}

s32 FontUpdate(void) {
    if (font_state < 3) {
        font_state_funcs[font_state]();
        return 0;
    }
    return 1;
}

void FontStateLoaded(void) {
    fn_8023A8E0(&font_dvd_info);
    FontRelocate(font_file);
    if (sdk_font != NULL) {
        fn_80005AD8(heap_font, sdk_font);
        sdk_font = NULL;
    }
    font_state = 3;
}

void FontStateLoading(void) {
}

void FontStateStart(void) {
    fn_801CC598();
    if (fn_8023A818(font_path, &font_dvd_info)) {
        fn_8023AB88(&font_dvd_info, font_file, 0x13020, 0, FontReadDone, 2);
        font_state = 1;
    }
}

void FontReadDone(void) {
    font_state = 2;
}

void FontInit(void) {
    u32 size;
    u32 tmp;
    glyph_ring_pos = 0;
    font_state = 0;
    font_file = fn_80005B50(heap_main, 0x13020);
    glyph_ring = fn_80005B50(heap_main, 0x24000);
    font_encode = OSGetFontEncode();
    if (font_encode == 1) {
        size = 0x90EE4;
        tmp = 0x4D000;
    } else {
        size = 0x10120;
        tmp = 0x3000;
    }
    sdk_font = fn_80005B50(heap_font, size);
    tmp = (u32)fn_80005B50(heap_font, tmp);
    fn_80234F3C(sdk_font, (void*)tmp);
    fn_80005AD8(heap_font, (void*)tmp);
    TextResetInline();
}
