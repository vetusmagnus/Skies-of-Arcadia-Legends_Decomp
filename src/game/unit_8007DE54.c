#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <math.h>
#include "game/task.h"
#include "game/save_8030B7F4.h"
#include "game/stat_8030B4D4.h"
#include "game/gamedata.h"
#include "game/unit_80074D9C.h"
extern void fn_8006B774(void* p);
extern s16 lbl_80302BF0[];
extern s8 lbl_80347334;
extern ChrState lbl_80309174[12];
extern PosTbl lbl_803097F0;
extern MdlTask *fn_80021658(s8 i);
extern struct Slot;
extern Slot *lbl_80309700[12];
extern s32 fn_80081FEC(s16 i);
extern s32 fn_80083BAC(s32 a, s32 b);
extern Chr_UNIT0000* lbl_80309DE4[12];
void *fn_8006C9AC(void *root, s32 target);
typedef struct R16 {
    s32 w0;
    s8 b4;
    u8 pad_5[0x1];
    s16 h6;
    u8 b8;
    s8 b9;
    s8 xa;
    u8 pad_b[0x2];
    s8 xd;
    u8 pad_e[0x2];
} R16;
extern R16 lbl_80309730[];
extern s32 fn_80078610(s8 idx);
extern void fn_8007DE54(Obj_8007DE54 *p);
extern void *lbl_803475A8;
extern void *lbl_8034736C;
extern void *fn_802268E8(void *, void *);
typedef struct Map_800840BC { u8 pad0[0x24]; u8* cells; } Map_800840BC;
extern void fn_802AC710(void* dst, void* src, int n);
extern void* fn_801E1C7C(int size);
extern void fn_80217830(s32 arg);
extern s32 lbl_8034733C;
extern s32 lbl_80347348;
extern s16 lbl_80347374;
extern void fn_800801A8(Slot *);
s32 fn_80080278(Slot* t);
void fn_800840BC(void);
extern void fn_80010CF4(void);
extern void fn_80084570(void);
extern void fn_800842A0(s16 idx);
void fn_800804B8(Slot* t);
extern void fn_80010474(s16 i);
extern void fn_80085414(s32 i);
extern u8* lbl_80347354;
extern u8* lbl_80347350;
extern u8 lbl_80347340;
extern void fn_80086C48(Slot *);
typedef struct { s8 x0; u8 pad1[3]; s32 x4; s32 x8; } E12;
extern E12 lbl_80302C08[12];
extern void fn_800839D8(s32 a, void *p, s32 b);
extern s32 lbl_80302C98[8];
extern s32 rand(void);
typedef struct Hdr { void* x0; } Hdr;
typedef struct Rec {
    void* x0;
    u8 pad4[4];
    struct Hdr* x8;
    u8 padc[4];
    void* x10;
    u8 pad14[2];
    s16 x16;
    s16 x18;
    u8 pad1a[0x40 - 0x1a];
    void* x40;
    u8 pad44[0x4c - 0x44];
} Rec;
typedef struct Src8 { u8 pad0[8]; s32* x8; } Src8;
typedef struct Ent_8007E13C { Rec* recs; Src8* src; u8 pad8[4]; u8 count; u8 pad0d[7]; } Ent_8007E13C;
typedef struct G_8007E13C {
    u8 pad0[8];
    u32 flags;
    u8 pad0c[4];
    f32 f10;
    f32 f14;
    u8 pad18[8];
    s32 idx;
    u8 pad24[4];
    Ent_8007E13C* tab;
} G_8007E13C;
typedef struct Arg { u8 pad0[0xc]; Rec* recs; } Arg;
extern G_8007E13C lbl_80309E5C;
extern void fn_8007E9E0(u8 i);
extern void fn_8002DD8C(s16 a, s32 b, s8 c);
extern s16 lbl_8034734E;
extern u8 lbl_80309300[0x400];
extern s32 fn_80082AC0(s8 x, s8 y, u8* grid, s32 k);
extern s32 fn_8008328C(void* a, void* b, s8 x, s8 y);
extern Lim* lbl_80347390;
typedef struct Eff {
    u8 pad0[0xC];
    f32 xc;
    f32 x10;
    u8 pad14[0x40 - 0x14];
    s32 x40;
    s32 x44;
    f32 x48;
} Eff;
typedef struct Wk_8007E88C { u8 pad0[8]; void* x8; u8 pad[0x4C - 0xC]; Eff* eff; } Wk_8007E88C;
typedef struct Tk_8007E88C { u8 pad[0x19]; u8 state; u8 pad1a[0x24 - 0x1A]; Wk_8007E88C* work; } Tk_8007E88C;
typedef struct Tbl {
    u8 pad0[8];
    u32 flags;
    u8 padc[0x14 - 0xC];
    f32 x14;
    s32 x18;
    f32 x1c;
} Tbl;
extern int fn_80018B80(void*);
extern void fn_80018C94(void);
extern void fn_800342BC(void*);
int fn_80082840(s8 x, s8 y, u8 c, u8* grid, s32 idx);
typedef struct Obj24 {
    u8 pad0[0xE];
    u8 xe;
    u8 pad0f[7];
    u8 x16;
} Obj24;
typedef struct Obj {
    u8 pad0[0x24];
    Obj24* d;
} Obj;
typedef struct Slot_80083728 {
    u8 pad0[0xAE];
    s16 flags;
} Slot_80083728;
extern s32 fn_80083558(s32 a, s32 b);
extern s32 fn_80083398(s32 a, s32 b);
extern s32 fn_80082D8C(s32 a, s32 b);
extern void fn_8006CF28(Sub74E2C *, Loc74E2C **, s32);
extern s32 fn_80227810(void *);
typedef struct Wk_8007E690 { void* x0; u32 x4; void* x8; u8 padc[0x4C - 0xC]; Eff* eff; } Wk_8007E690;
typedef struct Tk_8007E690 { u8 pad[0x19]; u8 state; u8 pad1a[0x24 - 0x1A]; Wk_8007E690* work; } Tk_8007E690;
typedef struct Tbl_8007E690 {
    u8 pad0[8];
    u32 flags;
    u8 padc[0x10 - 0xC];
    f32 x10;
    u8 pad14[4];
    s32 x18;
    f32 x1c;
} Tbl_8007E690;
typedef struct Pos_8007E690 { u8 pad0[8]; f32 x8; f32 xc; f32 x10; } Pos_8007E690;
extern void sndAuxCallbackShutdownReverbSTD(void* a, Pos_8007E690** out);
extern int fn_80011E50(NJS_POINT3* v, f32* out, int flag);
extern s16 lbl_80309DCC[12];
extern s32 fn_8007FFE8(s32 i, u32 k);
void fn_800811E4(s16 id, int mode);
extern s32 fn_80010340(s32 i);
extern void fn_80087054(Slot*);
u8 fn_80078478(int a);
extern s32 fn_8007EBBC(s32 a, s32 b, s32 k, s32 st);
extern s32 fn_8007F270(s32 a, s32 b, s32 k, s32 st);
extern void fn_80082134(s16 v);
extern int fn_8006D1C4(void);
extern s16 fn_80010CBC(s32 id);
typedef struct Blob { u32 w[16]; } Blob;
typedef struct Req_8007DFC0 {
    s16 a;          /* 0x00 */
    s16 b;          /* 0x02 */
    Blob data;      /* 0x04 */
} Req_8007DFC0;
typedef struct Cmd_8007DFC0 { u8 pad[0xC]; Req_8007DFC0* req; } Cmd_8007DFC0;
typedef struct Rec_8007DFC0 {
    void* x0;
    u8 pad4[0x48];
    struct Rec2* x4c;
} Rec_8007DFC0;
typedef struct Rec2 {
    u8 pad0[4];
    s16 x4;
    u8 pad6[6];
    Blob x0c;
} Rec2;
typedef struct Node_8007DFC0 { u8 pad[0x24]; Rec_8007DFC0* work; } Node_8007DFC0;
extern s32 fn_800300C4(s16);
extern void fn_80061F58(void*, int, int);
typedef struct Wk_E9E0 {
    Rec item;
    void* x4c;
    u8 pad50[8];
} Wk_E9E0;
typedef struct Node_8007E9E0 { u8 pad[0x24]; Wk_E9E0* work; } Node_8007E9E0;
extern void fn_8022F00C(void*);
extern void fn_8022F030(void*, int, int);
typedef struct Rec_8007DEE0 {
    void* x0;
    u8 pad4[0x4c - 4];
} Rec_8007DEE0;
typedef struct Ent_8007E13C_8007DEE0 { Rec_8007DEE0* recs; Src8* src; u8 pad8[4]; u8 count; u8 pad0d[7]; } Ent_8007E13C_8007DEE0;
typedef struct G_8007E13C_8007DEE0 {
    u8 pad0[8];
    u32 f8;
    u8 pad0c[0x14];
    s32 idx;
    u8 pad24[4];
    Ent_8007E13C_8007DEE0* tab;
} G_8007E13C_8007DEE0;
typedef struct Pos { u8 pad0[4]; s16 x4; s16 x6; } Pos;
typedef struct Wk_8007DEE0 { void* x0; u8 pad4[0x4c - 4]; Pos* pos; u8 pad50[8]; } Wk_8007DEE0;
typedef struct Tk_8007DEE0 { u8 pad0[0x24]; Wk_8007DEE0* work; } Tk_8007DEE0;
typedef struct Spawn { s16 i; s16 x2; s16 x4; s16 x6; } Spawn;
typedef struct ArgDEE0 { u8 pad0[0xc]; Spawn* sp; } ArgDEE0;
void fn_80081350(Wk* o, s16 id, s16 n, s8 x, s8 y);
typedef struct Shape {
    u8 pad0[0xAC];
    s8 w;
    s8 h;
} Shape;
typedef struct Pos_80083878 {
    u8 pad0[0xC];
    s8 x;
    s8 y;
} Pos_80083878;
typedef struct Tk_80083878 {
    u8 pad0[0x24];
    Pos_80083878* work;
} Tk_80083878;
typedef struct Out {
    s32 x0;
    s32 max;
    s32 score;
} Out;
typedef struct Pos_800855AC {
    u8 pad0[0x14];
    s8 x14;
} Pos_800855AC;
typedef struct Tk_800855AC {
    u8 pad0[0x24];
    Pos_800855AC* work;
} Tk_800855AC;
typedef struct Chr_UNIT0000_800855AC {
    u8 pad0[0x1C];
    u32 w1c;
} Chr_UNIT0000_800855AC;
extern s32 fn_80083728(s32 a, s32 b);
extern s32 fn_80082340(s32 a);
extern s32 fn_80083C50(s32 a, s32 b);
typedef struct ChrState_80088E4C {
    s32 x0;
    u8 pad4[0x1C];
} ChrState_80088E4C;
extern char lbl_802B0C80[];
extern void fn_801DBE1C(const char* fmt, ...);
typedef struct Chr_80089074 {
    u8 pad[0x1c];
    u32 w1c;
    u8 pad20[0x82 - 0x20];
    s16 x82;
} Chr_80089074;
typedef struct Chr_800899C0 {
    u8 pad[0xe];
    s16 xe;
} Chr_800899C0;
extern s32 fn_80089EC8(s32 a);
typedef struct Chr_80089AA0 {
    u8 pad[0x88];
    s16 x88;
    u8 pad8a[0x94 - 0x8a];
    s16 x94;
    s16 x96;
} Chr_80089AA0;
extern void fn_801E17E0(void *p);
typedef struct Anim {
    u16 cur;   /* 0x00 */
    u16 max;   /* 0x02 */
    s16 v[1];  /* 0x04 */
} Anim;
typedef struct Work {
    void *snd;      /* 0x00 */
    u8 pad04[0x48];
    Anim *anim;     /* 0x4C */
} Work;
extern void fn_802307EC(void *p, s16 *v, s32 n);
s32 fn_800824F0(u8 *pos, s8 val, u8 *grid, u8 *dir);
void* fn_801E1A74(s32 count, s32 size);
extern u32 fn_801F52AC(void);
void fn_80081168(s16 idx, s32 val);
int fn_8007FAB0(int a, int b);
extern s32 fn_800683D8(s16 a, s16 b, s32 c, s8 d);
extern void fn_8008BE94(Slot *);
extern void fn_8008178C(Wk* d, s8 a, s8 b, s32 id);
extern void fn_8008066C(s32);
void fn_80081648(Wk* d, s16 id);
void fn_800810FC(s16 idx);

#define NODE_OP(n)                     \
    switch (op) {                      \
    case 0: (n)->flags |= mask; break; \
    case 1: (n)->flags &= mask; break; \
    case 2: (n)->flags ^= mask; break; \
    }

void fn_8007E118(u8* p) {
    fn_8006B774(*(void**)(p + 0xc));
}

s32 fn_8007E264(f32* p) {
    *p = 0.0f;
    return 1;
}

void fn_8007E414(s32 on) {
  if (on) {
    lbl_80309E5C.flags |= 0x04000000;
  } else {
    lbl_80309E5C.flags &= ~0x04000000;
  }
}

typedef struct E0D8Anim {
    u16 cur;
    u16 end;
    s16 sub;
    u8 pad6[2];
    u32 val;
    u8 mat[0x14];
    void *p20;
    u8 pad24[8];
    void *p2c;
} E0D8Anim;
typedef struct E0D8Obj {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1A[10];
    struct { void *p0; u8 pad4[0x48]; E0D8Anim *anim; } *inner;
} E0D8Obj;
extern void fn_80230634(void *, void *);
extern void fn_80230280(void *, void *);
extern s32 fn_800179E4(s16);
extern void fn_8022FDA0(f32, void *, void *);
extern void fn_801E17E0(void* p);
void fn_8007E4F8(E0D8Obj *obj) {
    E0D8Anim *a;
    void *p;
    p = obj->inner->p0;
    a = obj->inner->anim;
    if (p == 0) {
        obj->state = 3;
    }
    switch (obj->state) {
    case 0:
        if (a->cur >= a->end) {
            obj->state = 1;
            a->val = *(u32 *)((u8 *)p + 4);
        } else {
            a->cur = a->cur + 1;
        }
        break;
    case 1:
        fn_80230634(p, a->mat);
        fn_80230280(p, a->mat);
        obj->state = 2;
        break;
    case 2:
        if (a->sub >= 0 && fn_800179E4(a->sub) == 0) {
            obj->state = 3;
        }
        fn_8022FDA0((f32)a->cur, p, a->mat);
        a->cur += 1.0f;
        break;
    case 3:
        if (a->p20 != 0) {
            fn_801E17E0(a->p20);
        }
        if (a->p2c != 0) {
            fn_801E17E0(a->p2c);
        }
        obj->flags |= 0x40;
        break;
    }
}
extern s32 fn_80078354(s32 i);
extern s32 fn_80078370(s32 i);
extern s32 fn_8007838C(s32 i);

