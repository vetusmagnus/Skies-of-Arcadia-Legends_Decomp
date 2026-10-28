/* fn_801C9198 (5.3 KB, the ending's picture show) and fn_801C8DF0 (936 bytes, the ending mode
 * that loads it, runs it and frees it): near misses, unit_801C5A60.c.
 *
 *   python tools/match/fdiff.py docs/near/fn_801C9198.c fn_801C9198   (34 lines)
 *   python tools/match/fdiff.py docs/near/fn_801C9198.c fn_801C8DF0   (143 lines)
 *
 * fn_801C9198: instructions exact except a few scheduling lines. Left: in the staff roll the
 * record pointer and the colour swap r21/r22; the layer-6 sprite's float temporaries and load
 * order; and in each caption the `cmpwi` on the caption number comes one load early. Found on
 * the way (see matching.md): the draw helpers are inline functions with `u16` picture/sprite
 * numbers (the `clrlwi 16` truncations), fn_801C8BC0 takes its texture list, sprite and colour
 * before its floats (it still matches that way), the fades test the compound assignment
 * (`if ((a += k) >= 1.0f)`), `counting` is unsigned, the caption's y is `20.0f + y` at each
 * use (no local), and the caption's z is its last parameter.
 *
 * fn_801C8DF0 reaches the unit's .rodata (file names) and .bss through section bases. MWCC
 * pools a .bss section only when a function references at least three objects in it (8-byte
 * objects go to .sbss and don't count), so the draw state, the camera block and the texture
 * slots are three statics here. MWCC lays .bss out in order of first use, and the camera is
 * used before the draw state, so this build puts the camera at +0 and the draw state at +0x20
 * where the original has the draw state at +0 and the camera at +0x28 (the other 100-odd lines
 * follow from that and from the load loops, which the original writes as base + 0x48 + i*8 per
 * iteration). Nothing in the original's .text or data refers to the draw state earlier; a
 * function that the linker dead-stripped would explain it.
 */
#include "../src/game/unit_801C5A60.c" /* found through -i include */
#include "game/drawstate.h"

/* fn_801C9198: the ending's picture show. Pictures fade in and out on two layers (each a
 * 768x512 image drawn as six 256x256 tiles, chosen from the task's picture list), the staff
 * roll scrolls up beside them, and the closing logo and caption fade in at the end. */
typedef struct EndLayer {
    f32 z;      /* 0x00 */
    f32 alpha;  /* 0x04 */
    s32 sel;    /* 0x08: picture, sprite or caption */
    s32 idx;    /* 0x0C: position in the picture list */
    f32 x;      /* 0x10 */
    f32 y;      /* 0x14 */
} EndLayer;

typedef struct EndWork {
    s32 x0;             /* 0x00 */
    u32 wait;           /* 0x04 */
    s32 x8;             /* 0x08 */
    u8 padc[4];
    u32 counting;       /* 0x10 */
    s32 count;          /* 0x14 */
    s32 scrolled;       /* 0x18 */
    f32 speed;          /* 0x1C */
    s32 pics[0x24];     /* 0x20 */
    EndLayer layer[7];  /* 0xB0 */
} EndWork;

typedef struct EndTask {
    u8 pad0[0x18];
    u8 flags;           /* 0x18 */
    u8 state;           /* 0x19 */
    u8 pad1a[0xA];
    EndWork* work;      /* 0x24 */
} EndTask;

typedef struct EndTexSlot {
    u32 x0;
    EndTexList* list;
} EndTexSlot;

typedef struct EndPadState {
    u8 pad0[8];
    u32 x8;
} EndPadState;

typedef struct EndPad {
    EndPadState* pad;
} EndPad;

static DrawState lbl_803084E8;      /* the ending's draw state */
static u8 lbl_80308510[0x20];       /* its camera */
static EndTexSlot lbl_80308530[36]; /* 34 pictures, the logo, the staff roll */
extern void* lbl_803471D8;
extern EndPad lbl_80311A60[];
extern void fn_80217380(s32 a);
extern void* fn_80215F14(s32, s32, s32, s32, s32, s32, const char*);
extern s32 fn_80215F8C(void*);
extern void fn_80215F94(void*);
extern s32 fn_80216F48(void*);

#define END_W (o->work)
#define END_ALPHA(a) (((s32)(255.0f * (a)) << 24) | 0xFFFFFF)

