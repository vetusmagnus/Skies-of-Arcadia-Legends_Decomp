/* Battle character state (0x8002C010 - 0x80031254): the per-character stat block lbl_80309DE4
 * (Chr: stat recompute fn_8002D72C, damage fn_8002DC14, limit gauge Lim), the event command
 * handlers that take (Msg*, slot index) and set or clear its status bits, the battle unit
 * records reached through the character tasks lbl_80309700 / lbl_80309E24 (Unit: command pick,
 * input flags, status application), the callback list in lbl_8030A10C (fn_8002FEB0 adds,
 * fn_8002FF70 runs), the file-name builders (fn_8002F80C / fn_8002FA00 / fn_8002FD58 /
 * fn_80030280 / fn_800308FC: "MA%03d.MLD" style names) and the title sequence task fn_800304DC
 * with its init/exit helpers. Types shared by several functions are declared once here; types
 * used by one function carry its address as a suffix. */
#include "types.h"

/* Battle unit record (pointed to by the work area at +0x4C). */
typedef struct Unit {
    s8 id;                  /* 0x00 */
    u8 pad1[3];
    u8 x4;                  /* 0x04 */
    u8 pad5;
    s16 x6;                 /* 0x06 */
    s16 x8;                 /* 0x08 */
    s16 xa;                 /* 0x0A */
    u8 padc[0x20 - 0xC];
    s16 x20;                /* 0x20 */
    u8 pad22[0x32 - 0x22];
    s16 x32;                /* 0x32 */
    s16 x34;                /* 0x34 */
    u8 pad36[0x38 - 0x36];
    s32 x38;                /* 0x38 */
    s16 x3c[3];             /* 0x3C */
    s8 x42;                 /* 0x42 */
    u8 pad43[0x50 - 0x43];
    u32 x50;                /* 0x50 */
    u8 pad54[0x5A - 0x54];
    u8 x5a;                 /* 0x5A */
    u8 pad5b[0xEC - 0x5B];
    u32 xec;                /* 0xEC */
    u32 xf0;                /* 0xF0 */
    u32 xf4;                /* 0xF4 */
    u8 padf8[0x134 - 0xF8];
    s32 x134;               /* 0x134 */
    u8 pad138[0x164 - 0x138];
    f32 x164;               /* 0x164 */
    u8 pad168[0x1DC - 0x168];
    void* x1dc;             /* 0x1DC */
    u8 pad1e0[0x228 - 0x1E0];
    void* x228;             /* 0x228 */
} Unit;

/* Work area of a character task (task->work). */
typedef struct Wk {
    s16 type;               /* 0x00 */
    s16 id;                 /* 0x02 */
    u8 pad4[0x3C - 4];
    u32 x3c;                /* 0x3C */
    s32 x40;                /* 0x40 */
    s16 x44;                /* 0x44 */
    s16 x46;                /* 0x46 */
    s16 x48;                /* 0x48 */
    u8 pad4a[2];
    Unit* w;                /* 0x4C */
} Wk;

/* Task object (same layout as Task in game/task.h, work typed per owner). */
typedef struct Tk {
    void (*func)(struct Tk*);   /* 0x00 */
    struct Tk* next;            /* 0x04 */
    struct Tk* parent;          /* 0x08 */
    u8 pad0C[0x0C];
    u8 flags;                   /* 0x18 */
    u8 state;                   /* 0x19 */
    u8 pad1A[0x0A];
    Wk* work;                   /* 0x24 */
} Tk;

/* Event message: handler argument. */
typedef struct Msg {
    s16 x0;
    s16 x2;
    s16 x4;
    s16 x6;
    s32 x8;
    s32 xc;
} Msg;

/* Per-character stat block (lbl_80309DE4[12]). */
typedef struct Chr {
    s16 x0;                 /* 0x00 */
    s16 x2;                 /* 0x02 */
    s8 x4;
    s8 x5;
    s8 x6;
    u8 x7;
    s16 x8;                 /* 0x08 */
    s16 xa;                 /* 0x0A */
    u8 padc[2];
    s16 flags;              /* 0x0E */
    u32 x10;
    s32 x14;                /* 0x14 */
    s32 x18;                /* 0x18 */
    u32 bits;               /* 0x1C */
    s16 x20[4];
    s16 x28[2][3];
    s16 x34[2][3];
    s16 x40[4][4];
    s16 x60[4][4];
    s16 x80[5];
    s16 x8a[5];
    s16 x94[2][3];
    s16 xa0[2][3];
    u8 padac[12];
    s8 xb8;
    s8 xb9;
    s16 xba;
    s16 xbc[2][3];
    s16 xc8[4][4];
    s16 xe8[5];
    s16 xf2[2][3];
    s8 xfe;
    s8 xff;
} Chr;

/* Per-character state table entry (lbl_80309174[12]). */
typedef struct ChrState {
    s32 x0;
    s8 x4;
    u8 pad5;
    s16 x6;
    s8 x8;
    u8 pad9[0x17];
} ChrState;

typedef struct Lim {
    u8 pad[6];
    s16 x6;
    s16 x8;
    s16 xa;
} Lim;

/* Callback list node (GameState.head / GameState.list). */
typedef struct Callback {
    void (*fn)(void*);
    void* arg;
    struct Callback* prev;
    struct Callback* next;
    u32 flags;
} Callback;

typedef struct GameState {
    u8 pad0[8];
    Tk* x8;                 /* 0x08 */
    s32 xc;                 /* 0x0C */
    s32 x10;                /* 0x10 */
    s8 grid[9][9];          /* 0x14 */
    u8 pad65[0x68 - 0x65];
    void* x68;              /* 0x68 */
    u32 flags;              /* 0x6C */
    s16 x70;                /* 0x70 */
    s8 x72;                 /* 0x72 */
    u8 pad73[0xC4 - 0x73];
    Callback* head;         /* 0xC4 */
    Callback* list;         /* 0xC8 */
    u8 padcc[0xEC - 0xCC];
    f32 xec;                /* 0xEC */
    u8 padf0[0x180 - 0xF0];
    s32 x180;               /* 0x180 */
    s32 x184;               /* 0x184 */
    u8 pad188[0x194 - 0x188];
    s32 x194[10];           /* 0x194 */
    u32 x1bc;               /* 0x1BC */
    u32 x1c0;               /* 0x1C0 */
    u8 pad1c4[0x1D0 - 0x1C4];
} GameState;

typedef struct Slot {
    u32 flags;
    u32 x4;
    u32 x8;
    u32 xc;
    u8 pad[0x24 - 0x10];
} Slot;

typedef struct Cfg {
    s32 flag;
    s32 cnt;
    s32 v[2];
    s32 p[3][2];
} Cfg;

extern Tk* lbl_80309700[12];
extern Tk* lbl_80309E24[12];
extern Tk* lbl_80347394;
extern Chr* lbl_80309DE4[12];
extern ChrState lbl_80309174[12];
extern GameState lbl_8030A10C;
extern Slot lbl_8030A6D4[];
extern Cfg lbl_80302B10;
extern Lim* lbl_80347390;
extern void* lbl_80347398;
extern void fn_8002D684(Chr*);
extern void fn_8002D72C(Chr*);
extern void fn_8002DC14(Msg*, s16);
extern void fn_8006E75C(void*, const char*, s32);
extern Tk* fn_80021658(int);
extern Tk* fn_8001E05C(void*);
extern int fn_8001BBF8(void*);
extern int fn_8001D944(u8, void*);
extern void fn_800085EC(void*, s32, s32, s32, s32);
extern int fn_8002111C(u8, s8, int);
extern int fn_800214FC(int, s16, int);
extern void fn_8001F814();
extern void fn_8002EB4C(int, int);
extern void fn_8002ECA4(Unit*, int);
extern void fn_80032BBC(s8, s32);
extern void fn_80032B6C(s8, s32);
extern void fn_80029168(s32, s32);
extern int fn_80014C90(s8, int);

/* Function-local types (suffix = function address). */
typedef struct { u8 pad[8]; s8 x8; u8 pad9; s8 xa; u8 padb[5]; } Ent2;
typedef struct { u32 flags; s32 val; } Ent_8002EEFC;
typedef struct { u16 val; s16 time; } Rec;
typedef struct { s16 pos; s16 pad; Rec* recs; } Ent_8002F35C;
typedef struct { s16 pad0; s16 pad2; s16 timer; s16 pad6; s32 pad8; Ent_8002F35C e[1]; } Q_8002F35C;
typedef struct { s32 v[5]; } R;
typedef struct { u8 pad0[4]; void* x4; u8 pad8[0x18 - 8]; s32 x18; } Ent_800303EC;
typedef struct { s32 x0; s32 ids[1]; } Work_800304DC;
typedef struct { u8 pad[0x24]; u8 work[1]; } Node;
typedef struct {
    Tk* a;
    Tk* b;
    s16 timer; /* 0x08 */
    s16 x;     /* 0x0A */
    s16 y;     /* 0x0C */
} Work_80030B34;
typedef struct {
    Tk* a;
    Tk* b;
    s16 timer; /* 0x08 */
} Work_80030C94;

