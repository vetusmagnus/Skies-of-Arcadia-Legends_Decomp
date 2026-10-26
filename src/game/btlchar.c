/* Battle character task and helpers (0x80031254 - 0x80032E78): node spawners for the 0x80030B34 /
 * 0x80030C94 / 0x800317FC tasks, battle-state predicates (fn_8003146C ...), the per-character
 * command task fn_800317FC, "show" wrappers that check the lbl_80347394 channel (BtlCanShow), and
 * the music/state save-restore fn_80032C6C. Per-function work layouts carry the function address. */
#include "types.h"
#include "game/task.h"

typedef struct { u8 pad[0x24]; void* work; } Node;
typedef struct { void* a; void* b; u8 pad[2]; s16 x; s16 y; } PosWork;

typedef struct { u8 pad[0x3c]; u32 flags; } SubA;
typedef struct { u8 pad[0x24]; SubA* sub; } ObjA;

typedef struct {
    u8 pad0[0xC];
    s32 xc;       /* 0x0C */
    u8 pad10[0x6C - 0x10];
    u32 x6c;      /* 0x6C */
    u8 pad70[0xF4 - 0x70];
    u32 xf4;      /* 0xF4 */
    u8 padF8[0x180 - 0xF8];
    s32 x180;     /* 0x180 */
    u8 pad184[0x1C4 - 0x184];
    s32 x1c4;     /* 0x1C4 */
} GameState;

typedef struct Obj {
    u8 pad[0x2C];
    struct Obj* child;   /* 0x2C */
    struct Obj* next;    /* 0x30 */
} Obj;

extern GameState lbl_8030A10C;
extern ObjA* lbl_80347394;
extern void* lbl_803475A8;
extern s32 lbl_8034733C;
extern s16 lbl_80347378;
extern s32 lbl_80346748;
extern s32 lbl_80346BC0;

extern void fn_80020B50(void*, s16*, s16*);
extern void* fn_8001E05C(void*);
extern Node* fn_802268E8(void*, void*);
extern Node* fn_8003DB34(void*);
extern void fn_80061F58(void*, int, int);
extern void fn_80030B34(void);
extern void fn_800317FC(Task* task);
extern void fn_80030C94(void);
extern s16 fn_8007838C(s16);
extern s16 fn_80078354(s16);
extern s16 fn_800783A8(int);
extern s16 fn_800290E8(s32);
extern void fn_80029364(s32, s8, s16, s32);
extern s8 fn_8001C12C(void);
extern s8 fn_80020E10(void*);
extern void fn_80014F90(int);
extern void fn_800152A0(void);
extern s32 fn_800179E4(s32 id);
extern s16 fn_8006D2C4(s32 a);
extern void fn_8002962C(s32 id);
extern void fn_800295E0(s32 id);
extern void fn_800085EC(Task* t, s32 a, s16 b, s32 c, s32 d);
extern void fn_8002942C();
extern void fn_8002923C(s32 id, s32 a, s32 b);
extern void fn_80029168(s32 id, s32 v);
extern void fn_800292F8(s32 id, s32 n);
extern s16 fn_8007EB74(s32 id);
extern void fn_80015020(u8 id);
extern void fn_80015344(u8 id);
extern void fn_800294E8(void);
extern void fn_801E17E0(void*);
extern s32 fn_80075FCC(void*);
extern void fn_80075F2C(void*);
extern void fn_8022E4CC(Obj* o, s32 a, s32 b, s32 c, s32 d, s32 e);
extern void fn_80299040(void);

typedef struct { s8 kind; u8 pad1[0x31]; s16 v; u8 pad34[0x1dc - 0x34]; u32 x1dc; } Inner36C;
typedef struct { u8 pad[0x24]; struct { u8 pad[0x4c]; Inner36C* inner; } *work; } Node36C;

typedef struct { u8 pad[0x10]; u8* x10; u8 pad14[0x38]; s8* x4c; } Sub5FC;
typedef struct { u8 pad[0x24]; Sub5FC* work; } Obj5FC;

typedef struct { u8 pad[0x3c]; s16 a, b, c; } Src6F8;
typedef struct { u8 id; u8 p1; s16 a, b, c; void* pad8; void* arg; } W6F8;

