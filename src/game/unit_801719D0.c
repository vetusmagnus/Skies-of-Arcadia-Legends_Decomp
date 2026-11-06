#include "types.h"
#include "game/stat_8030B4D4.h"
#include "game/work_8030CEA0.h"
#include "game/save_8030B7F4.h"
#include "game/task.h"
#include "game/evobj.h"
#include "game/menu.h"
#include "ninja.h"
#include "ninja_lib.h"
#include "game/camera_803119E0.h"
#include "game/uiobj.h"
#include "game/gamedata.h"
#include "game/text.h"
#include "game/sprite.h"
#include <math.h>
#include <string.h>
#include <dolphin/types.h>
#include "game/camp.h"
extern PadState* lbl_80311A60[];
/* camp_work: the camp menu's panels and the state of each screen. */
typedef struct CampWork {
    s8 *ids;            /* 0x000 */
    void *p04;          /* 0x004 */
    u8 pad08[4];
    s8 count;           /* 0x00C */
    u8 pad0d[3];
    CampPnl *pnl[0xB9]; /* 0x010 */
    u32 state[22];      /* 0x2F4: one per screen, as lbl_80307638 */
    f32 f34c;           /* 0x34C */
    f32 f350;           /* 0x350 */
    f32 f354;           /* 0x354 */
    f32 f358;           /* 0x358 */
    u8 pad35c[4];
} CampWork;
extern CampWork camp_work;
extern CampCtrl lbl_80307638[22];
extern CampTask *lbl_8034710C;
extern s32 fn_80193F78(void);
extern s32 lbl_80347154;
extern s32 camp_screen;
extern void fn_801F2E44(s32 a);
extern void fn_80180EA0(void);
extern void fn_80195A68(void* p, s32 a, s32 b, s32 c, s32 d, s32 e);
extern void fn_80180CCC(void);
extern void fn_80180B80(void);
extern void fn_80180A84(void);
extern s32 CampMenuAnyPanelBusy(void);
extern s32 fn_801C09F8(s32 a, s32 b);
extern void CampMenuFinishAllPanels(void);
extern s32 fn_8017F9D8(void);
extern void fn_8017F840(void);
extern void fn_801808D4(void);
extern void fn_801959D4(s32 n);
typedef struct Node_8018DD24 { s32 x0, x4; u8 ui[0x8c - 8]; f32 f8c; } Node_8018DD24;
typedef struct Obj_8018DD24 { u8 pad0[0x18]; u8 flags; u8 state; u8 pad1a[0x24 - 0x1a]; Node_8018DD24 *node; } Obj_8018DD24;
extern void fn_80199F38(void *ui);
extern const char* fn_801F48AC(s16 n);
extern void fn_801954D0(const char* help);
extern void fn_80174CB0(void);
extern s32 fn_801929B8(s32 idx);
extern s32 fn_8019A21C(u32 mask, s32 d, s32 n, s32 unused, s32 max);
extern void CampMenuHideAllPanels(void);
extern void fn_8017B0F8(void);
extern void fn_8017B19C(void);
extern void fn_8017B2AC(void);
extern void fn_8017B3BC(void);
extern void fn_8017B4E4(void);
extern void fn_8017B5EC(void);
extern s32 fn_801953B8(void);
extern SaveData lbl_8030B7F4;
extern void fn_80199BB8(UiObj *o, f32 x, f32 y);
extern void fn_80199BAC(UiObj *o, f32 x, f32 y);

/* Hide camp panel k (its window's first word is the hidden flag). */
static inline void Hide(CampWork *a, s32 k) {
    a->pnl[k]->win->x0 = 1;
}
/* One entry of a camp menu request (fn_80195EA4 fills six). */
typedef struct CampEnt {
    s8 x0;            /* 0x00 */
    u8 x1;            /* 0x01 */
    u8 x2;            /* 0x02 */
    u8 pad3;
    s16 x4;           /* 0x04 */
    s16 x6;           /* 0x06 */
    u8 pad8[4];
    const char *xc;   /* 0x0C the entry's text */
    const char *x10;  /* 0x10 */
} CampEnt;
/* A camp menu request (0x88): who, which list and page, then the entries. */
typedef struct CampReq {
    s32 a;            /* 0x00 */
    s32 b;            /* 0x04 */
    u8 d;             /* 0x08 */
    s8 count;         /* 0x09 */
    s8 x0a;           /* 0x0A */
    s8 x0b;           /* 0x0B */
    s32 xc;           /* 0x0C */
    CampEnt e[6];     /* 0x10 */
} CampReq;
void fn_80195EA4(CampReq *r, s8 a, s32 b, s32 c, s8 mode);
extern s32 fn_80195D8C(s8 a, s8 b, s32 c, s8 d);
typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 pad;
    f32 f;
    struct Ent2c* entry;
} Rec_80186E20;
extern Ent2c lbl_803072E8[];
s32 fn_801F4CA0();
typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
} Trio;
void fn_8019A15C(void* p, s32 a, s32 b, s32 c);
typedef struct {
    s32 v;
    u8 b;
} Rec_8018E81C;
extern Task* lbl_80347114;
extern void* lbl_8034759C;
extern u8 lbl_80347104[8];
/* lbl_80310B3C: the event flag bits, 32 per word. */
extern u32 lbl_80310B3C[];
extern u32 lbl_80308088[];
extern void* memset(void*, int, unsigned long);
typedef struct Sub_80168A04 {
    u32 w0;
    s32 id;
    u8 pad8[4];
    u8 fc;
    u8 fd;
    u8 pade;
    s8 bF;
    u8 pad10[8];
    u32 f18;            /* 0x18: id << 16 | ... | low byte */
    f32 x1c;            /* 0x1c position */
    f32 x20;
    f32 x24;
    f32 x28;            /* 0x28 range */
    u8 pad2c[4];
    struct Obj_80168A04* x30;   /* previous sound task */
    struct Obj_80168A04* x34;   /* next */
} Sub_80168A04;
typedef struct Obj_80168A04 {
    u8 pad[0x18];
    u8 b18;             /* task flags */
    u8 b19;             /* task state */
    u8 pad1a[0xA];
    Sub_80168A04* sub;
} Obj_80168A04;
extern Sys_80310A1C lbl_80310A1C;
typedef struct Target {
    u8 pad0[0x1c];
    s32 x1c;
    s32 x20;
} Target;
typedef struct Holder_80187F30 {
    CampCtrl* target;
    u8 b4;
} Holder_80187F30;
extern struct Dst_80189958;
extern void fn_80189958(struct Dst_80189958* dst, void* unused, s8 a, s32 b, s8 unused2, s32 c);
extern void fn_801E17E0(void* p);
extern void* fn_801E1C7C(s32 size);
extern void fn_80199F58(void* p);
extern void CampPanelDrawFrame();
extern s32 lbl_803475D8;
typedef struct {
    s32 kind;   /* 0x00 */
    u32 pad04;
    UiObj obj;  /* 0x08 */
    u8 pad54[0x74 - 8 - sizeof(UiObj)];
    Pos_80188274 pos; /* 0x74 */
    u8 pad94[0xbc - 0x94];
    Inn_80188098 *inn; /* 0xbc */
} Inner_8016F138;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_8016F138* inner; /* 0x24 */
} Self_8016F138;
extern s32 fn_801944C4(void);
extern void fn_80195A68(void* p, s32 a, s32 b, s32 c, s32 d, s32 e);
#define CWB ((u8 *)&camp_work)
extern s32 fn_80194490(void);
extern s32 fn_8019445C(void);
extern void fn_80199BB8(UiObj* obj, f32 x, f32 y);
extern void fn_80199BAC(UiObj* obj, f32 x, f32 y);
extern void fn_80193FF8(s32 n);
extern void fn_80193FBC(s32 unused, s32 toggle);
extern s32 (*lbl_803467A8[2])(void);
typedef struct {
    s8* ids;      /* 0x00 */
    void* p04;    /* 0x04 */
    u8 pad08[0x360 - 0x08];
} CampWork_UNIT0000;
extern s32 fn_801953B8(void);
extern s32 fn_80194028(void);
typedef struct {
    u8 pad00[0x14];
    s32 x14;
} CampObj;
extern s16 fn_801838C8(s32 a, s32 b);
extern s32 lbl_803470C8;
extern s32 (*lbl_802E97C0[5])(void);
extern void* lbl_803470DC;
extern void* lbl_803470D8;
extern Obj4* lbl_803470E4;
extern Obj4* lbl_803470D0;
extern void* lbl_803470E0;
void fn_801D6944(void* p);
void fn_801E17E0(void* p);
typedef struct {
    void* p0;
    void* p4;
} P2;
typedef struct {
    f32 f00, f04;          /* 0x00 */
    s32 i08;               /* 0x08 */
    s32 i0c;               /* 0x0C */
    f32 f10, f14, f18, f1c;
    P2* p20;               /* 0x20 */
    F4* p24;               /* 0x24 */
    u8 pad28[4];
    P2* p2c;               /* 0x2C */
    F4* p30;               /* 0x30 */
    u8 pad34[4];
    P2* p38;               /* 0x38 */
    F4* p3c;               /* 0x3C */
    u8 pad40[4];
    void* p44;             /* 0x44 */
} Obj48;
extern void* lbl_803470F4;
typedef struct {
    s32 a;
    s32 b;
} Pair8;
typedef struct {
    Pair8 pairs[11];   /* 0x00 */
    u32 mask0;         /* 0x58 */
    u32 mask1;         /* 0x5C */
} PairSet;
extern void* lbl_803470F0;
extern void* lbl_803470E8;
typedef struct {
    s32 kind;
    u8 pad04[4];
    f32 rect8[4];
    u8 pad_18[0x14];
    f32 x;
    f32 y;
    u8 pad_34[0x88];
    struct Kind_8018E73C* k;
} Sub_8018DFC4;
typedef struct {
    u8 pad00[0x18];
    u8 flags18;
    u8 state19;
    u8 pad1a[0x24 - 0x1a];
    Sub_8018DFC4* p24;
} Obj_8018DFC4;
void fn_80199F38(void* r);
/* The draw argument of fn_800C2650 and its siblings (Arg_800C2650 in
   unit_800B2DA0.c). */
typedef struct Arg_800C2650 {
    f32 f0;
    s16 h4;
    s16 h6;
    f32 f8;
    f32 fc;
} Arg_800C2650;
typedef struct Kind_8018E73C {
    s32 kind;
} Kind_8018E73C;
extern f32 fn_800C2A88(Arg_800C2650 *a);
extern f32 fn_800C287C(Arg_800C2650 *a);
extern f32 fn_800C285C(Arg_800C2650 *a);
extern f32 fn_800C2650(Arg_800C2650 *a);
f32 fn_8018E73C(Sub_8018DFC4 *s);
void fn_8018E0A8(Sub_8018DFC4* s);
extern void* lbl_803470EC;
extern void* lbl_803470F8;
extern void* lbl_80347618;
void fn_801C0FE8(s32 a, s32 b);
void *fn_802267AC(void *a, void *fn);
extern void *lbl_803470F0, *lbl_803470E8, *lbl_803470F4;
void fn_80199FFC(void *p, s32 a, void *b, s32 c, s32 d, s32 e);
typedef struct Dst_80171B64 { u8 pad[4]; void *spr; } Dst_80171B64;
typedef struct Sub_80171B64 { u8 pad[0x94]; Dst_80171B64 *dst; } Sub_80171B64;
typedef struct Hold_80171B64 { u8 pad[0x24]; Sub_80171B64 *sub; } Hold_80171B64;
typedef struct Camp_80171B64 { u8 pad[0xac]; Hold_80171B64 *hold; } Camp_80171B64;
extern void *lbl_803470F0;
void fn_8019520C(s8 idx, void *spr);
typedef struct Hm { u8 pad[0xbc]; void *w; } Hm;
typedef struct Mid_80172B54 { u8 pad[0x24]; Hm *hm; } Mid_80172B54;
typedef struct Camp_80172B54 { u8 pad[0x218]; Mid_80172B54 *mid; } Camp_80172B54;
void fn_80194C68(void *buf, s32 i, s32 j, s32 key);
s32 fn_801E4BF4(s8 k);
s32 fn_801E4BBC(s8 k);
typedef struct { u8 pad[0x24]; Win* in; } Pnl;
extern void CampMenuHideAllPanels(void);
extern s32 fn_80195CD0(s8 a, s8 b, s32 c, s8 d);
extern void fn_801D4F0C(void* spr, f32 f1, f32 f2, f32 f3, f32 f4, s32 a, s32 b, s32 c);
typedef struct { u8 pad[0x74]; f32 f74; } Win74;
typedef struct { u8 pad[0x24]; Win74* in; } Pnl74;
extern void fn_800FF348(void* spr, s32 id, f32 a, f32 b, f32 c);
extern void fn_801954D0(const char* help);
extern s32 lbl_80347154;
extern void fn_80180174(s8 a, s8 mode);
extern s32 CampMenuAnyPanelBusy(void);
extern s32 fn_801C09F8(s32 a, s32 b);
extern void CampMenuFinishAllPanels(void);
extern void fn_80180174(s8 unused, s8 mode);
#define PNL(off) (*(Pnl**)(CWB + (off)))
extern void CampMenuHideAllPanels(void);
extern s32 fn_80194CB8(void);
extern void fn_80199BB8(UiObj* o, f32 x, f32 y);
extern void fn_80199BAC(UiObj* o, f32 x, f32 y);
extern s32 camp_screen;
extern void fn_801959D4(s32 n);
extern const char lbl_802B44A8[];
extern void* fn_801E49D8(const char* name);
extern s32 fn_801E4974(void* h, s32 i);
extern s32 fn_801E48A8(void* h);
extern void* fn_801E4984(void* h, s32 i);
extern void MemCopy(void* dst, const void* src, s32 size);
extern void* fn_801E1584(void* h, s32 size);
extern Obj4* fn_801DB124(void* p);
extern void fn_801D6998(void* dst, void* src);
typedef struct {
    f32 x0;            /* 0x00 */
    f32 x4;            /* 0x04 */
    s32 x8;            /* 0x08 */
    s32 xC;            /* 0x0C */
    f32 x10, x14;      /* 0x10 */
    f32 x18, x1C;      /* 0x18 */
    void** a_ptr;        /* 0x20 */
    f32* a_pos;        /* 0x24 */
    u8 pad28[4];
    void** b_ptr;        /* 0x2C */
    f32* b_pos;        /* 0x30 */
    u8 pad34[4];
    void** c_ptr;        /* 0x38 */
    f32* c_pos;        /* 0x3C */
    u32 x40;
    void* x44;           /* 0x44 */
} Obj_80186D2C;
extern void fn_8019A15C(void* p, s32 a, s32 b, s32 c);
/* The equipment shown by the card of fn_80186F58. */
typedef struct {
    s8 kind;            /* 0x00 */
    u8 pad1[3];
    s32 id;             /* 0x04: item id, -1 for none */
    const char* name;   /* 0x08 */
    u32 users;          /* 0x0c: character bits */
    s32 stat[7];        /* 0x10 */
} Equip_80186F58;
typedef struct {
    u8 pad0[1];
    s8 kind; /* 0x01 */
    u8 pad2[6];
    Equip_80186F58* eq; /* 0x08 */
} Cfg;
typedef struct {
    s32 kind; /* 0x00 */
    s32 x4;
    UiObj obj; /* 0x08 */
    u8 pad[0x74 - 0x08 - sizeof(UiObj)];
    Pos_80188274 pos; /* 0x74 */
    u8 pad94[0xBC - 0x94];
    Cfg* cfg; /* 0xBC */
} Inner_80186E4C;
typedef struct {
    u8 pad[0x18];
    u8 flags; /* 0x18 */
    u8 state; /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_80186E4C* inner; /* 0x24 */
} Self_80186E4C;
extern void fn_80199F38(void* r);
extern void fn_80199F58(void* r);
extern void fn_8018796C(Inner_80186E4C* p);
extern void fn_80186F58(Inner_80186E4C* p);
typedef struct {
    u8 pad0;
    s8 a;  /* 0x01 */
    s8 b;  /* 0x02: 1 = selectable */
    s8 c;  /* 0x03 */
    s32 d; /* 0x04 */
    const char *e; /* 0x08 the line's text */
    const char *f; /* 0x0C */
} DstRec;
typedef struct Dst_80189958 {
    s8 id;        /* 0x00 */
    s8 x1;        /* 0x01 */
    s8 x2;        /* 0x02 */
    s8 ok;        /* 0x03 */
    DstRec rec[6]; /* 0x04 */
} Dst_80189958;
extern void* lbl_80347100;
extern void* fn_801CC0A0(void* p);
typedef struct {
    const char *name; /* 0x00 */
    u8 pad4[0x20];
    s32 id; /* 0x24 */
} Ent_801929FC;
extern Ent_801929FC lbl_802ED258[0x58];
void* fn_802267AC(void* a, void* b);
char* fn_80194C50(s8 i);
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; void* sub; } Win_80178F6C;
typedef struct { u8 pad[0x24]; Win_80178F6C* in; } Pnl_80178F6C;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_80178F6C* pnl[0xcf]; f32 f34c, f350, f354; } CampW_80178F6C;
extern s32 fn_801929B8(s32 idx);
extern void fn_80199BA4(UiObj* o, u8 v);
extern void fn_80199B9C(UiObj* o, f32 v);
extern s32 fn_80194CC8(void);
extern s32 lbl_80347124;
typedef struct {
    s32 kind;   /* 0x00 */
    s32 type;   /* 0x04 */
    UiObj obj;  /* 0x08 */
    u8 pad[0x8c - 8 - sizeof(UiObj)];
    f32 f8c;
} Inner;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner* inner; /* 0x24 */
} Self;
extern void fn_800FF3EC(void* p);
typedef struct { u8 pad0[4]; const char* str; } Sub;
typedef struct {
    s32 kind;   /* 0x00 */
    s32 type;   /* 0x04 */
    UiObj obj;  /* 0x08 */
    u8 pad[0x74 - 8 - sizeof(UiObj)];
    f32 f74;
    u8 pad78[0xbc - 0x78];
    Sub* sub;  /* 0xbc */
} Inner_80189B70;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_80189B70* inner; /* 0x24 */
} Self_80189B70;
/* One stat of the equip compare panel: the value and whether the candidate raises it
   (2), lowers it (3) or keeps it (1). */
typedef struct { s32 cur; s32 st; } StatCmpEnt;
/* The equip compare panel (a camp window's xbc; fn_8018DABC fills its first bytes). */
typedef struct {
    s8 mode;              /* 0x00 */
    s8 b;                 /* 0x01 */
    s8 c;                 /* 0x02 */
    s8 ch;                /* 0x03 */
    s8 lv;                /* 0x04 level */
    u8 pad5[3];
    StatCmpEnt stat[7];   /* 0x08 */
    s32 a40, a44, a48;    /* 0x40: the character's equip slots */
    const char* name[3];  /* 0x4c */
    s32 x58, x5c;         /* 0x58 level values */
    s32 x60[7];           /* 0x60 */
    s32 x7c;
    s32 x80[6];           /* 0x80 */
    s32 x98[6];           /* 0x98 */
} Sub_8018A16C;
typedef struct {
    s32 kind;   /* 0x00 */
    s32 type;   /* 0x04 */
    UiObj obj;  /* 0x08 */
    u8 pad54[0x74 - 8 - sizeof(UiObj)];
    Pos_80188274 pos; /* 0x74 */
    u8 pad94[0xbc - 0x94];
    Sub_8018A16C* sub;  /* 0xbc */
} Inner_8018A16C;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_8018A16C* inner; /* 0x24 */
} Self_8018A16C;
extern void fn_80296EEC(s32 a, s32 b, s32 c);
void fn_8018A2D8(Inner_8018A16C *self);
extern void fn_8018D250(Inner_8018A16C* p);
extern void fn_8018C8B4(Inner_8018A16C* p);
extern void fn_80194F88(void* p);
/* A camp menu option: its id, three label lines and the help line (lbl_802E9908). */
typedef struct CampOption {
    s32 id;
    const char* label[3];
    const char* help;
} CampOption;
extern CampOption lbl_802E9908[];
extern s32 fn_8019A21C(u32 mask, s32 d, s32 n, s32 unused, s32 max);
extern s32 (*lbl_802E9418[3])(void);
extern void fn_80195A68(void* c, s32 a, s32 b, s32 d, s32 e, s32 f);
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0x74 - 8 - sizeof(UiObj)]; f32 f74; u8 pad78[0xbc - 0x78]; } Win_8017D35C;
typedef struct { u8 pad[0x24]; Win_8017D35C* in; } Pnl_8017D35C;
typedef struct { u8 pad[0xc]; s8 count; u8 pad1[3]; Pnl_8017D35C* pnl[0xcf]; } CampW_8017D35C;
typedef struct { s16 x, y; f32 a, b; s8 idx; } Req_80188274;
typedef struct { u8 pad0[0x14]; f32 x, y; } Spr_80188274;
typedef struct { void *spr; } Sp_8018C6A8;
typedef struct {
    f32 f0, f4;
    s32 i8, ic;
    f32 f10, f14, f18, f1c;
    u8 pad20[0x2c - 0x20];
    Sp_8018C6A8 *sp;
    f32 *fp;
    u8 pad34[0x44 - 0x34];
    void *spr44;
} Pos_8018C6A8;
typedef struct { u8 pad0[0x74]; Pos_8018C6A8 pos; } Obj_8018C6A8;
typedef struct { u8 pad0[0x2c]; f32 x, y; u8 pad34[0x74 - 0x34]; f32 z; } Obj_8018FB9C;
extern s32 fn_80195184(s32 x);
extern s32 fn_80195148(s32 x);
extern s32 fn_801950D0(s32 x);
extern s32 fn_8019510C(s32 x);
extern void fn_8019A374(s32 spr, f32 x, f32 y, f32 z, u32 col, s32 n);
typedef struct { s32 row, col, dir, mode, found_idx, found; } Cur_80192EDC;
/* lbl_802EBA00: 24 entries; label is the entry's name. */
typedef struct { s32 x0; u32 id; const char *label; } Ent_80192EDC;
extern Ent_80192EDC lbl_802EBA00[24];
#define PNL_80177D7C(off) (*(Pnl_80177D7C**)(CWB + (off)))
#define PNL_80172C60(off) (*(Pnl_80172C60**)(CWB + (off)))
#define PNL_80173104(off) (*(Pnl_80172C60**)(CWB + (off)))
#define PNL_80174F40(off) (*(Pnl_80172C60**)(CWB + (off)))
#define PNL_801764E4(off) (*(Pnl_80172C60**)(CWB + (off)))
#define PNL_80176868(off) (*(Pnl_80172C60**)(CWB + (off)))
#define PNL_80178D2C(off) (*(Pnl_80172C60**)(CWB + (off)))
extern f32 TextGetZ(void);
#define PNL_8016FB2C(off) (*(u8**)(cw + (off)))
#define PNL2(off) (*(u8**)(CWB + (off)))
#define MID() (*(Mid_8017379C**)(CWB + 0x218))
typedef struct {
    u8 pad0[0x14];
    f32 x;
    f32 y;
} Eff_801784D8;
typedef struct {
    u8 pad0[0x2c];
    f32 rx;
    f32 ry;
} Win_801784D8;
typedef struct {
    u8 pad0[0x24];
    Win_801784D8* win;
} Pnl_801784D8;
extern s8 fn_801952D0(s32 v);
void fn_80217830(u32 a);
typedef struct { s32 hide; u8 pad4[4]; UiObj obj; u8 pad_[0xbc - 8 - sizeof(UiObj)]; } Win_8017BF14;
typedef struct { u8 pad[0x24]; Win_8017BF14* in; } Pnl_8017BF14;
typedef struct { s32 x0, x4; UiObj ui; u8 pad54[0x74 - 8 - sizeof(UiObj)]; Pos_80188274 pos; u8 pad94[0xbc - 0x94]; Dst_80189958 *in; } Node_801887EC;
typedef struct { u8 pad0[0x18]; u8 flags; u8 state; u8 pad1a[0x24 - 0x1a]; Node_801887EC *node; } Obj_801887EC;
typedef struct { u8 pad0[0x24]; Node_801887EC *node; } Ent_801887EC;
typedef struct { u8 pad0[0x2c]; f32 x, y; } Pos_801887EC;
extern u8 lbl_802EBB54[0x13];
extern u8 lbl_802EBB48[0xA];
extern u8 lbl_802EBB34[0x11];
extern u8 lbl_802EBB68[0x14];
extern u8 lbl_802EBB7C[0x18];
extern void fn_80188A18(Node_801887EC *n);
extern void TextPushColor(void);
extern void TextSetColor(u32 c);
extern void TextSetZ(f32 z);
extern void TextPopColor(s32 n);
typedef struct { s32 id; } In_80189EA0;
typedef struct { u8 pad0[0x2c]; f32 x, y; u8 pad34[0x74 - 0x34]; f32 z; u8 pad78[0xbc - 0x78]; In_80189EA0 *in; } Obj_80189EA0;
extern s16 fn_80194378(s8 id);
extern s32 fn_80193F78(void);
#define OBJ(i) (&((Elem*)camp_work.pnl[i])->mid->obj)
#define ND(i) (((Elem2*)camp_work.pnl[i])->n)
#define CW(off, T) (*(T*)((u8*)&camp_work + (off)))
extern s32 fn_8017E5FC(void);
extern void fn_8017E4E4(void);
extern void fn_8017EAEC(void);
extern void fn_8017F540(void);
extern void fn_8017F310(void);
extern void fn_8017F07C(void);
extern void fn_8017EBD8(void);
extern void fn_8017EE48(void);
extern s32 fn_80183D90(void);
extern void fn_80183C54(void);
extern void fn_80184CE8(void);
extern void fn_80184A78(void);
extern void fn_801847F0(void);
extern void fn_801841DC(void);
extern void fn_80184E2C(void);
extern void fn_80184558(void);
extern void fn_80184330(void);
extern s32 fn_8018126C(void);
extern s32 fn_801812C0(void);
typedef struct {
    u8 pad0[0x24];
    Win_80177D7C* in;
} Pnl_80173688;
typedef struct {
    u8 pad0[0x10];
    Pnl* pnl[0xd0]; /* 0x10 */
} CampWork_80184F8C;
typedef struct { u8 pad[4]; Sprite* spr; } Icon;
typedef struct { u8 pad[0x94]; Icon* icon; } Win_80184E2C;
typedef struct { u8 pad[0x24]; Win_80184E2C* in; } Pnl_80184E2C;
typedef struct {
    u8 pad0[0xc];
    s8 count;       /* 0x0c */
    u8 padd[3];
    Pnl_80184E2C* pnl[0xd0]; /* 0x10 */
} CampWork_80184E2C;
typedef struct {
    s32 v[2];
} Slots;
extern char lbl_802E98A0[11][9];
extern char lbl_803467B0[8];
extern s32 fn_80194C7C(void* base, s32 i, s32 j);
typedef struct {
    s32 kind;   /* 0x00 */
    s32 type;   /* 0x04 */
    UiObj obj;  /* 0x08 */
    u8 pad54[0x74 - 0x08 - sizeof(UiObj)];
    f32 z;      /* 0x74 */
} Inner_801918C4;
typedef struct {
    u8 pad0[2];
    char name[0x12]; /* 0x02 */
    s32 hp;          /* 0x14 */
} Info_801918C4;
typedef struct {
    u8 pad0[4];
    Info_801918C4* info;  /* 0x04 */
    u8 pad8[0x360 - 8];
} CampWork_801918C4;
extern s32 fn_80194A8C(s32 a);
extern s32 fn_80194A18(s32 a);
extern const char* fn_80194C38(s8 a);
#define LA(n) (((Pnl_801729D0*)camp_work.pnl[n])->in->la)
typedef struct Obj_80191E94 { u8 pad[0x18]; u8 flags; u8 kind; } Obj_80191E94;
#define OBJ_801763B8(i) (&((Elem*)camp_work.pnl[i])->mid->obj)
typedef struct IconObj_80189214 {
    f32 x;       /* 0x00 */
    f32 y;       /* 0x04 */
    s32 f08;
    s32 f0c;
    f32 f10;
    f32 scale;   /* 0x14 */
    f32 f18;
    f32 f1c;
    void** spr20;
    Vec4f* pos24;
    u8 pad28[0x1c];
    s32 f44;
} IconObj_80189214;
typedef struct { void* spr; } Sp_80191A04;
typedef struct Pos_80191A04 {
    f32 f0, f4;
    s32 i8, ic;
    f32 f10, f14, f18, f1c;
    Sp_80191A04* sp20;
    f32* fp24;
    u8 pad28[4];
    Sp_80191A04* sp;
    f32* fp;
    u8 pad34[0x44 - 0x34];
    void* spr44;
} Pos_80191A04;
extern void fn_8017379C(void);
extern s32 fn_80173688(void);
#define IN(i) (((Elem801732C8 *)camp_work.pnl[i])->in)
#define CW_801732C8(off, T) (*(T *)((u8 *)&camp_work + (off)))
typedef struct Inner_80176D70 {
    s32 kind;
    u32 pad04;
    UiObj obj;
} Inner_80176D70;
typedef struct Elem_80176D70 {
    u8 pad0[0x24];
    Inner_80176D70 *in;
} Elem_80176D70;
extern void fn_80177EFC(void);
extern s32 fn_80174A18(void);
extern void fn_8017567C(void);
extern void fn_80175520(void);
extern void fn_801753D4(void);
extern void fn_801752F4(void);
extern void fn_8017519C(void);
extern void fn_80173104(void);
extern void fn_80172E8C(void);
extern void fn_80172C60(void);
extern void fn_801729D0(void);
extern s32 fn_801720EC(void);
extern void fn_80194B84(s8* out);
extern void fn_801E4A54(s32 n);
extern void fn_801E49F8(s32 n);
extern void fn_80172B54(void);
extern void fn_801723A4(void);
extern void fn_801764E4(void);
extern void fn_80176868(void);
extern void fn_801766C4(void);
extern void fn_801763B8(void);
extern void fn_80175DC4(void);
extern s32 fn_8019576C(s32 a);
extern u8 fn_80195B34(s32);
extern void fn_801EF7E0(void);
extern void fn_80195B38(s8 idx, s32 id, s8 flag);
extern void fn_801957D8(s8 v);
extern s32 fn_801786C0(void);
extern void fn_801784D8(void);
extern void fn_80177D7C(void);
extern void fn_80177C98(void);
extern void fn_80177AC8(void);
extern void fn_80177BD4(void);
extern s32 fn_80177348(void);
extern void fn_80177134(void);
extern void fn_8017796C(void);
#define CW_80176D70(off, T) (*(T *)((u8 *)w + (off)))
#define CG(off, T) (*(T *)((u8 *)&camp_work + (off)))
#define IN_80176D70(i) (((Elem_80176D70 *)camp_work.pnl[i])->in)
typedef struct Self_8018C00C {
    u8 pad0[0x74];
    Obj48 panel;      /* 0x74 */
    s8 *data;         /* 0xBC */
} Self_8018C00C;
extern s32 fn_80194ECC(void);
extern void fn_80194F3C(void);
extern SaveData lbl_8030B7F4;
void fn_80189900(struct Dst_80189958* p, s8 a4, s8 a5, s32 a6, s8 a7);
extern void fn_80179554(void);
extern void fn_80179388(void);

extern s32 lbl_803470C0;
extern s32 fn_801943F4(void);
extern s32 fn_801946E8(s32 a, s32 b, s32 c);

void fn_801719D0(void) {
    s32 i;
    int j;
    CampWork *a;

    CampMenuHideAllPanels();
    a = &camp_work;
    Hide(a, lbl_80307638[1].cur[0].sel);
    for (i = 0; i < a->count; i++) {
        Hide(a, i);
    }
    camp_work.pnl[31]->win->x0 = 1;
    camp_work.pnl[32]->win->x0 = 1;
    camp_work.pnl[33]->win->x0 = 1;
    camp_work.pnl[34]->win->x0 = 1;
    for (j = 0; j < 15; j++) {
        a->pnl[j + 35]->win->x0 = 1;
    }
    if (fn_80193F78() != 0) {
        camp_work.pnl[50]->win->x0 = 1;
    }
}

s32 fn_80173F30(void) {
    CampCtrl *ctl = lbl_8034710C->holder->ctrl;
    UiObj *obj;
    s32 t;

    camp_work.pnl[0x67]->win->x0 = 0;
    switch (ctl->cur[6].mask) {
    case 3:
        if (CampMenuAnyPanelBusy() == 0) {
            ctl->cur[4].x8 = ctl->cur[4].sel;
            ctl->cur[4].sel = fn_8019A21C(ctl->cur[4].mask, lbl_803470C0, ctl->cur[4].sel, 0, 0x10);
            obj = &camp_work.pnl[fn_8019445C()]->win->obj;
            UiObjMoveTo(obj, 6, 4, -8.0f, 123.0f);
            UiObjSetCommand(obj, 0xf, 0);
            ctl->cur[6].mask = 4;
        } else if (fn_801C09F8(lbl_80347154, 7) != 0 || fn_801C09F8(lbl_80347154, 6) != 0) {
            CampMenuFinishAllPanels();
            ctl->cur[4].x8 = ctl->cur[4].sel;
            ctl->cur[4].sel = fn_8019A21C(ctl->cur[4].mask, lbl_803470C0, ctl->cur[4].sel, 0, 0x10);
            obj = &camp_work.pnl[fn_8019445C()]->win->obj;
            UiObjMoveTo(obj, 6, 4, -8.0f, 123.0f);
            UiObjSetCommand(obj, 0xf, 0);
            ctl->cur[6].mask = 4;
        }
        break;
    case 4:
        if (CampMenuAnyPanelBusy() == 0) {
            ctl->cur[6].mask = 6;
        } else if (fn_801C09F8(lbl_80347154, 7) != 0 || fn_801C09F8(lbl_80347154, 6) != 0) {
            CampMenuFinishAllPanels();
            ctl->cur[6].mask = 6;
        }
        break;
    case 5:
        break;
    case 6:
        camp_work.pnl[0x67]->win->x0 = 1;
        if (fn_801C09F8(lbl_80347154, 5) != 0) {
            ctl->cur[0].x8 = ctl->cur[0].sel;
            ctl->cur[0].sel = fn_8019A21C(ctl->cur[0].mask, 1, ctl->cur[0].sel, 0, 0x10);
            goto moved;
        } else if (fn_801C09F8(lbl_80347154, 4) != 0) {
            ctl->cur[0].x8 = ctl->cur[0].sel;
            ctl->cur[0].sel = fn_8019A21C(ctl->cur[0].mask, -1, ctl->cur[0].sel, 0, 0x10);
            goto moved;
        } else if (fn_801C09F8(lbl_80347154, 7) != 0) {
            t = ctl->cur[4].sel;
            if ((t & 1) == 1 || t == 10) {
                lbl_803470C0 = 1;
                ctl->cur[6].mask = 3;
                obj = &camp_work.pnl[fn_8019445C()]->win->obj;
                UiObjMoveTo(obj, 6, 5, -648.0f, 123.0f);
                UiObjSetCommand(obj, 0xf, 0);
            } else {
                ctl->cur[4].x8 = t;
                ctl->cur[4].sel = fn_8019A21C(ctl->cur[4].mask, 1, ctl->cur[4].sel, 0, 0x10);
                if (ctl->cur[4].x8 != ctl->cur[4].sel) {
                    fn_801929B8(0);
                }
            }
        } else if (fn_801C09F8(lbl_80347154, 6) != 0) {
            t = ctl->cur[4].sel;
            if ((t & 1) == 0) {
                lbl_803470C0 = -1;
                ctl->cur[6].mask = 3;
                obj = &camp_work.pnl[fn_8019445C()]->win->obj;
                UiObjMoveTo(obj, 6, 5, -648.0f, 123.0f);
                UiObjSetCommand(obj, 0xf, 0);
            } else {
                ctl->cur[4].x8 = t;
                ctl->cur[4].sel = fn_8019A21C(ctl->cur[4].mask, -1, ctl->cur[4].sel, 0, 0x10);
                if (ctl->cur[4].x8 != ctl->cur[4].sel) {
                    fn_801929B8(0);
                }
            }
        } else if (fn_801C09F8(lbl_80347154, 2) != 0) {
            if (fn_801946E8(ctl->cur[4].sel, ctl->cur[0].sel, fn_801943F4()) != 0) {
                fn_801929B8(2);
                return 1;
            }
            fn_801929B8(3);
        } else if (fn_801C09F8(lbl_80347154, 1) != 0) {
            return -1;
        }
        break;
    moved:
        fn_801929B8(0);
        break;
    }
    return 0;
}

void fn_80177BD4(void)
{
    u8 *p;
    UiObj *obj;
    s32 i;

    i = lbl_80307638[1].cur[0].sel;
    p = (u8 *)camp_work.pnl[i];
    obj = (UiObj *)(*(u8 **)(p + 0x24) + 8);

    UiObjSetRaised(obj);
    fn_80199BB8(obj, -348.0f, 61.0f);
    fn_80199BAC(obj, -348.0f, 61.0f);

    i = lbl_80307638[3].cur[0].sel;
    p = (u8 *)camp_work.pnl[i + 0x1f];
    obj = (UiObj *)(*(u8 **)(p + 0x24) + 8);

    UiObjSetRaised(obj);
    fn_80199BB8(obj, -348.0f, 125.0f);
    fn_80199BAC(obj, -348.0f, 125.0f);
}

void fn_80177EFC(void) {
    CampReq req;
    CampPnl **arr;
    s32 i;
    s32 j;
    s32 k;
    s32 mask;
    s32 idx;
    CampCtrl *c;

    c = lbl_8034710C->holder->ctrl;
    c->cur[1].sel = 0;
    c->cur[1].mask = 0;
    c->cur[4].sel = 0;
    idx = lbl_8030B7F4.party[lbl_80307638[1].cur[0].sel];
    fn_80195EA4(&req, idx, c->cur[1].sel, c->cur[4].sel, 0);
    arr = camp_work.pnl;
    for (i = 0; i < 6; i++) {
        arr[i + 0x34]->win->f74 = -4000.0f;
    }
    for (i = 0; i < 6; i++) {
        fn_80195EA4(&req, idx, i, 0, 0);
        if (req.b != -1) {
            c->cur[1].sel = i;
            c->cur[4].sel = 0;
            break;
        }
    }
    k = c->cur[1].sel + 0x34;
    arr[k]->win->f74 += 150.0f;
    arr[k]->win->f74 += 150.0f;
    c->cur[4].mask = req.x0a;
    mask = 0;
    for (j = 0; j < 6; j++) {
        fn_80195EA4(&req, idx, j, 0, 0);
        if (req.b != -1) {
            mask |= 1 << j;
        }
    }
    c->cur[1].mask = mask;
    c->cur[6].mask = 0;
    fn_80195A68(c, 0, 1, 0, 0, 0);
    fn_801954D0(0);
}