void fn_8007F00C(s32 a, s32 b)
{
    s32 v;
    switch (lbl_80309174[a].x0) {
    case 3:
    case 8:
        v = 0;
        break;
    case 5:
        v = fn_80078370(lbl_80309174[a].x6);
        break;
    case 12:
        v = fn_80078354(a);
        v = fn_80078354(v);
        break;
    case 2:
        v = fn_8007838C(lbl_80309174[a].x6);
        break;
    }

    if (fn_80078610(b) != 0) {
        if (lbl_80309DE4[b]->w1c & 0x40) {
            switch (v) {
            case 3: case 4: case 5:
            case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14:
            case 0x1a:
            case 0x3e:
            case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49:
                lbl_80309700[b]->work->x50 = 5;
                return;
            }
        }
        lbl_80309700[b]->work->flags |= 0x20;
        lbl_80309700[b]->work->x50 = 4;
        fn_80082134(b);
        if (a != b) {
            lbl_80309730[b].b9 = 0;
        }
    } else if (lbl_80309DE4[b] != 0 && lbl_80309700[b] != 0) {
        switch (v) {
        case 0x27:
        case 0x1b:
        case 0x1c:
        case 0x2f:
            fn_80082134(b);
            if (a != b) {
                lbl_80309730[b].b9 = 0;
            }
            break;
        default:
            lbl_80309700[b]->work->x3c = 0;
            lbl_80309700[b]->work->x40 = 0;
            lbl_80309700[b]->work->x44 = -1;
            lbl_80309700[b]->work->x46 = -1;
            lbl_80309700[b]->work->x48 = -1;
            lbl_80309700[b]->work->x4a = -1;
            break;
        }
    }
}

void fn_8007E678(s32 a, u32* b) {
    b[0] |= 0x800;
    b[2] = 0x800;
}

s32 fn_8007EB74(s32 i) {
    s32 r = 0;
    Slot* t = lbl_80309700[i];
    if (t != 0) {
        r = t->work->x3c;
    }
    return r;
}

#define CLEAR(b)                          \
    lbl_80309700[b]->work->x3c = 0;       \
    lbl_80309700[b]->work->x40 = 0;       \
    lbl_80309700[b]->work->x44 = -1;      \
    lbl_80309700[b]->work->x46 = -1;      \
    lbl_80309700[b]->work->x48 = -1;      \
    lbl_80309700[b]->work->x4a = -1

extern void fn_8007F00C(s32 a, s32 b);

s32 fn_8007EBBC(s32 a, s32 b, s32 c, s32 d) {
    s32 ret = 0;
    s32 i;
    u32 v;
    switch (c) {
    case 1:
    case 3:
        if (lbl_80309700[b]->work->x50 != 3 && lbl_80309700[b]->work->x50 != 1) break;
        ret = 1;
        if (lbl_80309174[a].x6 == 0x53) {
            fn_8007F00C(a, b);
            lbl_80309700[b]->work->x50 = 5;
            lbl_80309730[b].b9 = 1;
        } else {
            fn_8007F00C(a, b);
        }
        break;
    case 0:
        ret = 1;
        fn_8007F00C(a, b);
        break;
    case 5:
        fn_8007F00C(a, b);
        ret = 1;
        break;
    case 2:
        for (i = 0; i <= 3; i++) {
            if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
        }
        for (i = 0; i <= 3; i++) fn_8007F00C(a, i);
        ret = 1;
        break;
    case 4:
        for (i = 4; i <= 11; i++) {
            if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
        }
        for (i = 4; i <= 11; i++) fn_8007F00C(a, i);
        ret = 1;
        break;
    case 6:
        if (d == 8) {
            v = fn_801F52AC();
            if (v & 0xff00) {
                for (i = 0; i <= 3; i++) {
                    if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
                }
                for (i = 0; i <= 3; i++) fn_8007F00C(a, i);
            }
            if (v & 0xff) {
                for (i = 4; i <= 11; i++) {
                    if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
                }
                for (i = 4; i <= 11; i++) fn_8007F00C(a, i);
            }
            ret = 1;
        } else {
            for (i = 0; i <= 11; i++) {
                if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
            }
            for (i = 0; i <= 11; i++) fn_8007F00C(a, i);
            ret = 1;
        }
        break;
    default:
        if (c >= 0x20 && c < 0x60) {
            for (i = 4; i <= 11; i++) {
                if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
            }
            for (i = 4; i <= 11; i++) fn_8007F00C(a, i);
            ret = 1;
        } else if (c >= 0x60) {
            for (i = 0; i <= 3; i++) {
                if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
            }
            for (i = 0; i <= 3; i++) fn_8007F00C(a, i);
            ret = 1;
        } else {
            ret = 1;
        }
        break;
    }
done:
    return ret;
}

extern void fn_80082134(s16 v);
extern void fn_8007F6E4(s32 a, s32 b);

s32 fn_8007F270(s32 a, s32 b, s32 c, s32 d) {
    s32 ret = 0;
    s32 i;
    u32 v;
    switch (c) {
    case 1:
    case 3:
        if (lbl_80309700[b]->work->x50 != 3 && lbl_80309700[b]->work->x50 != 1) break;
        ret = 1;
        fn_8007F6E4(a, b);
        break;
    case 0:
        ret = 1;
        fn_80082134(b);
        break;
    case 5:
        if (!(lbl_80309DE4[a]->w1c & 0x18)) {
            fn_80082134(a);
        } else {
            lbl_80309700[a]->work->x3c = 0;
            lbl_80309700[a]->work->x40 = 0;
            lbl_80309700[a]->work->x44 = -1;
            lbl_80309700[a]->work->x46 = -1;
            lbl_80309700[a]->work->x48 = -1;
            lbl_80309700[a]->work->x4a = -1;
        }
        ret = 1;
        break;
    case 2:
        for (i = 0; i <= 3; i++) {
            if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
        }
        for (i = 0; i <= 3; i++) fn_8007F6E4(a, i);
        ret = 1;
        break;
    case 4:
        for (i = 4; i <= 11; i++) {
            if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
        }
        for (i = 4; i <= 11; i++) fn_8007F6E4(a, i);
        ret = 1;
        break;
    case 6:
        if (d == 8) {
            v = fn_801F52AC();
            if (v & 0xff00) {
                for (i = 0; i <= 3; i++) {
                    if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
                }
                for (i = 0; i <= 3; i++) fn_8007F6E4(a, i);
            }
            if (v & 0xff) {
                for (i = 4; i <= 11; i++) {
                    if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
                }
                for (i = 4; i <= 11; i++) fn_8007F6E4(a, i);
            }
            ret = 1;
        } else {
            for (i = 0; i <= 11; i++) {
                if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
            }
            for (i = 0; i <= 11; i++) fn_8007F6E4(a, i);
            ret = 1;
        }
        break;
    default:
        if (c >= 0x20 && c < 0x60) {
            for (i = 4; i <= 11; i++) {
                if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
            }
            for (i = 4; i <= 11; i++) fn_8007F6E4(a, i);
            ret = 1;
        } else if (c >= 0x60) {
            for (i = 0; i <= 3; i++) {
                if (fn_80078610(i) && lbl_80309700[i]->work->x50 != 3 && lbl_80309700[i]->work->x50 != 1) goto done;
            }
            for (i = 0; i <= 3; i++) fn_8007F6E4(a, i);
            ret = 1;
        } else {
            ret = 1;
        }
        break;
    }
done:
    return ret;
}
s32 fn_8007838C(s32 i);

void fn_8007F6E4(s32 a, s32 b)
{
    if (fn_80078610(b) && (lbl_80309DE4[b]->w1c & 8)) {
        lbl_80309700[b]->work->x50 = 5;
    } else if (fn_80078610(a) && (lbl_80309DE4[a]->w1c & 0x200)) {
        if (lbl_80309700[b] != 0) {
            lbl_80309700[b]->work->x50 = 5;
        }
    } else if (fn_80078610(b)) {
        if (lbl_80309DE4[b]->w1c & 0x40) {
            switch (fn_8007838C(lbl_80309174[a].x6)) {
            case 3:
            case 5:
            case 7:
            case 9:
            case 0xb:
            case 0xc:
            case 0xe:
            case 0x1a:
                lbl_80309700[b]->work->x50 = 5;
                return;
            case 4:
            case 0xa:
            case 0xd:
            case 0x3e:
            case 0x48:
            case 0x49:
                break;
            }
        }
        lbl_80309700[b]->work->flags |= 0x20;
        lbl_80309700[b]->work->x50 = 4;
        if (!(lbl_80309DE4[b]->w1c & 0x18)) {
            fn_80082134(b);
            if (a != b) {
                lbl_80309730[b].b9 = 0;
            }
        } else {
            lbl_80309700[b]->work->x50 = 5;
            CLEAR(b);
        }
    } else if (lbl_80309DE4[b] != 0 && lbl_80309700[b] != 0) {
        switch (fn_8007838C(lbl_80309174[a].x6)) {
        case 0x1b:
        case 0x1c:
        case 0x2f:
            if (!(lbl_80309DE4[b]->w1c & 0x18)) {
                fn_80082134(b);
                if (a != b) {
                    lbl_80309730[b].b9 = 0;
                }
            } else {
                lbl_80309700[b]->work->x50 = 5;
                CLEAR(b);
            }
            break;
        default:
            CLEAR(b);
            break;
        }
    }
}

s16 fn_8007FCF0(s32 i) {
    return fn_80021658(i)->work->u->x6;
}

s32 fn_8007FD20(s32 idx)
{
    s32 lv;

    if (lbl_8034733C == 4) {
        return 0;
    }
    if (fn_8006D1C4() == 1) {
        lv = fn_80078478(lbl_80347334);
        if (fn_80078610(idx) == 0) {
            lbl_80309730[idx].b9 = 1;
            return 1;
        }
        if (lv > 6) {
            switch (fn_80021658(idx)->work->u->x6) {
            case 0xb:
            case 0xc:
            case 0xd:
            case 0x20:
                break;
            default:
                lbl_80309730[idx].b9 = 1;
                return 1;
            }
        }
    }
    return 0;
}


s32 fn_8007FFE8(s32 i, u32 k)
{
    Mdl *w = fn_80021658(i)->work;
    s32 f = lbl_80309730[i].b9;
    s32 kind = w->u->x6;
    if (f != 0) {
        switch (k) {
        case 0:
        case 1:
        case 2:
        case 3:
            if (kind != 2 && kind != 7 && kind != 0xb && kind != 0x20 && kind != 0xd) {
                f = -1;
            }
            break;
        case 4:
            if (kind != 3 && kind != 6) {
                f = -1;
            }
            break;
        case 5:
        case 6:
        case 17:
            if (kind != 4 && kind != 8) {
                f = -1;
            }
            break;
        case 7:
            if (kind != 5) {
                f = -1;
            }
            break;
        case 8:
            if (kind != 0xc) {
                f = -1;
            }
            break;
        case 9:
            if (kind != 0x11) {
                f = -1;
            }
            break;
        case 10:
            if (kind != 0x14) {
                f = -1;
            }
            break;
        case 18:
            if (kind != 0xb && kind != 0x20 && kind != 0xd && kind != 0xc) {
                f = -1;
            }
            break;
        case 22:
            break;
        }
    }
    if (f == 0 && fn_8006D1C4() == 1 && lbl_8034733C != 4) {
        s32 old = lbl_80302BF0[i];
        lbl_80302BF0[i] = old + 1;
        if (old > 0x1e && lbl_80302BF0[i] > 0xf0) {
            lbl_80302BF0[i] = 0;
            lbl_80309730[i].b9 = 1;
            return 1;
        }
    }
    return f;
}

void fn_800810FC(s16 idx) {
  lbl_80309730[idx].w0 = 4;
  lbl_80309730[idx].b9 = 0;
  lbl_80302BF0[idx] = 0;
}

void fn_80081134(s16 i, u32 v) {
    s32 off = i * 16;
    *(u32*)((u8*)lbl_80309730 + off) = v;
    ((u8*)lbl_80309730 + off)[9] = 0;
    lbl_80302BF0[i] = 0;
}

s32 fn_8008210C(void) {
    return fn_80081FEC(lbl_80347334);
}

extern s32 fn_8008571C(s16);
extern void fn_80086308(Slot*);
extern void fn_80085CE0(Slot*);
extern void fn_80085064(Slot*);
extern void fn_80084E38(Slot*);
extern void fn_80084A08(Slot*);
void fn_80085ADC(Slot* o);
void fn_800858B8(Slot* self);
void fn_80085C88(Slot *c);
void fn_80084C78(Slot* t);
s32 fn_800855AC(s32 i);

#define SETFN(f)                       \
    lbl_80309700[id]->update = f;        \
    lbl_80309700[id]->state = 0

void fn_80081168(s16 idx, s32 val);
int fn_8007FAB0(int a, int b);

