#include "types.h"
#include "game/text.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <dolphin/os.h>
#include <dolphin/dvd.h>
#include "game/task.h"
#include "game/save_8030B7F4.h"
#include "game/stat_8030B4D4.h"
#include "game/gamedata.h"
#include <string.h>
#define PTR(p, off) (*(void**)((u8*)(p) + (off)))
extern void* lbl_803475A8;
extern void* fn_802268E8(void* a, void* cb);
extern void fn_801E17E0(void* p);
typedef struct Sub2_BB28 {
    u8 pad[0x4C];
    void* x4c;
    u32 x50;
} Sub2_BB28;
typedef struct Rec_BB28 {
    void* x0;
    u8 pad4[4];
    u32* x8;
    u32 xc;
    u8 pad10[6];
    s16 x16;
    s16 x18;
    u8 pad1a[0x40 - 0x1A];
    u32 x40;
    u8 pad44[0x4C - 0x44];
} Rec_BB28;
typedef struct Work_BB28 {
    Rec_BB28 r;
    Sub2_BB28* x4c;
    u8 pad50[8];
} Work_BB28;
typedef struct Ent_BB28 {
    Rec_BB28* recs;
    struct { u8 pad[8]; void* x8; }* x4;
    Work_BB28** ptrs;
    u8 xc;              /* 0x0c record count */
    u8 padd[3];
    void* x10;
} Ent_BB28;
typedef struct {
    u16 x0;
    u8 pad2[6];
    u32 x8;
    u8 padc[0x18 - 0xc];
    s32 x18;
    f32 x1c;
    int cur;
    int pad24;
    Ent_BB28* tbl;
} Sys_80309E5C;
extern Sys_80309E5C lbl_80309E5C;
extern s32 lbl_8034733C;
typedef struct {
    s16 id;
    s16 pad;
    void *ptr;
} Ent_80009860;
extern u8 *lbl_80346AA4;
extern void fn_801E17E0(void *);
typedef struct Slot {
    s16 id;
    u8 pad[0xa];
    void* ptr;
} Slot;
#define FLD(p, off, T) (*(T*)((u8*)(p) + (off)))
typedef struct Tk_80009FD8 { u8 pad0[4]; struct Tk_80009FD8* next; u8 pad8[0x10]; u8 flags; } Tk_80009FD8;
typedef struct Sys_80310A1C { u8 pad0[0x18]; u8 f18; } Sys_80310A1C;
extern Tk_80009FD8* lbl_80346A98;
extern s32 lbl_80347370;
extern s32 lbl_8034737C;
extern s16 lbl_8034736A;
extern Sys_80310A1C lbl_80310A1C;
extern s32 lbl_803475D4;
extern s32 lbl_80347704;
extern s32 lbl_80346A90;
extern u32 lbl_80347364;
extern char lbl_802ACC98[];
extern void fn_8002903C(void);
extern void fn_801D6738(void);
extern void fn_8000AA08(void);
extern void fn_8000AA98(void);
extern void fn_801CBBF8(void);
extern void fn_8022642C(void);
extern void fn_801E1D94(void);
extern void fn_801DBE6C(s32);
extern void fn_80228014(void);
extern void fn_80217830(s32);
extern void fn_80100178(char*);
void fn_8000AA58(void);
s32 fn_8000ACE8(void);
void fn_80009FBC(void *p);
extern void (*lbl_802DAE50[])(void);
void fn_80009FD8(void);
extern s32 lbl_803475D8;
extern s32 lbl_80346A94;
extern s16 lbl_80347368;
extern void* lbl_8034731C;
extern s32 lbl_80347380;
extern s32 lbl_80347338;
extern s32 lbl_80347508;
extern s32 lbl_80347518;
extern f32 lbl_80347510;
extern char lbl_803480D8[8];
extern void fn_8002F35C(void);
extern void StvSampLoadBlocking(void);
extern void fn_801DBA58(u32 a, u32 b, u32 c);
extern void fn_8025ECBC(void);
extern void fn_80226170(void);
extern void fn_801CBC30(void);
extern void fn_801C78B8(void);
extern void DrawStateInit(void);
extern void fn_800300DC(void);
extern void fn_80030100(void);
extern void TextReset(void);
extern s32 fn_80065490(void);
extern void fn_8005121C(void);
extern void fn_8002F54C(void);
extern void fn_801CC578(char* s);
extern void fn_80077428(void);
extern void fn_80030ABC(void);
extern void fn_800309C0(void);
extern void fn_800849A8(void);
extern void fn_801D67DC(void);
extern void fn_800308A8(void);
extern void fn_800309E4(void);
extern void fn_8002F6D4(void);
extern void fn_801CBBAC(f32 v);
extern void fn_801CBBD8(void);
extern void fn_80009874(void);
extern s32 lbl_80346A80;

