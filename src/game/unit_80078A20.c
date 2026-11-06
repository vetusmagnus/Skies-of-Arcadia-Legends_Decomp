#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <math.h>
#include "game/task.h"
#include "game/save_8030B7F4.h"
#include "game/stat_8030B4D4.h"
#include "game/gamedata.h"
#include "game/unit_80074D9C.h"
extern s32 lbl_80347330;
extern ChrState lbl_80309174[12];
extern struct Slot;
extern Slot *lbl_80309700[12];
extern s32 fn_80081FEC(s16 i);
extern Chr_UNIT0000* lbl_80309DE4[12];
extern s32 fn_80078610(s8 idx);
void fn_8007D42C(Obj_8007DE54_8007D42C* p);
extern void *lbl_803475A8;
extern void *lbl_8034736C;
extern void *fn_802268E8(void *, void *);
extern void* fn_801E1C7C(int size);
extern void fn_80217830(s32 arg);
extern s32 lbl_8034733C;
extern struct Task_8007BEB4 *lbl_803472FC;
extern struct Task_8007BEB4 *lbl_80347300;
extern struct Task_8007BEB4 *lbl_80347304;
extern struct Task_8007BEB4 *lbl_80347308;
extern struct Task_8007BEB4 *lbl_8034730C;
extern struct Task_8007BEB4 *lbl_80347310;
extern struct Task_8007BEB4 *lbl_80347314;
extern struct Task_8007CAB0 *lbl_80347318;
typedef struct Ent {
    s8 on;      /* 0x0 */
    s8 id;      /* 0x1 */
    s16 sort;   /* 0x2 */
    s16 type;   /* 0x4 */
    u8 pad6[2];
    const SkillData* p; /* 0x8 */
    u32 w;      /* 0xC */
} Ent;
typedef struct List {
    s8 count;   /* 0x0 */
    s8 x1;      /* selected page, 3..8 */
    s8 x2;      /* page availability bitmask */
    s8 x3;
    s8 x4;      /* current sub-page */
    s8 x5;      /* sub-page count */
    u8 x6;
    s8 x7;
    Ent e[8];   /* 0x8 */
} List;
extern s8 lbl_80346C0C;
extern Lim* lbl_80347390;
extern u32 lbl_802F6918[];
extern char* lbl_80347320;
extern s16 lbl_80309DCC[12];
extern s8* lbl_80346C14;
extern s32 lbl_80347338;
extern void fn_8007C344(struct Task_8007BEB4 *);
extern void fn_800794D8(void);
extern void fn_8007A890(struct Task_8007BEB4 *);
typedef struct Slot_8007BEB4 { u32 x0; u8 pad4[4]; u32 x8; u32 flags; u8 pad10[8]; u32 x18; u8 pad1c[8]; } Slot_8007BEB4;
/* Party status block (0x3A bytes) filled by fn_8007C7F8. */
typedef struct HudEnt {
    s16 lv;
    s16 hp;
    s16 mp;
    s16 x6;
    s16 x8;
    s16 st;
    u8 xc;      /* copy of Chr x100 */
    u8 pad;
} HudEnt;
typedef struct Hud {
    u8 n;
    u8 pad;
    HudEnt e[4];
} Hud;
typedef struct Task_8007BEB4 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    List* work;     /* 0x24 */
    Hud* hud;       /* 0x28 */
} Task_8007BEB4;
/* The battle command menu (task lbl_80347318). */
typedef struct Menu_8007CAB0 {
    s8* x0;     /* per-command enabled flags, lbl_80346C14 */
    s8 x4;      /* command count */
    s8 x5;      /* selected command */
    s8 x6;
    s8 x7;
    s8 x8;      /* acting party slot */
    s8 x9;
} Menu_8007CAB0;
typedef struct Task_8007CAB0 {
    u8 pad0[0x18];
    u8 flags;
    u8 state;
    u8 pad1a[0x24 - 0x1a];
    Menu_8007CAB0* work;    /* 0x24 */
    Hud* hud;               /* 0x28 */
} Task_8007CAB0;
extern s8 lbl_80346C0D;
extern s32 lbl_80347324;
extern s32 lbl_80347328;
extern s32 lbl_80346BF8;
extern s32 lbl_80346BFC;
extern s8 fn_801F4CA0(void);
extern void fn_800255CC(Menu_8007CAB0* w);
extern void fn_800255BC(Menu_8007CAB0* w);
extern void fn_80022F0C(Hud* h);
extern void fn_801E17E0(void* p);
extern s32 fn_8007C9CC(void);
void fn_8007C600(u32 arg);

void fn_8007CAB0(Task_8007CAB0* t);
typedef struct ChrState_8007BEB4 { s32 x0; u8 pad4[0x1c]; } ChrState_8007BEB4;
extern Slot_8007BEB4 lbl_8030A6D4[];
extern s32 lbl_80346C10;
extern s32 lbl_8034757C;
extern s32 fn_8007BC6C(s32 sel, SaveChar* pl, List* w);
extern void fn_80023D14(List* w);
extern void fn_80023D04(List* w);
extern void fn_8007B958(Task_8007BEB4* t, s32 sel, s16 item, s32 kind);
extern s32 SePlay(s32 bank, s8 arg1, s8 id);
void fn_8007BEB4(Task_8007BEB4* t);
void fn_8007B5B0(Task_8007BEB4* t);
void fn_8007D318(Task_8007BEB4* p);
extern void fn_8007C194(List* w);
typedef struct Flags_80310B3C { u8 pad[0x24]; u32 x24; } Flags_80310B3C;
extern Flags_80310B3C lbl_80310B3C;
extern u32 fn_801F52AC(void);
void fn_80078AD4(const char* src);

#define NODE_OP(n)                     \
    switch (op) {                      \
    case 0: (n)->flags |= mask; break; \
    case 1: (n)->flags &= mask; break; \
    case 2: (n)->flags ^= mask; break; \
    }