void fn_80085064(Slot* t) {
    s32 i;
    s32 c;
    Wk* wk;
    wk = t->work;
    i = wk->idx;
    c = lbl_80309174[i].b4;
    switch (t->state) {
    case 0:
        if (fn_8007FFE8(i, 0x16) != 0) {
            fn_800811E4(i, 0);
            t->state = 1;
            if (lbl_80309174[i].x6 == 0x77) {
                fn_80085414(i);
                lbl_80309174[i].bd = 0;
            }
        }
        break;
    case 1:
        if (fn_8007FFE8(i, 0) != 0 && fn_8007FAB0(i, c) != 0) {
            const SkillData* e = &lbl_802C4BF0[lbl_80309174[i].x6 & 0xFF];
            s16 save = wk->x3c;
            wk->x3c = lbl_80309174[i].bd;
            lbl_80309174[i].bd = 0;
            fn_8002DD8C(i, 0, 100);
            wk->x3c = save;
            if (e->speed == 0) {
                switch (e->effect) {
                case 0:
                case 4:
                case 0x11:
                    if (lbl_80309DE4[i]->x10 & 0x10) {
                        lbl_80309DE4[i]->x10 |= 0x20;
                    } else {
                        lbl_80309DE4[i]->x10 |= 0x10;
                    }
                    break;
                case 0x1f:
                case 0x20:
                    if (lbl_80309DE4[i]->x10 & 4) {
                        lbl_80309DE4[i]->x10 |= 8;
                    } else {
                        lbl_80309DE4[i]->x10 |= 4;
                    }
                    break;
                case 0x12:
                case 0x13:
                case 0x14:
                case 0x15:
                case 0x16:
                    if (lbl_80309DE4[i]->x10 & 0x40) {
                        lbl_80309DE4[i]->x10 |= 0x80;
                    } else {
                        lbl_80309DE4[i]->x10 |= 0x40;
                    }
                    break;
                }
                lbl_80309DE4[i]->xfe--;
            }
            fn_80081168(i, 12);
            lbl_80309730[i].b4 = c;
            lbl_80309730[i].h6 = lbl_80309174[i].x6;
            t->state = 0xb;
        }
        break;
    case 0xb:
        if (fn_8007FFE8(i, 12) != 0) {
            fn_800811E4(i, 0);
            t->state = 0xc;
        }
        break;
    case 0xc:
        if (fn_8007FFE8(i, 0) != 0) {
            const SkillData* e = &lbl_802C4BF0[lbl_80309174[i].x6 & 0xFF];
            if (i == c || e->target == 2) {
                if (fn_8006D1C4() != 1) {
                    break;
                }
            }
            fn_80010474(i);
            fn_800811E4(i, 0);
            t->state = 0xd;
        }
        break;
    case 0xd:
        if (fn_8006D1C4() == 1 && fn_8007FFE8(i, 0) != 0) {
            wk->flags |= 1;
            lbl_80309700[i]->update = fn_80086C48;
            lbl_80309700[i]->state = 0;
            lbl_80309DE4[i]->w1c &= ~0x400000;
        }
        break;
    }
}

void fn_80086C68(Slot* o)
{
    Wk* wk = o->work;
    Chr_UNIT0000* chr = wk->chr;
    s16 id = wk->idx;
    switch (o->state) {
    case 0: {
        u32 bits = chr->w1c;
        if (bits & 0x6500) {
            wk->flags |= 2;
            break;
        }
        if ((bits & 0x800) || lbl_80309174[id].b4 == -1) {
            lbl_80309174[id].x0 = 3;
            lbl_80309174[id].x6 = 0;
            fn_800855AC(id);
        } else if (lbl_80309174[id].x0 == 0xb) {
            wk->flags |= 2;
        }
        o->state = 3;
        break;
    }
    case 1:
        if (fn_8007FFE8(id, 0x16) != 0) {
            fn_800811E4(id, 0);
            o->state = 2;
        }
        break;
    case 2:
        if (fn_8007FFE8(id, 0) != 0) {
            o->state = 3;
        }
        break;
    case 3: {
        s32 s;
        if (lbl_80309174[id].x0 != 4 && lbl_80309174[id].x0 != 6 && lbl_80309174[id].x0 != 0) {
            if (lbl_80309174[id].x0 == 3 && lbl_80309174[id].x6 == 0) {
                fn_800855AC(id);
            }
            s = lbl_80309174[id].x0;
            if (!(s == 3 && lbl_80309174[id].x6 != 1)) {
                if (fn_8008571C(id) != 0 && s == 3 && fn_80083558(id, lbl_80309174[id].b4) != 0) {
                    lbl_80309174[id].x6 = 0;
                }
            }
        }
        wk->flags |= 1;
        switch (lbl_80309174[id].x0) {
        case 0:
            SETFN(fn_80085ADC);
            break;
        case 6:
            SETFN(fn_800858B8);
            break;
        case 4:
            SETFN(fn_80085C88);
            break;
        case 3:
            if (lbl_80309174[id].x6 == 0) {
                SETFN(fn_80086308);
                fn_80086308(o);
            } else {
                SETFN(fn_80085CE0);
            }
            break;
        case 1:
        case 2:
            SETFN(fn_80085064);
            break;
        case 8:
            if (lbl_80309174[id].x6 == 0x3d) {
                SETFN(fn_80084E38);
            } else {
                SETFN(fn_80084C78);
            }
            break;
        case 5:
            SETFN(fn_80084A08);
            break;
        case 7:
            break;
        }
        break;
    }
    }
}

extern void fn_8008178C(Wk* d, s8 a, s8 b, s32 id);
extern void fn_8008066C(s32);
void fn_80081648(Wk* d, s16 id);
void fn_800810FC(s16 idx);
void fn_80081EF4(s16 a, s32 b);
s32 fn_8008210C(void);

void fn_80087074(Slot* t)
{
    Wk* wk;
    s32 a;
    s32 c;
    EnemySkill* e;
    s16 k;
    s32 p;
    s32 q;
    int i;
    int j;
    s16 m;
    s8 kind;

    wk = t->work;
    a = wk->idx;
    c = lbl_80309174[a].b4;

    switch (t->state) {
    case 0:
        if (fn_8007FFE8(a, 0x16) != 0) {
            fn_800811E4(a, 0);
            if (lbl_80309174[a].x6 == 0x37 && (wk->x2 == 0x8a || wk->x2 == 0x8b)) {
                t->state = 100;
            } else {
                t->state = 1;
            }
        }
        break;
    case 100:
        if (wk->xc == 1) {
            if (wk->xd == 1) {
                p = 1;
                q = 7;
            } else {
                p = 7;
                q = 7;
            }
        } else {
            if (wk->xd == 1) {
                p = 1;
                q = 1;
            } else {
                p = 7;
                q = 1;
            }
        }
        fn_8008178C(wk, p, q, a);
        fn_800810FC(a);
        t->state = 101;
    case 101:
        if (fn_8007FFE8(a, 4) != 0) {
            fn_800811E4(a, 0);
            fn_80081648(wk, a);
            t->state = 1;
        }
        break;
    case 1:
        j = a;
        if (fn_8007FFE8(a, 0) != 0 && fn_8007FAB0(j, c) != 0) {
            k = lbl_80309174[a].x6;
            if (lbl_80309174[a].x0 == 12) {
                e = &lbl_802AD440[k + 0x24];
                fn_80081168(a, 0xb);
            } else {
                e = &lbl_802AD440[k];
                fn_80081168(a, 0xc);
            }
            if (e->kind) {
                kind = e->effect;
                lbl_80309DE4[a]->x10 |= 0x4000;
                switch (kind) {
                case 0:
                case 4:
                case 17:
                    if (lbl_80309DE4[a]->x10 & 0x10) {
                        lbl_80309DE4[a]->x10 |= 0x20;
                    } else {
                        lbl_80309DE4[a]->x10 |= 0x10;
                    }
                    break;
                case 31:
                case 32:
                    if (lbl_80309DE4[a]->x10 & 0x4) {
                        lbl_80309DE4[a]->x10 |= 0x8;
                    } else {
                        lbl_80309DE4[a]->x10 |= 0x4;
                    }
                    break;
                case 5:
                case 6:
                case 9:
                case 11:
                case 12:
                case 20:
                case 21:
                case 26:
                    if (lbl_80309DE4[a]->x10 & 0x40) {
                        lbl_80309DE4[a]->x10 |= 0x80;
                    } else {
                        lbl_80309DE4[a]->x10 |= 0x40;
                    }
                    break;
                }
            } else {
                lbl_80309DE4[a]->x10 |= 0x8000;
                /* fn_8008210C returns an unextended s32; the code compares its low byte */
                if ((s8)fn_8008210C() == 0x2b || (s8)fn_8008210C() == 0x40) {
                    c = lbl_80309174[a].b4;
                    k = lbl_80309174[a].x6;
                }
                switch (k) {
                case 0x2e:
                case 0x41:
                case 0x56:
                    lbl_80309DE4[a]->x24 = 1;
                    break;
                case 0xd:
                case 0x14:
                case 0x25:
                case 0x2f:
                case 0x3f:
                case 0x11e:
                    lbl_80309DE4[a]->x10 |= 0x100;
                    break;
                case 9:
                case 0x37:
                    lbl_80309DE4[a]->x10 |= 0x2000;
                    break;
                case 0x12d:
                    lbl_80309DE4[a]->x10 |= 0x20000;
                    break;
                default:
                    switch (e->effect) {
                    case 0x1f:
                        if (lbl_80309DE4[a]->x10 & 0x200) {
                            lbl_80309DE4[a]->x10 |= 0x400;
                        } else {
                            lbl_80309DE4[a]->x10 |= 0x200;
                        }
                        break;
                    case 0x2c:
                        if (lbl_80309DE4[a]->x10 & 0x800) {
                            lbl_80309DE4[a]->x10 |= 0x1000;
                        } else {
                            lbl_80309DE4[a]->x10 |= 0x800;
                        }
                        break;
                    case 0x3d:
                    case 0x3e:
                        lbl_80309700[a]->work->x37 = 1;
                    case 0x25:
                    case 0x26:
                        fn_80081EF4(a, 0);
                        break;
                    }
                    break;
                }
            }
            lbl_80309730[a].b4 = c;
            lbl_80309730[a].h6 = k;
            t->state = 11;
        }
        break;
    case 11:
        j = a;
        if (fn_8007FFE8(a, 0xb) != 0) {
            fn_800811E4(a, 0);
            t->state = 12;
            m = lbl_80309174[a].x6;
            if (lbl_80309174[a].x0 == 12) {
                e = &lbl_802AD440[m + 0x24];
            } else {
                e = &lbl_802AD440[m];
            }
            switch (e->effect) {
            case 0x3d:
            case 0x3e:
                for (i = 4; i < 12; i++) {
                    if (j == lbl_80309730[i].b4) {
                        lbl_80309730[i].b4 = i;
                    }
                    if (j == lbl_80309730[i].xd) {
                        lbl_80309730[i].xd = i;
                    }
                }
                fn_8008066C(j);
                t->flags18 |= 0x40;
                lbl_80309700[a] = 0;
                lbl_80309DCC[a] = -2;
                lbl_80347374 &= ~(1 << j);
                break;
            }
        }
        break;
    case 12:
        if (fn_8007FFE8(a, 0) != 0) {
            m = lbl_80309174[a].x6;
            if (lbl_80309174[a].x0 == 12) {
                e = &lbl_802AD440[m + 0x24];
            } else {
                e = &lbl_802AD440[m];
            }
            if (a == c || e->target == 2) {
                if (fn_8006D1C4() != 1) {
                    break;
                }
            }
            fn_80010474(a);
            fn_800811E4(a, 0);
            t->state = 13;
        }
        break;
    case 13:
        if (fn_8007FFE8(a, 0) != 0) {
            wk->flags |= 1;
            lbl_80309700[a]->update = fn_80087054;
            lbl_80309700[a]->state = 0;
            if ((s8)fn_8008210C() == 0x40) { /* low byte, as above */
                wk->flags |= 0x10;
            }
        }
        break;
    }
}

void fn_80088F60(void) {
}

void fn_8008999C(void* a) {
    fn_80083BAC((s32)a, 3);
}

extern s32 fn_80083ACC(s32 id, s32 kind);
void fn_8008A12C(s32 p) {
    fn_80083BAC(p, 1);
}

void fn_8008A150(s32 p) {
    fn_80083ACC(p, 1);
}

s32 fn_8008A880(s32 i) {
    Chr_UNIT0000* e = lbl_80309DE4[i];
    u32 f = e->x10;
    if (f & 0x20000) {
        e->x10 = f & ~0x20000;
        return 1;
    }
    return 0;
}

void fn_8007DE54(Obj_8007DE54 *p) {
    switch (p->state) {
    case 0:
        p->buf = fn_801E1C7C(4);
        p->state = 1;
    case 1:
        p->state = 2;
        break;
    case 0xff:
        fn_80217830(1);
        p->flags18 |= 0x40;
        lbl_8034736C = 0;
        break;
    }
}

s32 fn_80080438(Slot *p) {
    s32 mode = lbl_8034733C;
    s32 idx = p->work->idx;
    if (((u32)(mode - 5) <= 1) || mode == 3 || lbl_80347348 == 1) {
        lbl_80347374 = lbl_80347374 & ~(1 << idx);
        lbl_80309700[idx]->update = (void (*)())fn_80080278;
        lbl_80309700[idx]->state = 0;
        p->work->x50 = 0;
        return 1;
    }
    return 0;
}

void fn_80081168(s16 idx, s32 val) {
    Wk *req = lbl_80309700[idx]->work;
    if (req->flags & 0x20) {
        req->flags &= ~0x20;
        lbl_80309730[idx].w0 = 0x12;
    }
    if (lbl_80309730[idx].w0 != val) {
        lbl_80309730[idx].w0 = val;
        lbl_80309730[idx].b9 = 0;
        lbl_80302BF0[idx] = 0;
    }
}

void fn_800842A0(s16 idx) {
    s16 sel;
    Slot* t;
    Wk* w;
    s8 ax;
    s8 ay;
    s8 sx;
    s8 sy;
    f32 fa;
    f32 fb;
    lbl_80309700[idx] = 0;
    sel = lbl_80309DCC[idx];
    if (sel == -1) {
        return;
    }
    t = fn_802268E8(lbl_803475A8, fn_800804B8);
    lbl_80309700[idx] = t;
    w = fn_801E1A74(0xd4, 1);
    t->work = w;
    w->idx = idx;
    w->chr = lbl_80309DE4[idx];
    w->x2 = sel;
    lbl_80309700[idx]->work->x10 = 0;
    ax = lbl_803097F0.ent[idx].x1;
    sx = w->chr->xac;
    sy = w->chr->xad;
    ay = lbl_803097F0.ent[idx].x2;
    switch (sx) {
    case 1:
        fa = ax * 15 - 75;
        break;
    case 2:
        fa = ax * 15 - 75;
        fa += 7.0f;
        break;
    case 3:
        fa = ax * 15 - 75;
        fa += 15.0f;
        break;
    }
    switch (sy) {
    case 1:
        fb = ay * 15 - 75;
        break;
    case 2:
        fb = ay * 15 - 75;
        fb += 7.0f;
        break;
    case 3:
        fb = ay * 15 - 75;
        fb += 15.0f;
        break;
    }
    lbl_803097F0.ent[idx].x4 = fa;
    lbl_803097F0.ent[idx].x8 = fb;
    w->xc = ax;
    w->xd = ay;
    w->xe = 0;
    w->xf = 0;
    lbl_80309174[idx].x10 = 0;
    lbl_80309174[idx].x14 = 0;
    lbl_80309174[idx].x16 = 0;
    lbl_80309174[idx].x18 = 0;
    lbl_80309174[idx].x1a = 0;
    lbl_80309174[idx].x1c = 0;
    fn_80010474(idx);
    fn_800811E4(idx, 0);
    lbl_80309730[idx].b4 = idx;
}