void fn_8000A118(void) {
    if (lbl_803475D8 == 1) {
        lbl_8034737C = 8;
        lbl_80346A94 = 0;
    }
    if (lbl_80347368 != 0) fn_8002F35C();
    switch (lbl_8034737C) {
    case 0:
        lbl_80346A98 = 0;
        if (lbl_80346A94 == 0 && lbl_80347370 != 0) {
            lbl_80346A94 = 1;
            StvSampLoadBlocking();
        }
        fn_801DBA58(0, 0, 0);
        lbl_8034737C = 1;
    case 1:
        lbl_80347704 = 1;
        lbl_8034731C = 0;
        lbl_80346AA4 = 0;
        OSGetTick();
        fn_8025ECBC();
        OSGetTick();
        fn_8025ECBC();
        fn_80226170();
        lbl_80346A98 = fn_802268E8(lbl_803475A8, fn_80009FBC);
        fn_801CBC30();
        fn_801C78B8();
        DrawStateInit();
        fn_800300DC();
        fn_80030100();
        fn_801C78B8();
        TextReset();
        fn_8022642C();
        lbl_80347380 = 0;
        if (lbl_80347370 != 0) {
            lbl_8034737C = 2;
        } else {
            lbl_8034737C = 3;
        }
        break;
    case 2:
        lbl_8034737C = 3;
        break;
    case 11:
        if (fn_8000ACE8() != 0) lbl_8034737C = 12;
        break;
    case 12:
        if (fn_80065490() != 0) lbl_8034737C = 3;
        break;
    case 3:
        fn_8005121C();
        fn_8002F54C();
        fn_801CC578(lbl_803480D8);
        fn_80077428();
        fn_80030ABC();
        fn_800309C0();
        fn_800849A8();
        fn_801D67DC();
        fn_8000AA58();
        lbl_8034733C = 0;
        lbl_80347338 = 0;
        if (lbl_80347370 != 0) StvSampLoadBlocking();
        fn_800308A8();
        lbl_8034737C = 4;
        break;
    case 4:
        fn_800309E4();
        break;
    case 5:
        lbl_802DAE50[lbl_8034733C]();
        fn_800309E4();
        fn_8002F6D4();
        break;
    case 6:
        if (lbl_80347508 != 1) {
            if (lbl_80347518 == 0) {
                fn_801CBC30();
                fn_801CBBAC(7.5f);
                lbl_80347508 = 1;
                lbl_80347510 = 0.0f;
            }
            lbl_8034737C = 7;
        }
        fn_800309E4();
        break;
    case 7:
        if (lbl_80347508 != 1) {
            if (lbl_80347518 == 0) fn_801CBBD8();
            lbl_8034737C = 8;
        }
        fn_800309E4();
        break;
    case 8:
        fn_80009FD8();
        break;
    case 9:
        fn_80009874();
        break;
    case 10:
        break;
    }
}

void fn_80009860(void *v, Ent_80009860 *e)
{
    if (e->id < 0) return;
    e->ptr = v;
}

typedef struct Slot24 { u32 flags; u32 x4; u32 x8; u32 xc; u8 pad10[0x10]; u32 x20; } Slot24;
/* lbl_8030A6D4 entries (0x24 bytes): the pads */
extern Slot24 lbl_8030A6D4[];
extern s32 lbl_8034757C;
extern Tk_80009FD8* lbl_80346A98;
extern s32 lbl_8034737C;
extern Sys_80310A1C lbl_80310A1C;
extern s32 lbl_803475D4;
extern s32 lbl_80347704;
extern s32 lbl_80346A90;
extern s32 lbl_80346A8C;
extern f32 lbl_80346A88;
extern f32 lbl_80346A84;
extern s32 lbl_80346A80;
extern f32 lbl_80347510;
extern s32 lbl_80347508;
extern s32 lbl_80347518;
extern s32 lbl_803474A8;
extern s32 lbl_803472E8;
extern void fn_8002903C(void);
extern void fn_801D6738(void);
extern void fn_8000AA08(void);
extern void fn_8000AA98(void);
extern void fn_801CBBF8(void);
extern void fn_8022642C(void);
extern void fn_801E1D94(void);
extern void fn_801DBE6C(s32);
extern void fn_80228014(void);
extern void fn_80217830(s32);
extern void fn_80100178(char*);
extern void fn_800309E4(void);
extern void fn_801CBA60(f32 a, f32 c);
extern void fn_80219378(char*);
extern s32 fn_80218570(s32 a, s32 b, s32 c);
extern void fn_80009E5C(f32 a, f32 b);
extern void fn_801CBC30(void);
extern void fn_801CBBAC(f32);
extern void fn_801CBBD8(void);
extern void fn_80217B98(void);
extern s8 fn_801010CC(void);
extern int sprintf(char* s, const char* fmt, ...);
extern void StvSampPath(char* buf);
extern s32 fn_801F4D14(void);
extern void fn_802182F4(s32 a, s32 n, ...);