extern s32 fn_801F3F88(void* p, s8 i);
extern s32 fn_800786B0(s16* a, s16* b);
extern void qsort(void* base, s32 n, s32 size, s32 (*cmp)(s16*, s16*));

static inline s32 Has_8007B010(SaveChar* pl, s32 kind) {
    s32 j;
    for (j = 0; j < 0x24; j++) {
        if (fn_801F3F88(pl, j) != 0 && kind == lbl_802C4BF0[j].element) {
            return 1;
        }
    }
    return 0;
}

void fn_8007B010(List* w) {
    s32 mask;
    s32 cur;
    s32 sel;
    s32 j;
    s32 i;
    s32 k;
    s32 lim;
    SaveChar* pl;
    w->x2 = 0;
    pl = &lbl_8030B7F4.chr[lbl_8030B7F4.party[lbl_80347330]];
    for (i = 0; i < 6; i++) {
        if (Has_8007B010(pl, i)) {
            w->x2 |= 1 << i;
        }
    }
    cur = w->x1;
    mask = w->x2;
    for (;;) {
        if (mask & (1 << (cur - 3))) {
            w->x1 = cur;
            break;
        }
        cur++;
        if (cur > 8) cur = 3;
    }
    sel = w->x1 - 3;
    lim = lbl_80347390->xa;
    for (j = k = 0; j < 0x24; j++) {
        if (fn_801F3F88(pl, j) != 0 && sel == lbl_802C4BF0[j].element) {
            Ent* e = &w->e[k];
            const SkillData* it = &lbl_802C4BF0[j];
            s32 cost;
            e->type = j;
            e->p = it;
            e->sort = it->sort;
            cost = it->cost;
            e->id = cost;
            e->w = lbl_802F6918[j];
            if (lim >= cost && lbl_80309DE4[lbl_80347330]->xfe > 0) {
                e->on = 1;
            } else {
                e->on = 0;
            }
            k++;
        }
    }
    w->count = k;
    for (; k < 8; k++) {
        w->e[k].type = -1;
        w->e[k].sort = 10000;
        w->e[k].p = 0;
        w->e[k].id = -1;
        w->e[k].on = 0;
    }
    qsort(w->e, w->count, 0x10, fn_800786B0);
    w->x6 = 0;
    w->x7 = 0;
}

extern void fn_80077D40(s16 id);
extern void fn_80077DA0(s16 id);

static inline UseItemData* UseOf(s32 item) {
    return &lbl_802C7C34[item - 0xF0];
}

static inline s8 UsedUp(s32 item) {
    return UseOf(item)->use_up;
}

static inline void Release_8007B328(s32 idx) {
    s8 n = lbl_80309174[idx].bd;
    if (n > 0) {
        switch (lbl_80309174[lbl_80347330].x0) {
        case 5: {
            s16 item = lbl_80309174[lbl_80347330].x6;
            if (item != -1 && UsedUp(item) != 0) {
                fn_80077DA0(item);
            }
            break;
        }
        case 1:
            lbl_80309DE4[idx]->xfe++;
        case 2:
        case 8:
            lbl_80347390->xa += n;
            break;
        }
        lbl_80309174[idx].bd = 0;
    }
}

void fn_8007B328(s32 idx, s8 val, s32 kind) {
    switch (kind) {
    case 5: {
        s16 item;
        Release_8007B328(idx);
        item = lbl_80347308->work->e[lbl_80347308->work->x3].type;
        lbl_80309174[lbl_80347330].x6 = item;
        if (UsedUp(item) != 0) {
            fn_80077D40(item);
        }
        lbl_80309174[idx].bd = 1;
        break;
    }
    case 1:
        lbl_80309DE4[idx]->xfe--;
    case 2:
    case 8:
        Release_8007B328(idx);
        lbl_80347390->xa -= val;
        lbl_80309174[idx].bd = val;
        break;
    }
}

void fn_8007B5B0(Task_8007BEB4* t) {
    List* w;
    switch (t->state) {
    case 0:
        t->state = 1;
        w = fn_801E1C7C(0x88);
        t->work = w;
        w->x1 = 3;
        fn_8007B010(w);
        w->x7 |= 1;
        w->x3 = 0;
        w->x4 = 0;
        w->x5 = 1;
        break;
    case 1:
        if (lbl_80346C10 == 0) {
            fn_80023D14(t->work);
            t->state = 2;
            lbl_80346C10 = 1;
        }
        break;
    case 2: {
        u32 f;
        s8 sel;
        w = t->work;
        w->x6 = 0;
        sel = w->x3;
        if (sel < 0) break;
        if ((s8)w->count > 1) {
            f = lbl_8030A6D4[lbl_8034757C].flags;
            if (f & 8) {
                SePlay(0, 1, 0);
                w->x6 = 1;
                break;
            } else if (f & 4) {
                SePlay(0, 1, 0);
                w->x6 = 2;
                break;
            }
        }
        f = lbl_8030A6D4[lbl_8034757C].flags;
        if (f & 1) {
            s32 mask = w->x2;
            s32 cur = w->x1;
            s32 j = cur;
            do {
                j--;
                if (j < 3) j = 8;
            } while (!(mask & (1 << (j - 3))));
            if (cur == j) break;
            w->x1 = j;
            w->x3 = 0;
            fn_8007B010(w);
            w->x7 |= 1;
            SePlay(0, 1, 0);
        } else if (f & 2) {
            s32 mask = w->x2;
            s32 cur = w->x1;
            s32 j = cur;
            do {
                j++;
                if (j > 8) j = 3;
            } while (!(mask & (1 << (j - 3))));
            if (cur == j) break;
            w->x1 = j;
            w->x3 = 0;
            fn_8007B010(w);
            w->x7 |= 1;
            SePlay(0, 1, 0);
        } else {
            f = lbl_8030A6D4[lbl_8034757C].x8;
            if (f & 0x100) {
                Ent* e = &w->e[sel];
                if (e->on != 0) {
                    fn_8007B958(t, lbl_80347330, e->type, 1);
                    lbl_80309174[lbl_80347330].x0 = 1;
                    SePlay(0, 1, 2);
                } else {
                    SePlay(0, 1, 3);
                }
            } else if (f & 0x200) {
                lbl_80347318->state = 2;
                t->state = 7;
                SePlay(0, 1, 7);
            } else if (f & 0x400) {
                w->x7 |= 2;
                t->state = 6;
                SePlay(0, 1, 6);
            }
        }
        break;
    }
    case 6:
        if (lbl_8030A6D4[lbl_8034757C].x8 != 0) {
            t->state = 2;
            t->work->x7 &= ~2;
            SePlay(0, 1, 7);
        }
        break;
    case 7:
        t->flags |= 0x40;
        lbl_80347314 = 0;
        fn_80023D04(t->work);
        lbl_80346C10 = 0;
        break;
    case 3:
        return;
    case 4:
    case 5:
        break;
    }
}