void fn_801791E0(void)
{
    u8 *p;
    UiObj *obj;
    s32 i;

    i = lbl_80307638[1].cur[0].sel;
    p = (u8 *)camp_work.pnl[i];
    obj = (UiObj *)(*(u8 **)(p + 0x24) + 8);

    UiObjSetRaised(obj);
    fn_80199BB8(obj, -348.0f, 61.0f);
    fn_80199BAC(obj, -348.0f, 61.0f);

    i = lbl_80307638[3].cur[0].sel;
    p = (u8 *)camp_work.pnl[i + 0x1f];
    obj = (UiObj *)(*(u8 **)(p + 0x24) + 8);

    UiObjSetRaised(obj);
    fn_80199BB8(obj, -348.0f, 125.0f);
    fn_80199BAC(obj, -348.0f, 125.0f);
}

extern s32 fn_80194428(void);
extern s32 fn_801943C0(void);
extern s32 fn_8019438C(void);
extern s32 fn_80179BA4(void);
extern void fn_800C8F3C(s32 idx);

s32 fn_80179760(void) {
    CampWork *cw = &camp_work;
    UiObj *obj;
    CampCtrl *ctl;

    switch (cw->state[17]) {
    case 0:
        CampMenuHideAllPanels();
        camp_work.pnl[fn_80194490()]->win->x0 = 1;
        camp_work.pnl[fn_80194490()]->win->f74 = -5290.0f;
        camp_work.pnl[fn_80194428()]->win->x0 = 1;
        obj = &camp_work.pnl[fn_80194490()]->win->obj;
        fn_80199BB8(obj, -8.0f, 61.0f);
        fn_80199BAC(obj, -8.0f, 61.0f);
        obj = &camp_work.pnl[fn_80194428()]->win->obj;
        UiObjSetLowered(obj);
        fn_80199BB8(obj, 656.0f, 123.0f);
        fn_80199BAC(obj, 656.0f, 123.0f);
        obj = &camp_work.pnl[fn_80194428()]->win->obj;
        UiObjMoveTo(obj, 6, 4, 16.0f, 123.0f);
        UiObjSetCommand(obj, 0xf, 0);
        ctl = lbl_8034710C->holder->ctrl;
        ctl->cur[0].mask = 0;
        ctl->cur[4].mask = 0;
        fn_80195A68(ctl, 1, 0, 0, 0, 1);
        ctl->cur[6].mask = 6;
        cw->state[17] = 2;
        break;
    case 2:
        if (CampMenuAnyPanelBusy() == 0) {
            cw->state[17] = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            cw->state[17] = 3;
        }
        break;
    case 3:
        switch (fn_80179BA4()) {
        case 0:
            break;
        case -1:
            cw->state[17] = 0x18;
            break;
        case 1:
            cw->state[17] = 0xc;
            break;
        }
        break;
    case 12:
        obj = &camp_work.pnl[fn_80194428()]->win->obj;
        UiObjMoveTo(obj, 6, 5, 656.0f, 123.0f);
        UiObjSetCommand(obj, 0xf, 0);
        cw->state[17] = 0x12;
        break;
    case 18:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.state[fn_801943C0()] = 1;
            camp_screen = fn_801943C0();
            fn_801959D4(fn_801943C0());
            fn_800C8F3C(fn_8019438C());
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.state[fn_801943C0()] = 1;
            camp_screen = fn_801943C0();
            fn_801959D4(fn_801943C0());
            fn_800C8F3C(fn_8019438C());
        }
        break;
    case 24:
        obj = &camp_work.pnl[fn_80194428()]->win->obj;
        UiObjMoveTo(obj, 6, 5, 656.0f, 123.0f);
        UiObjSetCommand(obj, 0xf, 0);
        cw->state[17] = 0x13;
        break;
    case 19:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.state[fn_801943C0()] = 1;
            camp_screen = fn_801943C0();
            fn_801959D4(fn_801943C0());
            fn_800C8F3C(fn_8019438C());
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.state[fn_801943C0()] = 1;
            camp_screen = fn_801943C0();
            fn_801959D4(fn_801943C0());
            fn_800C8F3C(fn_8019438C());
        }
        break;
    }
    return 0;
}

extern void (*lbl_802E9428[4])(void);
extern void fn_801942A4(void);
extern void fn_8017A9FC(void);
extern void fn_8017A8A8(void);
extern void fn_8017A6A4(void);
extern s32 fn_8017A510(void);
extern void fn_8017A754(void);
extern void fn_80194268(void);

s32 fn_8017A040(void) {
    CampWork* cw;
    s32 v;
    fn_801954D0(lbl_802E9908[lbl_8034710C->holder->ctrl->cur[0].sel].help);
    cw = &camp_work;
    switch (cw->state[18]) {
    case 0:
        fn_801942A4();
        CampMenuHideAllPanels();
        camp_work.pnl[29]->win->x0 = 1;
        camp_work.pnl[145]->win->x0 = 1;
        camp_work.pnl[146]->win->x0 = 1;
        camp_work.pnl[147]->win->x0 = 1;
        camp_work.pnl[96]->win->x0 = 1;
        fn_8017A9FC();
        fn_8017A8A8();
        fn_8017A6A4();
        cw->state[18] = 2;
        break;
    case 2:
        if (CampMenuAnyPanelBusy() == 0) {
            cw->state[18] = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            cw->state[18] = 3;
        }
        break;
    case 3: {
        CampCtrl* ctrl;
        CampWin* pan;
        f32 x;
        Sprite* spr;
        v = fn_8017A510();
        ctrl = lbl_8034710C->holder->ctrl;
        pan = camp_work.pnl[145 + ctrl->cur[0].sel]->win;
        x = 5.0f + pan->f74;
        spr = fn_801D68C4(lbl_803470F4, 0x49);
        spr->x = (146.0f + pan->obj.rect[0]) + (f32)(ctrl->cur[4].sel * 0x70);
        spr->y = 17.0f + pan->obj.rect[1];
        fn_800FF348(spr, 2, x, 1.0f, lbl_8034710C->holder->ctrl->f74);
        switch (v) {
        case -1:
            cw->state[18] = 0x18;
            break;
        case 0:
            break;
        case 1:
            cw->state[18] = 0xc;
            break;
        }
        break;
    }
    case 12:
        {
            CampWin* pan;
            CampCtrl* ctrl;
            f32 x;
            Sprite* spr;
            ctrl = lbl_8034710C->holder->ctrl;
            pan = camp_work.pnl[145 + ctrl->cur[0].sel]->win;
            x = 5.0f + pan->f74;
            spr = fn_801D68C4(lbl_803470F4, 0x49);
            spr->x = (146.0f + pan->obj.rect[0]) + (f32)(ctrl->cur[4].sel * 0x70);
            spr->y = 17.0f + pan->obj.rect[1];
            fn_800FF348(spr, 2, x, 1.0f, lbl_8034710C->holder->ctrl->f74);
        }
        cw->state[18] = 0x12;
        break;
    case 18:
        {
            CampWin* pan;
            CampCtrl* ctrl;
            f32 x;
            Sprite* spr;
            ctrl = lbl_8034710C->holder->ctrl;
            pan = camp_work.pnl[145 + ctrl->cur[0].sel]->win;
            x = 5.0f + pan->f74;
            spr = fn_801D68C4(lbl_803470F4, 0x49);
            spr->x = (146.0f + pan->obj.rect[0]) + (f32)(ctrl->cur[4].sel * 0x70);
            spr->y = 17.0f + pan->obj.rect[1];
            fn_800FF348(spr, 2, x, 1.0f, lbl_8034710C->holder->ctrl->f74);
        }
        if (CampMenuAnyPanelBusy() == 0) {
            lbl_802E9428[lbl_8034710C->holder->ctrl->cur[0].sel]();
            fn_801942A4();
            cw->state[18] = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            lbl_802E9428[lbl_8034710C->holder->ctrl->cur[0].sel]();
            fn_801942A4();
            cw->state[18] = 3;
        }
        break;
    case 24:
        fn_8017A754();
        cw->state[18] = 0x13;
        break;
    case 19:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.pnl[187] = 0;
            camp_screen = 2;
            fn_801959D4(2);
            fn_80194268();
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.pnl[187] = 0;
            camp_screen = 2;
            fn_801959D4(2);
            fn_80194268();
        }
        break;
    }
    return 0;
}

void fn_8017A6A4(void) {
    s32 i;
    s32 first;
    u32 mask;
    CampCtrl *ctl;

    mask = 0;
    first = -1;
    ctl = lbl_8034710C->holder->ctrl;
    for (i = 0; i < 3; i++) {
        if (lbl_802E9418[i]() != 0) {
            mask |= 1 << i;
            if (first != -1) {
                first = i;
            }
        }
    }
    ctl->cur[0].mask = mask;
    ctl->cur[4].mask = 0;
    fn_80195A68(ctl, 1, 0, 0, 0, 1);
    fn_801954D0(0);
}

void fn_8017B5EC(void) {
    UiObj* o;
    f32 y;
    s32 i;
    UiObj* a;

    a = &PNL(0x78)->in->obj;
    fn_80199BB8(a, -8.0f, 61.0f);
    fn_80199BAC(a, -8.0f, 61.0f);
    for (i = 0; i < 2; i++) {
        o = &(*(Pnl**)(CWB + 0x22c + i * 4))->in->obj;
        y = (f32)((i + 1) * 64 + 61);
        UiObjSetLowered(o);
        fn_80199BB8(o, -348.0f, y);
        fn_80199BAC(o, -348.0f, y);
    }
}

void fn_80189900(Dst_80189958* p, s8 a4, s8 a5, s32 a6, s8 a7);
extern void fn_8017C6BC(void);
extern void fn_8017C510(void);
extern void fn_8017C2C4(void);
extern void fn_8017C0EC(void);
extern s32 fn_80194ECC(void);
extern const char* fn_801F48AC(s16 n);
extern s32 fn_8017BCA8(void);
extern void fn_8017BBC8(void);
extern void fn_8017BF14(void);

s32 fn_8017B6F4(void) {
    CampWork* cw;
    CampCtrl* ctrl = lbl_8034710C->holder->ctrl;
    CampReq req;
    s32 i;
    s32 n;
    s32 sel;

    sel = lbl_80307638[11].cur[0].sel;
    fn_80195EA4(&req, sel, lbl_80307638[11].cur[2].sel + 6, ctrl->cur[4].sel, 4);
    ctrl->cur[4].mask = 0;
    for (i = 0; i < req.count; i++) {
        ctrl->cur[4].mask |= 1 << i;
    }
    ctrl->cur[0].mask = 0;
    n = fn_80195D8C(sel, lbl_80307638[11].cur[2].sel + 6, 4, ctrl->cur[4].sel);
    for (i = 0; i < n; i++) {
        ctrl->cur[0].mask |= 1 << i;
    }

    cw = &camp_work;
    switch (cw->state[12]) {
    case 0: {
        s32 v;
        fn_8017C6BC();
        fn_8017C510();
        fn_8017C2C4();
        fn_8017C0EC();
        fn_80189900(camp_work.pnl[84]->win->xbc, lbl_80307638[11].cur[0].sel, lbl_80307638[11].cur[2].sel + 6, 4, ctrl->cur[4].sel);
        v = fn_80194ECC();
        if (v != -1) {
            fn_801954D0(fn_801F48AC(v));
        } else {
            fn_801954D0(0);
        }
        cw->state[12] = 2;
        break;
    }
    case 2:
        if (CampMenuAnyPanelBusy() == 0) {
            cw->state[12] = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            cw->state[12] = 3;
        }
        break;
    case 3: {
        s32 v = fn_8017BCA8();
        fn_8017BBC8();
        switch (v) {
        case -1:
            cw->state[12] = 0x18;
            camp_work.pnl[101]->win->x0 = 0;
            break;
        case 0:
            break;
        case 1:
            cw->state[12] = 0xc;
            break;
        }
        break;
    }
    case 12:
        cw->state[12] = 0x12;
        break;
    case 18:
        if (CampMenuAnyPanelBusy() == 0) {
            cw->state[12] = 0;
            camp_screen = 0xc;
            fn_801959D4(0xc);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            cw->state[12] = 0;
            camp_screen = 0xc;
            fn_801959D4(0xc);
        }
        break;
    case 24:
        fn_8017BF14();
        cw->state[12] = 0x13;
        break;
    case 19:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.state[11] = 1;
            camp_screen = 0xb;
            fn_801959D4(0xb);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.state[11] = 1;
            camp_screen = 0xb;
            fn_801959D4(0xb);
        }
        break;
    }
    return 0;
}

extern s32 lbl_80347128;

void fn_8017C6BC(void)
{
    CampReq buf;
    CampCtrl* g = lbl_80307638;
    CampCtrl* c;
    s32 id;
    s32 i, n;

    c = lbl_8034710C->holder->ctrl;
    camp_work.pnl[0x50]->win->f74 = -4000.0f;
    camp_work.pnl[0x51]->win->f74 = -4000.0f;
    camp_work.pnl[0x52]->win->f74 = -4000.0f;
    camp_work.pnl[0x53]->win->f74 = -4000.0f;
    camp_work.pnl[0x54]->win->f74 = -4000.0f;
    camp_work.pnl[0x55]->win->f74 = -4000.0f;
    c->cur[0].sel = 0;
    camp_work.pnl[0x54]->win->f74 += 150.0f;
    camp_work.pnl[0x54]->win->f74 += 150.0f;
    c->cur[2].sel = g[4].cur[2].sel;
    id = g[11].cur[0].sel;
    fn_80195EA4(&buf, id, g[11].cur[2].sel + 6, c->cur[4].sel, 4);
    c->cur[4].sel = 0;
    c->cur[4].mask = 0;
    for (i = 0; i < buf.count; i++) {
        c->cur[4].mask |= 1 << i;
    }
    c->cur[0].sel = 0;
    c->cur[0].mask = 0;
    n = fn_80195D8C(id, g[11].cur[2].sel + 6, 4, c->cur[4].sel);
    for (i = 0; i < n; i++) {
        c->cur[0].mask |= 1 << i;
    }
    fn_80195A68(c, 1, 0, 0, 0, 1);
    lbl_80347128 = 0;
    fn_801954D0(0);
}

/* What camp_work.p04 points at (fn_8017C948): two five-entry lists at 0x18 and 0x22. */
typedef struct CampP04 { u8 pad[0x18]; s16 a[5]; s16 b[5]; } CampP04;
extern s32 fn_8017CD88(void);
extern void fn_8017CC70(void);
extern void fn_8017D250(void);
extern void fn_8017E174(void);
extern void fn_8017DF14(void);
extern void fn_8017DA28(void);
extern void fn_8017DCB4(void);
extern void fn_8017D534(void);
extern void fn_8017D35C(void);
extern void fn_8017D7C0(void);

s32 fn_8017C948(void)
{
    CampP04* t;
    s32 r;
    s32 v;
    CampCtrl* c;

    t = camp_work.p04;
    c = lbl_8034710C->holder->ctrl;
    switch (camp_work.state[11]) {
    case 0:
        fn_8017D250();
        fn_8017E174();
        fn_8017DF14();
        fn_8017DA28();
        camp_work.state[11] = 2;
        switch (c->cur[2].sel) {
        case 0:
            v = t->a[c->cur[0].sel];
            break;
        case 1:
            v = t->b[c->cur[0].sel];
            break;
        }
        if (v != -1) {
            fn_801954D0(fn_801F48AC(v));
        } else {
            fn_801954D0(0);
        }
        break;
    case 1:
        fn_8017D250();
        fn_8017E174();
        fn_8017DCB4();
        fn_8017D534();
        camp_work.state[11] = 2;
        switch (c->cur[2].sel) {
        case 0:
            v = t->a[c->cur[0].sel];
            break;
        case 1:
            v = t->b[c->cur[0].sel];
            break;
        }
        if (v != -1) {
            fn_801954D0(fn_801F48AC(v));
        } else {
            fn_801954D0(0);
        }
        break;
    case 2:
        if (!CampMenuAnyPanelBusy()) {
            camp_work.state[11] = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            camp_work.state[11] = 3;
        }
        break;
    case 3:
        r = fn_8017CD88();
        fn_8017CC70();
        switch (r) {
        case -1:
            camp_work.state[11] = 0x18;
            break;
        case 0:
            break;
        case 1:
            camp_work.state[11] = 0xc;
            break;
        }
        break;
    case 12:
        fn_8017D35C();
        camp_work.state[11] = 0x12;
        break;
    case 18:
        if (!CampMenuAnyPanelBusy()) {
            camp_work.state[12] = 0;
            camp_screen = 0xc;
            fn_801959D4(0xc);
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            camp_work.state[12] = 0;
            camp_screen = 0xc;
            fn_801959D4(0xc);
        }
        break;
    case 24:
        fn_8017D7C0();
        camp_work.state[11] = 0x13;
        break;
    case 19:
        if (!CampMenuAnyPanelBusy()) {
            camp_work.state[1] = 0;
            camp_screen = 1;
            fn_801959D4(1);
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            camp_work.state[1] = 0;
            camp_screen = 1;
            fn_801959D4(1);
        }
        break;
    }
    return 0;
}

void fn_8017D7C0(void) {
    CampCtrl* c;
    UiObj* o;
    s32 i;
    s32 base;
    s32 n;
    s32 off;

    c = lbl_8034710C->holder->ctrl;
    o = &camp_work.pnl[4]->win->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    o = &camp_work.pnl[0x78 + lbl_80307638[4].cur[0].sel]->win->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 125.0f);
    UiObjSetCommand(o, 15, 1);
    o = &camp_work.pnl[0x6e]->win->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 189.0f);
    UiObjSetCommand(o, 15, 2);
    o = &camp_work.pnl[0x6f]->win->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 253.0f);
    UiObjSetCommand(o, 15, 3);
    switch (c->cur[2].sel) {
    case 0: base = 0x7a; n = 5; off = 0; break;
    case 1: base = 0x7f; n = 3; off = 0; break;
    }
    for (i = 0; i < n; i++) {
        o = &camp_work.pnl[base + i]->win->obj;
        UiObjMoveTo(o, 6, 5, 668.0f, (off + i) * 64 + 61);
        UiObjSetCommand(o, 15, i + off);
        camp_work.pnl[base + i]->win->f74 -= 150.0f;
    }
    o = &camp_work.pnl[0x60]->win->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_8017DCB4(void) {
    UiObj* o;
    s32 i;
    UiObj* a;
    f32 y;

    a = &camp_work.pnl[lbl_80307638[1].cur[0].sel]->win->obj;
    fn_80199BB8(a, -8.0f, 61.0f);
    fn_80199BAC(a, -8.0f, 61.0f);
    o = &camp_work.pnl[0x78 + lbl_80307638[4].cur[0].sel]->win->obj;
    fn_80199BB8(o, -8.0f, 125.0f);
    fn_80199BAC(o, -8.0f, 125.0f);
    o = &camp_work.pnl[0x6e]->win->obj;
    fn_80199BB8(o, -348.0f, 189.0f);
    fn_80199BAC(o, -348.0f, 189.0f);
    o = &camp_work.pnl[0x6f]->win->obj;
    fn_80199BB8(o, -348.0f, 253.0f);
    fn_80199BAC(o, -348.0f, 253.0f);
    for (i = 0; i < 5; i++) {
        o = &camp_work.pnl[0x7a + i]->win->obj;
        UiObjSetLowered(o);
        y = i * 64 + 61;
        fn_80199BB8(o, 668.0f, y);
        fn_80199BAC(o, 668.0f, y);
    }
    for (i = 5; i < 8; i++) {
        o = &camp_work.pnl[0x7a + i]->win->obj;
        UiObjSetLowered(o);
        y = (i - 5) * 64 + 61;
        fn_80199BB8(o, 668.0f, y);
        fn_80199BAC(o, 668.0f, y);
    }
    o = &camp_work.pnl[0x60]->win->obj;
    fn_80199BB8(o, 632.0f, 480.0f);
    fn_80199BAC(o, 632.0f, 480.0f);
}

void fn_8017E174(void)
{
    s32 i;
    UiObj* o;
    CampMenuHideAllPanels();
    camp_work.pnl[4]->win->x0 = 1;
    camp_work.pnl[0x78 + lbl_80307638[4].cur[0].sel]->win->x0 = 1;
    camp_work.pnl[0x6e]->win->x0 = 1;
    camp_work.pnl[0x6f]->win->x0 = 1;
    for (i = 0; i < 8; i++) {
        camp_work.pnl[0x7a + i]->win->x0 = 1;
        o = &camp_work.pnl[0x7a + i]->win->obj;
        fn_80199BA4(o, 1);
        fn_80199B9C(o, 0.7f);
    }
    camp_work.pnl[0x60]->win->x0 = 1;
}

extern s32 fn_801953B0(void);
void fn_8017EAEC(void)
{
    CampCtrl* c = lbl_8034710C->holder->ctrl;
    s32 i;
    c->cur[0].sel = 0;
    c->cur[0].x8 = 0;
    if (fn_801953B0() == 1) {
        c->cur[0].mask = 3;
    } else {
        c->cur[0].mask = 1;
    }
    c->cur[2].mask = 3;
    fn_80195A68(c, 1, 0, 0, 0, 1);
    for (i = 0; i < 8; i++) {
        camp_work.pnl[0x7a + i]->win->f74 = -6190.0f;
    }
}

s32 fn_8018126C(void) {
    CampReq req;
    s32 off = lbl_80307638[1].cur[0].sel;
    s32 v = lbl_8030B7F4.party[off];
    fn_80195EA4(&req, v, 0, 0, 2);
    return req.xc;
}

/* The item table (as in evobj.c). */
extern CampCtrl* fn_80195540(CampReq* r);
extern void fn_80182DF4(void);
extern void fn_80181D94(void);

static inline s32 CampKind(void) {
    CampReq req;
    CampCtrl* s = lbl_80307638;
    s32 kind;
    s32 special;
    s32 v;
    s32 id;
    s32 who;
    if (s[3].cur[0].sel == 1) {
        kind = 0;
    } else if (s[7].cur[1].sel == 0) {
        who = lbl_8030B7F4.party[s[7].cur[0].sel];
        fn_80195EA4(&req, who, s[7].cur[1].sel, s[7].cur[4].sel, 0);
        id = req.e[s[7].cur[0].sel].x6 - 0xf0;
        v = lbl_802C7C34[id].effect;
        switch (v) {
        case 0x35:
        case 0x4b:
        case 0x4c:
            special = 1;
            break;
        default:
            special = 0;
            break;
        }
        if (special != 0) {
            kind = 3;
        } else {
            kind = 1;
        }
    } else {
        kind = 2;
    }
    return kind;
}

void fn_80182A3C(void);
void fn_801825D8(void);
void fn_801822A0(void);
void fn_80181F58(void);
s32 fn_801818EC(void);
extern const char* lbl_802F7208[];



static inline void HideList(void) {
    s32 i;
    for (i = 0; i < camp_work.count; i++) {
        camp_work.pnl[i]->win->x0 = 1;
    }
}

static inline void MoveList(void) {
    s32 i;
    UiObj* ui;
    for (i = 0; i < camp_work.count; i++) {
        ui = &camp_work.pnl[i]->win->obj;
        UiObjMoveTo(ui, 6, 4, -348.0f, (f32)(61 + i * 64));
        UiObjSetCommand(ui, 10, i);
    }
}

s32 fn_80181318(void) {
    CampCtrl* slots = lbl_80307638;
    CampReq req;
    CampWork* cw;
    CampCtrl* slot;
    CampCtrl* ctrl;
    s32 s;
    s32 who;
    s32 sel;

    sel = slots[3].cur[0].sel;
    switch (sel) {
    case 0:
        s = 7;
        break;
    case 1:
        s = 5;
        break;
    case 2:
        s = 10;
        break;
    case 3:
        s = 8;
        break;
    default:
        s = 7;
        break;
    }
    slot = &lbl_80307638[s];
    ctrl = lbl_8034710C->holder->ctrl;

    if (sel == 1) {
        who = lbl_8030B7F4.party[slots[1].cur[0].sel];
        fn_80195EA4(&req, who, ctrl->cur[1].sel, ctrl->cur[4].sel, 1);
        if (ctrl->cur[0].sel == 4) {
            fn_801954D0(lbl_802F7208[req.e[slot->cur[0].sel].x6]);
        } else {
            fn_801954D0(req.e[slot->cur[0].sel].x10);
        }
    }
    cw = &camp_work;
    switch (cw->state[6]) {
    case 0:
        fn_80182A3C();
        HideList();
        if (fn_801953B8() != 0) {
            camp_work.pnl[4]->win->x0 = 1;
        }
        switch (CampKind()) {
        case 3:
            camp_work.pnl[0x95]->win->x0 = 1;
            camp_work.pnl[0x96]->win->x0 = 1;
            break;
        }
        fn_80181F58();
        fn_801825D8();
        cw->state[6] = 2;
        break;
    case 2:
        if (CampMenuAnyPanelBusy() == 0) {
            cw->state[6] = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            cw->state[6] = 3;
        }
        break;
    case 3:
        switch (fn_801818EC()) {
        case 0:
            break;
        case -1:
            cw->state[6] = 0x18;
            break;
        case 1:
            cw->state[6] = 0xc;
            break;
        }
        break;
    case 12:
        fn_801822A0();
        cw->state[6] = 0x12;
        break;
    case 18:
        CampMenuAnyPanelBusy();
        break;
    case 24:
        fn_801822A0();
        switch (CampKind()) {
        case 3:
            MoveList();
            break;
        }
        cw->state[6] = 0x13;
        break;
    case 19:
        if (CampMenuAnyPanelBusy() == 0) {
            sel = slots[3].cur[0].sel;
            switch (sel) {
            case 0:
                s = 7;
                break;
            case 1:
                s = 5;
                break;
            case 2:
                s = 10;
                break;
            case 3:
                s = 8;
                break;
            }
            camp_work.state[s] = 1;
            camp_screen = s;
            fn_801959D4(s);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            sel = slots[3].cur[0].sel;
            switch (sel) {
            case 0:
                s = 7;
                break;
            case 1:
                s = 5;
                break;
            case 2:
                s = 10;
                break;
            case 3:
                s = 8;
                break;
            }
            camp_work.state[s] = 1;
            camp_screen = s;
            fn_801959D4(s);
        }
        break;
    }
    return 0;
}

s32 fn_801818EC(void) {
    CampCtrl* slots = lbl_80307638;
    CampCtrl* ctrl = lbl_8034710C->holder->ctrl;
    CampReq req;
    CampCtrl* slot;

    slot = fn_80195540(&req);
    if (req.e[slot->cur[0].sel].x0 == 0) {
        fn_801929B8(3);
        return -1;
    }
    slot = fn_80195540(&req);
    switch (req.e[slot->cur[0].sel].x4) {
    case 1:
        if (fn_801C09F8(lbl_80347154, 5) != 0) {
            ctrl->cur[0].x8 = ctrl->cur[0].sel;
            ctrl->cur[0].sel = fn_8019A21C(ctrl->cur[0].mask, 1, ctrl->cur[0].sel, 0, 7);
            goto moved_cursor;
        } else if (fn_801C09F8(lbl_80347154, 4) != 0) {
            ctrl->cur[0].x8 = ctrl->cur[0].sel;
            ctrl->cur[0].sel = fn_8019A21C(ctrl->cur[0].mask, -1, ctrl->cur[0].sel, 0, 7);
            goto moved_cursor;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0) {
            goto confirm;
        } else if (fn_801C09F8(lbl_80347154, 1) != 0) {
            fn_801929B8(5);
            return -1;
        }
        goto done;
    case 2:
        if (fn_801C09F8(lbl_80347154, 2) != 0) {
            goto confirm;
        } else if (fn_801C09F8(lbl_80347154, 1) != 0) {
            return -1;
        }
        goto done;
    case 0:
    case 0xf0:
        if (fn_801C09F8(lbl_80347154, 2) != 0) {
            goto confirm;
        } else if (fn_801C09F8(lbl_80347154, 1) != 0) {
            return -1;
        }
        goto done;
    default:
        goto done;
    }

moved_cursor:
    {
        CampPnl** objs = camp_work.pnl;
        UiObjSetCommand(&objs[ctrl->cur[0].sel]->win->obj, 0x15, 0);
        fn_801929B8(4);
        UiObjSetCommand(&objs[ctrl->cur[0].x8]->win->obj, 0x14, 0);
        fn_801929B8(4);
    }
    goto done;

confirm:
    {
        s32 id0;
        s32 party;
        s8 a;
        s8 b;
        CampCtrl* sel;
        CampPnl** objs;
        s32 idx;
        slot = fn_80195540(&req);
        id0 = req.e[slot->cur[0].sel].x6;
        switch (CampKind()) {
        case 2:
            fn_80182DF4();
            break;
        case 1:
            fn_80182DF4();
            break;
        case 0:
            fn_80182DF4();
            break;
        case 3:
            fn_80182DF4();
            break;
        }
        slot = fn_80195540(&req);
        if (id0 != req.e[slot->cur[0].sel].x6) {
            a = slot->cur[1].sel;
            b = slot->cur[4].sel;
            fn_80181D94();
            sel = fn_80195540(&req);
            party = lbl_8030B7F4.party[slots[1].cur[0].sel];
            fn_80195EA4(&req, party, a, b, 0);
            if (req.b != -1) {
                sel->cur[1].sel = a;
                if (req.count > b) {
                    sel->cur[4].sel = b;
                    if (fn_80195D8C(party, sel->cur[1].sel, 0, sel->cur[4].sel) <= sel->cur[0].sel) {
                        sel->cur[0].sel--;
                    }
                }
            }
            objs = camp_work.pnl;
            objs[0x34]->win->f74 = -4000.0f;
            objs[0x35]->win->f74 = -4000.0f;
            objs[0x36]->win->f74 = -4000.0f;
            objs[0x37]->win->f74 = -4000.0f;
            objs[0x38]->win->f74 = -4000.0f;
            objs[0x39]->win->f74 = -4000.0f;
            idx = sel->cur[1].sel + 0x34;
            objs[idx]->win->f74 += 150.0f;
            objs[idx]->win->f74 += 150.0f;
            return -1;
        }
    }
done:
    return 0;
}

void fn_80181D94(void) {
    CampPnl **arr;
    s32 i;
    s32 idx;
    CampCtrl *c;
    s32 k;
    u32 mask;
    CampReq req;

    c = &lbl_80307638[7];
    lbl_80307638[7].cur[1].sel = 0;
    c->cur[1].mask = 0;
    c->cur[4].sel = 0;
    idx = lbl_8030B7F4.party[lbl_80307638[1].cur[0].sel];
    fn_80195EA4(&req, idx, 0, 0, 0);
    arr = camp_work.pnl;
    arr[0x34]->win->f74 = -4000.0f;
    arr[0x35]->win->f74 = -4000.0f;
    arr[0x36]->win->f74 = -4000.0f;
    arr[0x37]->win->f74 = -4000.0f;
    arr[0x38]->win->f74 = -4000.0f;
    arr[0x39]->win->f74 = -4000.0f;
    i = 0;
    do {
        fn_80195EA4(&req, idx, i, 0, 0);
        if (req.b != -1) {
            c->cur[1].sel = i;
            c->cur[4].sel = 0;
            break;
        }
        i++;
    } while (i < 6);
    k = c->cur[1].sel + 0x34;
    arr[k]->win->f74 += 150.0f;
    arr[k]->win->f74 += 150.0f;
    c->cur[4].mask = req.x0a;
    mask = 0;
    for (i = 0; i < 6; i++) {
        fn_80195EA4(&req, idx, i, 0, 0);
        if (req.b != -1) {
            mask |= 1 << i;
        }
    }
    c->cur[1].mask = mask;
    c->cur[6].mask = 0;
    fn_80195A68(c, 0, 1, 0, 0, 0);
    fn_801954D0(0);
}

void fn_80181F58(void) {
    s32 i;
    UiObj* ui;
    f32 y;

    switch (CampKind()) {
    case 0:
        for (i = 0; i < camp_work.count; i++) {
            ui = &camp_work.pnl[i]->win->obj;
            y = i * 64 + 61;
            UiObjSetLowered(ui);
            fn_80199BB8(ui, -348.0f, y);
            fn_80199BAC(ui, -348.0f, y);
        }
        if (fn_801953B8()) {
            ui = &camp_work.pnl[4]->win->obj;
            UiObjSetLowered(ui);
            fn_80199BB8(ui, -348.0f, 317.0f);
            fn_80199BAC(ui, -348.0f, 317.0f);
        }
        break;
    case 1:
        for (i = 0; i < camp_work.count; i++) {
            ui = &camp_work.pnl[i]->win->obj;
            y = i * 64 + 61;
            UiObjSetLowered(ui);
            fn_80199BB8(ui, -348.0f, y);
            fn_80199BAC(ui, -348.0f, y);
        }
        break;
    case 2:
        if (fn_801953B8()) {
            ui = &camp_work.pnl[4]->win->obj;
            UiObjSetLowered(ui);
            fn_80199BB8(ui, -348.0f, 317.0f);
            fn_80199BAC(ui, -348.0f, 317.0f);
        }
        break;
    case 3:
        ui = &camp_work.pnl[0x95]->win->obj;
        UiObjSetLowered(ui);
        fn_80199BB8(ui, -348.0f, 61.0f);
        fn_80199BAC(ui, -348.0f, 61.0f);
        ui = &camp_work.pnl[0x96]->win->obj;
        UiObjSetLowered(ui);
        fn_80199BB8(ui, 668.0f, 61.0f);
        fn_80199BAC(ui, 668.0f, 61.0f);
        break;
    }
}

void fn_801822A0(void) {
    s32 i;
    UiObj* ui;

    switch (CampKind()) {
    case 0:
        for (i = 0; i < camp_work.count; i++) {
            ui = &camp_work.pnl[i]->win->obj;
            UiObjMoveTo(ui, 6, -1, -348.0f, i * 64 + 61);
            UiObjSetCommand(ui, 15, 0);
        }
        if (fn_801953B8()) {
            ui = &camp_work.pnl[4]->win->obj;
            UiObjMoveTo(ui, 6, -1, -348.0f, 317.0f);
            UiObjSetCommand(ui, 15, 0);
        }
        break;
    case 1:
        for (i = 0; i < camp_work.count; i++) {
            ui = &camp_work.pnl[i]->win->obj;
            UiObjMoveTo(ui, 6, -1, -348.0f, i * 64 + 61);
            UiObjSetCommand(ui, 15, 0);
        }
        break;
    case 2:
        if (fn_801953B8()) {
            ui = &camp_work.pnl[4]->win->obj;
            UiObjMoveTo(ui, 6, -1, -348.0f, 317.0f);
            UiObjSetCommand(ui, 15, 0);
        }
        break;
    case 3:
        ui = &camp_work.pnl[0x95]->win->obj;
        UiObjMoveTo(ui, 6, -1, -348.0f, 61.0f);
        UiObjSetCommand(ui, 15, 0);
        ui = &camp_work.pnl[0x96]->win->obj;
        UiObjMoveTo(ui, 6, 5, 668.0f, 61.0f);
        UiObjSetCommand(ui, 15, 0);
        break;
    }
    fn_801929B8(5);
}

extern const char* lbl_802F7208[];

void fn_80182A3C(void) {
    CampReq req;
    CampCtrl* slots = lbl_80307638;
    u32 m;
    CampCtrl* slot;
    s32 i;
    CampCtrl* ctrl;
    s32 who;

    slot = fn_80195540(&req);
    ctrl = lbl_8034710C->holder->ctrl;

    switch (CampKind()) {
    case 0:
        m = 0;
        for (i = 0; i < camp_work.count; i++) m |= 1 << i;
        if (fn_801953B8() != 0) m |= 0x10;
        ctrl->cur[0].mask = m;
        ctrl->cur[0].sel = 0;
        who = lbl_8030B7F4.party[slots[1].cur[0].sel];
        fn_80195EA4(&req, who, ctrl->cur[1].sel, ctrl->cur[4].sel, 1);
        if (ctrl->cur[0].sel == 4) {
            fn_801954D0(lbl_802F7208[req.e[slot->cur[0].sel].x6]);
        } else {
            fn_801954D0(req.e[slot->cur[0].sel].x10);
        }
        break;
    case 1:
        m = 0;
        for (i = 0; i < camp_work.count; i++) m |= 1 << i;
        ctrl->cur[0].mask = m;
        ctrl->cur[0].sel = 0;
        break;
    case 2:
        ctrl->cur[0].mask = 0x10;
        ctrl->cur[0].sel = 4;
        break;
    case 3:
        ctrl->cur[0].mask = 1;
        ctrl->cur[0].sel = 0;
        break;
    }
    fn_80195A68(ctrl, 1, 0, 0, 0, 0);
}