typedef struct {
    s8 id;              /* 0x00 */
    u8 pad1[0x38 - 0x01];
    s32 x38;            /* 0x38 */
    s16 x3c[3];         /* 0x3C */
    u8 pad42[0x48 - 0x42];
    s8 target;          /* 0x48 */
    u8 pad49[0x50 - 0x49];
    u32 flags;          /* 0x50 */
    u8 pad54[0x70 - 0x54];
    s32 x70;            /* 0x70 */
    u8 pad74[0xF0 - 0x74];
    u32 xf0;            /* 0xF0 */
    u8 padF4[0x1DC - 0xF4];
    u32 x1dc;           /* 0x1DC */
} BtlChar;

typedef struct {
    u8 pad0[0xC];
    char name[1]; /* 0x0C */
} BtlInfo;

typedef struct {
    u8 pad0[0x10];
    BtlInfo* info;  /* 0x10 */
    u8 pad14[0x4C - 0x14];
    BtlChar* chr;   /* 0x4C */
} BtlOwner;

typedef struct {
    s8 kind;      /* 0x00 */
    s8 slot;      /* 0x01 */
    s16 cmd[3];   /* 0x02 */
    s16 timer;    /* 0x08 */
    u8 padA[2];
    Task* owner;  /* 0x0C */
} BtlWork;

typedef struct { u32 unk0; } Res5B8;
typedef struct {
    u8 pad0[6];
    s16 type;
    u8 pad8[0xec - 8];
    u32 flagsEC;
    u32 flagsF0;
    u8 padF4[0x1f4 - 0xf4];
    Res5B8** res;
} Inner5B8;
typedef struct { u8 pad[0x24]; struct { u8 pad[0x4c]; Inner5B8* inner; }* sub; } Obj5B8;

typedef struct { s32 key; s32 val; } KV;
typedef struct { u8 pad[0x50]; s32 id; s32 alt; } Info;
typedef struct { u8 pad[0x24]; Info* info; } ObjInfo;
typedef struct { u32 unk0; void* unk4; } E44;
extern KV lbl_802DC1F8[];
extern Obj5FC* lbl_80309E24[12];

#define BTL_CAN_SHOW(id)     ((lbl_80347394 != NULL && (lbl_80347394->sub->flags & 0x10)) || (lbl_80347394 == NULL && (id) >= 0))


void fn_80031254(void* p) {
    s16 x, y;
    void* q;
    Node* node;
    PosWork* w;
    fn_80020B50(p, &x, &y);
    q = fn_8001E05C(p);
    node = fn_802268E8(lbl_803475A8, fn_80030B34);
    fn_80061F58(&node->work, 0x10, 0);
    ((PosWork*)node->work)->a = p;
    ((PosWork*)node->work)->b = q;
    ((PosWork*)node->work)->x = x;
    ((PosWork*)node->work)->y = y;
}

void fn_800312F0(void* p, s16 x, s16 y) {
    void* q;
    Node* node;
    q = fn_8001E05C(p);
    node = fn_802268E8(lbl_803475A8, fn_80030C94);
    fn_80061F58(&node->work, 0x10, 0);
    ((PosWork*)node->work)->a = q;
    ((PosWork*)node->work)->b = p;
    ((PosWork*)node->work)->x = x;
    ((PosWork*)node->work)->y = y;
}

int fn_8003136C(Node36C* n) {
    s16 a, b;
    Inner36C* o;
    fn_80020B50(n, &a, &b);
    o = n->work->inner;
    if (o->x1dc != 0) {
        switch (a) {
        case 0x18:
            o->v = fn_8007838C(b);
            break;
        case 0x1d:
            o->v = fn_80078354(b);
            break;
        default:
            o->v = fn_800783A8(o->kind);
            break;
        }
    } else {
        o->v = 0;
    }
    switch ((s8)o->v) {
    case 0: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
    case 13: case 14: case 15: case 16: case 17:
    case 0x18: case 0x19: case 0x1a:
    case 0x41:
    case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49:
        return 1;
    }
    return 0;
}

int fn_8003146C(s8 x) {
    switch (x) {
    case 0: case 4: case 6: case 8: case 0x11: case 0x2c: case 0x3e:
    case 0x41: case 0x42: case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49:
        return 1;
    }
    return 0;
}

int fn_800314FC(s8 x) {
    switch (x) {
    case 0x1f: case 0x20:
        return 1;
    }
    return 0;
}

int fn_80031524(s16 x) {
    switch (x) {
    case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17:
    case 0x18: case 0x19: case 0x1a:
    case 0x3e:
    case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49:
        return 1;
    }
    return 0;
}

void fn_80031580(s32 a, s8 b, s16 c, s32 d) {
    s16 r = fn_800290E8(a);
    switch (b) {
    case 2:
        if (r != 0) {
            return;
        }
        break;
    }
    fn_80029364(a, b, c, d);
}