extern void fn_80022F1C(void *p);


extern void fn_80078EFC(void);
extern void fn_8007B328(s32 idx, s8 val, s32 kind);
extern s32 fn_80078478(s32 i);




void fn_8007B958(Task_8007BEB4* t, s32 sel, s16 item, s32 kind) {
    s8 val;
    s32 r;
    switch (kind) {
    case 8:
        val = lbl_80347390->xa;
        break;
    case 1:
    case 2:
        val = lbl_802C4BF0[item].cost;
        break;
    case 5:
    default:
        val = 0;
        break;
    }
    fn_8007B328(sel, val, kind);
    lbl_80309174[sel].x6 = item;
    r = fn_80078478(sel);
    switch ((u8)r) {
    case 1:
        if (lbl_8034730C == 0) {
            lbl_8034730C = fn_802268E8(t, fn_80078EFC);
            t->state = 4;
        }
        break;
    case 3:
        if (lbl_80347310 == 0) {
            lbl_80347310 = fn_802268E8(t, fn_800794D8);
            t->state = 4;
        }
        break;
    case 0:
    case 2:
    case 4:
    case 5:
    case 6:
        lbl_80309174[sel].b4 = sel;
        switch (kind) {
        case 1:
            fn_8007D318(lbl_80347314);
            break;
        case 2:
            if (lbl_80347304 != 0) {
                fn_8007D318(lbl_80347304);
            }
            break;
        case 5:
            fn_8007D318(lbl_80347308);
            break;
        case 8:
            if (lbl_80347300 != 0) {
                fn_8007D318(lbl_80347300);
            }
            break;
        }
        lbl_80347338 = 3;
        break;
    default:
        if ((u8)r >= 0x20 && (u8)r < 0x40 && lbl_80347310 == 0) {
            lbl_80347310 = fn_802268E8(t, fn_800794D8);
            t->state = 4;
        }
        if ((u8)r >= 0x40 && (u8)r < 0x60) {
            lbl_80347338 = 3;
            switch (kind) {
            case 1:
                fn_8007D318(lbl_80347314);
                break;
            case 2:
                if (lbl_80347304 != 0) {
                    fn_8007D318(lbl_80347304);
                }
                break;
            case 5:
                fn_8007D318(lbl_80347308);
                break;
            }
        }
        if ((u8)r >= 0x60 && (u8)r < 0xc8 && lbl_8034730C == 0) {
            lbl_8034730C = fn_802268E8(t, fn_80078EFC);
            t->state = 4;
        }
        if ((u8)r >= 0xc8) {
            lbl_80347338 = 3;
            switch (kind) {
            case 1:
                fn_8007D318(lbl_80347314);
                break;
            case 2:
                if (lbl_80347304 != 0) {
                    fn_8007D318(lbl_80347304);
                }
                break;
            case 5:
                fn_8007D318(lbl_80347308);
                break;
            }
        }
        break;
    }
}

void fn_8007C7F8(Hud* out)
{
    int i;
    Chr_UNIT0000* p;
    s16 f;
    u32 bits;
    s16 v;
    HudEnt* e;

    out->n = 0;
    for (i = 0; i < 4; i++) {
        p = lbl_80309DE4[i];
        e = &out->e[i];
        if (p != 0) {
            f = 0;
            e->lv = lbl_8030B7F4.chr[lbl_8030B7F4.party[i]].xb;
            e->hp = p->score;
            e->mp = p->x18;
            e->x6 = p->xfe;
            e->x8 = p->xff;
            e->xc = lbl_80309DE4[i]->x100;
            bits = p->w1c;
            if (bits & 0x80) f = 1;
            if (bits & 0x100) f += 2;
            if (bits & 0x200) f += 4;
            if (bits & 0x400) f += 8;
            if (bits & 0x800) f += 0x10;
            if (bits & 0x1000) f += 0x20;
            if (bits & 0x4000) f += 0x40;
            v = p->xe;
            if (v & 0x1) f |= 0x80;
            if (v & 0x2) f |= 0x80;
            if (v & 0x8) f |= 0x80;
            if (v & 0x10) f |= 0x80;
            if (v & 0x4) f |= 0x100;
            if (v & 0x20) f |= 0x200;
            if (v & 0x40) f |= 0x200;
            if (v & 0x80) f |= 0x200;
            if (v & 0x100) f |= 0x200;
            if (v & 0x200) f |= 0x400;
            e->st = f;
        }
    }
    fn_80022F1C(out);
}

void fn_8007D318(Task_8007BEB4* p) {
    if (p == 0) {
        return;
    }
    p->state = 7;
}

