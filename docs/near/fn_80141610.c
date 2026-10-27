/* fn_80141610 (5.7 KB, the party-member menu's state machine, work at lbl_80306738): a near miss.
 * With registers masked 15 lines differ; the register numbering is off almost everywhere.
 *
 * The cause found so far: the original reaches its four messages (lbl_802B3458, lbl_802B34B0 +0,
 * +0x48, +0x84) through one pooled base register set up in the prologue (`addi r26, ...` then
 * `addi r3, r26, 0x0`), like the shop unit's .rodata base. That only comes out with the file's
 * .rodata defined in C at its original offsets (see matching.md, "A function can reach its file's
 * data through the section base"); the pooled register changes the colouring of the whole
 * function. The other open lines are zeros the original copies from a live zero (`mr r25, r26`)
 * where this emits `li`.
 *
 * Found on the way: the inlines it uses are NameCount, StateValid, MemberStatus and TaskStop from
 * the unit; the member-sum and the "find a member" search are inline helpers here. The state-9
 * switch has an empty `case 0:` (its compare tree tests 1 first); the record loop reads the
 * kind into an int (`lbz; cmpwi`, not `cmplwi`).
 */
#include "../src/game/unit_8013D400.c" /* found through -i include */
/* fn_80141610: the party-member menu's state machine (lbl_80306738). */
typedef struct MenuW {
    s8 state;            /* 0x00 */
    s8 b1;               /* 0x01 */
    s8 mem;              /* 0x02 member */
    s8 kind;             /* 0x03 */
    u8 b4[6];            /* 0x04 */
    u8 xa;               /* 0x0A */
    u8 xb;               /* 0x0B */
    Task* task;   /* 0x0C */
    u8 pad10[6];
    s16 h16;             /* 0x16 */
    s16 h18;             /* 0x18 */
    s16 h1a;             /* 0x1A */
    s16 h1c;             /* 0x1C */
    s16 h1e;             /* 0x1E */
} MenuW;

typedef struct MenuTask {
    u8 pad0[0x18];
    u8 flags;            /* 0x18 */
    u8 state;            /* 0x19 */
    u8 pad1a[0xa];
    void* x24;           /* 0x24 */
    void* x28;           /* 0x28 */
} MenuTask_80141610;

typedef struct {
    u8 pad0[0xb];
    u8 bb;               /* 0x0B */
    u8 bc;               /* 0x0C */
    s8 bd;               /* 0x0D */
    s8 be;               /* 0x0E */
} MenuEnt;

typedef struct {
    u8 pad0[0x1f];
    s8 b1f;
    s8 b20;
    u8 pad21;
} MenuDst;

typedef struct {
    u8 pad0[0x11];
    s8 x11;              /* 0x11 */
    u8 pad12[2];
    s32 x14;             /* 0x14 */
    s32 x18;             /* 0x18 */
    u8 pad1c[0xe0];
    s8 xfc;              /* 0xFC */
} MenuSys;

typedef struct {
    u8 pad0[0x84];
    u32 x84;             /* 0x84 */
    u8 pad88[0x74];
    u32 xfc;             /* 0xFC */
} MenuFlags;

typedef s32 (*MenuFn)(MenuW* w);
typedef struct { u8 kind; s8 key; s8 member; u8 pad3; s8 level; } MenuRec;
#define MENU_REC ((MenuRec*)(lbl_80308E90 + 0x14))

