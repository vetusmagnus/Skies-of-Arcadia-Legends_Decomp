#include "game/unit_80055E94.h"
#include "game/chrinfo.h"

extern void fn_8021A1C4(s8 *buf);
extern Node *fn_80074E2C(char *, char *, void *, int, int);
typedef struct MdlCtl { u8 pad[0x10]; Obj_80017B18 *x10; u8 pad14[0x4c - 0x14]; ChrInfo *obj; } MdlCtl;
extern s32 fn_800154BC(Task *t);

typedef struct SndLimit { u8 pad[0x14]; s16 x14; } SndLimit;
typedef struct Snd {
    u8 pad_00[4];
    s16 x4;             /* 0x04 timer */
    u8 x6;              /* 0x06 1: crew under 11, 2: crew from 11 */
    s8 x7;              /* 0x07 index into list */
    s8 list[0x20];      /* 0x08 crew ids, -1 ends */
    s32 x28;
    s32 x2c;
    Task *x30;
    SndLimit *x34;
} Snd;
extern void fn_80218D84(void *dst, u32 src, u32 size);
typedef struct Hdr Hdr;
extern Ent6EB88 *lbl_80347398;
extern void fn_80014D0C(void);
extern void fn_80014CFC(void);
extern void SoundLoadCrSamp(s8 first, s8 second);
extern void SoundLoadB7Samp(void);
extern void SoundFreeSamp(void);
extern s16 fn_8006D2C4(s32 a);
extern void fn_8006D308(void);
extern void fn_80021934(char *path, char *name);
extern void *fn_8006DAF8(void *self);
extern s32 fn_8006E6E4(Hdr *h);
extern void fn_801E17E0(void *p);
extern Task *fn_80021658(s8 idx);
extern void fn_80020D50(Task *t);
extern s32 fn_8006D02C(Obj_80017B18 *p, s32 free);
extern s16 fn_800085EC(Task *a, s16 b, s16 c, struct Ent_80008800 *d, struct CondLink *p);
extern void fn_8004DD54(s16 a, s16 b, Task *task, s8 flag, int d);
extern void fn_80032B4C(void);
extern void fn_8001D14C(ChrInfo *c);
extern void fn_80072F10(Snd *s);
extern void fn_80073C44(Task *arg, s8 mode);
extern void fn_80073B48(s8 *out);
extern void fn_80073024(Ent6EB88 *out, s8 *p, s8 c);

inline MdlCtl *ChrW(Task *t)
{
    return t->work;
}


void fn_80073D14(void) {
}

void fn_80073D10(void) {
}

void fn_80073D0C(void) {
}

void fn_80073C44(Task *arg, s8 mode) {
    s8 i;
    for (i = 0; i < 12; i++) {
        if (lbl_80309E24[i] != NULL && fn_800154BC(lbl_80309E24[i]) == 0) {
            MdlCtl *c = lbl_80309E24[i]->work;
            ChrInfo *w = c->obj;
            switch (mode) {
            case 0:
                if (fn_8001D944(w->id, arg) == 0) {
                    w->draw.a = 0.0f;
                }
                break;
            case 1:
                if (fn_8001D944(w->id, arg) != 0) {
                    w->draw.a = 0.0f;
                }
                break;
            }
        }
    }
}

void fn_80073B48(s8 *out) {
    s8 pat[] = { 0, 4, 5, 6, 10, 11, 14, 16, 18, 17, 21, 1, 2, 3, 7, 8, 9, 12, 13, 15, 19, 20, -1 };
    s8 buf[0x20];
    s32 i = 0;
    s8 *b;
    s8 *p;
    s8 j;
    s8 n = 0;
    fn_8021A1C4(buf);
    for (p = pat; *p >= 0; p++, i++) {
        b = buf;
        for (j = 0; j < 0x16; b++, j++) {
            if (*b < 0) break;
            if (*b == *p) {
                out[n++] = i;
            }
        }
    }
    out[n] = -1;
}