#define CLEAR(b)                          \
    lbl_80309700[b]->work->x3c = 0;       \
    lbl_80309700[b]->work->x40 = 0;       \
    lbl_80309700[b]->work->x44 = -1;      \
    lbl_80309700[b]->work->x46 = -1;      \
    lbl_80309700[b]->work->x48 = -1;      \
    lbl_80309700[b]->work->x4a = -1

#define SETFN(f)                       \
    lbl_80309700[id]->update = f;        \
    lbl_80309700[id]->state = 0

void fn_8007D3D0(void) {
    lbl_80347318 = fn_802268E8(lbl_803475A8, fn_8007CAB0);
    if (lbl_80347318 == 0) {
        for (;;) {
        }
    }
    lbl_80347314 = 0;
    lbl_80347308 = 0;
    lbl_80347304 = 0;
    lbl_803472FC = 0;
    lbl_80347310 = 0;
    lbl_8034730C = 0;
    lbl_80347300 = 0;
}

void fn_8007D32C(void)
{
    if (lbl_80347318 != 0) {
        lbl_80347318->state = 7;
    }
    if (lbl_80347314 != 0) {
        lbl_80347314->state = 7;
    }
    if (lbl_80347310 != 0) {
        lbl_80347310->state = 7;
    }
    if (lbl_8034730C != 0) {
        lbl_8034730C->state = 7;
    }
    if (lbl_80347308 != 0) {
        lbl_80347308->state = 7;
    }
    if (lbl_80347304 != 0) {
        lbl_80347304->state = 7;
    }
    if (lbl_80347300 != 0) {
        lbl_80347300->state = 7;
    }
    if (lbl_803472FC != 0) {
        lbl_803472FC->state = 7;
    }
}

/* Implicit int: declared s32, no return statement. */
s32 fn_8007BC6C(s32 sel, SaveChar* pl, List* w) {
    s32 k;
    s32 n = 0;
    s32 have;
    s32 i;
    w->x1 = 0;
    have = lbl_80347390->xa;
    for (k = 0x24; k < 0x3c; k++) {
        if (fn_801F3F88(pl, k) != 0) {
            const SkillData* t = &lbl_802C4BF0[k];
            if (t->speed == 1 || t->speed == 2) {
                s32 b = t->cost;
                w->e[n].type = k;
                w->e[n].sort = t->sort;
                w->e[n].p = t;
                w->e[n].id = b;
                w->e[n].w = lbl_802F6918[k];
                if (have >= b) {
                    w->e[n].on = 1;
                } else {
                    w->e[n].on = 0;
                }
                if (k == 0x39 && (lbl_80309DE4[lbl_80347330]->w1c & 0x1000) != 0) {
                    w->e[n].on = 0;
                }
                n++;
            }
        }
    }
    w->count = n;
    for (i = n; i < 8; i++) {
        w->e[i].type = -1;
        w->e[i].sort = 10000;
        w->e[i].p = 0;
        w->e[i].id = -1;
        w->e[i].on = 0;
    }
    qsort(w->e, w->count, 0x10, fn_800786B0);
    w->x2 = 1;
    w->x6 = 0;
    w->x7 = 0;
}

void fn_8007C194(List* l) {
    Ent* e;
    s32 n = 0;
    s16 v;
    s32 i;
    l->x1 = 0;
    v = lbl_80347390->xa;
    if (lbl_80346C0C == 2 || lbl_80346C0C == 5) {
        l->e[0].type = 0x3D;
        n = 1;
        l->e[0].p = &lbl_802C4BF0[61];
        l->e[0].id = v;
        l->e[0].w = lbl_802F6918[0xF4 / 4];
        l->e[0].on = 1;
    }
    if (lbl_80346C0C == 3 || lbl_80346C0C == 5) {
        e = &l->e[n];
        e->type = 0x3C;
        e->p = &lbl_802C4BF0[60];
        e->id = v;
        e->w = lbl_802F6918[0xF0 / 4];
        e->on = 1;
        n++;
    }
    l->count = n;
    for (i = n; i < 8; i++) {
        l->e[i].type = -1;
        l->e[i].p = 0;
        l->e[i].id = -1;
        l->e[i].on = 0;
    }
    l->x2 = 1;
    l->x6 = 0;
    l->x7 = 0;
}

void fn_80078AD4(const char* src)
{
    int n;
    int left;
    int right;
    int pad;
    int i;
    char* dst;

    for (n = 0; n < 0x12; n += 2) {
        if ((s8)src[n] == 0) break;
    }
    pad = 16 - n;
    dst = lbl_80347320 + 0xb;
    left = pad / 2;
    right = pad - left;
    for (i = 0; i < left; i++) {
        *dst++ = ' ';
    }
    for (i = 0; i < n; i++) {
        *dst++ = *src++;
    }
    for (i = 0; i < right; i++) {
        *dst++ = ' ';
    }
    *dst = 0;
}

void fn_8007C600(u32 arg)
{
    s32 slot;
    if (lbl_80346C14[arg] == 0) return;
    slot = lbl_80347330;
    switch (arg) {
    case 0:
    case 4:
        lbl_80347338 = 3;
        lbl_80309174[slot].b4 = slot;
        lbl_80309174[slot].x6 = -1;
        break;
    case 6:
        if (lbl_80346C14[6] == 2) {
            if (lbl_80347300 == 0) {
                lbl_80347318->state = 4;
                lbl_80347300 = fn_802268E8(lbl_80347318, fn_8007C344);
            }
        } else {
            lbl_8034733C = 2;
            lbl_80347338 = 0;
            fn_8007D32C();
            lbl_80309174[0].x0 = 4;
            lbl_80309174[0].b4 = 0;
            lbl_80309174[0].x6 = -1;
            lbl_80309174[1].x0 = 4;
            lbl_80309174[1].b4 = 1;
            lbl_80309174[1].x6 = -1;
            lbl_80309174[2].x0 = 4;
            lbl_80309174[2].b4 = 2;
            lbl_80309174[2].x6 = -1;
            lbl_80309174[3].x0 = 4;
            lbl_80309174[3].b4 = 3;
            lbl_80309174[3].x6 = -1;
        }
        break;
    case 3:
        if (lbl_80347310 == 0) {
            lbl_80347318->state = 5;
            lbl_80347310 = fn_802268E8(lbl_80347318, fn_800794D8);
        }
        break;
    case 1:
        if (lbl_80347314 == 0) {
            lbl_80347318->state = 4;
            lbl_80347314 = fn_802268E8(lbl_80347318, fn_8007B5B0);
        }
        break;
    case 5:
        if (lbl_80347308 == 0) {
            lbl_80347318->state = 4;
            lbl_80347308 = fn_802268E8(lbl_80347318, fn_8007A890);
        }
        break;
    case 2:
        if (lbl_80347304 == 0) {
            lbl_80347318->state = 4;
            lbl_80347304 = fn_802268E8(lbl_80347318, fn_8007BEB4);
        }
        break;
    }
    lbl_80309174[lbl_80347330].x0 = arg;
}

