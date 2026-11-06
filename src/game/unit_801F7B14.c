#include "game/scptact.h"

void fn_80217B98();
void fn_800B0900(void *p);
s32 SePlay(s32 bank, s8 arg1, s8 id);
void fn_80217830(s32 arg);
extern u32 fn_800CCC48(s32 a, s32 b);
/* A move-script node: seven floats, then the timing fields of the segment that ends there. */
typedef struct MvNode {
    f32 x;       /* 0x00 */
    f32 y;       /* 0x04 */
    f32 z;       /* 0x08 */
    f32 x0c;     /* 0x0c */
    f32 x10;     /* 0x10 */
    f32 x14;     /* 0x14 */
    f32 x18;     /* 0x18 */
    s32 x1c;     /* 0x1c */
    s32 x20;     /* 0x20 */
    f32 x24;     /* 0x24 */
    s32 x28;     /* 0x28 */
    s32 x2c;     /* 0x2c */
} MvNode;
typedef struct Work_801F8158 {
    Ev ev;
    u8 pad14[0x4];
    u16 id;         /* 0x18 */
    u8 pad1a[0x2];
    u32 count;      /* 0x1c */
    MvNode* pts;      /* 0x20 */
    void* path;     /* 0x24 */
    u8 pad28[0x1c];
} Work_801F8158;
extern Actor* lbl_80347450;
extern void fn_8016058C(u32 n, MvNode* pts, Actor* obj);
extern void* fn_801607A0(u32 n, MvNode* pts, NJS_POINT3* pos);
extern void fn_80165C84(void* p);
typedef struct MvjParams {
    f32 f00, f04, f08;  /* 0x00 */
    u8 pad0c[0xC];
    f32 f18;            /* 0x18 */
    s32 i1c;            /* 0x1C */
    s32 i20;            /* 0x20 */
    f32 f24;            /* 0x24 */
    s32 i28;            /* 0x28 */
    s32 i2c;            /* 0x2C */
    f32 f30;            /* 0x30 */
    f32 f34;            /* 0x34 */
    f32 f38;            /* 0x38 */
    u8 pad3c[0xC];
    f32 f48;            /* 0x48 */
    s32 i4c;            /* 0x4C */
    s32 i50;            /* 0x50 */
    f32 f54;            /* 0x54 */
    s32 i58;            /* 0x58 */
    s32 i5c;            /* 0x5C */
    f32 f60, f64, f68;  /* 0x60 */
    u8 pad6c[0xC];
    f32 f78;            /* 0x78 */
    s32 i7c;            /* 0x7C */
    s32 i80;            /* 0x80 */
    f32 f84;            /* 0x84 */
    s32 i88;            /* 0x88 */
    s32 i8c;            /* 0x8C */
} MvjParams;

typedef struct Work_801FA630 {
    Ev ev;
    u8 pad14[0x4];
    u16 id;             /* 0x18 */
    u8 pad1a[2];
    s32 x1c;            /* 0x1C */
    u8 pad20[0x14];
    void* node;         /* 0x34 */
    MvjParams* params;  /* 0x38 */
    u8 pad3c[8];
} Work_801FA630;
typedef struct Work_801FABDC {
    Ev ev;           /* 0x00 */
    u8 pad14[4];
    u16 id;          /* 0x18 */
    u8 pad1a[2];
    u32 count;       /* 0x1c */
    MvNode* nodes;   /* 0x20 */
    void* result;    /* 0x24 */
    u8 pad28[0x1c];
} Work_801FABDC;
extern Actor* lbl_80347450;
void fn_8016058C(u32 n, MvNode* nodes, Actor* o);
void* fn_801607A0(u32 n, MvNode* nodes, NJS_POINT3* pos);
void* fn_80165EE4(u32 n, MvNode* nodes, NJS_POINT3* pos);
void fn_80165C84(void* sp);
typedef struct Work_801FC68C {
    Ev ev;           /* 0x00 */
    u8 pad14[4];
    u16 id;          /* 0x18 */
    u8 pad1a[2];
    u32 count;       /* 0x1c */
    MvNode* nodes;   /* 0x20 */
    u8 pad24[0x20];
} Work_801FC68C;
typedef struct { s32 flag; f32 f4; s32 i8; } Fx_8030CE94;
extern Fx_8030CE94 lbl_8030CE94;
void fn_800D23F8(s32 n, f32 a, f32 b, s32 m);
void fn_800D244C(s32 n, f32 a, f32 b, s32 m);
void fn_80211EB0(s16 mode, f32 v);
extern s32 lbl_803475B4;
double fn_8026216C(double x);
void fn_8021730C(u32 mode, s32 x);
extern s32 fn_80218570(s32 a, s32 b, s32 c);
void fn_800B09C0(s8 id, s8 a, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);
void fn_800AFCC0(s8 id, s8 a, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5);
extern s32 strlen(const char *s);
extern char *lbl_80346848;
extern char lbl_8034C198;
extern char *strcpy(void *dst, const char *src);
extern char *strcat(void *dst, const char *src);
extern void fn_80219378(void *p);
void fn_801694FC(s32 a, s8 b, s8 c, s32 d, f32 x, f32 y, f32 z);

extern void fn_80168398(f32 a, f32 b, f32 c, f32 d, s32 i0, s32 i1, s32 i2, s32 i3, u16 i4, u8 i5);

extern void fn_80169144(f32 a, f32 b, f32 c, f32 d, s32 i0, s32 i1, s32 i2, s32 i3, u16 i4, u8 i5);

extern void fn_80168B7C(s32 v);
void fn_80216CB4(char *p);
s32 fn_80217FD4(s32 bank, s8 arg1, s8 id);

extern char lbl_8034C1CC[5];
extern char lbl_8034C1D4[5];
void fn_80218D80(char *name, u32 tag, s32 v);


s32 fn_80216CA4(char *p);
s32 fn_801F7B14(u16 f, Scpt *c) {
    char *buf;
    if (f & 1) {
        ScptCur p;
        char *q;
        char *w;
        p.b = c->cur.b;
        q = p.s + 4;
        w = q + p.i[1];
        c->cur.s = q + 4;
        c->flags = 0;
        c->work.s = w;
    }
    if (f & 2) {
        buf = fn_801E1A2C(1, strlen(lbl_80346848) + strlen(c->work.s) + 5);
        strcpy(buf, lbl_80346848);
        strcat(buf, c->work.s);
        strcat(buf, &lbl_8034C198);
        if (fn_80216CA4(buf) != 0) {
            c->work.s = 0;
            if (buf != 0) {
                fn_801E1784(buf);
            }
            return 0;
        }
        if (buf != 0) {
            fn_801E1784(buf);
        }
    }
    return !(f & 8);
}