extern void fn_8002BC4C(s16);
extern void fn_80010474(s16);
extern s8 lbl_80347334;
extern void fn_80010538(s16);
extern void* fn_801E1C7C(s32);
extern void fn_801E17E0(void*);
extern void fn_8002BD88(Msg*);
extern int fn_8003146C(s8);
extern int fn_800314FC(s8);
extern void fn_800316F8(void*, s8);
extern void fn_80031580(s32 a, s8 b, s16 c, s32 d);
extern void fn_80032AF8(s8 a, u16 b);
extern void fn_8002923C(s32 id, s32 a, s32 b);
extern void fn_80020B28(Unit*);
extern int fn_80031524(int);
extern u32 fn_800215EC(u8);
extern void fn_800324B8(u8, int);
extern void fn_8003FA30(Unit*, u8);
extern s16 fn_80020094(Wk*, s16, int, int);
extern void fn_8003FB70(Tk*, int);
extern int fn_8025ECC4(void);
extern Ent2 lbl_80309730[12];
extern void fn_80081EF4(s8, int);
extern s32 fn_8007EB74(int);
extern void fn_80020B50(Tk*, s16*, s16*);
extern Q_8002F35C lbl_80302AE0;
extern s32 lbl_8034757C;
extern s32 lbl_8034737C;
extern s32 lbl_8034733C;
extern s32 lbl_80347330;
extern void fn_8029D008(s32);
extern void fn_80293310(void*, void*, f32);
extern s32 fn_8006DB94(void);
extern void fn_80017320(void);
extern void fn_800315FC(void);
extern void fn_8006D080(void*, s32);
extern void fn_8006C5A4(void);
extern void fn_8006DBDC(void);
extern int fn_8025CB24(char*, const char*, ...);
extern void fn_801DBE1C(const char*, ...);
extern s16 fn_80008274(s32);
extern void fn_8025F120(char*, const char*);
extern void fn_80061048(char*);
extern void fn_80046BB0(const char*, s32*);
extern s32 fn_80009500(void*, s32, s32);
extern s8 fn_8000F8F8(void*, char*, s32, s32, s32);
extern s32 fn_8006801C(Tk*, s16);
extern void fn_8006DC6C(void);
extern s16 fn_80068348(s16);
extern char lbl_802AD1D0[];
extern void fn_80061F58(void*, int, int);
extern void fn_80226D14(void);
extern void fn_801D0F80(int);
extern void fn_801D22CC(void);
extern void fn_801DBCD4(void);
extern void fn_80060AB4(void);
extern s32 lbl_802DBF38[];
extern void fn_802281BC(int);
extern u8 lbl_80309EC8[0x244];
extern u8 lbl_80309E5C[0x2c];
extern struct { u8 pad[0x88]; u32 flags; } lbl_80310B3C;
extern s32 lbl_803472EC;
extern s32 lbl_803472F8;
extern s32 lbl_803472F4;
extern s32 lbl_803472F0;
extern f32 lbl_80309168[3];
extern s32 lbl_80309118[20];
extern void* memset(void*, int, u32);
extern void fn_8006EB04(void);
extern char lbl_802AD0F8[];
extern int fn_80068128(void);
extern void fn_80068190(char*);
extern void fn_8006C8DC(char*, char*);
extern void fn_80021934(char*, char*);
extern void fn_80067E8C(char*, char*);
extern s32 lbl_80346BB8;
extern s16 lbl_803097F0[];
extern void fn_80227068(int);
extern void fn_800096BC(void);
extern void fn_801CBB9C(f32);
extern void fn_8006C710(int, int);
extern void fn_8006C5B4(void);
extern int fn_8006D1C4(void);
extern void fn_80226DC4(void);
extern void* lbl_803475A8;
extern Node* fn_802268E8(void*, void*);
extern void fn_8000CB44(void);
extern void fn_8006B3EC(void);
extern void fn_80014BA8(void);
extern void fn_800149AC(void);
extern void fn_8022642C(void);
extern void fn_8022DCC4(void);
extern void fn_80014784(void);
extern void fn_8006B71C(void);
extern void fn_8007651C(void);
extern s8 fn_8001E910(Tk*);
extern void fn_8001D14C(Unit*);
extern int fn_800207C8(Tk*);
extern void fn_8001DCA0(Unit*);

/* forward declarations */
extern void fn_8002F188(Tk* o, u32* out);
extern void fn_80030E5C(Tk* task);

static inline void ChrSetTimer(s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 0x200;
    e->bits |= 0x40000;
    e->x2 = lbl_80309700[i]->work->x3c;
    e->x0 = e->x2;
}

static inline void ChrBoostX94(s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 8;
    e->bits |= 0x100000;
    e->xa0[0][0] = e->xf2[0][0] / 4;
    e->x94[0][0] += e->xa0[0][0];
    e->xa0[0][1] = e->xf2[0][1] / 4;
    e->x94[0][1] += e->xa0[0][1];
}

static inline void ChrBoostX80(s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 4;
    e->bits |= 0x200000;
    e->x8a[4] = e->xe8[4] / 2;
    e->x80[4] += e->x8a[4];
}

static inline void Acc2(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    s32 v = e->x14;
    v += a->x8;
    if (e->x18 < v) v = e->x18;
    e->x14 = v;
}

static inline void AccB(Chr* e, s32 d) {
    s16 v = e->xfe + d;
    if (e->xff < v) v = e->xff;
    e->xfe = v;
}

static inline void Acc2B(Chr* e, s32 d) {
    s32 v = e->x14;
    v += d;
    if (e->x18 < v) v = e->x18;
    e->x14 = v;
}

void fn_8002C010(Msg* a, s16 i) {
    ChrSetTimer(i);
    ChrBoostX94(i);
    ChrBoostX80(i);
}

void fn_8002C0FC(Msg* a, s16 i) {
    Tk* t = lbl_80309700[i];
    Chr* e = lbl_80309DE4[i];
    if (t->work->x46 != -1) {
        e->bits |= 0x80;
        e->flags &= ~0x200;
        e->bits &= ~0x40000;
        e->x2 = 0;
        e->x0 = 0;
        e->bits &= ~0x400;
    }
    fn_8002DC14(a, i);
}

void fn_8002C188(Msg* a, s16 i) {
    fn_8002DC14(a, i);
}

void fn_8002C1A8(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->bits |= 0x1000000;
    e->bits |= 0x400;
    e->bits |= 0x40000;
    e->flags |= 0x200;
    e->x2 = lbl_80309700[i]->work->x3c;
    e->x0 = e->x2;
}

static inline void Acc(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    s16 v = e->xfe + a->x8;
    if (e->xff < v) v = e->xff;
    e->xfe = v;
}

void fn_8002C210(Msg* a, s16 i) {
    Acc(a, i);
    lbl_80309DE4[i]->bits |= 0x10;
    lbl_80309DE4[i]->bits |= 4;
    lbl_80309700[i]->work->x44 = 0x30;
}

void fn_8002C28C(Msg* a, s16 i) {
    lbl_80309DE4[i]->bits |= 0x400000;
}

void fn_8002C2B0(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    fn_8002DC14(a, i);
    if (lbl_80309700[i]->work->x46 != -1) {
        e->bits &= ~0x400;
        if (e->bits & 0x1000000) {
            e->bits &= ~0x1000000;
            e->flags &= ~0x200;
            e->bits &= ~0x40000;
            e->x2 = 0;
            e->x0 = 0;
        }
        e->bits |= 0x1000;
    }
}

void fn_8002C360(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    fn_8002DC14(a, i);
    if (lbl_80309700[i]->work->x46 != -1) {
        e->bits &= ~0x400;
        if (e->bits & 0x1000000) {
            e->bits &= ~0x1000000;
            e->flags &= ~0x200;
            e->bits &= ~0x40000;
            e->x2 = 0;
            e->x0 = 0;
        }
        e->bits |= 0x800;
        e->bits &= ~1;
    }
}

void fn_8002C41C(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    fn_8002DC14(a, i);
    if (lbl_80309700[i]->work->x46 != -1) {
        e->bits |= 0x400;
        e->bits &= ~1;
        e->bits &= ~0x1000;
    }
}

void fn_8002C4A0(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    fn_8002DC14(a, i);
    if (lbl_80309700[i]->work->x46 != -1) {
        e->x14 = 0;
        fn_8002BC4C(i);
    }
}

void fn_8002C51C(Msg* a, s16 i) {
    AccB(lbl_80309DE4[i], a->xc);
    Acc2B(lbl_80309DE4[i], a->x8);
    fn_80010474(i);
}

void fn_8002C5A4(Msg* a, s16 i) {
    Acc(a, i);
}

void fn_8002C5E8(Msg* a, s16 i) {
    lbl_80309DE4[i]->bits |= 0x10;
    lbl_80309DE4[i]->bits |= 4;
}

void fn_8002C61C(Msg* a, s16 i) {
    if (i < 4) {
        Acc2(a, i);
        fn_80010474(i);
        a->x2 = 30;
    } else {
        fn_8002DC14(a, i);
    }
}

void fn_8002C698(Msg* a, s16 i) {
    fn_8002DC14(a, i);
}

void fn_8002C6B8(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    if (e->bits & 0x800) {
        e->bits |= 0x2000000;
    }
    lbl_80309DE4[i]->bits &= ~0x100;
    lbl_80309DE4[i]->bits &= 0xFFF7A17F;
    e->flags &= ~0x100;
    fn_8002D684(e);
    if (e->flags & 4) {
        e->x8a[4] += e->xe8[4] / 2;
        e->x80[4] += e->x8a[4];
    }
    if (e->flags & 8) {
        e->xa0[0][0] += e->xf2[0][0] / 4;
        e->x94[0][0] += e->xa0[0][0];
        e->xa0[0][1] += e->xf2[0][1] / 4;
        e->x94[0][1] += e->xa0[0][1];
    }
    Acc2(a, i);
    fn_80010474(i);
    a->x2 = 30;
}

void fn_8002C810(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->bits |= 4;
    e->xa = 100 - e->x8;
    e->x8 = 100;
    if (i < 4) {
        lbl_80309DE4[i]->bits |= 0x800000;
    } else {
        lbl_80309DE4[i]->bits |= 2;
    }
}

void fn_8002C874(Msg* a, s16 i) {
    fn_8002DC14(a, i);
}

void fn_8002C894(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    int k;
    e->bits |= 0x40;
    for (k = 0; k < 16; k++) {
        e->x40[0][k] = 0;
    }
}

static inline void Lm(Msg* a) {
    Lim* l = lbl_80347390;
    s32 v = l->x8 + a->x8;
    if (l->x6 < (s16)v) v = l->x6;
    l->x8 = v;
    lbl_80347390->xa = v;
}

void fn_8002C8FC(Msg* a, s16 i) {
    lbl_80309DE4[i]->bits |= 1;
    Lm(a);
}

void fn_8002C950(Msg* a, s16 i) {
    lbl_80309DE4[i]->bits |= 0x10;
}

void fn_8002C974(Msg* a, s16 i) {
    lbl_80309DE4[i]->bits |= 8;
}