/* A 768x512 picture as six 256x256 tiles (two texture banks, see lbl_802C3F00). */
static inline void EndPicture(u16 img, f32 alpha, f32 z)
{
    u32 col = END_ALPHA(alpha);

    fn_801C8CC0(lbl_80308530[lbl_802C3F00[img][0]].list, (f32*)lbl_802C4120[0], col, lbl_802C3F00[img][1], 1, 0.0f, 0.0f, z);
    fn_801C8CC0(lbl_80308530[lbl_802C3F00[img][0]].list, (f32*)lbl_802C4120[0], col, lbl_802C3F00[img][2], 1, 256.0f, 0.0f, 0.0001f + z);
    fn_801C8CC0(lbl_80308530[lbl_802C3F00[img][0]].list, (f32*)lbl_802C4120[0], col, lbl_802C3F00[img][3], 1, 0.0f, 256.0f, 0.0002f + z);
    fn_801C8CC0(lbl_80308530[lbl_802C3F00[img][0]].list, (f32*)lbl_802C4120[0], col, lbl_802C3F00[img][4], 1, 256.0f, 256.0f, 0.0003f + z);
    fn_801C8CC0(lbl_80308530[lbl_802C3F00[img][5]].list, (f32*)lbl_802C4120[0], col, lbl_802C3F00[img][6], 1, 512.0f, 0.0f, 0.0004f + z);
    fn_801C8CC0(lbl_80308530[lbl_802C3F00[img][5]].list, (f32*)lbl_802C4120[0], col, lbl_802C3F00[img][7], 1, 512.0f, 256.0f, 0.0005f + z);
}

/* A caption: two 256x256 tiles of bank 33, picked by `sel`. */
static inline void EndCaption(u16 sel, f32 alpha, f32 x, f32 y, f32 z)
{
    u32 col = END_ALPHA(alpha);

    switch (sel) {
    case 0:
        fn_801C8CC0(lbl_80308530[33].list, (f32*)lbl_802C4120[0], col, 6, 1, x, 20.0f + y, z);
        fn_801C8CC0(lbl_80308530[33].list, (f32*)lbl_802C4120[0], col, 7, 1, 256.0f + x, 20.0f + y, 0.001f + z);
        break;
    case 1:
        fn_801C8CC0(lbl_80308530[33].list, (f32*)lbl_802C4120[0], col, 8, 1, x, 20.0f + y, z);
        fn_801C8CC0(lbl_80308530[33].list, (f32*)lbl_802C4120[0], col, 9, 1, 256.0f + x, 20.0f + y, 0.001f + z);
        break;
    case 2:
        fn_801C8CC0(lbl_80308530[33].list, (f32*)lbl_802C4120[0], col, 10, 1, x, 20.0f + y, z);
        fn_801C8CC0(lbl_80308530[33].list, (f32*)lbl_802C4120[0], col, 11, 1, 256.0f + x, 20.0f + y, 0.001f + z);
        break;
    }
}

/* One sprite of bank 35 (lbl_802C3C20). */
static inline void EndSprite(u16 n, f32 alpha, f32 z, f32 x, f32 y)
{
    fn_801C8BC0(lbl_80308530[35].list, (Rect8*)&lbl_802C3C20[n], END_ALPHA(alpha), x, y, z);
}

/* The staff roll: fifteen 256x512 strips of bank 35, one under the other. */
static inline void EndStaff(f32 alpha, f32 x, f32 y, f32 z)
{
    u32 col = END_ALPHA(alpha);
    s32 i;

    y = 512.0f - y;
    for (i = 0; i < 15; i++) {
        fn_801C8BC0(lbl_80308530[35].list, (Rect8*)&lbl_802C3C20[i], col, x, y, z);
        y += 512.0f;
    }
}

/* The logo: four 64x64 tiles of bank 34. */
static inline void EndLogo(f32 alpha, f32 z)
{
    u32 col = END_ALPHA(alpha);

    fn_801C8CC0(lbl_80308530[34].list, (f32*)lbl_802C4120[2], col, 0, 1, 32.0f, 32.0f, z);
    fn_801C8CC0(lbl_80308530[34].list, (f32*)lbl_802C4120[2], col, 1, 1, 96.0f, 32.0f, 0.001f + z);
    fn_801C8CC0(lbl_80308530[34].list, (f32*)lbl_802C4120[2], col, 2, 1, 160.0f, 32.0f, 0.002f + z);
    fn_801C8CC0(lbl_80308530[34].list, (f32*)lbl_802C4120[2], col, 3, 1, 224.0f, 32.0f, 0.003f + z);
}