void fn_8007BEB4(Task_8007BEB4* t) {
    List* w;
    s32 sel;
    switch (t->state) {
    case 0:
        t->state = 1;
        w = fn_801E1C7C(0x88);
        t->work = w;
        sel = lbl_8030B7F4.party[lbl_80347330];
        fn_8007BC6C(sel, &lbl_8030B7F4.chr[sel], w);
        w->x3 = 0;
        w->x4 = 0;
        w->x5 = 1;
        w->x7 |= 1;
    case 1:
        if (lbl_80346C10 == 0) {
            fn_80023D14(t->work);
            t->state = 2;
            lbl_80346C10 = 1;
        }
        break;
    case 2: {
        u32 f;
        w = t->work;
        w->x6 = 0;
        if (w->x3 < 0) break;
        if ((s8)w->count > 1) {
            f = lbl_8030A6D4[lbl_8034757C].flags;
            if (f & 8) {
                w->x6 = 1;
                SePlay(0, 1, 0);
                break;
            } else if (f & 4) {
                w->x6 = 2;
                SePlay(0, 1, 0);
                break;
            }
        }
        f = lbl_8030A6D4[lbl_8034757C].x8;
        if (f & 0x100) {
            Ent* e = &w->e[w->x3];
            if (e->on != 0) {
                SePlay(0, 1, 2);
                t->state = 4;
                fn_8007B958(t, lbl_80347330, e->type, 2);
                ((ChrState_8007BEB4*)lbl_80309174)[lbl_80347330].x0 = 2;
            } else {
                SePlay(0, 1, 3);
            }
        } else if (f & 0x200) {
            lbl_80347318->state = 2;
            w->x6 = 4;
            t->state = 7;
            w->x7 &= ~1;
            SePlay(0, 1, 7);
        } else if (f & 0x400) {
            w->x7 |= 2;
            t->state = 6;
            SePlay(0, 1, 6);
        }
        break;
    }
    case 6:
        if (lbl_8030A6D4[lbl_8034757C].x8 != 0) {
            t->state = 2;
            t->work->x7 &= ~2;
            SePlay(0, 1, 7);
        }
        break;
    case 7:
        t->flags |= 0x40;
        (*(u8**)&lbl_80347304) = 0;
        fn_80023D04(t->work);
        lbl_80346C10 = 0;
        break;
    case 3:
        return;
    case 4:
    case 5:
        break;
    }
}

void fn_8007C344(Task_8007BEB4* t) {
    List* w;
    switch (t->state) {
    case 0:
        t->state = 1;
        w = fn_801E1C7C(0x88);
        t->work = w;
        fn_8007C194(w);
        w->x3 = 0;
        w->x4 = 0;
        w->x5 = 1;
        w->x7 |= 1;
    case 1:
        if (lbl_80346C10 == 0) {
            fn_80023D14(t->work);
            t->state = 2;
            lbl_80346C10 = 1;
        }
        break;
    case 2: {
        u32 f;
        w = t->work;
        w->x6 = 0;
        if (w->x3 < 0) break;
        if ((s8)w->count > 1) {
            f = lbl_8030A6D4[lbl_8034757C].flags;
            if (f & 8) {
                w->x6 = 1;
                SePlay(0, 1, 0);
                break;
            } else if (f & 4) {
                w->x6 = 2;
                SePlay(0, 1, 0);
                break;
            }
        }
        f = lbl_8030A6D4[lbl_8034757C].x8;
        if (f & 0x100) {
            Ent* e = &w->e[w->x3];
            if (e->on != 0) {
                SePlay(0, 1, 2);
                t->state = 4;
                fn_8007B958(t, lbl_80347330, e->type, 8);
                lbl_80309174[lbl_80347330].x0 = 8;
            } else {
                SePlay(0, 1, 3);
            }
        } else if (f & 0x200) {
            lbl_80347318->state = 2;
            w->x6 = 4;
            t->state = 7;
            w->x7 &= ~1;
            SePlay(0, 1, 7);
        } else if (f & 0x400) {
            w->x7 |= 2;
            t->state = 6;
            SePlay(0, 1, 6);
        }
        break;
    }
    case 6:
        if (lbl_8030A6D4[lbl_8034757C].x8 != 0) {
            t->state = 2;
            t->work->x7 &= ~2;
            SePlay(0, 1, 7);
        }
        break;
    case 7:
        t->flags |= 0x40;
        lbl_80347300 = 0;
        fn_80023D04(t->work);
        lbl_80346C10 = 0;
        break;
    case 3:
        return;
    case 4:
    case 5:
        break;
    }
}

/* Uses a goto for the loop's early exit: the original jumps from inside the party loop
   straight to the fn_801F52AC test; break + "i > 3" and an inline returning 0/1 both cost 6+ lines. */