void fn_8002C998(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->bits |= 2;
    e->bits |= 1;
    e->xa = 100 - e->x8;
    e->x8 = 100;
}

void fn_8002C9DC(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 0x800;
    e->xa = 100 - e->x8;
    e->x8 = 100;
}

void fn_8002CA14(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 0x400;
    e->xa += 10;
    e->x8 += e->xa;
}

void fn_8002CA54(Msg* a, s16 i) {
    Lm(a);
}

void fn_8002CA88(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 0x200;
    e->bits |= 0x40000;
    e->x2 = lbl_80309700[i]->work->x3c;
    e->x0 = e->x2;
}

void fn_8002CAD8(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    s16 old;
    if (e->bits & 0x800) {
        e->bits |= 0x2000000;
    }
    e->bits &= 0xFFF7A17F;
    old = e->flags;
    e->flags &= ~0x100;
    fn_8002D684(e);
    if ((old >> 2) & 1) {
        e->flags |= 4;
        e->x8a[4] += e->xe8[4] / 2;
        e->x80[4] += e->x8a[4];
    }
    if (old & 8) {
        e->flags |= 8;
        e->xa0[0][0] += e->xf2[0][0] / 4;
        e->x94[0][0] += e->xa0[0][0];
        e->xa0[0][1] += e->xf2[0][1] / 4;
        e->x94[0][1] += e->xa0[0][1];
    }
}

void fn_8002CBF8(Msg* a, s16 i) {
    Chr* e;
    s32 lim, v;
    lbl_80309DE4[i]->bits &= 0x8;
    e = lbl_80309DE4[i];
    lim = e->x18;
    v = e->x14 + a->x8;
    if (lim < v) v = lim;
    e->x14 = v;
    fn_80010474(i);
    a->x2 = 30;
}

void fn_8002CC74(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    fn_8002D684(e);
    e->flags &= ~0x8;
    e->flags &= ~0x4;
    e->bits &= ~0x100000;
    e->bits &= ~0x200000;
    e->bits &= ~0x400;
    if (e->bits & 0x1000000) {
        e->bits &= ~0x1000000;
        e->flags &= ~0x200;
        e->bits &= ~0x40000;
        e->x2 = 0;
        e->x0 = 0;
    }
    e->flags |= 0x100;
    e->flags &= ~0x4;
    e->flags &= ~0x8;
    e->bits |= 0x80000;
    e->xa0[0][0] -= e->xf2[0][0] / 4;
    e->xa0[0][1] -= e->xf2[0][1] / 4;
    e->xa0[0][2] -= e->xf2[0][2] / 4;
    e->xa0[1][0] -= e->xf2[1][0] / 4;
    e->xa0[1][1] -= e->xf2[1][1] / 4;
    e->xa0[1][2] -= e->xf2[1][2] / 4;
    fn_8002D72C(e);
}

void fn_8002CDF0(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 0x80;
    e->x8a[4] -= e->xe8[4] / 2;
    e->x80[4] += e->x8a[4];
}

void fn_8002CE40(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 0x40;
    e->xa0[0][1] -= e->xf2[0][1] / 4;
    e->x94[0][1] += e->xa0[0][1];
}

void fn_8002CE8C(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 0x20;
    e->xa0[0][0] -= e->xf2[0][0] / 4;
    e->x94[0][0] += e->xa0[0][0];
}

void fn_8002CED8(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 0x10;
    e->xa0[0][0] += e->xf2[0][0] / 4;
    e->xa0[0][1] += e->xf2[0][1] / 4;
    e->xa0[0][2] += e->xf2[0][2] / 4;
    e->xa0[1][0] += e->xf2[1][0] / 4;
    e->xa0[1][1] += e->xf2[1][1] / 4;
    e->xa0[1][2] += e->xf2[1][2] / 4;
    fn_8002D72C(e);
}

void fn_8002CFA8(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 8;
    e->bits |= 0x100000;
    e->xa0[0][0] = e->xf2[0][0] / 4;
    e->x94[0][0] += e->xa0[0][0];
    e->xa0[0][1] = e->xf2[0][1] / 4;
    e->x94[0][1] += e->xa0[0][1];
}

void fn_8002D018(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 4;
    e->bits |= 0x200000;
    e->x8a[4] = e->xe8[4] / 2;
    e->x80[4] += e->x8a[4];
}

void fn_8002D06C(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 2;
    e->xa0[0][1] += e->xf2[0][1] / 4;
    e->x94[0][1] += e->xa0[0][1];
}

void fn_8002D0B8(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->flags |= 8;
    e->xa0[0][0] += e->xf2[0][0] / 4;
    e->x94[0][0] += e->xa0[0][0];
}

void fn_8002D104(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    if ((e->bits & 0x100000) || (e->bits & 0x200000)) {
        fn_8002D684(e);
    }
    if (e->bits & 0x80000) {
        fn_8002D684(e);
        e->xa0[0][0] -= e->xf2[0][0] / 4;
        e->xa0[0][1] -= e->xf2[0][1] / 4;
        e->xa0[0][2] -= e->xf2[0][2] / 4;
        e->xa0[1][0] -= e->xf2[1][0] / 4;
        e->xa0[1][1] -= e->xf2[1][1] / 4;
        e->xa0[1][2] -= e->xf2[1][2] / 4;
        fn_8002D72C(e);
    }
    e->flags &= ~0x8;
    e->flags &= ~0x4;
    e->flags &= ~0x200;
    e->bits &= ~0x100000;
    e->bits &= ~0x200000;
    e->bits &= ~0x40000;
    e->x2 = 0;
    e->x0 = 0;
    fn_8002DC14(a, i);
}

void fn_8002D27C(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    if ((e->bits & 0x100000) || (e->bits & 0x200000)) {
        fn_8002D684(e);
    }
    if (e->bits & 0x80000) {
        fn_8002D684(e);
        e->xa0[0][0] -= e->xf2[0][0] / 4;
        e->xa0[0][1] -= e->xf2[0][1] / 4;
        e->xa0[0][2] -= e->xf2[0][2] / 4;
        e->xa0[1][0] -= e->xf2[1][0] / 4;
        e->xa0[1][1] -= e->xf2[1][1] / 4;
        e->xa0[1][2] -= e->xf2[1][2] / 4;
        fn_8002D72C(e);
    }
    e->flags &= ~0x8;
    e->flags &= ~0x4;
    e->flags &= ~0x200;
    e->bits &= ~0x100000;
    e->bits &= ~0x200000;
    e->bits &= ~0x40000;
    e->x2 = 0;
    e->x0 = 0;
}

void fn_8002D3D0(void) {
}

void fn_8002D3D4(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->bits &= ~0x400;
    if (e->bits & 0x1000000) {
        e->bits &= ~0x1000000;
        e->flags &= ~0x200;
        e->bits &= ~0x40000;
        e->x2 = 0;
        e->x0 = 0;
    }
    e->bits |= 0x1000;
}

void fn_8002D43C(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->bits &= ~0x400;
    if (e->bits & 0x1000000) {
        e->bits &= ~0x1000000;
        e->flags &= ~0x200;
        e->bits &= ~0x40000;
        e->x2 = 0;
        e->x0 = 0;
    }
    e->bits |= 0x200;
}

void fn_8002D4A4(Msg* a, s16 i) {
    Chr* e = lbl_80309DE4[i];
    e->bits &= ~0x400;
    if (e->bits & 0x1000000) {
        e->bits &= ~0x1000000;
        e->bits &= ~0x40000;
        e->flags &= ~0x200;
        e->x2 = 0;
        e->x0 = 0;
    }
    e->bits |= 0x800;
    e->bits &= ~1;
}

void fn_8002D518(Msg* a, s16 i) {
    Chr* c = lbl_80309DE4[i];
    c->bits |= 0x400;
    c->bits &= ~1;
    c->bits &= ~0x1000;
}

void fn_8002D554(Msg* a, s16 i) {
    if (lbl_80309700[i]->work->x46 != -1) {
        Chr* c = lbl_80309DE4[i];
        if (c->bits & 0x800) {
            c->bits |= 0x2000000;
        }
        c->flags = 0;
        c->bits &= 8;
        c->bits |= 0x4000;
        c->x4 = 3;
        c->x2 = 0;
        c->x0 = 0;
        fn_8002D684(c);
    }
    fn_8002DC14(a, i);
}

void fn_8002D60C(Msg* a, s16 i) {
    Chr* c = lbl_80309DE4[i];
    if (c->bits & 0x800) {
        c->bits |= 0x2000000;
    }
    c->flags = 0;
    c->bits &= 8;
    c->bits |= 0x4000;
    c->x4 = 3;
    c->x2 = 0;
    c->x0 = 0;
    fn_8002D684(c);
}

void fn_8002D684(Chr* c) {
    int i;
    for (i = 0; i < 6; i++) c->x34[0][i] = 0;
    for (i = 0; i < 16; i++) c->x60[0][i] = 0;
    for (i = 0; i < 5; i++) c->x8a[i] = 0;
    for (i = 0; i < 6; i++) c->xa0[0][i] = 0;
    fn_8002D72C(c);
}