s16 fn_801F7C18(u32 flags, Scpt *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p4 = s->cur.b + 4;
        char *name = (char *)p4 + *(u32 *)p4;
        char *buf;
        s->cur.b = p4 + 4;
        buf = fn_801E1A2C(1, strlen(lbl_80346848) + strlen(name) + 5);
        strcpy(buf, lbl_80346848);
        strcat(buf, name);
        strcat(buf, &lbl_8034C198);
        fn_80216CB4(buf);
        if (buf != 0) {
            fn_801E1784(buf);
        }
    }
    return (s16)((f >> 3) & 1);
}

s32 fn_801F7CD8(u32 a, Scpt *st) {
    u16 f = a;
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_800B0900(c);
    }
    if (f & 8) return 1;
    return 0;
}

s16 fn_801F7D2C(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        s8 kind;
        s8 b;
        u32 n;
        f32 f31;
        f32 f30;
        f32 f29;
        f32 f4;
        kind = ReadInt(&p);
        f29 = (f32)ReadInt(&p);
        f31 = fn_801F6120(&p);
        f30 = fn_801F6120(&p);
        n = ReadInt(&p);
        b = ReadInt(&p);
        if (n == 0x7FFFFFFF) {
            switch (kind) {
            case 0:
            case 1:
            case 2:
            case 3:
                f4 = 120.0f;
                break;
            default:
                f4 = 10.0f;
                break;
            }
        } else {
            f4 = (f32)n;
        }
        if (b == 0x7FFFFFFF) {
            b = 0;
        }
        c->cur.f = p;
        switch (kind) {
        case 0:
        case 1:
        case 2:
        case 3:
            fn_800B09C0(kind, b, 0.49f, f31, f30, f4, f29);
            break;
        case 4:
        case 5:
            fn_800AFCC0(4, b, 0.49f, 0.0f, f30, f4, 0.0f);
            break;
        }
    }
    return (flags >> 3) & 1;
}