void fn_801825D8(void) {
    CampCtrl* ctrl = lbl_8034710C->holder->ctrl;
    s32 i;
    UiObj* ui;
    CampCtrl* slot;
    CampReq req;

    switch (CampKind()) {
    case 0:
        for (i = 0; i < camp_work.count; i++) {
            ui = &camp_work.pnl[i]->win->obj;
            UiObjMoveTo(ui, 6, 4, -8.0f, (f32)(61 + i * 64));
            slot = fn_80195540(&req);
            switch (req.e[slot->cur[0].sel].x4) {
            case 1:
                if (ctrl->cur[0].sel == i) {
                    UiObjSetCommand(ui, 10, i);
                } else {
                    UiObjSetCommand(ui, 0xf, i + 1);
                }
                break;
            case 2:
                UiObjSetCommand(ui, 10, i);
                break;
            }
        }
        if (fn_801953B8() != 0) {
            ui = &camp_work.pnl[4]->win->obj;
            UiObjMoveTo(ui, 6, 4, -8.0f, 317.0f);
            slot = fn_80195540(&req);
            switch (req.e[slot->cur[0].sel].x4) {
            case 2:
                break;
            case 1:
                if (ctrl->cur[0].sel == 4) {
                    UiObjSetCommand(ui, 10, 4);
                } else {
                    UiObjSetCommand(ui, 0xf, 5);
                }
                break;
            }
        }
        break;
    case 1:
        for (i = 0; i < camp_work.count; i++) {
            ui = &camp_work.pnl[i]->win->obj;
            UiObjMoveTo(ui, 6, 4, -8.0f, (f32)(61 + i * 64));
            slot = fn_80195540(&req);
            switch (req.e[slot->cur[0].sel].x4) {
            case 1:
                if (ctrl->cur[0].sel == i) {
                    UiObjSetCommand(ui, 10, i);
                } else {
                    UiObjSetCommand(ui, 0xf, i + 1);
                }
                break;
            case 2:
                UiObjSetCommand(ui, 10, i);
                break;
            }
        }
        break;
    case 2:
        if (fn_801953B8() != 0) {
            ui = &camp_work.pnl[4]->win->obj;
            UiObjMoveTo(ui, 6, 4, -8.0f, 317.0f);
            UiObjSetCommand(ui, 10, 4);
        }
        break;
    case 3:
        ui = &camp_work.pnl[149]->win->obj;
        UiObjMoveTo(ui, 6, 4, -8.0f, 61.0f);
        UiObjSetCommand(ui, 10, 0);
        ui = &camp_work.pnl[150]->win->obj;
        UiObjMoveTo(ui, 6, 4, 328.0f, 61.0f);
        UiObjSetCommand(ui, 10, 0);
        break;
    }
}

extern void fn_801854B8(void);
static inline UiObj* PnlObj(s32 i) { return &camp_work.pnl[i]->win->obj; }


void fn_80184A78(void) {
    UiObj* p;
    s32 i;
    s32 k;
    UiObj* o;
    f32 y;

    for (i = 0; i < camp_work.count; i++) {
        o = &camp_work.pnl[i]->win->obj;
        y = i * 64 + 61;
        UiObjSetLowered(o);
        fn_80199BB8(o, -348.0f, y);
        fn_80199BAC(o, -348.0f, y);
    }
    if (fn_801953B8() != 0) {
        p = &camp_work.pnl[4]->win->obj;
        UiObjSetLowered(p);
        fn_80199BB8(p, -348.0f, 317.0f);
        fn_80199BAC(p, -348.0f, 317.0f);
        p = &camp_work.pnl[0x6c]->win->obj;
        UiObjSetRaised(p);
        fn_80199BB8(p, 668.0f, 317.0f);
        fn_80199BAC(p, 668.0f, 317.0f);
        p = &camp_work.pnl[0x6d]->win->obj;
        UiObjSetRaised(p);
        fn_80199BB8(p, 668.0f, 317.0f);
        fn_80199BAC(p, 668.0f, 317.0f);
    }
    for (i = 0; i < camp_work.count; i++) {
        for (k = 0; k < 5; k++) {
            p = &camp_work.pnl[i * 5 + 6 + k]->win->obj;
            y = i * 64 + 61;
            UiObjSetRaised(p);
            fn_80199BB8(p, 668.0f, y);
            fn_80199BAC(p, 668.0f, y);
        }
    }
    if (fn_80194CB8() == 1) {
        o = &camp_work.pnl[5]->win->obj;
        fn_80199BB8(o, -348.0f, 381.0f);
        fn_80199BAC(o, -348.0f, 381.0f);
    }
}

s32 fn_801852F8(void) {
    CampCtrl* c;
    c = lbl_8034710C->holder->ctrl;
    fn_801854B8();
    if (lbl_803470C8 == 1) {
        if (CampMenuAnyPanelBusy() == 0) {
            lbl_803470C8 = 0;
        }
        goto end;
    }
    if (fn_801C09F8(lbl_80347154, 5) != 0) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = fn_8019A21C(c->cur[0].mask, 1, c->cur[0].sel, 0, 7);
    } else if (fn_801C09F8(lbl_80347154, 4) != 0) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = fn_8019A21C(c->cur[0].mask, -1, c->cur[0].sel, 0, 7);
    } else if (fn_801C09F8(lbl_80347154, 2) != 0) {
        fn_801929B8(2);
        return 1;
    } else if (fn_801C09F8(lbl_80347154, 1) != 0) {
        return -1;
    } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = 4;
        fn_801929B8(2);
        return 1;
    } else {
        goto end;
    }
    UiObjSetCommand(PnlObj(c->cur[0].sel + 0x1a), 0x15, 0);
    fn_801929B8(4);
    UiObjSetCommand(PnlObj(c->cur[0].x8 + 0x1a), 0x14, 0);
end:
    return 0;
}

void fn_80185864(void) {
    s32 i;
    UiObj* o;
    f32 y;
    CampCtrl* c;

    c = lbl_8034710C->holder->ctrl;
    for (i = 0; i < 4; i++) {
        if (lbl_802E97C0[i]()) {
            o = &camp_work.pnl[0x1a + i]->win->obj;
            y = i * 64 + 61;
            if (i == c->cur[0].sel) {
                UiObjMoveTo(o, 6, 4, -8.0f, 61.0f);
                UiObjSetCommand(o, 15, i);
            } else {
                UiObjMoveTo(o, 6, 5, -348.0f, y);
                UiObjSetCommand(o, 15, i + 1);
            }
        }
    }
    o = &camp_work.pnl[0x1e]->win->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 381.0f);
    if (c->cur[0].sel == 4) {
        UiObjSetCommand(o, 10, 5);
    } else {
        UiObjSetCommand(o, 15, 6);
    }
}
extern void fn_801D4C54(Sprite* s, f32 a, f32 b, f32 c, f32 d, s32 e, s32 f, s32 g);
extern void fn_801D5A50(Sprite* s, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, f32 f6, s32 a, s32 b, void* c);
extern void fn_801BCFAC(Sprite* s, s32 id);
extern void fn_801B71E8(s16 a, s32 b, s16 c);
extern void fn_801B7274(s16 a, s32 b, s16 c, s32 d, s16 e);
extern void fn_800DDE98(f32 f, f32 f2, s16 a, s32 b, s16 c, s32 d, void* e, s32 g);
void fn_801863E8(s16 dx, s32 b, s32 mode) {
    s32 arr[11] = {0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0};
    s32 idx[6] = {0, 2, 3, 8, 9, 10};
    Sprite* s;
    f32 y;
    f32 z;
    s32 i;
    s32 ix;
    y = -4090.0f;
    z = TextGetZ();
    TextPushColor();
    TextSetColor(0xff201008);
    for (i = 0; i < 6; i++) {
        s = fn_801D68C4(lbl_803470DC, idx[i]);
        ix = s->x;
        s->x = ix + dx;
        if (arr[idx[i]] == 0) {
            if (mode > 1 || (mode <= 1 && idx[i] != 9 && idx[i] != 10)) {
                fn_801D4C54(s, y, 0.0f, 1.0f, 1.0f, 0, 0, 1);
            }
        } else {
            fn_801BCFAC(s, 0x5d);
            fn_801D5A50(s, 1.0f, 1.0f, y, 0.0f, 1.0f, 1.0f, 0, 0, lbl_803470E4->x4->x20);
        }
        ix = s->x;
        s->x = ix - dx;
        y += 0.010000001f;
    }
    fn_801B71E8(dx + 0x134, 0xc1, b);
    fn_801B7274(dx + 0x14e, 0x8a, dx + 0x203, 0xa9, b);
    fn_800DDE98(1.0f, y, dx + 0x2a, 0xa1, dx + 0x12a, 0x1a1, lbl_803470D0->x4->x20, 0);
    TextSetZ(-27.5f);
    TextPopColor(1);
    TextSetZ(z);
}

void fn_80186E20(Rec_80186E20* r, s8 c, s8 b, s8 a, f32 v)
{
    r->a = a;
    r->b = b;
    r->c = c;
    r->f = v;
    r->entry = &lbl_803072E8[b];
}

s32 fn_80187F90(void)
{
    return (s8)fn_801F4CA0();
}

extern void fn_80188098(Inner_8016F138 *self);
void fn_80187FB4(Self_8016F138* self) {
    UiObj* obj = &self->inner->obj;

    if (lbl_803475D8 != 0) {
        self->state = 0xff;
    }
    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            CampPanelDrawFrame(self->inner);
            fn_80188098(self->inner);
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(self->inner);
        self->flags |= 0x40;
        break;
    }
}

void fn_80189DB0(s32* p, s8 v)
{
    *p = v;
}

extern s32 fn_801F4C24(s16 a);
extern void fn_801EE5A4(s32 c);
static inline void StatCmpSet(StatCmpEnt *s, s32 x) {
    if (x == s->cur) s->st = 1;
    else if (x < s->cur) s->st = 3;
    else s->st = 2;
    s->cur = x;
}
static inline void StatCmpAll(Sub_8018A16C *self, StatRec *r) {
    s32 v7, v6, v5, v4, v3, v2, v1;
    v1 = r->x52[0]; v2 = r->x52[1]; v3 = r->x48[1]; v4 = r->x52[2]; v5 = r->x52[3]; v6 = r->x52[4]; v7 = r->x48[4];
    StatCmpSet(&self->stat[0], v1);
    StatCmpSet(&self->stat[1], v2);
    StatCmpSet(&self->stat[2], v3);
    StatCmpSet(&self->stat[3], v4);
    StatCmpSet(&self->stat[4], v5);
    StatCmpSet(&self->stat[5], v6);
    StatCmpSet(&self->stat[6], v7);
}
extern void fn_801D52A8(Sprite *s, f32 f1, f32 f2, f32 f3, f32 f4, s32 a, s32 b);
extern s32 lbl_80347128;
extern void fn_8018DABC(Sub_8018A16C *d, s8 id, s8 b, s8 c, s8 kind);
extern void fn_8018D7F0(Sub_8018A16C *d);

#define SLOT(K, ID, SX, SY, TY, TX)     s = fn_801D68C4(lbl_803470F4, ID);     s->x = x + (SX);     s->y = y + (SY);     fn_801D52A8(s, 10.0f + self->pos.f0, self->pos.f4, 1.0f, 1.0f, self->pos.ic, self->pos.i8);     if (d->stat[K].st == 1) {         TextPrint(x + (TX), y + (TY), "-");     } else {         switch (d->stat[K].st) {         case 2:             col = 0xff2b5000;             break;         case 3:             col = 0xff800000;             break;         case 0:             col = 0xff201008;             break;         }         fn_8019A374(d->stat[K].cur, x + (TX), y + (TY), 10.0f + self->pos.f0, col, 0);     }

extern char* lbl_803467C0[2];
extern char lbl_802B45CC[];
extern char lbl_802EBB20[];
extern char lbl_8034B3D8[5];

#define NUM(V, DX, DY) fn_8019A374(V, x + (DX), y + (DY), 100.0f + self->pos.f0, 0xff201008, 0)

#define NAME(S, DY)                                 \
    if (S != NULL) {                                \
        TextPrint(x + 0x32, y + (DY), S);           \
    } else {                                        \
        TextPrint(x + 0x32, y + (DY), lbl_802EBB20); \
    }

#define BONUS(K)                                    \
    NUM(d->x80[K], 0x104, 0xa);                     \
    if (d->x98[K] > 0) {                            \
        NUM(d->x98[K], 0x104, 0x22);                \
    } else {                                        \
        TextPrint(x + 0xe0, y + 0x22, lbl_8034B3D8); \
    }

#define LEVEL()                                     \
    TextPrint(x + 0x1c, y + 6, lbl_803467C0[0]);    \
    TextPrint(x + 0x1c, y + 0x1e, lbl_803467C0[1]); \
    NUM(d->x58, 0x110, 0xa);                        \
    if (d->lv != 99) {                              \
        NUM(d->x5c, 0x110, 0x22);                   \
    } else {                                        \
        TextPrint(x + 0xbc, y + 0x22, lbl_802B45CC); \
    }

void fn_8018A2D8(Inner_8018A16C *self)
{
    s16 x;
    s16 y;
    Sub_8018A16C *d;
    f32 savez;

    d = self->sub;
    if (self->obj.rdy > 0.0f) {
        self->pos.f0 = 600.0f + (150.0f * d->b + -6940.0f);
    } else {
        self->pos.f0 = 150.0f * d->b + -6940.0f;
    }
    fn_8018DABC(d, d->ch, d->b, d->c, d->mode);
    x = self->obj.rect[0];
    y = self->obj.rect[1];
    savez = TextGetZ();
    TextPushColor();
    TextSetColor(0xff201008);
    TextSetZ(50.0f + (100.0f + self->pos.f0));
    switch (d->c) {
    case 0:
        switch (d->b) {
        case 0:
            NUM(d->x60[0], 0x8b, 0xa);
            NUM(d->x60[1], 0x10d, 0xa);
            NUM(d->x60[2], 0x8b, 0x22);
            NUM(d->x60[3], 0x10d, 0x22);
            break;
        case 1:
            NUM(d->x60[4], 0x8b, 0xa);
            NUM(d->x60[5], 0x10d, 0xa);
            NUM(d->stat[2].cur, 0x8b, 0x22);
            break;
        case 2:
            NUM(d->x60[6], 0x8b, 0xa);
            NUM(d->stat[6].cur, 0x8b, 0x22);
            break;
        case 3:
            LEVEL();
            break;
        }
        break;
    case 1:
        switch (d->b) {
        case 0:
            NAME(d->name[0], 6);
            NAME(d->name[1], 0x1e);
            break;
        case 1:
            NAME(d->name[2], 6);
            break;
        case 2:
            NUM(d->stat[0].cur, 0x8b, 0xa);
            NUM(d->stat[1].cur, 0x10d, 0xa);
            NUM(d->stat[2].cur, 0x8b, 0x22);
            NUM(d->stat[3].cur, 0x10d, 0x22);
            break;
        case 3:
            NUM(d->stat[4].cur, 0x8b, 0xa);
            NUM(d->stat[5].cur, 0x10d, 0xa);
            NUM(d->stat[6].cur, 0x8b, 0x22);
            break;
        case 4:
            LEVEL();
            break;
        }
        break;
    case 2:
        switch (d->b) {
        case 0:
            BONUS(0);
            break;
        case 1:
            BONUS(1);
            break;
        case 2:
            BONUS(2);
            break;
        case 3:
            BONUS(3);
            break;
        case 4:
            BONUS(4);
            break;
        case 5:
            BONUS(5);
            break;
        }
        break;
    }
    TextPopColor(1);
    TextSetZ(savez);
}

void fn_8018C8B4(Inner_8018A16C *self)
{
    Sprite *s;
    f32 savez;
    s16 x;
    s16 y;
    u32 col;
    Sub_8018A16C *d = self->sub;

    fn_8018DABC(d, d->ch, 0, 0, d->mode);
    switch (d->mode) {
    case 2:
        if (lbl_80347128 == 1) {
            fn_8018D7F0(d);
            if (d->stat[0].st == 1) {
                d->stat[0].st = 0;
            }
            if (d->stat[1].st == 1) {
                d->stat[1].st = 0;
            }
            if (d->stat[2].st == 1) {
                d->stat[2].st = 0;
            }
            if (d->stat[3].st == 1) {
                d->stat[3].st = 0;
            }
            if (d->stat[4].st == 1) {
                d->stat[4].st = 0;
            }
            if (d->stat[5].st == 1) {
                d->stat[5].st = 0;
            }
            if (d->stat[6].st == 1) {
                d->stat[6].st = 0;
            }
        }
        break;
    case 3:
        fn_8018D7F0(d);
        break;
    }
    x = self->obj.rect[0];
    y = self->obj.rect[1];
    savez = TextGetZ();
    TextSetZ(10.0f + self->pos.f0);
    TextPushColor();
    TextSetColor(0xff201008);
    col = 0xff201008;
    SLOT(0, 0x10, 0x10, 6, 0xa, 0x3f)
    SLOT(1, 0x11, 0x58, 6, 0xa, 0x87)
    SLOT(2, 0x12, 0xa0, 6, 0xa, 0xcf)
    SLOT(3, 0x13, 0xe8, 6, 0xa, 0x117)
    SLOT(4, 0x14, 0x10, 30, 0x22, 0x3f)
    SLOT(5, 0x15, 0x58, 30, 0x22, 0x87)
    SLOT(6, 0x16, 0xa0, 30, 0x22, 0xcf)
    TextPopColor(1);
    TextSetZ(savez);
}

#define NUM10(V, DX, DY) fn_8019A374(V, x + (DX), y + (DY), 10.0f + self->pos.f0, 0xff201008, 0)

void fn_8018D250(Inner_8018A16C *self)
{
    s16 x;
    s16 y;
    Sub_8018A16C *d;
    f32 savez;

    d = self->sub;
    fn_8018DABC(d, d->ch, d->b, d->c, d->mode);
    if (self->obj.rdy > 0.0f) {
        self->pos.f0 = 150.0f + (150.0f * d->b + -6940.0f);
    } else {
        self->pos.f0 = 150.0f * d->b + -6940.0f;
    }
    x = self->obj.rect[0];
    y = self->obj.rect[1];
    savez = TextGetZ();
    TextPushColor();
    TextSetColor(0xff201008);
    TextSetZ(100.0f + self->pos.f0);
    switch (d->c) {
    case 0:
        NUM10(d->stat[0].cur, 0x8b, 0xa);
        NUM10(d->stat[1].cur, 0x10d, 0xa);
        NUM10(d->stat[2].cur, 0x8b, 0x22);
        NUM10(d->stat[3].cur, 0x10d, 0x22);
        break;
    case 1:
        NUM10(d->stat[4].cur, 0x8b, 0xa);
        NUM10(d->stat[5].cur, 0x10d, 0xa);
        NUM10(d->stat[6].cur, 0x8b, 0x22);
        break;
    case 2:
        NAME(d->name[0], 6);
        NAME(d->name[1], 0x1e);
        break;
    case 3:
        NAME(d->name[2], 6);
        break;
    case 4:
        TextPrint(x + 0x1c, y + 6, lbl_803467C0[0]);
        TextPrint(x + 0x1c, y + 0x1e, lbl_803467C0[1]);
        NUM10(d->x58, 0x110, 0xa);
        if (d->lv != 99) {
            NUM10(d->x5c, 0x110, 0x22);
        } else {
            TextPrint(x + 0xbc, y + 0x22, lbl_802B45CC);
        }
        break;
    }
    TextPopColor(1);
    TextSetZ(savez);
}

void fn_8018D7F0(Sub_8018A16C* self) {
    s32 k;
    s32 old;
    SaveChar* c;
    s32 sel;
    StatRec* r;
    c = &lbl_8030B7F4.chr[self->ch];
    r = &lbl_8030B4D4.chr[self->ch];
    self->a40 = c->slot0;
    self->a44 = c->slot1;
    self->a48 = c->slot2;
    sel = lbl_803072E8[4].x4;
    k = fn_801F4C24(sel);
    switch (k) {
    case 0:
        old = c->slot0;
        c->slot0 = sel;
        break;
    case 1:
        old = c->slot1;
        if (sel == c->slot1) c->slot1 = -1; else c->slot1 = sel;
        break;
    case 2:
        old = c->slot2;
        if (sel == c->slot2) c->slot2 = -1; else c->slot2 = sel;
        break;
    }
    fn_801EE5A4(self->ch);
    StatCmpAll(self, r);
    switch (k) {
    case 0: c->slot0 = old; break;
    case 1: c->slot1 = old; break;
    case 2: c->slot2 = old; break;
    }
    fn_801EE5A4(self->ch);
}

void fn_8018DFAC(Trio* t, u32 v)
{
    t->f8 = v;
}

void fn_8018DFB4(Trio* t, u32 v)
{
    t->f0 = v;
}

void fn_8018DFBC(Trio* t, u32 v)
{
    t->f4 = v;
}

extern const char lbl_802B45D8[];
extern s32 fn_801943F4(void);
extern s32 fn_801946E8(s32 a, s32 b, s32 c);
extern s32 fn_801929FC(s32 v);

void fn_8018E3D0(s16 x, s16 y, f32 z) {
    s32 idx;
    s32 row;
    s32 col;
    s16 sx;
    s16 sy;
    f32 oldz;
    CampCtrl* c;
    s32 half;
    s16 ex;
    s16 ey;

    c = lbl_8034710C->holder->ctrl;
    half = c->cur[4].sel / 2;
    oldz = TextGetZ();
    TextSetZ(z);
    for (row = 0; row < fn_801943F4(); row++) {
        for (col = 0; col < 2; col++) {
            sx = x + 0x20 + col * 0xf8;
            idx = half * 2 + col;
            sy = y + 8 + row * 0x18;
            if (c->cur[4].sel == 10 && col == 1) {
                continue;
            }
            if (fn_801946E8(idx, row, fn_801943F4())) {
                TextPrintf(sx, sy, lbl_802ED258[fn_801929FC(row + idx * fn_801943F4())].name);
            } else {
                TextSetColor(0x40201008);
                TextPrintf(sx, sy, lbl_802B45D8);
                TextSetColor(0xff201008);
            }
        }
    }
    ex = x + 0x1dc;
    ey = y - 0x18;
    TextPrintf(ex, ey, "%d", half + 1);
    TextPrint(ex + 0xc, ey, "/");
    TextPrintf(ex + 0x18, ey, "6");
    TextPopColor(1);
    TextSetZ(oldz);
}

void fn_8018E588(s16 x, s16 y, f32 z)
{
    s32 n;
    s32 cx;
    s32 iy;
    s32 ix;
    s32 xs, ys;
    s32 i;
    s32 j;
    s16 py;
    s16 px;
    f32 oldz;
    s16 qx, qy;

    n = (2 <= lbl_8034710C->holder->ctrl->cur[4].sel) ? 2 : 0;
    oldz = TextGetZ();
    TextSetZ(z);
    ys = y;
    xs = x;
    iy = ys + 0x20;
    ix = xs + 0x20;
    for (i = 0; i < fn_801943F4(); i++) {
        cx = ix;
        py = iy;
        for (j = 0; j < 2; j++) {
            px = cx;
            if (fn_801946E8(j + n, i, fn_801943F4())) {
                TextPrintf(px, py, lbl_802EBA00[i + (j + n) * fn_801943F4()].label);
            } else {
                TextSetColor(0x40201008);
                TextPrintf(px, py, lbl_802B45D8);
                TextSetColor(0xff201008);
            }
            cx += 0xf8;
        }
        iy += 0x18;
    }
    qx = xs + 0x1dc;
    qy = ys - 0x18;
    TextPrintf(qx, qy, "%d", n / 2 + 1);
    TextPrint(qx + 0xc, qy, "/");
    TextPrintf(qx + 0x18, qy, "2");
    TextPopColor(1);
    TextSetZ(oldz);
}

void fn_8018E7F0(void* p)
{
    fn_8019A15C(p, 0, 0, 0);
}

void fn_8018E81C(Rec_8018E81C* r, s8 v, u8 b)
{
    r->v = v;
    r->b = b;
}



extern s32 lbl_803473EC;
extern s8 fn_8009763C(void);
extern s32 lbl_80347508;
extern s32 lbl_803473E8;
extern f32 fn_801CBBAC(f32);
extern void fn_801CBB9C(f32);
extern s32 lbl_80347130;
extern s32 lbl_8034712C;
extern s32 fn_800FF438(void);
extern s32 fn_801D6C3C(s32 h);
extern void fn_802171F0(s32 n);
extern u32 lbl_8034714C[2];
extern void fn_8022B9DC(void);
extern void fn_8022DBC8(void);
extern void fn_80192888(void);
extern void fn_8022697C(s32 n);
extern s32 lbl_803473E4;
extern s32 lbl_8034713C;
extern void fn_800C9070(void);
extern u8 lbl_802B45F0[];
extern void* fn_801E49B8(u8* p);
extern void fn_8022893C(void);
extern s32 fn_801E4998(void* p);
extern void fn_801926B8(void);
extern void fn_801D66D4(void);
extern void CampMenuTask(Task* t);
extern void fn_80194334(void);
extern s32 fog_enabled;
extern s32 lbl_803473E0;
extern void fn_8022B9A8(void);
extern void fn_80217134(void);
extern void fn_801D668C(void);
extern void fn_801925D8(void);
extern void fn_80192920(void);
extern void fn_80228930(void);
extern void fn_800C9060(void);
extern Task *lbl_803470FC;

/* Text at a float position. */
static inline void TextPrintF(f32 x, f32 y, const char *str)
{
    TextPrint(x, y, str);
}

#define SHOW(xo, av, col)                                                              \
    if (flag == 1) {                                                                   \
        if ((col) == 0xff201008) {                                                     \
            TextPrintF(x + (xo), y + 0x22, "-");                          \
        } else {                                                                       \
            fn_8019A374((av), x + (xo), y + 0x22, 10.0f + self->pos.f0, (col), 0); \
        }                                                                              \
    } else {                                                                           \
        fn_8019A374((av), x + (xo), y + 0x22, 10.0f + self->pos.f0, 0xff201008, 0); \
    }

void fn_801900F8(Inner_8018A16C *self, s32 id)
{
    s16 x;
    s16 y;
    s32 cur;
    s32 flag;
    f32 oz;
    s32 a, b;
    u32 col;
    CampP04 *lst;
    CampCtrl *ctl;

    lst = camp_work.p04;
    ctl = lbl_80307638;
    flag = 0;
    x = self->obj.rect[0];
    y = self->obj.rect[1];
    switch (self->type) {
    case 0x70:
        x += 12;
        break;
    case 0x71:
        flag = 1;
        x += 12;
        break;
    case 0x74:
        break;
    }
    cur = lst->a[ctl[11].cur[0].sel];
    oz = TextGetZ();
    TextSetZ(10.0f + self->pos.f0);
    TextPushColor();
    TextSetColor(0xff201008);

    a = id == -1 ? 0 : lbl_802D7E4C[id - 400].attack;
    b = lbl_802D7E4C[cur - 400].attack;
    if (a == b) {
        col = 0xff201008;
    } else if (a > b) {
        col = 0xff2b5000;
    } else {
        col = 0xff800000;
    }
    SHOW(0x33, a, col)

    a = id == -1 ? 0 : lbl_802D7E4C[id - 400].accuracy;
    b = lbl_802D7E4C[cur - 400].accuracy;
    if (a == b) {
        col = 0xff201008;
    } else if (a > b) {
        col = 0xff2b5000;
    } else {
        col = 0xff800000;
    }
    if (flag == 1) {
        if (col == 0xff201008) {
            TextPrintF(x + 0x7b, y + 0x22, "-");
        } else {
            fn_8019A374(a, (x + 0x7b), y + 0x22, 10.0f + self->pos.f0, col, 0);
        }
    } else {
        if (a == -1) a = 999;
        fn_8019A374(a, (x + 0x7b), y + 0x22, 10.0f + self->pos.f0, 0xff201008, 0);
    }

    a = id == -1 ? 0 : lbl_802D7E4C[id - 400].cost;
    b = lbl_802D7E4C[cur - 400].cost;
    if (a == b) {
        col = 0xff201008;
    } else if (a < b) {
        col = 0xff2b5000;
    } else {
        col = 0xff800000;
    }
    SHOW(0xc3, a, col)

    a = id == -1 ? 0 : lbl_802D7E4C[id - 400].limit;
    b = lbl_802D7E4C[cur - 400].limit;
    if (a == b) {
        col = 0xff201008;
    } else if (a > b) {
        col = 0xff2b5000;
    } else {
        col = 0xff800000;
    }
    SHOW(0x10b, a, col)

    TextPopColor(1);
    TextSetZ(oz);
}

void fn_801920AC(Task* t)
{
    int i;
    int h;
    DrawState ds;
    CampWork **cell;

    switch (t->state) {
    case 0:
    case 0xfe:
        lbl_803470FC = NULL;
        t->state = 1;
        lbl_80347154 = 0;
        break;
    case 1:
        if (lbl_803473EC == 1) break;
        if (lbl_80310B3C[0x21] & 0x80000000) break;
        if (fn_8009763C() == 12) break;
        if (lbl_80347508 == 1) break;
        if (lbl_803473E8 != 1) break;
        if (!(lbl_80311A60[lbl_80347154]->held & 0x400)) break;
        fn_801CBBAC(3.0f);
        lbl_80347130 = 0;
        lbl_8034712C = 0;
        h = fn_800FF438();
        if (h != -1) {
            s32 r;
            do {
                r = fn_801D6C3C(h);
            } while (r != 0 && r != -2);
        }
        fn_802171F0(-0x1f);
        for (i = 0; i < 27; i++) {
            lbl_80308088[i] = 0;
        }
        lbl_8034714C[0] = 0;
        lbl_8034714C[1] = 0;
        fn_8022B9DC();
        fn_8022DBC8();
        if (lbl_80310A1C.f6 == 12 || (lbl_80310A1C.f6 >= 0 && lbl_80310A1C.f6 <= 4)) {
            if (lbl_8030B7F4.party[0] == 0) {
                fn_80192888();
            }
        }
        fn_8022697C(t->x14);
        lbl_803473E4 = 1;
        lbl_8034713C = 0;
        fn_800C9070();
        lbl_80347100 = fn_801E49B8(lbl_802B45F0);
        fn_8022893C();
        if (fn_801953B8() != 0) {
            fn_80194F3C();
        }
        t->state = 3;
        break;
    case 3:
        if (lbl_80347508 != 1 && fn_801E4998(lbl_80347100) == 1) {
            fn_801CBB9C(3.0f);
            fn_801926B8();
            fn_801D66D4();
            lbl_803470FC = fn_802267AC(t, CampMenuTask);
            lbl_803470FC->work = fn_801E1C7C(4);
            cell = lbl_803470FC->work;
            *cell = &camp_work;
            memset(&camp_work, 0, 0x35c);
            camp_work.f34c = 1.0f;
            camp_work.f350 = 1.0f;
            camp_work.f354 = 1.0f;
            camp_work.f358 = 1.0f;
            lbl_80347128 = 0;
            fn_801D6C3C(0);
            fn_80194334();
            fn_801942A4();
            fog_enabled = 0;
            DrawStateDefault2D(&ds);
            DrawStatePush(&ds);
            t->state = 4;
        }
        fn_8022DBC8();
        break;
    case 4:
        if (lbl_80347508 != 1) {
            t->state = 5;
        }
        fn_8022DBC8();
        break;
    case 5:
        if (lbl_803473EC == 1 || (lbl_80311A60[lbl_80347154]->held & 0x400)) {
            if (lbl_803473E0 == 1) {
                fn_801CBBAC(3.0f);
                t->state = 6;
            }
        }
        fn_8022DBC8();
        break;
    case 6:
        if (lbl_80347508 != 1) {
            lbl_803470FC->state = 3;
            lbl_803470FC = NULL;
            fn_801CBB9C(3.0f);
            t->state = 7;
            fn_8022B9A8();
            fn_8022DBC8();
        } else {
            fn_8022DBC8();
        }
        break;
    case 7:
        fn_8022697C(0x7fffffff);
        for (i = 0; i < 27; i++) {
            if (lbl_80308088[i] != 0) {
                fn_80217830(lbl_80308088[i]);
                lbl_80308088[i] = 0;
            }
        }
        for (i = 0; i < 2; i++) {
            if (lbl_8034714C[i] != 0) {
                fn_80217830(lbl_8034714C[i]);
                lbl_8034714C[i] = 0;
            }
        }
        fn_80217134();
        lbl_803473EC = 0;
        lbl_803473E4 = 0;
        fn_801D668C();
        fn_801925D8();
        if (lbl_80310A1C.f6 == 12 || (lbl_80310A1C.f6 >= 0 && lbl_80310A1C.f6 <= 4)) {
            if (lbl_8030B7F4.party[0] == 0) {
                fn_80192920();
            }
        }
        fn_80228930();
        fn_801D6C3C(0);
        fn_80194268();
        DrawStatePop(0);
        DrawStateRestore();
        fn_800C9060();
        t->state = 1;
        break;
    case 0xff:
        if (lbl_803470FC != NULL) {
            TaskDelete(lbl_803470FC);
        }
        t->flags |= 0x40;
        break;
    }
}

void fn_80192800(void)
{
    TaskDelete(lbl_80347114);
    lbl_80347114 = 0;
}

void CampMenuCreate(void)
{
    lbl_80347114 = fn_802267AC(lbl_8034759C, fn_801920AC);
    lbl_80347114->work = fn_801E1C7C(4);
    lbl_803473E8 = 1;
    lbl_803473E0 = 1;
    lbl_803473E4 = 0;
    lbl_80347100 = lbl_80347104;
}

void fn_80192920(void)
{
    Save1568* p = &lbl_8030B7F4.x1568;
    s32 i;

    for (i = 0; i < 5; i++) {
        if (p->s1580[i] != -1) {
            fn_801C1148(p->s1580[i], 1);
        }
    }
    for (i = 0; i < 3; i++) {
        if (p->s158a[i] != -1) {
            fn_801C1148(p->s158a[i], 1);
        }
    }
}

s32 fn_801929B8(s32 idx) {
    lbl_80308088[idx] = MenuPlaySe((s16)idx);
    return lbl_80308088[idx];
}

s32 fn_801812C0(void)
{
    CampReq req;
    s32 off = lbl_80307638[1].cur[0].sel;
    s32 v = lbl_8030B7F4.party[off];
    s8 r;
    fn_80195EA4(&req, v, 0, 0, 2);
    r = req.x0b;
    return r;
}

void fn_80187F30(Holder_80187F30* h, CampCtrl* t)
{
    h->b4 = fn_801F4CA0();
    h->target = t;
    h->target->cur[1].mask = (s8)h->b4;
    h->target->cur[2].x0 = (s8)h->b4;
}

void fn_80189900(Dst_80189958* p, s8 a4, s8 a5, s32 a6, s8 a7)
{
    u8 local[0x80];
    p->id = a6;
    p->x2 = a4;
    p->x1 = a5;
    if (a5 == -1) {
        p->ok = 0;
    } else {
        fn_80189958(p, local, a4, a5, p->id, a7);
    }
}

void fn_8017439C(void) {
    u32 a;
    u32 b;
    CampCtrl* ms = lbl_8034710C->holder->ctrl;

    switch (fn_801944C4()) {
    case 0:
        a = 0x3f;
        b = 0xf;
        break;
    case 1:
        a = 0xff;
        b = 0x7ff;
        break;
    }
    ms->cur[0].mask = a;
    ms->cur[4].mask = b;
    fn_80195A68(ms, 1, 0, 0, 0, 1);
    ms->cur[6].mask = 6;
    ms->cur[0].sel = 0;
    ms->cur[4].sel = 0;
}

void fn_80174444(void) {
    void** arr;
    s32 i;
    s32 j;
    UiObj* obj;

    i = fn_80194490();
    arr = (void**)(CWB + 0x10);
    obj = (UiObj*)(*(u8**)(*(u8**)&arr[i] + 0x24) + 8);
    fn_80199BB8(obj, -8.0f, 61.0f);
    fn_80199BAC(obj, -8.0f, 61.0f);

    j = fn_8019445C();
    obj = (UiObj*)(*(u8**)(*(u8**)&arr[j] + 0x24) + 8);
    fn_80199BB8(obj, -648.0f, 123.0f);
    fn_80199BAC(obj, -648.0f, 123.0f);

    obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x1ac) + 0x24) + 8);
    fn_80199BB8(obj, 48.0f, 131.0f);
    fn_80199BAC(obj, 48.0f, 131.0f);
}

s32 fn_80174A18(void)
{
    CampCtrl* c;
    s32 id;
    s32 i;
    s32 v;
    SaveChar* r;
    UiObj* o;

    c = lbl_8034710C->holder->ctrl;
    id = lbl_8030B7F4.party[lbl_80307638[1].cur[0].sel];
    fn_801957D8(id);
    r = &lbl_8030B7F4.chr[id];
    switch (c->cur[0].sel) {
    case 0:
        v = r->slot0;
        break;
    case 1:
        v = r->slot1;
        break;
    case 2:
        v = r->slot2;
        break;
    }
    if (v != -1) {
        fn_801954D0(fn_801F48AC(v));
    } else {
        fn_801954D0(0);
    }
    switch (c->cur[6].mask) {
    case 6:
        fn_80174CB0();
        break;
    default:
        if (fn_801C09F8(lbl_80347154, 5)) {
            c->cur[0].x8 = c->cur[0].sel;
            c->cur[0].sel++;
            if (c->cur[0].sel >= 3) c->cur[0].sel = 0;
        } else if (fn_801C09F8(lbl_80347154, 4)) {
            c->cur[0].x8 = c->cur[0].sel;
            c->cur[0].sel--;
            if (c->cur[0].sel < 0) c->cur[0].sel = 2;
        } else if (fn_801C09F8(lbl_80347154, 2)) {
            fn_801929B8(2);
            return 1;
        } else if (fn_801C09F8(lbl_80347154, 1)) {
            fn_801929B8(5);
            return -1;
        } else if (fn_801C09F8(lbl_80347154, 0x11)) {
            c->cur[2].x8 = c->cur[2].sel;
            c->cur[2].sel = fn_8019A21C(c->cur[2].mask, -1, c->cur[2].sel, 0, 7);
            goto setmode;
        } else if (fn_801C09F8(lbl_80347154, 0x10)) {
            c->cur[2].x8 = c->cur[2].sel;
            c->cur[2].sel = fn_8019A21C(c->cur[2].mask, 1, c->cur[2].sel, 0, 7);
            goto setmode;
        } else {
            break;
        }
        i = c->cur[0].sel + 0x5a;
        o = &camp_work.pnl[i]->win->obj;
        UiObjSetCommand(o, 0x15, 0);
        fn_801929B8(4);
        i = c->cur[0].x8 + 0x5a;
        o = &camp_work.pnl[i]->win->obj;
        UiObjSetCommand(o, 0x14, 0);
        break;
    setmode:
        c->cur[6].mask = 6;
    }
    return 0;
}

void fn_801778AC(void) {
    CampCtrl* ms = lbl_8034710C->holder->ctrl;

    switch (ms->cur[1].sel) {
    case 0:
        fn_80193FF8(3);
        break;
    case 1:
        fn_80193FF8(0);
        break;
    case 2:
        fn_80193FF8(1);
        break;
    case 3:
        fn_80193FF8(2);
        break;
    case 4:
        fn_80193FBC(5, 1);
        fn_80193FBC(6, 0);
        fn_80193FBC(7, 0);
        break;
    case 5:
        fn_80193FF8(4);
        break;
    }
}