void fn_8002D72C(Chr* c) {
    s16 v;
    s8 d;
    s8 w;
    s16 e;
    int i;
    int k;

    v = c->x2 + c->xb8;
    if (v < 0) v = 0;
    c->x0 = v;

    d = c->xb9;
    w = c->x6 + d;
    if (w < 1) w = 1;
    else if (w > d * 2) w = d * 2;
    c->x5 = w;

    e = c->xba;
    v = c->xa + e;
    if (v < 1) v = 1;
    else if (v > e * 2) v = e * 2;
    c->x8 = v;

    k = 0;
    for (i = 0; i < 4; i += 2) {
        v = c->x34[k][0] + c->xbc[k][0];
        if (v < 0) v = 0;
        else if (v > 255) v = 255;
        c->x28[k][0] = v;
        v = c->x34[k][1] + c->xbc[k][1];
        if (v < 0) v = 0;
        else if (v > 255) v = 255;
        c->x28[k][1] = v;
        v = c->x34[k][2] + c->xbc[k][2];
        if (v < 0) v = 0;
        else if (v > 255) v = 255;
        c->x28[k][2] = v;
        k++;
    }
    k = 0;
    for (i = 0; i < 12; i += 3) {
        v = c->x60[k][0] + c->xc8[k][0];
        if (v < 0) v = 0;
        else if (v > 255) v = 255;
        c->x40[k][0] = v;
        v = c->x60[k][1] + c->xc8[k][1];
        if (v < 0) v = 0;
        else if (v > 255) v = 255;
        c->x40[k][1] = v;
        v = c->x60[k][2] + c->xc8[k][2];
        if (v < 0) v = 0;
        else if (v > 255) v = 255;
        c->x40[k][2] = v;
        v = c->x60[k][3] + c->xc8[k][3];
        if (v < 0) v = 0;
        else if (v > 255) v = 255;
        c->x40[k][3] = v;
        k++;
    }
    for (i = 0; i < 5; i++) {
        e = c->xe8[i];
        v = c->x8a[i] + e;
        if (v < 1) v = 1;
        else if (v > e * 2) v = e * 2;
        c->x80[i] = v;
    }
    k = 0;
    for (i = 0; i < 4; i += 2) {
        e = c->xf2[k][0];
        v = c->xa0[k][0] + e;
        if (v < 1) v = 1;
        else if (v > e * 2) v = e * 2;
        c->x94[k][0] = v;
        e = c->xf2[k][1];
        v = c->xa0[k][1] + e;
        if (v < 1) v = 1;
        else if (v > e * 2) v = e * 2;
        c->x94[k][1] = v;
        e = c->xf2[k][2];
        v = c->xa0[k][2] + e;
        if (v < 1) v = 1;
        else if (v > e * 2) v = e * 2;
        c->x94[k][2] = v;
        k++;
    }
}

void fn_8002DA24(Msg* a, s16 i) {
    if (lbl_80309700[i]->work->x46 != -1) {
        lbl_80309DE4[i]->x14 = 0;
        fn_8002BC4C(i);
    } else {
        fn_8002DC14(a, i);
    }
}

void fn_8002DA88(Msg* a, s16 i) {
    lbl_80309DE4[i]->x14 = 0;
    fn_8002BC4C(i);
}

void fn_8002DAC8(Msg* a, s16 i) {
    Tk* t = lbl_80309700[i];
    Chr* c = lbl_80309DE4[i];
    if (t->work->x46 != -1) {
        c->bits |= 0x80;
        c->flags &= ~0x200;
        c->bits &= ~0x40000;
        c->x2 = 0;
        c->x0 = 0;
        c->bits &= ~0x400;
    }
    fn_8002DC14(a, i);
}

void fn_8002DB54(Msg* a, s16 i) {
    Chr* c = lbl_80309DE4[i];
    c->bits |= 0x80;
    c->flags &= ~0x200;
    c->bits &= ~0x40000;
    c->x2 = 0;
    c->x0 = 0;
    c->bits &= ~0x400;
}

void fn_8002DBA8(Msg* a, s16 i) {
    Chr* c = lbl_80309DE4[i];
    s32 mx;
    s32 hp = c->x14;
    mx = c->x18;
    hp += a->x8;
    if (mx < hp) hp = mx;
    c->x14 = hp;
    fn_80010474(i);
    a->x2 = 30;
}

void fn_8002DC14(Msg* a, s16 i) {
    Chr* c;
    s32 hp;
    s32 dmg;
    fn_80010538(i);
    c = lbl_80309DE4[i];
    hp = c->x14;
    if (lbl_80309174[i].x8 != 0) {
        if (c->bits & 0x800) {
            c->bits |= 0x2000000;
        }
        c->bits &= ~0xC00;
        if (c->bits & 0x1000000) {
            c->bits &= ~0x1000000;
            c->bits &= ~0x40000;
            c->flags &= ~0x200;
            c->x2 = 0;
            c->x0 = 0;
        }
    }
    dmg = a->x8;
    if (c->bits & 0x800) {
        lbl_80309174[i].x0 = 3;
        lbl_80309174[i].x4 = -1;
        lbl_80309174[i].x6 = 0;
    }
    hp -= dmg;
    if (hp < 0) hp = 0;
    c->x14 = hp;
    fn_8002BC4C(i);
    fn_80010474(i);
    a->x2 = 0;
    lbl_80309DE4[i]->x10 |= 1;
    if (lbl_80309174[lbl_80347334].x0 == 1) {
        lbl_80309DE4[i]->x10 |= 2;
    }
}

void fn_8002DD88(void) {}

void fn_8002DD8C(s16 a, s16 b, s16 c) {
    Wk* w = lbl_80309700[a]->work;
    Msg* m;
    Msg* n;
    m = fn_801E1C7C(16);
    m->x0 = a;
    m->x8 = w->x3c;
    m->xc = w->x40;
    m->x2 = b;
    m->x4 = 15;
    m->x6 = c;
    fn_8002BD88(m);
    fn_801E17E0(m);
    switch (c) {
    default:
        break;
    case 0x3d:
    case 0x3e:
        if (a == lbl_80347334) {
            m->x6 = 0;
            n = fn_801E1C7C(16);
            n->x0 = lbl_80347334;
            n->x8 = lbl_80309DE4[lbl_80347334]->x14;
            n->x2 = b;
            n->x4 = 15;
            n->x6 = 0;
            fn_8002BD88(n);
            fn_801E17E0(n);
        }
        break;
    case 0x2c:
        m->x6 = 0;
        w = lbl_80309700[lbl_80347334]->work;
        n = fn_801E1C7C(16);
        n->x0 = lbl_80347334;
        n->x8 = w->x3c;
        n->x2 = b;
        n->x4 = 15;
        n->x6 = 31;
        fn_8002BD88(n);
        fn_801E17E0(n);
        break;
    }
}

void fn_8002DF0C(Tk* obj, s32 clear, s16 p) {
    Unit* c = obj->work->w;
    s16 i;

    if (p != 0) {
        fn_80031580(c->id, 1, p, 1);
    } else {
        fn_80032BBC(c->id, 1);
    }

    if (c->x1dc != 0) {
        switch (c->x42) {
        case 6:
            if (c->x38 >= 0) {
                fn_80029168(c->id, c->x38);
            }
            fn_80032B6C(c->id, 6);
            fn_8002923C(c->id, 0xFD, 1);
            break;
        case 2:
            fn_80032B6C(c->id, 3);
            if (c->x38 >= 0) {
                fn_80029168(c->id, c->x38);
            } else {
                fn_80029168(c->id, 0);
            }
            break;
        case 1:
            if (c->x38 >= 0) {
                fn_80029168(c->id, -c->x38);
            } else {
                fn_80029168(c->id, 0);
            }
        case 0:
            fn_80032B6C(c->id, 6);
            fn_8002923C(c->id, 0x700, 1);
            break;
        case 8:
            if (c->x38 >= 0) {
                fn_80029168(c->id, c->x38);
            } else {
                fn_80029168(c->id, 0);
            }
            fn_80032B6C(c->id, 6);
            fn_8002923C(c->id, 0xFF, 1);
            break;
        case 4:
            if (c->x38 >= 0) {
                fn_80032B6C(c->id, 4);
                fn_80029168(c->id, -c->x38);
            } else {
                fn_80032B6C(c->id, 5);
            }
            fn_8002923C(c->id, 0x7FB, 0);
            fn_80032AF8(c->id, 4);
            break;
        case 5:
            if (c->x38 >= 0) {
                fn_80032B6C(c->id, 4);
                fn_80029168(c->id, -c->x38);
            } else {
                fn_80032B6C(c->id, 5);
            }
            fn_8002923C(c->id, 0x7FF, 0);
            fn_80032AF8(c->id, 2);
            break;
        case 3:
            if (c->x38 >= 0) {
                fn_80032B6C(c->id, 4);
                fn_80029168(c->id, -c->x38);
            } else {
                fn_80032B6C(c->id, 5);
            }
            for (i = 0; i < 3; i++) {
                switch (c->x3c[i]) {
                case 3:
                case 4:
                case 62:
                    fn_80032AF8(c->id, 1);
                    break;
                case 63:
                    fn_80032AF8(c->id, 0x100);
                case 9:
                case 10:
                case 69:
                    fn_80032AF8(c->id, 8);
                    break;
                case 11:
                case 70:
                    fn_80032AF8(c->id, 0x10);
                    break;
                case 12:
                case 13:
                case 71:
                    fn_80032AF8(c->id, 0x20);
                    break;
                case 14:
                case 72:
                    fn_80032AF8(c->id, 0x40);
                    break;
                case 15:
                    fn_80032AF8(c->id, 1);
                    fn_80032AF8(c->id, 8);
                    fn_80032AF8(c->id, 0x20);
                    break;
                case 20:
                    fn_80032AF8(c->id, 0x400);
                    break;
                case 21:
                    fn_80032AF8(c->id, 0x200);
                    break;
                case 26:
                case 73:
                    fn_80032AF8(c->id, 0x80);
                    break;
                case 27:
                case 28:
                    fn_80032B6C(c->id, 6);
                    fn_8002923C(c->id, 2, 1);
                    break;
                case 33:
                    fn_80032AF8(c->id, 0x100);
                    break;
                }
                c->x3c[i] = -1;
            }
            break;
        }
    }
    if (clear != 0) {
        c->xf0 &= ~0x08000000;
    }
    c->x38 = -1;
    c->x42 = -1;
}

void fn_8002E320(Tk* t, s8 b) {
    s32 cnt = 0;
    int flag = 0;
    Unit* p = t->work->w;
    s8 k;
    switch (p->x42) {
    case 5:
        if (p->x38 > 0) flag = 1;
        break;
    default:
        flag = fn_8003146C(p->x34);
        break;
    }
    if (flag || fn_800314FC(p->x34)) {
        cnt = p->x38;
        if (cnt < 0) cnt = 0;
        fn_80032BBC(p->id, 1);
        fn_80032B6C(p->id, 4);
        if (p->x34 == 0x42 && (s8)p->id < 4) flag = 0;
        if (flag) cnt = cnt * -1;
        fn_80029168(p->id, cnt);
        p->x38 = -1;
    } else if (b != 9) {
        for (k = 0; k < 3; k++) {
            if (p->x3c[k] >= 0) cnt = (s8)(cnt + 1);
        }
        if ((s8)cnt == 0) b = 7;
    }
    if (b != 2 && !(p->xf0 & 0x4000000)) {
        fn_800316F8(t, b);
    }
}