static inline void CheckVoice(Obj5FC* o, s8 mode) {
    Sub5FC* s = o->work;
    s8* p = s->x4c;
    s8 k;
    if (fn_80020E10(s->x10 + 0xc) < 0) {
        if (mode == 2) {
            k = *p;
            fn_800290E8(k);
            fn_80029364(k, 3, 30, 1);
        }
    } else if (mode == 1) {
        k = *p;
        fn_800290E8(k);
        fn_80029364(k, 3, 30, 1);
    }
}

void fn_800315FC(void) {
    s8 mode;
    s8 i;
    mode = fn_8001C12C();
    if (mode != 0) {
        for (i = 0; i < 12; i++) {
            if (lbl_80309E24[i] != 0) {
                CheckVoice(lbl_80309E24[i], mode);
            }
        }
    }
}

void fn_800316F8(Node* t, u8 id) {
    Src6F8* src = *(Src6F8**)((u8*)t->work + 0x4c);
    Node* node = fn_8003DB34(fn_800317FC);
    W6F8* w;
    fn_80061F58(&node->work, 0x10, 0);
    w = node->work;
    w->a = src->a;
    w->b = src->b;
    w->c = src->c;
    w->id = id;
    w->arg = t;
}

void fn_80031788(s16 n) {
    if (!(lbl_8030A10C.xf4 & (1 << n))) {
        lbl_80347378 &= ~(1 << n);
    }
}

void fn_800317B8(void) {
    if (!(lbl_8030A10C.x6c & 0x10000000)) {
        fn_80014F90(0);
        fn_80014F90(1);
        fn_800152A0();
    }
}

inline void BtlShowA(s8 id, s32 n) {
    if (BTL_CAN_SHOW(id)) {
        fn_8002942C(id, n);
    }
}

inline void BtlShowB(s8 id, s32 n) {
    if (BTL_CAN_SHOW(id)) {
        fn_800292F8(id, n);
    }
}

inline void BtlShowC(s8 id) {
    if (BTL_CAN_SHOW(id)) {
        s16 r = fn_800290E8(id);
        if (!(r < 3 && r >= 1) && !(lbl_8034733C < 10 && lbl_8034733C >= 7)) {
            fn_8002962C(id);
        }
    }
}

inline void BtlShowD(s8 id) {
    if (BTL_CAN_SHOW(id)) {
        s16 r = fn_800290E8(id);
        if (!(r < 3 && r >= 1)) {
            fn_800295E0(id);
        }
    }
}

inline void BtlShowAC(s8 id) {
    BtlShowA(id, 9);
    BtlShowC(id);
}