extern s32 lbl_803472D8;
extern MenuFlags lbl_80310B3C;
extern void* lbl_80347590;
extern s32 lbl_803473EC;
extern s32 lbl_803473E8;
extern MenuFn lbl_802E5BC0[8];
extern MenuFn lbl_802E5BE0[8];
extern char lbl_802B3458[];
extern void fn_801355A4(void* t);
extern void fn_80136848(s32 i, s32 k);
extern void fn_80140800(s32 m);
extern void* fn_801298CC(void);
extern void fn_801300E0(s32* a);
extern void fn_80130264(s32* b);
extern void fn_80130040(void);
extern void fn_80130338(s32 a);
extern void fn_8012FF48(s8 n);
extern void fn_80130304(s32 a);
extern s32 fn_8012FF08(void);
extern Task* fn_80226848(void* list, void (*fn)(void*), s32 pri);
extern void fn_80140A14(MenuW* w);
extern void fn_8015A888(void);
extern void fn_801330FC(u8 a);
extern void fn_801330E4(u8 a);
extern void fn_801330CC(s32 a);
extern void fn_801330B4(s32 a);
extern void fn_8013309C(s32 a);
extern void fn_80133084(s32 a);
extern void fn_8013306C(MenuSys* s);
extern void fn_80133030(s32* v);
extern void fn_80133114(s32 a);
extern void fn_80131598(u8 m);
extern void fn_801315EC(u8 m);
extern void fn_8012C4E8(void);
extern void fn_8013F8F8(s32 m, s16 h);
extern s32 fn_801358A0(s32 i, s32 m, s32 a, s32 b, s32 n);
extern void fn_8012AEA8(s32 k);
extern s32 fn_80138930(void* buf, MenuEnt* e, s32 k);
extern void fn_801353A8(void);
extern void fn_8012F458(s32 a);
extern void fn_8012F468(char* s);
extern void fn_8012F478(s32 a);
extern void fn_801315FC(s32 a);

#define MENU_PAD (*(Pad_80141610**)&lbl_80311A60[0])
typedef struct { u8 pad0[8]; u32 x8; } Pad_80141610;

static inline void MenuRecClear(s32 i)
{
    if (i >= -4 && i < 4) {
        ((s8*)lbl_80308E90)[i * 5 + 0x14] = -1;
        ((s8*)lbl_80308E90)[i * 5 + 0x15] = -1;
        ((s8*)lbl_80308E90)[i * 5 + 0x16] = -1;
        ((s8*)lbl_80308E90)[i * 5 + 0x17] = -1;
        ((s8*)lbl_80308E90)[i * 5 + 0x18] = -1;
    }
}

static inline s32 MenuDstSum(MenuDst* d)
{
    s32 v = 100;

    if (d != NULL) {
        v = d->b1f + d->b20;
    }
    return v;
}

static inline s32 MenuMemberSum(s32 m)
{
    s32 v = 100;
    s8* b = (s8*)fn_80135598();

    if (StateValid((Party*)(b + 0x238), m)) {
        v = MenuDstSum((MenuDst*)(b + 0x298 + m * 0x22));
    }
    return v;
}

static inline void MenuStopTask(MenuW* w)
{
    if (w != NULL && w->task != NULL) {
        TaskStop(w->task);
        w->task = NULL;
    }
}

static inline void* MenuCurSlot(void)
{
    void* p = NULL;

    if (lbl_80346F6C >= 0) {
        p = (u8*)lbl_803472CC + lbl_80346F6C * 4;
    }
    return p;
}

static inline s32 MenuIdle(void)
{
    s32 ok = 0;

    if (fn_80130318() == 0 && fn_8012FF08() == 0) {
        ok = 1;
    }
    return ok;
}

static inline void MenuShowList(s32 n)
{
    s32 a[8];
    s32 b[8];
    void* o = fn_801298CC();

    if (o != NULL) {
        fn_8014093C(o, n, a, b);
        if (a != NULL && b != NULL) {
            fn_801300E0(a);
            fn_80130264(b);
        }
    }
    if (lbl_803472D8 == 0) {
        fn_80130040();
        fn_80130338(0);
    } else {
        fn_80130338(10);
    }
}

static inline void MenuSetTask(MenuTask_80141610* t, void* a, void* b)
{
    if (t != NULL) {
        t->x24 = a;
        t->x28 = b;
    }
}

static inline void MenuFill(s32* v)
{
    if (v != NULL) {
        v[0] = -1;
        v[1] = -1;
        v[2] = -1;
        if (fn_80145CA4(0, 0, 3)) {
            v[0] = 0;
        }
        if (fn_80145CA4(0, 0, 8)) {
            v[0] = 1;
        }
        if (fn_80145CA4(0, 0, 2)) {
            v[1] = 2;
        }
        if (fn_80145CA4(0, 0, 0xc)) {
            v[2] = 3;
        }
    }
}

/* The first member in [0, party size) that fn_801358A0 accepts, or -1. */
static inline s32 MenuFind(s32 m, s32 a, s32 b)
{
    s32 n = NameCount();
    s32 i;

    i = 0;
    while (i >= 0 && i < n && !fn_801358A0(i, m, a, b, n)) {
        i++;
    }
    i = i > -1 ? i : -1;
    i = i < n ? i : n;
    if (i < 0 || i >= n) {
        i = -1;
    }
    return i;
}