void fn_80177134(void) {
    Sprite* e;
    UiObj* o = &camp_work.pnl[51]->win->obj;
    f32 x;
    s32 who;
    CampWork* cw = &camp_work;
    CampCtrl* tb = lbl_80307638;
    CampCtrl* c = lbl_8034710C->holder->ctrl;
    switch (c->cur[6].mask) {
    case 0:
        if (fn_801952D0(c->cur[1].mask) > 1) {
            x = 5.0f + o->rect[0] + (f32)(c->cur[1].sel * 0x30);
            e = fn_801D68C4(lbl_803470F0, 0x44);
            e->x = x;
            e->y = 179.0f;
            fn_800FF348(e, 0, -3100.0f, 1.0f, cw->f354);
            x = 47.0f + o->rect[0] + (f32)(c->cur[1].sel * 0x30);
            e = fn_801D68C4(lbl_803470F0, 0x43);
            e->x = x;
            e->y = 179.0f;
            fn_800FF348(e, 0, -3100.0f, 1.0f, cw->f354);
        }
        break;
    case 1:
        who = lbl_8030B7F4.party[tb[1].cur[0].sel];
        if (fn_80195CD0(who, c->cur[1].sel, 0, c->cur[4].sel) > 1) {
            e = fn_801D68C4(lbl_803470F0, 0x62);
            e->x = 24.0f + o->rect[0];
            e->y = 156.0f + o->rect[1];
            fn_800FF348(e, 0, -3100.0f, 1.0f, cw->f358);
            e = fn_801D68C4(lbl_803470F0, 0x63);
            e->x = 272.0f + o->rect[0];
            e->y = 156.0f + o->rect[1];
            fn_800FF348(e, 0, -3100.0f, 1.0f, cw->f358);
        }
        break;
    }
}

void fn_80177C98(void) {
    s32 i;
    UiObj* obj;

    for (i = 0; i < 7; i++) {
        obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0xdc + i * 4) + 0x24) + 8);
        fn_80199BB8(obj, 668.0f, 204.0f);
        fn_80199BAC(obj, 668.0f, 204.0f);
    }
    obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x194) + 0x24) + 8);
    fn_80199BB8(obj, 328.0f, 204.0f);
    fn_80199BAC(obj, 328.0f, 204.0f);
    obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x190) + 0x24) + 8);
    fn_80199BB8(obj, 632.0f, 480.0f);
    fn_80199BAC(obj, 632.0f, 480.0f);
}

void fn_801792A4(void) {
    s32 i;
    UiObj* obj;

    for (i = 0; i < 7; i++) {
        obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0xf8 + i * 4) + 0x24) + 8);
        fn_80199BB8(obj, 668.0f, 204.0f);
        fn_80199BAC(obj, 668.0f, 204.0f);
    }
    obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x198) + 0x24) + 8);
    fn_80199BB8(obj, 328.0f, 204.0f);
    fn_80199BAC(obj, 328.0f, 204.0f);
    obj = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x190) + 0x24) + 8);
    fn_80199BB8(obj, 632.0f, 480.0f);
    fn_80199BAC(obj, 632.0f, 480.0f);
}

void fn_8017B0F8(void) {
    s32 (**fp)(void);
    s32 i;
    s32 first;
    u32 mask;
    CampCtrl* ms;

    mask = 0;
    first = -1;
    i = 0;
    fp = lbl_803467A8;
    ms = lbl_8034710C->holder->ctrl;
    for (; i < 2; i++) {
        if ((*fp)() != 0) {
            mask |= 1 << i;
            if (first != -1) {
                first = i;
            }
        }
        fp++;
    }
    ms->cur[0].mask = mask;
    ms->cur[4].mask = 0;
    fn_80195A68(ms, 1, 0, 0, 0, 1);
}

s32 fn_80183750(s8 a)
{
    if (a < 4) {
        SaveChar* r = &lbl_8030B7F4.chr[camp_work.ids[a]];
        return r->hpMax > r->hp;
    }
    if (fn_801953B8() == 0) {
        return 0;
    }
    {
        CampObj* o = (CampObj*)((CampWork_UNIT0000*)CWB)->p04;
        s32 v = fn_80194028();
        return o->x14 < v;
    }
}

s32 fn_80183800(s32 a, s32 b)
{
    s16 v = fn_801838C8(a, lbl_8030B7F4.party[b]);
    switch (a) {
    case 0x36: case 0x37: case 0x38: case 0x39: case 0x3a:
        return v < 0x3e7;
    case 0x3b:
        return v < 0x270f;
    case 0x3c:
        return v < 0x63;
    default:
        return 0;
    }
}

void fn_8018564C(void)
{
    s32 i;
    s32 first;
    u32 mask;
    CampCtrl* c;

    mask = 0;
    first = -1;
    c = lbl_8034710C->holder->ctrl;
    for (i = 0; i < 5; i++) {
        if (lbl_802E97C0[i]() != 0) {
            mask |= 1 << i;
            if (first == -1) {
                first = i;
            }
        }
    }
    c->cur[0].mask = mask;
    if (lbl_802E97C0[c->cur[0].sel]() == 0) {
        c->cur[0].sel = first;
    }
    c->cur[4].mask = 0;
    fn_80195A68(c, 1, 0, 0, 0, 1);
    lbl_803470C8 = 0;
}

void fn_80186348(void)
{
    if (lbl_803470DC != 0) {
        fn_801D6944(lbl_803470DC);
        fn_801E17E0(lbl_803470DC);
        lbl_803470DC = 0;
    }
    if (lbl_803470D8 != 0) {
        fn_801D6944(lbl_803470D8);
        fn_801E17E0(lbl_803470D8);
        lbl_803470D8 = 0;
    }
    if (lbl_803470E4 != 0) {
        fn_802275A4(lbl_803470E4->x4->x20, 0);
        fn_801E17E0(lbl_803470E4);
        lbl_803470E4 = 0;
    }
    if (lbl_803470E0 != 0) {
        fn_801E17E0(lbl_803470E0);
        lbl_803470E0 = 0;
    }
}

void fn_80186908(Obj48* o)
{
    void* r;

    o->f00 = -3940.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 1.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 1;
    o->i0c = 0;
    r = fn_801D68C4(lbl_803470F4, 0x4c);
    fn_8019A15C(o, 0, 1, 0);
    o->p38->p0 = r;
    o->p3c->f0 = 36.0f;
    o->p3c->f4 = 31.0f;
    o->p44 = 0;
}

void fn_801869B8(PairSet* o, Pair8* src)
{
    s32 i;

    o->mask0 = 0;
    o->mask1 = 0;
    for (i = 0; i < 11; i++) {
        u32 bit = 1 << i;

        o->pairs[i].a = src[i].a;
        if (src[i].a != -1) {
            o->mask0 |= bit;
            if (src[i].b != -1) {
                o->mask1 |= bit;
            }
        }
        o->pairs[i].b = src[i].b;
        if (src[i].a != -1) {
            o->mask0 |= bit;
            if (src[i].b != -1) {
                o->mask1 |= bit;
            }
        }
    }
}

void fn_80187E68(Obj48* o)
{
    o->f00 = -6190.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 0.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 1, 0, 1);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 10);
    o->p24->f0 = 0.0f;
    o->p24->f4 = 0.0f;
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 2);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = fn_801D68C4(lbl_803470F0, 4);
}

void fn_801884C4(Obj48* o)
{
    o->f00 = -6790.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 0.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 1, 0, 1);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 10);
    o->p24->f0 = 0.0f;
    o->p24->f4 = 0.0f;
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 2);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = fn_801D68C4(lbl_803470F0, 1);
}

void fn_8018873C(Obj48* o)
{
    void* r;

    o->f00 = -3700.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 1.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 1;
    o->i0c = 0;
    r = fn_801D68C4(lbl_803470F4, 0x4d);
    fn_8019A15C(o, 0, 1, 0);
    o->p38->p0 = r;
    o->p3c->f0 = 16.0f;
    o->p3c->f4 = 12.0f;
    o->p44 = 0;
}

void fn_801895C0(void* unused, Obj48* o, f32 f1)
{
    o->f00 = -4000.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = f1;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 2, 0, 0);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x22);
    o->p24->f0 = 0.0f;
    o->p24->f4 = -26.0f;
    o->p20->p4 = fn_801D68C4(lbl_803470F0, 0x3b);
    o->p24->f8 = 68.0f;
    o->p24->fc = -26.0f;
    o->p44 = 0;
}

void fn_80189788(void* unused, Obj48* o, f32 f1)
{
    void* r;

    o->f00 = -4000.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = f1;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    r = fn_801D68C4(lbl_803470F0, 0x20);
    fn_8019A15C(o, 1, 0, 0);
    o->p20->p0 = r;
    o->p24->f0 = 0.0f;
    o->p24->f4 = 2.0f;
    o->p44 = 0;
}

void fn_80189834(Obj48* o, f32 f1)
{
    o->f00 = -3850.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = f1;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 1, 0, 1);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x1f);
    o->p24->f0 = 0.0f;
    o->p24->f4 = 160.0f;
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 3);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = fn_801D68C4(lbl_803470F0, 5);
}

void fn_80189CF0(Obj48* o)
{
    o->f00 = -3990.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 0.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    fn_8019A15C(o, 1, 0, 1);
    o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x27);
    o->p24->f0 = 0.0f;
    o->p24->f4 = 0.0f;
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 4);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = 0;
}

void fn_8018DEFC(Obj48* o)
{
    void* r;

    o->f00 = -3940.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 1.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 1;
    o->i0c = 0;
    r = fn_801D68C4(lbl_803470F4, 0x4a);
    fn_8019A15C(o, 0, 1, 0);
    o->p38->p0 = r;
    o->p3c->f0 = -24.0f;
    o->p3c->f4 = 0.0f;
    o->p44 = 0;
}

void fn_8018DFC4(Obj_8018DFC4* o)
{
    Sub_8018DFC4* s = o->p24;
    void* r = s->rect8;

    if (lbl_803475D8 != 0) {
        o->state19 = 0xff;
    }
    switch (o->state19) {
    case 0:
    case 0xfe:
        o->state19 = 1;
        /* fall through */
    case 1:
        fn_80199F38(r);
        UiObjCalcRect(r);
        if (o->p24->kind == 1) {
            fn_8018E73C(o->p24);
            fn_8018E0A8(o->p24);
        }
        break;
    case 0x64:
        o->state19 = 0xff;
        break;
    case 0xff:
        fn_80199F58(o->p24);
        o->flags18 |= 0x40;
        break;
    }
}

void fn_801925D8(void)
{
    if (lbl_803470E8 != 0) {
        fn_801D6944(lbl_803470E8);
        fn_801E17E0(lbl_803470E8);
        lbl_803470E8 = 0;
    }
    if (lbl_803470EC != 0) {
        fn_801D6944(lbl_803470EC);
        fn_801E17E0(lbl_803470EC);
        lbl_803470EC = 0;
    }
    if (lbl_803470F0 != 0) {
        fn_801D6944(lbl_803470F0);
        fn_801E17E0(lbl_803470F0);
        lbl_803470F0 = 0;
    }
    if (lbl_803470F4 != 0) {
        fn_801D6944(lbl_803470F4);
        fn_801E17E0(lbl_803470F4);
        lbl_803470F4 = 0;
    }
    if (lbl_80347618 != 0) {
        fn_802275A4(((Obj4*)lbl_80347618)->x4->x20, 1);
        fn_801E17E0(lbl_80347618);
        lbl_80347618 = 0;
    }
    if (lbl_803470F8 != 0) {
        fn_801E17E0(lbl_803470F8);
        lbl_803470F8 = 0;
    }
}

void fn_80192888(void)
{
    Save1568* p = &lbl_8030B7F4.x1568;
    s32 i;

    for (i = 0; i < 5; i++) {
        if (p->s1580[i] != -1) {
            fn_801C0FE8(p->s1580[i], 1);
        }
    }
    for (i = 0; i < 3; i++) {
        if (p->s158a[i] != -1) {
            fn_801C0FE8(p->s158a[i], 1);
        }
    }
}

#define BSW(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | ((x) << 24))

void fn_80171B64(s8 idx) {
    void *spr;
    Hold_80171B64 *h = ((Camp_80171B64*)CWB)->hold;
    switch (idx) {
    case 0: spr = fn_801D68C4(lbl_803470F0, 0x2b); break;
    case 1: spr = fn_801D68C4(lbl_803470F0, 0x2c); break;
    case 2: spr = fn_801D68C4(lbl_803470F0, 0x2d); break;
    case 3: spr = fn_801D68C4(lbl_803470F0, 0x2e); break;
    case 4: spr = fn_801D68C4(lbl_803470F0, 0x2f); break;
    case 5: spr = fn_801D68C4(lbl_803470F0, 0x30); break;
    default: spr = fn_801D68C4(lbl_803470F0, 0x2b); break;
    }
    fn_8019520C(idx, spr);
    h->sub->dst->spr = spr;
}

void fn_80172B54(void) {
    u8 buf[0x60];
    s32 i, j;
    s32 k;
    void *w = ((Camp_80172B54*)CWB)->mid->hm->w;
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 2; j++) {
            fn_80194C68(buf, i, j, -1);
        }
    }
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 2; j++) {
            k = i * 2 + j;
            if (fn_801E4BF4(k) != 0) {
                if (fn_801E4BBC(k) != 0) {
                    fn_80194C68(buf, i, 0, k);
                } else {
                    fn_80194C68(buf, i, 1, k);
                }
            } else {
                fn_80194C68(buf, i, j, -1);
            }
        }
    }
    fn_801869B8(w, (void*)buf);
}

void fn_80176A44(void) {
    CampCtrl* c;
    Pnl** arr;
    s32 k;

    c = lbl_8034710C->holder->ctrl;
    CampMenuHideAllPanels();
    arr = (Pnl**)(CWB + 0x10);
    arr[lbl_80307638[1].cur[0].sel]->in->hide = 1;
    (*(Pnl**)(CWB + 0x8c + lbl_80307638[3].cur[0].sel * 4))->in->hide = 1;
    PNL(0x1b0)->in->hide = 1;
    PNL(0x1b4)->in->hide = 1;
    PNL(0x18c)->in->hide = 1;
    PNL(0x184)->in->hide = 1;
    PNL(0x188)->in->hide = 1;
    PNL(0x114)->in->hide = 1;
    k = lbl_80307638[8].cur[0].sel + 0x43;
    arr[k]->in->hide = 1;
    PNL(0x190)->in->hide = 1;
    PNL(0x19c)->in->hide = 0;
    c->cur[6].mask = 1;
}

static inline s32 BitTest(s32 m, s32 i) {
    return (m & (1 << i)) != 0;
}
void fn_80176B3C(void) {
    CampReq req;
    CampCtrl* c;
    s32 i;
    s32 k;
    CampPnl** arr;
    CampCtrl* cm;
    f32 a = -4000.0f;
    f32 b = 150.0f;
    s32 who;
    cm = lbl_80307638;
    c = lbl_8034710C->holder->ctrl;
    camp_work.pnl[0x42]->win->f74 = a;
    arr = camp_work.pnl;
    for (i = 0x43; i < 0x48; i++) {
        arr[i]->win->f74 = a;
    }
    c->cur[0].sel = 0;
    k = cm[8].cur[0].sel + 0x43;
    arr[k]->win->f74 += b;
    arr[k]->win->f74 += b;
    c->cur[1].mask = fn_80187F90();
    for (i = 0; i < 6; i++) {
        if (BitTest(c->cur[1].mask, i) == 1) break;
    }
    c->cur[1].sel = lbl_8030B7F4.chr[lbl_8030B7F4.party[cm[1].cur[0].sel]].xf;
    c->cur[4].sel = 0;
    who = lbl_8030B7F4.party[cm[1].cur[0].sel];
    fn_80195EA4(&req, who, cm[8].cur[0].sel + 1, c->cur[4].sel, 3);
    c->cur[4].mask = req.x0a;
    fn_80195A68(c, 1, 0, 0, 0, 1);
    lbl_80347128 = 0;
    fn_801954D0(0);
}

void fn_80177AC8(void) {
    UiObj* q;
    UiObj* p;
    s32 i;
    CampCtrl* c;
    UiObj* o;

    c = lbl_8034710C->holder->ctrl;
    o = &PNL(0xdc)->in->obj;
    UiObjMoveTo(o, 6, 4, 328.0f, 204.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 6; i++) {
        if (c->cur[1].mask & (1 << i)) {
            p = &(*(Pnl**)(CWB + 0xdc + 4 + i * 4))->in->obj;
            UiObjMoveTo(p, 6, -1, 328.0f, 204.0f);
            UiObjSetCommand(p, 15, 0);
        }
    }
    q = &PNL(0x190)->in->obj;
    UiObjMoveTo(q, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(q, 15, 0);
}

void fn_801790C8(void) {
    UiObj* q;
    UiObj* p;
    s32 i;
    CampCtrl* c;
    UiObj* o;

    c = lbl_8034710C->holder->ctrl;
    c->cur[0].sel = 0;
    c->cur[0].x8 = 0;
    o = &PNL(0xf8)->in->obj;
    UiObjMoveTo(o, 6, 4, 328.0f, 204.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 6; i++) {
        if (c->cur[1].mask & (1 << i)) {
            p = &(*(Pnl**)(CWB + 0xf8 + 4 + i * 4))->in->obj;
            UiObjMoveTo(p, 6, -1, 328.0f, 204.0f);
            UiObjSetCommand(p, 15, 0);
        }
    }
    q = &PNL(0x190)->in->obj;
    UiObjMoveTo(q, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(q, 15, 0);
}

void fn_8017A9FC(void) {
    UiObj* q;
    UiObj* o;
    UiObj* a;
    f32 y;
    s32 i;

    a = &PNL(0x84)->in->obj;
    fn_80199BB8(a, -8.0f, 61.0f);
    fn_80199BAC(a, -8.0f, 61.0f);
    for (i = 0; i < 3; i++) {
        o = &(*(Pnl**)(CWB + 0x254 + i * 4))->in->obj;
        y = (f32)((i + 1) * 64 + 61);
        UiObjSetLowered(o);
        fn_80199BB8(o, -398.0f, y);
        fn_80199BAC(o, -398.0f, y);
    }
    q = &PNL(0x190)->in->obj;
    fn_80199BB8(q, 632.0f, 480.0f);
    fn_80199BAC(q, 632.0f, 480.0f);
}

void fn_8017B19C(void) {
    UiObj* o;
    s32 i;
    CampCtrl* c;
    UiObj* q;

    c = lbl_8034710C->holder->ctrl;
    q = &PNL(0x78)->in->obj;
    UiObjMoveTo(q, 6, -1, -8.0f, 61.0f);
    UiObjSetCommand(q, 15, 0);
    for (i = 0; i < 2; i++) {
        o = &(*(Pnl**)(CWB + 0x22c + i * 4))->in->obj;
        UiObjMoveTo(o, 6, 4, -8.0f, (f32)((i + 1) * 64 + 61));
        if (c->cur[0].sel == i) {
            UiObjSetCommand(o, 10, i);
        } else {
            UiObjSetCommand(o, 15, i);
        }
    }
}

void fn_8017B2AC(void) {
    UiObj* o;
    s32 i;
    CampCtrl* c;
    UiObj* q;

    c = lbl_8034710C->holder->ctrl;
    q = &PNL(0x78)->in->obj;
    UiObjMoveTo(q, 6, -1, -348.0f, 61.0f);
    UiObjSetCommand(q, 15, 0);
    for (i = 0; i < 2; i++) {
        o = &(*(Pnl**)(CWB + 0x22c + i * 4))->in->obj;
        UiObjMoveTo(o, 6, 5, -348.0f, (f32)((i + 1) * 64 + 61));
        if (c->cur[0].sel == i) {
            UiObjSetCommand(o, 15, i);
        } else {
            UiObjSetCommand(o, 15, i);
        }
    }
}

void fn_8017B3BC(void) {
    UiObj* o;
    s32 i;
    CampCtrl* c;
    UiObj* q;
    f32 y;

    c = lbl_8034710C->holder->ctrl;
    q = &PNL(0x78)->in->obj;
    UiObjMoveTo(q, 6, -1, -348.0f, 61.0f);
    UiObjSetCommand(q, 15, 0);
    for (i = 0; i < 2; i++) {
        o = &(*(Pnl**)(CWB + 0x22c + i * 4))->in->obj;
        y = (f32)((i + 1) * 64 + 61);
        if (i == c->cur[0].sel) {
            UiObjMoveTo(o, 6, 4, -8.0f, 61.0f);
            UiObjSetCommand(o, 15, i);
        } else {
            UiObjMoveTo(o, 6, 5, -348.0f, y);
            UiObjSetCommand(o, 15, i);
        }
    }
}

void fn_8017B4E4(void) {
    UiObj* o;
    f32 y;
    s32 i;
    UiObj* a;

    a = &PNL(0x78)->in->obj;
    fn_80199BB8(a, -348.0f, 61.0f);
    fn_80199BAC(a, -348.0f, 61.0f);
    for (i = 0; i < 2; i++) {
        o = &(*(Pnl**)(CWB + 0x22c + i * 4))->in->obj;
        y = (f32)((i + 1) * 64 + 61);
        UiObjSetLowered(o);
        fn_80199BB8(o, -348.0f, y);
        fn_80199BAC(o, -348.0f, y);
    }
}

void fn_8017CC70(void) {
    UiObj* o;
    f32 off;
    Sprite* s;
    u8* cw = CWB;

    switch (lbl_8034710C->holder->ctrl->cur[2].sel) {
    case 0:
        o = &(*(Pnl**)(cw + 0x1f8))->in->obj;
        off = 0.0f;
        break;
    case 1:
        o = &(*(Pnl**)(cw + 0x20c))->in->obj;
        off = 0.0f;
        break;
    }
    s = fn_801D68C4(lbl_803470F0, 0x62);
    s->x = 24.0f + o->x;
    s->y = -16.0f + o->y + off;
    fn_800FF348(s, 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
    s = fn_801D68C4(lbl_803470F0, 0x63);
    s->x = 272.0f + o->x;
    s->y = -16.0f + o->y + off;
    fn_800FF348(s, 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
}

void fn_8017D250(void) {
    CampCtrl* c;
    f32 v;
    CampCtrl *b = lbl_80307638;

    c = lbl_8034710C->holder->ctrl;
    switch (b[4].cur[2].sel) {
    case 0:
        c->cur[0].mask = 0x1f;
        c->cur[0].sel = 0;
        break;
    case 1:
        c->cur[0].mask = 7;
        c->cur[0].sel = 0;
        break;
    }
    c->cur[2].mask = 3;
    c->cur[2].sel = b[4].cur[2].sel;
    fn_80195A68(c, 1, 0, 0, 0, 1);
    fn_801954D0(0);
    v = -6190.0f;
    ((Pnl74*)PNL(0x1f8))->in->f74 = v;
    ((Pnl74*)PNL(0x1fc))->in->f74 = v;
    ((Pnl74*)PNL(0x200))->in->f74 = v;
    ((Pnl74*)PNL(0x204))->in->f74 = v;
    ((Pnl74*)PNL(0x208))->in->f74 = v;
    ((Pnl74*)PNL(0x20c))->in->f74 = v;
    ((Pnl74*)PNL(0x210))->in->f74 = v;
    ((Pnl74*)PNL(0x214))->in->f74 = v;
}

void fn_8017E4E4(void) {
    UiObj* o;
    f32 off;
    Sprite* s;
    u8* cw = CWB;

    switch (lbl_8034710C->holder->ctrl->cur[2].sel) {
    case 0:
        o = &(*(Pnl**)(cw + 0x1f8))->in->obj;
        off = -64.0f;
        break;
    case 1:
        o = &(*(Pnl**)(cw + 0x20c))->in->obj;
        off = -64.0f;
        break;
    }
    s = fn_801D68C4(lbl_803470F0, 0x62);
    s->x = 24.0f + o->rect[0];
    s->y = -16.0f + o->rect[1] + off;
    fn_800FF348(s, 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
    s = fn_801D68C4(lbl_803470F0, 0x63);
    s->x = 272.0f + o->rect[0];
    s->y = -16.0f + o->rect[1] + off;
    fn_800FF348(s, 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
}

void fn_8018006C(s8 arg) {
    CampCtrl* c = lbl_8034710C->holder->ctrl;

    switch (c->state) {
    case 0:
        fn_80180174(c->cur[4].sel, arg);
        c->state++;
        break;
    case 1:
        if (CampMenuAnyPanelBusy() == 0) {
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            c->state++;
        }
        break;
    case 2:
        c->state = 0;
        switch (arg) {
        case 0:
            c->cur[6].mask = 5;
            break;
        case 1:
            c->cur[6].mask = 2;
            break;
        }
        break;
    }
}

void fn_80180174(s8 unused, s8 mode) {
    UiObj* p;
    f32 x, y;
    s16 se;
    UiObj* o;
    s32 cmd1, cmd2;

    switch (mode) {
    case 0:
        x = -8.0f;
        cmd1 = 10;
        y = 253.0f;
        cmd2 = 15;
        se = 4;
        break;
    case 1:
        x = -348.0f;
        cmd1 = 15;
        y = 253.0f;
        cmd2 = 15;
        se = 5;
        break;
    }
    o = &PNL(0x27c)->in->obj;
    UiObjFinish(o);
    UiObjMoveTo(o, 6, se, x - 60.0f, y);
    UiObjSetCommand(o, cmd1, 2);
    p = &PNL(0x280)->in->obj;
    UiObjFinish(p);
    UiObjMoveTo(p, 6, -1, x - 60.0f, 64.0f + y);
    UiObjSetCommand(p, cmd2, 2);
}

void fn_80180A84(void) {
    UiObj* q;
    UiObj* p;
    s32 i;
    UiObj* o;

    o = &PNL(0x1b8)->in->obj;
    UiObjMoveTo(o, 6, 4, -8.0f, 189.0f);
    UiObjSetCommand(o, 10, 0);
    for (i = 0; i < 7; i++) {
        p = &(*(Pnl**)(CWB + 0x130 + i * 4))->in->obj;
        UiObjMoveTo(p, 6, -1, 328.0f, 204.0f);
        UiObjSetCommand(p, 15, 0);
    }
    q = &PNL(0x190)->in->obj;
    UiObjMoveTo(q, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(q, 15, 0);
}

void fn_80183C54(void) {
    UiObj* o;
    Sprite* s;
    u8* cw = CWB;

    switch (lbl_8034710C->holder->ctrl->cur[4].sel) {
    case 0:
        o = &(*(Pnl**)(cw + 0x28))->in->obj;
        break;
    case 1:
        o = &(*(Pnl**)(cw + 0x2c))->in->obj;
        break;
    case 2:
        o = &(*(Pnl**)(cw + 0x30))->in->obj;
        break;
    case 3:
        o = &(*(Pnl**)(cw + 0x34))->in->obj;
        break;
    case 4:
        o = &(*(Pnl**)(cw + 0x38))->in->obj;
        break;
    }
    s = fn_801D68C4(lbl_803470F0, 0x62);
    s->x = 24.0f + o->rect[0];
    s->y = -16.0f + o->rect[1];
    fn_800FF348(s, 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
    s = fn_801D68C4(lbl_803470F0, 0x63);
    s->x = 272.0f + o->rect[0];
    s->y = -16.0f + o->rect[1];
    fn_800FF348(s, 0, -5850.0f, 1.0f, *(f32*)(cw + 0x350));
}

void fn_80184CE8(void) {
    s32 i;
    s32 k;
    CampWork* a;

    CampMenuHideAllPanels();
    a = &camp_work;
    for (i = 0; i < a->count; i++) {
        (*(Pnl**)(CWB + i * 4 + 0x10))->in->hide = 1;
        for (k = 0; k < 5; k++) {
            (*(Pnl**)(CWB + (i * 5 + 6 + k) * 4 + 0x10))->in->hide = 1;
        }
    }
    if (fn_801953B8() != 0) {
        PNL(0x20)->in->hide = 1;
        PNL(0x1c0)->in->hide = 1;
        PNL(0x1c4)->in->hide = 1;
    }
    if (fn_80194CB8() == 1) {
        PNL(0x24)->in->hide = 1;
    }
}

void fn_80185AFC(void) {
    s32 i;
    f32 y;
    UiObj* o;
    for (i = 0; i < 4; i++) {
        if (lbl_802E97C0[i]() != 0) {
            o = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x78 + i * 4) + 0x24) + 8);
            y = 61 + i * 64;
            UiObjSetLowered(o);
            fn_80199BB8(o, -348.0f, y);
            fn_80199BAC(o, -348.0f, y);
        }
    }
    o = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x88) + 0x24) + 8);
    UiObjSetLowered(o);
    fn_80199BB8(o, -348.0f, 381.0f);
    fn_80199BAC(o, -348.0f, 381.0f);
}

void fn_801851C8(void) {
    s32 sel = lbl_8034710C->holder->ctrl->cur[0].sel;
    switch (sel) {
    case 4:
    case 5:
        *(s32*)(CWB + 0x2f8) = 0;
        camp_screen = 1;
        fn_801959D4(1);
        break;
    case 0:
        *(s32*)(CWB + 0x330) = 0;
        camp_screen = 0xf;
        fn_801959D4(0xf);
        break;
    case 1:
        *(s32*)(CWB + 0x328) = 0;
        camp_screen = 0xd;
        fn_801959D4(0xd);
        break;
    case 2:
        *(s32*)(CWB + 0x340) = 0;
        camp_screen = 0x13;
        fn_801959D4(0x13);
        break;
    case 3:
        *(s32*)(CWB + 0x33c) = 0;
        camp_screen = 0x12;
        fn_801959D4(0x12);
        break;
    default:
        *(s32*)(CWB + 0x300) = 0;
        camp_screen = 3;
        fn_801959D4(3);
        break;
    }
}

void fn_80185724(void) {
    s32 i;
    CampCtrl* st = lbl_8034710C->holder->ctrl;
    UiObj* o;
    for (i = 0; i < 4; i++) {
        if (lbl_802E97C0[i]() != 0) {
            o = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x78 + i * 4) + 0x24) + 8);
            UiObjMoveTo(o, 6, 5, -348.0f, 61 + i * 64);
            if (st->cur[0].sel == i) {
                UiObjSetCommand(o, 10, i);
            } else {
                UiObjSetCommand(o, 15, i + 1);
            }
        }
    }
    o = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x88) + 0x24) + 8);
    UiObjMoveTo(o, 6, 5, -348.0f, 381.0f);
    if (st->cur[0].sel == 4) {
        UiObjSetCommand(o, 10, 5);
    } else {
        UiObjSetCommand(o, 15, 6);
    }
}

void fn_801859BC(void) {
    s32 i;
    CampCtrl* st = lbl_8034710C->holder->ctrl;
    UiObj* o;
    for (i = 0; i < 4; i++) {
        if (lbl_802E97C0[i]() != 0) {
            o = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x78 + i * 4) + 0x24) + 8);
            UiObjMoveTo(o, 6, 4, -8.0f, 61 + i * 64);
            if (st->cur[0].sel == i) {
                UiObjSetCommand(o, 10, i);
            } else {
                UiObjSetCommand(o, 15, i + 1);
            }
        }
    }
    o = (UiObj*)(*(u8**)(*(u8**)(CWB + 0x88) + 0x24) + 8);
    UiObjMoveTo(o, 6, 4, -8.0f, 381.0f);
    if (st->cur[0].sel == 4) {
        UiObjSetCommand(o, 10, 5);
    } else {
        UiObjSetCommand(o, 15, 6);
    }
}

void fn_801866B4(void) {
    s32 b;
    void* buf;
    s32 a;
    void* src;
    void* s0;
    lbl_803470E0 = fn_801E49D8(lbl_802B44A8);
    a = fn_801E4974(lbl_803470E0, 2);
    b = fn_801E48A8(lbl_803470E0);
    buf = fn_801E1C7C(a);
    src = fn_801E4984(lbl_803470E0, 2);
    MemCopy(buf, src, a);
    lbl_803470E0 = fn_801E1584(lbl_803470E0, b - a);
    lbl_803470E4 = fn_801DB124(buf);
    fn_80227810(lbl_803470E4->x4->x20);
    lbl_803470DC = fn_801E1C7C(0x14);
    s0 = fn_801E4984(lbl_803470E0, 0);
    fn_801D6998(lbl_803470DC, s0);
    lbl_803470D8 = fn_801E1C7C(0x14);
    fn_801D6998(lbl_803470D8, fn_801E4984(lbl_803470E0, 1));
}

void fn_80186D2C(Obj_80186D2C* o) {
    o->x0 = -4090.0f;
    o->x4 = 0.0f;
    o->x10 = 1.0f;
    o->x14 = 0.0f;
    o->x18 = 1.0f;
    o->x1C = 0.0f;
    o->x8 = 0;
    o->xC = 0;
    fn_8019A15C(o, 1, 1, 1);
    *o->c_ptr = fn_801D68C4(lbl_803470F4, 0x3f);
    o->c_pos[0] = 36.0f;
    o->c_pos[1] = 28.0f;
    *o->a_ptr = fn_801D68C4(lbl_803470F0, 0x55);
    o->a_pos[0] = 0.0f;
    o->a_pos[1] = 0.0f;
    *o->b_ptr = fn_801D68C4(lbl_803470E8, 8);
    o->b_pos[0] = 0.0f;
    o->b_pos[1] = 0.0f;
    o->x44 = fn_801D68C4(lbl_803470F0, 0x52);
}

void fn_80186E4C(Self_80186E4C* self) {
    UiObj* obj = &self->inner->obj;
    Cfg* cfg = self->inner->cfg;

    if (lbl_803475D8 != 0) {
        self->state = 0xff;
    }
    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            CampPanelDrawFrame(self->inner);
            switch (cfg->kind) {
            case 4:
                fn_8018796C(self->inner);
                break;
            default:
                fn_80186F58(self->inner);
                break;
            }
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(self->inner);
        self->flags |= 0x40;
        break;
    }
}

void fn_80187D78(Obj_80186D2C* o, f32 sx) {
    o->x0 = -6190.0f;
    o->x4 = 0.0f;
    o->x10 = sx;
    o->x14 = 0.0f;
    o->x18 = 1.0f;
    o->x1C = 0.0f;
    o->x8 = 0;
    o->xC = 0;
    fn_8019A15C(o, 1, 1, 1);
    *o->a_ptr = fn_801D68C4(lbl_803470F0, 0x2a);
    o->a_pos[0] = 0.0f;
    o->a_pos[1] = 0.0f;
    *o->b_ptr = fn_801D68C4(lbl_803470E8, 5);
    o->b_pos[0] = 0.0f;
    o->b_pos[1] = 0.0f;
    *o->c_ptr = fn_801D68C4(lbl_803470F4, 0x37);
    o->c_pos[0] = 6.0f;
    o->c_pos[1] = 6.0f;
    o->x44 = fn_801D68C4(lbl_803470F0, 0x28);
}

void fn_8018968C(s32 a, Obj_80186D2C* o, s32 b, s8 idx, f32 sy) {
    o->x0 = -4000.0f;
    o->x4 = 0.0f;
    o->x10 = 1.0f;
    o->x14 = sy;
    o->x18 = 1.0f;
    o->x1C = 0.0f;
    o->x8 = 0;
    o->xC = 0;
    fn_8019A15C(o, 2, 0, 0);
    o->a_ptr[0] = fn_801D68C4(lbl_803470F0, 0x21);
    o->a_pos[0] = 0.0f;
    o->a_pos[1] = -26.0f;
    o->a_ptr[1] = fn_801D68C4(lbl_803470F0, 0x3a);
    o->a_pos[2] = idx * 0x30 + 0x14;
    o->a_pos[3] = -26.0f;
    o->x44 = 0;
}

void fn_80189958(Dst_80189958* dst, void* unused, s8 a, s32 b, s8 unused2, s32 c) {
    CampReq tmp;
    s32 i;
    fn_80195EA4(&tmp, a, b, c, dst->id);
    if (b != tmp.b) {
        dst->ok = 0;
    } else {
        dst->ok = 1;
        for (i = 0; i < 6; i++) {
            dst->rec[i].a = tmp.e[i].x1;
            dst->rec[i].e = tmp.e[i].xc;
            dst->rec[i].f = tmp.e[i].x10;
            dst->rec[i].b = tmp.e[i].x0;
            dst->rec[i].c = tmp.e[i].x2;
            dst->rec[i].d = tmp.e[i].x6;
        }
    }
}

s32 fn_80189A70(s32 id, u32* out) {
    s32 i;
    *out = 0;
    for (i = 0; i < (s8)CWB[0xc]; i++) {
        SaveChar* r = &lbl_8030B7F4.chr[lbl_8030B7F4.party[i]];
        if (id == r->slot0) {
            switch (r->xf) {
            case 0: *out = 0xff20ff0a; break;
            case 1: *out = 0xffff4020; break;
            case 2: *out = 0xffc800ff; break;
            case 3: *out = 0xff0096ff; break;
            case 4: *out = 0xffffc800; break;
            case 5: *out = 0xffdcdcdc; break;
            default: *out = 0xffffffff; break;
            }
            return 1;
        }
    }
    return 0;
}

void fn_8018A07C(Obj_80186D2C* o, s8 idx) {
    o->x0 = -5590.0f + 150.0f * idx;
    o->x4 = 0.0f;
    o->x10 = 1.0f;
    o->x14 = 0.0f;
    o->x18 = 1.0f;
    o->x1C = 0.0f;
    o->x8 = 0;
    o->xC = 0;
    fn_8019A15C(o, 1, 0, 1);
    *o->a_ptr = fn_801D68C4(lbl_803470F0, 0x5c);
    o->a_pos[0] = 0.0f;
    o->a_pos[1] = 0.0f;
    *o->b_ptr = fn_801D68C4(lbl_803470E8, 10);
    o->b_pos[0] = 0.0f;
    o->b_pos[1] = 0.0f;
    o->x44 = fn_801D68C4(lbl_803470F0, 0x5b);
}