typedef struct EndMdl {
    u8 pad0[4];
    struct { u8 pad0[0x20]; EndTexList* list; }* x4;
} EndMdl;

extern s32 lbl_80311AD4[11];
extern void* lbl_803471E0;
extern void* lbl_803471DC;
extern EndTask* lbl_803471E4;
extern s32 lbl_803475D8;
extern f32 lbl_80346788;
extern f32 lbl_8034678C;
extern void* lbl_803475A8;
extern s32 lbl_80347830;
extern void TextReset(void);
extern void MemCopy(void* dst, const void* src, s32 size);
extern EndMdl* fn_801DB124(void* data);
extern void* fn_801E49D8(const char* path);
extern s32 fn_801E4974(void* bank, s32 i);
extern void* fn_801E4984(void* bank, s32 i);
extern u32 fn_801EF300(void);
extern EndMdl* fn_801C5348(const char* path);
extern void fn_801DBA58(u32 a, u32 b, u32 c);
extern void fn_8028BB90(void* cam);
extern void fn_8022B960(void* cam);
extern void fn_802A75C8(f32, f32, f32);
extern void fn_802A75B0(f32, f32);
extern void fn_8022642C(void);
extern void fn_801DBE6C(s32 n);
extern void fn_802275A4(void* p, s32 n);
extern void fn_80227810(void* p);
extern void* fn_802268E8(void*, void*);
extern void fn_800976F8(void);
extern void fn_801E1D94(void);
extern void fn_801E1CCC(void);
extern void fn_80226170(void);
extern void fn_802281BC(s32 a);
extern void fn_8022DCC4(void);
extern void fn_801DA1C0(void);
extern void njClipZ(f32 near, f32 far);

#define END_MODE (lbl_80311AD4[9])

/* Loads entry i of a bank into a fresh buffer and makes a model of it. */
#define END_LOAD(slot, bank, i)                                                \
    {                                                                          \
        void* bk_ = bank;                                                      \
        s32 sz_ = fn_801E4974(bk_, i);                                         \
        void* buf_ = fn_801E1C7C(sz_);                                         \
        MemCopy(buf_, fn_801E4984(bk_, i), sz_);                               \
        (slot)->x0 = (u32)fn_801DB124(buf_);                                   \
        fn_80227810(((EndMdl*)(slot)->x0)->x4->list);                          \
        (slot)->list = ((EndMdl*)(slot)->x0)->x4->list;                        \
    }

/* The ending: loads the pictures, the logo and the staff roll, runs the picture show
 * (fn_801C9198) and frees it all when it is done. */
void fn_801C9198(EndTask* o);

/* The ending draws with the default 3D state plus attribute 0x100. */
static inline void EndDrawState(void)
{
    DrawStateDefault(1, &lbl_803084E8);
    lbl_803084E8.attr_or |= 0x100;
}