s32 fn_801F7F98(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f;
        Fx* fx;
        p++;
        fx = fn_801E1A2C(1, 0x44);
        c->work.fx = fx;
        fx->x18 = ReadInt(&p);
        fx->x1c = fn_801F6120(&p);
        fx->x20 = fn_801F6120(&p);
        fx->x24 = fn_801F6120(&p);
        fx->x28 = fn_801F6120(&p);
        fx->x2c = fn_801F6120(&p);
        fx->x30 = fn_801F6120(&p);
        fx->x34 = ReadInt(&p);
        c->cur.f = p;
        fx->ev.hd.kind = 0;
        fn_80211058(c, 6, fx->x18, 0x2e, lbl_8030CEA0.x08, &fx->ev);
    }
    if (flags & 2) {
        Fx* cur = c->work.fx;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
        } else if (cur->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801F8158(u32 flags, Scpt* t)
{
    u16 f = flags;
    Work_801F8158* w;
    MvNode* pts;
    Actor* obj;
    Actor* ref;
    Obj10A* look;
    void* path;
    f32* save;
    u32 i;
    u32 j;
    f32 px, py, pz;
    ScptCur cur;

    if (flags & 1) {
        cur.f = t->cur.f;
        cur.f++;
        w = fn_801E1A2C(1, 0x44);
        if (w == 0) fn_801DBE1C("scptMV3: malloc failed");
        t->work.p = w;
        w->id = ReadInt(&cur.f);
        w->count = *cur.u++;
        w->path = 0;
        pts = fn_801E1A2C(1, w->count * 0x30);
        if (pts == 0) fn_801DBE1C("scptMV3 Node: malloc failed");
        w->pts = pts;
        for (i = 0; i < w->count; i++) {
            w->pts[i].x = fn_801F6120(&cur.f);
            w->pts[i].y = fn_801F6120(&cur.f);
            w->pts[i].z = fn_801F6120(&cur.f);
            w->pts[i].x0c = fn_801F6120(&cur.f);
            w->pts[i].x10 = fn_801F6120(&cur.f);
            w->pts[i].x14 = fn_801F6120(&cur.f);
            w->pts[i].x18 = fn_801F6120(&cur.f);
            w->pts[i].x20 = ReadInt(&cur.f);
            w->pts[i].x28 = ReadInt(&cur.f);
        }
        t->cur.f = cur.f;
        if (w->id == 0xFFFF) {
            obj = lbl_80347450;
        } else {
            look = fn_8010A164(w->id);
            if (look == 0) return 0;
            obj = look->x24;
        }
        if (obj->x1d8 != 0) {
            ref = obj->x1d8->x8;
            if (ref == 0) ref = obj;
            px = ref->pos.x;
            py = ref->pos.y;
            pz = ref->pos.z;
            save = fn_801E1A2C(1, w->count * 4);
            for (j = 0; j < w->count; j++) save[j] = w->pts[j].y;
            fn_8016058C(w->count, w->pts, ref);
            path = fn_801607A0(w->count, w->pts, &ref->pos);
            w->path = path;
            if (path == 0) return 0;
            for (i = 0; i < w->count; i++) w->pts[i].y = save[i];
            if (save != 0) fn_801E1784(save);
            ref->pos.x = px;
            ref->pos.y = py;
            ref->pos.z = pz;
        }
        if (f & 4) {
            if (fn_800CCC48(6, w->id) != 0) {
                fn_801E1784(pts);
                fn_801E1784(w);
                return 0;
            }
        }
        w->ev.hd.kind = 0;
        fn_80211058(t, 6, w->id, 0x26, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = t->work.p;
        if (t->handle == 0) {
            t->handle = fn_800CD0B8(t->a20, t->a24, t->a28, t->a2c);
            t->cnt++;
            if (t->cnt == 5) fn_801DBE1C("scptMV3: message post time out");
        } else if (w->ev.hd.kind == 2) {
            fn_80165C84(w->path);
            if (w->pts != 0) {
                fn_801E1784(w->pts);
                w->pts = 0;
            }
            return 0;
        }
    }
    if (f & 8) {
        w = t->work.p;
        if (w->path != 0) fn_80165C84(w->path);
        if (w->pts != 0) {
            fn_801E1784(w->pts);
            w->pts = 0;
        }
        return 1;
    }
    return 1;
}

s32 fn_801F8608(u32 flags, Scpt* s) {
    Work801F8* w;
    f32* cur;
    u16 f = flags;
    s32 v;
    if (f & 1) {
        cur = s->cur.f;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptPlayMO3: malloc failed");
        s->work.work801F8 = w;
        cur = cur + 1;
        w->n = ReadInt(&cur);
        w->x1c = ReadInt(&cur);
        w->x20 = ReadInt(&cur);
        w->x24 = fn_801F6120(&cur);
        w->x28 = fn_801F6120(&cur);
        w->x2c = ReadInt(&cur);
        v = (u16)ReadInt(&cur);
        if (w->x28 == 3.4028235e38f) w->x28 = 0.0f;
        if (w->x2c == 0x7fffffff) w->x2c = 0;
        w->x2c = (u16)w->x2c;
        w->x2c |= v << 16;
        w->ev.hd.kind = 0;
        fn_80211058(s, 6, w->n, 0x25, lbl_8030CEA0.x08, &w->ev);
        s->cur.f = cur;
    }
    if (f & 2) {
        w = s->work.work801F8;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("PlayMO3: message post time out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

s32 fn_801F88D4(u32 flags, Scpt* t)
{
    u16 f = flags;
    Work_801F8158* w;
    MvNode* pts;
    Actor* obj;
    Actor* ref;
    Obj10A* look;
    void* path;
    f32* save;
    u32 i;
    u32 j;
    f32 px, py, pz;
    ScptCur cur;

    if (flags & 1) {
        cur.f = t->cur.f;
        cur.f++;
        w = fn_801E1A2C(1, 0x44);
        if (w == 0) fn_801DBE1C("scptMV2: malloc failed");
        t->work.p = w;
        w->id = ReadInt(&cur.f);
        w->count = *cur.u++;
        w->path = 0;
        pts = fn_801E1A2C(1, w->count * 0x30);
        if (pts == 0) fn_801DBE1C("scptMV2 Node: malloc failed");
        w->pts = pts;
        for (i = 0; i < w->count; i++) {
            w->pts[i].x = fn_801F6120(&cur.f);
            w->pts[i].y = fn_801F6120(&cur.f);
            w->pts[i].z = fn_801F6120(&cur.f);
            w->pts[i].x0c = fn_801F6120(&cur.f);
            w->pts[i].x10 = fn_801F6120(&cur.f);
            w->pts[i].x14 = fn_801F6120(&cur.f);
            w->pts[i].x28 = 0x7FFFFFFF;
            w->pts[i].x18 = fn_801F6120(&cur.f);
        }
        t->cur.f = cur.f;
        if (w->id == 0xFFFF) {
            obj = lbl_80347450;
        } else {
            look = fn_8010A164(w->id);
            if (look == 0) return 0;
            obj = look->x24;
        }
        if (obj->x1d8 != 0) {
            ref = obj->x1d8->x8;
            if (ref == 0) ref = obj;
            px = ref->pos.x;
            py = ref->pos.y;
            pz = ref->pos.z;
            save = fn_801E1A2C(1, w->count * 4);
            for (j = 0; j < w->count; j++) save[j] = w->pts[j].y;
            fn_8016058C(w->count, w->pts, ref);
            path = fn_801607A0(w->count, w->pts, &ref->pos);
            w->path = path;
            if (path == 0) return 0;
            for (i = 0; i < w->count; i++) w->pts[i].y = save[i];
            if (save != 0) fn_801E1784(save);
            ref->pos.x = px;
            ref->pos.y = py;
            ref->pos.z = pz;
        }
        if (f & 4) {
            if (fn_800CCC48(6, w->id) != 0) {
                fn_801E1784(pts);
                fn_801E1784(w);
                return 0;
            }
        }
        w->ev.hd.kind = 0;
        fn_80211058(t, 6, w->id, 0x21, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = t->work.p;
        if (t->handle == 0) {
            t->handle = fn_800CD0B8(t->a20, t->a24, t->a28, t->a2c);
            t->cnt++;
            if (t->cnt == 5) fn_801DBE1C("scptMV2: message post time out");
        } else if (w->ev.hd.kind == 2) {
            fn_80165C84(w->path);
            if (w->pts != 0) {
                fn_801E1784(w->pts);
                w->pts = 0;
            }
            return 0;
        }
    }
    if (f & 8) {
        w = t->work.p;
        if (w->path != 0) fn_80165C84(w->path);
        if (w->pts != 0) {
            fn_801E1784(w->pts);
            w->pts = 0;
        }
        return 1;
    }
    return 1;
}

s32 fn_801F8D0C(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f;
        Fx_801F8D0C* fx = fn_801E1A2C(1, 0x44);
        if (fx == 0) {
            fn_801DBE1C("scptPlayMO2: malloc failed");
        }
        c->work.fx_801F8D0C = fx;
        p++;
        fx->x18 = ReadInt(&p);
        fx->x1c = ReadInt(&p);
        fx->x20 = ReadInt(&p);
        fx->x24 = fn_801F6120(&p);
        fx->x28 = fn_801F6120(&p);
        fx->x2c = ReadInt(&p);
        if (fx->x28 == 3.4028235e38f) {
            fx->x28 = 0.0f;
        }
        if (fx->x2c == 0x7FFFFFFF) {
            fx->x2c = 0;
        }
        fx->ev.hd.kind = 0;
        fn_80211058(c, 6, fx->x18, 0x20, lbl_8030CEA0.x08, &fx->ev);
        c->cur.f = p;
    }
    if (flags & 2) {
        Fx_801F8D0C* cur = c->work.fx_801F8D0C;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("PlayMO2: message post time out");
            }
        } else if (cur->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801F8F7C(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        Fx_801F8F7C* fx = fn_801E1A2C(1, 0x44);
        if (fx == 0) {
            fn_801DBE1C("scptParentOff: malloc failed");
        }
        c->work.fx_801F8F7C = fx;
        fx->x18 = ReadInt(&p);
        fx->x1a = ReadInt(&p);
        c->cur.f = p;
        fx->ev.hd.kind = 0;
        fn_80211058(c, 6, fx->x1a, 0x1a, lbl_8030CEA0.x08, &fx->ev);
    }
    if (flags & 2) {
        Fx_801F8F7C* cur = c->work.fx_801F8F7C;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("scptParentOff: message post time out");
            }
        } else if (cur->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801F9120(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        Fx_801F9120* fx = fn_801E1A2C(1, 0x44);
        if (fx == 0) {
            fn_801DBE1C("scptParentOn: malloc failed");
        }
        c->work.fx_801F9120 = fx;
        fx->x18 = ReadInt(&p);
        fx->x1c = ReadInt(&p);
        fx->x1a = ReadInt(&p);
        fx->x20 = fn_801F6120(&p);
        fx->x24 = fn_801F6120(&p);
        fx->x28 = fn_801F6120(&p);
        fx->x2c = fn_801F6120(&p);
        fx->x30 = fn_801F6120(&p);
        fx->x34 = fn_801F6120(&p);
        c->cur.f = p;
        fx->ev.hd.kind = 0;
        fn_80211058(c, 6, fx->x1a, 0x19, lbl_8030CEA0.x08, &fx->ev);
    }
    if (flags & 2) {
        Fx_801F9120* cur = c->work.fx_801F9120;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("scptParentOn: message post time out");
            }
        } else if (cur->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801F934C(u32 flags, Scpt *st) {
    s32 n;
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        st->cur.f = p;
        if (lbl_8030CE94.flag != 0) {
            fn_800D23F8(n, lbl_8030CE94.f4, 0.0f, lbl_8030CE94.i8);
        } else {
            fn_800D244C(n, lbl_8030CE94.f4, 0.0f, lbl_8030CE94.i8);
        }
        fn_80211EB0(2, (f32)n);
    }
    if (f & 8) {
        return 1;
    }
    return 0;
}

s32 fn_801F9454(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        s32 on = ReadInt(&p);
        f32 v = fn_801F6120(&p);
        s32 m;
        lbl_8030CE94.f4 = v;
        lbl_8030CE94.i8 = m = ReadInt(&p);
        c->cur.f = p;
        if (on != 0) {
            fn_800D23F8(1, 0.0f, v, m);
            lbl_8030CE94.flag = 1;
        } else {
            fn_800D244C(1, 0.0f, v, m);
            lbl_8030CE94.flag = 0;
        }
        fn_80211EB0(1, lbl_8030CE94.f4);
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}

s32 fn_801F95C0(u32 a, Scpt *st) {
    u16 f = a;
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80217CB0(c);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801F9614(u32 a, Scpt *st) {
    u16 f = a;
    if (a & 1) {
        u8 *c = st->cur.b;
        st->cur.b = c + 4;
        fn_80217B98(c);
    }
    if (f & 8) return 1;
    return 0;
}

s32 fn_801F9668(u32 flags, Scpt *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p = s->cur.b + 4;
        u32 v;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur.b = p;
        fn_80217830(v);
    }
    if (f & 0x8) {
        return 1;
    }
    return 0;
}

s16 fn_801F9708(u32 a0, Scpt *st) {
    u16 a = a0;
    if (a0 & 1) {
        float *p = st->cur.f + 1;
        int i;
        s8 j;
        s8 k;
        u32 r;
        i = RDI(p);
        j = RDI(p);
        k = RDI(p);
        st->cur.f = p;
        r = fn_80217FD4(i, j, k);
        if (r != 0) lbl_8030CEA0.x157c = r;
    }
    return (a >> 3) & 1;
}

s16 fn_801F984C(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        st->cur.f = p;
        if ((u32)n >= 3) {
            fn_80217830(n);
        }
    }
    return (f >> 3) & 1;
}
s32 fn_801F98E8(u32 flags, Scpt *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p = s->cur.b + 4;
        u32 v;
        if (3.4028235e38f == *(f32 *)p) {
            p += 4;
            v = 0x7FFFFFFF;
        } else {
            v = (s32)fn_801F6120((f32**)&p);
        }
        s->cur.b = p;
        fn_80168B7C(v);
    }
    if (f & 0x8) {
        return 1;
    }
    return 0;
}
s32 fn_801F9988(u16 flags, Scpt* obj)
{
    f32* p;
    f32 f0, f1, f2, f3;
    s32 h;
    u16 a;
    u32 c;
    s8 d;
    s8 e;
    s8 b;

    if (flags & 1) {
        p = obj->cur.f + 1;
        a = ReadInt(&p);
        f0 = fn_801F6120(&p);
        f1 = fn_801F6120(&p);
        f2 = fn_801F6120(&p);
        b = ReadInt(&p);
        f3 = fn_801F6120(&p);
        c = ReadInt(&p);
        d = ReadInt(&p);
        e = ReadInt(&p);
        h = ReadInt(&p);
        h = (h == 0x7FFFFFFF) ? 0 : h + 1;
        obj->cur.f = p;
        fn_80168398(f0, f1, f2, f3, c, d, e, b, a, h);
    }
    if (flags & 8)
        return 1;
    return 0;
}
s32 fn_801F9C18(u16 flags, Scpt* obj)
{
    f32* p;
    f32 f0, f1, f2, f3;
    s32 h;
    u16 a;
    u32 c;
    s8 d;
    s8 e;
    s8 b;

    if (flags & 1) {
        p = obj->cur.f + 1;
        a = ReadInt(&p);
        f0 = fn_801F6120(&p);
        f1 = fn_801F6120(&p);
        f2 = fn_801F6120(&p);
        b = ReadInt(&p);
        f3 = fn_801F6120(&p);
        c = ReadInt(&p);
        d = ReadInt(&p);
        e = ReadInt(&p);
        h = ReadInt(&p);
        h = (h == 0x7FFFFFFF) ? 0 : h + 1;
        obj->cur.f = p;
        fn_80169144(f0, f1, f2, f3, c, d, e, b, a, h);
    }
    if (flags & 8)
        return 1;
    return 0;
}

s32 fn_801F9EA8(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        s32 e;
        int a;
        s8 b;
        s8 d;
        f32 x;
        f32 y;
        f32 z;
        a = ReadInt(&p);
        b = ReadInt(&p);
        d = ReadInt(&p);
        e = ReadInt(&p);
        x = fn_801F6120(&p);
        y = fn_801F6120(&p);
        z = fn_801F6120(&p);
        c->cur.f = p;
        fn_801694FC(a, b, d, e, x, y, z);
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}


s16 fn_801FA060(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        s32 vol;
        s8 b;
        s8 d;
        u32 r;
        vol = ReadInt(&p);
        b = ReadInt(&p);
        d = ReadInt(&p);
        if (3.4028235e38f == *p) {
            p++;
        } else {
            fn_801F6120(&p);
        }
        c->cur.f = p;
        vol = 16 - vol;
        if (vol >= 16) {
            vol = 0;
        } else if (vol < 1) {
            vol = 1;
        }
        r = SePlay(vol, b, d);
        if (r != 0) {
            lbl_8030CEA0.x157c = r;
        }
    }
    return (flags >> 3) & 1;
}

s16 fn_801FA1D0(u32 flags, Scpt *s)
{
    u16 f = (u16)flags;
    if (flags & 1) {
        u8 *p4 = s->cur.b + 4;
        char *name = (char *)p4 + *(u32 *)p4;
        u8 *buf;
        s->cur.b = p4 + 4;
        buf = fn_801E1A2C(1, strlen(lbl_80346848) + strlen(name) + 5);
        strcpy(buf, lbl_80346848);
        strcat(buf, name);
        strcat(buf, &lbl_8034C198);
        fn_80219378(buf);
        if (buf != 0) {
            fn_801E1784(buf);
        }
    }
    return (s16)((f >> 3) & 1);
}

s32 fn_801FA290(u32 flags, Scpt *st) {
    u16 f = flags;
    if (flags & 1) {
        float *p = st->cur.f + 1;
        s32 n;
        s16 m;
        if (*p == 3.4028235e38f) {
            p++;
            n = 0x7FFFFFFF;
        } else {
            n = (s32)fn_801F6120(&p);
        }
        m = n;
        if (m <= 0) {
            m = 1;
        }
        fn_8021730C(1, (s32)(f32)fn_8026216C((f32)m * (16.666666f * (f32)lbl_803475B4)));
        st->cur.f = p;
    }
    if (f & 8) {
        return 1;
    }
    return 0;
}

s32 fn_801FA398(u16 flags, Scpt *c)
{
    float *p;
    s8 a;
    s8 b;
    if (flags & 1) {
        p = c->cur.f + 1;
        a = RDI(p);
        b = RDI(p);
        RDI(p);
        c->cur.f = p;
        fn_80218570(0, a, b);
    }
    if (flags & 8) {
        return 1;
    }
    return 0;
}
s16 fn_801FA4C0(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f + 1;
        s32 a;
        char* str;
        char* b1;
        char* b2;
        if (3.4028235e38f == *p) {
            p++;
            a = 0x7FFFFFFF;
        } else {
            a = (s32)fn_801F6120(&p);
        }
        str = (char*)p + *(s32*)p;
        p++;
        c->cur.f = p;
        b1 = fn_801E1A2C(1, strlen(lbl_80346848) + strlen(str) + 5);
        strcpy(b1, lbl_80346848);
        strcat(b1, str);
        strcat(b1, lbl_8034C1CC);
        b2 = fn_801E1A2C(1, strlen(lbl_80346848) + strlen(str) + 4);
        strcpy(b2, lbl_80346848);
        strcat(b2, str);
        strcat(b2, lbl_8034C1D4);
        fn_80218D80(b1, 0x42504d53, a);
        fn_80218D80(b2, 0x42534d53, a);
        if (b1 != 0) {
            fn_801E1784(b1);
        }
        if (b2 != 0) {
            fn_801E1784(b2);
        }
    }
    return (flags >> 3) & 1;
}

s32 fn_801FA630(u32 flags, Scpt* t)
{
    u16 f = flags;
    Work_801FA630* w;
    void* node;
    MvjParams* p;
    ScptCur cur;

    if (flags & 1) {
        cur.f = t->cur.f;
        cur.f++;
        w = fn_801E1A2C(1, 0x44);
        if (w == 0) fn_801DBE1C("scptMvj: malloc failed");
        t->work.p = w;
        w->id = ReadInt(&cur.f);
        w->x1c = 1;
        node = fn_801E1A2C(1, 0x30);
        if (node == 0) fn_801DBE1C("scptMvj Node: malloc failed");
        w->node = node;
        p = fn_801E1A2C(1, 0x90);
        /* the original re-tests node here, not p */
        if (node == 0) fn_801DBE1C("scptMvj NodeSub: malloc failed");
        w->params = p;
        w->params->i58 = ReadInt(&cur.f);
        w->params->f00 = fn_801F6120(&cur.f);
        w->params->f04 = fn_801F6120(&cur.f);
        w->params->f08 = fn_801F6120(&cur.f);
        w->params->f18 = 3.4028235e38f;
        w->params->i1c = ReadInt(&cur.f);
        w->params->i20 = ReadInt(&cur.f);
        w->params->f24 = fn_801F6120(&cur.f);
        w->params->i28 = ReadInt(&cur.f);
        w->params->i2c = 1;
        w->params->f30 = 3.4028235e38f;
        w->params->f34 = fn_801F6120(&cur.f);
        w->params->f38 = 3.4028235e38f;
        w->params->f48 = 3.4028235e38f;
        w->params->i4c = ReadInt(&cur.f);
        w->params->i50 = ReadInt(&cur.f);
        w->params->f54 = fn_801F6120(&cur.f);
        w->params->i5c = 1;
        w->params->f60 = fn_801F6120(&cur.f);
        w->params->f64 = fn_801F6120(&cur.f);
        w->params->f68 = fn_801F6120(&cur.f);
        w->params->f78 = 3.4028235e38f;
        w->params->i7c = ReadInt(&cur.f);
        w->params->i80 = ReadInt(&cur.f);
        w->params->f84 = fn_801F6120(&cur.f);
        w->params->i88 = ReadInt(&cur.f);
        w->params->i8c = 1;
        t->cur.f = cur.f;
        if (f & 4) {
            if (fn_800CCC48(6, w->id) != 0) {
                fn_801E1784(node);
                fn_801E1784(p);
                fn_801E1784(w);
                return 0;
            }
        }
        w->ev.hd.kind = 0;
        fn_80211058(t, 6, w->id, 0x18, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = t->work.p;
        if (t->handle == 0) {
            t->handle = fn_800CD0B8(t->a20, t->a24, t->a28, t->a2c);
            t->cnt++;
            if (t->cnt == 5) fn_801DBE1C("scptMVJ: message post time out");
        } else if (w->ev.hd.kind == 2) {
            if (w->node != 0) {
                fn_801E1784(w->node);
                w->node = 0;
            }
            if (w->params != 0) {
                fn_801E1784(w->params);
                w->params = 0;
            }
            return 0;
        }
    }
    if (f & 8) {
        w = t->work.p;
        if (w->node != 0) {
            fn_801E1784(w->node);
            w->node = 0;
        }
        if (w->params != 0) {
            fn_801E1784(w->params);
            w->params = 0;
        }
        return 1;
    }
    return 1;
}

s32 fn_801FABDC(u16 flags, Scpt* c)
{
    Work_801FABDC* w;
    MvNode* nodes;
    ScptCur p;
    Actor* o;
    Actor* t;
    u32 i;
    if (flags & 1) {
        p.f = c->cur.f;
        p.f = p.f + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptMVSF: malloc failed");
        c->work.p = w;
        w->id = ReadInt(&p.f);
        w->count = *p.i++;
        w->result = NULL;
        nodes = fn_801E1A2C(1, w->count * 0x30);
        if (nodes == NULL) fn_801DBE1C("scptMVSF Node: malloc failed");
        w->nodes = nodes;
        for (i = 0; i < w->count; i++) {
            w->nodes[i].x = fn_801F6120(&p.f);
            w->nodes[i].y = fn_801F6120(&p.f);
            w->nodes[i].z = fn_801F6120(&p.f);
            w->nodes[i].x18 = fn_801F6120(&p.f);
            w->nodes[i].x1c = ReadInt(&p.f);
            w->nodes[i].x20 = ReadInt(&p.f);
            w->nodes[i].x24 = fn_801F6120(&p.f);
            w->nodes[i].x28 = ReadInt(&p.f);
            w->nodes[i].x2c = ReadInt(&p.f);
            if (w->nodes[i].x == 0.0f) w->nodes[i].x = 0.00001f;
            if (w->nodes[i].y == 0.0f) w->nodes[i].y = 0.00001f;
            if (w->nodes[i].z == 0.0f) w->nodes[i].z = 0.00001f;
        }
        c->cur.f = p.f;
        if (w->id == 0xffff) {
            o = lbl_80347450;
        } else {
            Obj10A* tk = fn_8010A164(w->id);
            o = tk->x24;
        }
        if (o->x1d8 != NULL) {
            f32 px, py, pz;
            f32* save;
            t = o->x1d8->x8;
            if (t == NULL) t = o;
            px = t->pos.x;
            py = t->pos.y;
            pz = t->pos.z;
            save = fn_801E1A2C(1, w->count * 4);
            { s32 j; for (j = 0; j < w->count; j++) save[j] = w->nodes[j].y; }
            fn_8016058C(w->count, w->nodes, t);
            w->result = fn_801607A0(w->count, w->nodes, &t->pos);
            for (i = 0; i < w->count; i++) w->nodes[i].y = save[i];
            if (save != NULL) fn_801E1784(save);
            t->pos.x = px;
            t->pos.y = py;
            t->pos.z = pz;
        }
        if (flags & 4) {
            if (fn_800CCC48(6, w->id) != 0) {
                fn_801E1784(nodes);
                fn_801E1784(w);
                return 0;
            }
        }
        w->ev.hd.kind = 0;
        fn_80211058(c, 6, w->id, 0x17, lbl_8030CEA0.x08, &w->ev);
    }
    if (flags & 2) {
        Work_801FABDC* cur = c->work.p;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt += 1;
            if (c->cnt == 5) fn_801DBE1C("scptMVSF: message post time out");
        } else if (cur->ev.hd.kind == 2) {
            fn_80165C84(cur->result);
            if (cur->nodes != NULL) {
                fn_801E1784(cur->nodes);
                cur->nodes = NULL;
            }
            return 0;
        }
    }
    if (flags & 8) {
        Work_801FABDC* cur = c->work.p;
        if (cur->result != NULL) fn_80165C84(cur->result);
        if (cur->nodes != NULL) {
            fn_801E1784(cur->nodes);
            cur->nodes = NULL;
        }
        return 1;
    }
    return 1;
}


s32 fn_801FB120(u16 flags, Scpt* c)
{
    Work_801FABDC* w;
    MvNode* nodes;
    ScptCur p;
    Actor* o;
    Actor* t;
    u32 i;
    if (flags & 1) {
        p.f = c->cur.f;
        p.f = p.f + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptMVS: malloc failed");
        c->work.p = w;
        w->id = ReadInt(&p.f);
        w->count = *p.i++;
        w->result = NULL;
        nodes = fn_801E1A2C(1, w->count * 0x30);
        if (nodes == NULL) fn_801DBE1C("scptMVS Node: malloc failed");
        w->nodes = nodes;
        for (i = 0; i < w->count; i++) {
            w->nodes[i].x = fn_801F6120(&p.f);
            w->nodes[i].y = fn_801F6120(&p.f);
            w->nodes[i].z = fn_801F6120(&p.f);
            w->nodes[i].x18 = fn_801F6120(&p.f);
            w->nodes[i].x1c = ReadInt(&p.f);
            w->nodes[i].x20 = ReadInt(&p.f);
            w->nodes[i].x24 = fn_801F6120(&p.f);
            w->nodes[i].x28 = ReadInt(&p.f);
            w->nodes[i].x2c = ReadInt(&p.f);
            if (w->nodes[i].x == 0.0f) w->nodes[i].x = 0.00001f;
            if (w->nodes[i].y == 0.0f) w->nodes[i].y = 0.00001f;
            if (w->nodes[i].z == 0.0f) w->nodes[i].z = 0.00001f;
        }
        c->cur.f = p.f;
        if (w->id == 0xffff) {
            o = lbl_80347450;
        } else {
            Obj10A* tk = fn_8010A164(w->id);
            o = tk->x24;
        }
        if (o->x1d8 != NULL) {
            f32 px, py, pz;
            f32* save;
            t = o->x1d8->x8;
            if (t == NULL) t = o;
            px = t->pos.x;
            py = t->pos.y;
            pz = t->pos.z;
            save = fn_801E1A2C(1, w->count * 4);
            { s32 j; for (j = 0; j < w->count; j++) save[j] = w->nodes[j].y; }
            fn_8016058C(w->count, w->nodes, t);
            w->result = fn_80165EE4(w->count, w->nodes, &t->pos);
            for (i = 0; i < w->count; i++) w->nodes[i].y = save[i];
            if (save != NULL) fn_801E1784(save);
            t->pos.x = px;
            t->pos.y = py;
            t->pos.z = pz;
        }
        if (flags & 4) {
            if (fn_800CCC48(6, w->id) != 0) {
                fn_801E1784(nodes);
                fn_801E1784(w);
                return 0;
            }
        }
        w->ev.hd.kind = 0;
        fn_80211058(c, 6, w->id, 0x16, lbl_8030CEA0.x08, &w->ev);
    }
    if (flags & 2) {
        Work_801FABDC* cur = c->work.p;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt += 1;
            if (c->cnt == 5) fn_801DBE1C("scptMVS: message post time out");
        } else if (cur->ev.hd.kind == 2) {
            fn_80165C84(cur->result);
            if (cur->nodes != NULL) {
                fn_801E1784(cur->nodes);
                cur->nodes = NULL;
            }
            return 0;
        }
    }
    if (flags & 8) {
        Work_801FABDC* cur = c->work.p;
        if (cur->result != NULL) fn_80165C84(cur->result);
        if (cur->nodes != NULL) {
            fn_801E1784(cur->nodes);
            cur->nodes = NULL;
        }
        return 1;
    }
    return 1;
}