s32 fn_8007C9CC(void)
{
    s32 i;
    s32 r = 0;
    if ((lbl_80310B3C.x24 & 0x10000000) && lbl_8030B7F4.party[lbl_80347330] == 0
        && lbl_80347390->x6 == lbl_80347390->x8) {
        for (i = 0; i <= 3; i++) {
            if (!fn_80078610(i) || (lbl_80309DE4[i]->w1c & 0x6d00)) {
                goto check;
            }
        }
        if (lbl_8030B7F4.x348 >= 100) {
            r = 2;
        }
    check:
        if (fn_801F52AC() != 0) {
            r += 3;
        }
    }
    return r;
}
extern void fn_80079F74(List* w);
void fn_80079C5C(Task_8007BEB4* t);
extern s8 fn_801F4CA0(void);
extern void fn_80022AAC(void* p);
extern void fn_80022A9C(void* w);
extern void fn_80076584(s32 i);

void fn_80079C5C(Task_8007BEB4* t) {
    List* m;
    List* w;
    switch (t->state) {
    case 0: {
        w = fn_801E1C7C(0x88);
        t->work = w;
        w->x3 = -1;
        w->count = 6;
        w->x2 = fn_801F4CA0();
        w->x1 = lbl_80309DE4[lbl_80347330]->x100;
        w->x7 |= 1;
        fn_80022AAC(w);
        t->state = 2;
        break;
    }
    case 2: {
        w = t->work;
        if (lbl_8030A6D4[lbl_8034757C].flags & 1) {
            s32 mask;
            s32 cur;
            s32 i;
            cur = w->x1;
            mask = w->x2;
            i = cur;
            do {
                i--;
                if (i < 0) i = 5;
            } while ((mask & (1 << i)) == 0);
            if (i != cur) {
                w->x1 = i;
                SePlay(0, 1, 0);
            }
        }
        if (lbl_8030A6D4[lbl_8034757C].flags & 2) {
            s32 mask;
            s32 cur;
            s32 i;
            cur = w->x1;
            mask = w->x2;
            i = cur;
            do {
                i++;
                if (i > 5) i = 0;
            } while ((mask & (1 << i)) == 0);
            if (i != cur) {
                w->x1 = i;
                SePlay(0, 1, 0);
            }
        }
        {
            u32 f = lbl_8030A6D4[lbl_8034757C].x8;
            if (f & 0x100) {
                s8 sv;
                Hud* o;
                s32 i;
                lbl_80347308->state = 3;
                t->state = 7;
                lbl_80309DE4[lbl_80347330]->x100 = w->x1;
                m = lbl_80347308->work;
                lbl_80309DE4[lbl_80347330]->xb6 = m->e[m->x3].type;
                sv = m->x3;
                fn_80079F74(lbl_80347308->work);
                m->x3 = sv;
                m->x7 |= 1;
                fn_80076584(lbl_80347330);
                o = lbl_80347318->hud;
                for (i = 0; i < 4; i++) {
                    if (lbl_80309DE4[i]) o->e[i].xc = lbl_80309DE4[i]->x100;
                }
                SePlay(0, 1, 0x16);
                lbl_80347318->state = 2;
                lbl_80347308->state = 7;
                t->state = 7;
            } else if (f & 0x200) {
                lbl_80347308->state = 3;
                t->state = 7;
                SePlay(0, 1, 7);
            }
        }
        break;
    }
    case 7:
        fn_80022A9C(t->work);
        t->flags |= 0x40;
        lbl_803472FC = 0;
        break;
    }
}