static inline s32 MenuHas(s32 m, s32 a, s32 b)
{
    s32 f = 0;

    if (MenuFind(m, a, b) >= 0) {
        f = 1;
    }
    return f;
}

static inline s32 MenuHasGold(MenuW* w)
{
    s32 ok = 0;

    if (w != NULL && w->h16 >= 0) {
        ok = 1;
    }
    return ok;
}

static inline MenuEnt* MenuEntOf(s32 m)
{
    MenuEnt* e = NULL;

    if (m >= 0 && m < 4) {
        e = (MenuEnt*)(fn_80135598() + 0x1c6 + m * 0x1c);
    }
    return e;
}

static inline s32 MenuCanUse(MenuW* w)
{
    s32 f = 0;

    if (w != NULL) {
        MenuEnt* e = MenuEntOf(w->mem);
        if (e != NULL) {
            u8 buf[8];
            s32 k;
            for (k = 0; k < 6; k++) {
                if (fn_80138930(buf, e, k) > 0) {
                    f = 1;
                    break;
                }
            }
        }
    }
    return f;
}

static inline s32 MenuEntBe(MenuW* w)
{
    MenuEnt* e = MenuEntOf(w->mem);
    s32 v = 0;

    if (e != NULL) {
        v = e->be;
    }
    return v;
}

static inline s32 MenuWaitKey(MenuW* w)
{
    s32 f = 0;

    if (MENU_PAD->x8 & 0xf00) {
        if (w != NULL) {
            w->xa = 0;
        }
        fn_8012F478(1);
        SePlay(0xf, 1, 7);
        f = 1;
    }
    return f;
}

static inline void MenuText(MenuW* w, char* s)
{
    fn_8012F468(s);
    if (w != NULL) {
        w->xa = 1;
    }
    fn_8012F478(0);
}

static inline void MenuOk(MenuW* w)
{
    fn_8012AEA8(w->kind);
    fn_8012AEB8(2);
    SePlay(0xf, 1, 2);
    w->state = 8;
}