void fn_800849A8(void) {
    s16 i;
    lbl_80347354 = 0;
    lbl_80347350 = 0;
    fn_800840BC();
    fn_80010CF4();
    fn_80084570();
    i = 0;
    do {
        fn_800842A0(i);
        i++;
    } while (i < 12);
    lbl_80347340 = 1;
}

void fn_80085C88(Slot *c) {
    Wk *req = c->work;
    void (*fp)(Slot *) = fn_80086C48;
    s16 idx = req->idx;
    Chr_UNIT0000 *o = lbl_80309DE4[idx];
    o->w1c |= 1;
    req->flags |= 1;
    lbl_80309700[idx]->update = fp;
    lbl_80309700[idx]->state = 0;
}

s32 fn_80089E3C(void) {
    s32 i;
    s32 best;
    s32 bestScore = 0;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i)) {
            if (bestScore < lbl_80309DE4[i]->score) {
                best = i;
                bestScore = lbl_80309DE4[i]->score;
            }
        }
    }
    return best;
}

s32 fn_8008A004(void) {
    s32 i;
    s32 best;
    s32 bestScore = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            if (bestScore < lbl_80309DE4[i]->score) {
                best = i;
                bestScore = lbl_80309DE4[i]->score;
            }
        }
    }
    return best;
}

s32 fn_80083BAC(s32 a, s32 b) {
    lbl_80302C08[0].x4 = 0x7f;
    lbl_80302C08[0].x0 = -1;
    lbl_80302C08[1].x4 = 0x7f;
    lbl_80302C08[1].x0 = -1;
    lbl_80302C08[2].x4 = 0x7f;
    lbl_80302C08[2].x0 = -1;
    lbl_80302C08[3].x4 = 0x7f;
    lbl_80302C08[3].x0 = -1;
    lbl_80302C08[4].x4 = 0x7f;
    lbl_80302C08[4].x0 = -1;
    lbl_80302C08[5].x4 = 0x7f;
    lbl_80302C08[5].x0 = -1;
    lbl_80302C08[6].x4 = 0x7f;
    lbl_80302C08[6].x0 = -1;
    lbl_80302C08[7].x4 = 0x7f;
    lbl_80302C08[7].x0 = -1;
    lbl_80302C08[8].x4 = 0x7f;
    lbl_80302C08[8].x0 = -1;
    lbl_80302C08[9].x4 = 0x7f;
    lbl_80302C08[9].x0 = -1;
    lbl_80302C08[10].x4 = 0x7f;
    lbl_80302C08[10].x0 = -1;
    lbl_80302C08[11].x4 = 0x7f;
    lbl_80302C08[11].x0 = -1;
    fn_800839D8(a, lbl_80302C08, b);
    return lbl_80302C08[0].x0;
}

s32 fn_80089DAC(void) {
    s32 i;
    s32 idx;
    s32 best;
    best = 0x1869F;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i)) {
            if (best > lbl_80309DE4[i]->score) {
                idx = i;
                best = lbl_80309DE4[i]->score;
            }
        }
    }
    return idx;
}

s32 fn_80089EC8(s32 a) {
    s32 *out;
    s32 i;
    s32 n;
    out = lbl_80302C98;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    out[4] = -1;
    out[5] = -1;
    out[6] = -1;
    out[7] = -1;
    n = 0;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i)) {
            out[n] = i;
            n++;
        }
    }
    return lbl_80302C98[rand() % n];
}

s32 fn_80089F78(void) {
    s32 i;
    s32 idx;
    s32 best;
    best = 0x1869F;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            if (best > lbl_80309DE4[i]->score) {
                idx = i;
                best = lbl_80309DE4[i]->score;
            }
        }
    }
    return idx;
}

s32 fn_8008A08C(void) {
    s32 *out;
    s32 i;
    s32 n;
    out = lbl_80302C98;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    n = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            out[n] = i;
            n++;
        }
    }
    return lbl_80302C98[rand() % n];
}

void fn_8007E13C(Arg* a) {
    Rec* r;
    s32 i;
    lbl_80309E5C.tab[lbl_80309E5C.idx].count = *lbl_80309E5C.tab[lbl_80309E5C.idx].src->x8;
    lbl_80309E5C.tab[lbl_80309E5C.idx].recs = fn_801E1C7C(lbl_80309E5C.tab[lbl_80309E5C.idx].count * sizeof(Rec));
    r = a->recs;
    for (i = 0; i < lbl_80309E5C.tab[lbl_80309E5C.idx].count; i++) {
        lbl_80309E5C.tab[lbl_80309E5C.idx].recs[i] = r[i];
        lbl_80309E5C.tab[lbl_80309E5C.idx].recs[i].x10 = lbl_80309E5C.tab[lbl_80309E5C.idx].src;
        fn_8007E9E0(i);
    }
}

void fn_80081EF4(s16 a, s32 b) {
    s32 c = fn_80081FEC(lbl_80347334);
    Wk* w;
    if ((s8)c == 0x1b || (s8)c == 0x1c || (s8)c == 0x2f || (s8)c == 0x27 || fn_80078610(a)) {
        w = lbl_80309700[a]->work;
        if (w->x37 != 0) {
            if (w->x3c != -1 || w->x44 != -1 || w->x46 != -1 || w->x48 != -1 || w->x4a != -1) {
                w->x37 = 0;
                fn_8002DD8C(a, b, c);
            }
        }
    }
}

s32 fn_80081FEC(s16 k) {
    if (k == lbl_80309174[lbl_80347334].b4 && lbl_80309174[lbl_80347334].x0 == 3) {
        return 0;
    }
    switch (lbl_80309174[k].x0) {
    case 3:
        return 0;
    case 1:
    case 2:
    case 8:
        {
            s16 j = lbl_80309174[k].x6;
            if (k < 4) {
                return (s8)lbl_802C4BF0[j].effect;
            }
            return (s8)lbl_802AD440[j].effect;
        }
    case 5:
        return (s8)lbl_802C7C34[lbl_80309174[k].x6 - 0xF0].effect;
    case 12:
        return (s8)lbl_802AD440[lbl_80309174[k].x6 + 0x24].effect;
    }
    return 0;
}

void fn_80082C98(s8 x, s8 y, u8* grid, s32 a, s32 b) {
    void* wa;
    void* wb;
    if (x >= 0 && x <= 10 && y >= 0 && y <= 10) {
        wa = lbl_80309700[a]->work;
        wb = lbl_80309700[b]->work;
        if (fn_80082AC0(x, y, grid, a) == 0) return;
        if (fn_8008328C(wa, wb, x, y) == 0) return;
        lbl_80309300[lbl_8034734E * 2] = x;
        lbl_80309300[lbl_8034734E * 2 + 1] = y;
        *(grid + y * 11 + x) = 1;
        lbl_8034734E++;
        if (lbl_8034734E >= 0x200) lbl_8034734E = 0;
    }
}

s32 fn_8008A738(void) {
    s32 i;
    s16 sum = 0;
    for (i = 4; i < 12; i++) {
        if (sum > 3000) {
            break;
        }
        if (lbl_80309DE4[i] == NULL) {
            return 1;
        }
        if (lbl_80309700[i] != 0) {
            sum = sum + lbl_80309DE4[i]->p110->s56;
        }
    }
    return 0;
}

void fn_8007E88C(Tk_8007E88C* t) {
    Wk_8007E88C* w = t->work;
    Eff* e = w->eff;
    DrawState ds;
    switch (t->state) {
    case 0:
        t->state = 1;
        e->xc = 0.0f;
        break;
    default:
        DrawStateDefault2D(&ds);
        if ((*(Tbl*)&lbl_80309E5C).flags & 0x20000000) {
            e->x10 += (*(Tbl*)&lbl_80309E5C).x14;
            if (e->x10 <= -1.0f) {
                e->x10 = -1.0f;
            }
        } else if ((*(Tbl*)&lbl_80309E5C).flags & 0x10000000) {
            e->x10 += (*(Tbl*)&lbl_80309E5C).x14;
            if (e->x10 >= 0.0f) {
                e->x10 = 0.0f;
                (*(Tbl*)&lbl_80309E5C).flags &= ~0x10000000;
            }
        } else {
            e->x10 = 0.0f;
        }
        if ((*(Tbl*)&lbl_80309E5C).flags & 0x08000000) {
            e->x40 = 1;
            e->x44 = (*(Tbl*)&lbl_80309E5C).x18;
            e->x48 = (*(Tbl*)&lbl_80309E5C).x1c;
        } else {
            e->x40 = 0;
        }
        if (fn_80018B80(&e->x10)) {
            fn_80299040(w->x8);
            if (e->x10 > -1.0f) {
                fn_800342BC(w);
            }
            fn_80018C94();
        }
        break;
    }
}

static inline s32 GridGet(u8* grid, s8 x, s8 y) {
    return *(grid + y * 11 + x);
}

int fn_80082840(s8 x, s8 y, u8 c, u8* grid, s32 idx) {
    s8 n;
    u8 v;

    if (x > 11) {
        return 0;
    }
    if (y > 11) {
        return 0;
    }
    if (fn_80082AC0(x, y, grid, idx) == 0) {
        return 0;
    }
    n = c;
    v = GridGet(grid, x, y);
    if (v <= n + 1 && v != 0) {
        return 1;
    }
    lbl_80309300[lbl_8034734E * 2] = x;
    lbl_80309300[lbl_8034734E * 2 + 1] = y;
    *(grid + y * 11 + x) = n + 1;
    if (++lbl_8034734E >= 0x200) {
        lbl_8034734E = 0;
    }
    return 2;
}

void fn_80082948(s8 x, s8 y, u8* grid, s32 idx) {
    u8 c = *(grid + y * 11 + x);
    s8 m = 0;
    if (!fn_80082840(x - 1, y, c, grid, idx)) {
        m = 4;
    }
    if (!fn_80082840(x, y - 1, c, grid, idx)) {
        m += 1;
    }
    if (!fn_80082840(x, y + 1, c, grid, idx)) {
        m += 2;
    }
    if (!fn_80082840(x + 1, y, c, grid, idx)) {
        m += 8;
    }
    if (!(m & 5)) {
        fn_80082840(x - 1, y - 1, c, grid, idx);
    }
    if (!(m & 6)) {
        fn_80082840(x - 1, y + 1, c, grid, idx);
    }
    if (!(m & 9)) {
        fn_80082840(x + 1, y - 1, c, grid, idx);
    }
    if (!(m & 0xA)) {
        fn_80082840(x + 1, y + 1, c, grid, idx);
    }
}

s32 fn_80083728(s32 a, s32 b)
{
    Obj24* d = (*(Obj*(*)[12])&lbl_80309700)[a]->d;
    d->x16 = 0;
    if (!fn_80078610(b)) return 0;
    if (fn_80083558(a, b)) {
        d->x16 = 1;
        return 1;
    }
    if (!fn_80083398(a, b)) return 0;
    if (!((*(Slot_80083728*(*)[12])&lbl_80309DE4)[a]->flags & 1)) return 0;
    if (fn_80083558(a, b)) {
        d->x16 = 2;
        return 2;
    }
    if (fn_80082D8C(a, b)) {
        d->x16 = 4;
        return 4;
    }
    d->xe = 0;
    if (fn_80082D8C(a, b)) {
        d->x16 = 4;
        return 4;
    }
    return 0;
}

void fn_8007E690(Tk_8007E690* t)
{
    Wk_8007E690* w = t->work;
    Eff* e = w->eff;
    Pos_8007E690* pos;
    NJS_POINT3 v;
    f32 hit;

    switch (t->state) {
    case 0:
        t->state = 1;
        e->xc = 0.0f;
        break;
    default:
        if ((*(Tbl_8007E690*)&lbl_80309E5C).flags & 0x80000000) {
            e->x10 += (*(Tbl_8007E690*)&lbl_80309E5C).x10;
            if (e->x10 <= -1.0f) {
                e->x10 = -1.0f;
            }
        } else if ((*(Tbl_8007E690*)&lbl_80309E5C).flags & 0x40000000) {
            e->x10 += (*(Tbl_8007E690*)&lbl_80309E5C).x10;
            if (e->x10 >= 0.0f) {
                e->x10 = 0.0001f;
                (*(Tbl_8007E690*)&lbl_80309E5C).flags &= ~0x40000000;
            }
        } else {
            e->x10 = 0.0001f;
        }
        if ((*(Tbl_8007E690*)&lbl_80309E5C).flags & 0x08000000) {
            e->x40 = 1;
            e->x44 = (*(Tbl_8007E690*)&lbl_80309E5C).x18;
            e->x48 = (*(Tbl_8007E690*)&lbl_80309E5C).x1c;
        } else {
            e->x40 = 0;
        }
        if (!((*(Tbl_8007E690*)&lbl_80309E5C).flags & 0x04000000)) {
            sndAuxCallbackShutdownReverbSTD(w->x0, &pos);
            v.x = pos->x8;
            v.y = pos->xc;
            v.z = pos->x10;
            if (fn_80011E50(&v, &hit, (f32)fabs(v.x) > (f32)fabs(v.z) ? 0 : 1) != 0) {
                if ((*(Tbl_8007E690*)&lbl_80309E5C).flags & 0x40000000) {
                    if (hit < e->x10) {
                        e->x10 = hit;
                        (*(Tbl_8007E690*)&lbl_80309E5C).flags &= ~0x40000000;
                    }
                } else {
                    e->x10 = hit;
                }
            }
        }
        if (fn_80018B80(&e->x10)) {
            fn_80299040(w->x8);
            if (e->x10 > -1.0f) {
                fn_800342BC(w);
            }
            fn_80018C94();
        }
        break;
    }
}

