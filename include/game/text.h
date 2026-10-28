#ifndef GAME_TEXT_H
#define GAME_TEXT_H

#include "types.h"
#include <dolphin/gx.h>
#include <dolphin/dvd.h>

/* The text queue and the game font. Strings are queued during the frame (TextPrint and friends)
 * with a copy of the current text state, and TextFlush draws them all from main. Each glyph comes
 * from the game font ('AFNT', loaded by FontInit/FontUpdate) or, failing that, the SDK font, and is
 * rendered into one of 512 24x24 I4 textures before it's drawn. See docs/ui.md. */

/* The current text settings, copied into every queued string (0x28). */
typedef struct {
    u32 colour;      /* 0x00 */
    f32 x, y, z;     /* 0x04 */
    f32 sx, sy;      /* 0x10 character scale: a space advances 12 * sx, a newline 24 * sy */
    f32 clip_x0;     /* 0x18 clip rectangle, the whole screen by default */
    f32 clip_x1;     /* 0x1C */
    f32 clip_y0;     /* 0x20 */
    f32 clip_y1;     /* 0x24 */
} TextState;

/* A queued string (variable size). */
typedef struct TextNode {
    TextState st;          /* 0x00 */
    s32 cont;              /* 0x28 continue from where the previous string ended */
    struct TextNode* next; /* 0x2C */
    s16 len;               /* 0x30 */
    u16 text[1];           /* 0x32 codes: 0x0A newline, 0x20 space, 0xFFFF skipped, ASCII or Shift-JIS */
} TextNode;

/* Game font file ('AFNT'), pointers relocated in place by FontRelocate. */
typedef struct {
    u16 rle;    /* nonzero: run-length encoded (value, count) pairs */
    u16 pad;
    void* data; /* 0x120 bytes of 24x24 I4, or RLE */
} FontGlyph;

typedef struct {
    FontGlyph* glyphs;
    u32 count;
} FontTable;

typedef struct {
    u8 magic[4];
    u32 pad04;
    FontTable* tables; /* 0x08 */
    u32 ntables;       /* 0x0C */
} FontFile;

typedef struct {
    u16 first, last, table, base;
} FontRange;

typedef struct {
    f32 x, y, u, v;
} GlyphVtx;

typedef struct {
    u16 code, index;
} FontSpecial;

/* The part of TextState after the colour. */
typedef struct {
    f32 x, y, z;
    f32 sx, sy;
    f32 space, line, f20, f24;
} TextGeom;

extern TextState text_state;
extern u32 text_color_stack[8];
extern s32 text_color_depth;
extern s32 text_count; /* queued strings */
extern TextNode* text_tail;
extern TextNode* text_head;
extern void* heap_main;
extern s32 font_state; /* font state: 0 none, 1 loading, 2 loaded, 3 ready */
extern FontFile* font_file; /* font file */
extern u8* glyph_ring; /* glyph texture ring, 512 x 0x120 */
extern s32 glyph_ring_pos; /* ring position */
extern void* sdk_font; /* SDK (IPL) font */
extern u16 font_encode; /* OSGetFontEncode */
extern void* heap_font; /* heap for the SDK font */
extern u32 text_last_colour; /* last colour */
extern GXColor text_last_gxcolour; /* last colour as GXColor */
extern f32 text_pen_x; /* pen x */
extern f32 text_pen_y; /* pen y */
extern f32 text_line_x; /* line start x */
extern GXColor lbl_80346830;
extern s32 screen_width;
extern s32 screen_height;
extern DVDFileInfo font_dvd_info;
extern GlyphVtx glyph_quad[4];
extern GXTexObj glyph_texobj;
extern FontRange font_ranges[4];
extern FontSpecial font_specials[15];
extern void (*font_state_funcs[3])(void);
extern char font_path[];

void FontReadDone(void);
void TextFlush(void);
void TextDrawGlyph(u16 code, f32* pos, f32* outx, f32* outy);
void TextDrawNode(TextNode* node);
void TextGlyphQuad(s32 os, u16 code, f32 w, f32 h, f32* pos, GlyphVtx* v, f32* outx, f32* outy);
void FontExpandRle(u8* dst, u8* src);
void* FontFindGlyph(u16 code, s32* rle);
TextNode* TextNodeNewN(const char* str, s16 n);
TextNode* TextNodeNew(const char* str);
TextNode* TextContinueN(const char* str, s16 n);
TextNode* TextPrintNumber(s16 x, s16 y, u32 value, u16 flags);
TextNode* TextPrintN(s16 x, s16 y, const char* str, s16 n);
TextNode* TextPrint(s16 x, s16 y, const char* str);
TextNode* TextPrintf(s16 x, s16 y, const char* fmt, ...);
u8* TextCopyN(u8* dst, const u8* p, s16 n);
s32 TextStrlen(const char* s);
u16 TextReadChar(const u8** pp);
void TextGetState(TextState* out);
void TextSetScale(f32 sx, f32 sy);
void TextSetZ(f32 z);
f32 TextGetZ(void);
void TextSetColor(u32 colour);
void TextPopColor(s32 n);
void TextPushColor(void);
void FontRelocate(FontFile* f);
s32 FontIsReady(void);
void TextReset(void);
void FontFree(void);
s32 FontUpdate(void);
void FontStateLoaded(void);
void FontStateLoading(void);
void FontStateStart(void);
void FontReadDone(void);
void FontInit(void);

#endif