void fn_800317FC(Task* task) {
    BtlWork* w = task->work;
    BtlChar* c;
    s16 i;
    s16 next = -1;

    if (task->state != 0 && fn_800179E4(w->slot) == 0) {
        task->state = 6;
        c = NULL;
    } else {
        c = ((BtlOwner*)((BtlWork*)task->work)->owner->work)->chr;
        if (c->x1dc == 0) {
            task->state = 6;
        }
    }

    switch (task->state) {
    case 0:
        lbl_80347378 |= 1 << c->id;
        c->flags |= 0x1000000;
        w->slot = c->id;
        lbl_8030A10C.xf4 |= 1 << w->slot;
        if (lbl_8034733C != 5) {
            break;
        }
        if (fn_8006D2C4(1) != 0 && !(lbl_8030A10C.x6c & 0x20000000)) {
            break;
        }
        if (c->x70 == 0) {
            break;
        }
        task->state = 1;
        lbl_8030A10C.x6c |= 0x20000000;
    case 1:
        task->state = 3;
        BtlShowC(c->id);
        switch (w->kind) {
        case 9:
            BtlShowD(c->id);
            fn_800085EC(((BtlWork*)task->work)->owner, 0x21, -1, lbl_8030A10C.xc, lbl_8030A10C.x180);
            task->state = 2;
        case 7:
            BtlShowAC(c->id);
            break;
        case 6:
            BtlShowA(c->id, 6);
            fn_8002923C(c->id, 0xFD, 1);
            break;
        case 1:
            if (c->x38 >= 0) {
                fn_80029168(c->id, -c->x38);
            } else {
                fn_80029168(c->id, 0);
            }
        case 0:
            BtlShowA(c->id, 6);
            fn_8002923C(c->id, 0x700, 1);
            break;
        case 8:
            if (c->x38 >= 0) {
                fn_80029168(c->id, c->x38);
            } else {
                fn_80029168(c->id, 0);
            }
            BtlShowA(c->id, 6);
            fn_8002923C(c->id, 0xFF, 1);
            break;
        case 4:
            fn_8002923C(c->id, 0x7FB, 0);
            BtlShowB(c->id, 4);
            next = 0x16;
            break;
        case 5:
            if (c->x38 >= 0) {
                BtlShowA(c->id, 4);
                fn_80029168(c->id, -c->x38);
            } else {
                BtlShowA(c->id, 5);
            }
            fn_8002923C(c->id, 0x7FF, 0);
            BtlShowB(c->id, 2);
            break;
        case 3:
            for (i = 0; i < 3; i++) {
                switch (w->cmd[i]) {
                case 0x30:
                case 0x31:
                    BtlShowA(c->id, 10);
                    break;
                case 0x2C:
                    BtlShowA(c->target, 4);
                    break;
                default:
                    if (w->cmd[i] >= 0) {
                        BtlShowA(c->id, 5);
                    }
                    break;
                }
                switch (w->cmd[i]) {
                case 48:
                case 49:
                    fn_80029168(c->id, c->x38);
                    break;
                case 44: {
                    s32 v = fn_8007EB74(c->id);
                    BtlShowC(c->target);
                    fn_80029168(c->target, v);
                    task->state = 4;
                    break;
                }
                case 3:
                case 4:
                case 62:
                    BtlShowB(c->id, 1);
                    next = 0x14;
                    break;
                case 63:
                    BtlShowB(c->id, 0x100);
                case 9:
                case 10:
                case 69:
                    BtlShowB(c->id, 8);
                    next = 0x17;
                    break;
                case 11:
                case 70:
                    BtlShowB(c->id, 0x10);
                    next = 0x18;
                    break;
                case 12:
                case 13:
                case 71:
                    BtlShowB(c->id, 0x20);
                    next = 0x19;
                    break;
                case 14:
                case 72:
                    BtlShowB(c->id, 0x40);
                    next = 0x1A;
                    break;
                case 20:
                    BtlShowB(c->id, 0x400);
                    break;
                case 21:
                    BtlShowB(c->id, 0x200);
                    break;
                case 26:
                case 73:
                    BtlShowB(c->id, 0x80);
                    next = 0x1C;
                    break;
                case 27:
                case 28:
                    fn_8002923C(c->id, 2, 0);
                    break;
                case 33:
                    BtlShowB(c->id, 0x100);
                    break;
                case 7:
                    fn_8002923C(c->id, 0x7FB, 0);
                    BtlShowB(c->id, 4);
                    next = 0x16;
                    break;
                case 5:
                case 6:
                case 68:
                    fn_8002923C(c->id, 0x7FD, 0);
                    BtlShowB(c->id, 2);
                    next = 0x15;
                    break;
                }
                c->x3c[i] = -1;
            }
            break;
        }
        if (next != 0x15 && next >= 0) {
            if (fn_80020E10(((BtlOwner*)((BtlWork*)task->work)->owner->work)->info->name) >= 0 &&
                fn_8001C12C() == 1) {
                next = -1;
            }
        }
        if (next >= 0) {
            switch (next) {
            case 0x16:
                fn_800085EC(((BtlWork*)task->work)->owner, 0x1E, next, lbl_8030A10C.xc, lbl_8030A10C.x180);
                task->state = 2;
                break;
            default:
                if (!(c->xf0 & 0x100)) {
                    fn_800085EC(((BtlWork*)task->work)->owner, 0x1E, next, lbl_8030A10C.xc, lbl_8030A10C.x180);
                    task->state = 2;
                }
                break;
            }
        }
        break;
    case 2:
        if (fn_8006D2C4(1) == 0) {
            task->state = 5;
        }
        break;
    case 3:
        if (w->timer >= 20) {
            task->state = 5;
        } else {
            w->timer++;
        }
        break;
    case 4:
        if (fn_800290E8(c->target) != 3) {
            task->state = 5;
        }
        break;
    case 5:
        if (fn_800290E8(c->id) != 3) {
            c->flags &= ~0x1000000;
            fn_80015020(c->id);
            fn_80015344(c->id);
            task->state = 6;
        }
        break;
    case 6:
        lbl_80347378 &= ~(1 << w->slot);
        lbl_8030A10C.xf4 &= ~(1 << w->slot);
        task->flags |= 0x40;
        lbl_8030A10C.x1c4--;
        break;
    }
}