s32 fn_801FB664(u16 flags, Scpt* c)
{
    Work_801FABDC* w;
    MvNode* nodes;
    ScptCur p;
    Actor* o;
    Actor* t;
    u32 i;
    if (flags & 1) {
        p.f = c->cur.f;
        p.f = p.f + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptMVF: malloc failed");
        c->work.p = w;
        w->id = ReadInt(&p.f);
        w->count = *p.i++;
        w->result = NULL;
        nodes = fn_801E1A2C(1, w->count * 0x30);
        if (nodes == NULL) fn_801DBE1C("scptMVF Node: malloc failed");
        w->nodes = nodes;
        for (i = 0; i < w->count; i++) {
            w->nodes[i].x = fn_801F6120(&p.f);
            w->nodes[i].y = fn_801F6120(&p.f);
            w->nodes[i].z = fn_801F6120(&p.f);
            w->nodes[i].x18 = fn_801F6120(&p.f);
            w->nodes[i].x1c = ReadInt(&p.f);
            w->nodes[i].x20 = ReadInt(&p.f);
            w->nodes[i].x24 = fn_801F6120(&p.f);
            w->nodes[i].x28 = ReadInt(&p.f);
            w->nodes[i].x2c = ReadInt(&p.f);
            if (w->nodes[i].x == 0.0f) w->nodes[i].x = 0.00001f;
            if (w->nodes[i].y == 0.0f) w->nodes[i].y = 0.00001f;
            if (w->nodes[i].z == 0.0f) w->nodes[i].z = 0.00001f;
        }
        c->cur.f = p.f;
        if (w->id == 0xffff) {
            o = lbl_80347450;
        } else {
            Obj10A* tk = fn_8010A164(w->id);
            o = tk->x24;
        }
        if (o->x1d8 != NULL) {
            f32 px, py, pz;
            f32* save;
            t = o->x1d8->x8;
            if (t == NULL) t = o;
            px = t->pos.x;
            py = t->pos.y;
            pz = t->pos.z;
            save = fn_801E1A2C(1, w->count * 4);
            { s32 j; for (j = 0; j < w->count; j++) save[j] = w->nodes[j].y; }
            fn_8016058C(w->count, w->nodes, t);
            w->result = fn_801607A0(w->count, w->nodes, &t->pos);
            for (i = 0; i < w->count; i++) w->nodes[i].y = save[i];
            if (save != NULL) fn_801E1784(save);
            t->pos.x = px;
            t->pos.y = py;
            t->pos.z = pz;
        }
        if (flags & 4) {
            if (fn_800CCC48(6, w->id) != 0) {
                fn_801E1784(nodes);
                fn_801E1784(w);
                return 0;
            }
        }
        w->ev.hd.kind = 0;
        fn_80211058(c, 6, w->id, 0x15, lbl_8030CEA0.x08, &w->ev);
    }
    if (flags & 2) {
        Work_801FABDC* cur = c->work.p;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt += 1;
            if (c->cnt == 5) fn_801DBE1C("scptMVF: message post time out");
        } else if (cur->ev.hd.kind == 2) {
            fn_80165C84(cur->result);
            if (cur->nodes != NULL) {
                fn_801E1784(cur->nodes);
                cur->nodes = NULL;
            }
            return 0;
        }
    }
    if (flags & 8) {
        Work_801FABDC* cur = c->work.p;
        if (cur->result != NULL) fn_80165C84(cur->result);
        if (cur->nodes != NULL) {
            fn_801E1784(cur->nodes);
            cur->nodes = NULL;
        }
        return 1;
    }
    return 1;
}