void fn_801C8DF0(void)
{
    s32 i;
    s32 k;

    if (lbl_803475D8 == 1) {
        END_MODE = 3;
    }
    switch (END_MODE) {
    case 0:
        fn_800976F8();
        fn_801E1D94();
        fn_801E1CCC();
        fn_80226170();
        fn_802281BC(0x400);
        fn_8022DCC4();
        fn_801DA1C0();
        lbl_80346788 = -1.0f;
        lbl_8034678C = -10000.0f;
        njClipZ(-1.0f, -10000.0f);
        fn_801DBA58(0xff000000, 0xff000000, 0xff000000);
        fn_8028BB90(lbl_80308510);
        fn_8022B960(lbl_80308510);
        fn_802A75C8(0.0f, 0.0f, 1.0f);
        fn_802A75B0(1.0f, 0.5f);
        EndDrawState();
        lbl_803471E0 = fn_801E49D8(lbl_802C4138);
        lbl_803471DC = fn_801E49D8(lbl_802C4148);
        for (i = 0; i < 0x22; i++) {
            END_LOAD(&lbl_80308530[i], lbl_803471E0, i);
        }
        k = fn_801EF300() & 0x1f;
        END_LOAD(&lbl_80308530[34], lbl_803471DC, k);
        lbl_80308530[35].x0 = (u32)fn_801C5348(lbl_802C415C);
        fn_80227810(((EndMdl*)lbl_80308530[35].x0)->x4->list);
        lbl_80308530[35].list = ((EndMdl*)lbl_80308530[35].x0)->x4->list;
        TextReset();
        END_MODE = 1;
        lbl_803471E4 = fn_802268E8(lbl_803475A8, fn_801C9198);
        lbl_803471E4->work = fn_801E1C7C(0x158);
        break;
    case 1:
        if (lbl_803471E4->state == 0xff) {
            END_MODE = 2;
        }
        fn_8022642C();
        break;
    case 2:
        fn_801DBE6C(3);
        END_MODE = 2;
        lbl_80347830 = 1;
    case 3:
        fn_8022642C();
        fn_8022642C();
        fn_8022642C();
        for (i = 0; i < 0x22; i++) {
            if (lbl_80308530[i].list != NULL) {
                fn_802275A4(lbl_80308530[i].list, 1);
            }
            lbl_80308530[i].list = NULL;
            if (lbl_80308530[i].x0 != 0) {
                fn_801E17E0((void*)lbl_80308530[i].x0);
            }
            lbl_80308530[i].x0 = 0;
        }
        if (lbl_80308530[35].list != NULL) {
            fn_802275A4(lbl_80308530[35].list, 1);
        }
        lbl_80308530[35].list = NULL;
        if (lbl_80308530[35].x0 != 0) {
            fn_801E17E0((void*)lbl_80308530[35].x0);
        }
        lbl_80308530[35].x0 = 0;
        if (lbl_80308530[34].list != NULL) {
            fn_802275A4(lbl_80308530[34].list, 1);
        }
        lbl_80308530[34].list = NULL;
        if (lbl_80308530[34].x0 != 0) {
            fn_801E17E0((void*)lbl_80308530[34].x0);
        }
        lbl_80308530[34].x0 = 0;
        fn_801E17E0(lbl_803471E0);
        lbl_803471E0 = NULL;
        fn_801E17E0(lbl_803471DC);
        lbl_803471DC = NULL;
        fn_801E1D94();
        break;
    }
}