void fn_8007A890(Task_8007BEB4* t) {
    List* w;
    s32 mask;
    s32 cur;
    s32 n;
    u32 f;
    s8 sel;
    s32 who;
    Ent* e;

    switch (t->state) {
    case 0:
        t->state = 1;
        w = fn_801E1C7C(0x88);
        t->work = w;
        w->x1 = 9;
        w->x4 = 0;
        fn_80079F74(w);
        w->x3 = -1;
        w->x7 |= 1;
        break;
    case 1:
        if (lbl_80346C10 == 0) {
            fn_80023D14(t->work);
            t->state = 2;
            lbl_80346C10 = 1;
            t->work->x4 = 0;
        }
        break;
    case 2:
        w = t->work;
        if (lbl_8030A6D4[lbl_8034757C].flags & 1) {
            cur = w->x1;
            mask = w->x2;
            n = cur;
            do {
                n--;
                if (n < 9) {
                    n = 14;
                }
            } while (!(mask & (1 << (n - 9))));
            if (n != cur) {
                w->x1 = n;
                w->x4 = 0;
                fn_80079F74(w);
                w->x3 = -1;
                w->x7 |= 1;
                SePlay(0, 1, 0);
            }
        }
        if (lbl_8030A6D4[lbl_8034757C].flags & 2) {
            mask = w->x1;
            cur = w->x2;
            n = mask;
            do {
                n++;
                if (n > 14) {
                    n = 9;
                }
            } while (!(cur & (1 << (n - 9))));
            if (n != mask) {
                w->x1 = n;
                w->x4 = 0;
                fn_80079F74(w);
                w->x3 = -1;
                w->x7 |= 1;
                SePlay(0, 1, 0);
            }
        }
        f = lbl_8030A6D4[lbl_8034757C].x8;
        if (f & 0x100) {
            w->x3 = 0;
            t->state = 3;
            SePlay(0, 1, 2);
        } else if (f & 0x200) {
            lbl_80347318->state = 2;
            t->state = 7;
            SePlay(0, 1, 7);
        } else {
            if (lbl_8030A6D4[lbl_8034757C].flags & 8) {
                w->x3 = w->count - 1;
                t->state = 3;
                SePlay(0, 1, 0);
            }
            if (lbl_8030A6D4[lbl_8034757C].flags & 4) {
                w->x3 = 0;
                t->state = 3;
                SePlay(0, 1, 0);
            }
        }
        break;
    case 3:
        w = t->work;
        w->x6 = 0;
        if (lbl_8030A6D4[lbl_8034757C].x8 & 0x200) {
            t->state = 2;
            w->x3 = -1;
            SePlay(0, 1, 0);
        }
        if (w->x3 < 0) {
            break;
        }
        if ((s8)w->count == 0) {
            break;
        }
        f = lbl_8030A6D4[lbl_8034757C].flags;
        if (f & 8) {
            SePlay(0, 1, 0);
            w->x6 = 1;
            if (w->x3 == 0) {
                t->state = 2;
                w->x3 = -1;
                w->x6 = 0;
            }
        } else if (f & 4) {
            SePlay(0, 1, 0);
            w->x6 = 2;
            if (w->x3 == (s8)w->count - 1) {
                t->state = 2;
                w->x3 = -1;
                w->x6 = 0;
            }
        } else {
            s32 old = w->x4;
            if (f & 1) {
                w->x4--;
                if (w->x4 < 0) {
                    w->x4 = w->x5 - 1;
                }
                if (old != w->x4) {
                    SePlay(0, 1, 0);
                }
                fn_80079F74(w);
                w->x7 |= 1;
                w->x3 = 0;
            } else if (f & 2) {
                w->x4++;
                if (w->x4 >= w->x5) {
                    w->x4 = 0;
                }
                if (old != w->x4) {
                    SePlay(0, 1, 0);
                }
                fn_80079F74(w);
                w->x3 = 0;
                w->x7 |= 1;
            } else {
                f = lbl_8030A6D4[lbl_8034757C].x8;
                if (f & 0x100) {
                    sel = w->x3;
                    who = lbl_80347330;
                    e = &w->e[sel];
                    if (e->on == 0) {
                        break;
                    }
                    switch (w->x1) {
                    case 10:
                        if (lbl_803472FC == 0) {
                            t->state = 4;
                            lbl_803472FC = fn_802268E8(lbl_80347308, fn_80079C5C);
                            SePlay(0, 1, 2);
                        }
                        break;
                    case 11:
                        if (w->e[sel].id == -1) {
                            lbl_80309DE4[who]->x102 = -1;
                        } else {
                            lbl_80309DE4[who]->x102 = w->e[sel].type;
                            SePlay(0, 1, 0x16);
                        }
                        sel = w->x3;
                        fn_80079F74(w);
                        w->x3 = sel;
                        w->x7 |= 1;
                        fn_80076584(who);
                        lbl_80347318->state = 2;
                        t->state = 7;
                        break;
                    case 12:
                        if (w->e[sel].id == -1) {
                            lbl_80309DE4[who]->x104 = -1;
                        } else {
                            lbl_80309DE4[who]->x104 = w->e[sel].type;
                            SePlay(0, 1, 0x16);
                        }
                        sel = w->x3;
                        fn_80079F74(w);
                        w->x3 = sel;
                        w->x7 |= 1;
                        fn_80076584(who);
                        lbl_80347318->state = 2;
                        t->state = 7;
                        break;
                    case 9:
                        fn_8007B958(t, who, e->type, 5);
                        lbl_80309174[lbl_80347330].x0 = 5;
                        SePlay(0, 1, 2);
                        break;
                    }
                } else if (f & 0x400) {
                    w->x7 |= 2;
                    t->state = 6;
                    SePlay(0, 1, 6);
                }
            }
        }
        break;
    case 6:
        if (lbl_8030A6D4[lbl_8034757C].x8 != 0) {
            t->state = 3;
            t->work->x7 &= ~2;
            SePlay(0, 1, 7);
        }
        break;
    case 7:
        t->flags |= 0x40;
        lbl_80347308 = 0;
        fn_80023D04(t->work);
        lbl_80346C10 = 0;
        break;
    case 4:
    case 5:
        break;
    }
}

void fn_80078A20(s32 a, s32 b, s32 kind) {
    const char* s;
    switch (kind) {
    case 11:
        s = lbl_802AD440[b + 0x24].name;
        break;
    case 12:
        if (a <= 3) {
            s = lbl_802C4BF0[b].name;
            lbl_80347320[0xa] = 1;
        } else {
            s = lbl_802AD440[b].name;
        }
        break;
    case 13:
    default:
        if (a <= 3) {
            lbl_80347320[0xa] = 1;
        }
        s = lbl_802C7C34[b].name;
        break;
    }
    fn_80078AD4(s);
}

typedef struct EnemyData {
    u8 pad[0x24];
    s32 x24;    /* max HP */
} EnemyData;
extern s16 lbl_80302BD8[12];
extern s32 lbl_803472E8;
extern s32 fn_801F4D14(void);
extern EnemyData* fn_80077B88(u8 id);
extern s32 fn_802182F4(s32 unused, s32 n, s8 a, s8 b, ...);
extern s8 lbl_80346C00[4];

/* fn_8007D42C (unit_80074D9C): the battle music task (fn_80078658 mode 1). It snapshots the enemy
 * slots, then keeps comparing the party's and the enemies' remaining HP and switches between the
 * calm (state 2), pinch (3) and winning (4) phrase sets of the battle track (fn_802182F4). */