void fn_8002E48C(Tk* o) {
    s8 v = 2;
    Unit* w = o->work->w;
    s8 i;
    if (!(w->xec & 0x100000)) {
        if (w->x1dc != 0) {
            if (w->xf0 & 0x8000000) {
                for (i = 0; i < 3; i++) {
                    switch (w->x3c[i]) {
                    case 29:
                    case 30:
                        v = 6;
                        i = 99;
                        break;
                    case 16:
                        v = 0;
                        i = 99;
                        break;
                    case 17:
                        v = 1;
                        i = 99;
                        break;
                    case 27:
                    case 28:
                    case 47:
                        v = 8;
                        i = 99;
                        break;
                    case 8:
                        v = 4;
                        i = 99;
                        break;
                    case 6:
                        v = 5;
                        i = 99;
                        break;
                    case 3: case 4: case 5: case 7: case 9: case 10: case 11: case 12:
                    case 13: case 14: case 15: case 20: case 21: case 26: case 33:
                    case 44: case 48: case 49: case 62: case 63: case 68: case 69:
                    case 70: case 71: case 72: case 73:
                        v = 3;
                        break;
                    case -1:
                        break;
                    default:
                        v = 2;
                        break;
                    }
                }
                if (w->xf4 & 0x800000) v = 9;
                w->x42 = v;
                if (!(w->xf0 & 0x800000)) fn_8002E320(o, v);
            }
        } else {
            if (!(w->xf0 & 0x800000)) {
                fn_80032BBC(w->id, 1);
            } else {
                w->xf0 &= ~0x800000;
                w->xf0 |= 0x8000000;
            }
        }
    }
}