void fn_801C9198(EndTask* o)
{

    if (END_W->counting != 0) {
        END_W->count++;
    }
    if (END_W->speed != 0.0f) {
        END_W->scrolled++;
    }
    switch (o->state) {
    case 0:
    case 0xfe:
        fn_80217380(1);
        lbl_803471D8 = fn_80215F14(1, 44100, 2, 0, 0, 0, lbl_802C4170);
        o->state = 1;
        END_W->count = 0;
        break;
    case 1:
        if (fn_80215F8C(lbl_803471D8) == 1) {
            o->state = 2;
            fn_801CA66C((Tk*)o);
            END_W->x8 = 0;
            END_W->x0 = 0;
            END_W->layer[5].z = 0.1f;
            END_W->layer[5].sel = 0;
            END_W->layer[5].alpha = 0.0f;
            END_W->layer[5].x = 352.0f;
            END_W->layer[5].y = 32.0f;
            END_W->layer[6].z = 0.15f;
            END_W->layer[6].sel = 16;
            END_W->layer[6].alpha = 0.0f;
            END_W->layer[6].x = 352.0f;
            END_W->layer[6].y = -7512.0f;
            END_W->layer[2].z = 0.03f;
            END_W->layer[2].sel = 0;
            END_W->layer[2].alpha = 0.0f;
            END_W->layer[2].x = 0.0f;
            END_W->layer[2].y = 0.0f;
            END_W->layer[3].z = 0.04f;
            END_W->layer[3].sel = 0;
            END_W->layer[3].alpha = 0.0f;
            END_W->layer[3].x = 0.0f;
            END_W->layer[3].y = 0.0f;
            END_W->layer[4].z = 0.05f;
            END_W->layer[4].sel = 0;
            END_W->layer[4].alpha = 0.0f;
            END_W->layer[4].x = 0.0f;
            END_W->layer[4].y = 0.0f;
            END_W->layer[0].z = 0.06f;
            END_W->layer[0].idx = 0;
            END_W->layer[0].sel = END_W->pics[END_W->layer[0].idx];
            END_W->layer[0].alpha = 0.0f;
            END_W->layer[0].x = 0.0f;
            END_W->layer[0].y = 0.0f;
            END_W->layer[1].z = 0.07f;
            END_W->layer[1].idx = 1;
            END_W->layer[1].sel = END_W->pics[END_W->layer[1].idx];
            END_W->layer[1].alpha = 0.0f;
            END_W->layer[1].x = 0.0f;
            END_W->layer[1].y = 0.0f;
            END_W->count = 0;
            END_W->counting = 1;
            END_W->scrolled = 0;
            END_W->speed = 1.0f;
        }
        break;
    case 2:
        END_W->layer[0].alpha += 0.016666668f;
        END_W->layer[5].alpha = END_W->layer[6].alpha = END_W->layer[0].alpha;
        if (END_W->layer[0].alpha >= 1.0f) {
            END_W->layer[0].alpha = 1.0f;
            END_W->layer[5].alpha = END_W->layer[6].alpha = 1.0f;
            o->state = 3;
            END_W->wait = 0xc5;
            fn_80215F94(lbl_803471D8);
        }
        break;
    case 3:
        if (--END_W->wait == 0) {
            if (END_W->layer[1].idx == 0x21) {
                o->state = 6;
            } else if (END_W->layer[1].alpha == 0.0f) {
                o->state = 4;
            } else {
                o->state = 5;
            }
        }
        break;
    case 4:
        if ((END_W->layer[1].alpha += 0.023f) >= 1.0f) {
            END_W->layer[1].alpha = 1.0f;
            o->state = 3;
            END_W->wait = 0xc5;
            END_W->layer[0].idx += 2;
            END_W->layer[0].sel = END_W->pics[END_W->layer[0].idx];
            if (END_W->layer[0].idx == 0x22) {
                END_W->layer[0].sel = 0;
            }
        }
        break;
    case 5:
        if ((END_W->layer[1].alpha -= 0.023f) <= 0.0f) {
            END_W->layer[1].alpha = 0.0f;
            o->state = 3;
            END_W->wait = 0xc5;
            END_W->layer[1].idx += 2;
            END_W->layer[1].sel = END_W->pics[END_W->layer[1].idx];
            if (END_W->layer[1].idx == 0x23) {
                END_W->layer[1].sel = 0;
            }
        }
        break;
    case 6:
        END_W->layer[0].alpha -= 0.01f;
        END_W->layer[5].alpha = END_W->layer[6].alpha = END_W->layer[0].alpha;
        if (END_W->layer[0].alpha <= 0.0f) {
            o->state = 7;
            END_W->layer[0].z = 0.001f;
            END_W->layer[0].sel = 0x21;
            END_W->layer[0].alpha = 0.0f;
            END_W->layer[0].x = 0.0f;
            END_W->layer[0].y = 0.0f;
            END_W->layer[2].z = 0.003f;
            END_W->layer[2].sel = 0;
            END_W->layer[2].alpha = 0.0f;
            END_W->layer[2].x = 48.0f;
            END_W->layer[2].y = 235.0f;
            END_W->layer[3].z = 0.003f;
            END_W->layer[3].sel = 1;
            END_W->layer[3].alpha = 0.0f;
            END_W->layer[3].x = 48.0f;
            END_W->layer[3].y = 235.0f;
            END_W->layer[4].z = 0.004f;
            END_W->layer[4].sel = 1;
            END_W->layer[4].alpha = 0.0f;
            END_W->layer[4].x = 48.0f;
            END_W->layer[4].y = 235.0f;
            END_W->layer[1].z = 0.002f;
            END_W->layer[1].sel = 0x11;
            END_W->layer[1].alpha = 0.0f;
            END_W->layer[1].x = 256.0f;
            END_W->layer[1].y = 176.0f;
        }
        break;
    case 7:
        if ((END_W->layer[0].alpha += 0.01f) >= 1.0f) {
            o->state = 8;
            END_W->layer[0].alpha = 1.0f;
            END_W->wait = 0x10e;
        }
        END_W->layer[2].alpha = END_W->layer[4].alpha = END_W->layer[0].alpha;
        break;
    case 8:
        if (END_W->wait != 0) {
            END_W->wait--;
        } else {
            END_W->layer[2].alpha -= 0.01f;
            END_W->layer[3].alpha += 0.01f;
            if (END_W->layer[2].alpha <= 0.0f) {
                o->state = 9;
                END_W->layer[2].sel = 2;
                END_W->layer[2].alpha = 0.0f;
                END_W->layer[3].alpha = 1.0f;
                END_W->wait = 0x10e;
            }
        }
        break;
    case 9:
        if (END_W->wait != 0) {
            END_W->wait--;
        } else {
            END_W->layer[3].alpha -= 0.01f;
            END_W->layer[2].alpha += 0.01f;
            if (END_W->layer[3].alpha <= 0.0f) {
                o->state = 10;
                END_W->layer[2].alpha = 1.0f;
                END_W->layer[3].alpha = 0.0f;
                END_W->wait = 0x168;
            }
        }
        break;
    case 10:
        if (END_W->wait != 0) {
            END_W->wait--;
        } else {
            END_W->layer[0].alpha -= 0.006666667f;
            END_W->layer[2].alpha = END_W->layer[4].alpha = END_W->layer[0].alpha;
            if (END_W->layer[0].alpha <= 0.0f) {
                END_W->layer[0].alpha = 0.0f;
                o->state = 11;
                END_W->layer[2].alpha = END_W->layer[4].alpha = END_W->layer[0].alpha;
            }
        }
        break;
    case 11:
        if ((END_W->layer[1].alpha += 0.01f) >= 1.0f) {
            END_W->layer[1].alpha = 1.0f;
            o->state = 12;
            END_W->wait = 0x96;
        }
        break;
    case 12:
        if (fn_80216F48(lbl_803471D8) == 0) {
            if (END_W->wait-- == 0) {
                o->state = 13;
                END_W->counting = 0;
            }
        }
        break;
    case 13:
        if ((END_W->layer[1].alpha -= 0.005f) <= 0.0f) {
            o->state = 14;
        }
        break;
    case 14:
        o->state = 0xff;
    case 0xff:
        o->flags |= 0x40;
        return;
    case 15:
        if (lbl_80311A60[0].pad->x8 & 0x100) {
            o->state = 0;
        }
        break;
    }
    switch (o->state) {
    case 2:
    case 3:
    case 4:
    case 5:
        if (END_W->speed != 0.0f) {
            if (END_W->layer[5].y <= 8100.0f) {
                END_W->layer[5].y += END_W->speed;
            } else {
                END_W->speed = 0.0f;
            }
            if (END_W->layer[6].y <= 336.0f) {
                END_W->layer[6].y += END_W->speed;
            }
        }
    case 6:
        EndPicture(END_W->layer[0].sel, END_W->layer[0].alpha, END_W->layer[0].z);
        EndPicture(END_W->layer[1].sel, END_W->layer[1].alpha, END_W->layer[1].z);
        if (END_W->layer[1].sel == 1) {
            EndPicture(END_W->layer[0].sel, END_W->layer[0].alpha, END_W->layer[0].z);
        }
        EndStaff(END_W->layer[5].alpha, END_W->layer[5].x, END_W->layer[5].y, END_W->layer[5].z);
        if (END_W->layer[6].sel >= 0) {
            EndSprite(END_W->layer[6].sel, END_W->layer[6].alpha, END_W->layer[6].z, END_W->layer[6].x,
                      512.0f - END_W->layer[6].y);
        }
        break;
    case 7:
    case 8:
    case 9:
    case 10:
        EndPicture(END_W->layer[0].sel, END_W->layer[0].alpha, END_W->layer[0].z);
        EndLogo(END_W->layer[4].alpha, END_W->layer[4].z);
        EndCaption(END_W->layer[3].sel, END_W->layer[3].alpha, END_W->layer[3].x, END_W->layer[3].y,
                   END_W->layer[3].z);
        EndCaption(END_W->layer[2].sel, END_W->layer[2].alpha, END_W->layer[2].x, END_W->layer[2].y,
                   END_W->layer[2].z);
        break;
    case 11:
    case 12:
    case 13:
        EndSprite(END_W->layer[1].sel, END_W->layer[1].alpha, END_W->layer[1].z, END_W->layer[1].x,
                  END_W->layer[1].y);
        break;
    }
}