void fn_8007D42C(Obj_8007DE54_8007D42C* p)
{
    s32 i;
    s32 max;
    s32 hp;
    s32 h;
    s32 m;
    s32 ehp;
    s32 emax;

    switch (p->state) {
    case 0:
        p->state = 1;
        p->buf = fn_801E1C7C(4);
        for (i = 0; i < sizeof(lbl_80302BD8) / sizeof(lbl_80302BD8[0]); i++) {
            lbl_80302BD8[i] = lbl_80309DCC[i];
        }
    case 1:
        if (fn_801F4D14()) {
            p->state = 2;
        } else {
            p->state = 3;
        }
        break;
    case 3:
        max = 0;
        hp = 0;
        for (i = 0; i < 4; i++) {
            if (lbl_80309DE4[i] != NULL) {
                m = lbl_80309DE4[i]->x18;
                h = lbl_80309DE4[i]->score;
                if ((f32)h / (f32)m < 0.25f) {
                    return;
                }
                max += m;
                hp += h;
            }
        }
        if ((f32)hp / (f32)max < 0.75) {
            return;
        }
        emax = 1;
        ehp = 0;
        for (i = 4; i <= 11; i++) {
            if (lbl_80302BD8[i] != -1 && lbl_80302BD8[i] >= 0x80) {
                emax += fn_80077B88(lbl_80302BD8[i])->x24;
                if (fn_80078610(i)) {
                    ehp += lbl_80309DE4[i]->score;
                }
            }
        }
        if ((f32)ehp / (f32)emax >= 0.3) {
            goto calm3;
        }
        p->state = 4;
        if (lbl_803472E8 == 1) {
            p->buf[0] = fn_802182F4(0, 5, 4, 0xe, 4, 8, 4, 9, 4, 0xa, 4, 0xb);
        } else {
            p->buf[0] = fn_802182F4(0, 3, 4, 0xb, 4, 6, 4, 7);
        }
        break;
    calm3:
        p->state = 2;
        if (lbl_803472E8 != 1) {
            p->buf[0] = fn_802182F4(0, 5, 4, 0xa, 4, 0, 4, 1, 4, 2, 4, 3);
        }
        break;
    case 4:
        max = 0;
        hp = 0;
        for (i = 0; i < 4; i++) {
            if (lbl_80309DE4[i] != NULL) {
                m = lbl_80309DE4[i]->x18;
                h = lbl_80309DE4[i]->score;
                if ((f32)h / (f32)m < 0.25f) {
                    goto pinch4;
                }
                max += m;
                hp += h;
            }
        }
        if ((f32)hp / (f32)max < 0.4) {
            goto pinch4;
        }
        emax = 1;
        ehp = 0;
        for (i = 4; i <= 11; i++) {
            if (lbl_80302BD8[i] != -1 && lbl_80302BD8[i] >= 0x80) {
                emax += fn_80077B88(lbl_80302BD8[i])->x24;
                if (fn_80078610(i)) {
                    ehp += lbl_80309DE4[i]->score;
                }
            }
        }
        if ((f32)ehp / (f32)emax >= 0.5) {
            goto calm4;
        }
        break;
    pinch4:
        p->state = 3;
        if (lbl_803472E8 == 1) {
            p->buf[0] = fn_802182F4(0, 9, 4, 0xd, 4, 0, 4, 1, 4, 2, 4, 3, 4, 4, 4, 5, 4, 6, 4, 7);
        } else {
            p->buf[0] = fn_802182F4(0, 3, 4, 8, 4, 4, 4, 5);
        }
        break;
    calm4:
        p->state = 2;
        if (lbl_803472E8 == 1) {
            p->buf[0] = fn_802182F4(0, 9, 4, 0xd, 4, 0, 4, 1, 4, 2, 4, 3, 4, 4, 4, 5, 4, 6, 4, 7);
        } else {
            p->buf[0] = fn_802182F4(0, 5, 4, 9, 4, 0, 4, 1, 4, 2, 4, 3);
        }
        break;
    default:
        max = 0;
        hp = 0;
        for (i = 0; i < 4; i++) {
            if (lbl_80309DE4[i] != NULL) {
                m = lbl_80309DE4[i]->x18;
                h = lbl_80309DE4[i]->score;
                if ((f32)h / (f32)m < 0.25f) {
                    goto pinch;
                }
                max += m;
                hp += h;
            }
        }
        if ((f32)hp / (f32)max < 0.4) {
            goto pinch;
        }
        emax = 1;
        ehp = 0;
        for (i = 4; i <= 11; i++) {
            if (lbl_80302BD8[i] != -1 && lbl_80302BD8[i] >= 0x80) {
                emax += fn_80077B88(lbl_80302BD8[i])->x24;
                if (fn_80078610(i)) {
                    ehp += lbl_80309DE4[i]->score;
                }
            }
        }
        if ((f32)ehp / (f32)emax < 0.5) {
            goto win;
        }
        break;
    pinch:
        p->state = 3;
        if (lbl_803472E8 != 1) {
            p->buf[0] = fn_802182F4(0, 3, 4, 0xc, 4, 4, 4, 5);
        }
        break;
    win:
        p->state = 4;
        if (lbl_803472E8 == 1) {
            p->buf[0] = fn_802182F4(0, 5, 4, 0xe, 4, 8, 4, 9, 4, 0xa, 4, 0xb);
        } else {
            p->buf[0] = fn_802182F4(0, 3, 4, 0xd, 4, 6, 4, 7);
        }
        break;
    case 0xff:
        fn_80217830(1);
        p->flags18 |= 0x40;
        lbl_8034736C = 0;
        break;
    }
}

extern s8 lbl_80346C00[4];
int fn_80078D24(int arg)
{
    int i;
    int v;
    s8 kind = fn_80081FEC(arg);

    v = arg;

    switch (kind) {
    case 0x1d:
    case 0x1e:
        for (i = 0; i < 4; i++) {
            if (lbl_80309DE4[i] != 0 && (lbl_80309DE4[i]->w1c & 0x85E80) != 0) {
                v = i;
                break;
            }
        }
        break;
    case 0x1b:
    case 0x1c:
    case 0x2f:
        for (i = 0; i < 4; i++) {
            if (lbl_80309DE4[i] != 0 && (lbl_80309DE4[i]->w1c & 0x2100) != 0) {
                v = i;
                break;
            }
        }
        break;
    }
    {
        s8* p = lbl_80346C00;
        for (i = 0; i < 4; i++) {
            s32 c = p[i];
            if (c == v) {
                return i;
            }
        }
    }
    return 0;
}