inline int NoPending(Unit* w, u32 fl) {
    s8 j;
    int r;
    if (fl & 0x08000000) {
        for (j = 0; j < 3; j++) {
            if (w->x3c[j] > 0) {
                r = 0;
                return r;
            }
        }
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

int fn_8002E5D0(Tk* o) {
    u32 flags = 0;
    int c;
    Tk* o2;
    Unit* w2;
    Unit* w = o->work->w;
    int a = 0;
    u8 x4;
    int b = 0;
    u8 save;
    Unit* w3;
    int r;

    fn_80020B28(w);
    o2 = fn_8001E05C(o);
    x4 = w->x4;
    w2 = o2->work->w;
    if (o->work->w->x1dc != 0) {
        c = fn_80031524(o->work->w->x32);
    } else if (lbl_80347394->work->x3c & 0x400) {
        c = 1;
    } else {
        c = 0;
    }
    if (w2->x1dc != 0) {
        b = 1;
    }
    flags = w2->xf4;

    switch (w->x6) {
    case 24:
        if (w->xec & 0x80) {
            save = w->x4;
            w->x4 = w->x5a;
            {
                Tk* p = fn_8001E05C(o);
                u32* q = &p->work->w->xf4;
                *q = 0;
                fn_8002F188(p, q);
            }
            fn_80030E5C(o);
            w->x4 = save;
        } else {
            fn_80030E5C(o);
        }
        break;
    case 29:
        if (w->xec & 0x80) {
            save = w->x4;
            w->x4 = w->x5a;
            o2 = fn_8001E05C(o);
            w2 = o2->work->w;
        }
        flags = 0;
        fn_8002F188(o2, &flags);
        x4 = w->x4;
        if (fn_800215EC(x4) != 0) {
            if (b != 0) {
                fn_8002ECA4(w, x4);
                if (w2->x50 & 0x40000000) {
                    w2->xf0 |= 0x04000000;
                }
                w2->xf4 = flags;
                if ((s8)w->x4 == (s8)w->id && w2->x38 <= 0 && w2->x3c[0] < 0 && w2->x3c[1] < 0 &&
                    w2->x3c[2] < 0) {
                    a = 1;
                    c = 0;
                }
            }
            if (a == 0 && fn_8003146C(w2->x34)) {
                a = fn_8002111C(w->x4, w->id, w->x6);
            }
            if (c != 0) {
                if (NoPending(w2, flags)) {
                    w2->xf4 |= 0x00800000;
                }
                if (a == 0) {
                    a = fn_8002111C(w->x4, w->id, w->x6);
                    if (a != 0) {
                        w2->xec |= 0x20;
                    }
                }
            }
            if (a == 0 && fn_8003146C(w2->x34)) {
                a = fn_8002111C(w->x4, w->id, w->x6);
            }
            if (a == 0 && (s8)w->x4 == (s8)w->id) {
                fn_8002E48C(o2);
            }
        }
        if (w->xec & 0x80) {
            w->x4 = save;
        }
        break;
    case 4:
    case 5:
    case 8:
    case 9:
    case 10:
        if (!(w->xec & 0x00100000) && b != 0) {
            fn_8002ECA4(w, x4);
            w3 = o2->work->w;
            w3->xf4 &= 0x7BFFFFFF;
            w3->xf4 &= ~0x01000000;
            if (fn_80014C90(w3->id, 1)) {
                w3->xf4 |= 0x80000000;
            }
            flags = w2->xf4;
            if (w2->x50 & 0x80000000) {
                flags |= 0x01000000;
            } else if (w2->x50 & 0x40000000) {
                w2->xf0 |= 0x04000000;
            } else if (w2->x50 & 0x20000000) {
                flags |= 0x04000000;
            }
            w2->xf4 = flags;
        }
        if (w->xec & 0x00100000) {
            fn_8002EB4C(x4, w->id);
            w->xec &= ~0x00100000;
        } else if (flags & 0x01000000) {
            if (fn_800214FC(x4, 0xd, w->id) == 0) {
                fn_8002111C(x4, w->id, w->x6);
            }
            fn_800324B8(x4, 0);
            fn_8003FA30(w, x4);
        } else {
            if (flags & 0x04000000) {
                switch (w->x6) {
                case 5:
                    r = fn_800214FC(x4, 0xa, w->id);
                    break;
                case 4:
                case 8:
                    r = fn_800214FC(x4, 9, w->id);
                    break;
                default:
                    r = fn_8002111C(x4, w->id, w->x6);
                    break;
                }
                if (lbl_80347394 != NULL) {
                    lbl_80347394->work->x3c &= ~0x1000;
                }
            } else {
                r = fn_8002111C(x4, w->id, w->x6);
            }
            if (c != 0) {
                if (flags & 0x08000000) {
                    w2->xf4 |= 0x00800000;
                } else if (r == 0) {
                    r = fn_8002111C(x4, w->id, w->x6);
                }
            }
            if (r == 0) {
                fn_8002111C(x4, w->id, w->x6);
            }
        }
        break;
    case 17:
        if (fn_80014C90(w->id, 0x1000)) {
            fn_800324B8(w->id, 0);
        }
        break;
    }
    return 1;
}

void fn_8002EB4C(int o, int arg) {
    s16 k;
    Tk* p;
    s16 pick = -1;
    Unit* w;
    s16 tbl[2] = {12, 13};
    s16 r;
    s16* tp;
    s16 i;
    p = fn_80021658(o);
    w = p->work->w;
    tp = tbl;
    w->xa = w->x6;
    for (i = 0; i < 2; i++) {
        r = fn_80020094(p->work, *tp, -1, 1);
        if (r >= 0) break;
        tp++;
    }
    if (r < 0) pick = 3;
    while (pick < 0) {
        k = fn_8025ECC4() % 2;
        if (fn_80020094(p->work, tbl[k], -1, 1) >= 0) pick = tbl[k];
    }
    fn_800214FC(o, pick, arg);
    w->xec |= 8;
    if (w->x164 > -1.0f) fn_8003FB70(p, arg);
    switch (k) {
    case 0: w->x20 = 0x34; break;
    case 1: w->x20 = 0x35; break;
    }
    fn_8001F814(o, arg);
}

void fn_8002ECA4(Unit* a, int b) {
    Tk* p;
    s8 idx;
    Unit* w;
    s32 v;
    int ok;
    s8 j;
    p = fn_80021658(b);
    idx = b;
    w = p->work->w;
    if (lbl_80309700[idx] != 0 && w->x1dc != 0) {
        v = lbl_80309DE4[w->id]->x14;
        fn_80081EF4(idx, 1);
        w->xf0 |= 0x8000000;
        w->x38 = fn_8007EB74(idx);
        w->x3c[0] = lbl_80309700[idx]->work->x44;
        w->x3c[1] = lbl_80309700[idx]->work->x46;
        w->x3c[2] = lbl_80309700[idx]->work->x48;
        w->x34 = a->x32;
        switch (a->x6) {
        case 0x18:
            w->xf0 |= 0x100;
            break;
        default:
            w->xf0 &= ~0x100;
            break;
        }
        w->x50 &= 0x0FFFFFFF;
        if ((s8)b != a->id) {
            switch (lbl_80309730[idx].x8) {
            case 0:
                w->x50 |= 0x80000000;
                break;
            case 5:
                ok = 0;
                if (v > w->x38) {
                    for (j = 0; j < 3; j++) {
                        if (w->x3c[j] == 5 || w->x3c[j] == 6 || w->x3c[j] == 0x44) {
                            ok = 1;
                            break;
                        }
                    }
                } else {
                    if (v == 0) ok = 0; else ok = 1;
                }
                if (ok) w->x50 |= 0x40000000;
                break;
            }
            if (lbl_80309730[idx].xa) w->x50 |= 0x20000000;
        }
    }
}

int fn_8002EEB0(Tk* o) {
    Unit* w = o->work->w;
    if (w->x1dc != 0) {
        return fn_80031524(w->x32);
    }
    return (lbl_80347394->work->x3c >> 10) & 1;
}

int fn_8002EEFC(Tk* o, u32* out) {
    Ent_8002EEFC ents[14];
    u32 tmp;
    s16 b, a;
    s8 mode;
    Ent_8002EEFC* ep;
    Ent_8002EEFC* q;
    Unit* w = o->work->w;
    s16 i;
    s16 n = 0;
    u32 acc = 0;
    int ok;
    int ret;
    Unit* w2;

    fn_80020B50(o, &b, &a);
    switch (a) {
    case 0: case 1:
    case 6: case 7: case 8: case 9:
    case 13: case 14: case 15: case 16:
        mode = 0;
        break;
    default:
        mode = 1;
        break;
    }
    q = ents;
    ep = q;
    for (i = 0; i < 12; i++) {
        tmp = 0;
        if (lbl_80309E24[i] != 0) {
            w2 = lbl_80309E24[i]->work->w;
            switch (mode) {
            case 0:
                if (fn_8001D944(w2->id, o) == 0) ok = 1; else ok = 0;
                break;
            case 1:
                if (fn_8001D944(w2->id, o) != 0) ok = 1; else ok = 0;
                break;
            }
            if (ok) {
                w->x4 = w2->id;
                fn_8002F188(fn_8001E05C(o), &tmp);
                n++;
                ep->flags = tmp;
                acc |= tmp;
                ep->val = w2->id;
                ep++;
            }
        }
    }
    *out = acc;
    if (fn_8001BBF8(o) == 0) *out &= ~0x20000000;
    ret = 0;
    if (*out & 0x20000000) {
        ret = 1;
        for (i = 0; i < n; i++) {
            if (q->flags & 0x20000000) w->x4 = q->val;
            q++;
        }
    }
    return ret;
}

void fn_8002F0E0(void) {
    s16 i;
    u32 v;
    for (i = 0; i < 12; i++) {
        v = 0;
        if (lbl_80309E24[i] != 0) fn_8002F188(lbl_80309E24[i], &v);
    }
}

void fn_8002F154(Tk* o, u32* out) {
    fn_8002F188(fn_8001E05C(o), out);
}

void fn_8002F188(Tk* o, u32* out) {
    Unit* w = o->work->w;
    int id = w->id;
    if (w->x1dc != 0) {
        if (fn_80014C90(id, 1)) *out |= 0x80000000;
        if (fn_80014C90(id, 4)) *out |= 0x40000000;
        if (fn_80014C90(id, 8)) *out |= 0x20000000;
        if (fn_80014C90(id, 0x40)) *out |= 0x08000000;
    } else {
        if (lbl_80347394->work->x3c & 0x20000) *out |= 0x80000000;
        if (lbl_80347394->work->x3c & 0x10000) *out |= 0x40000000;
        if (lbl_80347394->work->x3c & 0x8000) {
            if (lbl_80347394->work->x3c & 0x100) {
                if (w->id % 2) *out |= 0x20000000;
            } else {
                *out |= 0x20000000;
            }
        }
        if (lbl_80347394->work->x3c & 0x2000) *out |= 0x08000000;
        if (lbl_80347394->work->x3c & 0x1000) *out |= 0x04000000;
        if (lbl_80347394->work->x3c & 0x800) *out |= 0x01000000;
    }
    w->xf4 = *out;
}

void fn_8002F35C(void) {
    u8* g = (u8*)lbl_8030A6D4;
    s32 off = lbl_8034757C * 0x24;
    if (*(u32*)(g + off) & 0x1000) {
        lbl_8034737C = 8;
    }
    *(u32*)(g + off) = 0;
    *(u32*)(g + 8 + off) = 0;
    *(u32*)(g + 0xc + off) = 0;
    if (lbl_8034733C == 1) {
        Q_8002F35C* q = &lbl_80302AE0;
        Ent_8002F35C* e;
        Rec* r;
        if (--q->timer > 0) return;
        e = &q->e[lbl_80347330];
        r = &e->recs[e->pos++];
        if (r->val == 0xffff) {
            e->pos = 0;
            r = &e->recs[e->pos++];
        }
        q->timer = r->time;
        *(u32*)(g + off) = r->val;
        *(u32*)(g + 8 + off) = r->val;
        *(u32*)(g + 0xc + off) = r->val;
    }
}

void fn_8002F448(void) {
    if (lbl_80302B10.flag != 0) {
        lbl_80302B10.cnt++;
    }
}

s32 fn_8002F46C(s32* out, s32* flag) {
    s32 i = lbl_80302B10.cnt % 2;
    out[7] = lbl_80302B10.p[0][i * 2];
    out[8] = lbl_80302B10.p[0][i * 2 + 1];
    *flag = (i == 0);
    return lbl_80302B10.v[i];
}

void fn_8002F4BC(void* a, void* b, f32 f) {
    fn_8029D008((lbl_80302B10.p[2][0] << 11) | (lbl_80302B10.p[2][1] << 8));
    fn_80293310(a, b, f);
}

s32 fn_8002F52C(void) { return lbl_80302B10.flag; }

void fn_8002F53C(void) { lbl_80302B10.flag = 1; }

void fn_8002F54C(void) {
    lbl_80302B10.flag = 0;
    lbl_80302B10.cnt = 0;
    lbl_80302B10.v[0] = 1;
    lbl_80302B10.v[1] = 1;
    lbl_80302B10.p[0][0] = 8;
    lbl_80302B10.p[0][1] = 6;
    lbl_80302B10.p[1][0] = 8;
    lbl_80302B10.p[1][1] = 6;
    lbl_80302B10.p[2][0] = 4;
    lbl_80302B10.p[2][1] = 5;
}

s32 fn_8002F598(s8 row) {
    s32 tbl[3][10] = {
        {2, 2, 1, 1, 8, 4, 8, 4, 2, 1},
        {8, 1, 8, 2, 4, 4, 8, 4, 1, 2},
        {8, 8, 4, 4, 2, 1, 2, 1, 4, 8},
    };
    s32* m = tbl[row];
    GameState* p = &lbl_8030A10C;
    s8 i = 0;
    while (i < 10) {
        if ((p->x194[0] & *m) == 0) break;
        m++;
        p = (GameState*)((s32*)p + 1);
        i++;
    }
    return i >= 10;
}

void fn_8002F630(void) {
    s8 i;
    R* p = (R*)lbl_8030A10C.x194;
    for (i = 0; i < 10; i += 5) {
        p->v[0] = 0;
        p->v[1] = 0;
        p->v[2] = 0;
        p->v[3] = 0;
        p->v[4] = 0;
        p++;
    }
}

void fn_8002F670(void) {}

s32 fn_8002F674(void) {
    switch (lbl_8034733C) {
    case 7:
        if (lbl_8030A10C.x68 == 0 && fn_8006DB94() != 0) {
            return 1;
        }
        return 0;
    default:
        return 1;
    }
}

void fn_8002F6D4(void) {
    s16 i;
    Unit* r;
    fn_80017320();
    switch (lbl_8034733C) {
    case 3:
        for (i = 0; i < 12; i++) {
            if (lbl_80309E24[i] != NULL) {
                r = lbl_80309E24[i]->work->w;
                if (r->x228 != NULL) {
                    fn_8006D080(r->x228, 1);
                    r->x228 = NULL;
                }
            }
        }
        break;
    }
    fn_800315FC();
    if (lbl_8030A6D4[lbl_8034757C].x8 != 0) {
        lbl_8030A10C.x194[lbl_8030A10C.x1c0] = lbl_8030A6D4[lbl_8034757C].x8;
        if (++lbl_8030A10C.x1c0 >= 10) {
            lbl_8030A10C.x1c0 = 0;
        }
        lbl_8030A10C.x1bc = 0;
    } else {
        if (++lbl_8030A10C.x1bc > 60) {
            lbl_8030A10C.x1bc = 0;
            lbl_8030A10C.x1c0 = 0;
        }
    }
}

static inline s32 NeedsAdd(Tk* t, s32 hash) {
    s16 k;
    s32* p = ((s32*)t->work) + 1;
    for (k = 0; k < 128; p++, k++) {
        if (hash == *p) return 0;
        if (*p == 0) return 1;
    }
    return 1;
}

s32 fn_8002F80C(s8 mode, Tk* tab) {
    s32 count = 0;
    s16 i;
    s8 end;
    Tk** pp;
    char buf[0x20];
    char name1[0x20];
    char name2[0x20];
    s32 hash;
    fn_8006C5A4();
    switch (mode) {
    case 0:
        i = 0;
        end = 4;
        break;
    case 1:
        i = 4;
        end = 12;
        break;
    default:
        i = 0;
        end = 12;
        break;
    }
    pp = &lbl_80309700[i];
    for (; i < end; pp++, i++) {
        if (*pp != NULL) {
            Wk* info = (*pp)->work;
            s16 type = info->type;
            s16 id = info->id;
            if (type < 4) {
                fn_8025CB24(buf, "MA%03d.MLD", id);
            } else {
                if (id < 0) {
                    fn_801DBE1C("incorrect load character No[%d]", id);
                }
                if (id < 128) {
                    fn_8025CB24(buf, "MB%03d.MLD", id);
                } else {
                    fn_8025CB24(buf, "MG%03d.MLD", fn_80008274(id) - 128);
                }
            }
            fn_8025F120(name1, buf);
            fn_8025F120(name2, buf);
            fn_80061048(name1);
            fn_80046BB0(buf, &hash);
            if (NeedsAdd(tab, hash)) {
                fn_8025CB24(buf, "%s0.STD", name1);
                fn_8006E75C(lbl_80347398, buf, hash);
                count++;
            }
        }
    }
    fn_8006DBDC();
    return count;
}

s32 fn_8002FA00(s8 mode, s32 flag, Tk* tab) {
    Tk** pp;
    s32 count = 0;
    s16 i;
    s32 n = 0;
    s8 end;
    s32 a;
    s32 b;
    Wk* info;
    char buf[0x20];
    char name1[0x20];
    char name2[0x20];
    s32 hash;
    s32 key;
    fn_8006C5A4();
    if (flag != 0) {
        void* h = lbl_80347398;
        fn_80046BB0("E1800000.MLD", &key);
        if (fn_80009500(h, key, -1) != 0) {
            n = 1;
        }
    }
    switch (mode) {
    case 0:
    case 3:
    case 5:
        a = 0;
        b = 4;
        break;
    case 1:
    case 4:
        a = 4;
        b = 12;
        break;
    default:
        a = 0;
        b = 12;
        break;
    }
    i = (s8)a;
    end = (s8)b;
    pp = &lbl_80309700[i];
    for (; i < end; pp++, i++) {
        if (*pp != NULL) {
            s16 type, id;
            info = (*pp)->work;
            type = info->type;
            id = info->id;
            if (type < 4) {
                fn_8025CB24(buf, "MA%03d.MLD", id);
            } else {
                if (id < 0) {
                    fn_801DBE1C("incorrect load character No[%d]", id);
                }
                if (id < 128) {
                    fn_8025CB24(buf, "MB%03d.MLD", id);
                } else {
                    fn_8025CB24(buf, "MG%03d.MLD", fn_80008274(id) - 128);
                }
            }
            fn_8025F120(name1, buf);
            fn_8025F120(name2, buf);
            fn_80061048(name1);
            fn_80046BB0(buf, &hash);
            if (NeedsAdd(tab, hash)) {
                if (mode < 5) {
                    s16 cnt;
                    fn_80009500(lbl_80347398, hash, hash);
                    ((s32*)tab->work)[(s16)n + 1] = hash;
                    fn_8025CB24(buf, "%s.STD", name1);
                    fn_8006E75C(lbl_80347398, buf, hash);
                    ((s32*)tab->work)[(s16)(n + 1) + 1] = hash;
                    n += 2;
                    if (mode < 3) {
                        fn_8025CB24(buf, "%s0.STD", name1);
                        fn_8006E75C(lbl_80347398, buf, hash);
                        ((s32*)tab->work)[(s16)n + 1] = hash;
                        n++;
                    }
                }
                {
                    s16 c = fn_8000F8F8(lbl_80347398, name2, info->id, info->type, hash);
                    while (c != 0) {
                        ((s32*)tab->work)[(s16)n + 1] = hash;
                        n++;
                        c--;
                    }
                }
                count++;
            }
            if (info->id == 2 && info->type < 4) {
                n = fn_8006801C(tab, n);
            }
        }
    }
    fn_8006DC6C();
    return count;
}

void fn_8002FD58(void) {
    s16 i;
    char buf[0x20];
    for (i = 0; i < 4; i++) {
        if (lbl_80309700[i] != NULL) {
            Wk* info = lbl_80309700[i]->work;
            if (info->id == 2 && info->type < 4) {
                s16 v = fn_80068348(i);
                if (v >= 15 && v < 26) {
                    fn_8025CB24(buf, "D05000%02X.MLK", v);
                    fn_8006E75C(lbl_80347398, buf, 0);
                }
            }
        }
    }
}

void fn_8002FE10(void) {
    char buf[0x20];
    s16 i;
    for (i = 4; i < 12; i++) {
        Tk* t = lbl_80309700[i];
        if (t != 0) {
            fn_8025CB24(buf, lbl_802AD1D0, fn_80008274(t->work->id));
            fn_8006E75C(lbl_80347398, buf, 0);
        }
    }
}

void fn_8002FEB0(void (*fn)(void*), void* arg, u32 flags) {
    Callback* tail = lbl_8030A10C.head;
    if (tail == 0) {
        fn_80061F58(&lbl_8030A10C.head, 0x14, 0);
        lbl_8030A10C.head->fn = fn;
        lbl_8030A10C.head->arg = arg;
        lbl_8030A10C.head->flags = flags;
    } else {
        Callback* n;
        for (;;) {
            Callback* nx = tail->next;
            if (nx == 0) break;
            tail = nx;
        }
        fn_80061F58(&n, 0x14, 0);
        tail->next = n;
        n->prev = tail;
        n->fn = fn;
        n->arg = arg;
        n->flags = flags;
    }
}

void fn_8002FF70(void) {
    Callback* e;
    Callback* b;
    Callback* c;
    Callback* a;
    for (e = lbl_8030A10C.head; e != 0; e = e->next) {
        if (e->flags & 0x80000000) e->fn(e->arg);
    }
    if (lbl_8030A10C.flags & 0x40000000) fn_80226D14();
    if (lbl_80302B10.flag != 0) {
        a = lbl_8030A10C.head;
        if (a != 0) {
            b = a->next;
            c = b->next;
            if (b != 0 && c != 0) {
                lbl_8030A10C.head = a;
                a->next = c;
                c->next = b;
                b->next = 0;
            }
        }
    }
    e = lbl_8030A10C.head;
    if (e != 0) {
        fn_801D0F80(1);
        fn_801D22CC();
        fn_801DBCD4();
        for (; e != 0; e = e->next) {
            if (!(e->flags & 0x80000000)) e->fn(e->arg);
        }
    }
    e = lbl_8030A10C.head;
    while (e != 0) {
        Callback* n = e;
        e = e->next;
        fn_801E17E0(n);
    }
    lbl_8030A10C.head = 0;
    if (lbl_8034733C != 5) lbl_8030A10C.flags &= ~0x20000000;
    fn_80060AB4();
}

s32 fn_800300C4(s16 i) { return lbl_802DBF38[i]; }

void fn_800300DC(void) { fn_802281BC(1000); }

void fn_80030100(void) {
    s16 i;
    s32 j;
    s8 k;
    memset(lbl_80309EC8, 0, 0x244);
    fn_8006EB04();
    memset(lbl_80309E5C, 0, 0x2c);
    memset(lbl_80309E24, 0, 0x38);
    memset(&lbl_8030A10C, 0, 0x1d0);
    lbl_803472EC = 0;
    if (!(lbl_80310B3C.flags & 0x10)) lbl_8030A10C.flags |= 0x10000;
    lbl_8030A10C.xec = 1.5f;
    lbl_8030A10C.x72 = -1;
    lbl_8030A10C.x70 = 7;
    for (i = 0; i < 9; i++) {
        for (j = 0; (s16)j < 9; j += 3) {
            s16 a = j + 1;
            s16 b = j + 2;
            lbl_8030A10C.grid[i][j] = -1;
            lbl_8030A10C.grid[i][a] = -1;
            lbl_8030A10C.grid[i][b] = -1;
        }
    }
    lbl_80309168[0] = 0.0f;
    lbl_80347394 = 0;
    lbl_803472F8 = 0;
    lbl_803472F4 = 0;
    lbl_803472F0 = 0;
    lbl_80309168[1] = 0.0f;
    lbl_80309168[2] = 0.0f;
    for (k = 0; k < 20; k += 5) {
        s32* p = lbl_80309118 + k;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
    }
}

void fn_80030280(s32 id) {
    char buf[0x20];
    char tmp[0x20];
    s32 out;
    char* st = lbl_802AD0F8;
    s16 b;
    Tk** p;
    Tk* t;
    s16 c;
    s16 i;
    if (fn_80068128() == 0) {
        p = lbl_80309700;
        for (i = 0; i < 12; p++, i++) {
            t = *p;
            if (t != 0) {
                s16 a = t->work->type;
                b = t->work->id;
                if (a < 4) {
                    fn_8025CB24(buf, st + 0x78, b);
                } else {
                    if (b < 0) fn_801DBE1C(st + 0x84, b);
                    if (b < 0x80) {
                        fn_8025CB24(buf, st + 0xa0, b);
                    } else {
                        c = fn_80008274(b);
                        fn_8025CB24(buf, st + 0xac, c - 0x80);
                    }
                }
                fn_80046BB0(buf, &out);
                if (out == id) {
                    lbl_8030A10C.x8 = t;
                    fn_8006C8DC(tmp, buf);
                    fn_80021934(tmp, buf);
                }
            }
        }
    } else {
        fn_80068190(buf);
        fn_80046BB0(buf, &out);
        if (out == id) {
            fn_8006C8DC(tmp, buf);
            fn_80067E8C(tmp, buf);
        }
    }
}

s16 fn_800303EC(s32* ids, s32 flag) {
    s32* ip = ids;
    s16 i;
    s16 count = 0;
    for (i = 0; i < 128; ip++, i++) {
        s32 id = *ip;
        if (id != 0) {
            Ent_800303EC* e = lbl_80347398;
            s16 j;
            for (j = 0; j < 128; e++, j++) {
                if (id == e->x18 && e->x4 == 0) break;
            }
            if (j == 128) {
                if (flag != 0) {
                    s32* p;
                    s16 k;
                    fn_80030280(id);
                    k = 0;
                    for (p = ids; k < 128; p++, k++) {
                        if (id == *p) *p = 0;
                    }
                }
            } else {
                count++;
            }
        }
    }
    return count;
}

void fn_800304DC(Tk* task) {
    Work_800304DC* w = (Work_800304DC*)task->work;
    switch (task->state) {
    default:
        break;
    case 0:
        task->state = 1;
        w->x0 = 30;
        fn_80227068(1);
        lbl_80346BB8 = 0;
        break;
    case 1:
        if (!(lbl_8030A10C.flags & 0x80000000)) {
            lbl_8030A10C.x68 = 0;
            task->state = 2;
        }
        break;
    case 2:
        if (!(lbl_8030A10C.flags & 0x80000000)) {
            fn_800096BC();
            lbl_8030A10C.x68 = 0;
            fn_8002F80C(2, task);
            task->state = 3;
        }
        break;
    case 3:
        if (!(lbl_8030A10C.flags & 0x80000000)) {
            fn_801CBB9C(0.0f);
            task->state = 4;
        }
        break;
    case 4:
        lbl_8030A10C.x68 = 0;
        fn_8006C710(0, 0);
        task->state = 5;
        break;
    case 5:
        if (!(lbl_8030A10C.flags & 0x80000000)) task->state = 8;
        break;
    case 6:
        if (!(lbl_8030A10C.flags & 0x80000000)) {
            lbl_8030A10C.x68 = 0;
            fn_8002FA00(4, 1, task);
            task->state = 7;
        }
        break;
    case 7:
        if (fn_800303EC(w->ids, 1) == 0) {
            fn_800303EC(w->ids, 1);
            task->state = 11;
        }
        break;
    case 8:
        if (!(lbl_8030A10C.flags & 0x80000000)) {
            lbl_8030A10C.x68 = 0;
            fn_8002FA00(3, 0, task);
            task->state = 9;
        }
        break;
    case 9:
        if (fn_800303EC(w->ids, 1) == 0) {
            fn_800303EC(w->ids, 1);
            task->state = 6;
        }
        break;
    case 11:
        task->state = 12;
        break;
    case 12:
        task->state = 10;
        break;
    case 10:
        lbl_8030A10C.x68 = 0;
        fn_8006C5B4();
        task->state = 13;
        break;
    case 13:
        if (!(lbl_8030A10C.flags & 0x80000000)) {
            u32 f = lbl_8030A10C.flags;
            if (f & 0x00400000) {
                lbl_8030A10C.flags = f & ~0x00400000;
                task->state = 15;
            } else if (f & 0x00040000) {
                lbl_8030A10C.flags = f & ~0x00040000;
                task->state = 16;
            } else {
                task->state = 17;
            }
        }
        break;
    case 15:
        if (lbl_8030A10C.flags & 0x00800000) task->state = 17;
        break;
    case 16:
        task->state = 17;
        break;
    case 17:
        if (lbl_8030A10C.flags & 0x00800000) {
            w->x0 = 0;
        } else if (w->x0 != 0) {
            w->x0--;
            if (lbl_8030A6D4[lbl_8034757C].flags & 0x100) w->x0 = 0;
        } else if (fn_8006D1C4() != 0) {
            if (lbl_803097F0[0] == 9 && lbl_80346BB8 < 90) {
                lbl_80346BB8++;
            } else {
                lbl_8034737C = 5;
                lbl_8030A10C.x68 = 0;
                task->flags |= 0x40;
                fn_80226DC4();
                lbl_8030A10C.flags |= 0x800;
                lbl_80302B10.flag = 0;
            }
        }
        break;
    }
    if (lbl_8030A10C.flags & 0x00800000) w->x0 = 0;
}

void fn_800308A8(void) {
    Node* node = fn_802268E8(lbl_803475A8, fn_800304DC);
    fn_80061F58(node->work, 0x204, 0);
    lbl_8030A10C.x68 = node;
}

static inline int Fmt(char* buf, s16 id, s16 kind) {
    if (kind < 4) {
        fn_8025CB24(buf, "MA%03d.MLD", id);
    } else {
        if (id < 0) {
            fn_801DBE1C("incorrect load chara No[%d]", id);
        }
        if (id < 0x80) {
            fn_8025CB24(buf, "MB%03d.MLD", id);
        } else {
            s16 n = fn_80008274(id);
            fn_8025CB24(buf, "MG%03d.MLD", n - 0x80);
        }
    }
    return 1;
}

int fn_800308FC(char* buf, s16 id, s16 kind) { return Fmt(buf, id, kind); }

void fn_800309C0(void) {
    fn_8000CB44();
    fn_8006B3EC();
}

void fn_800309E4(void) {
    Callback* e;
    if (lbl_8030A10C.flags & 0x800) {
        lbl_8030A10C.flags &= ~0x800;
    }
    lbl_8030A10C.flags &= ~0x200;
    switch (lbl_8034733C) {
    case 3:
        fn_8002F0E0();
        break;
    case 2:
        fn_80014BA8();
        break;
    }
    fn_800149AC();
    fn_8022642C();
    for (e = lbl_8030A10C.list; e != NULL; e = e->next) {
        e->fn(e->arg);
    }
    e = lbl_8030A10C.list;
    while (e != NULL) {
        void* p = e;
        e = e->next;
        fn_801E17E0(p);
    }
    lbl_8030A10C.list = NULL;
    fn_8002FF70();
}

void fn_80030ABC(void) {
    fn_8022DCC4();
    fn_80014784();
    fn_8006B71C();
    fn_8007651C();
}

s8 fn_80030AE8(u32 flags, s8* p) {
    if (fn_80014C90(*p, 0x200)) return 2; return (flags & 0x20000000) != 0;
}

void fn_80030B34(Tk* task) {
    Unit* a = ((Work_80030B34*)task->work)->a->work->w;
    Unit* b = ((Work_80030B34*)task->work)->b->work->w;
    int done = 0;
    switch (task->state) {
    case 0:
        a->xec |= 0x40000;
        task->state = 1;
    case 1:
        switch (a->x20) {
        case 0xd:
            if (fn_8001E910(((Work_80030B34*)task->work)->a)) {
                done = 1;
            }
            break;
        default:
            if (((Work_80030B34*)task->work)->timer >= 100) {
                done = 1;
            }
            break;
        }
        if (done) {
            a->x6 = ((Work_80030B34*)task->work)->x;
            a->x8 = ((Work_80030B34*)task->work)->y;
            a->x4 = b->id;
            a->xec &= ~0x8000;
            fn_800085EC(((Work_80030B34*)task->work)->a, a->x6, a->x8, lbl_8030A10C.x10, lbl_8030A10C.x184);
            task->state = 2;
        }
        break;
    case 2:
        task->flags |= 0x40;
        return;
    }
    ((Work_80030B34*)task->work)->timer++;
}

void fn_80030C94(Tk* task) {
    Tk* o;
    Unit* a = ((Work_80030C94*)task->work)->a->work->w;
    Unit* b = ((Work_80030C94*)task->work)->b->work->w;
    s16 i;
    s8 r;
    switch (task->state) {
    case 0:
        b->xec |= 0x80000;
        b->xec |= 0x40000;
        task->state = 1;
    case 1:
        switch (((Work_80030C94*)task->work)->timer) {
        case 0x5a:
            fn_8001F814((u8)a->id, (u8)b->id);
            fn_800085EC(((Work_80030C94*)task->work)->a, 0x1e, 0x2b, lbl_8030A10C.x10, lbl_8030A10C.x184);
            r = fn_80014C90(b->id, 0x200) ? 2 : 0;
            if (r == 2) {
                fn_800085EC(((Work_80030C94*)task->work)->b, 0x1e, 0x19, lbl_8030A10C.xc, lbl_8030A10C.x180);
            } else {
                for (i = 0; i < 12; i++) {
                    o = lbl_80309E24[i];
                    if (o != NULL) {
                        if (fn_8001D944(o->work->w->id, ((Work_80030C94*)task->work)->a) == 0) {
                            fn_800085EC(o, 0x23, -1, lbl_8030A10C.xc, lbl_8030A10C.x180);
                        }
                    }
                }
            }
            task->state = 2;
            break;
        }
        break;
    case 2:
        fn_8001D14C(b);
        task->flags |= 0x40;
        return;
    }
    ((Work_80030C94*)task->work)->timer++;
}

static inline int KindA(s8 x) {
    switch (x) {
    case 0: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
    case 13: case 14: case 15: case 16: case 17:
    case 0x18: case 0x19: case 0x1a:
    case 0x41:
    case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49:
        return 1;
    }
    return 0;
}

void fn_80030E5C(Tk* task) {
    Tk* obj;
    Unit* c;
    Unit* o;
    int r;
    u32 fl;
    u8 x4;

    c = ((Wk*)task->work)->w;
    r = KindA(c->x32);
    obj = fn_8001E05C(task);
    x4 = c->x4;
    o = obj->work->w;
    if (fn_8001BBF8(task) == 0) {
        o->xf4 &= ~0x20000000;
    }
    fl = o->xf4;
    if (c->x32 == 0x42) {
        if (fn_8001D944(o->id, task)) {
            r = 1;
        } else {
            r = 0;
        }
    }
    if (r) {
        if (fn_80014C90(c->id, 0x200)) {
            r = 2;
        } else if (fl & 0x20000000) {
            r = 1;
        } else {
            r = 0;
        }
        if (((fl & 0x20000000) && fn_800207C8(task)) || (fn_800207C8(task) && (s8)r == 2)) {
            if ((s8)r == 1) {
                fn_800085EC(obj, 0x23, -1, lbl_8030A10C.xc, lbl_8030A10C.x180);
            } else if ((s8)r == 2) {
                fn_800085EC(task, 0x1e, 0x19, lbl_8030A10C.xc, lbl_8030A10C.x180);
            }
            fn_8001DCA0(o);
            o->x134 = 1;
        } else if (fn_8002EEB0(task)) {
            switch ((s8)c->x32) {
            case 0: case 4: case 6: case 8: case 0x11: case 0x2c: case 0x3e:
            case 0x41: case 0x42: case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49:
                r = 1;
                break;
            default:
                r = 0;
                break;
            }
            if (fl & 0x08000000) {
                o->xf4 |= 0x800000;
            }
            fn_8002111C(c->x4, c->id, 0x18);
            if (!r) {
                o->xec |= 0x20;
            }
        } else {
            fn_8002111C(c->x4, c->id, 0x18);
        }
        fn_8002ECA4(c, x4);
        if (c->x50 & 0x40000000) {
            c->xf0 |= 0x4000000;
        }
    } else {
        if (fn_80014C90(c->id, 0x200)) {
            r = 2;
        } else if (fl & 0x20000000) {
            r = 1;
        } else {
            r = 0;
        }
        if (((fl & 0x20000000) && fn_800207C8(task)) || (fn_800207C8(task) && (s8)r == 2)) {
            if ((s8)r == 1) {
                fn_800085EC(obj, 0x23, -1, lbl_8030A10C.xc, lbl_8030A10C.x180);
            } else if ((s8)r == 2) {
                fn_800085EC(task, 0x1e, 0x19, lbl_8030A10C.xc, lbl_8030A10C.x180);
            }
            fn_8001DCA0(o);
            o->x134 = 1;
        } else {
            fn_800085EC(obj, c->x6, c->x8, lbl_8030A10C.xc, lbl_8030A10C.x180);
            o->x134 = 1;
            fn_8002ECA4(c, x4);
            fn_8002E48C(obj);
            fn_8001DCA0(o);
        }
    }
}