static inline void fn_80009874_end(void) {
    Tk_80009FD8* t;
    fn_8002903C();
    fn_801D6738();
    fn_8000AA08();
    fn_8000AA98();
    fn_801CBBF8();
    if ((t = lbl_80346A98) != 0) {
        do {
            t->flags |= 0x40;
        } while ((t = t->next) != 0);
    }
    fn_8022642C();
    fn_801E1D94();
    fn_80228014();
}

void fn_80009874(void) {
    f32 z;
    char buf[64];
    switch (lbl_80346A90) {
    case 0:
        lbl_80346A90 = 1;
        lbl_80347510 = 0.5f;
        lbl_80346A8C = 60;
        fn_800309E4();
        fn_801CBA60(lbl_80347510, -1.0699999f);
        break;
    case 1:
        lbl_80347510 = 0.5f;
        if (lbl_80346A8C-- > 0) {
            fn_800309E4();
            fn_801CBA60(lbl_80347510, -1.0699999f);
            break;
        }
        fn_80219378("/sound/m0367.mlt");
        fn_80218570(0, 3, 0);
        lbl_80346A90 = 2;
        lbl_80346A84 = -0.010000001f;
        lbl_80346A80 = 0;
    case 2:
        lbl_80347510 = 0.5f;
        TextSetColor(-1);
        z = TextGetZ();
        TextSetZ(-1.02f);
        TextPrintf(0x50, 0x140, "Would you like to try again?");
        TextPrintf(0xa0, 0x168, "I never give up!");
        TextPrintf(0xa0, 0x180, "I quit.");
        TextSetZ(z);
        if (lbl_8030A6D4[lbl_8034757C].xc & 4) {
            lbl_80346A80++;
        }
        if (lbl_8030A6D4[lbl_8034757C].xc & 8) {
            lbl_80346A80--;
        }
        lbl_80346A80 &= 1;
        if (lbl_8030A6D4[lbl_8034757C].x8 & 0x100) {
            lbl_80346A90 = lbl_80346A80 + 3;
            break;
        }
        lbl_80346A88 += lbl_80346A84;
        if (0.0f > lbl_80346A84) {
            if (0.7f > lbl_80346A88) {
                lbl_80346A88 = 0.7f;
                lbl_80346A84 = 0.010000001f;
            }
        } else {
            if (1.0f < lbl_80346A88) {
                lbl_80346A88 = 1.0f;
                lbl_80346A84 = -0.010000001f;
            }
        }
        fn_800309E4();
        fn_801CBA60(lbl_80347510, -1.023f);
        fn_80009E5C(lbl_80346A88, -1.021f);
        break;
    case 4:
        if (lbl_80347508 != 1) {
            if (lbl_80347518 == 0) {
                fn_801CBC30();
                fn_801CBBAC(7.5f);
                lbl_80347508 = 1;
            }
            lbl_80346A90 = 10;
        } else {
            fn_800309E4();
        }
        break;
    case 10:
        if (lbl_80347508 != 1) {
            lbl_80346A90 = 11;
        }
        fn_800309E4();
        break;
    case 11:
        lbl_803475D4 = 1;
        lbl_80310A1C.f18 = 1;
        fn_80100178("ME090A.sct");
        fn_801DBE6C(6);
        lbl_80347704 = 0;
        break;
    case 3:
        if (lbl_80347508 != 1) {
            if (lbl_80347518 == 0) {
                fn_801CBC30();
                fn_801CBBAC(7.5f);
                lbl_80347508 = 1;
            }
            lbl_80346A90 = 20;
        } else {
            fn_800309E4();
        }
        break;
    case 20:
        if (lbl_80347508 != 1) {
            if (lbl_80347518 == 0) {
                fn_801CBBD8();
            }
            lbl_80346A90 = 21;
            fn_80009874_end();
        } else {
            fn_800309E4();
        }
        break;
    case 21:
        lbl_8034737C = 0;
        fn_80217B98();
        fn_80217830(1);
        sprintf(buf, "/sound/m04%02d.samp", fn_801010CC());
        fn_80219378(buf);
        StvSampPath(buf);
        fn_80219378(buf);
        if (lbl_803474A8 == 1) {
            if (fn_801F4D14() == 1) {
                if (lbl_803472E8 == 1) {
                    fn_802182F4(0, 9, 4, 12, 4, 0, 4, 1, 4, 2, 4, 3, 4, 4, 4, 5, 4, 6, 4, 7);
                } else {
                    fn_802182F4(0, 5, 4, 9, 4, 0, 4, 1, 4, 2, 4, 3);
                }
            } else {
                if (lbl_803472E8 == 1) {
                    fn_802182F4(0, 9, 4, 12, 4, 0, 4, 1, 4, 2, 4, 3, 4, 4, 4, 5, 4, 6, 4, 7);
                } else {
                    fn_802182F4(0, 3, 4, 8, 4, 4, 4, 5);
                }
            }
        } else {
            fn_80218570(0, 4, 0);
        }
        lbl_80346A90 = 0;
        break;
    case 100:
        fn_80009874_end();
        break;
    }
}