inline void CrLoad(char* name)
{
    void* p = fn_8006DAF8(name);
    if (p != NULL) {
        fn_8006E6E4(p);
        fn_801E17E0(p);
    }
}

inline void CrPlaySe(Snd* w, s8 id)
{
    if (lbl_8030A10C.x7c != 0) {
        if (w->x28 != 0) {
            fn_80217830(w->x28);
        }
        fn_80218D84(lbl_8030A10C.x84, lbl_8030A10C.x7c, (lbl_8030A10C.x74 + 0x1f) & ~0x1f);
        w->x28 = SePlay(3, 3, id);
        lbl_8030A10C.x7c = 0;
        lbl_8030A10C.x74 = 0;
    }
}

void fn_80073164(Task* t)
{
    Snd* w = t->work;
    ChrInfo* chr = ChrW(w->x30)->obj;
    s32 ok;
    void* p;
    Task* o;
    ChrInfo* c;
    s8 v;
    s16 i;
    char buf[16];

    switch (t->state) {
    case 0:
        w->x28 = SePlay(3, 3, 0);
        fn_80014D0C();
        lbl_8030A10C.f6c &= ~0x01000000;
        lbl_8030A10C.f6c |= 0x20000;
        chr->xec |= 0x80000;
        if (w->x4 > w->x34->x14) {
            t->state = 1;
        }
        break;
    case 1:
        fn_80073B48(w->list);
        if (w->list[w->x7] >= 0) {
            fn_80073024(lbl_80347398, w->list, 0);
            t->state = 3;
        }
        break;
    case 3:
        if (lbl_8030A10C.f6c & 0x80000000) {
            break;
        }
        SoundLoadCrSamp(w->list[0] + 1, -1);
        t->state = 4;
        break;
    case 4:
        if (lbl_8030A10C.f6c & 0x80000000) {
            break;
        }
        ok = 0;
        if (w->x7 == 0) {
            if (fn_8006D2C4(1) == 0) {
                ok = 1;
                fn_8006D308();
            }
        } else {
            ok = 1;
        }
        if (ok) {
            sprintf(buf, "CR%03d", w->list[w->x7] + 1);
            fn_80021934("/BCHARA/", buf);
            sprintf(buf, "CR%03d.MLK", w->list[w->x7] + 1);
            CrLoad(buf);
            t->state = 5;
            if (w->x28 != 0) {
                fn_80217830(w->x28);
            }
        }
        break;
    case 5:
        if (lbl_8030A10C.f6c & 0x80000000) {
            break;
        }
        fn_80072F10(w);
        lbl_8030A10C.f6c &= ~0x0E000000;
        if (w->x7 == 0 && w->list[w->x7 + 1] >= 0) {
            lbl_8030A10C.f6c |= 0x08000000;
        } else if (w->x7 != 0) {
            lbl_8030A10C.f6c |= 0x04000000;
        }
        c = ChrW(fn_80021658(0xd))->obj;
        c->x18 = 0x18;
        c->x1a = 0x3c;
        c->xec |= 0x40000000;
        t->state = 6;
        break;
    case 6:
        if (fn_8006D2C4(1) == 0) {
            break;
        }
        lbl_8030A10C.f6c |= 0x01000000;
        w->x7++;
        if (w->list[w->x7] >= 0) {
            fn_80073024(lbl_80347398, &w->list[w->x7], 0);
        } else {
            fn_80073024(lbl_80347398, w->list, 1);
        }
        t->state = 7;
        break;
    case 7:
        if (lbl_8030A10C.f6c & 0x80000000) {
            break;
        }
        v = w->list[w->x7];
        if (v < 0) {
            SoundLoadCrSamp(0x1a, -1);
        } else if (w->list[w->x7 - 1] < 0xb && v >= 0xb) {
            SoundLoadCrSamp(v + 1, 0x65);
        } else {
            SoundLoadCrSamp(v + 1, -1);
        }
        t->state = 8;
        break;
    case 8:
        c = ChrW(fn_80021658(0xd))->obj;
        c->xec &= ~0x40000000;
        lbl_8030A10C.f6c &= ~0x01000000;
        if (fn_8006D2C4(1) != 0) {
            break;
        }
        o = fn_80021658(0xd);
        chr = ChrW(o)->obj;
        fn_80020D50(o);
        fn_8006D02C(ChrW(o)->x10, 1);
        if (chr->x154 != NULL) {
            fn_801E17E0(chr->x154);
        }
        if (chr->x158 != NULL) {
            fn_801E17E0(chr->x158);
        }
        if (chr->x298 != NULL) {
            fn_801E17E0(chr->x298);
        }
        fn_801E17E0(chr);
        o->flags |= 0x40;
        fn_8006D308();
        if (w->list[w->x7] >= 0) {
            t->state = 4;
            break;
        }
        t->state = 10;
        if (w->x2c != 0) {
            fn_80217830(w->x2c);
        }
        break;
    case 10:
        if (lbl_8030A10C.f6c & 0x80000000) {
            break;
        }
        CrLoad("CREN30.MLK");
        if (w->x30 != NULL) {
            fn_800085EC(w->x30, 0x1e, 0x1e, ChrW(w->x30)->x10->x30, chr->x298);
            for (i = 0; i < 0x16; i++) {
                if (w->list[i] < 0) {
                    break;
                }
                if (w->list[i] < 0xb) {
                    w->x6 |= 1;
                }
                if (w->list[i] >= 0xb) {
                    w->x6 |= 2;
                }
            }
            if (w->x6 & 1) {
                t->state = 0xf;
            } else {
                t->state = 0x13;
            }
        } else {
            t->state = 0x18;
        }
        break;
    case 15:
        if (fn_8006D2C4(1) == 0) {
            break;
        }
        if (w->x6 & 2) {
            CrPlaySe(w, 1);
        } else {
            CrPlaySe(w, 0);
        }
        lbl_8030A10C.f6c |= 0x01000000;
        fn_80073024(lbl_80347398, w->list, 2);
        t->state = 0x11;
        break;
    case 17:
        lbl_8030A10C.f6c &= ~0x01000000;
        if (lbl_8030A10C.f6c & 0x80000000) {
            break;
        }
        if (fn_8006D2C4(1) != 0) {
            break;
        }
        lbl_8030A10C.f6c &= ~0x0E000000;
        fn_80073C44(w->x30, 1);
        fn_8006D308();
        CrLoad("CREN31.MLK");
        fn_800085EC(w->x30, 0x1e, 0x1f, ChrW(w->x30)->x10->x30, chr->x298);
        fn_8004DD54(0x18, 0x3c, w->x30, 0, 0);
        if (w->x6 & 2) {
            t->state = 0x13;
        } else {
            t->state = 0x12;
        }
        break;
    case 18:
        if (fn_8006D2C4(1) == 0) {
            break;
        }
        lbl_8030A10C.f6c |= 0x01000000;
        t->state = 0x17;
        break;
    case 19:
        if (fn_8006D2C4(1) == 0) {
            break;
        }
        if (!(w->x6 & 1)) {
            CrPlaySe(w, 2);
        }
        lbl_8030A10C.f6c |= 0x01000000;
        fn_80073024(lbl_80347398, w->list, 3);
        t->state = 0x15;
        break;
    case 21:
        lbl_8030A10C.f6c &= ~0x01000000;
        if (lbl_8030A10C.f6c & 0x80000000) {
            break;
        }
        if (fn_8006D2C4(1) != 0) {
            break;
        }
        fn_80032B4C();
        lbl_8030A10C.f6c &= ~0x0E000000;
        fn_8006D308();
        fn_80073C44(w->x30, 0);
        CrLoad("CREN32.MLK");
        fn_800085EC(w->x30, 0x1e, 0x20, ChrW(w->x30)->x10->x30, chr->x298);
        fn_8004DD54(0x18, 0x3c, w->x30, 1, 0);
        t->state = 0x16;
        break;
    case 22:
        if (fn_8006D2C4(1) == 0) {
            break;
        }
        lbl_8030A10C.f6c |= 0x01000000;
        t->state = 0x17;
        break;
    case 23:
        if (fn_8006D2C4(1) != 0) {
            break;
        }
        fn_8006D308();
        t->state = 0x18;
        SoundLoadB7Samp();
        t->state = 0xb;
        break;
    case 11:
        if (lbl_8030A10C.f6c & 0x80000000) {
            break;
        }
        if (w->x28 != 0) {
            fn_80217830(w->x28);
        }
        if (w->x2c != 0) {
            fn_80217830(w->x2c);
        }
        SoundFreeSamp();
        t->state = 0x18;
        break;
    case 24:
        fn_80014CFC();
        lbl_8030A10C.f6c &= ~0x20000;
        fn_8001D14C(chr);
        t->flags |= 0x40;
        lbl_8030A10C.count--;
        return;
    }
    w->x4++;
}