void fn_800840BC(void)
{
    u8* src;
    u8* dst;
    u8* map;
    u8* row;
    u8* p;
    s16 i;
    s16 j;

    if (lbl_80347354 == 0) {
        lbl_80347354 = fn_801E1C7C(0x79);
    }
    row = lbl_80347354;
    map = (*(Map_800840BC*)&lbl_80309E5C).cells;
    for (i = 0; i < 9; i++) {
        src = map;
        dst = row;
        for (j = 0; j < 9; j++) {
            switch (*src) {
            case 1:
                dst[12] = 0x7D;
                break;
            case 2:
            case 4:
                dst[12] = 0x7C;
                break;
            default:
                dst[12] = 0;
                break;
            }
            src++;
            dst++;
        }
        map += 9;
        row += 11;
    }
    p = lbl_80347354;
    for (i = 0; i < 11; i++) {
        *p++ = 0x7F;
    }
    for (i = 0; i < 9; i++) {
        p[0] = 0x7F;
        p[10] = 0x7F;
        p += 11;
    }
    for (i = 0; i < 11; i++) {
        *p++ = 0x7F;
    }
    if (lbl_80347350 == 0) {
        lbl_80347350 = fn_801E1C7C(0x79);
    }
    fn_802AC710(lbl_80347350, lbl_80347354, 0x79);
}

void fn_800858B8(Slot* self) {
    s32 i;
    Wk* sub;
    sub = self->work;
    i = sub->idx;
    switch (self->state) {
    case 0:
        if (fn_8007FFE8(i, 0) != 0) {
            self->state = 10;
        }
        break;
    case 10:
        fn_80081168(i, 10);
        if (fn_80010340(i) != 0) {
            self->state = 1;
            lbl_80309730[i].b8 = 1;
        } else {
            self->state = 2;
            lbl_80309730[i].b8 = 0;
        }
        break;
    case 1:
        if (fn_8007FFE8(i, 10) != 0) {
            lbl_80309DE4[i]->w1c |= 0x2000;
            lbl_80309DCC[i] = -3;
            sub->flags |= 0x10;
            lbl_80309700[i]->update = fn_80086C48;
            lbl_80309700[i]->state = 0;
        }
        break;
    case 2:
        if (fn_8007FFE8(i, 10) != 0) {
            s32 j;
            for (j = 0; j <= 3; j++) {
                if (fn_80078610(j) != 0) {
                    lbl_80309DE4[j]->w1c |= 1;
                }
            }
            fn_800811E4(i, 0);
            self->state = 3;
        }
        break;
    case 3:
        if (fn_8007FFE8(i, 0) != 0) {
            sub->flags |= 1;
            lbl_80309700[i]->update = fn_80086C48;
            lbl_80309700[i]->state = 0;
        }
        break;
    }
}

void fn_80088B14(Slot* self) {
    s32 i;
    Wk* sub;
    sub = self->work;
    i = sub->idx;
    switch (self->state) {
    case 0:
        fn_80081168(i, 10);
        if (fn_80010340(i) != 0) {
            self->state = 1;
            lbl_80309730[i].b8 = 1;
        } else {
            lbl_80309730[i].b8 = 0;
            self->state = 2;
        }
        break;
    case 1:
        if (fn_8007FFE8(i, 10) != 0) {
            lbl_80309DCC[i] = -3;
            lbl_80309DE4[i]->w1c |= 0x2000;
            sub->flags |= 0x10;
            lbl_80309700[i]->update = fn_80087054;
            lbl_80309700[i]->state = 0;
        }
        break;
    case 2:
        if (fn_8007FFE8(i, 10) != 0) {
            self->state = 3;
            fn_800811E4(i, 0);
            lbl_80309DE4[i]->w1c |= 1;
        }
        break;
    case 3:
        if (fn_8007FFE8(i, 0) != 0) {
            sub->flags |= 1;
            lbl_80309700[i]->update = fn_80087054;
            lbl_80309700[i]->state = 0;
        }
        break;
    }
}

s32 fn_80080278(Slot* t) {
    s16 id = t->work->idx;
    s32 v;
    if (lbl_80309700[id]->work->x10 != 0) {
    lbl_80309700[id]->update = fn_800801A8;
    lbl_80309700[id]->state = 0;
    if (fn_8007FFE8(id, 0x16)) {
        if (id <= 3) {
            lbl_80302C08[0].x4 = 0x7F;
            lbl_80302C08[0].x0 = -1;
            lbl_80302C08[1].x4 = 0x7F;
            lbl_80302C08[1].x0 = -1;
            lbl_80302C08[2].x4 = 0x7F;
            lbl_80302C08[2].x0 = -1;
            lbl_80302C08[3].x4 = 0x7F;
            lbl_80302C08[3].x0 = -1;
            lbl_80302C08[4].x4 = 0x7F;
            lbl_80302C08[4].x0 = -1;
            lbl_80302C08[5].x4 = 0x7F;
            lbl_80302C08[5].x0 = -1;
            lbl_80302C08[6].x4 = 0x7F;
            lbl_80302C08[6].x0 = -1;
            lbl_80302C08[7].x4 = 0x7F;
            lbl_80302C08[7].x0 = -1;
            lbl_80302C08[8].x4 = 0x7F;
            lbl_80302C08[8].x0 = -1;
            lbl_80302C08[9].x4 = 0x7F;
            lbl_80302C08[9].x0 = -1;
            lbl_80302C08[10].x4 = 0x7F;
            lbl_80302C08[10].x0 = -1;
            lbl_80302C08[11].x4 = 0x7F;
            lbl_80302C08[11].x0 = -1;
            fn_800839D8(id, lbl_80302C08, 2);
            v = lbl_80302C08[0].x0;
        } else {
            lbl_80302C08[0].x4 = 0x7F;
            lbl_80302C08[0].x0 = -1;
            lbl_80302C08[1].x4 = 0x7F;
            lbl_80302C08[1].x0 = -1;
            lbl_80302C08[2].x4 = 0x7F;
            lbl_80302C08[2].x0 = -1;
            lbl_80302C08[3].x4 = 0x7F;
            lbl_80302C08[3].x0 = -1;
            lbl_80302C08[4].x4 = 0x7F;
            lbl_80302C08[4].x0 = -1;
            lbl_80302C08[5].x4 = 0x7F;
            lbl_80302C08[5].x0 = -1;
            lbl_80302C08[6].x4 = 0x7F;
            lbl_80302C08[6].x0 = -1;
            lbl_80302C08[7].x4 = 0x7F;
            lbl_80302C08[7].x0 = -1;
            lbl_80302C08[8].x4 = 0x7F;
            lbl_80302C08[8].x0 = -1;
            lbl_80302C08[9].x4 = 0x7F;
            lbl_80302C08[9].x0 = -1;
            lbl_80302C08[10].x4 = 0x7F;
            lbl_80302C08[10].x0 = -1;
            lbl_80302C08[11].x4 = 0x7F;
            lbl_80302C08[11].x0 = -1;
            fn_800839D8(id, lbl_80302C08, 1);
            v = lbl_80302C08[0].x0;
        }
        lbl_80309730[id].xd = v;
        fn_800811E4(id, 2);
    }
    return 1;
    }
    return 0;
}

void fn_800801A8(Slot *self)
{
    s16 i = self->work->idx;
    switch (self->state) {
    case 0:
        if (fn_8007FFE8(i, 0x16) != 0) {
            fn_800811E4(i, 0);
            self->state = 1;
        }
        break;
    case 1:
        if (fn_8007FFE8(i, 0) != 0) {
            if (lbl_80309700[i]->work->x10 != 0) {
                lbl_80309700[i]->update = lbl_80309700[i]->work->x10;
                lbl_80309700[i]->state = 0;
                lbl_80309700[i]->work->x10 = 0;
            }
        }
        break;
    }
}

void fn_800804B8(Slot* t) {
    s16 id = t->work->idx;
    s32 v;
    if (lbl_80309700[id]->work->x10 != 0) {
    lbl_80309700[id]->update = fn_800801A8;
    lbl_80309700[id]->state = 0;
    if (fn_8007FFE8(id, 0x16)) {
        if (id <= 3) {
            lbl_80302C08[0].x4 = 0x7F;
            lbl_80302C08[0].x0 = -1;
            lbl_80302C08[1].x4 = 0x7F;
            lbl_80302C08[1].x0 = -1;
            lbl_80302C08[2].x4 = 0x7F;
            lbl_80302C08[2].x0 = -1;
            lbl_80302C08[3].x4 = 0x7F;
            lbl_80302C08[3].x0 = -1;
            lbl_80302C08[4].x4 = 0x7F;
            lbl_80302C08[4].x0 = -1;
            lbl_80302C08[5].x4 = 0x7F;
            lbl_80302C08[5].x0 = -1;
            lbl_80302C08[6].x4 = 0x7F;
            lbl_80302C08[6].x0 = -1;
            lbl_80302C08[7].x4 = 0x7F;
            lbl_80302C08[7].x0 = -1;
            lbl_80302C08[8].x4 = 0x7F;
            lbl_80302C08[8].x0 = -1;
            lbl_80302C08[9].x4 = 0x7F;
            lbl_80302C08[9].x0 = -1;
            lbl_80302C08[10].x4 = 0x7F;
            lbl_80302C08[10].x0 = -1;
            lbl_80302C08[11].x4 = 0x7F;
            lbl_80302C08[11].x0 = -1;
            fn_800839D8(id, lbl_80302C08, 2);
            v = lbl_80302C08[0].x0;
        } else {
            lbl_80302C08[0].x4 = 0x7F;
            lbl_80302C08[0].x0 = -1;
            lbl_80302C08[1].x4 = 0x7F;
            lbl_80302C08[1].x0 = -1;
            lbl_80302C08[2].x4 = 0x7F;
            lbl_80302C08[2].x0 = -1;
            lbl_80302C08[3].x4 = 0x7F;
            lbl_80302C08[3].x0 = -1;
            lbl_80302C08[4].x4 = 0x7F;
            lbl_80302C08[4].x0 = -1;
            lbl_80302C08[5].x4 = 0x7F;
            lbl_80302C08[5].x0 = -1;
            lbl_80302C08[6].x4 = 0x7F;
            lbl_80302C08[6].x0 = -1;
            lbl_80302C08[7].x4 = 0x7F;
            lbl_80302C08[7].x0 = -1;
            lbl_80302C08[8].x4 = 0x7F;
            lbl_80302C08[8].x0 = -1;
            lbl_80302C08[9].x4 = 0x7F;
            lbl_80302C08[9].x0 = -1;
            lbl_80302C08[10].x4 = 0x7F;
            lbl_80302C08[10].x0 = -1;
            lbl_80302C08[11].x4 = 0x7F;
            lbl_80302C08[11].x0 = -1;
            fn_800839D8(id, lbl_80302C08, 1);
            v = lbl_80302C08[0].x0;
        }
        lbl_80309730[id].xd = v;
        fn_800811E4(id, 2);
    }
    }
}

void fn_800811E4(s16 id, int mode) {
    int r;
    int k = 0;
    if (lbl_80309700[id] == 0) {
        return;
    }
    if (lbl_80309700[id]->work->flags & 0x20) {
        lbl_80309700[id]->work->flags &= ~0x20;
        lbl_80309730[id].w0 = 0x12;
    }
    if (lbl_80309DE4[id]->w1c & 0x8000) {
        k = 1;
    }
    switch (mode) {
    case 0:
    case 1:
        r = k != 0;
        break;
    case 2:
    case 3:
        r = 2;
        if (k != 0) {
            r = 3;
        }
        break;
    }
    switch (lbl_80309730[id].w0) {
    case 0:
    case 2:
        if (r == 0 || r == 2) {
            lbl_80309730[id].w0 = r;
            return;
        }
        break;
    case 1:
    case 3:
        if (r == 1 || r == 3) {
            lbl_80309730[id].w0 = r;
            return;
        }
        break;
    }
    if (lbl_80309700[id]->work->flags & 0x20) {
        lbl_80309700[id]->work->flags &= ~0x20;
        lbl_80309730[id].w0 = 0x12;
    }
    if (r != lbl_80309730[id].w0) {
        lbl_80309730[id].w0 = r;
        lbl_80309730[id].b9 = 0;
        lbl_80302BF0[id] = 0;
    }
}

int fn_8007FAB0(int a, int b)
{
    int v = 0;
    u32 st;
    int k;
    int i;

    lbl_80309700[a]->work->x50 = 3;
    if (b == -1) {
        if (lbl_80309DE4[a]->w1c & 0x400000) {
            b = a;
        } else {
            return 1;
        }
    }
    st = lbl_80309174[a].x0;
    k = fn_80078478(a);
    switch (st) {
    case 2:
        if (fn_8007838C(lbl_80309174[a].x6) == 0x2f) {
            for (i = 0; i < 4; i++) {
                if (lbl_80309700[i] != 0) {
                    s8 x = lbl_80309700[i]->work->x50;
                    if (x != 3 && x != 1) goto done;
                }
            }
            {
                i = 0;
                do {
                    if (lbl_80309700[i] != 0) {
                        lbl_80309700[i]->work->flags |= 0x20;
                        lbl_80309700[i]->work->x50 = 4;
                        fn_80082134(i);
                        if (a != i) {
                            lbl_80309730[i].b9 = 0;
                        }
                    }
                    i++;
                } while (i <= 3);
                v = 1;
            }
        } else {
            v = fn_8007EBBC(a, b, k, st);
        }
        break;
    case 3:
    case 5:
    case 8:
    case 12:
        v = fn_8007EBBC(a, b, k, st);
        break;
    case 1:
        v = fn_8007F270(a, b, k, st);
        break;
    }
done:
    return v;
}

void fn_80084C78(Slot* t)
{
    int a;
    int c;
    Wk* wk;
    int r;
    s16 saved;

    wk = t->work;
    a = wk->idx;
    c = lbl_80309174[a].b4;

    switch (t->state) {
    case 0:
        if (fn_8007FFE8(a, 0x16) != 0) {
            fn_800811E4(a, 0);
            t->state = 1;
        }
        break;
    case 1:
        if (fn_8007FFE8(0, 0) != 0) {
            if (fn_8007FAB0(a, c) != 0) {
                saved = wk->x3c;
                wk->x3c = lbl_80347390->x8;
                lbl_80309174[a].bd = 0;
                fn_8002DD8C(a, 0, 100);
                wk->x3c = saved;
                fn_80081168(a, 0xC);
                lbl_80309730[a].b4 = c;
                lbl_80309730[a].h6 = 0x3C;
                t->state = 0xB;
            }
        }
        break;
    case 11:
        if (fn_8007FFE8(a, 0x15) != 0) {
            fn_800811E4(a, 0);
            t->state = 0xC;
        }
        break;
    case 12:
        r = fn_8007FFE8(a, 0x16);
        if (r != 0) {
            if (fn_8006D1C4() == 1) {
                wk->flags |= 1;
                lbl_80309700[a]->update = fn_80086C48;
                lbl_80309700[a]->state = 0;
            }
        }
        break;
    }
}