void fn_80191D78(Obj_80186D2C* o) {
    o->x0 = -7390.0f;
    o->x4 = 0.0f;
    o->x10 = 1.0f;
    o->x14 = 0.0f;
    o->x18 = 1.0f;
    o->x1C = 0.0f;
    o->x8 = 0;
    o->xC = 0;
    fn_8019A15C(o, 2, 1, 1);
    fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 2), 0x55, 0x1e, 2);
    *o->b_ptr = fn_801D68C4(lbl_803470E8, 1);
    o->b_pos[0] = 0.0f;
    o->b_pos[1] = 0.0f;
    o->a_ptr[0] = fn_801D68C4(lbl_803470F0, 8);
    o->a_pos[0] = 0.0f;
    o->a_pos[1] = 0.0f;
    o->a_ptr[1] = fn_801D68C4(lbl_803470F0, 0x1e);
    o->a_pos[2] = 24.0f;
    o->a_pos[3] = -2.0f;
    o->x44 = fn_801D68C4(lbl_803470F0, 1);
}

void fn_801926B8(void) {
    s32 b;
    void* buf;
    s32 a;
    void* src;
    void* s0;
    lbl_803470F8 = fn_801CC0A0(lbl_80347100);
    a = fn_801E4974(lbl_803470F8, 4);
    b = fn_801E48A8(lbl_803470F8);
    buf = fn_801E1C7C(a);
    src = fn_801E4984(lbl_803470F8, 4);
    MemCopy(buf, src, a);
    lbl_803470F8 = fn_801E1584(lbl_803470F8, b - a);
    lbl_80347618 = fn_801DB124(buf);
    fn_80227810(*(void**)((u8*)((void**)lbl_80347618)[1] + 0x20));
    lbl_803470E8 = fn_801E1C7C(0x14);
    s0 = fn_801E4984(lbl_803470F8, 0);
    fn_801D6998(lbl_803470E8, s0);
    lbl_803470EC = fn_801E1C7C(0x14);
    fn_801D6998(lbl_803470EC, fn_801E4984(lbl_803470F8, 1));
    lbl_803470F0 = fn_801E1C7C(0x14);
    fn_801D6998(lbl_803470F0, fn_801E4984(lbl_803470F8, 2));
    lbl_803470F4 = fn_801E1C7C(0x14);
    fn_801D6998(lbl_803470F4, fn_801E4984(lbl_803470F8, 3));
}

s32 fn_801929FC(s32 v) {
    s32 i;
    for (i = 0; i < 0x58; i++) {
        if (v == lbl_802ED258[i].id) {
            return i;
        }
    }
    if (i == 0x58) {
        v = 0;
    }
    return v;
}

void fn_8017519C(void) {
    s32 i;
    UiObj* o;

    o = &PNL(0x98)->in->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 125.0f);
    UiObjSetCommand(o, 15, 0);
    o = &PNL(0x1b0)->in->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 194.0f);
    UiObjSetCommand(o, 15, 1);
    for (i = 0; i < 3; i++) {
        o = &(*(Pnl**)(CWB + 0x178 + i * 4))->in->obj;
        UiObjMoveTo(o, 6, 5, 668.0f, 61 + i * 88);
        UiObjSetCommand(o, 15, i);
    }
    o = &PNL(0x190)->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_801753D4(void) {
    s32 i;
    CampCtrl* c;
    UiObj* o;

    c = lbl_8034710C->holder->ctrl;
    o = &PNL(0x1b0)->in->obj;
    UiObjMoveTo(o, 6, -1, -8.0f, 194.0f);
    UiObjSetCommand(o, 10, 0);
    for (i = 0; i < 3; i++) {
        o = &(*(Pnl**)(CWB + 0x178 + i * 4))->in->obj;
        UiObjMoveTo(o, 6, 4, 328.0f, 61 + i * 88);
        if (i == c->cur[0].sel) {
            UiObjSetCommand(o, 10, i);
        } else {
            UiObjSetCommand(o, 15, i + 1);
        }
    }
    o = &PNL(0x190)->in->obj;
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 0);
}

extern void fn_80195410(void);
extern void fn_80175774(void);
extern s32 lbl_80347128;
extern s32 fn_801929B8(s32 idx);
extern s32 fn_8019A21C(u32 mask, s32 d, s32 n, s32 unused, s32 max);
extern s32 fn_80195CD0(s8 a, s8 b, s32 c, s8 d);
extern void fn_801954D0(const char* help);

s32 fn_80175EE8(void)
{
    CampReq req;
    CampCtrl* g = lbl_80307638;
    CampCtrl* c;
    s32 id;
    s32 n;
    s32 m;

    c = lbl_8034710C->holder->ctrl;
    id = lbl_8030B7F4.party[g[1].cur[0].sel];
    n = fn_80195D8C(id, g[8].cur[0].sel + 1, 3, c->cur[4].sel);
    m = fn_80195CD0(id, g[8].cur[0].sel + 1, 3, c->cur[4].sel);
    if (n <= 0) {
        camp_work.pnl[0x63]->win->x0 = 0;
        c->cur[0].sel = 0;
    } else {
        camp_work.pnl[0x63]->win->x0 = 1;
    }
    id = lbl_8030B7F4.party[g[1].cur[0].sel];
    fn_80195EA4(&req, id, g[8].cur[0].sel + 1, c->cur[4].sel, 3);
    fn_801954D0(req.e[c->cur[0].sel].x10);
    if (n <= 0) {
        if (fn_801C09F8(lbl_80347154, 1) != 0) {
            fn_801929B8(5);
            return -1;
        }
        goto end;
    }
    switch (c->cur[6].mask) {
    case 1:
        c->cur[6].mask = 1;
        fn_80195A68(c, 1, 0, 0, 0, 1);
        if (fn_801C09F8(lbl_80347154, 5) != 0) {
            c->cur[0].x8 = c->cur[0].sel;
            c->cur[0].sel++;
            if (c->cur[0].sel >= n) {
                c->cur[0].sel = 0;
            }
            if (c->cur[0].x8 != c->cur[0].sel) goto moved;
        } else if (fn_801C09F8(lbl_80347154, 4) != 0) {
            c->cur[0].x8 = c->cur[0].sel;
            c->cur[0].sel--;
            if (c->cur[0].sel < 0) {
                c->cur[0].sel = n - 1;
            }
            if (c->cur[0].x8 != c->cur[0].sel) goto moved;
        } else if (fn_801C09F8(lbl_80347154, 7) != 0) {
            c->cur[4].x8 = c->cur[4].sel;
            c->cur[4].sel++;
            if (c->cur[4].sel >= m) {
                c->cur[4].sel = 0;
            }
            if (c->cur[4].x8 != c->cur[4].sel) goto moved2;
        } else if (fn_801C09F8(lbl_80347154, 6) != 0) {
            c->cur[4].x8 = c->cur[4].sel;
            c->cur[4].sel--;
            if (c->cur[4].sel < 0) {
                c->cur[4].sel = m - 1;
            }
            if (c->cur[4].x8 != c->cur[4].sel) goto moved2;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0) {
            if (g[8].cur[0].sel == 0) {
                lbl_80347128 = 1;
            } else {
                lbl_80347128 = 0;
            }
            goto help;
        } else if (fn_801C09F8(lbl_80347154, 1) != 0) {
            fn_801929B8(5);
            return -1;
        }
        break;
    case 0:
        c->cur[6].mask = 0;
        fn_80195A68(c, 0, 1, 0, 0, 0);
        if (fn_801C09F8(lbl_80347154, 7) != 0) {
            c->cur[1].x8 = c->cur[1].sel;
            c->cur[1].sel = fn_8019A21C(c->cur[1].mask, 1, c->cur[1].sel, 0, 7);
            if (c->cur[1].x8 != c->cur[1].sel) goto moved;
        } else if (fn_801C09F8(lbl_80347154, 6) != 0) {
            c->cur[1].x8 = c->cur[1].sel;
            c->cur[1].sel = fn_8019A21C(c->cur[1].mask, -1, c->cur[1].sel, 0, 7);
            if (c->cur[1].x8 != c->cur[1].sel) goto moved;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0) {
            lbl_80347128 = 1;
            goto help;
        } else if (fn_801C09F8(lbl_80347154, 1) != 0) {
            lbl_80347128 = 0;
            goto help;
        }
        break;
    case 6:
        if (CampMenuAnyPanelBusy() == 0) {
            if (lbl_80347128 == 1) {
                c->cur[6].mask = 0;
            } else {
                c->cur[6].mask = 1;
            }
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            if (lbl_80347128 == 1) {
                c->cur[6].mask = 0;
            } else {
                c->cur[6].mask = 1;
            }
        }
        break;
    }
    goto end;
moved:
    fn_80195410();
    fn_801929B8(0);
    goto end;
moved2:
    c->cur[0].sel = 0;
    fn_80195410();
    fn_801929B8(0);
    goto end;
help:
    fn_80175774();
end:
    return 0;
}

void fn_80175520(void) {
    f32 y;
    s32 i;
    UiObj* p;
    s32 j;
    UiObj* o;

    for (i = 0; i < 3; i++) {
        o = &(*(Pnl**)(CWB + 0x178 + i * 4))->in->obj;
        y = 61 + i * 88;
        UiObjSetLowered(o);
        fn_80199BB8(o, 668.0f, y);
        fn_80199BAC(o, 668.0f, y);
    }
    for (j = 0; j < 2; j++) {
        p = &(*(Pnl**)(CWB + 0x1b0 + j * 4))->in->obj;
        y = 194 + j * 64;
        UiObjSetLowered(p);
        fn_80199BB8(p, -348.0f, y);
        fn_80199BAC(p, -348.0f, y);
    }
    o = &PNL(0x190)->in->obj;
    fn_80199BB8(o, 632.0f, 480.0f);
    fn_80199BAC(o, 632.0f, 480.0f);
}

void fn_801766C4(void) {
    Pnl** arr;
    s32 k;
    UiObj* o;

    o = &PNL(0x184)->in->obj;
    UiObjMoveTo(o, 6, 4, 328.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    o = &PNL(0x188)->in->obj;
    UiObjMoveTo(o, 6, -1, 328.0f, 143.0f);
    UiObjSetCommand(o, 15, 0);
    o = &PNL(0x114)->in->obj;
    UiObjMoveTo(o, 6, 4, 328.0f, 204.0f);
    UiObjSetCommand(o, 15, 1);
    arr = (Pnl**)(CWB + 0x10);
    k = lbl_80307638[8].cur[0].sel + 0x43;
    o = &arr[k]->in->obj;
    UiObjMoveTo(o, 6, -1, 328.0f, 204.0f);
    UiObjSetCommand(o, 15, 1);
    o = &PNL(0x190)->in->obj;
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 0);
    o = &PNL(0x1b4)->in->obj;
    UiObjMoveTo(o, 6, -1, -8.0f, 258.0f);
    UiObjSetCommand(o, 10, 1);
}

void fn_8017796C(void) {
    UiObj* q;
    UiObj* r;
    UiObj* p;
    CampCtrl* c;
    s32 i;
    UiObj* o;

    c = lbl_8034710C->holder->ctrl;
    o = &((Pnl**)(CWB + 0x8c))[lbl_80307638[3].cur[0].sel]->in->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 125.0f);
    UiObjSetCommand(o, 15, 0);
    p = &PNL(0xdc)->in->obj;
    UiObjMoveTo(p, 6, -1, 668.0f, 204.0f);
    UiObjSetCommand(p, 15, 0);
    for (i = 0; i < 6; i++) {
        if (c->cur[1].mask & (1 << i)) {
            r = &(*(Pnl**)(CWB + 0xdc + 4 + i * 4))->in->obj;
            UiObjMoveTo(r, 6, -1, 668.0f, 204.0f);
            UiObjSetCommand(r, 15, 0);
        }
    }
    q = &PNL(0x190)->in->obj;
    UiObjMoveTo(q, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(q, 15, 0);
}

void fn_80178F6C(void) {
    s32 j;
    CampCtrl* c;
    UiObj* o;
    s32 idx = lbl_80307638[3].cur[0].sel;
    c = lbl_8034710C->holder->ctrl;
    o = &(((Pnl_80178F6C**)&(*(CampW_80178F6C*)CWB).pnl[0x1f])[idx])->in->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 125.0f);
    UiObjSetCommand(o, 0xf, 0);
    o = &(*(CampW_80178F6C*)CWB).pnl[0x3a]->in->obj;
    UiObjMoveTo(o, 6, -1, 668.0f, 204.0f);
    UiObjSetCommand(o, 0xf, 0);
    for (j = 0; j < 6; j++) {
        if (c->cur[1].mask & (1 << j)) {
            o = &(*(CampW_80178F6C*)CWB).pnl[0x3b + j]->in->obj;
            UiObjMoveTo(o, 6, -1, 668.0f, 204.0f);
            UiObjSetCommand(o, 0xf, 0);
        }
    }
    o = &(*(CampW_80178F6C*)CWB).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 0xf, 0);
}

void fn_801808D4(void) {
    s32 i;
    UiObj* o;

    o = &(*(CampW_80178F6C*)CWB).pnl[0x21]->in->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 125.0f);
    UiObjSetCommand(o, 0xf, 0);
    o = &(*(CampW_80178F6C*)CWB).pnl[0x6a]->in->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 189.0f);
    UiObjSetCommand(o, 0xf, 1);
    o = &(*(CampW_80178F6C*)CWB).pnl[0x9b]->in->obj;
    UiObjMoveTo(o, 6, -1, -408.0f, 253.0f);
    UiObjSetCommand(o, 0xf, 1);
    o = &(*(CampW_80178F6C*)CWB).pnl[0x9c]->in->obj;
    UiObjMoveTo(o, 6, -1, -408.0f, 317.0f);
    UiObjSetCommand(o, 0xf, 1);
    for (i = 0; i < 7; i++) {
        o = &(*(CampW_80178F6C*)CWB).pnl[0x48 + i]->in->obj;
        UiObjMoveTo(o, 6, -1, 668.0f, 204.0f);
        UiObjSetCommand(o, 0xf, 0);
    }
    o = &(*(CampW_80178F6C*)CWB).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 0xf, 0);
}

void fn_80180B80(void) {
    s32 i;
    UiObj* o;

    o = &(*(CampW_80178F6C*)CWB).pnl[0x6a]->in->obj;
    fn_80199BB8(o, -348.0f, 189.0f);
    fn_80199BAC(o, -348.0f, 189.0f);
    o = &(*(CampW_80178F6C*)CWB).pnl[0x9b]->in->obj;
    fn_80199BB8(o, -408.0f, 253.0f);
    fn_80199BAC(o, -408.0f, 253.0f);
    o = &(*(CampW_80178F6C*)CWB).pnl[0x9c]->in->obj;
    fn_80199BB8(o, -408.0f, 317.0f);
    fn_80199BAC(o, -408.0f, 317.0f);
    for (i = 0; i < 7; i++) {
        o = &(*(CampW_80178F6C*)CWB).pnl[0x48 + i]->in->obj;
        fn_80199BB8(o, 668.0f, 204.0f);
        fn_80199BAC(o, 668.0f, 204.0f);
    }
    o = &(*(CampW_80178F6C*)CWB).pnl[0x60]->in->obj;
    fn_80199BB8(o, 632.0f, 480.0f);
    fn_80199BAC(o, 632.0f, 480.0f);
}

void fn_801854B8(void) {
    CampCtrl* c = lbl_8034710C->holder->ctrl;
    s32 cur = fn_80194CC8();
    UiObj* o;

    if (cur != lbl_80347124) {
        lbl_803470C8 = 1;
        if (lbl_80347124 == 1) {
            (*(CampW_80178F6C*)CWB).pnl[0x1c]->in->hide = 1;
            o = &(*(CampW_80178F6C*)CWB).pnl[0x1c]->in->obj;
            UiObjMoveTo(o, 6, 5, -348.0f, 189.0f);
            UiObjSetCommand(o, 10, 0);
            c->cur[0].mask &= ~4;
            if (c->cur[0].sel == 2) {
                c->cur[0].sel = 0;
                UiObjSetCommand(&(*(CampW_80178F6C*)CWB).pnl[0x1a]->in->obj, 0x15, 0);
                fn_801929B8(4);
            }
        } else {
            (*(CampW_80178F6C*)CWB).pnl[0x1c]->in->hide = 1;
            o = &(*(CampW_80178F6C*)CWB).pnl[0x1c]->in->obj;
            fn_80199BB8(o, -348.0f, 189.0f);
            fn_80199BAC(o, -348.0f, 189.0f);
            UiObjSetLowered(o);
            UiObjMoveTo(o, 6, 4, -8.0f, 189.0f);
            UiObjSetCommand(o, 0xf, 0);
            c->cur[0].mask |= 4;
            if (c->cur[0].sel == 2) {
                UiObjSetCommand(o, 10, 0);
            }
        }
    }
    lbl_80347124 = cur;
}

void fn_801861F8(void) {
    s32 i;
    UiObj* o;
    CampCtrl* c = lbl_8034710C->holder->ctrl;

    o = &(*(CampW_80178F6C*)CWB).pnl[0x1c]->in->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 61.0f);
    UiObjSetCommand(o, 0xf, 0);
    for (i = 0; i < 2; i++) {
        o = &(*(CampW_80178F6C*)CWB).pnl[0x89 + i]->in->obj;
        UiObjMoveTo(o, 6, 5, -348.0f, (f32)((i + 1) * 64 + 61));
        if (c->cur[0].sel == i) {
            UiObjSetCommand(o, 10, i);
        } else {
            UiObjSetCommand(o, 0xf, i + 1);
        }
    }
    o = &(*(CampW_80178F6C*)CWB).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 0xf, 0);
}

void fn_801867B8(Self* self) {
    UiObj* obj = &self->inner->obj;
    s32 idx;
    f32 y;

    switch (self->inner->type) {
    case 0x66:
        idx = lbl_80307638[13].cur[0].sel;
        break;
    }
    y = (f32)(idx * 0x18 + 0x7c);
    fn_80199BB8(obj, 0.0f, y);
    fn_80199BAC(obj, 0.0f, y);
    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            self->inner->f8c = lbl_8034710C->holder->ctrl->f74;
            fn_800FF3EC(self->inner);
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(self->inner);
        self->flags |= 0x40;
        break;
    }
}

void fn_8018858C(Self* self) {
    UiObj* obj = &self->inner->obj;
    s32 idx;
    f32 y;

    switch (self->inner->type) {
    case 0x61:
        idx = lbl_80307638[7].cur[0].sel;
        break;
    case 0x62:
        idx = lbl_80307638[5].cur[0].sel;
        break;
    case 0x63:
        idx = lbl_80307638[9].cur[0].sel;
        break;
    case 0x64:
        idx = lbl_80307638[10].cur[0].sel;
        break;
    case 0x65:
        idx = lbl_80307638[12].cur[0].sel;
        break;
    }
    y = (f32)(idx * 0x18 + 0xcc);
    fn_80199BB8(obj, 328.0f, y);
    fn_80199BAC(obj, 328.0f, y);
    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            self->inner->f8c = lbl_8034710C->holder->ctrl->f74;
            fn_800FF3EC(self->inner);
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(self->inner);
        self->flags |= 0x40;
        break;
    }
}

void fn_80189B70(Self_80189B70* self) {
    Sub* sub;
    s32 y;
    s32 x;
    Inner_80189B70* in;
    UiObj* obj = &self->inner->obj;
    f32 z;

    if (lbl_803475D8 != 0) {
        self->state = 0xff;
    }
    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            CampPanelDrawFrame(self->inner);
            in = self->inner;
            sub = in->sub;
            if (sub->str != 0) {
                x = (s32)in->obj.rect[0];
                y = (s32)in->obj.rect[1];
                z = TextGetZ();
                TextSetZ(10.0f + in->f74);
                TextPushColor();
                TextSetColor(0xff201008);
                TextPrint(x + 0x14, y + 0xc, sub->str);
                TextPopColor(1);
                TextSetZ(z);
            }
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(self->inner);
        self->flags |= 0x40;
        break;
    }
}

void fn_8018A16C(Self_8018A16C* self) {
    Inner_8018A16C* inner = self->inner;
    UiObj* obj = &inner->obj;
    Sub_8018A16C* sub = inner->sub;

    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        if (lbl_803475D8 != 0) {
            self->state = 0xff;
        }
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            fn_80296EEC(0, 3, 0);
            CampPanelDrawFrame(self->inner);
            fn_80296EEC(1, 3, 1);
            switch (sub->mode) {
            case 1:
                fn_8018A2D8(self->inner);
                break;
            case 0:
                fn_8018D250(self->inner);
                break;
            case 2:
                fn_8018C8B4(self->inner);
                break;
            case 3:
                fn_8018C8B4(self->inner);
                fn_80194F88(self->inner);
                break;
            }
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(inner);
        self->flags |= 0x40;
        break;
    }
}

s32 fn_8017A510(void) {
    CampCtrl* c = lbl_8034710C->holder->ctrl;

    if (fn_801C09F8(lbl_80347154, 5)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = fn_8019A21C(c->cur[0].mask, 1, c->cur[0].sel, 0, 7);
        goto upd;
    } else if (fn_801C09F8(lbl_80347154, 4)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = fn_8019A21C(c->cur[0].mask, -1, c->cur[0].sel, 0, 7);
        goto upd;
    } else if (fn_801C09F8(lbl_80347154, 7)) {
        c->cur[4].x8 = c->cur[4].sel;
        c->cur[4].sel = 1;
        if (c->cur[4].x8 != c->cur[4].sel) goto snd;
    } else if (fn_801C09F8(lbl_80347154, 6)) {
        c->cur[4].x8 = c->cur[4].sel;
        c->cur[4].sel = 0;
        if (c->cur[4].x8 != c->cur[4].sel) goto snd;
    } else if (fn_801C09F8(lbl_80347154, 2)) {
        fn_801929B8(2);
        return 1;
    } else if (fn_801C09F8(lbl_80347154, 1)) {
        fn_801929B8(5);
        return -1;
    }
    goto end;
upd:
    fn_801954D0(lbl_802E9908[c->cur[0].sel].help);
    fn_801929B8(0);
    goto end;
snd:
    fn_801929B8(0);
end:
    return 0;
}

void fn_8017A754(void) {
    s32 i;
    UiObj* o;

    o = &(*(CampW_80178F6C*)CWB).pnl[0x1d]->in->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 61.0f);
    UiObjSetCommand(o, 0xf, 0);
    for (i = 0; i < 3; i++) {
        o = &(*(CampW_80178F6C*)CWB).pnl[0x91 + i]->in->obj;
        UiObjMoveTo(o, 6, 5, -398.0f, (f32)((i + 1) * 64 + 61));
        if (lbl_802E9418[i]() == 1) {
            UiObjSetCommand(o, 10, 0);
        } else {
            UiObjSetCommand(o, 0xf, 0);
        }
    }
    o = &(*(CampW_80178F6C*)CWB).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 0xf, 0);
}

void fn_8017A8A8(void) {
    s32 i;
    UiObj* o;

    o = &(*(CampW_80178F6C*)CWB).pnl[0x91]->in->obj;
    UiObjMoveTo(o, 6, 4, -8.0f, 61.0f);
    UiObjSetCommand(o, 0xf, 0);
    for (i = 0; i < 3; i++) {
        o = &(*(CampW_80178F6C*)CWB).pnl[0x91 + i]->in->obj;
        UiObjMoveTo(o, 6, -1, -8.0f, (f32)((i + 1) * 64 + 61));
        if (lbl_802E9418[i]() == 1) {
            UiObjSetCommand(o, 10, 0);
        } else {
            UiObjSetCommand(o, 0xf, 0);
        }
    }
    o = &(*(CampW_80178F6C*)CWB).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 0xf, 0);
}

void fn_801841DC(void) {
    s32 i;
    u32 mask = 0;
    CampCtrl* c = lbl_8034710C->holder->ctrl;

    for (i = 0; i < (*(CampW_80178F6C*)CWB).count; i++) {
        mask |= 1 << i;
    }
    c->cur[0].mask = mask;
    if (fn_801953B8() != 0) {
        c->cur[0].mask |= 0x10;
    }
    if (fn_80194CB8() == 1) {
        c->cur[0].mask |= 0x20;
    }
    c->cur[4].mask = 0x1f;
    c->cur[1].mask = 0x1f;
    fn_80195A68(c, 1, 0, 0, 0, 1);
}

void fn_8017D35C(void) {
    CampCtrl* c;
    UiObj* o;
    UiObj* q;
    s32 i;
    s32 base;
    s32 n;
    s32 off;

    c = lbl_8034710C->holder->ctrl;
    switch (c->cur[2].sel) {
    case 0: base = 0x7a; n = 5; off = 0; break;
    case 1: base = 0x7f; n = 3; off = 0; break;
    }
    for (i = 0; i < n; i++) {
        q = &(*(CampW_8017D35C*)CWB).pnl[base + i]->in->obj;
        UiObjMoveTo(q, 6, -1, 668.0f, (f32)((off + i) * 64 + 61));
        UiObjSetCommand(q, 15, 0);
        (*(CampW_8017D35C*)CWB).pnl[base + i]->in->f74 -= 150.0f;
    }
    o = &(*(CampW_8017D35C*)CWB).pnl[0x6e]->in->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 189.0f);
    UiObjSetCommand(o, 15, 0);
    o = &(*(CampW_8017D35C*)CWB).pnl[0x6f]->in->obj;
    UiObjMoveTo(o, 6, 5, -348.0f, 253.0f);
    UiObjSetCommand(o, 15, 1);
    o = &(*(CampW_8017D35C*)CWB).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_8017EBD8(void) {
    UiObj* o;
    s32 i;
    s32 base;
    s32 n;
    s32 off;
    CampCtrl* c;

    c = lbl_8034710C->holder->ctrl;
    o = &(*(CampW_8017D35C*)CWB).pnl[4]->in->obj;
    UiObjMoveTo(o, 6, -1, -8.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 2; i++) {
        if (c->cur[0].mask & (1 << i)) {
            o = &(*(CampW_8017D35C*)CWB).pnl[0x78 + i]->in->obj;
            if (i == c->cur[0].sel) {
                UiObjMoveTo(o, 6, -1, -8.0f, 125.0f);
                UiObjSetCommand(o, 15, i + 2);
            } else {
                UiObjMoveTo(o, 6, -1, -348.0f, (f32)((i + 1) * 64 + 61));
                UiObjSetCommand(o, 15, i + 2);
            }
        }
    }
    o = &(*(CampW_8017D35C*)CWB).pnl[0x6c]->in->obj;
    UiObjMoveTo(o, 6, -1, 668.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    switch (c->cur[2].sel) {
    case 0: base = 0x7a; n = 5; off = 1; break;
    case 1: base = 0x7f; n = 3; off = 1; break;
    }
    for (i = 0; i < n; i++) {
        o = &(*(CampW_8017D35C*)CWB).pnl[base + i]->in->obj;
        UiObjSetLowered(o);
        UiObjMoveTo(o, 6, 5, 668.0f, (f32)((off + i) * 64 + 61));
        UiObjSetCommand(o, 15, i + off);
        (*(CampW_8017D35C*)CWB).pnl[base + i]->in->f74 -= 150.0f;
    }
}

void fn_8017EE48(void) {
    UiObj* o;
    s32 i;
    s32 base;
    s32 n;
    s32 off;
    CampCtrl* c;

    c = lbl_8034710C->holder->ctrl;
    o = &(*(CampW_8017D35C*)CWB).pnl[4]->in->obj;
    UiObjMoveTo(o, 6, -1, -348.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 2; i++) {
        if (c->cur[0].mask & (1 << i)) {
            o = &(*(CampW_8017D35C*)CWB).pnl[0x78 + i]->in->obj;
            UiObjMoveTo(o, 6, -1, -348.0f, (f32)((i + 1) * 64 + 61));
            UiObjSetCommand(o, 15, i + 2);
        }
    }
    o = &(*(CampW_8017D35C*)CWB).pnl[0x6c]->in->obj;
    UiObjMoveTo(o, 6, -1, 668.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    switch (c->cur[2].sel) {
    case 0: base = 0x7a; n = 5; off = 1; break;
    case 1: base = 0x7f; n = 3; off = 1; break;
    }
    for (i = 0; i < n; i++) {
        o = &(*(CampW_8017D35C*)CWB).pnl[base + i]->in->obj;
        UiObjSetLowered(o);
        UiObjMoveTo(o, 6, 5, 668.0f, (f32)((off + i) * 64 + 61));
        UiObjSetCommand(o, 15, i + off);
        (*(CampW_8017D35C*)CWB).pnl[base + i]->in->f74 += 150.0f;
    }
}

void fn_80188274(Req_80188274 *r, Pos_80188274 *p);
void fn_80188098(Inner_8016F138 *self) {
    extern Spr_80188274 *fn_801D68C4(void *bank, u32 n);
    extern void fn_801D4F0C(Spr_80188274 *s, f32 f1, f32 f2, f32 f3, f32 f4, s32 a, s32 b, s32 c);
    Spr_80188274 *s;
    s32 x;
    s16 y;
    s16 xx;
    s16 i = 0;
    Pos_80188274 *pos = &self->pos;
    Inn_80188098 *inn = self->inn;
    s32 sy;
    y = (s16)self->obj.rect[1];
    x = (s16)self->obj.rect[0];
    xx = x;
    for (; i < 6; i++) {
        s32 on = (((s32)inn->mask) & (1 << i)) != 0;
        if (on == 1) {
            Req_80188274 r;
            f32 a;
            if (i == inn->sel->sel) a = 1.0f; else a = 0.5f;
            r.x = xx;
            r.y = y;
            r.a = a;
            r.idx = i;
            r.b = 10.0f + pos->f0;
            fn_80188274(&r, pos);
        }
        xx += 0x30;
    }
    s = fn_801D68C4(lbl_803470F0, 0x44);
    s->x = (f32)(x + inn->sel->sel * 0x30 + 0xe);
    sy = y + 0x11;
    s->y = (f32)sy;
    fn_801D4F0C(s, -4000.0f, pos->f4, 1.0f, 1.0f, pos->ic, pos->i8, 1);
    s = fn_801D68C4(lbl_803470F0, 0x43);
    s->x = (f32)(x + inn->sel->sel * 0x30 + 0x36);
    s->y = (f32)sy;
    fn_801D4F0C(s, -4000.0f, pos->f4, 1.0f, 1.0f, pos->ic, pos->i8, 1);
}

void fn_80188274(Req_80188274 *r, Pos_80188274 *p) {
    extern void *lbl_803470F4;
    extern Spr_80188274 *fn_801D68C4(void *bank, u32 n);
    extern void fn_801D4F0C(Spr_80188274 *s, f32 f1, f32 f2, f32 f3, f32 f4, s32 a, s32 b, s32 c);
    extern void fn_801D52A8(Spr_80188274 *s, f32 f1, f32 f2, f32 f3, f32 f4, s32 a, s32 b);
    s16 x = r->x;
    s16 y = r->y;
    f32 a, b;
    Spr_80188274 *s1, *s2;
    b = r->b;
    a = r->a;
    switch (r->idx) {
    case 0:
        s1 = fn_801D68C4(lbl_803470F4, 0x2b);
        s2 = fn_801D68C4(lbl_803470F0, 0x34);
        break;
    case 1:
        s1 = fn_801D68C4(lbl_803470F4, 0x2c);
        s2 = fn_801D68C4(lbl_803470F0, 0x35);
        break;
    case 2:
        s1 = fn_801D68C4(lbl_803470F4, 0x2e);
        s2 = fn_801D68C4(lbl_803470F0, 0x37);
        break;
    case 3:
        s1 = fn_801D68C4(lbl_803470F4, 0x2d);
        s2 = fn_801D68C4(lbl_803470F0, 0x36);
        break;
    case 4:
        s1 = fn_801D68C4(lbl_803470F4, 0x2f);
        s2 = fn_801D68C4(lbl_803470F0, 0x38);
        break;
    case 5:
        s1 = fn_801D68C4(lbl_803470F4, 0x30);
        s2 = fn_801D68C4(lbl_803470F0, 0x39);
        break;
    }
    s2->x = (f32)(x + 0x1c);
    s2->y = (f32)(y + 6);
    fn_801D4F0C(s2, b, p->f4, a, p->f18 + p->f1c, p->ic, p->i8, 1);
    s1->x = (f32)(x + 0x1e);
    s1->y = (f32)(y + 0x1e);
    fn_801D52A8(s1, b, p->f4, a, p->f18 + p->f1c, p->ic, p->i8);
}

void fn_8018C6A8(Obj_8018C6A8 *self, f32 f) {
    extern void *lbl_803470E8;
    extern void *lbl_803470F4;
    extern void *fn_801D68C4(void *bank, u32 n);
    extern void fn_8019A15C(void *p, s32 a, s32 b, s32 c);
    extern void fn_80199FFC(void *p, s32 a, void *b, s32 c, s32 d, s32 e);
    Pos_8018C6A8 *p = &self->pos;
    p->f0 = -6790.0f;
    p->f4 = 0.0f;
    p->f10 = 1.0f;
    p->f14 = f;
    p->f18 = 1.0f;
    p->f1c = 0.0f;
    p->i8 = 0;
    p->ic = 0;
    fn_8019A15C(p, 1, 8, 1);
    fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F0, 10), 0, 0, 0);
    fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x10), 0x10, 6, 2);
    fn_80199FFC(p, 1, fn_801D68C4(lbl_803470F4, 0x11), 0x58, 6, 2);
    fn_80199FFC(p, 2, fn_801D68C4(lbl_803470F4, 0x12), 0xa0, 6, 2);
    fn_80199FFC(p, 3, fn_801D68C4(lbl_803470F4, 0x13), 0xe8, 6, 2);
    fn_80199FFC(p, 4, fn_801D68C4(lbl_803470F4, 0x14), 0x10, 0x1e, 2);
    fn_80199FFC(p, 5, fn_801D68C4(lbl_803470F4, 0x15), 0x58, 0x1e, 2);
    fn_80199FFC(p, 6, fn_801D68C4(lbl_803470F4, 0x16), 0xa0, 0x1e, 2);
    fn_80199FFC(p, 7, fn_801D68C4(lbl_803470F4, 0x35), 6, 6, 2);
    p->sp->spr = fn_801D68C4(lbl_803470E8, 2);
    p->fp[0] = 0.0f;
    p->fp[1] = 0.0f;
    p->spr44 = fn_801D68C4(lbl_803470F0, 1);
}

void fn_8018FB9C(Obj_8018FB9C *self, s32 id) {
    s16 x = (s16)self->x;
    s16 y = (s16)self->y;
    fn_8019A374(id == -1 ? 0 : fn_80195184(id), (f32)(x + 0x33), (f32)(y + 0x22), 10.0f + self->z, 0xff201008, 0);
    fn_8019A374(id == -1 ? 0 : fn_80195148(id), (f32)(x + 0x7b), (f32)(y + 0x22), 10.0f + self->z, 0xff201008, 0);
    fn_8019A374(id == -1 ? 0 : fn_801950D0(id), (f32)(x + 0xc3), (f32)(y + 0x22), 10.0f + self->z, 0xff201008, 0);
    fn_8019A374(id == -1 ? 0 : fn_8019510C(id), (f32)(x + 0x10b), (f32)(y + 0x22), 10.0f + self->z, 0xff201008, 0);
}

inline s32 Test_80192EDC(u32 b) {
    return (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
}

#define FLAG(b) ((lbl_80310B3C[(b) >> 5] & (1 << ((b) & 31))) != 0)

static inline u32 Find_801929FC(s32 v) {
    s32 i;
    u32 r;
    for (i = 0; i < 0x58; i++) {
        if (v == lbl_802ED258[i].id) {
            r = i;
            goto done;
        }
    }
    if (i == 0x58) {
        r = 0;
    }
done:
    return r;
}
static inline s32 GetMode(void) {
    s32 r = 0;
    switch (lbl_80307638[15].cur[0].sel) {
    case 0: r = 0; break;
    case 1: r = 1; break;
    }
    return r;
}
s32 fn_80192B04(void) {
    s32 mode;
    s32 found;
    s32 i;
    s32 set;

    mode = GetMode();
    found = 0;
    switch (mode) {
    case 0:
        for (i = 0; i < 24; i++) {
            u32 b = lbl_802EBA00[i].id;
            set = FLAG(b);
            if (set != 0) {
                if (found == 1) {
                    return 1;
                }
                found = 1;
            }
        }
        break;
    case 1:
        for (i = 0; i < 0x58; i++) {
            if ((lbl_80310B3C[(Find_801929FC(i) + 0xb54) >> 5] & (1 << ((Find_801929FC(i) + 0xb54) & 31)))) {
                if (found == 1) {
                    return 1;
                }
                found = 1;
            }
        }
        break;
    }
    return 0;
}

void fn_80192EDC(Cur_80192EDC *c) {
    s32 row = c->row;
    s32 col = c->col;
    s32 w = 8;
    s32 lim;
    s32 start;
    s32 i;
    if (c->mode == 0) w = 6;
    lim = 0x58;
    if (c->mode == 0) lim = 0x18;
    c->found = 0;
    if (c->dir == -1) {
        start = row * w + col;
        for (i = start - 1; i >= 0; i--) {
            if (Test_80192EDC(lbl_802EBA00[i].id) != 0) {
                c->found = 1;
                c->found_idx = i;
                break;
            }
        }
        if (c->found != 1) {
            for (i = lim - 1; i > start; i--) {
                if (Test_80192EDC(lbl_802EBA00[i].id) != 0) {
                    c->found = 1;
                    c->found_idx = i;
                    break;
                }
            }
        }
    } else {
        start = row * w + col;
        for (i = start + 1; i < lim; i++) {
            if (Test_80192EDC(lbl_802EBA00[i].id) != 0) {
                c->found = 1;
                c->found_idx = i;
                break;
            }
        }
        if (c->found != 1) {
            for (i = 0; i < start; i++) {
                if (Test_80192EDC(lbl_802EBA00[i].id) != 0) {
                    c->found = 1;
                    c->found_idx = i;
                    break;
                }
            }
        }
    }
    if (c->found == 1) {
        c->row = c->found_idx / w;
        c->col = c->found_idx % w;
    }
}

void fn_80177D7C(void) {
    CampCtrl* c;
    s32 i;

    c = lbl_8034710C->holder->ctrl;
    CampMenuHideAllPanels();
    ((Pnl_80177D7C**)(CWB + 0x10))[lbl_80307638[1].cur[0].sel]->in->hide = 1;
    ((Pnl_80177D7C**)(CWB + 0x8c))[lbl_80307638[3].cur[0].sel]->in->hide = 1;
    PNL_80177D7C(0xdc)->in->hide = 1;
    for (i = 0; i < 6; i++) {
        if (c->cur[1].mask & (1 << i)) {
            (*(Pnl_80177D7C**)(CWB + 0xdc + 4 + i * 4))->in->hide = 1;
        }
    }
    PNL_80177D7C(0x190)->in->hide = 1;
    PNL_80177D7C(0x194)->in->hide = 0;
}

s32 fn_801780C8(void) {
    CampCtrl* c;
    UiObj* o;
    s32 r;

    switch (camp_work.state[5]) {
    case 0:
        c = lbl_8034710C->holder->ctrl;
        fn_80179554();
        c->cur[6].mask = 2;
        fn_80195A68(c, 1, 1, 0, 0, 0);
        fn_801954D0(0);
        fn_80179388();
        fn_801792A4();
        fn_801790C8();
        camp_work.state[5] = 2;
        break;
    case 1:
        c = lbl_8034710C->holder->ctrl;
        fn_80179554();
        c->cur[6].mask = 2;
        fn_80195A68(c, 1, 1, 0, 0, 0);
        fn_801954D0(0);
        fn_80179388();
        camp_work.pnl[0x62]->win->x0 = 1;
        fn_801791E0();
        o = &camp_work.pnl[lbl_80307638[1].cur[0].sel]->win->obj;
        UiObjMoveTo(o, 6, 4, -8.0f, 61.0f);
        UiObjSetCommand(o, 15, 0);
        o = &camp_work.pnl[lbl_80307638[3].cur[0].sel + 0x1f]->win->obj;
        UiObjMoveTo(o, 6, 4, -8.0f, 125.0f);
        UiObjSetCommand(o, 15, 1);
        camp_work.state[5] = 2;
        break;
    case 2:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.state[5] = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.state[5] = 3;
        }
        break;
    case 3:
        r = fn_801786C0();
        fn_801784D8();
        switch (r) {
        case -1:
            camp_work.state[5] = 0x18;
            break;
        case 1:
            camp_work.state[5] = 0xc;
            break;
        }
        break;
    case 12:
        o = &camp_work.pnl[lbl_80307638[1].cur[0].sel]->win->obj;
        UiObjMoveTo(o, 6, 5, -348.0f, 61.0f);
        UiObjSetCommand(o, 15, 0);
        o = &camp_work.pnl[lbl_80307638[3].cur[0].sel + 0x1f]->win->obj;
        UiObjMoveTo(o, 6, 5, -348.0f, 125.0f);
        UiObjSetCommand(o, 15, 1);
        camp_work.state[5] = 0x12;
        break;
    case 18:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.state[6] = 0;
            camp_screen = 6;
            fn_801959D4(6);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.state[6] = 0;
            camp_screen = 6;
            fn_801959D4(6);
        }
        break;
    case 24:
        camp_work.pnl[0x62]->win->x0 = 0;
        fn_80178F6C();
        camp_work.state[5] = 0x13;
        break;
    case 19:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.state[3] = 0;
            camp_screen = 3;
            fn_801959D4(3);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.state[3] = 0;
            camp_screen = 3;
            fn_801959D4(3);
        }
        break;
    }
    return 0;
}