void fn_80073024(Ent6EB88* out, s8* p, s8 c) {
    char buf[0x18];
    out->f0 = -1;
    switch (c) {
    case 0:
        while (*p >= 0) {
            sprintf(buf, "CR%03d.MLD", *p + 1);
            fn_8006E75C(out, buf, 0);
            sprintf(buf, "CR%03d.STD", *p + 1);
            fn_8006E75C(out, buf, 0);
            sprintf(buf, "CR%03d0.STD", *p + 1);
            fn_8006E75C(out, buf, 0);
            sprintf(buf, "CR%03d.MLK", *p + 1);
            fn_8006E75C(out, buf, 0);
            break;
        }
        break;
    default:
        sprintf(buf, "CREN%2d.MLK", c + 0x1d);
        fn_8006E75C(out, buf, 0);
        break;
    }
    fn_8006DC6C();
}

void fn_80072F10(Snd *s) {
    if (lbl_8030A10C.x7c != 0) {
        if (s->x28 != 0) {
            fn_80217830(s->x28);
        }
        fn_80218D84(lbl_8030A10C.x84, lbl_8030A10C.x7c, (lbl_8030A10C.x74 + 0x1f) & ~0x1f);
        s->x28 = SePlay(3, 3, 0);
        lbl_8030A10C.x7c = 0;
        lbl_8030A10C.x74 = 0;
    }
    if (lbl_8030A10C.x80 != 0) {
        if (s->x2c != 0) {
            fn_80217830(s->x2c);
        }
        if (s->x7 != 0) {
            fn_80218D84(lbl_8030A10C.xa4, lbl_8030A10C.x80, (lbl_8030A10C.x78 + 0x1f) & ~0x1f);
        }
        s->x2c = SePlay(3, 7, 0);
        lbl_8030A10C.x80 = 0;
        lbl_8030A10C.x78 = 0;
    }
}

void fn_80072E8C(s16 k, s16 b, s16 c, char *d) {
    switch (k) {
    case 0x18:
    case 0x19:
    case 0x1d:
    case 0x1e:
        sprintf(d, "E67%03d%02d.MLD", b, k);
        break;
    default:
        sprintf(d, "E67%03d%02d.MLD", c, k);
        break;
    }
}

s32 fn_80072DD4(s16 a, s16 b, s16 c, void *d)
{
    char buf2[0x20];
    char buf1[0x20];

    switch (a) {
    case 0x18:
    case 0x19:
    case 0x1d:
    case 0x1e:
        sprintf(buf2, "E67%03d%02d.MLD", b, a);
        break;
    default:
        sprintf(buf2, "E67%03d%02d.MLD", c, a);
        break;
    }
    fn_8006C8DC(buf1, buf2);
    fn_80074E2C(buf1, buf2, d, 0, 1);
    return 1;
}