s32 fn_8008100C(s32 id) {
    s32 cur = lbl_80309174[lbl_80347334].b4;
    int kind = fn_80078478(lbl_80347334);

    if (id == cur) {
        return 1;
    }
    switch (kind) {
    case 2:
        if (id < 4) {
            return 1;
        }
        break;
    case 4:
        if (id >= 4) {
            return 1;
        }
        break;
    case 6:
        return 1;
    }
    if (id >= 0x20 && id < 0x60 && id >= 4) {
        return 1;
    }
    if (id >= 0x60 && id < 4) {
        return 1;
    }
    return 0;
}

void fn_80085ADC(Slot* o)
{
    s32 id;
    Wk* d = o->work;
    id = d->idx;
    switch (o->state) {
    case 0:
        if (fn_8007FFE8(id, 0)) {
            fn_800811E4(id, 0);
            o->state = 10;
        }
        break;
    case 10:
        if (fn_8007FFE8(id, 0)) {
            fn_80081168(id, 9);
            if (lbl_80309DE4[id]->w1c & 0x3100) {
                lbl_80309730[id].b8 = 0;
                d->x3c = 0;
            } else {
                lbl_80309730[id].b8 = 1;
                d->x3c = fn_80010CBC(id);
            }
            fn_8002DD8C(id, 0xF, 0x65);
            o->state = 1;
        }
        break;
    case 1:
        if (fn_8007FFE8(id, 9)) {
            fn_800811E4(id, 0);
            o->state = 2;
        }
        break;
    case 2:
        if (fn_8007FFE8(id, 0)) {
            d->flags |= 1;
            lbl_80309700[id]->update = fn_80086C48;
            lbl_80309700[id]->state = 0;
        }
        break;
    }
}

void fn_8007DFC0(Cmd_8007DFC0* c) {
    G_8007E13C* t = &lbl_80309E5C;
    Req_8007DFC0* r = c->req;
    Node_8007DFC0* n;
    Rec_8007DFC0* w;
    if (r->a < t->tab[t->idx].count) {
        n = fn_802268E8(lbl_803475A8, (void*)fn_800300C4(4));
        fn_80061F58(&n->work, 0x58, 0);
        w = n->work;
        w->x0 = fn_8006C9AC(t->tab[t->idx].recs[r->a].x0, r->b & 0xFFFF);
        fn_80061F58(&w->x4c, 0x4c, 0);
        w->x4c->x0c = r->data;
        w->x4c->x4 = -1;
    }
}

void fn_8007E9E0(u8 i) {
    G_8007E13C* t = &lbl_80309E5C;
    Hdr* h;
    Node_8007E9E0* n;
    Wk_E9E0* w;
    s16 a;

    a = t->tab[t->idx].recs[i].x18;
    fn_8006CF28((void *)t->tab[t->idx].src->x8, (void *)&h, t->tab[t->idx].recs[i].x16);
    n = fn_802268E8(lbl_803475A8, (void*)fn_800300C4(a));
    fn_80061F58(&n->work, 0x58, 0);
    w = n->work;
    w->item = t->tab[t->idx].recs[i];
    w->item.x8 = (Hdr*)((u8*)h + 8);
    if (w->item.x8->x0 != 0) {
        w->item.x40 = (void *)fn_80227810((void *)w->item.x8);
    } else {
        w->item.x8 = 0;
    }
    w->item.x0 = h->x0;
    t->tab[t->idx].recs[i] = w->item;
    if (a != 0xFF) {
        fn_80061F58(&w->x4c, 0x54, 0);
        fn_8022F00C(w->item.x0);
        fn_8022F030(w->item.x0, -1, 1);
    }
}

int fn_800819D0(s16 a, s16 b)
{
    Chr_UNIT0000* chr = lbl_80309DE4[b];
    u32 bits = chr->w1c;

    if (bits & 0x6D00) return 0;
    if ((b < 4 && a < 4) || (b >= 4 && a >= 4)) return 0;
    if ((int)lbl_80309730[b].b8 == 2) return 0;
    if ((bits & 2) == 0 && (bits & 0x800000) == 0) {
        if (chr->xba == 0) return 0;
        if (rand() % 100 >= chr->xb4) return 0;
    }
    if (lbl_80309730[a].w0 == 7) {
        if ((lbl_80309DE4[b]->xae & 0x80) == 0) return 0;
        lbl_80309174[b].xc = 1;
    } else if ((lbl_80309DE4[b]->xae & 0x40) == 0) {
        lbl_80309174[b].xc = 1;
    } else {
        lbl_80309174[b].xc = 0;
    }
    if ((chr->w1c & 2) || (chr->w1c & 0x800000)) {
        chr->xb4 = 100;
    } else {
        chr->xb4 = 0;
    }
    return 1;
}

void fn_80087054(Slot* s) {
    fn_800804B8(s);
}

void fn_8007EB9C(s32 a, s32 b) {
    fn_80083558(a, b);
}

void fn_80086C48(Slot* t) {
    fn_800804B8(t);
}

void fn_80088ABC(Slot *c) {
    Wk *req = c->work;
    void (*fp)(Slot *) = fn_80087054;
    s16 idx = req->idx;
    Chr_UNIT0000 *o = lbl_80309DE4[idx];
    o->w1c |= 1;
    req->flags |= 1;
    lbl_80309700[idx]->update = fp;
    lbl_80309700[idx]->state = 0;
}

s32 fn_800824F0(u8* pos, s8 val, u8* grid, u8* dir) {
    u8 dx = dir[0];
    u8 dy = dir[1];
    u8 px = pos[0];
    u8 py = pos[1];
    s32 y;
    s32 x;
    switch ((s8)(dy + ((s8)dx + 1) * 16 + 1)) {
    case 0:
        x = (s8)px;
        y = (s8)py;
        if (val == (s8)(grid + y * 11)[x - 12]) {
            pos[1] = y - 1;
            pos[0] = x - 1;
            return 1;
        }
        break;
    case 1:
        x = (s8)px;
        y = (s8)py;
        if (val == (s8)(grid + y * 11)[x - 1]) {
            pos[0] = x - 1;
            return 1;
        }
        break;
    case 2:
        x = (s8)px;
        y = (s8)py;
        if (val == (s8)(grid + y * 11)[x + 10]) {
            pos[1] = y + 1;
            pos[0] = x - 1;
            return 1;
        }
        break;
    case 16:
        x = (s8)px;
        y = (s8)py;
        if (val == (s8)(grid + y * 11)[x - 11]) {
            pos[1] = y - 1;
            return 1;
        }
        break;
    case 18:
        x = (s8)px;
        y = (s8)py;
        if (val == (s8)(grid + y * 11)[x + 11]) {
            pos[1] = y + 1;
            return 1;
        }
        break;
    case 32:
        x = (s8)px;
        y = (s8)py;
        if (val == (s8)(grid + y * 11)[x - 10]) {
            pos[1] = y - 1;
            pos[0] = x + 1;
            return 1;
        }
        break;
    case 33:
        x = (s8)px;
        y = (s8)py;
        if (val == (s8)(grid + y * 11)[x + 1]) {
            pos[0] = x + 1;
            return 1;
        }
        break;
    case 34:
        x = (s8)px;
        y = (s8)py;
        if (val == (s8)(grid + y * 11)[x + 12]) {
            pos[1] = y + 1;
            pos[0] = x + 1;
            return 1;
        }
        break;
    }
    y = (s8)py;
    x = (s8)px;
    if (val == (s8)(grid + y * 11)[x - 1]) {
        pos[0] = x - 1;
    } else if (val == (s8)(grid + y * 11)[x + 1]) {
        pos[0] = x + 1;
    } else if (val == (s8)(grid + y * 11)[x - 11]) {
        pos[1] = y - 1;
    } else if (val == (s8)(grid + y * 11)[x + 11]) {
        pos[1] = y + 1;
    } else if (val == (s8)(grid + y * 11)[x - 12]) {
        pos[1] = y - 1;
        pos[0] = x - 1;
    } else if (val == (s8)(grid + y * 11)[x + 10]) {
        pos[1] = y + 1;
        pos[0] = x - 1;
    } else if (val == (s8)(grid + y * 11)[x - 10]) {
        pos[1] = y - 1;
        pos[0] = x + 1;
    } else if (val == (s8)(grid + y * 11)[x + 12]) {
        pos[1] = y + 1;
        pos[0] = x + 1;
    } else {
        return 0;
    }
    return 1;
}

void fn_8007DEE0(ArgDEE0* a) {
    Spawn* sp = a->sp;
    Tk_8007DEE0* t;
    Wk_8007DEE0* w;
    if (sp->i < (*(G_8007E13C_8007DEE0*)&lbl_80309E5C).tab[(*(G_8007E13C_8007DEE0*)&lbl_80309E5C).idx].count) {
        t = fn_802268E8((void *)((*(void**)&lbl_803475A8)), (void *)(fn_800300C4(5)));
        fn_80061F58(&t->work, 0x58, 0);
        w = t->work;
        w->x0 = fn_8006C9AC((*(G_8007E13C_8007DEE0*)&lbl_80309E5C).tab[(*(G_8007E13C_8007DEE0*)&lbl_80309E5C).idx].recs[sp->i].x0, sp->x2 & 0xFFFF);
        fn_80061F58(&w->pos, 8, 0);
        w->pos->x4 = sp->x4;
        w->pos->x6 = sp->x6;
    }
}

void fn_80081350(Wk* o, s16 id, s16 n, s8 x, s8 y) {
    s8 ox = o->xc;
    s8 oy = o->xd;
    s32 i;
    s32 j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            lbl_80347354[(y + j) * 11 + x + i] = lbl_80347350[(y + j) * 11 + x + i];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            lbl_80347354[(oy + j) * 11 + ox + i] = id + 0x50;
        }
    }
}

void fn_80081648(Wk* d, s16 id) {
    s8 cx = d->xc;
    s8 cy = d->xd;
    s8 tx = d->xe;
    s8 ty = d->xf;
    s8 dx;
    s8 dy;
    s8 n;
    s8 sx;
    s8 sy;
    s8 k;
    s32 i;

    if (cx == tx && cy == ty) {
        return;
    }
    dx = tx - cx;
    dy = ty - cy;
    k = lbl_80309DE4[id]->xac;
    if (__abs(dx) > __abs(dy)) {
        n = __abs(dx);
        sx = dx / n;
        sy = dy / n;
    } else {
        n = __abs(dy);
        sx = dx / n;
        sy = dy / n;
    }
    for (i = 0; i < n; i++) {
        fn_80081350(d, id, k, tx - sx * i, ty - sy * i);
    }
}

void fn_80083878(s32 unused, Out* out, s32 idx, Shape* sh, s8 px, s8 py) {
    s16 w = sh->w;
    s8 d;
    s8 dx;
    s8 h = sh->h;
    s8 dy;
    s8 mx;

    dx = __abs(((Tk_80083878**)lbl_80309700)[idx]->work->x - px);
    while (--w > 0) {
        d = __abs(w + ((Tk_80083878**)lbl_80309700)[idx]->work->x - px);
        dx = dx > d ? dx : d;
    }
    dy = __abs(((Tk_80083878**)lbl_80309700)[idx]->work->y - py);
    while (--h > 0) {
        d = __abs(((Tk_80083878**)lbl_80309700)[idx]->work->y - py);
        dy = dy > d ? dy : d;
    }
    mx = dy > dx ? dy : dx;
    out->max = mx;
    out->score = (s8)(mx + (dy > dx ? dx / 2 : dy / 2));
}

s32 fn_800855AC(s32 i) {
    s8 r;
    s8 cur;

    if (((Chr_UNIT0000_800855AC**)lbl_80309DE4)[i]->w1c & 0x800) {
        r = fn_80083C50(i, 3);
        if (r == -1) {
            lbl_80309174[i].x6 = 1;
            return 0;
        }
        lbl_80309174[i].b4 = r;
        return 2;
    }
    cur = lbl_80309174[i].b4;
    if (cur != -1 && cur > 3 && fn_80078610(cur) != 0) {
        if (fn_80083728(i, cur) != 0 && fn_80082340(i) == 0 && ((Tk_800855AC**)lbl_80309700)[i]->work->x14 <= 4) {
            return 1;
        }
        lbl_80309174[i].x6 = 1;
        return 1;
    }
    r = fn_80083C50(i, 2);
    if (r == -1) {
        lbl_80309174[i].x6 = 1;
        return 0;
    }
    lbl_80309174[i].b4 = r;
    return 2;
}

static inline s32 PickRandomAlive(void) {
    s32* p = ((s32*)lbl_80302C98);
    s32 j;
    s32 n;

    p[0] = -1;
    p[1] = -1;
    p[2] = -1;
    p[3] = -1;
    n = 0;
    for (j = 0; j <= 3; j++) {
        if (fn_80078610(j) != 0) {
            *p++ = j;
            n++;
        }
    }
    return ((s32*)lbl_80302C98)[rand() % n];
}

s32 fn_80088E4C(s32 i) {
    s32 j;

    for (j = 0; j < 4; j++) {
        if (lbl_8030B7F4.party[j] == 1) {
            if (fn_80078610(j) != 0) {
                return j;
            }
            ((ChrState_80088E4C*)lbl_80309174)[i].x0 = 0x226;
            return PickRandomAlive();
        }
    }
    fn_801DBE1C(lbl_802B0C80);
    return j;
}

static inline s32 RandomLivingAlly(void) {
    s32 i;
    s32 n;
    s32* out;

    out = lbl_80302C98;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    n = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i)) {
            lbl_80302C98[n] = i;
            n++;
        }
    }
    return lbl_80302C98[rand() % n];
}