void fn_80141610(void)
{
    MenuW* w = (MenuW*)lbl_80306738;
    char* text = lbl_802B3458;
    s32 s;
    s32 n;
    s32 i;
    s32 k;
    s32 m;
    s32 f;
    s32 sum;
    s32 r;
    s8* q;

    switch (w->state) {
    case 0:
        if (lbl_80346F74 == 0) {
            break;
        }
        s = 0;
        if (lbl_803472D8 == 0) {
            s = -4;
        } else {
            n = NameCount();
            k = -n;
            for (i = 0; i < n; i++) {
                fn_80136848(i, k);
                k++;
            }
        }
        for (; s < 4; s++) {
            MenuRecClear(s);
        }
        if (w != NULL) {
            w->mem = 0;
            w->h18 = 0;
            w->h1a = 0;
            w->h1c = 0;
            w->h1e = 0;
            q = (s8*)fn_80135598();
            n = NameCount();
            sum = 0;
            for (k = -n; k < 0; k++) {
                s32 kd = lbl_80308E90[k * 5 + 0x14];
                if (kd == 4) {
                    s32 st;
                    s32 lv;
                    m = (s8)lbl_80308E90[k * 5 + 0x16];
                    st = MemberStatus(m);
                    lv = (s8)lbl_80308E90[k * 5 + 0x18];
                    switch (st) {
                    case 1:
                        if (lv >= 0) {
                            sum += (lv + 1) * MenuMemberSum(m);
                        }
                        break;
                    }
                }
            }
            w->h16 = *(s16*)(q + 8) - sum;
            w->h16 = w->h16 < 0 ? 0 : w->h16;
        }
        w->kind = 3;
        w->xb = 0;
        fn_8012C048(0x12);
        fn_80140800(w->mem);
        if (w->task != NULL && MenuCurSlot() == NULL) {
            MenuStopTask(w);
        }
        n = NameCount();
        k = NameCount() * 2;
        fn_8012FF48(n);
        fn_80130350(0);
        fn_80130304(-1);
        if (!MenuIdle()) {
            w->state = 1;
            break;
        }
        MenuShowList(k);
        w->state = 2;
        break;
    case 1:
        if (!MenuIdle()) {
            break;
        }
        MenuShowList(NameCount() * 2);
        w->state = 2;
        break;
    case 2:
        if (fn_80130318() != 0) {
            break;
        }
        if (MenuCurSlot() != NULL && w != NULL) {
            void* o = fn_801298CC();
            void* slot = MenuCurSlot();
            if (w != NULL && o != NULL && slot != NULL) {
                if (w->task == NULL) {
                    w->task = fn_80226848(lbl_80347590, fn_801355A4, 8);
                    if (w->task != NULL) {
                        ((MenuTask_80141610*)w->task)->state = 0;
                    }
                }
                if (w->task != NULL) {
                    MenuSetTask((MenuTask_80141610*)w->task, o, slot);
                }
            }
        }
        w->state = 3;
        break;
    case 3:
        fn_80140A14(w);
        fn_8015A888();
        w->state = 4;
    case 4: {
        s32 v[3];
        MenuSys* sys;
        MenuEnt* e;
        m = w->mem;
        w->kind = 3;
        w->xb = 0;
        q = (s8*)fn_80135598();
        sys = (MenuSys*)(q + 0x238);
        e = (MenuEnt*)(q + 0x1c6 + m * 0x1c);
        fn_801330FC(e->bb);
        fn_801330E4(e->bc);
        fn_801330CC(e->be);
        fn_801330B4(e->bd);
        fn_8013309C(sys->x18);
        fn_80133084(sys->x14);
        fn_8013306C(sys);
        MenuFill(v);
        fn_80133030(v);
        fn_80133114(0x11);
        fn_80131598(w->mem);
        fn_801315EC(w->mem);
        fn_8012C4E8();
        if (w != NULL) {
            fn_8013F8F8(w->mem, w->h16);
        }
        f = MenuHas(w->mem, 3, 0);
        if (!f) {
            w->state = 10;
            break;
        }
        fn_8012C614(5);
        w->state = 5;
    }
    case 5:
        if (fn_8012C5DC() == 0) {
            w->state = 6;
        }
        break;
    case 6:
        r = fn_80141390((Obj_80141390*)w);
        switch ((s8)r) {
        case 0:
            f = 0;
            if (w != NULL) {
                s32 ok = 0;
                m = w->mem;
                if (!(lbl_80310B3C.xfc & 0x80000000) && m >= 0 && m < 4 && ((s8*)fn_80135598())[m] == 0) {
                    ok = 1;
                }
                if (ok) {
                    f = 1;
                }
            }
            if (!f) {
                SePlay(0xf, 1, 3);
                break;
            }
            fn_8013F634(w->mem, 0);
            SePlay(0xf, 1, 2);
            w->state = 0x10;
            break;
        case 1:
            f = MenuHas(w->mem, 3, 0);
            if (!f || !fn_80141078()) {
                SePlay(0xf, 1, 3);
                break;
            }
            MenuOk(w);
            break;
        case 2:
            f = MenuHas(w->mem, 3, 0);
            if (!f || !MenuHasGold(w)) {
                SePlay(0xf, 1, 3);
                break;
            }
            MenuOk(w);
            break;
        case 4:
            f = MenuHas(w->mem, 3, 0);
            if (!f || !MenuCanUse(w) || MenuEntBe(w) < 1) {
                SePlay(0xf, 1, 3);
                break;
            }
            MenuOk(w);
            break;
        case 6:
            if (fn_80140D04(r) == 0) {
                SePlay(0xf, 1, 3);
                break;
            }
            m = w->mem;
            if (MenuFind(m, 4, 4) < 0) {
                SePlay(0xf, 1, 3);
                w->state = 0xc;
                break;
            }
            {
                s32 x = w->h16;
                s32 lim;
                s32 act;
                MenuSys* b;
                f = 0;
                lim = 100;
                q = (s8*)fn_80135598();
                act = 0;
                b = (MenuSys*)(q + 0x238);
                if (b != NULL && b->xfc >= 0) {
                    act = 1;
                }
                if (act) {
                    MenuDst* d = (MenuDst*)(q + 0x320);
                    lim = 100;
                    if (d != NULL) {
                        lim = d->b1f + d->b20;
                    }
                }
                if (x >= lim) {
                    f = 1;
                }
            }
            if (!f) {
                SePlay(0xf, 1, 3);
                w->state = 0xe;
                break;
            }
            MenuOk(w);
            break;
        case 3:
        case 5:
        case 7:
            f = MenuHas(w->mem, 3, 0);
            if (!f) {
                SePlay(0xf, 1, 3);
                break;
            }
            MenuOk(w);
            break;
        case 8:
            if (w->mem > 0) {
                fn_801415C4((CountObj*)w);
                w->state = 4;
            }
            break;
        case 9:
            break;
        }
        break;
    case 7:
        if (!(MENU_PAD->x8 & 0x800)) {
            break;
        }
        lbl_80346F61 = 0;
        if ((s8)lbl_80346F60 == 0) {
            lbl_80310B3C.x84 &= ~0x80000000;
        } else {
            lbl_80310B3C.x84 |= 0x80000000;
        }
        lbl_803473EC = 1;
        lbl_803473E8 = 0;
        fn_801353A8();
        fn_80140A14(w);
        w->state = 4;
        break;
    case 8:
        if (w->kind >= 0 && w->kind < 8 && lbl_802E5BC0[w->kind] != NULL) {
            w->b4[0] = 0;
            w->b4[1] = 0;
            w->b4[2] = 0;
            w->b4[3] = 0;
            w->b4[4] = 0;
            w->b4[5] = 0;
            w->xa = 0;
            w->xb = 0;
            lbl_802E5BC0[w->kind](w);
        }
        w->state++;
        break;
    case 9: {
        s32 ns;
        r = 3;
        if (w->kind >= 0 && w->kind < 8 && lbl_802E5BE0[w->kind] != NULL) {
            r = lbl_802E5BE0[w->kind](w);
        }
        ns = w->state;
        switch ((s8)r) {
        case 0:
            break;
        case 1:
            ns = 6;
            break;
        case 2:
            w->mem++;
            n = NameCount();
            if (w->mem < n) {
                ns = 4;
            } else {
                ns = 0x10;
            }
            break;
        }
        w->state = ns;
        if (w->state != 9) {
            fn_8012AEB8(1);
            fn_80130304(-1);
            fn_801315FC(1);
        }
        break;
    }
    case 10:
        fn_8012F458(0);
        MenuText(w, text);
        w->state = 0xb;
    case 11:
        if (MenuWaitKey(w)) {
            if (w->mem > 0) {
                fn_801415C4((CountObj*)w);
            }
            w->state = 4;
        }
        break;
    case 12:
        fn_8012F458(0);
        MenuText(w, text + 0x58);
        w->state = 0xd;
    case 13:
        if (MenuWaitKey(w)) {
            w->state = 6;
        }
        break;
    case 14: {
        char* msg = text + 0xa0;
        fn_8012F458(0);
        f = 0;
        {
            MenuSys* b = (MenuSys*)(fn_80135598() + 0x238);
            s32 ok = 0;
            if (b != NULL && b->xfc >= 0) {
                ok = 1;
            }
            if (ok) {
                if (Mode_80141390() == 3) {
                    f = 1;
                }
            }
        }
        if (f) {
            MenuSys* a;
            f = 0;
            a = (MenuSys*)(fn_80135598() + 0x238);
            if (a != NULL && a->x11 >= 2) {
                f = 1;
            }
            if (f) {
                msg = text + 0xdc;
            }
        }
        MenuText(w, msg);
        w->state = 0xf;
    }
    case 15:
        if (MenuWaitKey(w)) {
            w->state = 6;
        }
        break;
    case 16:
        if ((*(s32**)&lbl_80346F74) != NULL) {
            *(*(s32**)&lbl_80346F74) = 1;
            (*(s32**)&lbl_80346F74) = NULL;
        }
        fn_8012AEB8(1);
        fn_8012AED0(1);
        fn_8012C648(1);
        fn_8012E5C0(1);
        fn_80130350(1);
        fn_801316B4(1);
        fn_8013312C(1);
        MenuStopTask(w);
        lbl_80346F68 = lbl_80346F70;
        lbl_80346F64 = lbl_80346F6C;
        lbl_80346F70 = -1;
        lbl_80346F6C = -1;
        fn_8015A844();
        fn_8012C048(0x16);
        fn_80142F18();
        break;
    }
}