void fn_80009FBC(void *p)
{
    Task *t = p;
    if (t->state == 0xff) t->flags |= 0x40;
}

void fn_80009800(Slot* list) {
    Slot* s = list;

    for (;;) {
        if (s->id < 0) {
            break;
        }
        if (s->ptr != 0) {
            fn_801E17E0(s->ptr);
        }
        s++;
    }
    fn_801E17E0(list);
}

void fn_80009FD8(void) {
    Tk_80009FD8* t;
    fn_8002903C();
    fn_801D6738();
    fn_8000AA08();
    fn_8000AA98();
    fn_801CBBF8();
    if ((t = lbl_80346A98) != 0) {
        do {
            t->flags |= 0x40;
        } while ((t = t->next) != 0);
    }
    fn_8022642C();
    lbl_8034737C = 0;
    if (lbl_80347370 != 0) {
        fn_801E1D94();
        fn_801DBE6C(7);
        fn_80228014();
        if (lbl_80347364 != 0xffff) fn_80217830(lbl_80347364);
    } else {
        switch (lbl_8034736A) {
        case 2:
            lbl_803475D4 = 1;
            lbl_80310A1C.f18 = 1;
            fn_80100178(lbl_802ACC98);
            fn_801DBE6C(6);
            lbl_80347704 = 0;
            break;
        case 0:
            fn_801E1D94();
            fn_801DBE6C(6);
            lbl_80347704 = 0;
            lbl_80310A1C.f18 = 0;
            break;
        case 1:
            lbl_80346A90 = 0;
            break;
        case 3:
        case 4:
            fn_801E1D94();
            fn_801DBE6C(6);
            lbl_80310A1C.f18 = 1;
            lbl_80347704 = 0;
            break;
        }
    }
}

#ifdef NONMATCHING
#include <dolphin/os/OSFastCast.h>
typedef struct VertexCol {
    f32 x, y, z;
    u32 colour;
} VertexCol;
extern f32 fn_801DBD9C(f32 z);
extern void fn_80290ED4(VertexCol* v, s32 count, s32 flag);
#endif

#ifdef NONMATCHING
void fn_80009E5C(f32 alpha, f32 z) {
    VertexCol v[4];
    u32 col;
    f32 zz;
    u8 a, c;

    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 8);
    if (alpha == 0.0f) {
        col = 0;
    } else {
        a = __OSf32tou8(255.0f * alpha);
        c = __OSf32tou8(64.0f * alpha);
        col = (a << 24) | (c << 16) | (c << 8) | c;
    }
    zz = fn_801DBD9C(z);
    v[0].z = zz;
    v[0].colour = col;
    v[1].z = zz;
    v[1].colour = col;
    v[2].z = zz;
    v[2].colour = col;
    v[3].z = zz;
    v[3].colour = col;
    v[0].x = 160.0f;
    v[0].y = 24.0f * lbl_80346A80 + 360.0f;
    v[1].x = v[0].x;
    v[1].y = 24.0f + v[0].y;
    v[2].x = 204.0f + v[0].x;
    v[2].y = v[0].y;
    v[3].x = v[2].x;
    v[3].y = v[1].y;
    fn_80290ED4(v, 4, 1);
}
#endif