void fn_80172C60(void) {
    UiObj* ui;
    ui = &PNL_80172C60(0x20)->win->ui;
    UiObjMoveTo(ui, 6, 5, -348.0f, 125.0f);
    UiObjSetCommand(ui, 0xF, 0);
    ui = &PNL_80172C60(0x1E8)->win->ui;
    UiObjMoveTo(ui, 6, 5, -348.0f, 189.0f);
    UiObjSetCommand(ui, 0xF, 1);
    ui = &PNL_80172C60(0x1EC)->win->ui;
    UiObjMoveTo(ui, 6, 5, -348.0f, 253.0f);
    UiObjSetCommand(ui, 0xF, 2);
    ui = &PNL_80172C60(0x224)->win->ui;
    UiObjSetLowered(ui);
    UiObjMoveTo(ui, 6, -1, 668.0f, 61.0f);
    UiObjSetCommand(ui, 0xF, 0);
    ui = &PNL_80172C60(0x21C)->win->ui;
    UiObjSetLowered(ui);
    UiObjMoveTo(ui, 6, -1, 668.0f, 119.0f);
    UiObjSetCommand(ui, 0xF, 0);
    ui = &PNL_80172C60(0x228)->win->ui;
    UiObjSetLowered(ui);
    UiObjMoveTo(ui, 6, -1, 668.0f, 183.0f);
    UiObjSetCommand(ui, 0xF, 1);
    ui = &PNL_80172C60(0x220)->win->ui;
    UiObjSetLowered(ui);
    UiObjMoveTo(ui, 6, -1, 668.0f, 241.0f);
    UiObjSetCommand(ui, 0xF, 1);
    ui = &PNL_80172C60(0x190)->win->ui;
    UiObjSetLowered(ui);
    UiObjMoveTo(ui, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(ui, 0xF, 1);
}

void fn_80173104(void) {
    UiObj* ui;
    ui = &PNL_80173104(0x20)->win->ui;
    fn_80199BB8(ui, -348.0f, 125.0f);
    fn_80199BAC(ui, -348.0f, 125.0f);
    ui = &PNL_80173104(0x1E8)->win->ui;
    fn_80199BB8(ui, -348.0f, 189.0f);
    fn_80199BAC(ui, -348.0f, 189.0f);
    ui = &PNL_80173104(0x1EC)->win->ui;
    fn_80199BB8(ui, -348.0f, 253.0f);
    fn_80199BAC(ui, -348.0f, 253.0f);
    ui = &PNL_80173104(0x224)->win->ui;
    fn_80199BB8(ui, 668.0f, 61.0f);
    fn_80199BAC(ui, 668.0f, 61.0f);
    ui = &PNL_80173104(0x21C)->win->ui;
    fn_80199BB8(ui, 668.0f, 119.0f);
    fn_80199BAC(ui, 668.0f, 119.0f);
    ui = &PNL_80173104(0x228)->win->ui;
    fn_80199BB8(ui, 668.0f, 183.0f);
    fn_80199BAC(ui, 668.0f, 183.0f);
    ui = &PNL_80173104(0x220)->win->ui;
    fn_80199BB8(ui, 668.0f, 241.0f);
    fn_80199BAC(ui, 668.0f, 241.0f);
    ui = &PNL_80173104(0x190)->win->ui;
    fn_80199BB8(ui, 632.0f, 480.0f);
    fn_80199BAC(ui, 632.0f, 480.0f);
}

void fn_80174F40(s32 unused, s8 mode) {
    CampCtrl* c = lbl_8034710C->holder->ctrl;
    UiObj* q;
    UiObj* p;
    s16 se;
    s32 i;
    UiObj* ui;
    f32 x, y, x2, y2, x3, y3;
    switch (mode) {
    case 0:
        ui = &((Pnl_80172C60**)(CWB + 0x10))[c->cur[2].sel]->win->ui;
        x = -8.0f;
        y = 61.0f;
        x2 = 24.0f;
        y2 = 384.0f;
        x3 = 328.0f;
        y3 = 194.0f;
        se = 4;
        break;
    case 1:
        ui = &((Pnl_80172C60**)(CWB + 0x10))[c->cur[2].x8]->win->ui;
        x = -348.0f;
        y = 61.0f;
        x2 = 632.0f;
        y2 = 480.0f;
        x3 = 668.0f;
        y3 = 194.0f;
        se = 5;
        break;
    }
    UiObjFinish(ui);
    UiObjMoveTo(ui, 6, -1, x, y);
    UiObjSetCommand(ui, 0xF, 0);
    ui = &PNL_80174F40(0x1B0)->win->ui;
    UiObjFinish(ui);
    UiObjMoveTo(ui, 6, -1, x, y3);
    UiObjSetCommand(ui, 0xF, 1);
    for (i = 0; i < 3; i++) {
        p = &((Pnl_80172C60**)CWB)[0x178 / 4 + i]->win->ui;
        UiObjFinish(p);
        UiObjMoveTo(p, 6, se, x3, y + (f32)(i * 0x58));
        UiObjSetCommand(p, 0xF, i);
    }
    q = &PNL_80174F40(0x190)->win->ui;
    UiObjFinish(q);
    UiObjMoveTo(q, 6, -1, x2, y2);
    UiObjSetCommand(q, 0xF, 0);
}

void fn_801764E4(void) {
    UiObj* ui;
    Pnl_80172C60** arr;
    s32 k;
    ui = &PNL_801764E4(0x1B0)->win->ui;
    UiObjMoveTo(ui, 6, 4, -348.0f, 194.0f);
    UiObjSetCommand(ui, 0xA, 1);
    ui = &PNL_801764E4(0x1B4)->win->ui;
    UiObjMoveTo(ui, 6, 4, -348.0f, 258.0f);
    UiObjSetCommand(ui, 0xA, 2);
    ui = &PNL_801764E4(0x184)->win->ui;
    UiObjMoveTo(ui, 6, 4, 668.0f, 61.0f);
    UiObjSetCommand(ui, 0xF, 0);
    ui = &PNL_801764E4(0x188)->win->ui;
    UiObjMoveTo(ui, 6, -1, 668.0f, 143.0f);
    UiObjSetCommand(ui, 0xF, 0);
    ui = &PNL_801764E4(0x114)->win->ui;
    UiObjMoveTo(ui, 6, -1, 668.0f, 204.0f);
    UiObjSetCommand(ui, 0xF, 1);
    arr = (Pnl_80172C60**)(CWB + 0x10);
    k = lbl_80307638[8].cur[0].sel + 0x43;
    ui = &arr[k]->win->ui;
    UiObjMoveTo(ui, 6, -1, 668.0f, 204.0f);
    UiObjSetCommand(ui, 0xF, 1);
    ui = &PNL_801764E4(0x190)->win->ui;
    UiObjMoveTo(ui, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(ui, 0xF, 0);
}

void fn_80176868(void) {
    UiObj* ui;
    Pnl_80172C60** arr;
    s32 k;
    ui = &PNL_80176868(0x1B4)->win->ui;
    fn_80199BB8(ui, -348.0f, 258.0f);
    fn_80199BAC(ui, -348.0f, 258.0f);
    ui = &PNL_80176868(0x18C)->win->ui;
    fn_80199BB8(ui, -348.0f, 258.0f);
    fn_80199BAC(ui, -348.0f, 258.0f);
    ui = &PNL_80176868(0x184)->win->ui;
    fn_80199BB8(ui, 668.0f, 61.0f);
    fn_80199BAC(ui, 668.0f, 61.0f);
    ui = &PNL_80176868(0x188)->win->ui;
    fn_80199BB8(ui, 668.0f, 143.0f);
    fn_80199BAC(ui, 668.0f, 143.0f);
    ui = &PNL_80176868(0x114)->win->ui;
    fn_80199BB8(ui, 668.0f, 204.0f);
    fn_80199BAC(ui, 668.0f, 204.0f);
    arr = (Pnl_80172C60**)(CWB + 0x10);
    k = lbl_80307638[8].cur[0].sel + 0x43;
    ui = &arr[k]->win->ui;
    fn_80199BB8(ui, 668.0f, 204.0f);
    fn_80199BAC(ui, 668.0f, 204.0f);
    ui = &PNL_80176868(0x19C)->win->ui;
    fn_80199BB8(ui, 328.0f, 204.0f);
    fn_80199BAC(ui, 328.0f, 204.0f);
    ui = &PNL_80176868(0x190)->win->ui;
    fn_80199BB8(ui, 632.0f, 480.0f);
    fn_80199BAC(ui, 632.0f, 480.0f);
}

void fn_80178D2C(s32 unused, s8 mode) {
    CampCtrl* c = lbl_8034710C->holder->ctrl;
    UiObj* q;
    UiObj* p;
    s16 se;
    s32 i;
    UiObj* ui;
    f32 x, y, x2, y2, x3, y3;
    switch (mode) {
    case 0:
        ui = &((Pnl_80172C60**)(CWB + 0x10))[c->cur[2].sel]->win->ui;
        x = 328.0f;
        y = 204.0f;
        x2 = -8.0f;
        y2 = 61.0f;
        x3 = 24.0f;
        y3 = 384.0f;
        se = 4;
        break;
    case 1:
        ui = &((Pnl_80172C60**)(CWB + 0x10))[c->cur[2].x8]->win->ui;
        x = 668.0f;
        y = 204.0f;
        x2 = -348.0f;
        y2 = 61.0f;
        x3 = 632.0f;
        y3 = 480.0f;
        se = 5;
        break;
    }
    UiObjFinish(ui);
    UiObjMoveTo(ui, 6, se, x2, y2);
    UiObjSetCommand(ui, 0xF, 2);
    ui = &PNL_80178D2C(0xF8)->win->ui;
    UiObjMoveTo(ui, 6, se, x, y);
    UiObjSetCommand(ui, 0xF, 0);
    for (i = 0; i < 6; i++) {
        p = &((Pnl_80172C60**)CWB)[0xFC / 4 + i]->win->ui;
        UiObjMoveTo(p, 6, -1, x, y);
        UiObjSetCommand(p, 0xF, 0);
    }
    q = &PNL_80178D2C(0x190)->win->ui;
    UiObjFinish(q);
    UiObjMoveTo(q, 6, se, x3, y3);
    UiObjSetCommand(q, 0xF, 3);
}

void fn_8017379C(void) {
    u8 buf[0x60];
    s32 i, j;
    s32 k;
    CampCtrl* c = lbl_8034710C->holder->ctrl;
    W_8017379C* w = MID()->hm->w;
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 2; j++) {
            fn_80194C68((void *)(buf), i, j, -1);
        }
    }
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 2; j++) {
            k = i * 2 + j;
            if (fn_801E4BF4(k) != 0) {
                if (fn_801E4BBC(k) != 0) {
                    fn_80194C68((void *)(buf), i, 0, k);
                } else {
                    fn_80194C68((void *)(buf), i, 1, k);
                }
            } else {
                fn_80194C68((void *)(buf), i, j, -1);
            }
        }
    }
    fn_801869B8((void *)(w), (void *)(buf));
    c->cur[0].mask = w->mask;
    for (i = 0; i < 32; i++) {
        if (c->cur[0].mask & (1 << i)) {
            c->cur[0].sel = i;
            break;
        }
    }
    c->cur[4].mask = 0;
    fn_80195A68((void *)(c), 1, 0, 0, 0, 1);
}

void fn_801784D8(void) {
    u8* cw = CWB;
    CampCtrl *tb = lbl_80307638;
    CampCtrl* c = lbl_8034710C->holder->ctrl;
    Win_801784D8* w;
    Eff_801784D8* e;
    f32 x;
    if (*(s8*)(cw + 0xC) > 1) {
        w = ((Pnl_801784D8**)(cw + 0x10))[tb[1].cur[0].sel]->win;
        e = ((Eff_801784D8*)fn_801D68C4((void *)(lbl_803470F0), 0x45));
        e->x = 24.0f + w->rx;
        e->y = -16.0f + w->ry;
        fn_800FF348((void *)(e), 0, -3100.0f, 1.0f, *(f32*)(cw + 0x34C));
        e = ((Eff_801784D8*)fn_801D68C4((void *)(lbl_803470F0), 0x46));
        e->x = 272.0f + w->rx;
        e->y = -16.0f + w->ry;
        fn_800FF348((void *)(e), 0, -3100.0f, 1.0f, *(f32*)(cw + 0x34C));
    }
    if (fn_801952D0(c->cur[1].mask) > 1) {
        w = (*(Pnl_801784D8**)(CWB + 0xF8))->win;
        x = 5.0f + w->rx + (f32)(c->cur[1].sel * 0x30);
        e = ((Eff_801784D8*)fn_801D68C4((void *)(lbl_803470F0), 0x44));
        e->x = x;
        e->y = 179.0f;
        fn_800FF348((void *)(e), 0, -3100.0f, 1.0f, *(f32*)(cw + 0x354));
        x = 47.0f + w->rx + (f32)(c->cur[1].sel * 0x30);
        e = ((Eff_801784D8*)fn_801D68C4((void *)(lbl_803470F0), 0x43));
        e->x = x;
        e->y = 179.0f;
        fn_800FF348((void *)(e), 0, -3100.0f, 1.0f, *(f32*)(cw + 0x354));
    }
}

extern s32 fn_801954EC(CampReq* r);
extern void fn_80178A60(void);
s32 fn_801786C0(void) {
    CampCtrl* c = lbl_8034710C->holder->ctrl;
    s32 n;
    CampReq list;
    s32 who;
    s32 w1;

    w1 = lbl_8030B7F4.party[lbl_80307638[1].cur[0].sel];
    n = fn_80195D8C(w1, c->cur[1].sel, 1, c->cur[4].sel);
    camp_work.pnl[0x62]->win->x0 = 1;
    fn_80195A68(c, 1, 1, 0, 0, 0);
    who = lbl_8030B7F4.party[lbl_80307638[1].cur[0].sel];
    fn_80195EA4(&list, who, c->cur[1].sel, c->cur[4].sel, 1);
    fn_801954D0(list.e[c->cur[0].sel].x10);
    switch (c->cur[6].mask) {
    case 6:
        camp_work.pnl[0x62]->win->x0 = 0;
        fn_80178A60();
        c->cur[0].sel = 0;
        goto end;
    }
    if (fn_801C09F8(lbl_80347154, 5)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel++;
        if (c->cur[0].sel >= n) c->cur[0].sel = 0;
        goto moved;
    } else if (fn_801C09F8(lbl_80347154, 4)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel--;
        if (c->cur[0].sel < 0) c->cur[0].sel = n - 1;
        goto moved;
    } else if (fn_801C09F8(lbl_80347154, 7)) {
        c->cur[1].x8 = c->cur[1].sel;
        c->cur[1].sel = fn_8019A21C(c->cur[1].mask, 1, c->cur[1].sel, 0, 7);
        goto changedA;
    } else if (fn_801C09F8(lbl_80347154, 6)) {
        c->cur[1].x8 = c->cur[1].sel;
        c->cur[1].sel = fn_8019A21C(c->cur[1].mask, -1, c->cur[1].sel, 0, 7);
        goto changedA;
    } else if (fn_801C09F8(lbl_80347154, 0x10)) {
        c->cur[2].x8 = c->cur[2].sel;
        c->cur[2].sel = fn_8019A21C(c->cur[2].mask, 1, c->cur[2].sel, 0, 7);
        goto changedB;
    } else if (fn_801C09F8(lbl_80347154, 0x11)) {
        c->cur[2].x8 = c->cur[2].sel;
        c->cur[2].sel = fn_8019A21C(c->cur[2].mask, -1, c->cur[2].sel, 0, 7);
        goto changedB;
    } else if (fn_801C09F8(lbl_80347154, 2)) {
        if (fn_801954EC(&list) == 1) {
            fn_801929B8(2);
            return 1;
        }
        fn_801929B8(3);
    } else if (fn_801C09F8(lbl_80347154, 1)) {
        fn_801929B8(5);
        return -1;
    }
    goto end;
moved:
    if (c->cur[0].x8 != c->cur[0].sel) fn_801929B8(0);
    goto end;
changedA:
    if (c->cur[1].x8 != c->cur[1].sel) {
        CampPnl** objs;
        s32 i;
        s32 j;
        fn_801929B8(0);
        c->cur[0].sel = 0;
        c->cur[0].x8 = 0;
        objs = camp_work.pnl;
        i = c->cur[1].x8 + 0x3b;
        objs[i]->win->f74 -= 150.0f;
        objs[i]->win->f74 -= 150.0f;
        j = c->cur[1].sel + 0x3b;
        objs[j]->win->f74 += 150.0f;
        objs[j]->win->f74 += 150.0f;
    }
    goto end;
changedB:
    c->cur[6].mask = 6;
end:
    return 0;
}

void fn_80179388(void) {
    CampCtrl* c;
    s32 i;
    CampCtrl *w = lbl_80307638;

    c = lbl_8034710C->holder->ctrl;
    CampMenuHideAllPanels();
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[lbl_80307638[1].cur[0].sel]))->in->hide = 1;
    for (i = 0; i < *(s8 *)(CWB + 0xc); i++) {
        ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[i]))->in->hide = 1;
    }
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[w[3].cur[0].sel + 0x1f]))->in->hide = 1;
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[0x3a]))->in->hide = 1;
    for (i = 0; i < 6; i++) {
        if (c->cur[1].mask & (1 << i)) {
            ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[0x3b + i]))->in->hide = 1;
        }
    }
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[0x60]))->in->hide = 1;
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[0x62]))->in->hide = 0;
}

void fn_8017BF14(void) {
    s32 i;
    UiObj* o;
    s32 base;

    switch (lbl_80307638[11].cur[2].sel) {
    case 0: base = 0x70; break;
    case 1: base = 0x72; break;
    }
    for (i = 0; i < 2; i++) {
        o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[base + i]))->in->obj;
        UiObjMoveTo(o, 6, 5, -348.0f, (f32)((i + 2) * 64 + 61));
        UiObjSetCommand(o, 10, i);
    }
    switch (lbl_80307638[11].cur[2].sel) {
    case 0: base = 0x74; break;
    case 1: base = 0x75; break;
    }
    o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[base]))->in->obj;
    UiObjMoveTo(o, 6, -1, 668.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 7; i++) {
        o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[0x4f + i]))->in->obj;
        UiObjMoveTo(o, 6, -1, 668.0f, 204.0f);
        UiObjSetCommand(o, 15, 0);
    }
    o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[0x60]))->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_8017C0EC(void) {
    s32 i;
    UiObj* o;
    s32 base;

    switch (lbl_80307638[11].cur[2].sel) {
    case 0: base = 0x70; break;
    case 1: base = 0x72; break;
    }
    for (i = 0; i < 2; i++) {
        o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[base + i]))->in->obj;
        UiObjMoveTo(o, 6, 4, -8.0f, (f32)((i + 2) * 64 + 61));
        UiObjSetCommand(o, 10, i);
    }
    switch (lbl_80307638[11].cur[2].sel) {
    case 0: base = 0x74; break;
    case 1: base = 0x75; break;
    }
    o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[base]))->in->obj;
    UiObjMoveTo(o, 6, 4, 328.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 7; i++) {
        o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[0x4f + i]))->in->obj;
        UiObjMoveTo(o, 6, -1, 328.0f, 204.0f);
        UiObjSetCommand(o, 15, 0);
    }
    o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[0x60]))->in->obj;
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_8017F310(void) {
    UiObj* o;
    s32 i;
    f32 y;
    CampCtrl* c;

    c = lbl_8034710C->holder->ctrl;
    o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[lbl_80307638[1].cur[0].sel]))->in->obj;
    fn_80199BB8(o, -8.0f, 61.0f);
    fn_80199BAC(o, -8.0f, 61.0f);
    for (i = 0; i < 2; i++) {
        if (c->cur[0].mask & (1 << i)) {
            o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[0x78 + i]))->in->obj;
            y = (f32)((i + 1) * 64 + 61);
            fn_80199BB8(o, -348.0f, y);
            fn_80199BAC(o, -348.0f, y);
        }
    }
    o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[0x6c]))->in->obj;
    fn_80199BB8(o, 668.0f, 61.0f);
    fn_80199BAC(o, 668.0f, 61.0f);
    for (i = 0; i < 5; i++) {
        o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[0x7a + i]))->in->obj;
        y = (f32)((i + 1) * 64 + 61);
        fn_80199BB8(o, 668.0f, y);
        fn_80199BAC(o, 668.0f, y);
    }
    for (i = 5; i < 8; i++) {
        o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[0x7a + i]))->in->obj;
        y = (f32)((i - 4) * 64 + 61);
        fn_80199BB8(o, 668.0f, y);
        fn_80199BAC(o, 668.0f, y);
    }
}

void fn_80180694(s8 unused, s8 mode) {
    CampCtrl* c;
    UiObj* p;
    s16 se;
    s32 i;
    UiObj* o;
    f32 bx, by, ax, ay, cx, cy;

    c = lbl_8034710C->holder->ctrl;
    switch (mode) {
    case 0:
        o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[c->cur[2].sel]))->in->obj;
        se = 4;
        bx = 328.0f; by = 204.0f;
        ax = -8.0f; ay = 61.0f;
        cx = 24.0f; cy = 384.0f;
        break;
    case 1:
        o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[c->cur[2].x8]))->in->obj;
        se = 5;
        bx = 668.0f; by = 204.0f;
        ax = -348.0f; ay = 61.0f;
        cx = 632.0f; cy = 480.0f;
        break;
    }
    UiObjFinish(o);
    UiObjMoveTo(o, 6, se, ax, ay);
    UiObjSetCommand(o, 15, 2);
    o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[0x48]))->in->obj;
    UiObjMoveTo(o, 6, se, bx, by);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 6; i++) {
        p = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[0x49 + i]))->in->obj;
        UiObjMoveTo(p, 6, -1, bx, by);
        UiObjSetCommand(p, 15, 0);
    }
    o = &((Pnl_8017BF14 *)((Pnl_8017BF14 *)camp_work.pnl[0x60]))->in->obj;
    UiObjFinish(o);
    UiObjMoveTo(o, 6, se, cx, cy);
    UiObjSetCommand(o, 15, 3);
}

void fn_80180CCC(void) {
    CampCtrl* c;
    s32 i;

    c = lbl_8034710C->holder->ctrl;
    CampMenuHideAllPanels();
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[lbl_80307638[1].cur[0].sel]))->in->hide = 1;
    for (i = 0; i < *(s8 *)(CWB + 0xc); i++) {
        ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[i]))->in->hide = 1;
    }
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[0x21]))->in->hide = 1;
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[0x6a]))->in->hide = 1;
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[0x9b]))->in->hide = 1;
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[0x9c]))->in->hide = 1;
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[0x48]))->in->hide = 1;
    for (i = 0; i < 6; i++) {
        if (c->cur[1].mask & (1 << i)) {
            ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[0x49 + i]))->in->hide = 1;
        }
    }
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[0x60]))->in->hide = 1;
    ((Pnl_80177D7C *)((Pnl_80177D7C *)camp_work.pnl[0x64]))->in->hide = 0;
}

void fn_801887EC(Obj_801887EC *self) {
    Node_801887EC *node = self->node;
    const char *str;
    s16 x, y;
    s32 id;
    UiObj *ui = &node->ui;
    Dst_80189958 *in = node->in;
    if (lbl_803475D8 != 0) {
        self->state = 0xff;
    }
    switch (self->state) {
    case 0xFE:
    case 0:
        self->state = 1;
    case 1:
        fn_80199F38(ui);
        UiObjCalcRect(ui);
        if (self->node->x0 == 1) {
            CampPanelDrawFrame();
            if (in->ok == 1) {
                fn_80188A18(self->node);
            } else {
                switch (in->id) {
                case 1: id = 0x3a; str = (const char *)lbl_802EBB54; break;
                case 0: id = 0x33; str = (const char *)lbl_802EBB48; break;
                case 3: id = 0x41; str = (const char *)lbl_802EBB34; break;
                case 2: id = 0x48; str = (const char *)lbl_802EBB68; break;
                case 4: id = 0x4f; str = (const char *)lbl_802EBB7C; break;
                }
                if (id != self->node->x4) {
                    Pos_801887EC *p = (Pos_801887EC *)((Ent_801887EC *)camp_work.pnl[id])->node;
                    f32 z;
                    x = (s16)p->x;
                    y = (s16)p->y;
                    TextPushColor();
                    TextSetColor(0xff201008);
                    z = TextGetZ();
                    TextSetZ(self->node->pos.f0);
                    TextPrint(x + 0x34, y + 0xc, str);
                    TextSetZ(z);
                    TextPopColor(1);
                }
            }
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xFF:
        fn_80199F58(self->node);
        self->flags |= 0x40;
        break;
    }
}

void fn_80189EA0(Obj_80189EA0 *self) {
    In_80189EA0 *in = self->in;
    s16 x = (s16)self->x;
    s16 y = (s16)self->y;
    f32 z = TextGetZ();
    TextSetZ(10.0f + self->z);
    TextPushColor();
    TextSetColor(0xff201008);
    TextPrint(x + 0x12, y + 0x11, lbl_802E9908[in->id].label[0]);
    switch (fn_80194378(in->id)) {
    case 0:
        TextPushColor();
        TextSetColor(0x40201008);
        TextPrint(x + 0x102, y + 0x11, lbl_802E9908[in->id].label[2]);
        TextPopColor(1);
        TextPrint(x + 0x92, y + 0x11, lbl_802E9908[in->id].label[1]);
        break;
    case 1:
        TextPushColor();
        TextSetColor(0x40201008);
        TextPrint(x + 0x92, y + 0x11, lbl_802E9908[in->id].label[1]);
        TextPopColor(1);
        TextPrint(x + 0x102, y + 0x11, lbl_802E9908[in->id].label[2]);
        break;
    }
    TextPopColor(1);
    TextSetZ(z);
}

extern void fn_80180414(void);
void fn_801802AC(void) {
    CampCtrl* c = lbl_8034710C->holder->ctrl;

    switch (c->state) {
    case 0:
        fn_80180694(c->cur[4].sel, 1);
        c->state++;
        break;
    case 1:
        if (CampMenuAnyPanelBusy() == 0) {
            fn_80180414();
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            fn_80180414();
            c->state++;
        }
        break;
    case 2:
        fn_80180694(c->cur[4].sel, 0);
        c->state++;
        break;
    case 3:
        if (CampMenuAnyPanelBusy() == 0) {
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            c->state++;
        }
        break;
    case 4:
        c->state = 0;
        c->cur[6].mask = 2;
        break;
    }
}

extern void fn_80174E18(void);
void fn_80174CB0(void) {
    CampCtrl* c = lbl_8034710C->holder->ctrl;

    switch (c->state) {
    case 0:
        fn_80174F40((s8)c->cur[4].sel, 1);
        c->state++;
        break;
    case 1:
        if (CampMenuAnyPanelBusy() == 0) {
            fn_80174E18();
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            fn_80174E18();
            c->state++;
        }
        break;
    case 2:
        fn_80174F40((s8)c->cur[4].sel, 0);
        c->state++;
        break;
    case 3:
        if (CampMenuAnyPanelBusy() == 0) {
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            c->state++;
        }
        break;
    case 4:
        c->state = 0;
        c->cur[6].mask = 2;
        break;
    }
}

extern void fn_80178BC8(void);
void fn_80178A60(void) {
    CampCtrl* c = lbl_8034710C->holder->ctrl;

    switch (c->state) {
    case 0:
        fn_80178D2C((s8)c->cur[4].sel, 1);
        c->state++;
        break;
    case 1:
        if (CampMenuAnyPanelBusy() == 0) {
            fn_80178BC8();
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            fn_80178BC8();
            c->state++;
        }
        break;
    case 2:
        fn_80178D2C((s8)c->cur[4].sel, 0);
        c->state++;
        break;
    case 3:
        if (CampMenuAnyPanelBusy() == 0) {
            c->state++;
        } else if (fn_801C09F8(lbl_80347154, 0x11) != 0 || fn_801C09F8(lbl_80347154, 0x10) != 0) {
            CampMenuFinishAllPanels();
            c->state++;
        }
        break;
    case 4:
        c->state = 0;
        c->cur[6].mask = 2;
        break;
    }
}

void fn_80189DBC(Self_8016F138* self) {
    UiObj* obj = &self->inner->obj;

    if (lbl_803475D8 != 0) {
        self->state = 0xff;
    }
    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            CampPanelDrawFrame(self->inner);
            fn_80189EA0((Obj_80189EA0 *)self->inner);
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(self->inner);
        self->flags |= 0x40;
        break;
    }
}

void fn_80172E8C(void)
{
    Leaf* la = ((Elem*)camp_work.pnl[0x82])->mid->leaf;
    UiObj* o;

    o = OBJ(4);
    UiObjSetLowered(o);
    UiObjMoveTo(o, 6, 4, -8.0f, 125.0f);
    UiObjSetCommand(o, 10, 0);
    o = OBJ(0x76);
    UiObjSetLowered(o);
    UiObjMoveTo(o, 6, 4, -8.0f, 189.0f);
    UiObjSetCommand(o, 10, 1);
    o = OBJ(0x77);
    UiObjSetLowered(o);
    UiObjMoveTo(o, 6, 4, -8.0f, 253.0f);
    UiObjSetCommand(o, 10, 2);
    o = OBJ(0x85);
    UiObjSetLowered(o);
    UiObjMoveTo(o, 6, -1, 328.0f, 61.0f);
    UiObjSetCommand(o, 10, 0);
    o = OBJ(0x83);
    UiObjSetLowered(o);
    UiObjMoveTo(o, 6, -1, 328.0f, 119.0f);
    UiObjSetCommand(o, 10, 0);
    if (la->f5c & (1 << lbl_80307638[13].cur[0].sel)) {
        o = OBJ(0x86);
        UiObjSetLowered(o);
        UiObjMoveTo(o, 6, -1, 328.0f, 183.0f);
        UiObjSetCommand(o, 15, 1);
        o = OBJ(0x84);
        UiObjSetLowered(o);
        UiObjMoveTo(o, 6, -1, 328.0f, 241.0f);
        UiObjSetCommand(o, 15, 1);
    }
    o = OBJ(0x60);
    UiObjSetLowered(o);
    UiObjMoveTo(o, 6, 4, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 1);
}