s32 fn_801FBBA8(u16 flags, Scpt* c)
{
    if (flags & 1) {
        f32* p = c->cur.f;
        Fx_801FBBA8* fx = fn_801E1A2C(1, 0x44);
        if (fx == 0) {
            fn_801DBE1C("scptDefMO: malloc failed");
        }
        c->work.fx_801FBBA8 = fx;
        p++;
        fx->x18 = ReadInt(&p);
        fx->x1c = ReadInt(&p);
        fx->x20 = ReadInt(&p);
        fx->x24 = fn_801F6120(&p);
        fx->ev.hd.kind = 0;
        fn_80211058(c, 6, fx->x18, 0x12, lbl_8030CEA0.x08, &fx->ev);
        c->cur.f = p;
    }
    if (flags & 2) {
        Fx_801FBBA8* cur = c->work.fx_801FBBA8;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt++;
            if (c->cnt == 5) {
                fn_801DBE1C("scptDefMO: message post time out");
            }
        } else if (cur->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}
s32 fn_801FBD9C(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Work801F8* s = fn_801E1A2C(1, 0x44);
        if (s == 0) {
            fn_801DBE1C("scptPlayColMO: malloc failed");
        }
        o->work.work801F8 = s;
        p++;
        s->n = ReadInt(&p);
        s->x1c = ReadInt(&p);
        s->x20 = ReadInt(&p);
        s->x24 = fn_801F6120(&p);
        s->ev.hd.kind = 0;
        fn_80211058(o, 6, s->n, 0x14, lbl_8030CEA0.x08, &s->ev);
        o->cur.f = p;
    }
    if (flags & 2) {
        Work801F8* st = o->work.work801F8;
        if (o->handle == 0) {
            o->handle = fn_800CD0B8(o->a20, o->a24, o->a28, o->a2c);
            o->cnt++;
            if (o->cnt == 5) {
                fn_801DBE1C("scptPlayColMO: message post time out");
            }
        } else if (st->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}
s32 fn_801FBF90(u16 flags, Scpt* o) {
    if (flags & 1) {
        f32* p = o->cur.f;
        Work801F8* s = fn_801E1A2C(1, 0x44);
        if (s == 0) {
            fn_801DBE1C("scptPlayMO: malloc failed");
        }
        o->work.work801F8 = s;
        p++;
        s->n = ReadInt(&p);
        s->x1c = ReadInt(&p);
        s->x20 = ReadInt(&p);
        s->x24 = fn_801F6120(&p);
        s->ev.hd.kind = 0;
        fn_80211058(o, 6, s->n, 0x13, lbl_8030CEA0.x08, &s->ev);
        o->cur.f = p;
    }
    if (flags & 2) {
        Work801F8* st = o->work.work801F8;
        if (o->handle == 0) {
            o->handle = fn_800CD0B8(o->a20, o->a24, o->a28, o->a2c);
            o->cnt++;
            if (o->cnt == 5) {
                fn_801DBE1C("PlayMO: message post time out");
            }
        } else if (st->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (flags & 8) {
        return 1;
    }
    return 1;
}

s32 fn_801FC184(u32 flags, Scpt* s) {
    Work801FC* w;
    f32* cur;
    u16 f = flags;
    if (f & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptRollP: malloc failed");
        s->work.work801FC = w;
        w->n = ReadInt(&cur);
        w->x1c = fn_801F6120(&cur);
        w->x20 = fn_801F6120(&cur);
        w->x24 = fn_801F6120(&cur);
        w->x28 = ReadInt(&cur);
        w->x2c = ReadInt(&cur);
        w->x30 = ReadInt(&cur);
        w->x34 = fn_801F6120(&cur);
        s->cur.f = cur;
        if (f & 4) {
            if (fn_800CCC48(6, w->n) != 0) {
                fn_801E1784(w);
                return 0;
            }
        }
        w->ev.hd.kind = 0;
        fn_80211058(s, 6, w->n, 0xb, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = s->work.work801FC;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptRollP: message post time out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

s32 fn_801FC408(u32 flags, Scpt* s) {
    Work801FC* w;
    f32* cur;
    u16 f = flags;
    if (f & 1) {
        cur = s->cur.f;
        cur = cur + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptRollA: malloc failed");
        s->work.work801FC = w;
        w->n = ReadInt(&cur);
        w->x1c = fn_801F6120(&cur);
        w->x20 = fn_801F6120(&cur);
        w->x24 = fn_801F6120(&cur);
        w->x28 = ReadInt(&cur);
        w->x2c = ReadInt(&cur);
        w->x30 = ReadInt(&cur);
        w->x34 = fn_801F6120(&cur);
        s->cur.f = cur;
        if (f & 4) {
            if (fn_800CCC48(6, w->n) != 0) {
                fn_801E1784(w);
                return 0;
            }
        }
        w->ev.hd.kind = 0;
        fn_80211058(s, 6, w->n, 0xa, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        w = s->work.work801FC;
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            s->cnt += 1;
            if (s->cnt == 5) fn_801DBE1C("scptRollA: message post time out");
        } else if (w->ev.hd.kind == 2) {
            return 0;
        }
    }
    if (f & 8) return 1;
    return 1;
}

s32 fn_801FC68C(u16 flags, Scpt* c)
{
    Work_801FC68C* w;
    MvNode* nodes;
    ScptCur p;
    s32 i;
    if (flags & 1) {
        p.f = c->cur.f;
        p.f = p.f + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptMVR: malloc failed");
        c->work.p = w;
        w->id = ReadInt(&p.f);
        w->count = *p.i++;
        nodes = fn_801E1A2C(1, w->count * 0x30);
        if (nodes == NULL) fn_801DBE1C("scptMVR Node: malloc failed");
        w->nodes = nodes;
        for (i = 0; i < w->count; i++) {
            w->nodes[i].x = fn_801F6120(&p.f);
            w->nodes[i].y = fn_801F6120(&p.f);
            w->nodes[i].z = fn_801F6120(&p.f);
            w->nodes[i].x18 = fn_801F6120(&p.f);
            w->nodes[i].x1c = ReadInt(&p.f);
            w->nodes[i].x20 = ReadInt(&p.f);
            w->nodes[i].x24 = fn_801F6120(&p.f);
            w->nodes[i].x28 = ReadInt(&p.f);
            w->nodes[i].x2c = ReadInt(&p.f);
            if (w->nodes[i].x == 0.0f) w->nodes[i].x = 0.00001f;
            if (w->nodes[i].y == 0.0f) w->nodes[i].y = 0.00001f;
            if (w->nodes[i].z == 0.0f) w->nodes[i].z = 0.00001f;
        }
        c->cur.f = p.f;
        if (flags & 4) {
            if (fn_800CCC48(6, w->id) != 0) {
                if (nodes != NULL) fn_801E1784(nodes);
                if (w != NULL) fn_801E1784(w);
                return 0;
            }
        }
        w->ev.hd.kind = 0;
        fn_80211058(c, 6, w->id, 7, lbl_8030CEA0.x08, &w->ev);
    }
    if (flags & 2) {
        Work_801FC68C* cur = c->work.p;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt += 1;
            if (c->cnt == 5) fn_801DBE1C("scptMVR: message post time out");
        } else if (cur->ev.hd.kind == 2) {
            if (cur->nodes != NULL) {
                fn_801E1784(cur->nodes);
                cur->nodes = NULL;
            }
            return 0;
        }
    }
    if (flags & 8) {
        Work_801FC68C* cur = c->work.p;
        if (cur->nodes != NULL) {
            fn_801E1784(cur->nodes);
            cur->nodes = NULL;
        }
        return 1;
    }
    return 1;
}


s32 fn_801FCAAC(u16 flags, Scpt* c)
{
    Work_801FABDC* w;
    MvNode* nodes;
    ScptCur p;
    Actor* o;
    Actor* t;
    u32 i;
    if (flags & 1) {
        p.f = c->cur.f;
        p.f = p.f + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("scptMV: malloc failed");
        c->work.p = w;
        w->id = ReadInt(&p.f);
        w->count = *p.i++;
        w->result = NULL;
        nodes = fn_801E1A2C(1, w->count * 0x30);
        if (nodes == NULL) fn_801DBE1C("scptMV Node: malloc failed");
        w->nodes = nodes;
        for (i = 0; i < w->count; i++) {
            w->nodes[i].x = fn_801F6120(&p.f);
            w->nodes[i].y = fn_801F6120(&p.f);
            w->nodes[i].z = fn_801F6120(&p.f);
            w->nodes[i].x18 = fn_801F6120(&p.f);
            w->nodes[i].x1c = ReadInt(&p.f);
            w->nodes[i].x20 = ReadInt(&p.f);
            w->nodes[i].x24 = fn_801F6120(&p.f);
            w->nodes[i].x28 = ReadInt(&p.f);
            w->nodes[i].x2c = ReadInt(&p.f);
            if (w->nodes[i].x == 0.0f) w->nodes[i].x = 0.00001f;
            if (w->nodes[i].y == 0.0f) w->nodes[i].y = 0.00001f;
            if (w->nodes[i].z == 0.0f) w->nodes[i].z = 0.00001f;
        }
        c->cur.f = p.f;
        if (w->id == 0xffff) {
            o = lbl_80347450;
        } else {
            Obj10A* tk = fn_8010A164(w->id);
            o = tk->x24;
        }
        if (o->x1d8 != NULL) {
            f32 px, py, pz;
            f32* save;
            t = o->x1d8->x8;
            if (t == NULL) t = o;
            px = t->pos.x;
            py = t->pos.y;
            pz = t->pos.z;
            save = fn_801E1A2C(1, w->count * 4);
            { s32 j; for (j = 0; j < w->count; j++) save[j] = w->nodes[j].y; }
            fn_8016058C(w->count, w->nodes, t);
            w->result = fn_80165EE4(w->count, w->nodes, &t->pos);
            for (i = 0; i < w->count; i++) w->nodes[i].y = save[i];
            if (save != NULL) fn_801E1784(save);
            t->pos.x = px;
            t->pos.y = py;
            t->pos.z = pz;
        }
        if (flags & 4) {
            if (fn_800CCC48(6, w->id) != 0) {
                fn_801E1784(nodes);
                fn_801E1784(w);
                return 0;
            }
        }
        w->ev.hd.kind = 0;
        fn_80211058(c, 6, w->id, 6, lbl_8030CEA0.x08, &w->ev);
    }
    if (flags & 2) {
        Work_801FABDC* cur = c->work.p;
        if (c->handle == 0) {
            c->handle = fn_800CD0B8(c->a20, c->a24, c->a28, c->a2c);
            c->cnt += 1;
            if (c->cnt == 5) fn_801DBE1C("scptMV: message post time out");
        } else if (cur->ev.hd.kind == 2) {
            fn_80165C84(cur->result);
            if (cur->nodes != NULL) {
                fn_801E1784(cur->nodes);
                cur->nodes = NULL;
            }
            return 0;
        }
    }
    if (flags & 8) {
        Work_801FABDC* cur = c->work.p;
        if (cur->result != NULL) fn_80165C84(cur->result);
        if (cur->nodes != NULL) {
            fn_801E1784(cur->nodes);
            cur->nodes = NULL;
        }
        return 1;
    }
    return 1;
}