s32 fn_80089074(void) {
    s32 i;
    s32 best = -1;
    s32 bestVal = 0;

    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && !(((Chr_80089074**)lbl_80309DE4)[i]->w1c & 0x200) && bestVal < ((Chr_80089074**)lbl_80309DE4)[i]->x82) {
            best = i;
            bestVal = ((Chr_80089074**)lbl_80309DE4)[i]->x82;
        }
    }
    if (best == -1) {
        return RandomLivingAlly();
    }
    return best;
}

s32 fn_800899C0(s32 a) {
    s32 i;
    s32 n;

    lbl_80302C98[0] = -1;
    lbl_80302C98[1] = -1;
    lbl_80302C98[2] = -1;
    lbl_80302C98[3] = -1;
    lbl_80302C98[4] = -1;
    lbl_80302C98[5] = -1;
    lbl_80302C98[6] = -1;
    lbl_80302C98[7] = -1;
    n = 0;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i) && ((((Chr_800899C0**)lbl_80309DE4)[i]->xe >> 3) & 1) == 0 && !(((Chr_800899C0**)lbl_80309DE4)[i]->xe & 0x10)) {
            lbl_80302C98[n] = i;
            n++;
        }
    }
    if (n != 0) {
        return lbl_80302C98[rand() % n];
    }
    return fn_80089EC8(a);
}

s32 fn_80089AA0(void) {
    s32 i;
    s32 n;
    s32 best;

    lbl_80302C98[0] = -1;
    lbl_80302C98[1] = -1;
    lbl_80302C98[2] = -1;
    lbl_80302C98[3] = -1;
    lbl_80302C98[4] = -1;
    lbl_80302C98[5] = -1;
    lbl_80302C98[6] = -1;
    lbl_80302C98[7] = -1;
    best = 0;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i) && best < ((Chr_80089AA0**)lbl_80309DE4)[i]->x88) {
            best = ((Chr_80089AA0**)lbl_80309DE4)[i]->x88;
        }
    }
    n = 0;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i) && best == ((Chr_80089AA0**)lbl_80309DE4)[i]->x88) {
            lbl_80302C98[n] = i;
            n++;
        }
    }
    return lbl_80302C98[rand() % n];
}

s32 fn_80089BA4(void) {
    s32 i;
    s32 n;
    s32 best;

    lbl_80302C98[0] = -1;
    lbl_80302C98[1] = -1;
    lbl_80302C98[2] = -1;
    lbl_80302C98[3] = -1;
    lbl_80302C98[4] = -1;
    lbl_80302C98[5] = -1;
    lbl_80302C98[6] = -1;
    lbl_80302C98[7] = -1;
    best = 0;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i) && best < ((Chr_80089AA0**)lbl_80309DE4)[i]->x96) {
            best = ((Chr_80089AA0**)lbl_80309DE4)[i]->x96;
        }
    }
    n = 0;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i) && best == ((Chr_80089AA0**)lbl_80309DE4)[i]->x96) {
            lbl_80302C98[n] = i;
            n++;
        }
    }
    return lbl_80302C98[rand() % n];
}

s32 fn_80089CA8(void) {
    s32 i;
    s32 n;
    s32 best;

    lbl_80302C98[0] = -1;
    lbl_80302C98[1] = -1;
    lbl_80302C98[2] = -1;
    lbl_80302C98[3] = -1;
    lbl_80302C98[4] = -1;
    lbl_80302C98[5] = -1;
    lbl_80302C98[6] = -1;
    lbl_80302C98[7] = -1;
    best = 0;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i) && best < ((Chr_80089AA0**)lbl_80309DE4)[i]->x94) {
            best = ((Chr_80089AA0**)lbl_80309DE4)[i]->x94;
        }
    }
    n = 0;
    for (i = 4; i <= 11; i++) {
        if (fn_80078610(i) && best == ((Chr_80089AA0**)lbl_80309DE4)[i]->x94) {
            lbl_80302C98[n] = i;
            n++;
        }
    }
    return lbl_80302C98[rand() % n];
}

s32 fn_8008A174(s32 idx) {
    s32 t;
    s32 r;

    if (lbl_80309DE4[idx]->w1c & 0x800) {
        r = fn_80083C50(idx, 3);
        if (r == -1) {
            lbl_80309174[idx].b4 = r;
            return 0;
        }
        lbl_80309174[idx].b4 = r;
        return 2;
    }
    t = lbl_80309174[idx].b4;
    if (t != -1 && t <= 3 && fn_80083728(idx, t)) {
        lbl_80309174[idx].b4 = t;
        return 2;
    }
    r = fn_80083C50(idx, 1);
    if (r == -1) {
        lbl_80309174[idx].b4 = -1;
        return 0;
    }
    lbl_80309174[idx].b4 = r;
    return 2;
}

s32 fn_80089184(void) {
    s32* out;
    s32 i;
    s32 n;

    out = lbl_80302C98;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    n = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && !(lbl_80309DE4[i]->w1c & 0x80)) {
            lbl_80302C98[n] = i;
            n++;
        }
    }
    if (n != 0) {
        return lbl_80302C98[rand() % n];
    }
    return RandomLivingAlly();
}

s32 fn_800892AC(void) {
    s32* out;
    s32 i;
    s32 n;

    out = lbl_80302C98;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    n = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && !(lbl_80309DE4[i]->w1c & 0x1000)) {
            lbl_80302C98[n] = i;
            n++;
        }
    }
    if (n != 0) {
        return lbl_80302C98[rand() % n];
    }
    return RandomLivingAlly();
}

s32 fn_800893D4(void) {
    s32* out;
    s32 i;
    s32 n;

    out = lbl_80302C98;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    n = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && !(lbl_80309DE4[i]->w1c & 0x80000)) {
            lbl_80302C98[n] = i;
            n++;
        }
    }
    if (n != 0) {
        return lbl_80302C98[rand() % n];
    }
    return RandomLivingAlly();
}

s32 fn_800894FC(void) {
    s32* out;
    s32 i;
    s32 n;

    out = lbl_80302C98;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    n = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && !(lbl_80309DE4[i]->w1c & 0x400)) {
            lbl_80302C98[n] = i;
            n++;
        }
    }
    if (n != 0) {
        return lbl_80302C98[rand() % n];
    }
    return RandomLivingAlly();
}

s32 fn_80089624(void) {
    s32* out;
    s32 i;
    s32 n;

    out = lbl_80302C98;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    n = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && !(lbl_80309DE4[i]->w1c & 0x200)) {
            lbl_80302C98[n] = i;
            n++;
        }
    }
    if (n != 0) {
        return lbl_80302C98[rand() % n];
    }
    return RandomLivingAlly();
}

s32 fn_8008974C(void) {
    s32* out;
    s32 i;
    s32 n;

    out = lbl_80302C98;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    n = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && !(lbl_80309DE4[i]->w1c & 0x800)) {
            lbl_80302C98[n] = i;
            n++;
        }
    }
    if (n != 0) {
        return lbl_80302C98[rand() % n];
    }
    return RandomLivingAlly();
}

s32 fn_80089874(void) {
    s32* out;
    s32 i;
    s32 n;

    out = lbl_80302C98;
    out[0] = -1;
    out[1] = -1;
    out[2] = -1;
    out[3] = -1;
    n = 0;
    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && !(lbl_80309DE4[i]->w1c & 0x4000)) {
            lbl_80302C98[n] = i;
            n++;
        }
    }
    if (n != 0) {
        return lbl_80302C98[rand() % n];
    }
    return RandomLivingAlly();
}

s32 fn_80083ACC(s32 id, s32 kind) {
    s32 i;

    lbl_80302C08[0].x4 = 0x7f;
    lbl_80302C08[0].x0 = -1;
    lbl_80302C08[1].x4 = 0x7f;
    lbl_80302C08[1].x0 = -1;
    lbl_80302C08[2].x4 = 0x7f;
    lbl_80302C08[2].x0 = -1;
    lbl_80302C08[3].x4 = 0x7f;
    lbl_80302C08[3].x0 = -1;
    lbl_80302C08[4].x4 = 0x7f;
    lbl_80302C08[4].x0 = -1;
    lbl_80302C08[5].x4 = 0x7f;
    lbl_80302C08[5].x0 = -1;
    lbl_80302C08[6].x4 = 0x7f;
    lbl_80302C08[6].x0 = -1;
    lbl_80302C08[7].x4 = 0x7f;
    lbl_80302C08[7].x0 = -1;
    lbl_80302C08[8].x4 = 0x7f;
    lbl_80302C08[8].x0 = -1;
    lbl_80302C08[9].x4 = 0x7f;
    lbl_80302C08[9].x0 = -1;
    lbl_80302C08[10].x4 = 0x7f;
    lbl_80302C08[10].x0 = -1;
    lbl_80302C08[11].x4 = 0x7f;
    lbl_80302C08[11].x0 = -1;
    fn_800839D8(id, lbl_80302C08, kind);
    for (i = 11; i >= 0; i--) {
        if (lbl_80302C08[i].x4 != 0x7f) {
            return lbl_80302C08[i].x0;
        }
    }
    return -1;
}

s32 fn_8007E274(u16 x) {
    if (lbl_80309E5C.flags & 0x40000000) {
        return 1;
    }
    lbl_80309E5C.flags = lbl_80309E5C.flags & 0x7fffffff;
    lbl_80309E5C.flags = lbl_80309E5C.flags | 0x40000000;
    lbl_80309E5C.f10 = 1.0f / (f32)x;
    return 0;
}

s32 fn_8007E2D8(u16 x) {
    if (lbl_80309E5C.flags & 0x80000000) {
        return 2;
    }
    if (lbl_80309E5C.flags & 0x40000000) {
        return 1;
    }
    lbl_80309E5C.flags = lbl_80309E5C.flags | 0x80000000;
    lbl_80309E5C.f10 = -1.0f / (f32)x;
    return 0;
}

s32 fn_8007E344(u16 x) {
    if (lbl_80309E5C.flags & 0x10000000) {
        return 1;
    }
    lbl_80309E5C.flags = lbl_80309E5C.flags & ~0x20000000;
    lbl_80309E5C.flags = lbl_80309E5C.flags | 0x10000000;
    lbl_80309E5C.f14 = 1.0f / (f32)x;
    return 0;
}

s32 fn_8007E3A8(u16 x) {
    if (lbl_80309E5C.flags & 0x20000000) {
        return 2;
    }
    if (lbl_80309E5C.flags & 0x10000000) {
        return 1;
    }
    lbl_80309E5C.flags = lbl_80309E5C.flags | 0x20000000;
    lbl_80309E5C.f14 = -1.0f / (f32)x;
    return 0;
}

void fn_8007E44C(Task *t) {
    Work *w = t->work;
    Anim *a;
    void *snd;
    snd = w->snd;
    a = w->anim;
    if (snd == NULL) {
        t->state = 3;
    }
    switch (t->state) {
    case 0:
        if (a->cur >= a->max) {
            t->state = 1;
        } else {
            a->cur++;
        }
        break;
    case 1:
        fn_802307EC(snd, a->v, 0);
        break;
    case 2:
        break;
    case 3:
        t->flags |= 0x40;
        break;
    }
}

s32 fn_80083C50(s32 a, s32 b) {
    E12 *e;
    s32 id;
    int i;
    e = lbl_80302C08;
    for (i = 0; i < 12; i++) {
        e[i].x4 = 0x7f;
        e[i].x0 = -1;
    }
    fn_800839D8(a, e = lbl_80302C08, b);
    id = e->x0;
    do {
        if (fn_80083728(a, id)) {
            return id;
        }
        id = (++e)->x0;
    } while (id != -1);
    return -1;
}

f32 fn_80083F34(s8 a, s8 b)
{
    f32 r;
    switch (b) {
    case 1:
        r = a * 15 - 75;
        break;
    case 2:
        r = a * 15 - 75;
        r += 7.0f;
        break;
    case 3:
        r = a * 15 - 75;
        r += 15.0f;
        break;
    }
    return r;
}

f32 fn_80083FF8(s8 a, s8 b)
{
    f32 r;
    switch (b) {
    case 1:
        r = a * 15 - 75;
        break;
    case 2:
        r = a * 15 - 75;
        r += 7.0f;
        break;
    case 3:
        r = a * 15 - 75;
        r += 15.0f;
        break;
    }
    return r;
}

/* Trace the path back from the walker's position, recording each step and marking the grid. */
s32 fn_80082340(s32 idx) {
    Wk *w = lbl_80309700[idx]->work;
    s32 n = 0;
    s32 i;
    s8 dx, dy;
    if (w->path[0][0] == -1) return 0;
    if (w->path[1][0] == -1) return 0;
    dx = w->path[0][0] - w->xc;
    dy = w->path[0][1] - w->xd;
    i = 0;
    do {
        if (dx != 0 || dy != 0) n++;
        i++;
    } while (w->path[i + 1][0] != -1);
    return n >= 2;
}

s8 fn_800823E4(Wk *w)
{
    s8 i;
    s8 n;
    s32 k;
    u8 pos[2];
    u8 dir[2];
    u8 ox, oy;
    u8 *grid;

    if (w->state == 1 || w->state == 2) {
        w->len = 0;
        return 0;
    }
    n = w->len;
    pos[0] = w->xc;
    pos[1] = w->xd;
    dir[0] = 0;
    dir[1] = 0;
    grid = w->grid;
    for (i = n, k = 0; i > 0; i--, k++) {
        ox = pos[0];
        oy = pos[1];
        fn_800824F0(pos, i, grid, dir);
        dir[0] = ox - pos[0];
        dir[1] = oy - pos[1];
        w->path[k][0] = pos[0];
        w->path[k][1] = pos[1];
        (lbl_80347354 + (s8)pos[1] * 11)[(s8)pos[0]] = i + 0x60;
    }
    w->path[n][0] = -1;
    return n;
}

s32 fn_80082AC0(s8 x, s8 y, u8* grid, s32 idx)
{
    Chr_UNIT0000* chr = lbl_80309DE4[idx];
    int type = chr->xae & 0xC;
    int n = chr->xac;
    int i;
    int k;
    int c;
    u8 u;

    switch (type) {
    case 4:
        for (i = 0; i < n; i++) {
            for (k = 0; k < n; k++) {
                c = grid[(x + i) + (y + k) * 11];
                u = c;
                if (c != idx + 0x50) {
                    if (u >= 0x7C) return 0;
                    if (u >= 0x50 && u <= 0x7F) return 0;
                }
            }
        }
        break;
    case 8:
        for (i = 0; i < n; i++) {
            for (k = 0; k < n; k++) {
                c = grid[(x + i) + (y + k) * 11];
                u = c;
                if (c != idx + 0x50) {
                    if (u == 0 || u >= 0x7D) return 0;
                    if (u >= 0x50 && u <= 0x7F) return 0;
                }
            }
        }
        break;
    case 12:
        for (i = 0; i < n; i++) {
            for (k = 0; k < n; k++) {
                c = grid[(x + i) + (y + k) * 11];
                u = c;
                if (c != idx + 0x50) {
                    if (u >= 0x7D) return 0;
                    if (u >= 0x50 && u <= 0x7F) return 0;
                }
            }
        }
        break;
    }
    return 1;
}