void fn_800324B8(s8 a, s16 b) {
    if (BTL_CAN_SHOW(a)) {
        fn_8002942C(a, 9);
    }
    if (b != 0) {
        fn_800290E8(a);
        fn_80029364(a, 1, b, 1);
    } else if (BTL_CAN_SHOW(a)) {
        s16 r = fn_800290E8(a);
        if (!(r < 3 && r >= 1) && !(lbl_8034733C < 10 && lbl_8034733C >= 7)) {
            fn_8002962C(a);
        }
    }
}

void fn_800325B8(Obj5B8* o) {
    Inner5B8* p = o->sub->inner;
    p->flagsEC &= ~0x400;
    p->flagsF0 &= ~0x800;
    if (p->res != 0) {
        if (*p->res != 0) {
            fn_801E17E0(*p->res);
        }
        if (p->res != 0) {
            fn_801E17E0(p->res);
        }
        p->res = 0;
    }
    switch (p->type) {
    case 0xb:
    case 0x20:
        break;
    default:
        if (fn_80075FCC(o) == 0) {
            fn_80075F2C(o);
        }
        break;
    }
}

inline void fn_8003266C(Obj* o, s32 a, s32 b, s32 c)
{
    if (o != NULL) {
        fn_8022E4CC(o, a, b, c, 3, 0x11);
    }
    if (o->child != NULL) {
        fn_8003266C(o->child, a, b, c);
    }
    if (o->next != NULL) {
        fn_8003266C(o->next, a, b, c);
    }
}

void fn_80032AD8(Obj* o, s32 a, s32 b, s32 c)
{
    fn_8003266C(o, a, b, c);
}

void fn_80032AF8(s8 a, u16 b) {
    if ((lbl_80347394 != 0 && (lbl_80347394->sub->flags & 0x10)) || (lbl_80347394 == 0 && a >= 0)) {
        fn_800292F8(a, b);
    }
}

void fn_80032B4C(void) { fn_800294E8(); }

void fn_80032B6C(s8 a, s32 b) {
    if ((lbl_80347394 != 0 && (lbl_80347394->sub->flags & 0x10)) || (lbl_80347394 == 0 && a >= 0)) {
        fn_8002942C(a, b);
    }
}

void fn_80032BBC(s8 a, s32 b) {
    if (BTL_CAN_SHOW(a)) {
        s8 id = a;
        s16 r = fn_800290E8(id);
        if (!(r < 3 && r >= 1)) {
            if (b != 0) {
                if (!(lbl_8034733C < 10 && lbl_8034733C >= 7)) {
                    fn_8002962C(id);
                }
            } else {
                fn_800295E0(id);
            }
        }
    }
}

void fn_80032C68(void) {}

void fn_80032C6C(s32 restore, ObjInfo* o) {
    s32 hit;
    s32 i;
    s32 id;
    s32 r;
    Info* in;
    if (restore != 0) {
    lbl_80346BC0 = lbl_80346748;
    id = o->info->id;
    if (0x195DC <= id && id <= 0x1963F) {
        lbl_80346748 = 0;
    } else if (0x198FC <= id && id <= 0x1995F) {
        lbl_80346748 = 0;
    } else {
        hit = 0;
        switch (id) {
        case 0x194B8:
        case 0x194B9:
        case 0x194BC:
        case 0x19BB9:
        case 0x19BBA:
        case 0x19BBB:
        case 0x19BBC:
        case 0x19BCB:
        case 0x16EFE0:
        case 0x175A8F:
        case 0x75F544:
        case 0x75F545:
        case 0x75F546:
        case 0x75F547:
        case 0x75F548:
            hit = 1;
            break;
        }
        if (hit != 0) {
            lbl_80346748 = 0;
        } else if (0x4F5880 <= id && id <= 0x4F5C67) {
            lbl_80346748 = 0x20000000;
        } else {
            lbl_80346748 = 0x85000;
        }
    }
    in = o->info;
    if (in->alt == -1) {
        r = -1;
        i = 0;
        do {
            if (in->id == lbl_802DC1F8[i].key) {
                r = lbl_802DC1F8[i].val;
                break;
            }
            i++;
        } while (lbl_802DC1F8[i].key != -1);
        in->alt = r;
    }
    if (o->info->alt != -1) {
        lbl_80346748 = o->info->alt;
    }
    } else {
        lbl_80346748 = lbl_80346BC0;
    }
}

void fn_80032E44(E44* p) {
    if (p != 0 && p->unk4 != 0) {
        fn_80299040();
    }
}