void fn_8017D534(void)
{
    UiObj* o;
    s32 i;
    s32 a;
    s32 b;
    s32 d;
    CampCtrl* c;

    c = lbl_8034710C->holder->ctrl;
    o = OBJ(4);
    UiObjMoveTo(o, 6, -1, -8.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    o = OBJ(0x78 + lbl_80307638[4].cur[0].sel);
    UiObjMoveTo(o, 6, -1, -8.0f, 125.0f);
    UiObjSetCommand(o, 15, 1);
    o = OBJ(0x6e);
    UiObjMoveTo(o, 6, -1, -8.0f, 189.0f);
    UiObjSetCommand(o, 10, 2);
    o = OBJ(0x6f);
    UiObjMoveTo(o, 6, -1, -8.0f, 253.0f);
    UiObjSetCommand(o, 10, 3);
    switch (c->cur[2].sel) {
    case 0:
        a = 0x7a;
        b = 5;
        d = 0;
        break;
    case 1:
        a = 0x7f;
        b = 3;
        d = 0;
        break;
    }
    for (i = 0; i < b; i++) {
        o = OBJ(a + i);
        UiObjMoveTo(o, 6, 4, 328.0f, (d + i) * 64 + 61);
        if (i == c->cur[0].sel) {
            UiObjSetCommand(o, 10, i + d);
        } else {
            UiObjSetCommand(o, 15, i + d);
        }
        ND(a + i)->y += 150.0f;
    }
    o = OBJ(0x60);
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_8017DA28(void)
{
    UiObj* o;
    s32 i;
    s32 a;
    s32 b;
    s32 d;
    CampCtrl* c;

    c = lbl_8034710C->holder->ctrl;
    o = OBJ(4);
    UiObjMoveTo(o, 6, -1, -8.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    o = OBJ(0x78 + lbl_80307638[4].cur[0].sel);
    UiObjMoveTo(o, 6, -1, -8.0f, 125.0f);
    UiObjSetCommand(o, 10, 1);
    o = OBJ(0x6e);
    UiObjMoveTo(o, 6, -1, -8.0f, 189.0f);
    UiObjSetCommand(o, 10, 2);
    o = OBJ(0x6f);
    UiObjMoveTo(o, 6, -1, -8.0f, 253.0f);
    UiObjSetCommand(o, 10, 3);
    switch (c->cur[2].sel) {
    case 0:
        a = 0x7a;
        b = 5;
        d = 0;
        break;
    case 1:
        a = 0x7f;
        b = 3;
        d = 0;
        break;
    }
    for (i = 0; i < b; i++) {
        o = OBJ(a + i);
        UiObjMoveTo(o, 6, 4, 328.0f, (d + i) * 64 + 61);
        if (i == c->cur[0].sel) {
            UiObjSetCommand(o, 10, i + d);
        } else {
            UiObjSetCommand(o, 15, i + d);
        }
        ND(a + i)->y += 150.0f;
    }
    o = OBJ(0x60);
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 0);
}

s32 fn_8017E260(void)
{
    CampCtrl* c;
    s32 r;
    s32 n;

    c = lbl_8034710C->holder->ctrl;
    switch (CW(0x304, u32)) {
    case 0:
        fn_8017EAEC();
        fn_8017F540();
        fn_8017F310();
        fn_8017F07C();
        CW(0x304, s32) = 2;
        break;
    case 2:
        if (!CampMenuAnyPanelBusy()) {
            CW(0x304, s32) = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            CW(0x304, s32) = 3;
        }
        break;
    case 3:
        r = fn_8017E5FC();
        fn_8017E4E4();
        switch (r) {
        case -1:
            CW(0x304, s32) = 0x18;
            break;
        case 0:
            break;
        case 1:
            CW(0x304, s32) = 0xc;
            break;
        }
        break;
    case 12:
        fn_8017EBD8();
        CW(0x304, s32) = 0x12;
        break;
    case 18:
        switch (c->cur[0].sel) {
        case 0:
            n = 0xb;
            break;
        case 1:
            n = 0xb;
            break;
        case 2:
            n = 0xb;
            break;
        default:
            n = 0xb;
            break;
        }
        if (!CampMenuAnyPanelBusy()) {
            camp_screen = n;
            ((s32*)((u8*)&camp_work + 0x2f4))[n] = 0;
            fn_801959D4(n);
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            camp_screen = n;
            ((s32*)((u8*)&camp_work + 0x2f4))[n] = 0;
            fn_801959D4(n);
        }
        break;
    case 24:
        fn_8017EE48();
        CW(0x304, s32) = 0x13;
        break;
    case 19:
        if (!CampMenuAnyPanelBusy()) {
            CW(0x2f8, s32) = 0;
            camp_screen = 1;
            fn_801959D4(1);
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            CW(0x2f8, s32) = 0;
            camp_screen = 1;
            fn_801959D4(1);
        }
        break;
    }
    return 0;
}

void fn_8017F07C(void)
{
    UiObj* o;
    s32 i;
    s32 a;
    s32 b;
    s32 d;
    CampCtrl* c;

    c = lbl_8034710C->holder->ctrl;
    o = OBJ(4);
    UiObjMoveTo(o, 6, -1, -8.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    for (i = 0; i < 2; i++) {
        if (c->cur[0].mask & (1 << i)) {
            o = OBJ(0x78 + i);
            UiObjMoveTo(o, 6, -1, -8.0f, (i + 1) * 64 + 61);
            if (c->cur[0].sel == i) {
                UiObjSetCommand(o, 10, i + 1);
            } else {
                UiObjSetCommand(o, 15, i + 4);
            }
        }
    }
    o = OBJ(0x6c);
    UiObjMoveTo(o, 6, -1, 328.0f, 61.0f);
    UiObjSetCommand(o, 15, 0);
    switch (c->cur[2].sel) {
    case 0:
        a = 0x7a;
        b = 5;
        d = 1;
        break;
    case 1:
        a = 0x7f;
        b = 3;
        d = 1;
        break;
    }
    for (i = 0; i < b; i++) {
        o = OBJ(a + i);
        UiObjSetLowered(o);
        UiObjMoveTo(o, 6, 4, 328.0f, (d + i) * 64 + 61);
        UiObjSetCommand(o, 15, i + d);
        ND(a + i)->y += 150.0f;
    }
    o = OBJ(0x60);
    UiObjMoveTo(o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(o, 15, 0);
}

s32 fn_8018394C(void)
{
    s32 r;

    switch (CW(0x2f8, u32)) {
    case 0:
        fn_80184CE8();
        fn_80184A78();
        fn_801847F0();
        fn_801841DC();
        fn_80184E2C();
        CW(0x2f8, s32) = 2;
        break;
    case 2:
        if (!CampMenuAnyPanelBusy()) {
            CW(0x2f8, s32) = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            CW(0x2f8, s32) = 3;
        }
        break;
    case 3:
        r = fn_80183D90();
        fn_80183C54();
        switch (r) {
        case -1:
            CW(0x2f8, s32) = 0x18;
            break;
        case 0:
            break;
        case 1:
            CW(0x2f8, s32) = 0xc;
            break;
        }
        break;
    case 12:
        fn_80184558();
        CW(0x2f8, s32) = 0x12;
        break;
    case 18:
        if (!CampMenuAnyPanelBusy()) {
            switch (lbl_8034710C->holder->ctrl->cur[0].sel) {
            case 4:
                CW(0x320, s32) = 0;
                camp_screen = 0xb;
                fn_801959D4(0xb);
                break;
            case 5:
                CW(0x2fc, s32) = 0;
                camp_screen = 2;
                fn_801959D4(2);
                break;
            default:
                CW(0x300, s32) = 0;
                camp_screen = 3;
                fn_801959D4(3);
                break;
            }
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            switch (lbl_8034710C->holder->ctrl->cur[0].sel) {
            case 4:
                CW(0x320, s32) = 0;
                camp_screen = 0xb;
                fn_801959D4(0xb);
                break;
            case 5:
                CW(0x2fc, s32) = 0;
                camp_screen = 2;
                fn_801959D4(2);
                break;
            default:
                CW(0x300, s32) = 0;
                camp_screen = 3;
                fn_801959D4(3);
                break;
            }
        }
        break;
    case 24:
        fn_80184330();
        CW(0x2f8, s32) = 0x13;
        break;
    case 19:
        if (!CampMenuAnyPanelBusy()) {
            camp_screen = 0;
            CW(0x2f4, s32) = 0;
            fn_801959D4(0);
        } else if (fn_801C09F8(lbl_80347154, 2) || fn_801C09F8(lbl_80347154, 1)) {
            CampMenuFinishAllPanels();
            camp_screen = 0;
            CW(0x2f4, s32) = 0;
            fn_801959D4(0);
        }
        break;
    }
    return 0;
}

void fn_80184558(void)
{
    CampCtrl* c;
    s32 i;
    UiObj* o;

    c = lbl_8034710C->holder->ctrl;
    for (i = 0; i < *(s8*)((u8*)&camp_work + 0xc); i++) {
        o = OBJ(i);
        if (i == c->cur[0].sel) {
            UiObjMoveTo(o, 6, 4, -8.0f, 61.0f);
            UiObjSetCommand(o, 15, i);
        } else {
            UiObjMoveTo(o, 6, 5, -348.0f, i * 64 + 61);
            UiObjSetCommand(o, 15, i);
        }
    }
    if (fn_801953B8()) {
        o = OBJ(4);
        if (c->cur[0].sel == 4) {
            UiObjMoveTo(o, 6, 4, -8.0f, 61.0f);
            UiObjSetCommand(o, 15, 4);
        } else {
            UiObjMoveTo(o, 6, 5, -348.0f, 317.0f);
            UiObjSetCommand(o, 15, 4);
        }
        o = OBJ(0x6c + c->cur[1].sel);
        UiObjMoveTo(o, 6, 5, 668.0f, 317.0f);
        UiObjSetCommand(o, 15, 4);
    }
    for (i = 0; i < *(s8*)((u8*)&camp_work + 0xc); i++) {
        o = OBJ(c->cur[4].sel + (i * 5 + 6));
        UiObjMoveTo(o, 6, -1, 668.0f, i * 64 + 61);
        UiObjSetCommand(o, 15, i);
    }
    if (fn_80194CB8() == 1) {
        o = OBJ(5);
        UiObjMoveTo(o, 6, 5, -348.0f, 381.0f);
        UiObjSetCommand(o, 15, 6);
    }
}
s16 fn_801838C8(s32 kind, s32 idx) {
    SaveChar* c = &lbl_8030B7F4.chr[idx];
    StatRec* s = &lbl_8030B4D4.chr[idx];
    s16 r = 0;
    switch (kind) {
    case 0x36: r = s->x48[0]; break;
    case 0x37: r = s->x48[1]; break;
    case 0x38: r = s->x48[2]; break;
    case 0x39: r = s->x48[3]; break;
    case 0x3a: r = s->x48[4]; break;
    case 0x3b: r = c->hpMax; break;
    case 0x3c: r = c->mpMax; break;
    }
    return r;
}

s32 fn_80173688(void) {
    CampCtrl* c = lbl_8034710C->holder->ctrl;

    ((Pnl_80173688*)camp_work.pnl[0x66])->in->hide = 1;
    if (fn_801C09F8(lbl_80347154, 5)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = fn_8019A21C(c->cur[0].mask, 1, c->cur[0].sel, 0, 0x18);
    } else if (fn_801C09F8(lbl_80347154, 4)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = fn_8019A21C(c->cur[0].mask, -1, c->cur[0].sel, 0, 0x18);
    } else if (fn_801C09F8(lbl_80347154, 2)) {
        fn_801929B8(2);
        return 1;
    } else if (fn_801C09F8(lbl_80347154, 1)) {
        fn_801929B8(5);
        return -1;
    } else {
        goto end;
    }
    fn_801929B8(0);
end:
    return 0;
}

void fn_801752F4(void) {
    s32 i;
    UiObj* o;

    for (i = 0; i < 3; i++) {
        o = &(*(CampWork_80184F8C*)&camp_work).pnl[0x5a + i]->in->obj;
        UiObjMoveTo(o, 6, 5, 668.0f, 61 + i * 88);
        UiObjSetCommand(o, 15, i);
    }
    o = &(*(CampWork_80184F8C*)&camp_work).pnl[0x60]->in->obj;
    UiObjMoveTo(o, 6, -1, 632.0f, 480.0f);
    UiObjSetCommand(o, 15, 0);
}

void fn_8017F540(void) {
    CampCtrl* c;
    s32 i;
    UiObj* o;

    c = lbl_8034710C->holder->ctrl;
    CampMenuHideAllPanels();
    (*(CampWork_80184F8C*)&camp_work).pnl[4]->in->hide = 1;
    for (i = 0; i < 2; i++) {
        if (c->cur[0].mask & (1 << i)) {
            (*(CampWork_80184F8C*)&camp_work).pnl[0x78 + i]->in->hide = 1;
        }
    }
    (*(CampWork_80184F8C*)&camp_work).pnl[0x6c]->in->hide = 1;
    for (i = 0; i < 8; i++) {
        (*(CampWork_80184F8C*)&camp_work).pnl[0x7a + i]->in->hide = 1;
        o = &(*(CampWork_80184F8C*)&camp_work).pnl[0x7a + i]->in->obj;
        fn_80199BA4(o, 0);
        fn_80199B9C(o, 1.0f);
    }
}

void fn_80184E2C(void) {
    Sprite* s;
    Pnl_80184E2C* p;
    s32 i;
    s32 who;

    for (i = 0; i < (*(CampWork_80184E2C*)&camp_work).count; i++) {
        p = (*(CampWork_80184E2C*)&camp_work).pnl[i * 5 + 8];
        who = lbl_8030B7F4.party[i];
        switch (who) {
        case 0:
            s = fn_801D68C4(lbl_803470F0, 0x2b);
            break;
        case 1:
            s = fn_801D68C4(lbl_803470F0, 0x2c);
            break;
        case 2:
            s = fn_801D68C4(lbl_803470F0, 0x2d);
            break;
        case 3:
            s = fn_801D68C4(lbl_803470F0, 0x2e);
            break;
        case 4:
            s = fn_801D68C4(lbl_803470F0, 0x2f);
            break;
        case 5:
            s = fn_801D68C4(lbl_803470F0, 0x30);
            break;
        default:
            s = fn_801D68C4(lbl_803470F0, 0x2b);
            break;
        }
        fn_8019520C(who, (void *)(s));
        p->in->icon->spr = s;
    }
}

void fn_80186BE4(s16 x, s16 y, Slots* slots) {
    s32 i;
    s32 j;
    s16 tx;
    s16 ty;

    for (i = 0; i < 11; i++) {
        if (fn_80194C7C(slots, i, 0)) {
            TextPushColor();
            TextSetColor(0xff201008);
            TextPrint(x + 0x24, y + 0x1e + i * 0x18, lbl_802E98A0[i]);
        } else {
            TextPushColor();
            TextSetColor(0x40201008);
            TextPrint(x + 0x24, y + 0x1e + i * 0x18, lbl_803467B0);
        }
        for (j = 0; j < 2; j++) {
            if (j == 0) {
                tx = x + 0x9e;
                ty = y + 0x1e + i * 0x18;
            } else {
                tx = x + 0x146;
                ty = y + 0x1e + i * 0x18;
            }
            if (fn_80194C7C(slots, i, j)) {
                TextPrint(tx, ty, fn_80194C50(slots[i].v[j]));
            } else {
                TextPrint(tx, ty, lbl_803467B0);
            }
        }
        TextPopColor(1);
    }
}

void fn_801918C4(Inner_801918C4* in) {
    s16 x;
    s16 y;
    Info_801918C4* info;
    f32 z;

    x = in->obj.rect[0];
    y = in->obj.rect[1];
    info = (*(CampWork_801918C4*)&camp_work).info;
    z = TextGetZ();
    TextSetZ(10.0f + in->z);
    TextPushColor();
    TextSetColor(0xff201008);
    TextPrint(x + 0x56, y + 6, info->name);
    TextPrintf(x + 0x56, y + 0x1e, "Hp");
    TextPrintf(x + 0x6e, y + 0x1e, "%6d", info->hp);
    TextPrintf(x + 0xb6, y + 0x1e, "/");
    TextPrintf(x + 0xc2, y + 0x1e, "%6d", fn_80194028());
    TextPopColor(1);
    TextSetZ(z);
}

void fn_801729D0(void) {
    CampCtrl* c;
    CampCtrl *tb;
    La_801729D0* la;
    CampCtrl* c2;

    c = lbl_8034710C->holder->ctrl;
    tb = lbl_80307638;
    la = LA(0x82);
    c->cur[0].mask = 0;
    if (la->f5c & (1 << tb[13].cur[0].sel)) {
        c->cur[0].mask = 3;
    } else {
        c->cur[0].mask = 1;
    }
    c->cur[0].sel = 0;
    c->cur[0].x8 = 0;
    c->cur[4].mask = la->f58;
    c->cur[4].sel = tb[13].cur[0].sel;
    fn_80195A68(c, 1, 0, 0, 0, 1);
    c2 = lbl_8034710C->holder->ctrl;
    {
        La_801729D0* t = LA(0x85);
        t->f10 = fn_80194A8C(c2->cur[4].sel);
    }
    {
        La_801729D0* t = LA(0x83);
        t->f8 = fn_80194A8C(c2->cur[4].sel);
    }
    {
        La_801729D0* t = LA(0x86);
        t->f10 = fn_80194A18(c2->cur[4].sel);
    }
    {
        La_801729D0* t = LA(0x84);
        t->f8 = fn_80194A18(c2->cur[4].sel);
    }
    fn_801954D0(fn_80194C38(LA(0x85 + (s8)c->cur[0].sel)->f10));
}

void fn_80191E94(Obj_80191E94 *o) {
    switch (o->kind) {
    case 0:
    case 1:
        break;
    case 0xfe:
        break;
    case 0xff:
        o->flags |= 0x40;
        break;
    }
}

/* Slides four camp-menu panels to their places over 6 frames and starts their command 0xf. */
void fn_801763B8(void)
{
    UiObj* obj;
    s32 i;

    obj = OBJ_801763B8(0x5d);
    UiObjMoveTo(obj, 6, 4, 328.0f, 61.0f);
    UiObjSetCommand(obj, 0xf, 0);
    obj = OBJ_801763B8(0x41);
    UiObjMoveTo(obj, 6, 4, 328.0f, 204.0f);
    UiObjSetCommand(obj, 0xf, 1);
    i = lbl_80307638[8].cur[0].sel + 0x43;
    obj = OBJ_801763B8(i);
    UiObjMoveTo(obj, 6, -1, 328.0f, 204.0f);
    UiObjSetCommand(obj, 0xf, 1);
    obj = OBJ_801763B8(0x60);
    UiObjMoveTo(obj, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(obj, 0xf, 0);
}

f32 fn_8018E73C(Sub_8018DFC4 *s)
{
    f32 w;
    s16 x = s->x;
    s16 y = s->y;
    Kind_8018E73C *k = s->k;
    Arg_800C2650 a;

    a.f0 = -4090.0f;
    a.h4 = x;
    a.h6 = y;
    a.f8 = 1.0f;
    a.fc = 1.0f;
    switch (k->kind) {
    case 0:
        w = fn_800C2A88(&a);
        break;
    case 1:
        w = fn_800C287C(&a);
        break;
    case 2:
        w = fn_800C285C(&a);
        break;
    case 3:
        w = fn_800C2650(&a);
        break;
    }
    return w;
}

void fn_80189214(s8* kind, IconObj_80189214* o, s8 idx, f32 scale) {
    void* a;
    void* b;

    o->x = -4000.0f;
    o->y = 0.0f;
    o->f10 = 1.0f;
    o->scale = scale;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->f08 = 0;
    o->f0c = 0;
    switch (*kind) {
    case 1:
        switch (idx) {
        case 0:
            a = fn_801D68C4(lbl_803470F0, 0x21);
            b = fn_801D68C4(lbl_803470F0, 0x34);
            break;
        case 1:
            a = fn_801D68C4(lbl_803470F0, 0x22);
            b = fn_801D68C4(lbl_803470F0, 0x35);
            break;
        case 2:
            a = fn_801D68C4(lbl_803470F0, 0x23);
            b = fn_801D68C4(lbl_803470F0, 0x37);
            break;
        case 3:
            a = fn_801D68C4(lbl_803470F0, 0x24);
            b = fn_801D68C4(lbl_803470F0, 0x36);
            break;
        case 4:
            a = fn_801D68C4(lbl_803470F0, 0x25);
            b = fn_801D68C4(lbl_803470F0, 0x38);
            break;
        case 5:
            a = fn_801D68C4(lbl_803470F0, 0x26);
            b = fn_801D68C4(lbl_803470F0, 0x39);
            break;
        default:
            a = fn_801D68C4(lbl_803470F0, 0x21);
            b = fn_801D68C4(lbl_803470F0, 0x34);
            break;
        }
        break;
    case 0:
        switch (idx) {
        case 0:
            a = fn_801D68C4(lbl_803470F0, 0x21);
            b = fn_801D68C4(lbl_803470F0, 0x32);
            break;
        case 1:
            a = fn_801D68C4(lbl_803470F0, 0x22);
            b = fn_801D68C4(lbl_803470F0, 0x5d);
            break;
        case 2:
            a = fn_801D68C4(lbl_803470F0, 0x23);
            b = fn_801D68C4(lbl_803470F0, 0x31);
            break;
        case 3:
            a = fn_801D68C4(lbl_803470F0, 0x24);
            b = fn_801D68C4(lbl_803470F0, 0x33);
            break;
        case 4:
            a = fn_801D68C4(lbl_803470F0, 0x25);
            b = fn_801D68C4(lbl_803470F0, 0x41);
            break;
        case 5:
            a = fn_801D68C4(lbl_803470F0, 0x26);
            b = fn_801D68C4(lbl_803470F0, 0x3c);
            break;
        default:
            a = fn_801D68C4(lbl_803470F0, 0x21);
            b = fn_801D68C4(lbl_803470F0, 0x32);
            break;
        }
        break;
    }
    fn_8019A15C(o, 2, 0, 0);
    o->spr20[0] = a;
    o->pos24->a = 0.0f;
    o->pos24->b = -26.0f;
    o->spr20[1] = b;
    o->pos24->c = (f32)(idx * 0x30 + 0x14);
    o->pos24->d = -26.0f;
    o->f44 = 0;
}

void fn_80191A04(Pos_80191A04* p, s32 kind) {
    p->f0 = -6190.0f;
    p->f4 = 0.0f;
    p->f10 = 1.0f;
    p->f14 = 0.0f;
    p->f18 = 1.0f;
    p->f1c = 0.0f;
    p->i8 = 0;
    p->ic = 0;
    fn_8019A15C(p, 1, 1, 1);
    switch (kind) {
    case 1:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x58), 6, 0x1e, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 4);
        break;
    case 2:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 4), 8, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 4);
        break;
    case 3:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x58), 6, 0x1e, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 1);
        break;
    case 4:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 4), 8, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 1);
        break;
    case 15:
    case 16:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 4), 8, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 4);
        break;
    case 5:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x3b), 6, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 4);
        break;
    case 6:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x3b), 6, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 1);
        break;
    case 7:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x3b), 0x12, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 1);
        break;
    case 8:
    case 13:
    case 14:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 4), 6, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 1);
        break;
    case 9:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x3b), 6, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 4);
        break;
    case 10:
        fn_80199FFC(p, 0, fn_801D68C4(lbl_803470F4, 0x3b), 6, 6, 2);
        p->spr44 = fn_801D68C4(lbl_803470F0, 4);
        break;
    }
    p->sp->spr = fn_801D68C4(lbl_803470E8, 2);
    p->fp[0] = 0.0f;
    p->fp[1] = 0.0f;
    p->sp20->spr = fn_801D68C4(lbl_803470F0, 10);
    p->fp24[0] = 0.0f;
    p->fp24[1] = 0.0f;
}

s32 fn_801732C8(void) {
    UiObj *o;
    UiObj *p;

    switch (CW_801732C8(0x328, u32)) {
    case 0:
        CampMenuHideAllPanels();
        IN(0x1b)->kind = 1;
        IN(0x1b)->y74 = -7990.0f;
        IN(0x82)->kind = 1;
        IN(0x66)->kind = 0;
        o = &IN(0x82)->obj;
        fn_80199BB8(o, -496.0f, 124.0f);
        fn_80199BAC(o, -496.0f, 124.0f);
        o = &IN(0x66)->obj;
        fn_80199BB8(o, 0.0f, 124.0f);
        fn_80199BAC(o, 0.0f, 124.0f);
        p = &IN(0x82)->obj;
        UiObjMoveTo(p, 6, 4, 0.0f, 124.0f);
        UiObjSetCommand(p, 0xf, 0);
        fn_8017379C();
        CW_801732C8(0x328, s32) = 2;
        break;
    case 2:
        if (CampMenuAnyPanelBusy() == 0) {
            CW_801732C8(0x328, s32) = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            CW_801732C8(0x328, s32) = 3;
        }
        break;
    case 3:
        switch (fn_80173688()) {
        case -1:
            CW_801732C8(0x328, s32) = 0x18;
            IN(0x66)->kind = 0;
            break;
        case 1:
            CW_801732C8(0x328, s32) = 0xc;
            IN(0x66)->kind = 0;
            break;
        }
        break;
    case 12:
        p = &IN(0x82)->obj;
        UiObjMoveTo(p, 6, 4, -496.0f, 124.0f);
        UiObjSetCommand(p, 0xf, 0);
        CW_801732C8(0x328, s32) = 0x12;
        break;
    case 18:
        if (CampMenuAnyPanelBusy() == 0) {
            CW_801732C8(0x32c, s32) = 0;
            camp_screen = 0xe;
            fn_801959D4(0xe);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            CW_801732C8(0x32c, s32) = 0;
            camp_screen = 0xe;
            fn_801959D4(0xe);
        }
        break;
    case 24:
        p = &IN(0x1b)->obj;
        UiObjMoveTo(p, 6, 4, -348.0f, 61.0f);
        UiObjSetCommand(p, 0xf, 1);
        p = &IN(0x82)->obj;
        UiObjMoveTo(p, 6, 4, -496.0f, 124.0f);
        UiObjSetCommand(p, 0xf, 0);
        CW_801732C8(0x328, s32) = 0x13;
        break;
    case 19:
        if (CampMenuAnyPanelBusy() == 0) {
            CW_801732C8(0x2fc, s32) = 0;
            camp_screen = 2;
            fn_801959D4(2);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            CW_801732C8(0x2fc, s32) = 0;
            camp_screen = 2;
            fn_801959D4(2);
        }
        break;
    }
    return 0;
}

s32 fn_80176D70(void) {
    CampCtrl *c = lbl_8034710C->holder->ctrl;
    CampWork *w = &camp_work;
    UiObj *o;
    UiObj *p;
    s32 r;

    switch (CW_80176D70(0x310, u32)) {
    case 0:
        fn_80177EFC();
        fn_80177D7C();
        fn_80177C98();
        fn_80177AC8();
        CW_80176D70(0x310, s32) = 2;
        break;
    case 1:
        fn_80177D7C();
        IN_80176D70(0x61)->kind = 1;
        fn_80177BD4();
        o = &IN_80176D70(lbl_80307638[1].cur[0].sel)->obj;
        UiObjMoveTo(o, 6, 4, -8.0f, 61.0f);
        UiObjSetCommand(o, 0xf, 0);
        o = &IN_80176D70(lbl_80307638[3].cur[0].sel + 0x1f)->obj;
        UiObjMoveTo(o, 6, 4, -8.0f, 125.0f);
        UiObjSetCommand(o, 0xf, 1);
        c->cur[6].mask = 1;
        fn_80195A68(c, 1, 0, 0, 0, 1);
        CW_80176D70(0x310, s32) = 2;
        break;
    case 2:
        if (CampMenuAnyPanelBusy() == 0) {
            CW_80176D70(0x310, s32) = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            CW_80176D70(0x310, s32) = 3;
        }
        break;
    case 3:
        r = fn_80177348();
        fn_80177134();
        switch (r) {
        case -1:
            CW_80176D70(0x310, s32) = 0x18;
            break;
        case 1:
            CW_80176D70(0x310, s32) = 0xc;
            break;
        }
        break;
    case 12:
        o = &IN_80176D70(lbl_80307638[1].cur[0].sel)->obj;
        UiObjMoveTo(o, 6, 5, -348.0f, 61.0f);
        UiObjSetCommand(o, 0xf, 0);
        p = &IN_80176D70(lbl_80307638[3].cur[0].sel + 0x1f)->obj;
        UiObjMoveTo(p, 6, 5, -348.0f, 125.0f);
        UiObjSetCommand(p, 0xf, 1);
        CW_80176D70(0x310, s32) = 0x12;
        break;
    case 18:
        if (CampMenuAnyPanelBusy() == 0) {
            CG(0x30c, s32) = 0;
            camp_screen = 6;
            fn_801959D4(6);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            CG(0x30c, s32) = 0;
            camp_screen = 6;
            fn_801959D4(6);
        }
        break;
    case 24:
        fn_8017796C();
        CW_80176D70(0x310, s32) = 0x13;
        break;
    case 19:
        if (CampMenuAnyPanelBusy() == 0) {
            CG(0x300, s32) = 0;
            camp_screen = 3;
            fn_801959D4(3);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            CG(0x300, s32) = 0;
            camp_screen = 3;
            fn_801959D4(3);
        }
        break;
    }
    return 0;
}

void fn_8018B278(Self_8018C00C *self, f32 a, s8 kind, s8 mode)
{
    Obj48 *o = &self->panel;
    s8 *d = self->data;
    void *spr2;
    void *spA;
    void *spB;

    o->f00 = -6940.0f + 150.0f * (f32)d[1];
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = a;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    switch (kind) {
    case 0:
        switch (mode) {
        case 0:
            fn_8019A15C(o, 1, 8, 1);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x1b), 0x1c, 0x6, 2);
            fn_80199FFC(o, 1, fn_801D68C4(lbl_803470F4, 0x28), 0x34, 0xa, 2);
            fn_80199FFC(o, 2, fn_801D68C4(lbl_803470F4, 0x1c), 0xa0, 0x6, 2);
            fn_80199FFC(o, 3, fn_801D68C4(lbl_803470F4, 0x29), 0xb8, 0xa, 2);
            fn_80199FFC(o, 4, fn_801D68C4(lbl_803470F4, 0x19), 0x1c, 0x1e, 2);
            fn_80199FFC(o, 5, fn_801D68C4(lbl_803470F4, 0x26), 0x34, 0x22, 2);
            fn_80199FFC(o, 6, fn_801D68C4(lbl_803470F4, 0x55), 0xa0, 0x1e, 2);
            fn_80199FFC(o, 7, fn_801D68C4(lbl_803470F4, 0x4), 0x8, 0x6, 2);
            break;
        case 1:
            fn_8019A15C(o, 1, 7, 1);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x17), 0x1c, 0x6, 2);
            fn_80199FFC(o, 1, fn_801D68C4(lbl_803470F4, 0x24), 0x34, 0xa, 2);
            fn_80199FFC(o, 2, fn_801D68C4(lbl_803470F4, 0x18), 0xa0, 0x6, 2);
            fn_80199FFC(o, 3, fn_801D68C4(lbl_803470F4, 0x25), 0xb8, 0xa, 2);
            fn_80199FFC(o, 4, fn_801D68C4(lbl_803470F4, 0x12), 0x1c, 0x1e, 2);
            fn_80199FFC(o, 5, fn_801D68C4(lbl_803470F4, 0x1f), 0x34, 0x22, 2);
            fn_80199FFC(o, 6, fn_801D68C4(lbl_803470F4, 0x4), 0x8, 0x6, 2);
            break;
        case 2:
            fn_8019A15C(o, 1, 5, 1);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x1a), 0x1c, 0x6, 2);
            fn_80199FFC(o, 1, fn_801D68C4(lbl_803470F4, 0x27), 0x34, 0xa, 2);
            fn_80199FFC(o, 2, fn_801D68C4(lbl_803470F4, 0x16), 0x1c, 0x1e, 2);
            fn_80199FFC(o, 3, fn_801D68C4(lbl_803470F4, 0x23), 0x34, 0x22, 2);
            fn_80199FFC(o, 4, fn_801D68C4(lbl_803470F4, 0x4), 0x8, 0x6, 2);
            break;
        case 3:
            fn_8019A15C(o, 1, 1, 1);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x36), 0xc, 0x1f, 2);
            break;
        }
        break;
    case 1:
        switch (mode) {
        case 0:
            fn_8019A15C(o, 3, 1, 1);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
            switch (d[3]) {
            case 0:
                spr2 = fn_801D68C4(lbl_803470F0, 0x2b);
                break;
            case 1:
                spr2 = fn_801D68C4(lbl_803470F0, 0x2c);
                break;
            case 2:
                spr2 = fn_801D68C4(lbl_803470F0, 0x2d);
                break;
            case 3:
                spr2 = fn_801D68C4(lbl_803470F0, 0x2e);
                break;
            case 4:
                spr2 = fn_801D68C4(lbl_803470F0, 0x2f);
                break;
            case 5:
                spr2 = fn_801D68C4(lbl_803470F0, 0x30);
                break;
            }
            fn_8019520C(d[3], spr2);
            fn_80199FFC(o, 1, spr2, 0x1c, 6, 0);
            fn_80199FFC(o, 2, fn_801D68C4(lbl_803470F0, 0x31), 0x1c, 0x1e, 0);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x38), 0x12, 0x6, 2);
            break;
        case 1:
            fn_8019A15C(o, 2, 1, 1);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
            fn_80199FFC(o, 1, fn_801D68C4(lbl_803470F0, 0x33), 0x1c, 0x6, 0);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x38), 0x12, 0x6, 2);
            break;
        case 2:
            fn_8019A15C(o, 1, 9, 1);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x10), 0x1c, 0x6, 2);
            fn_80199FFC(o, 1, fn_801D68C4(lbl_803470F4, 0x1d), 0x34, 0xa, 2);
            fn_80199FFC(o, 2, fn_801D68C4(lbl_803470F4, 0x11), 0xa0, 0x6, 2);
            fn_80199FFC(o, 3, fn_801D68C4(lbl_803470F4, 0x1e), 0xb8, 0xa, 2);
            fn_80199FFC(o, 4, fn_801D68C4(lbl_803470F4, 0x12), 0x1c, 0x1e, 2);
            fn_80199FFC(o, 5, fn_801D68C4(lbl_803470F4, 0x1f), 0x34, 0x22, 2);
            fn_80199FFC(o, 6, fn_801D68C4(lbl_803470F4, 0x13), 0xa0, 0x1e, 2);
            fn_80199FFC(o, 7, fn_801D68C4(lbl_803470F4, 0x20), 0xb8, 0x22, 2);
            fn_80199FFC(o, 8, fn_801D68C4(lbl_803470F4, 0x4), 0x8, 0x6, 2);
            break;
        case 3:
            fn_8019A15C(o, 1, 7, 1);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x14), 0x1c, 0x6, 2);
            fn_80199FFC(o, 1, fn_801D68C4(lbl_803470F4, 0x21), 0x34, 0xa, 2);
            fn_80199FFC(o, 2, fn_801D68C4(lbl_803470F4, 0x15), 0xa0, 0x6, 2);
            fn_80199FFC(o, 3, fn_801D68C4(lbl_803470F4, 0x22), 0xb8, 0xa, 2);
            fn_80199FFC(o, 4, fn_801D68C4(lbl_803470F4, 0x16), 0x1c, 0x1e, 2);
            fn_80199FFC(o, 5, fn_801D68C4(lbl_803470F4, 0x23), 0x34, 0x22, 2);
            fn_80199FFC(o, 6, fn_801D68C4(lbl_803470F4, 0x4), 0x8, 0x6, 2);
            break;
        case 4:
            fn_8019A15C(o, 1, 1, 1);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
            fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x36), 0xc, 0x1f, 2);
            break;
        }
        break;
    case 2:
        switch (mode) {
        case 0:
            spA = fn_801D68C4(lbl_803470F0, 0x34);
            spB = fn_801D68C4(lbl_803470F4, 0x2b);
            break;
        case 1:
            spA = fn_801D68C4(lbl_803470F0, 0x35);
            spB = fn_801D68C4(lbl_803470F4, 0x2c);
            break;
        case 2:
            spA = fn_801D68C4(lbl_803470F0, 0x37);
            spB = fn_801D68C4(lbl_803470F4, 0x2e);
            break;
        case 3:
            spA = fn_801D68C4(lbl_803470F0, 0x36);
            spB = fn_801D68C4(lbl_803470F4, 0x2d);
            break;
        case 4:
            spA = fn_801D68C4(lbl_803470F0, 0x38);
            spB = fn_801D68C4(lbl_803470F4, 0x2f);
            break;
        case 5:
            spA = fn_801D68C4(lbl_803470F0, 0x39);
            spB = fn_801D68C4(lbl_803470F4, 0x30);
            break;
        }
        fn_8019A15C(o, 2, 5, 1);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
        fn_80199FFC(o, 1, spA, 0xc, 6, 0);
        fn_80199FFC(o, 0, spB, 0x24, 0xa, 2);
        fn_80199FFC(o, 1, fn_801D68C4(lbl_803470F4, 0x31), 0x38, 0xa, 2);
        fn_80199FFC(o, 2, fn_801D68C4(lbl_803470F4, 0x32), 0x71, 0xa, 2);
        fn_80199FFC(o, 3, fn_801D68C4(lbl_803470F4, 0x33), 0x71, 0x22, 2);
        fn_80199FFC(o, 4, fn_801D68C4(lbl_803470F4, 0x2a), 0x7, 0x6, 2);
        break;
    default:
        fn_8019A15C(o, 1, 1, 1);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x10), 0x1c, 0x6, 2);
        break;
    }
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 2);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    d[2] = kind;
    o->p44 = fn_801D68C4(lbl_803470F0, 4);
}

void fn_8018C00C(Self_8018C00C *self, f32 a, s8 unused, s8 mode)
{
    Obj48 *o = &self->panel;
    s8 *d = self->data;
    void *spr2;

    o->f00 = -6940.0f + 150.0f * (f32)d[1];
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = a;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    switch (mode) {
    case 0:
        fn_8019A15C(o, 1, 9, 1);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x10), 0x1c, 0x6, 2);
        fn_80199FFC(o, 1, fn_801D68C4(lbl_803470F4, 0x1d), 0x34, 0xa, 2);
        fn_80199FFC(o, 2, fn_801D68C4(lbl_803470F4, 0x11), 0xa0, 0x6, 2);
        fn_80199FFC(o, 3, fn_801D68C4(lbl_803470F4, 0x1e), 0xb8, 0xa, 2);
        fn_80199FFC(o, 4, fn_801D68C4(lbl_803470F4, 0x12), 0x1c, 0x1e, 2);
        fn_80199FFC(o, 5, fn_801D68C4(lbl_803470F4, 0x1f), 0x34, 0x22, 2);
        fn_80199FFC(o, 6, fn_801D68C4(lbl_803470F4, 0x13), 0xa0, 0x1e, 2);
        fn_80199FFC(o, 7, fn_801D68C4(lbl_803470F4, 0x20), 0xb8, 0x22, 2);
        fn_80199FFC(o, 8, fn_801D68C4(lbl_803470F4, 0x4), 0x8, 0x6, 2);
        break;
    case 1:
        fn_8019A15C(o, 1, 7, 1);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x14), 0x1c, 0x6, 2);
        fn_80199FFC(o, 1, fn_801D68C4(lbl_803470F4, 0x21), 0x34, 0xa, 2);
        fn_80199FFC(o, 2, fn_801D68C4(lbl_803470F4, 0x15), 0xa0, 0x6, 2);
        fn_80199FFC(o, 3, fn_801D68C4(lbl_803470F4, 0x22), 0xb8, 0xa, 2);
        fn_80199FFC(o, 4, fn_801D68C4(lbl_803470F4, 0x16), 0x1c, 0x1e, 2);
        fn_80199FFC(o, 5, fn_801D68C4(lbl_803470F4, 0x23), 0x34, 0x22, 2);
        fn_80199FFC(o, 6, fn_801D68C4(lbl_803470F4, 0x4), 0x8, 0x6, 2);
        break;
    case 2:
        fn_8019A15C(o, 3, 1, 1);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
        switch (d[3]) {
        case 0:
            spr2 = fn_801D68C4(lbl_803470F0, 0x2b);
            break;
        case 1:
            spr2 = fn_801D68C4(lbl_803470F0, 0x2c);
            break;
        case 2:
            spr2 = fn_801D68C4(lbl_803470F0, 0x2d);
            break;
        case 3:
            spr2 = fn_801D68C4(lbl_803470F0, 0x2e);
            break;
        case 4:
            spr2 = fn_801D68C4(lbl_803470F0, 0x2f);
            break;
        case 5:
            spr2 = fn_801D68C4(lbl_803470F0, 0x30);
            break;
        }
        fn_8019520C(d[3], spr2);
        fn_80199FFC(o, 1, spr2, 0x1c, 6, 0);
        fn_80199FFC(o, 2, fn_801D68C4(lbl_803470F0, 0x31), 0x1c, 0x1e, 0);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x38), 0x12, 0x6, 2);
        break;
    case 3:
        fn_8019A15C(o, 2, 1, 1);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
        fn_80199FFC(o, 1, fn_801D68C4(lbl_803470F0, 0x33), 0x1c, 0x6, 0);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x38), 0x12, 0x6, 2);
        break;
    case 4:
        fn_8019A15C(o, 1, 1, 1);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x36), 0xc, 0x1f, 2);
        break;
    default:
        fn_8019A15C(o, 1, 0, 1);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F0, 0xa), 0x0, 0x0, 0);
    }
    o->p2c->p0 = fn_801D68C4(lbl_803470E8, 2);
    o->p30->f0 = 0.0f;
    o->p30->f4 = 0.0f;
    o->p44 = fn_801D68C4(lbl_803470F0, 4);
}

void fn_8017BB1C(void) {
    s16 *base = camp_work.p04;
    CampCtrl *c = &lbl_80307638[11];
    s32 v = fn_80194ECC();
    s16 *row = base + c->cur[0].sel;
    s32 x = row[17];
    s32 st = c->cur[2].sel;
    switch (st) {
    case 0:
        row[12] = v; fn_801929B8(0x16);
        break;
    case 1:
        if (x == v) { row[17] = -1; fn_801929B8(2); }
        else { row[17] = v; fn_801929B8(0x16); }
        break;
    }
    fn_80194F3C();
}