/* The unit's RandomLivingAlly (unit_80074D9C.c): a random living party member. */


/* The living party member (without flag 0x80000) with the highest x94, else a random one.
 * Same shape as fn_80089074, which ranks by x82. */
s32 fn_80088F64(void) {
    s32 i;
    s32 best = -1;
    s32 bestVal = 0;

    for (i = 0; i <= 3; i++) {
        if (fn_80078610(i) && !(lbl_80309DE4[i]->w1c & 0x80000) && bestVal < lbl_80309DE4[i]->x94) {
            best = i;
            bestVal = lbl_80309DE4[i]->x94;
        }
    }
    if (best == -1) {
        return RandomLivingAlly();
    }
    return best;
}

void fn_80084E38(Slot* self) {
    s32 i;
    s32 v;
    Wk* sub;
    sub = self->work;
    i = sub->idx;
    v = lbl_80309174[i].b4;
    switch (self->state) {
    case 0:
        if (fn_8007FFE8(i, 0x16) != 0) {
            fn_800811E4(i, 0);
            self->state = 1;
        }
        break;
    case 1:
        if (fn_8007FFE8(0, 0) != 0 && fn_8007FFE8(1, 0) != 0 && fn_8007FFE8(2, 0) != 0 && fn_8007FFE8(3, 0) != 0
            && fn_8007FAB0(i, v) != 0) {
            s16 old = sub->x3c;
            sub->x3c = lbl_80347390->x8;
            lbl_80309174[i].bd = 0;
            fn_8002DD8C(i, 0, 100);
            sub->x3c = old;
            fn_80081168(i, 0xc);
            lbl_80309730[i].b4 = v;
            lbl_80309730[i].h6 = 0x3d;
            self->state = 0xb;
        }
        break;
    case 11:
        if (fn_8007FFE8(i, 0xc) != 0) {
            fn_800811E4(i, 0);
            self->state = 0xc;
        }
        break;
    case 12:
        if (fn_8007FFE8(0, 0x16) != 0 && fn_8007FFE8(1, 0x16) != 0 && fn_8007FFE8(2, 0x16) != 0 && fn_8007FFE8(3, 0x16) != 0) {
            sub->flags |= 1;
            lbl_80309700[i]->update = fn_80086C48;
            lbl_80309700[i]->state = 0;
        }
        break;
    }
}

static inline u8 AnimOf(s8 v)
{
    u8 m = v;
    switch (v) {
    case 0x46: m = 0xb; break;
    case 0x45: m = 9; break;
    case 0x47: m = 0xc; break;
    case 0x48: m = 0xe; break;
    case 0x49: m = 0x1a; break;
    case 4: m = 3; break;
    case 8: m = 7; break;
    }
    return m;
}

void fn_80085CE0(Slot *t)
{
    s16 i;
    s16 save;
    s32 j;
    Wk *w;
    s8 n;
    s32 k;

    w = t->work;
    i = w->idx;
    j = lbl_80309174[i].b4;

    switch (t->state) {
    case 0:
        if (j == -1) {
            fn_800811E4(i, 0);
            t->state = 0x14;
        } else {
            t->state = 1;
        }
        break;
    case 1:
        if (fn_8007FAB0(i, j) == 0) {
            break;
        }
        if (lbl_80309174[j].x9 != -1) {
            switch (lbl_80309174[j].x9) {
            case 0x46: n = 0xb; break;
            case 0x45: n = 9; break;
            case 0x47: n = 0xc; break;
            case 0x48: n = 0xe; break;
            case 0x49: n = 0x1a; break;
            case 4: n = 3; break;
            case 8: n = 7; break;
            default: n = lbl_80309174[j].x9; break;
            }
            save = lbl_80309700[j]->work->x3c;
            fn_800683D8(i, j, 0, n);
            lbl_80309700[j]->work->x3c = save;
        }
        t->state = 0x64;
    case 0x64:
        fn_80081168(i, 7);
        lbl_80309730[i].b4 = j;
        lbl_80309700[j]->work->flags |= 0x20;
        lbl_80309700[j]->work->x50 = 4;
        lbl_80309730[j].b9 = 0;
        t->state = 0xb;
        break;
    case 0xb:
        if (fn_8007FFE8(i, 7) == 0) {
            break;
        }
        lbl_80347348 = 1;
        if (lbl_80309174[j].x9 != -1) {
            fn_8002DD8C(j, 0, AnimOf(lbl_80309174[j].x9));
        }
        if (lbl_80309174[j].xa != 0) {
            lbl_80309700[j]->work->x50 = 4;
            lbl_80309730[i].b9 = 0;
            t->state = 0xe;
        } else {
            t->state = 0xf;
            fn_800811E4(i, 0);
        }
        break;
    case 0xe:
        if (fn_8007FFE8(i, 0x12) != 0) {
            lbl_80309174[j].xa = 0;
            lbl_80309730[j].xa = 0;
            fn_800811E4(i, 0);
            t->state = 0xf;
        }
        break;
    case 0xf:
        if (fn_8007FFE8(i, 0x16) != 0 && fn_8007FFE8(j, 0x16) != 0) {
            if (lbl_80309DE4[i]->w1c & 0x2100) {
                fn_80081168(i, 0xe);
                lbl_80309DCC[i] = -2;
                t->state = 0x11;
            } else {
                fn_800811E4(i, 0);
                t->state = 0x10;
            }
        }
        break;
    case 0x10:
        if (fn_8007FFE8(i, 0) != 0) {
            w->flags |= 1;
            lbl_80309700[i]->update = fn_80086C48;
            lbl_80309700[i]->state = 0;
        }
        break;
    case 0x11:
        if (fn_8007FFE8(i, 0xe) != 0) {
            w->flags |= 1;
            lbl_80309700[i]->update = fn_8008BE94;
            lbl_80309700[i]->state = 0;
            for (k = 4; k < 12; k++) {
                if (i == lbl_80309730[k].b4) {
                    lbl_80309730[k].b4 = k;
                }
                if (i == lbl_80309730[k].xd) {
                    lbl_80309730[k].xd = k;
                }
            }
            lbl_80347374 &= ~(1 << i);
        }
        break;
    case 0x14:
        if (fn_8007FFE8(i, 0) != 0) {
            lbl_80309700[i]->update = fn_80086C48;
            lbl_80309700[i]->state = 0;
            w->flags |= 2;
        }
        break;
    }
}

void fn_80087844(Slot *t)
{
    s16 i;
    s32 j;
    Wk *w;
    s8 n;
    s32 a;
    s32 b;
    int k;
    int m;

    w = t->work;
    i = w->idx;
    j = lbl_80309174[i].b4;

    switch (t->state) {
    case 0:
        if (j == -1) {
            fn_800811E4(i, 0);
            t->state = 0x14;
        } else if (w->x2 == 0x8a || w->x2 == 0x8b) {
            t->state = 0x64;
        } else {
            t->state = 1;
        }
        break;
    case 0x64:
        if (w->xc == 1) {
            if (w->xd == 1) {
                a = 1;
                b = 7;
            } else {
                a = 7;
                b = 7;
            }
        } else {
            if (w->xd == 1) {
                a = 1;
                b = 1;
            } else {
                a = 7;
                b = 1;
            }
        }
        fn_8008178C(w, a, b, i);
        fn_800810FC(i);
        t->state = 0x65;
        break;
    case 0x65:
        if (fn_8007FFE8(i, 4) != 0) {
            fn_800811E4(i, 0);
            fn_80081648(w, i);
            t->state = 0x66;
        }
        break;
    case 0x66:
        if (fn_8007FFE8(i, 0) != 0) {
            t->state = 1;
        }
        break;
    case 1:
        if (fn_8007FAB0(i, j) == 0) {
            break;
        }
        if (lbl_80309174[j].x9 != -1) {
            s16 save;
            switch (lbl_80309174[j].x9) {
            case 0x46: n = 0xb; break;
            case 0x45: n = 9; break;
            case 0x47: n = 0xc; break;
            case 0x48: n = 0xe; break;
            case 0x49: n = 0x1a; break;
            case 4: n = 3; break;
            case 8: n = 7; break;
            default: n = lbl_80309174[j].x9; break;
            }
            save = lbl_80309700[j]->work->x3c;
            fn_800683D8(i, j, 0, n);
            lbl_80309700[j]->work->x3c = save;
        }
        t->state = 2;
    case 2:
        fn_80081168(i, 7);
        lbl_80309730[i].b4 = j;
        lbl_80309700[j]->work->flags |= 0x20;
        lbl_80309730[j].b9 = 0;
        lbl_80309700[j]->work->x50 = 4;
        t->state = 0xb;
        break;
    case 0xb:
        if (fn_8007FFE8(i, 7) == 0) {
            break;
        }
        lbl_80347348 = 1;
        if (lbl_80309174[j].xa != 0) {
            t->state = 0xe;
            lbl_80309730[i].b9 = 0;
        } else {
            t->state = 0xf;
            fn_800811E4(i, 0);
        }
        break;
    case 0xe:
        if (fn_8007FFE8(i, 0x12) != 0) {
            lbl_80309174[j].xa = 0;
            lbl_80309730[j].xa = 0;
            fn_800811E4(i, 0);
            t->state = 0xf;
        }
        break;
    case 0xf:
        if (fn_8007FFE8(i, 0x16) != 0 && fn_8007FFE8(j, 0x16) != 0) {
            if (lbl_80309DE4[i]->w1c & 0x2100) {
                fn_80081168(i, 0xe);
                lbl_80309DCC[i] = -2;
                t->state = 0x11;
            } else {
                fn_800811E4(i, 0);
                t->state = 0x10;
            }
            if (lbl_80309174[j].x9 != -1) {
                fn_8002DD8C(j, 0, AnimOf(lbl_80309174[j].x9));
            }
        }
        break;
    case 0x10:
        if (fn_8007FFE8(i, 0) != 0) {
            w->flags |= 1;
            lbl_80309700[i]->update = fn_80087054;
            lbl_80309700[i]->state = 0;
        }
        break;
    case 0x11:
        m = i;
        if (fn_8007FFE8(i, 0xe) != 0) {
            for (k = 4; k < 12; k++) {
                if (m == lbl_80309730[k].b4) {
                    lbl_80309730[k].b4 = k;
                }
                if (m == lbl_80309730[k].xd) {
                    lbl_80309730[k].xd = k;
                }
            }
            fn_8008066C(m);
            t->flags18 |= 0x40;
            lbl_80309700[i] = 0;
            lbl_80309DCC[i] = -2;
            lbl_80347374 &= ~(1 << m);
        }
        break;
    case 0x14:
        if (fn_8007FFE8(i, 0) != 0) {
            lbl_80309700[i]->update = fn_80087054;
            lbl_80309700[i]->state = 0;
            w->flags |= 2;
        }
        break;
    }
}

#ifdef NONMATCHING
extern char lbl_802B0C90[];
extern char lbl_802B0CB8[];
#endif

/* fn_8007D42C (unit_80074D9C): the battle music task (fn_80078658 mode 1). It snapshots the enemy
 * slots, then keeps comparing the party's and the enemies' remaining HP and switches between the
 * calm (state 2), pinch (3) and winning (4) phrase sets of the battle track (fn_802182F4). */
#ifdef NONMATCHING
s32 fn_80088CE8(s32 i)
{
    s32 k;
    Chr_UNIT0000** sp;
    s32 n;
    s32* list = lbl_80302C98;
    s32* out2;
    s32* out;
    s32 j;
    s32 res;
    s8 c;
    sp = lbl_80309DE4;
    lbl_80302C98[0] = -1;
    lbl_80302C98[1] = -1;
    lbl_80302C98[2] = -1;
    lbl_80302C98[3] = -1;
    out = list;
    n = 0;
    for (j = 0; j <= 3; j++, sp++) {
        if (fn_80078610(j) && !((*sp)->w1c & 0x4000)) {
            *out++ = j;
            n++;
        }
    }
    if (n != 0) {
        c = lbl_80309174[i].b4;
        if (c > 3) {
            res = lbl_80302C98[rand() % n];
            return res;
        }
        return c;
    } else {
        lbl_80309174[i].x0 = 0x226;
        lbl_80302C98[0] = -1;
        lbl_80302C98[1] = -1;
        lbl_80302C98[2] = -1;
        lbl_80302C98[3] = -1;
        out2 = list;
        n = 0;
        for (k = n; k <= 3; k++) {
            if (fn_80078610(k)) {
                *out2++ = k;
                n++;
            }
        }
        return lbl_80302C98[rand() % n];
    }
}
#endif

#ifdef NONMATCHING
s32 fn_8008A280(s32 i)
{
    s8* pc;
    s8 c;
    s8 r;
    s32 v;
    pc = &lbl_80309174[i].b4;
    c = *pc;
    if (lbl_80309DE4[i]->w1c & 0x800) {
        r = fn_80083BAC(i, 3);
        if (r == -1) {
            for (;;) fn_801DBE1C(lbl_802B0C90);
        }
        *pc = r;
        return 2;
    }
    v = fn_80078478(i);
    if (v == 3 || (v >= 0x20 && v < 0x40)) {
        if (c != -1 && c > 3 && fn_80078610(c)) {
            return 1;
        }
        r = fn_80083BAC(i, 2);
        if (r == -1) {
            *pc = i;
            return 2;
        }
        *pc = r;
        return 2;
    }
    if (v == 1 || (v >= 0x60 && v < 0xC8)) {
        if (c != -1 && c <= 3 && fn_80078610(c)) {
            *pc = c;
            return 1;
        }
        r = fn_80083BAC(i, 1);
        if (r == -1) {
            for (;;) fn_801DBE1C(lbl_802B0CB8);
        }
        *pc = r;
        return 2;
    }
    return 1;
}
#endif