void fn_8017DF14(void)
{
    UiObj *obj;
    s32 i;
    UiObj *first;
    f32 y;

    first = &camp_work.pnl[lbl_80307638[1].cur[0].sel]->win->obj;
    fn_80199BB8(first, -8.0f, 61.0f);
    fn_80199BAC(first, -8.0f, 61.0f);

    obj = &camp_work.pnl[lbl_80307638[4].cur[0].sel + 0x78]->win->obj;
    fn_80199BB8(obj, -348.0f, 125.0f);
    fn_80199BAC(obj, -348.0f, 125.0f);

    obj = &camp_work.pnl[0x6e]->win->obj;
    fn_80199BB8(obj, -348.0f, 189.0f);
    fn_80199BAC(obj, -348.0f, 189.0f);

    obj = &camp_work.pnl[0x6f]->win->obj;
    fn_80199BB8(obj, -348.0f, 253.0f);
    fn_80199BAC(obj, -348.0f, 253.0f);

    for (i = 0; i < 5; i++) {
        obj = &camp_work.pnl[0x7a + i]->win->obj;
        UiObjSetLowered(obj);
        y = (f32)(i * 64 + 61);
        fn_80199BB8(obj, 668.0f, y);
        fn_80199BAC(obj, 668.0f, y);
    }
    for (i = 5; i < 8; i++) {
        obj = &camp_work.pnl[0x7a + i]->win->obj;
        UiObjSetLowered(obj);
        y = (f32)((i - 5) * 64 + 61);
        fn_80199BB8(obj, 668.0f, y);
        fn_80199BAC(obj, 668.0f, y);
    }

    obj = &camp_work.pnl[0x60]->win->obj;
    fn_80199BB8(obj, 632.0f, 480.0f);
    fn_80199BAC(obj, 632.0f, 480.0f);
}

void fn_8017567C(void)
{
    s32 i;
    CampCtrl *m = lbl_80307638;

    CampMenuHideAllPanels();
    camp_work.pnl[lbl_80307638[1].cur[0].sel]->win->x0 = 1;
    for (i = 0; i < camp_work.count; i++) {
        camp_work.pnl[i]->win->x0 = 1;
    }
    camp_work.pnl[m[3].cur[0].sel + 0x1f]->win->x0 = 1;
    camp_work.pnl[0x68]->win->x0 = 1;
    camp_work.pnl[0x69]->win->x0 = 1;
    camp_work.pnl[0x5a]->win->x0 = 1;
    camp_work.pnl[0x5b]->win->x0 = 1;
    camp_work.pnl[0x5c]->win->x0 = 1;
    camp_work.pnl[0x60]->win->x0 = 1;
}

void fn_80175DC4(void) {
    CampCtrl *c;
    UiObj *w;
    CampWork *cw;
    Sprite *s;
    s32 who;

    cw = &camp_work;
    c = lbl_8034710C->holder->ctrl;
    w = &cw->pnl[0x41]->win->obj;
    who = lbl_8030B7F4.party[lbl_80307638[1].cur[0].sel];
    if (fn_80195CD0(who, lbl_80307638[8].cur[0].sel + 1, 3, c->cur[4].sel) > 1) {
        s = fn_801D68C4(lbl_803470F0, 0x62);
        s->x = 24.0f + w->rect[0];
        s->y = 156.0f + w->rect[1];
        fn_801D4F0C(s, -3100.0f, 0.0f, 1.0f, cw->f358, 0, 0, 1);
        s = fn_801D68C4(lbl_803470F0, 0x63);
        s->x = 272.0f + w->rect[0];
        s->y = 156.0f + w->rect[1];
        fn_801D4F0C(s, -3100.0f, 0.0f, 1.0f, cw->f358, 0, 0, 1);
    }
}

void fn_80178BC8(void) {
    CampReq req;
    CampCtrl* m;
    s8* party;
    s32 j;
    s32 idx;
    s32 i;
    s32 who;
    CampCtrl* c;
    UiObj* o;

    m = lbl_80307638;
    c = lbl_8034710C->holder->ctrl;
    party = lbl_8030B7F4.party;
    idx = c->cur[2].sel;
    m[1].cur[0].sel = idx;
    who = party[idx];
    o = &camp_work.pnl[idx]->win->obj;
    fn_80199BB8(o, -348.0f, 61.0f);
    fn_80199BAC(o, -348.0f, 61.0f);
    UiObjSetRaised(o);
    for (i = 0; i < 7; i++) {
        s32 n = i + 0x3a;
        o = &camp_work.pnl[n]->win->obj;
        fn_80199BB8(o, 668.0f, 204.0f);
        fn_80199BAC(o, 668.0f, 204.0f);
    }
    fn_80179554();
    fn_80179388();
    for (j = 0; j < 7; j++) {
        fn_80189900(camp_work.pnl[j + 0x3a]->win->xbc, who, j - 1, 1, 0);
    }
    who = party[m[1].cur[0].sel];
    fn_80195EA4(&req, who, c->cur[1].sel, c->cur[4].sel, 1);
    fn_801954D0(req.e[c->cur[0].sel].x10);
}

void fn_8017C510(void) {
    s32 i;
    UiObj* o;
    CampCtrl* scr4 = &lbl_80307638[4];
    CampCtrl* scr11 = &lbl_80307638[11];
    CampCtrl* c = lbl_8034710C->holder->ctrl;

    CampMenuHideAllPanels();
    camp_work.pnl[4]->win->x0 = 1;
    camp_work.pnl[0x78 + scr4->cur[0].sel]->win->x0 = 1;
    camp_work.pnl[0x70]->win->x0 = 1;
    camp_work.pnl[0x71]->win->x0 = 1;
    camp_work.pnl[0x74]->win->x0 = 1;
    camp_work.pnl[0x72]->win->x0 = 1;
    camp_work.pnl[0x73]->win->x0 = 1;
    camp_work.pnl[0x75]->win->x0 = 1;
    c->cur[2].sel = scr4->cur[2].sel;
    if (fn_80195D8C(scr11->cur[0].sel, scr11->cur[2].sel + 6, 4, c->cur[4].sel) <= 0) {
        camp_work.pnl[0x71]->win->x0 = 0;
        camp_work.pnl[0x73]->win->x0 = 0;
    }
    for (i = 0; i < 7; i++) {
        camp_work.pnl[0x4f + i]->win->x0 = 0;
        o = &camp_work.pnl[0x4f + i]->win->obj;
        fn_80199BA4(o, 0);
        fn_80199B9C(o, 1.0f);
    }
    camp_work.pnl[0x4f]->win->x0 = 1;
    camp_work.pnl[0x54]->win->x0 = 1;
    camp_work.pnl[0x60]->win->x0 = 1;
    camp_work.pnl[0x65]->win->x0 = 0;
}

void fn_801847F0(void) {
    CampCtrl* c;
    s32 i;
    UiObj* o;
    c = lbl_8034710C->holder->ctrl;
    for (i = 0; i < camp_work.count; i++) {
        o = &camp_work.pnl[i]->win->obj;
        UiObjMoveTo(o, 6, -1, -8.0f, i * 64 + 61);
        if (c->cur[0].sel == i) UiObjSetCommand(o, 10, i);
        else UiObjSetCommand(o, 15, i);
    }
    if (fn_801953B8()) {
        o = &camp_work.pnl[4]->win->obj;
        UiObjMoveTo(o, 6, 4, -8.0f, 317.0f);
        if (c->cur[0].sel == 4) UiObjSetCommand(o, 10, 4);
        else UiObjSetCommand(o, 15, 4);
        o = &camp_work.pnl[0x6c + c->cur[1].sel]->win->obj;
        UiObjMoveTo(o, 6, -1, 328.0f, 317.0f);
        UiObjSetCommand(o, 15, 4);
    }
    for (i = 0; i < camp_work.count; i++) {
        o = &camp_work.pnl[c->cur[4].sel + (i * 5 + 6)]->win->obj;
        UiObjMoveTo(o, 6, 4, 328.0f, i * 64 + 61);
        UiObjSetCommand(o, 15, i);
    }
    if (fn_80194CB8() == 1) {
        o = &camp_work.pnl[5]->win->obj;
        UiObjMoveTo(o, 6, 4, -8.0f, 381.0f);
        if (c->cur[0].sel == 5) UiObjSetCommand(o, 10, 5);
        else UiObjSetCommand(o, 15, 5);
    }
}

s32 fn_8017F644(void) {
    CampCtrl* c;
    s32 r;

    fn_801F2E44(lbl_8030B7F4.party[lbl_80307638[1].cur[0].sel]);
    switch (camp_work.state[10]) {
    case 0:
        c = lbl_8034710C->holder->ctrl;
        fn_80180EA0();
        c->cur[6].mask = 2;
        fn_80195A68(c, 1, 1, 0, 0, 0);
        c->cur[1].sel = 0;
        c->cur[1].x8 = 1;
        c->state = 0;
        fn_801954D0(0);
        fn_80180CCC();
        fn_80180B80();
        fn_80180A84();
        camp_work.state[10] = 2;
        break;
    case 2:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.state[10] = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.state[10] = 3;
        }
        break;
    case 3:
        r = fn_8017F9D8();
        fn_8017F840();
        switch (r) {
        case -1:
            camp_work.state[10] = 0x18;
            break;
        case 0x7fffffff: /* only this second case gives the original's beq/blt/b tree; 0x7FFFFFFF is the
                            script "no value" sentinel, but whether fn_8017F9D8 returns it is unverified */
            break;
        }
        break;
    case 0x18:
        camp_work.pnl[0x64]->win->x0 = 0;
        fn_801808D4();
        camp_work.state[10] = 0x13;
        break;
    case 0x13:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.state[3] = 0;
            camp_screen = 3;
            fn_801959D4(3);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.state[3] = 0;
            camp_screen = 3;
            fn_801959D4(3);
        }
        break;
    }
    return 0;
}

void fn_8018DD24(Obj_8018DD24 *self) {
    Node_8018DD24 *node = self->node;
    void *ui = node->ui;
    s32 b;
    s16 a;
    s16 c;
    switch (node->x4) {
    case 0x67:
        if (lbl_80307638[15].cur[0].sel == 0) {
            a = 0x18;
            b = lbl_80307638[16].cur[0].sel;
            c = (lbl_80307638[16].cur[4].sel % 2) * 0xf8;
        } else {
            a = 0;
            b = lbl_80307638[16].cur[0].sel;
            c = (lbl_80307638[16].cur[4].sel % 2) * 0xf8;
        }
        break;
    default:
        break;
    }
    {
        f32 x = c + 0x30;
        f32 y = b * 0x18 + 0x83 + a;
        fn_80199BB8(ui, x, y);
        fn_80199BAC(ui, x, y);
    }
    switch (self->state) {
    case 0xFE:
    case 0:
        self->state = 1;
    case 1:
        fn_80199F38(ui);
        UiObjCalcRect(ui);
        if (self->node->x0 == 1) {
            self->node->f8c = lbl_8034710C->holder->ctrl->f74;
            fn_800FF3EC(self->node);
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xFF:
        fn_80199F58(self->node);
        self->flags |= 0x40;
        break;
    }
}

#ifdef NONMATCHING
extern void fn_801957D8(s8 v);
extern s32 fn_8017AFA0(void);
extern void fn_80195B38(s8 idx, s32 id, s8 flag);
#endif

#ifdef NONMATCHING
s32 fn_8017AB38(void)
{
    CampWork* cw;
    UiObj* o;
    s32 i;
    CampCtrl* c;

    cw = &camp_work;
    switch (cw->state[15]) {
    case 0:
        CampMenuHideAllPanels();
        camp_work.pnl[0x1a]->win->x0 = 1;
        camp_work.pnl[0x87]->win->x0 = 1;
        camp_work.pnl[0x88]->win->x0 = 1;
        camp_work.pnl[0x87]->win->f74 = -5290.0f;
        camp_work.pnl[0x88]->win->f74 = -5140.0f;
        fn_8017B5EC();
        c = lbl_8034710C->holder->ctrl;
        for (i = 0; i < 2; i++) {
            o = &camp_work.pnl[0x87 + i]->win->obj;
            UiObjMoveTo(o, 6, 4, -8.0f, (i + 1) * 64 + 61);
            if (c->cur[0].sel == i) {
                UiObjSetCommand(o, 10, i);
            } else {
                UiObjSetCommand(o, 0xf, i + 1);
            }
        }
        fn_8017B0F8();
        cw->state[15] = 2;
        break;
    case 1:
        CampMenuHideAllPanels();
        camp_work.pnl[0x1a]->win->x0 = 1;
        camp_work.pnl[0x87]->win->x0 = 1;
        camp_work.pnl[0x88]->win->x0 = 1;
        camp_work.pnl[0x87]->win->f74 = -5290.0f;
        camp_work.pnl[0x88]->win->f74 = -5140.0f;
        fn_8017B4E4();
        fn_8017B19C();
        fn_8017B0F8();
        cw->state[15] = 2;
        break;
    case 2:
        if (CampMenuAnyPanelBusy() == 0) {
            cw->state[15] = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            cw->state[15] = 3;
        }
        break;
    case 3:
        switch (fn_8017AFA0()) {
        case -1:
            cw->state[15] = 0x18;
            break;
        case 0:
            break;
        case 1:
            cw->state[15] = 0xc;
            break;
        }
        break;
    case 12:
        fn_8017B3BC();
        cw->state[15] = 0x12;
        break;
    case 18:
        if (CampMenuAnyPanelBusy() == 0) {
            switch (lbl_8034710C->holder->ctrl->cur[0].sel) {
            case 0:
                camp_work.state[16] = 0;
                camp_screen = 0x10;
                fn_801959D4(0x10);
                break;
            case 1:
                camp_work.state[16] = 0;
                camp_screen = 0x10;
                fn_801959D4(0x10);
                break;
            default:
                camp_work.state[2] = 0;
                camp_screen = 2;
                fn_801959D4(2);
                break;
            }
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            switch (lbl_8034710C->holder->ctrl->cur[0].sel) {
            case 0:
                camp_work.state[16] = 0;
                camp_screen = 0x10;
                fn_801959D4(0x10);
                break;
            case 1:
                camp_work.state[16] = 0;
                camp_screen = 0x10;
                fn_801959D4(0x10);
                break;
            default:
                camp_work.state[2] = 0;
                camp_screen = 2;
                fn_801959D4(2);
                break;
            }
        }
        break;
    case 24:
        fn_8017B2AC();
        cw->state[15] = 0x13;
        break;
    case 19:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.state[2] = 0;
            camp_screen = 2;
            fn_801959D4(2);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.state[2] = 0;
            camp_screen = 2;
            fn_801959D4(2);
        }
        break;
    }
    return 0;
}
#endif

#ifdef NONMATCHING
s32 fn_80183D90(void)
{
    UiObj* o;
    s32 k;
    s32 y;
    s32 i;
    CampCtrl* c;

    c = lbl_8034710C->holder->ctrl;

    if (fn_801C09F8(lbl_80347154, 5)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = fn_8019A21C(c->cur[0].mask, 1, c->cur[0].sel, 0, 7);
        goto upd;
    } else if (fn_801C09F8(lbl_80347154, 4)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = fn_8019A21C(c->cur[0].mask, -1, c->cur[0].sel, 0, 7);
        goto upd;
    } else if (fn_801C09F8(lbl_80347154, 7)) {
        c->cur[4].x8 = c->cur[4].sel;
        c->cur[4].sel++;
        if (c->cur[4].sel >= 5) {
            c->cur[4].sel = 0;
        }
        c->cur[1].x8 = c->cur[1].sel;
        c->cur[1].sel++;
        if (c->cur[1].sel >= 2) {
            c->cur[1].sel = 0;
        }
        goto anim;
    } else if (fn_801C09F8(lbl_80347154, 6)) {
        c->cur[4].x8 = c->cur[4].sel;
        c->cur[4].sel--;
        if (c->cur[4].sel < 0) {
            c->cur[4].sel = 4;
        }
        c->cur[1].x8 = c->cur[1].sel;
        c->cur[1].sel--;
        if (c->cur[1].sel < 0) {
            c->cur[1].sel = 1;
        }
        goto anim;
    } else if (fn_801C09F8(lbl_80347154, 2)) {
        fn_801929B8(2);
        return 1;
    } else if (fn_801C09F8(lbl_80347154, 1)) {
        return -1;
    } else if (fn_801C09F8(lbl_80347154, 0x11) || fn_801C09F8(lbl_80347154, 0x10)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = 5;
        fn_801929B8(2);
        return 1;
    }
    goto end;
upd:
    UiObjSetCommand(&camp_work.pnl[c->cur[0].sel]->win->obj, 0x15, 0);
    fn_801929B8(4);
    UiObjSetCommand(&camp_work.pnl[c->cur[0].x8]->win->obj, 0x14, 0);
    goto end;
anim:
    for (i = 0, k = 6, y = 0x3d; i < camp_work.count; k += 5, y += 0x40, i++) {
        o = &camp_work.pnl[c->cur[4].x8 + k]->win->obj;
        UiObjFinish(o);
        if (i == 0) {
            UiObjMoveTo(o, 6, 4, 668.0f, y);
        } else {
            UiObjMoveTo(o, 6, -1, 668.0f, y);
        }
        UiObjSetCommand(o, 10, 0);
        o = &camp_work.pnl[c->cur[4].sel + k]->win->obj;
        UiObjFinish(o);
        UiObjMoveTo(o, 6, -1, 328.0f, y);
        UiObjSetCommand(o, 5, 0);
    }
    if (fn_801953B8()) {
        o = &camp_work.pnl[c->cur[1].x8 + 0x6c]->win->obj;
        UiObjFinish(o);
        UiObjMoveTo(o, 6, -1, 668.0f, 317.0f);
        UiObjSetCommand(o, 10, 0);
        o = &camp_work.pnl[c->cur[1].sel + 0x6c]->win->obj;
        UiObjFinish(o);
        UiObjMoveTo(o, 6, -1, 328.0f, 317.0f);
        UiObjSetCommand(o, 5, 0);
    }
end:
    return 0;
}
#endif

#ifdef NONMATCHING
void fn_80174E18(void)
{
    SaveChar *c;
    s32 i;
    s32 id;
    s32 j;
    UiObj *obj;
    s32 v;
    s32 k;

    i = lbl_8034710C->holder->ctrl->cur[2].sel;
    lbl_80307638[1].cur[0].sel = i;
    v = lbl_8030B7F4.party[i];
    obj = &camp_work.pnl[i]->win->obj;
    fn_80199BB8(obj, -348.0f, 61.0f);
    fn_80199BAC(obj, -348.0f, 61.0f);
    UiObjSetRaised(obj);
    c = &lbl_8030B7F4.chr[v];
    for (j = 0; j < 3; j++) {
        switch (j) {
        case 0:
            id = c->slot0;
            k = 0;
            break;
        case 1:
            id = c->slot1;
            k = 1;
            break;
        case 2:
            id = c->slot2;
            k = 2;
            break;
        }
        fn_80195B38(k, id, j + 1);
    }
}
#endif


s32 fn_8017AFA0(void) {
    CampCtrl *c = lbl_8034710C->holder->ctrl;

    if (fn_801C09F8(lbl_80347154, 5)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = fn_8019A21C(c->cur[0].mask, 1, c->cur[0].sel, 0, 7);
    } else if (fn_801C09F8(lbl_80347154, 4)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = fn_8019A21C(c->cur[0].mask, -1, c->cur[0].sel, 0, 7);
    } else if (fn_801C09F8(lbl_80347154, 2)) {
        fn_801929B8(2);
        return 1;
    } else if (fn_801C09F8(lbl_80347154, 1)) {
        fn_801929B8(5);
        return -1;
    } else {
        return 0;
    }
    UiObjSetCommand(PnlObj(c->cur[0].sel + 0x87), 0x15, 0);
    fn_801929B8(4);
    UiObjSetCommand(PnlObj(c->cur[0].x8 + 0x87), 0x14, 0);
    return 0;
}

void fn_8017BBC8(void) {
    UiObj *w;
    CampWork *cw;
    Sprite *s;

    cw = &camp_work;
    w = &cw->pnl[0x4f]->win->obj;
    if (fn_80194E6C() > 1) {
        s = fn_801D68C4(lbl_803470F0, 0x62);
        s->x = 24.0f + w->rect[0];
        s->y = 156.0f + w->rect[1];
        fn_801D4F0C(s, -3100.0f, 0.0f, 1.0f, cw->f358, 0, 0, 1);
        s = fn_801D68C4(lbl_803470F0, 0x63);
        s->x = 272.0f + w->rect[0];
        s->y = 156.0f + w->rect[1];
        fn_801D4F0C(s, -3100.0f, 0.0f, 1.0f, cw->f358, 0, 0, 1);
    }
}

extern void fn_8017BB1C(void);
extern void fn_8019540C(void);
s32 fn_8017BCA8(void) {
    CampCtrl *c;
    s32 n;
    s32 k;
    CampCtrl *z = &lbl_80307638[11];

    c = lbl_8034710C->holder->ctrl;
    n = fn_80195D8C(z->cur[0].sel, z->cur[2].sel + 6, 4, c->cur[4].sel);
    if (n <= 0) {
        camp_work.pnl[0x65]->win->x0 = 0;
        c->cur[0].sel = 0;
    } else {
        camp_work.pnl[0x65]->win->x0 = 1;
    }
    k = fn_80194ECC();
    if (k != -1) {
        fn_801954D0(fn_801F48AC(k));
    } else {
        fn_801954D0(0);
    }
    if (fn_801C09F8(lbl_80347154, 5)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = fn_8019A21C(c->cur[0].mask, 1, c->cur[0].sel, 0, 7);
        if (c->cur[0].x8 != c->cur[0].sel) goto upd;
    } else if (fn_801C09F8(lbl_80347154, 4)) {
        c->cur[0].x8 = c->cur[0].sel;
        c->cur[0].sel = fn_8019A21C(c->cur[0].mask, -1, c->cur[0].sel, 0, 7);
        if (c->cur[0].x8 != c->cur[0].sel) goto upd;
    } else if (fn_801C09F8(lbl_80347154, 7)) {
        c->cur[4].x8 = c->cur[4].sel;
        c->cur[4].sel = fn_8019A21C(c->cur[4].mask, 1, c->cur[4].sel, 0, 7);
        if (c->cur[4].x8 != c->cur[4].sel) goto page;
        goto upd;
    } else if (fn_801C09F8(lbl_80347154, 6)) {
        c->cur[4].x8 = c->cur[4].sel;
        c->cur[4].sel = fn_8019A21C(c->cur[4].mask, -1, c->cur[4].sel, 0, 7);
        if (c->cur[4].x8 != c->cur[4].sel) goto page;
        goto upd;
    } else if (fn_801C09F8(lbl_80347154, 2)) {
        if (n <= 0) goto end;
        goto pick;
    } else if (fn_801C09F8(lbl_80347154, 1)) {
        fn_801929B8(5);
        return -1;
    }
    goto end;
upd:
    fn_8019540C();
    fn_801929B8(0);
    goto end;
page:
    c->cur[0].sel = 0;
    fn_8019540C();
    fn_801929B8(0);
    goto end;
pick:
    fn_8017BB1C();
end:
    return 0;
}

typedef struct {
    s32 kind;   /* 0x00 */
    s32 type;   /* 0x04 */
    UiObj obj;  /* 0x08 */
    u8 pad[0xbc - 8 - sizeof(UiObj)];
    Slots* sub; /* 0xbc */
} Inner_80186A60;
typedef struct {
    u8 pad00[0x18];
    u8 flags;    /* 0x18 */
    u8 state;    /* 0x19 */
    u8 pad1A[0x24 - 0x1A];
    Inner_80186A60* inner; /* 0x24 */
} Self_80186A60;
extern const char lbl_802B44C0[];

static inline void DrawPanelText_80186A60(Inner_80186A60* in) {
    f32 z;
    s16 x;
    s16 y;
    Slots* sub;

    x = in->obj.rect[0];
    y = in->obj.rect[1];
    sub = in->sub;
    z = TextGetZ();
    TextSetZ(-3930.0f);
    TextPushColor();
    TextSetColor(0xff201008);
    TextPrint(x + 0x98, y + 4, "Active");
    TextPrint(x + 0x140, y + 4, lbl_802B44C0);
    fn_80186BE4(x, y, sub);
    TextPopColor(1);
    TextSetZ(z);
}

void fn_80186A60(Self_80186A60* self) {
    UiObj* obj = &self->inner->obj;

    if (lbl_803475D8 != 0) {
        self->state = 0xff;
    }
    switch (self->state) {
    case 0:
    case 0xfe:
        self->state = 1;
    case 1:
        fn_80199F38(obj);
        UiObjCalcRect(obj);
        if (self->inner->kind == 1) {
            CampPanelDrawFrame(self->inner);
            DrawPanelText_80186A60(self->inner);
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58(self->inner);
        self->flags |= 0x40;
        break;
    }
}

static inline SaveChar* ChrOf_80186F58(s16 i) {
    return &lbl_8030B7F4.chr[i];
}

static inline s32 HasBit_80186F58(u32 mask, s16 i) {
    return (mask & (1 << i)) != 0;
}

#define ICON_80186F58(ID, SX, SY, K, TX, TY)                                                         \
    s = fn_801D68C4(lbl_803470F4, ID);                                                               \
    s->x = x + (SX);                                                                                 \
    s->y = y + (SY);                                                                                 \
    fn_801D52A8(s, 10.0f + self->pos.f0, self->pos.f4, 1.0f, 1.0f, self->pos.ic, self->pos.i8);     \
    fn_8019A374(cfg->eq->stat[K], x + (TX), y + (TY), 10.0f + self->pos.f0, 0xff201008, 0)

#define USER_ICON_80186F58(spr, i)                                  \
    switch (i) {                                                    \
    case 0: spr = fn_801D68C4(lbl_803470F0, 0x2b); break;           \
    case 1: spr = fn_801D68C4(lbl_803470F0, 0x2c); break;           \
    case 2: spr = fn_801D68C4(lbl_803470F0, 0x2d); break;           \
    case 3: spr = fn_801D68C4(lbl_803470F0, 0x2e); break;           \
    case 4: spr = fn_801D68C4(lbl_803470F0, 0x2f); break;           \
    case 5: spr = fn_801D68C4(lbl_803470F0, 0x30); break;           \
    default: spr = fn_801D68C4(lbl_803470F0, 0x2b); break;          \
    }

void fn_80186F58(Inner_80186E4C* self) {
    Cfg* cfg = self->cfg;
    s16 x = self->obj.rect[0];
    s16 y = self->obj.rect[1];
    f32 savez;
    s16 i;
    Sprite* spr;
    Sprite* s;
    s32 w;

    savez = TextGetZ();
    TextSetZ(10.0f + self->pos.f0);
    TextPushColor();
    TextSetColor(0xff201008);
    switch (cfg->kind) {
    case 0:
        for (i = 0; i < 6; i++) {
            if (HasBit_80186F58(cfg->eq->users, i) == 1) {
                break;
            }
        }
        USER_ICON_80186F58(spr, i);
        fn_8019520C(i, spr);
        break;
    case 1:
        spr = fn_801D68C4(lbl_803470F0, 0x31);
        break;
    case 2:
        spr = fn_801D68C4(lbl_803470F0, 0x33);
        break;
    case 3:
        switch (cfg->eq->kind) {
        case 1:
            for (i = 0; i < 6; i++) {
                if (HasBit_80186F58(cfg->eq->users, i) == 1) {
                    break;
                }
            }
            USER_ICON_80186F58(spr, i);
            w = ChrOf_80186F58(i)->slot0;
            if (w == cfg->eq->id) {
                fn_8019520C(i, spr);
            } else {
                spr->pieces->colour = -1;
            }
            break;
        case 2:
            spr = fn_801D68C4(lbl_803470F0, 0x31);
            break;
        case 3:
            spr = fn_801D68C4(lbl_803470F0, 0x33);
            break;
        }
        break;
    case 5:
        fn_80195B38(5, lbl_8030B7F4.chr[2].slot0, 1);
        spr = fn_801D68C4(lbl_803470F0, 0x2d);
        if (lbl_8030B7F4.chr[2].slot0 == cfg->eq->id) {
            fn_8019520C(2, spr);
        } else {
            spr->pieces->colour = -1;
        }
        break;
    }
    spr->x = x + 0x18;
    spr->y = y + 6;
    fn_801D4F0C(spr, 10.0f + self->pos.f0, self->pos.f4, 1.0f, 1.0f, self->pos.ic, self->pos.i8, 1);
    spr->pieces->colour = -1;
    if (cfg->eq->id == -1) {
        TextPrint(x + 0x32, y + 6, lbl_802EBB20);
    } else {
        TextPrint(x + 0x32, y + 6, cfg->eq->name);
    }
    ICON_80186F58(0x10, 4, 0x1e, 0, 0x33, 0x22);
    ICON_80186F58(0x11, 0x4c, 0x1e, 1, 0x7b, 0x22);
    ICON_80186F58(0x12, 0x94, 0x1e, 2, 0xc3, 0x22);
    ICON_80186F58(0x13, 0xdc, 0x1e, 3, 0x10b, 0x22);
    ICON_80186F58(0x14, 4, 0x36, 4, 0x33, 0x3a);
    ICON_80186F58(0x15, 0x4c, 0x36, 5, 0x7b, 0x3a);
    ICON_80186F58(0x16, 0x94, 0x36, 6, 0xc3, 0x3a);
    TextPopColor(1);
    TextSetZ(savez);
}

extern void* fn_801DB244(void* p);
extern s16 lbl_803470D4;
extern s16 lbl_803470D6;
extern int sprintf(char* buf, const char* fmt, ...);
extern char *strcat(char *dst, const char *src);
extern void fn_801866B4(void);
extern void fn_80186348(void);
static inline s32 Test2_80192EDC(u32 b)
{
    s32 f = (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
    return f != 0;
}

s32 fn_80185C00(void)
{
    char buf[0x20];
    s32 i;
    s32 cnt = 0;
    s32 first = 0;
    CampWork *cw;

    for (i = 0; i < 8; i++) {
        if (Test2_80192EDC(i + 0xac8)) {
            if (first == 0) {
                first = i + 1;
            }
            cnt++;
        }
    }
    cw = &camp_work;
    switch (cw->state[19]) {
    case 0:
        cw->state[19] = 2;
        fn_801866B4();
        lbl_803470D4 = 0x280;
        lbl_803470D6 = first - 1;
        sprintf(buf, "/field/wanted%02d", lbl_803470D6 + 1);
        if (lbl_80310A1C.x64[lbl_803470D6] < 3) {
            strcat(buf, "a.mld");
        } else {
            strcat(buf, "b.mld");
        }
        lbl_803470D0 = fn_801DB244(buf);
        fn_80227810(lbl_803470D0->x4->x20);
        SePlay(2, 1, 4);
        break;
    case 2:
        fn_801863E8(lbl_803470D4, lbl_803470D6, 0);
        lbl_803470D4 -= 0x60;
        if (lbl_803470D4 <= 0) {
            lbl_803470D4 = 0;
            cw->state[19] = 3;
        }
        break;
    case 3:
        fn_801863E8(lbl_803470D4, lbl_803470D6, cnt);
        if ((lbl_80311A60[0]->held & 0x200) != 0) {
            cw->state[19] = 0x18;
            SePlay(2, 1, 4);
        } else if ((lbl_80311A60[0]->held & 0x40) != 0 && cnt > 1) {
            cw->state[19] = 0x14;
            lbl_803470D4 = 0;
            SePlay(2, 1, 4);
        } else if ((lbl_80311A60[0]->held & 0x20) != 0 && cnt > 1) {
            cw->state[19] = 0x15;
            lbl_803470D4 = 0;
            SePlay(2, 1, 4);
        }
        break;
    case 24:
        fn_801863E8(lbl_803470D4, lbl_803470D6, 0);
        fn_801861F8();
        cw->state[19] = 0x12;
        break;
    case 18:
        fn_801863E8(lbl_803470D4, lbl_803470D6, 0);
        lbl_803470D4 += 0x60;
        if (lbl_803470D4 >= 0x280) {
            lbl_803470D4 = 0;
            cw->state[19] = 0x13;
            fn_802275A4(lbl_803470D0->x4->x20, 1);
            fn_801E17E0(lbl_803470D0);
            lbl_803470D0 = 0;
            fn_80186348();
        }
        break;
    case 19:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.state[2] = 0;
            camp_screen = 2;
            fn_801959D4(2);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.state[2] = 0;
            camp_screen = 2;
            fn_801959D4(2);
        }
        break;
    case 20:
        lbl_803470D4 += 0x60;
        fn_801863E8(lbl_803470D4, lbl_803470D6, 0);
        if (lbl_803470D4 >= 0x2e0) {
            lbl_803470D4 = 0x280;
            while (1) {
                lbl_803470D6--;
                if (lbl_803470D6 < 0) {
                    lbl_803470D6 = 7;
                }
            if (Test2_80192EDC(lbl_803470D6 + 0xac8)) break;
            }
            cw->state[19] = 0x16;
        }
        break;
    case 21:
        lbl_803470D4 += 0x60;
        fn_801863E8(lbl_803470D4, lbl_803470D6, 0);
        if (lbl_803470D4 >= 0x2e0) {
            lbl_803470D4 = 0x280;
            while (1) {
                lbl_803470D6++;
                if (lbl_803470D6 > 7) {
                    lbl_803470D6 = 0;
                }
            if (Test2_80192EDC(lbl_803470D6 + 0xac8)) break;
            }
            cw->state[19] = 0x16;
        }
        break;
    case 22:
        fn_802275A4(lbl_803470D0->x4->x20, 1);
        fn_801E17E0(lbl_803470D0);
        lbl_803470D0 = 0;
        sprintf(buf, "/field/wanted%02d", lbl_803470D6 + 1);
        if (lbl_80310A1C.x64[lbl_803470D6] < 3) {
            strcat(buf, "a.mld");
        } else {
            strcat(buf, "b.mld");
        }
        lbl_803470D0 = fn_801DB244(buf);
        fn_80227810(lbl_803470D0->x4->x20);
        cw->state[19] = 0x17;
        SePlay(2, 1, 4);
        /* fall through */
    case 23:
        fn_801863E8(lbl_803470D4, lbl_803470D6, 0);
        lbl_803470D4 -= 0x60;
        if (lbl_803470D4 <= 0) {
            lbl_803470D4 = 0;
            cw->state[19] = 3;
        }
        break;
    }
    return 0;
}

void fn_8017F840(void) {
    CampWork* cw = &camp_work;
    Sprite* s;
    f32 v;
    CampCtrl* lw = lbl_80307638;
    CampCtrl* c = lbl_8034710C->holder->ctrl;
    UiObj* o;

    if (cw->count > 1) {
        o = &cw->pnl[lw[1].cur[0].sel]->win->obj;
        s = fn_801D68C4(lbl_803470F0, 0x45);
        s->x = 24.0f + o->rect[0];
        s->y = -16.0f + o->rect[1];
        fn_800FF348(s, 0, -5850.0f, 1.0f, cw->f34c);
        s = fn_801D68C4(lbl_803470F0, 0x46);
        s->x = 272.0f + o->rect[0];
        s->y = -16.0f + o->rect[1];
        fn_800FF348(s, 0, -5850.0f, 1.0f, cw->f34c);
    }
    if (fn_801952D0(c->cur[1].mask) > 1) {
        o = &camp_work.pnl[0x48]->win->obj;
        v = 5.0f + o->rect[0];
        s = fn_801D68C4(lbl_803470F0, 0x44);
        s->x = v;
        s->y = 179.0f;
        fn_800FF348(s, 0, -4000.0f, 1.0f, cw->f354);
        v = 47.0f + o->rect[0];
        s = fn_801D68C4(lbl_803470F0, 0x43);
        s->x = v;
        s->y = 179.0f;
        fn_800FF348(s, 0, -4000.0f, 1.0f, cw->f354);
    }
}

void fn_80184330(void) {
    CampCtrl* c = lbl_8034710C->holder->ctrl;
    s32 i;
    UiObj* o;

    for (i = 0; i < camp_work.count; i++) {
        o = &camp_work.pnl[i]->win->obj;
        UiObjMoveTo(o, 6, 5, -348.0f, (f32)(i * 64 + 61));
        UiObjSetCommand(o, 15, i);
    }
    if (fn_801953B8() != 0) {
        o = &camp_work.pnl[4]->win->obj;
        UiObjMoveTo(o, 6, 5, -348.0f, 317.0f);
        UiObjSetCommand(o, 15, 4);
        o = &camp_work.pnl[c->cur[1].sel + 0x6c]->win->obj;
        UiObjMoveTo(o, 6, 4, 668.0f, 317.0f);
        UiObjSetCommand(o, 15, 4);
    }
    for (i = 0; i < camp_work.count; i++) {
        o = &camp_work.pnl[i * 5 + 6 + c->cur[4].sel]->win->obj;
        UiObjMoveTo(o, 6, -1, 668.0f, (f32)(i * 64 + 61));
        UiObjSetCommand(o, 15, i);
    }
    if (fn_80194CB8() == 1) {
        o = &camp_work.pnl[5]->win->obj;
        UiObjMoveTo(o, 6, 5, -348.0f, 381.0f);
        UiObjSetCommand(o, 15, 6);
    }
}

/* Hide the panel of each entry whose check passes. */
static inline void HideUsableEntries(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (lbl_802E97C0[i]() != 0) {
            camp_work.pnl[0x1a + i]->win->x0 = 1;
        }
    }
}

s32 fn_80184F68(void) {
    s32 r;

    switch (camp_work.state[2]) {
    case 0:
        CampMenuHideAllPanels();
        HideUsableEntries();
        camp_work.pnl[0x1b]->win->f74 = -6040.0f;
        camp_work.pnl[0x1e]->win->x0 = 1;
        lbl_80347124 = fn_80194CC8();
        fn_8018564C();
        fn_80185AFC();
        fn_801859BC();
        camp_work.state[2] = 2;
        break;
    case 2:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.state[2] = 3;
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.state[2] = 3;
        }
        break;
    case 3:
        r = fn_801852F8();
        switch (r) {
        case -1:
            camp_work.state[2] = 0x18;
            break;
        case 0:
            break;
        case 1:
            camp_work.state[2] = 0xc;
            break;
        }
        break;
    case 0xc:
        fn_80185864();
        camp_work.state[2] = 0x12;
        break;
    case 0x12:
        if (CampMenuAnyPanelBusy() == 0) {
            fn_801851C8();
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            fn_801851C8();
        }
        break;
    case 0x18:
        fn_80185724();
        camp_work.state[2] = 0x13;
        break;
    case 0x13:
        if (CampMenuAnyPanelBusy() == 0) {
            camp_work.state[1] = 0;
            camp_screen = 1;
            fn_801959D4(1);
        } else if (fn_801C09F8(lbl_80347154, 2) != 0 || fn_801C09F8(lbl_80347154, 1) != 0) {
            CampMenuFinishAllPanels();
            camp_work.state[1] = 0;
            camp_screen = 1;
            fn_801959D4(1);
        }
        break;
    }
    return 0;
}
