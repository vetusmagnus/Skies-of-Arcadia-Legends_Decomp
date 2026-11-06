#include "game/shop.h"



void fn_80199B9C(void* p, f32 v) {
    *(f32*)((u8*)p + 0x34) = v;
}

void fn_80199BA4(void* p, u8 v) {
    *(u8*)((u8*)p + 0x40) = v;
}

void fn_80199BAC(void* p, f32 a, f32 b) {
    *(f32*)((u8*)p + 0x4) = a;
    *(f32*)((u8*)p + 0x8) = b;
}

void fn_80199BB8(void* p, f32 a, f32 b) {
    *(f32*)((u8*)p + 0xC) = a;
    *(f32*)((u8*)p + 0x10) = b;
}

void fn_80199F38(void* obj) {
    UiObjUpdate(obj);
}

void fn_80199F58(Obj_80199F58 *o) {
    if (o->pbc != 0) {
        fn_801E17E0(o->pbc);
    }
    if (o->f9c > 0) {
        o->f9c = 0;
        fn_801E17E0(o->p94);
        fn_801E17E0(o->p98);
    }
    if (o->fa8 > 0) {
        o->fa8 = 0;
        fn_801E17E0(o->pa0);
        fn_801E17E0(o->pa4);
    }
    if (o->fb4 > 0) {
        o->fb4 = 0;
        fn_801E17E0(o->pac);
        fn_801E17E0(o->pb0);
    }
}

s32 fn_80199FFC(PosTabs *t, s8 idx, s32 val, s16 x, s16 y, s8 kind)
{
    switch (kind) {
    case 0:
        t->a0[idx] = val;
        t->f0[idx * 2] = x;
        t->f0[idx * 2 + 1] = y;
        break;
    case 1:
        t->a1[idx] = val;
        t->f1[idx * 2] = x;
        t->f1[idx * 2 + 1] = y;
        break;
    case 2:
        t->a2[idx] = val;
        t->f2[idx * 2] = x;
        t->f2[idx * 2 + 1] = y;
        break;
    }
    return val;
}

void fn_8019A15C(u8 *o, s8 a, s8 b, s8 c) {
    *(s8 *)(o + 0x28) = a;
    if (a > 0) {
        *(void **)(o + 0x20) = fn_801E1C7C(a * 4);
        *(void **)(o + 0x24) = fn_801E1C7C(a * 8);
    }
    *(s8 *)(o + 0x34) = c;
    if (c > 0) {
        *(void **)(o + 0x2c) = fn_801E1C7C(c * 4);
        *(void **)(o + 0x30) = fn_801E1C7C(c * 8);
    }
    *(s8 *)(o + 0x40) = b;
    if (b > 0) {
        *(void **)(o + 0x38) = fn_801E1C7C(b * 4);
        *(void **)(o + 0x3c) = fn_801E1C7C(b * 8);
    }
}

s32 fn_8019A21C(u32 mask, s32 d, s32 n, s32 unused, s32 max)
{
    s32 i;
    s32 k;

    k = n + d;
    if (bit_set(mask, k)) {
        return k;
    }
    if (d > 0) {
        for (i = n; i < max; i++) {
            k = n + d * (i - n + 1);
            if (bit_set(mask, k)) {
                return k;
            }
        }
        if (i >= max) {
            for (i = 0; i < n; i++) {
                if (mask & (1 << (i * d))) {
                    return i;
                }
            }
            if (i >= n) {
                return n;
            }
        }
    } else {
        for (i = n; i > 0; i--) {
            k = n + d * (n - i + 1);
            if (bit_set(mask, k)) {
                return k;
            }
        }
        if (i <= 0) {
            for (k = max; k > n; k--) {
                if (mask & (1 << k)) {
                    return k;
                }
            }
            if (k <= n) {
                return n;
            }
        }
    }
}

Sprite* fn_8019AB94(s16 a) {
    switch (a) {
    case 0:
        return fn_801D68C4(lbl_803470EC, 4);
    case 1:
        return fn_801D68C4(lbl_803470EC, 5);
    case 2:
        return fn_801D68C4(lbl_803470EC, 6);
    case 3:
        return fn_801D68C4(lbl_803470EC, 7);
    case 4:
        return fn_801D68C4(lbl_803470EC, 8);
    case 5:
        return fn_801D68C4(lbl_803470EC, 9);
    case 6:
        return fn_801D68C4(lbl_803470EC, 10);
    case 7:
        return fn_801D68C4(lbl_803470EC, 11);
    case 8:
        return fn_801D68C4(lbl_803470EC, 12);
    case 9:
        return fn_801D68C4(lbl_803470EC, 13);
    case -1:
        return fn_801D68C4(lbl_803470EC, 4);
    default:
        return fn_801D68C4(lbl_803470EC, 4);
    }
}

Sprite* fn_8019AC94(s16 a) {
    switch (a) {
    case 0:
        return fn_801D68C4(lbl_803470F4, 5);
    case 1:
        return fn_801D68C4(lbl_803470F4, 6);
    case 2:
        return fn_801D68C4(lbl_803470F4, 7);
    case 3:
        return fn_801D68C4(lbl_803470F4, 8);
    case 4:
        return fn_801D68C4(lbl_803470F4, 9);
    case 5:
        return fn_801D68C4(lbl_803470F4, 10);
    case 6:
        return fn_801D68C4(lbl_803470F4, 11);
    case 7:
        return fn_801D68C4(lbl_803470F4, 12);
    case 8:
        return fn_801D68C4(lbl_803470F4, 13);
    case 9:
        return fn_801D68C4(lbl_803470F4, 14);
    case -1:
        return fn_801D68C4(lbl_803470F4, 5);
    default:
        return fn_801D68C4(lbl_803470F4, 5);
    }
}

void fn_8019AD94(void* p, u32 a, u32 b) {
    ((u32*)p)[0] = a;
    ((u32*)p)[1] = b;
}
void fn_8019ADA0(Self_8016F138* self) {
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
            fn_8019AE84((struct Self_8016F594 *)self->inner);
        }
        break;
    case 0x64:
        self->state = 0xff;
        break;
    case 0xff:
        fn_80199F58((Obj_80199F58 *)self->inner);
        self->flags |= 0x40;
        break;
    }
}

void fn_8019B36C(u8 *o) {
    *(f32 *)(o + 0x0) = -5440.0f;
    *(f32 *)(o + 0x4) = 0.0f;
    *(f32 *)(o + 0x10) = 1.0f;
    *(f32 *)(o + 0x14) = 0.0f;
    *(f32 *)(o + 0x18) = 1.0f;
    *(f32 *)(o + 0x1c) = 0.0f;
    *(u32 *)(o + 0x8) = 0;
    *(u32 *)(o + 0xc) = 0;
    fn_8019A15C(o, 1, 0, 1);
    *(void **)(*(u8 **)(o + 0x2c)) = fn_801D68C4(lbl_803470E8, 2);
    *(f32 *)(*(u8 **)(o + 0x30) + 0x0) = 0.0f;
    *(f32 *)(*(u8 **)(o + 0x30) + 0x4) = 0.0f;
    *(void **)(*(u8 **)(o + 0x20)) = fn_801D68C4(lbl_803470F0, 10);
    *(f32 *)(*(u8 **)(o + 0x24) + 0x0) = 0.0f;
    *(f32 *)(*(u8 **)(o + 0x24) + 0x4) = 0.0f;
    *(u32 *)(o + 0x44) = 0;
}

void fn_8019B42C(void* p, u32 a) {
    ((u32*)p)[0] = a;
    ((u8**)p)[1] = lbl_8030741C.b8;
    ((u32*)p)[2] = 0;
}

void fn_8019B44C(Self_8019B44C *self) {
    extern void fn_80199F38(void *ui);
    extern void UiObjCalcRect(void *ui);
    extern void CampPanelDrawFrame(void);
    extern void fn_8019BB54(Ctx_8019B44C *c);
    extern void fn_8019B980(Ctx_8019B44C *c);
    extern void fn_8019B59C(Ctx_8019B44C *c);
    extern void fn_801E17E0(void *p);
    extern void fn_80199F58(Ctx_8019B44C *c);
    Ctx_8019B44C *ctx = self->ctx;
    void *ui = ctx->ui;
    Sub_8019B44C *sub = ctx->pbc;

    if (lbl_803475D8 != 0) {
        self->state19 = 0xff;
    }
    switch (self->state19) {
    case 0xfe:
    case 0:
        self->state19 = 1;
        sub->w8 = 0;
    case 1:
        fn_80199F38(ui);
        UiObjCalcRect(ui);
        if (self->ctx->w0 == 1) {
            CampPanelDrawFrame();
            switch (sub->mode) {
            case 0:
                fn_8019BB54(self->ctx);
                break;
            case 1:
                fn_8019B980(self->ctx);
                break;
            case 2:
                fn_8019B59C(self->ctx);
                break;
            }
        }
        break;
    case 100:
        self->state19 = 0xff;
        break;
    case 0xff:
        if (sub->w8 != 0) {
            fn_801E17E0(sub->w8);
            sub->w8 = 0;
        }
        fn_80199F58(self->ctx);
        self->flags18 |= 0x40;
        break;
    }
}

void fn_8019B980(Obj_8019B980 *self) {
    extern const char *lbl_802EBCB0[4];
    extern s16 lbl_802EBCC0[8];
    extern s32 lbl_803073F0[11];
    extern f32 TextGetZ(void);
    extern void TextSetZ(f32 z);
    extern void TextPushColor(void);
    extern void TextSetColor(u32 c);
    extern void TextPrint(s16 x, s16 y, const char *s);
    extern void TextPrintf(s16 x, s16 y, const char *fmt, ...);
    extern void TextPopColor(s32 n);
    s16 x = (s16)self->x;
    s16 y = (s16)self->y;
    f32 z = TextGetZ();
    TextSetZ(10.0f + self->z);
    TextPushColor();
    TextSetColor(0xff201008);
    TextPrint((s16)(x + lbl_802EBCC0[0]), (s16)(y + lbl_802EBCC0[1]), lbl_802EBCB0[0]);
    TextPrintf(x + lbl_802EBCC0[0] + 0xa8, y + lbl_802EBCC0[1], "%6d", lbl_803073F0[0]);
    TextPrint((s16)(x + lbl_802EBCC0[2]), (s16)(y + lbl_802EBCC0[3]), lbl_802EBCB0[1]);
    TextPrintf(x + lbl_802EBCC0[2] + 0x90, y + lbl_802EBCC0[3], "%8d", lbl_803073F0[1]);
    TextPrint((s16)(x + lbl_802EBCC0[6]), (s16)(y + lbl_802EBCC0[7]), lbl_802EBCB0[3]);
    TextPrintf(x + lbl_802EBCC0[6] + 0xa8, y + lbl_802EBCC0[7], "%8d", lbl_803073F0[2]);
    TextPopColor(1);
    TextSetZ(z);
}

void fn_8019BD2C(Obj48 *o, s32 mode) {
    extern void *lbl_803470F0, *lbl_803470E8, *lbl_803470F4;
    extern void *fn_801D68C4(void *a, u32 n);
    extern void fn_8019A15C(void *p, s32 a, s32 b, s32 c);
    extern void fn_80199FFC(void *p, s32 a, void *b, s32 c, s32 d, s32 e);
    o->f00 = -4000.0f;
    o->f04 = 0.0f;
    o->f10 = 1.0f;
    o->f14 = 0.0f;
    o->f18 = 1.0f;
    o->f1c = 0.0f;
    o->i08 = 0;
    o->i0c = 0;
    switch (mode) {
    case 0:
    case 1:
        fn_8019A15C(o, 1, 1, 1);
        fn_80199FFC(o, 0, fn_801D68C4(lbl_803470F4, 0x4e), 0, 0, 2);
        o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x68);
        o->p24->f0 = 0.0f;
        o->p24->f4 = 0.0f;
        o->p2c->p0 = fn_801D68C4(lbl_803470E8, 0xb);
        o->p30->f0 = 0.0f;
        o->p30->f4 = 0.0f;
        o->p44 = fn_801D68C4(lbl_803470F0, 0x6a);
        break;
    case 2:
        fn_8019A15C(o, 2, 0, 1);
        o->p20->p0 = fn_801D68C4(lbl_803470F0, 0x20);
        o->p24->f0 = 0.0f;
        o->p24->f4 = 2.0f;
        o->p20->p4 = fn_801D68C4(lbl_803470F0, 0x1f);
        o->p24->f8 = 0.0f;
        o->p24->fc = 330.0f;
        o->p2c->p0 = fn_801D68C4(lbl_803470E8, 0xc);
        o->p30->f0 = 0.0f;
        o->p30->f4 = 0.0f;
        o->p44 = fn_801D68C4(lbl_803470F0, 0x6b);
        break;
    }
}

void fn_8019BED8(struct Task* t, EvObj* o) {
    EvExt* e;
    Rec* r;
    s32 ty;
    s32 k;
    t->state = 5;
    e = o->ext;
    if (e == NULL) return;
    o->hit = fn_802258BC(0xffff, (u16)e->x04, 2);
    if (o->hit == NULL) return;
    r = e->info;
    if (r == NULL) return;
    ty = r->type;
    if (ty <= 10) return;
    o->x20c = r->f24;
    k = r->f28;
    o->x210 = k;
    if (k == 0) {
        if ((u32)ty == 0xf && r->f34 > r->f38) {
            o->x24c.x = 0.0001f * r->f2c;
            o->x24c.y = 0.0001f * r->f30;
            o->x24c.z = 0.01f * r->f34;
            o->x258 = 0.01f * r->f38;
            o->ang[1] = 182.04445f * (0.01f * r->f3c);
            o->x158.y = 0.0f;
            o->x158.x = 0.0f;
            o->x158.z = -o->x24c.x;
            fn_801DCE18(&o->x158.x, &o->x158.x, o->ang[1]);
            t->state = 3;
        }
    } else if (k == 1) {
        if ((u32)ty == 0x10 && r->f34 > r->f38) {
            o->x24c.x = 0.0001f * r->f2c;
            o->x24c.y = 0.0001f * r->f30;
            o->x24c.z = 0.01f * r->f34;
            o->x258 = 0.01f * r->f38;
            o->pos.x = 0.01f * r->f3c;
            o->pos.z = 0.01f * r->f40;
            o->x158.y = 0.0f;
            t->state = 4;
        }
    }
}

void fn_8019C190(struct Task* t) {
    EvObj* o;
    f32 d;
    f32 k;
    o = t->work;
    switch (t->state) {
    case 0:
    case 1:
    case 0xfe:
        if (lbl_80347450 == NULL || lbl_803473A8 == 0) {
            t->state = 1;
            break;
        }
    case 2:
        fn_8019BED8(t, o);
        break;
    case 3:
        if (InArea_8019C190(o)) fn_800CF8C4(&o->x158.x, o->x24c.y);
        break;
    case 4:
        if (InArea_8019C190(o)) {
            f32 dz = lbl_80347450->pos.z - o->pos.z;
            f32 dx = lbl_80347450->pos.x - o->pos.x;
            d = dx * dx + dz * dz;
            if (0.000000009999999f < d) {
                k = o->x24c.x / fn_80291A5C(d);
                o->x158.x = dx * k;
                o->x158.z = dz * k;
                fn_800CF8C4(&o->x158.x, o->x24c.y);
            }
        }
        break;
    case 5:
        fn_801DBE1C("BadOption %d", o->x17a);
        break;
    default:
        if (o->hit != NULL) {
            fn_801E17E0(o->hit);
            o->hit = NULL;
        }
        fn_80100B74(t);
        break;
    }
}

void fn_8019C424(Task *t)
{
    EvInfoSpark *info;
    EvObj *o;
    Obj_8019CB80_8019C424 *sp;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 r1;
    f32 r2;
    NJS_POINT3 p;
    s32 area;

    o = t->work;
    info = o->ext->info;
    if (lbl_80347450 == 0) {
        return;
    }
    switch (t->state) {
    case 0:
        fn_80227810(o->texlist);
        t->state++;
    case 1:
        dx = lbl_80347450->pos.x - lbl_80347450->home.x;
        dz = lbl_80347450->pos.z - lbl_80347450->home.z;
        dist = fn_80291A5C(dx * dx + dz * dz);
        area = (lbl_80347450->hit->h24 >> 8) & 0x7f;
        if ((((u32)lbl_80347450->hit->h24 >> 8) & 0xff) == 0 || area != info->area) {
            break;
        }
        memcpy(&p, &lbl_80347450->pos, sizeof(NJS_POINT3));
        fn_802254A0(&p, lbl_80347450->hit);
        if (lbl_80347450->pos.y < p.y || lbl_80347450->pos.y > p.y + info->height || !(dist > info->minDist)) {
            break;
        }
        o->x210 = 1;
        if (!(RND() > info->rate)) {
            break;
        }
        sp = fn_80226704(t, fn_8019CB80, 0x5c);
        if (sp == 0) {
            break;
        }
        r1 = info->spread * RND();
        r2 = RND();
        sp->st = &sp->buf;
        sp->st->x4.texlist = o->texlist;
        sp->st->x4.model = fn_801C8930(o->model);
        sp->st->x10 = lbl_80347450->pos.y + info->yOfs;
        sp->st->x18 = 65536.0f * RND();
        sp->st->x1c = 65536.0f * RND();
        sp->st->x20 = 65536.0f * RND();
        sp->st->x24 = info->scale;
        sp->st->x28 = info->scale;
        sp->st->x2c = info->scale;
        sp->st->x50 = info->life;
        sp->st->x48 = info->drag;
        sp->st->x4c = info->gravity;
        sp->st->x3c = info->angVel * RND();
        sp->st->x40 = info->angVel * RND();
        sp->st->x44 = info->angVel * RND();
        if (RND() > 0.5f) {
            sp->st->xc = lbl_80347450->pos.x + dx * r1 + info->side * SIGN(dz);
            sp->st->x14 = lbl_80347450->pos.z + dz * r1 - info->side * SIGN(dx);
            sp->st->x30 = dx + r2 * (dz * info->spin);
            sp->st->x34 = info->rise + dist * info->riseVar * RND();
            sp->st->x38 = dz - r2 * (dx * info->spin);
        } else {
            sp->st->xc = lbl_80347450->pos.x + dx * r1 - info->side * SIGN(dz);
            sp->st->x14 = lbl_80347450->pos.z + dz * r1 + info->side * SIGN(dx);
            sp->st->x30 = dx - r2 * (dz * info->spin);
            sp->st->x34 = info->rise + dist * info->riseVar * RND();
            sp->st->x38 = dz + r2 * (dx * info->spin);
        }
        break;
    case 0xff:
        if (o->texlist != 0) {
            fn_802275A4(o->texlist, 0);
        }
        if (o->x20c != 0) {
            o->x20c = 0;
            fn_80217830(o->x23c);
        }
        fn_80100B74(t);
        return;
    }
    if (info->area == 8) {
        if (o->x210 != 0) {
            o->x210 = 0;
            if (o->x20c == 0) {
                o->x20c = 1;
                o->x23c = SePlay(8, 5, 8);
            }
        } else if (o->x20c != 0) {
            o->x20c = 0;
            fn_80217830(o->x23c);
        }
    }
}

void fn_8019CB80(Obj_8019CB80* o) {
    St* s = o->st;
    if (o->x8->flags & 0x40) {
        o->flags |= 0x40;
        return;
    }
    switch (o->state) {
    case 0:
        s->xc += s->x30;
        s->x10 += s->x34;
        s->x14 += s->x38;
        s->x18 += s->x3c;
        s->x1c += s->x40;
        s->x20 += s->x44;
        s->x34 -= s->x4c;
        s->x30 *= s->x48;
        s->x38 *= s->x48;
        fn_800906E8(&s->x4);
        s->x50--;
        if (s->x50 <= 0) o->state = 0xff;
        break;
    case 0xff:
        o->flags |= 0x40;
        break;
    }
}

void fn_8019D168(Obj_8019D168 *self) {
    extern u8 lbl_802DFEF0[0x2c];
    extern f32 njSin(s32 a);
    extern void fn_80090664(Dat_8019D168 *d);
    Dat_8019D168 *d = self->dat;
    DrawState st;
    if (self->par->flags & 0x40) {
        self->flags |= 0x40;
        return;
    }
    switch (self->state) {
    case 0:
        d->w44 = d->w48;
        self->state = self->state + 1;
    case 1:
        d->f20 = d->f28 = d->f38 * d->f3c;
        if (d->w50 == 0) {
            d->f20 = -d->f20;
        }
        d->f24 = d->f38 * njSin((d->w48 << 14) / d->w44);
        d->f8 = d->f8 + d->f2c;
        d->f10 = d->f10 + d->f34;
        d->w18 = d->w18 + d->w40;
        njMemCopy(&st, lbl_802DFEF0, 10);
        st.colour.a = -(f32)(d->w44 - d->w48) / (f32)d->w44;
        st.attr_or |= 0x100;
        DrawStatePush(&st);
        fn_80090664(d);
        DrawStatePop(0);
        d->sig->ready = 1;
        d->w48 = d->w48 - 1;
        if (d->w48 <= 0) {
            self->state = 0xff;
        }
        break;
    case 0xff:
        self->flags |= 0x40;
        break;
    }
}

void fn_8019D598(Self* o) {
    Sub* p = o->parent;
    Data* d = o->data;
    if (p->flags & 0x40) {
        o->flags |= 0x40;
    } else {
        switch (o->state) {
        case 0:
            d->x7c += 0.05;
            d->x80 += 0.05;
            d->x84 += 0.05;
            fn_8009076C(1, d);
            d->x88--;
            if (d->x88 <= 0) {
                o->state = 0xff;
            }
            break;
        case 0xff:
            o->flags |= 0x40;
            break;
        }
    }
}

void fn_8019D678(Task* t) {
    extern f32 njSin(s32 a);
    extern f32 njCos(s32 a);
    EvObj* o;
    Trail_8019D678* b;
    int i;
    f32 s;
    f32 c;
    f32 dx;
    f32 dz;
    s32 still;

    o = t->work;
    if (lbl_80347450 == 0) {
        return;
    }
    switch (t->state) {
    case 0:
        fn_80227810(o->ext->texlist);
        b = fn_801E1C34(0x62c);
        o->x25c = b;
        b->strip.v = b->v;
        b->strip.idx = b->idx;
        b->strip.uv = b->uv;
        b->strip.n = 48;
        for (i = 0; i < 48; i++) {
            b->strip.v[i].y = 13.0 - 0.1 * i;
            b->strip.idx[i] = -1;
        }
        b->cur = 24;
        t->state++;
    case 1:
        s = lbl_803467E0 * njSin(lbl_80347450->ang[1]);
        c = lbl_803467E0 * njCos(lbl_80347450->ang[1]);
        dx = lbl_80347450->pos.x - lbl_80347450->home.x;
        dz = lbl_80347450->pos.z - lbl_80347450->home.z;
        if (lbl_80347160 > 1.0f) {
            still = 0;
        } else {
            still = 1;
        }
        lbl_80347160 = fn_80291A5C(dx * dx + dz * dz);
        b = o->x25c;
        if (lbl_80347160 > 1.0f) {
            TRAIL_STEP(b);
            if (still) {
                b->w[b->cur] = 0.0f;
                b->w2[b->cur] = 0.0f;
            } else {
                f32 w_ = (lbl_80347160 - 1.0f) * lbl_803467E4;
                b->w[b->cur] = w_;
                b->w2[b->cur] = w_;
            }
            TRAIL_POS(b);
        } else if (!still) {
            TRAIL_STEP(b);
            b->w[b->cur] = 0.0f;
            b->w2[b->cur] = 0.0f;
            TRAIL_POS(b);
        }
        fn_80296E4C(0);
        fn_80296DC8(0);
        fn_80299040(o->ext->texlist);
        fn_80298FE4(0);
        fn_8019DBA8(&b->strip, &b->x[b->cur], &b->z[b->cur], &b->w[b->cur]);
        break;
    case 0xff:
        if (o->ext->texlist != 0) {
            fn_802275A4(o->ext->texlist, 0);
        }
        fn_801E1784(o->x25c);
        fn_80100B74(t);
        break;
    }
}

void SaveLoadTask(Task *task) {
    if (lbl_803475D8 != 0) {
        task->state = 0x1F;
    }
    lbl_802EBD30[task->state](task);
}

void fn_8019E294(Self_8019E294 *o) {
    fn_801A473C();
    fn_801A69BC();
    if (o->ctx->b1 == 1) {
        if (o->ctx->b0 == 0) {
            fn_80226DC4();
        }
        {
            u8 ba = o->ctx->ba;
            if (ba == 1) {
                lbl_803473C4 = ba;
                lbl_80310B3C[0x21] &= 0x7fffffff;
            } else {
                lbl_803473C4 = 2;
            }
        }
    } else {
        fn_801A6824(o);
        lbl_803473C4 = 1;
        Ui2DEnd();
    }
    o->flags18 |= 0x40;
}

void fn_8019E33C(Task *t) {
    if (lbl_80347508 == 0) {
        u8 *p = *(u8 **)((u8 *)t->work + 0x208);
        if (p != 0) {
            p[0x18] |= 0x40;
            *(void **)((u8 *)t->work + 0x208) = 0;
        }
        fn_801A65D4(t);
        t->state = 0x20;
    }
}

void fn_8019E3A8(Task *t)
{
    fn_801CBBAC(8.0f);
    t->state = 0x1F;
}

void fn_8019E3E0(Task *t) {
    if (fn_801A6554(t) == 0) {
        t->state = 0x1E;
    } else if (lbl_80311A60[0]->held & 0x200) {
        fn_801A64E0(t);
        t->state = 0x1E;
    }
}

void SaveLoadSlideAllOut(Self_801A0C3C *o) {
    if (fn_801A6554(o) != 0) return;
    UiObjMoveTo(&o->ctx->objs[0]->obj->o, 6, 5, 640.0f, 480.0f);
    UiObjSetCommand(&o->ctx->objs[0]->obj->o, 0xf, 0);
    SlideAll_801A038C(o);
    if (UiObjMoveToXIfChanged(&o->ctx->objs[2]->obj->o, 6, 5, -340.0f) != 0) {
        UiObjSetCommand(&o->ctx->objs[2]->obj->o, 0xf, 4);
    }
    if (UiObjMoveToXIfChanged(&o->ctx->objs[3]->obj->o, 6, 5, -340.0f) != 0) {
        UiObjSetCommand(&o->ctx->objs[3]->obj->o, 0xf, 2);
    }
    UiObjMoveToX(&o->ctx->objs[4]->obj->o, 6, -1, -340.0f);
    UiObjSetCommand(&o->ctx->objs[4]->obj->o, 0xf, 0);
    o->state = 0x1d;
}

void fn_8019E5F0(Task *t) {
    fn_801A66AC(*(void **)((u8 *)t->work + 0x20C));
    if (lbl_80311A60[0]->held & 0x300) {
        fn_801A4DCC(t, 1);
        t->state = 0xC;
    }
}

void fn_8019E650(Self_8019E650 *o) {
    s32 x;

    if (fn_801A2670(o->ctx->b4, &x) != 0) {
        if (x == 0) {
            fn_801A4DCC(o, 1);
            fn_801A64B4(o, 0x17);
            MenuPlaySe(0x15);
        } else {
            s32 k;
            if (x == -3) {
                k = 0x18;
            } else {
                k = (u8)(o->ctx->b4 + 0x19);
            }
            fn_801A64B4(o, k);
            MenuPlaySe(3);
        }
        o->state19 = 0x1b;
    }
}

void fn_8019E96C(Self_8019E96C *self) {
    s32 r = fn_801A28AC(self->ctx->b4);
    if (r == 1) {
        self->ctx->w25c[self->ctx->b4] = r;
        UiObjMoveToX(&self->ctx->p220->ui->o, 6, 5, -240.0f);
        UiObjSetCommand(&self->ctx->p220->ui->o, 0x1a, 2);
        UiObjMoveToX(&self->ctx->p224->ui->o, 6, 5, -240.0f);
        UiObjSetCommand(&self->ctx->p224->ui->o, 0x1a, 0);
        MenuPlaySe(3);
        fn_801A64B4(self, 4);
        self->state19 = 0x17;
    } else if (fn_801A6554(self) == 0 || (lbl_80311A60[0]->held & 0x100) != 0) {
        u32 cmd;
        fn_801A64E0(self);
        cmd = 0x14;
        if (self->ctx->b8 == 0) {
            cmd = 0x15;
        }
        UiObjSetCommand(&self->ctx->p220->ui->o, cmd, 0);
        cmd = 0x14;
        if (self->ctx->b8 == 1) {
            cmd = 0x15;
        }
        UiObjSetCommand(&self->ctx->p224->ui->o, cmd, 0);
        self->state19 = 0x19;
    }
}

void fn_8019EAD4(Self_801A0C3C *o) {
    u32 held;
    s32 r;
    if (fn_801A6554(o) != 0) return;
    if (o->ctx->slot[o->ctx->idx] != 1 && (r = fn_801A28AC(o->ctx->idx)) == 1) {
        o->ctx->slot[o->ctx->idx] = r;
        MenuPlaySe(3);
        fn_801A64B4(o, 4);
    }
    fn_801A66AC(o->ctx->objs[0]);
    held = lbl_80311A60[0]->held;
    if (held & 0x300) {
        SlideAll_801A038C(o);
        fn_801A4DCC(o, 1);
        UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        if (o->ctx->slot[o->ctx->idx] == 2) {
            MenuPlaySe(2);
            SlideBut_801A038C(o);
            o->ctx->x8 = 0;
            if (o->ctx->objs[5] == 0) o->ctx->objs[5] = fn_801A5BE8(o, 0);
            if (o->ctx->objs[6] == 0) o->ctx->objs[6] = fn_801A5BE8(o, 1);
            UiObjMoveToX(&o->ctx->objs[5]->obj->o, 6, 4, -8.0f);
            UiObjSetCommand(&o->ctx->objs[5]->obj->o, 0xf, 0);
            UiObjMoveToX(&o->ctx->objs[6]->obj->o, 6, 4, -8.0f);
            UiObjSetCommand(&o->ctx->objs[6]->obj->o, 0xf, 2);
            o->ctx->x8 = 1;
            fn_801A64B4(o, 0x32);
            o->state = 0x18;
        } else {
            o->state = 0xc;
        }
    } else if (held & 0x400) {
        o->state = 0x1e;
    }
}

void fn_8019EDEC(Task *t) {
    if (fn_801A6554(t) == 0 || (lbl_80311A60[0]->held & 0x200)) {
        fn_801A64B4(t, 5);
        t->state = 0x8;
    }
}

void fn_8019EE4C(Self_8019EE4C *self) {
    extern void fn_801A64B4(void *o, u8 k);
    extern void fn_801A1B98(void *o, s32 k);
    extern u32 fn_801A6A58(int sub, int idx);
    s32 k;
    if (fn_801A6554(self) != 0) {
        return;
    }
    if (self->ctx->wc != 0) {
        self->ctx->wc--;
    }
    if (self->ctx->wc == 0 || (lbl_80311A60[0]->held & 0x300) != 0) {
        fn_801A1B98(self, 1);
        fn_801A4DCC(self, 1);
        UiObjMoveToXIfChanged(&self->ctx->p210->ui->o, 6, 4, -330.0f);
        UiObjSetCommand(&self->ctx->p210->ui->o, 0xf, 0);
        self->state19 = 0x16;
    } else if ((lbl_80311A60[0]->held & 0x400) != 0) {
        self->state19 = 0x1e;
    }
    self->ctx->w25c[self->ctx->b4] = fn_801A28AC(self->ctx->b4);
    if (self->ctx->w25c[self->ctx->b4] != 0) {
        self->ctx->b9 = 0;
        if (1.0f != self->ctx->f18) {
            fn_801A4DCC(self, 1);
        }
        UiObjMoveToXIfChanged(&self->ctx->p210->ui->o, 6, 4, -330.0f);
        UiObjSetCommand(&self->ctx->p210->ui->o, 0xf, 0);
        k = fn_801A6A58(self->ctx->b4, self->ctx->w25c[self->ctx->b4]);
        fn_801A64B4(self, k);
        MenuPlaySe(3);
        self->state19 = 0xb;
    }
}

void fn_8019EFF8(SaveTask* t) {
    s32 r;
    if (fn_801A3B30(t, &r) == 0) return;
    if (r == 0) {
        MemCopy(&t->w->ent[t->w->f7], (u8*)t->w + 0x1d8, 0x2c);
        t->w->ent[t->w->f7].f0 = 1;
        t->w->f9 = 0;
        fn_801A41C0(t->w->f258);
        t->w->f258 = NULL;
        fn_801A64B4(t, 10);
        MenuPlaySe(0xd);
        UiObjMoveToXIfChanged(&t->w->p[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&t->w->p[1]->obj->o, 0xf, 0);
        fn_801A4DCC(t, 1);
        UiObjMoveToX(&t->w->p[5]->obj->o, 6, 5, -240.0f);
        UiObjSetCommand(&t->w->p[5]->obj->o, 0x1a, 2);
        UiObjMoveToX(&t->w->p[6]->obj->o, 6, 5, -240.0f);
        UiObjSetCommand(&t->w->p[6]->obj->o, 0x1a, 0);
        lbl_803475D0 = 0;
        lbl_803475E0 = 0;
        t->w->fc = 10;
        t->state = 0x15;
    } else if (r != -1) {
        t->w->ent[t->w->f7].f0 = 2;
        t->w->f9 = 0;
        fn_801A41C0(t->w->f258);
        t->w->f258 = NULL;
        fn_801A64B4(t, 9);
        MenuPlaySe(3);
        UiObjMoveToXIfChanged(&t->w->p[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&t->w->p[1]->obj->o, 0xf, 0);
        UiObjMoveToX(&t->w->p[5]->obj->o, 6, 5, -240.0f);
        UiObjSetCommand(&t->w->p[5]->obj->o, 0x1a, 2);
        UiObjMoveToX(&t->w->p[6]->obj->o, 6, 5, -240.0f);
        UiObjSetCommand(&t->w->p[6]->obj->o, 0x1a, 0);
        fn_801A4DCC(t, 1);
        lbl_803475D0 = 0;
        lbl_803475E0 = 0;
        t->state = 0x17;
    }
}

void fn_8019F28C(Self_801A0C3C *o) {
    if (fn_801A6554(o) != 0) return;
    if (o->ctx->xc != 0) o->ctx->xc--;
    if (o->ctx->xc != 0 && (lbl_80311A60[0]->held & 0x300) == 0) return;
    o->ctx->xc = 0;
    fn_801A4DCC(o, 1);
    UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
    UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
    SlideBut_801A038C(o);
    UiObjMoveToX(&o->ctx->objs[3]->obj->o, 6, 5, -340.0f);
    UiObjSetCommand(&o->ctx->objs[3]->obj->o, 0xf, 2);
    UiObjMoveToX(&o->ctx->objs[4]->obj->o, 6, -1, -340.0f);
    UiObjSetCommand(&o->ctx->objs[4]->obj->o, 0xf, 0);
    o->state = 0x1c;
}

void fn_8019F44C(SaveTask* t) {
    s32 a = 0;
    s32 b = 0;
    s32 r;
    CardSaveData* p;
    u32 sum;
    r = fn_801A3A10(t->w->sel, t);
    fn_801A2D20(t, lbl_803081CC[t->w->sel].done, lbl_803081CC[t->w->sel].total);
    if (r == 0) {
        p = &t->w->f258->buf->save;
        sum = fn_801A4684(p, 0x31fc);
        if (sum != p->sum) {
            a = 1;
            b = 1;
            t->w->st[t->w->sel] = 3;
        } else {
            fn_801A4354(p);
            t->w->fa = 1;
            t->w->fc = 10;
            fn_801A64B4(t, 0x10);
            MenuPlaySe(0xd);
            UiObjMoveToX(&t->w->p[5]->obj->o, 6, 5, -240.0f);
            UiObjSetCommand(&t->w->p[5]->obj->o, 0x1a, 2);
            UiObjMoveToX(&t->w->p[6]->obj->o, 6, 5, -240.0f);
            UiObjSetCommand(&t->w->p[6]->obj->o, 0x1a, 0);
            fn_801A41C0(t->w->f258);
            t->w->f258 = NULL;
            t->state = 0x13;
        }
    } else if (r != -1) {
        a = 1;
        b = 0;
        t->w->st[t->w->sel] = fn_801A6A04(r);
    }
    if (a != 0) {
        if (b != 0) t->w->ent[t->w->f7].f0 = 2;
        t->w->f9 = 0;
        fn_801A41C0(t->w->f258);
        t->w->f258 = NULL;
        fn_801A64B4(t, 0x28);
        MenuPlaySe(3);
        UiObjMoveToXIfChanged(&t->w->p[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&t->w->p[1]->obj->o, 0xf, 0);
        UiObjMoveToX(&t->w->p[5]->obj->o, 6, 5, -240.0f);
        UiObjSetCommand(&t->w->p[5]->obj->o, 0x1a, 2);
        UiObjMoveToX(&t->w->p[6]->obj->o, 6, 5, -240.0f);
        UiObjSetCommand(&t->w->p[6]->obj->o, 0x1a, 0);
        fn_801A4DCC(t, 1);
        lbl_803475D0 = 0;
        lbl_803475E0 = 0;
        t->state = 0x17;
    }
}

void fn_8019F730(SaveTask *self) {
    if (fn_801A6554(self) != 0) {
        return;
    }
    if (self->w->f1 == 1) {
        if (fn_801A4070(self) == 0) {
            self->w->f9 = 0;
            fn_801A41C0(self->w->f258);
            self->w->f258 = 0;
            fn_801A64B4(self, 0x28);
            MenuPlaySe(3);
            UiObjMoveToXIfChanged(&self->w->p[1]->obj->o, 6, 4, -330.0f);
            UiObjSetCommand(&self->w->p[1]->obj->o, 0xf, 0);
            UiObjMoveToX(&self->w->p[5]->obj->o, 6, 5, -240.0f);
            UiObjSetCommand(&self->w->p[5]->obj->o, 0x1a, 2);
            UiObjMoveToX(&self->w->p[6]->obj->o, 6, 5, -240.0f);
            UiObjSetCommand(&self->w->p[6]->obj->o, 0x1a, 0);
            fn_801A4DCC(self, 1);
            lbl_803475D0 = 0;
            lbl_803475E0 = 0;
            self->state = 0x17;
        } else {
            self->state = 0x12;
        }
    } else {
        fn_801A4060(self);
        self->state = 0x14;
    }
}

void fn_8019F898(SaveTask *t) {
    u8 k;
    if (fn_801A6554(t) == 0 || (lbl_80311A60[0]->held & 0x200)) {
        fn_801A64E0(t);
        fn_801A6650(t, 5);
        fn_801A6650(t, 6);
        k = t->w->f1 == 1 ? 0xc : 5;
        fn_801A64B4(t, k);
        t->state = 8;
    }
}

void fn_8019FDB0(Self_8019FDB0 *o) {
    if (fn_801A6554(o) == 0 || (lbl_80311A60[0]->held & 0x100)) {
        s32 cmd;
        fn_801A64E0(o);
        cmd = 0x14;
        if (o->ctx->b8 == 0) {
            cmd = 0x15;
        }
        UiObjSetCommand(&o->ctx->p220->ui->o, (u16)cmd, 0);
        cmd = 0x14;
        if (o->ctx->b8 == 1) {
            cmd = 0x15;
        }
        UiObjSetCommand(&o->ctx->p224->ui->o, (u16)cmd, 0);
        o->state19 = 0xf;
    }
}

void fn_8019FE64(Self_8019FE64 *o) {
    s32 doit = 0;
    s32 i;

    if (fn_801A6554(o) == 0) {
        doit = 1;
    } else if (lbl_80311A60[0]->held & 0x100) {
        fn_801A64E0(o);
        doit = 1;
    }
    if (doit) {
        if (o->ctx->p220 != 0) {
            fn_801A6650((void *)o, 5);
            fn_801A6650((void *)o, 6);
        }
        if (o->ctx->p228 != 0) {
            for (i = 0; i < 7; i++) {
                fn_801A6650((void *)o, (u16)(i + 7));
            }
        }
        o->state19 = 4;
    }
}

void fn_8019FF38(Self_8019FF38 *o) {
    if (o->ctx->b4 >= 2) {
        return;
    }
    if (o->ctx->b4 == 0) {
        UiObjMoveToX(&o->ctx->p21c->ui->o, 6, 5, -8.0f);
        UiObjSetCommand(&o->ctx->p21c->ui->o, 0xf, 0);
    } else {
        UiObjMoveToX(&o->ctx->p218->ui->o, 6, 5, -8.0f);
        UiObjSetCommand(&o->ctx->p218->ui->o, 0xf, 3);
        UiObjMoveToY(&o->ctx->p21c->ui->o, 3, -1, 164.0f);
        UiObjSetCommand(&o->ctx->p21c->ui->o, 0xf, 0);
    }
    o->state19 = 0xd;
}

void fn_801A0018(Self_801A0C3C *o) {
    s32 v;
    fn_801A66AC(o->ctx->objs[0]);
    if (o->ctx->slot[o->ctx->idx] != 1 && (v = fn_801A28AC(o->ctx->idx)) == 1) {
        o->ctx->slot[o->ctx->idx] = v;
        MenuPlaySe(3);
        fn_801A64B4(o, 4);
        o->ctx->x26c = 0;
    }
    if (lbl_80311A60[0]->held & 0x100) {
        if (o->ctx->x26c != 0) {
            fn_801A64B4(o, o->ctx->x26c);
            o->ctx->x26c = 0;
        } else {
            if (1.0f != o->ctx->x18) fn_801A4DCC(o, 1);
            if (o->ctx->objs[5] != 0) {
                UiObjMoveToX(&o->ctx->objs[5]->obj->o, 6, 5, -240.0f);
                UiObjSetCommand(&o->ctx->objs[5]->obj->o, 0x1a, 2);
                UiObjMoveToX(&o->ctx->objs[6]->obj->o, 6, 5, -240.0f);
                UiObjSetCommand(&o->ctx->objs[6]->obj->o, 0x1a, 0);
            }
            if (o->ctx->objs[7] != 0) {
                SlideAll_801A038C(o);
            }
            o->state = 0xc;
        }
    }
}

void fn_801A0214(Self_801A0214 *self) {
    extern void fn_801A64B4(void *o, u8 k);
    extern u32 fn_801A6A58(int sub, int idx);
    extern s32 fn_801C09F8(s32 a, s32 b);
    s32 i;
    s32 k;
    if (fn_801A6554(self) == 0 || fn_801C09F8(0, 4) != 0 || fn_801C09F8(0, 5) != 0) {
        for (i = 0; i < 7; i++) {
            s32 j = i + 7;
            Holder_8019FDB0 *h = self->ctx->h[j];
            if (h != 0 && h->ui != 0) {
                UiObjFinish(&h->ui->o);
            }
        }
        self->state19 = 9;
        self->ctx->w25c[self->ctx->b4] = fn_801A28AC(self->ctx->b4);
        if (self->ctx->w25c[self->ctx->b4] != 0) {
            self->ctx->b9 = 0;
            if (1.0f != self->ctx->f18) {
                fn_801A4DCC(self, 1);
            }
            UiObjMoveToXIfChanged(&self->ctx->h[1]->ui->o, 6, 4, -330.0f);
            UiObjSetCommand(&self->ctx->h[1]->ui->o, 0xf, 0);
            k = fn_801A6A58(self->ctx->b4, self->ctx->w25c[self->ctx->b4]);
            fn_801A64B4(self, k);
            MenuPlaySe(3);
            self->state19 = 0xb;
        }
    }
}

void fn_801A038C(Self_801A0C3C *o)
{
    s32 r;
    s32 k;
    const Ent_801A1B98 *e;
    u32 held;

    o->ctx->slot[o->ctx->idx] = fn_801A28AC(o->ctx->idx);
    if (o->ctx->slot[o->ctx->idx] != 0) {
        o->ctx->x9 = 0;
        if (1.0f != o->ctx->x18) {
            fn_801A4DCC(o, 1);
        }
        UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        k = fn_801A6A58(o->ctx->idx, o->ctx->slot[o->ctx->idx]);
        fn_801A64B4(o, (u8)k);
        MenuPlaySe(3);
        o->state = 0xb;
        r = 0;
    } else {
        r = 1;
    }
    if (r == 0) {
        return;
    }
    fn_801A1FBC(o);
    held = lbl_80311A60[0]->held;
    if (held & 0x200) {
        FinishList_801A038C(o);
        SlideAll_801A038C(o);
        o->state = 0xc;
    } else if (held & 0x100) {
        FinishList_801A038C(o);
        if (o->ctx->x1 == 1) {
            if (o->ctx->items[o->ctx->x7].kind == 1) {
                SlideBut_801A038C(o);
                MenuPlaySe(2);
                fn_801A64B4(o, 0xe);
                o->ctx->x8 = 0;
                if (o->ctx->objs[5] == 0) {
                    o->ctx->objs[5] = fn_801A5BE8(o, 0);
                }
                if (o->ctx->objs[6] == 0) {
                    o->ctx->objs[6] = fn_801A5BE8(o, 1);
                }
                UiObjMoveToX(&o->ctx->objs[5]->obj->o, 6, 4, -8.0f);
                UiObjSetCommand(&o->ctx->objs[5]->obj->o, 0xf, 0);
                UiObjMoveToX(&o->ctx->objs[6]->obj->o, 6, 4, -8.0f);
                UiObjSetCommand(&o->ctx->objs[6]->obj->o, 0xf, 2);
                o->state = 0xe;
            } else {
                MenuPlaySe(3);
            }
        } else {
            fn_800073C0(&lbl_80308198);
            o->ctx->stamp.year = lbl_80308198.stamp.year;
            o->ctx->stamp.month = lbl_80308198.stamp.month;
            o->ctx->stamp.day = lbl_80308198.stamp.day;
            o->ctx->stamp.hour = lbl_80308198.stamp.hour;
            o->ctx->stamp.min = lbl_80308198.stamp.min;
            o->ctx->stamp.sec = lbl_80308198.stamp.sec;
            o->ctx->stamp.wday = lbl_80308198.stamp.wday;
            o->data->x31ec = o->ctx->x1e0 = fn_80228928();
            switch (o->ctx->items[o->ctx->x7].kind) {
            case 0:
                SlideBut_801A038C(o);
                o->ctx->x8 = 0;
                if (o->ctx->objs[5] == 0) {
                    o->ctx->objs[5] = fn_801A5BE8(o, 0);
                }
                if (o->ctx->objs[6] == 0) {
                    o->ctx->objs[6] = fn_801A5BE8(o, 1);
                }
                UiObjMoveToX(&o->ctx->objs[5]->obj->o, 6, 4, -8.0f);
                UiObjSetCommand(&o->ctx->objs[5]->obj->o, 0xf, 0);
                UiObjMoveToX(&o->ctx->objs[6]->obj->o, 6, 4, -8.0f);
                UiObjSetCommand(&o->ctx->objs[6]->obj->o, 0xf, 2);
                o->ctx->x9 = 1;
                fn_801A64B4(o, 6);
                MenuPlaySe(2);
                o->state = 0xe;
                break;
            case 1:
            case 2:
            case 4:
                SlideBut_801A038C(o);
                o->ctx->x8 = 0;
                if (o->ctx->objs[5] == 0) {
                    o->ctx->objs[5] = fn_801A5BE8(o, 0);
                }
                if (o->ctx->objs[6] == 0) {
                    o->ctx->objs[6] = fn_801A5BE8(o, 1);
                }
                UiObjMoveToX(&o->ctx->objs[5]->obj->o, 6, 4, -8.0f);
                UiObjSetCommand(&o->ctx->objs[5]->obj->o, 0xf, 0);
                UiObjMoveToX(&o->ctx->objs[6]->obj->o, 6, 4, -8.0f);
                UiObjSetCommand(&o->ctx->objs[6]->obj->o, 0xf, 2);
                o->ctx->x9 = 2;
                fn_801A64B4(o, 7);
                MenuPlaySe(2);
                o->state = 0xe;
                break;
            case 3:
                MenuPlaySe(3);
                break;
            }
        }
    } else if (held & 0x400) {
        o->state = 0x1e;
    } else {
        fn_801A1958(o, 10);
    }
}

void fn_801A0B18(Self_801A0B18* o) {
    s32 r;
    s32 k;
    o->ctx->slot[o->ctx->idx] = fn_801A28AC(o->ctx->idx);
    if (o->ctx->slot[o->ctx->idx] != 0) {
        o->ctx->x9 = 0;
        if (1.0f != o->ctx->x18) {
            fn_801A4DCC(o, 1);
        }
        UiObjMoveToXIfChanged(&o->ctx->x210->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->x210->obj->o, 0xf, 0);
        k = fn_801A6A58(o->ctx->idx, o->ctx->slot[o->ctx->idx]);
        fn_801A64B4(o, (u8)k);
        MenuPlaySe(3);
        o->state = 0xb;
        r = 0;
    } else {
        r = 1;
    }
    if (r != 0 && fn_801A6554(o) == 0) {
        o->state = 9;
    }
}

void fn_801A0C3C(Self_801A0C3C *o) {
    extern void fn_801A1DB4(void);
    s32 k;
    if (o->ctx->x250 == 0) return;
    if (o->ctx->slot[o->ctx->idx] != 0) {
        MenuPlaySe(3);
        UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        fn_801A4DCC(o, 1);
        k = fn_801A6A58(o->ctx->idx, o->ctx->slot[o->ctx->idx]);
        fn_801A64B4(o, k);
        o->state = 0x17;
    } else if (o->ctx->x1 == 1) {
        fn_801A1DB4();
        fn_801A1B98(o, 0);
        fn_801A4DCC(o, 1);
        UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        o->ctx->x9 = 0;
        o->state = 8;
    } else if (o->ctx->x14 != 0) {
        fn_801A64B4(o, 5);
        fn_801A1B98(o, 0);
        o->ctx->x9 = 0;
        fn_801A4DCC(o, 1);
        UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        o->state = 8;
    } else {
        o->ctx->slot[o->ctx->idx] = 6;
        fn_801A64B4(o, fn_801A6A58(o->ctx->idx, o->ctx->slot[o->ctx->idx]));
        o->ctx->x26c = 3;
        MenuPlaySe(3);
        fn_801A4DCC(o, 1);
        UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        o->state = 0xb;
    }
}

void fn_801A0E7C(Self_801A0E7C *self) {
    if (SelectSlot(self) != 0 && fn_801A6554(self) == 0) {
        fn_801A64B4(self, 0x11);
        self->ctx->b7 = 0;
        self->ctx->b5 = 0;
        self->ctx->b6 = 0;
        *(void **)((u8 *)self->ctx + 0x24c) = fn_801A343C((Task_801A343C *)self);
        self->state19 = 7;
    }
}

void fn_801A0FD8(Self_801A0FD8 *o) {
    s32 r;
    s32 k;
    o->ctx->slot[o->ctx->idx] = fn_801A28AC(o->ctx->idx);
    if (o->ctx->slot[o->ctx->idx] != 0) {
        o->ctx->x9 = 0;
        if (1.0f != o->ctx->x18) fn_801A4DCC(o, 1);
        UiObjMoveToXIfChanged(&o->ctx->objs[1]->obj->o, 6, 4, -330.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        k = fn_801A6A58(o->ctx->idx, o->ctx->slot[o->ctx->idx]);
        fn_801A64B4(o, (u8)k);
        MenuPlaySe(3);
        o->state = 0xb;
        r = 0;
    } else {
        r = 1;
    }
    if (r != 0 && fn_801A6554(o) == 0 && o->ctx->idx < 2) {
        if (o->ctx->idx == 1) {
            UiObjMoveToY(&o->ctx->objs[4]->obj->o, 3, 4, 100.0f);
            UiObjSetCommand(&o->ctx->objs[4]->obj->o, 0xf, 0);
        }
        o->ctx->objs[1]->x19 = 1;
        ((u16 *)o->ctx->objs[1]->obj)[0x54 / 2] = 1;
        o->ctx->x1c = 0.0f;
        UiObjMoveToX(&o->ctx->objs[1]->obj->o, 6, 4, 160.0f);
        UiObjSetCommand(&o->ctx->objs[1]->obj->o, 0xf, 0);
        fn_801A4DCC(o, 0);
        o->state = 6;
    }
}

void fn_801A11B0(SaveTask* t) {
    u32 bits;
    u8 v;
    s32 arg;
    if (t->w->f18 != 1.0f) fn_801A4DCC((void *)(t), 1);
    if (fn_801A6554((void *)(t)) != 0) return;
    if (lbl_803081CC[0].busy == 0 && lbl_803081CC[1].busy == 0) {
        t->w->st[0] = fn_801A28AC(0);
        t->w->st[1] = fn_801A28AC(1);
        t->w->f3 = t->w->cnt;
        t->w->cnt = 0;
        if (t->w->st[0] != 1) t->w->cnt++;
        if (t->w->st[1] != 1) t->w->cnt++;
    }
    if (fn_801C09F8(0, 4) != 0 || fn_801C09F8(0, 5) != 0) {
        if (t->w->cnt == 2) {
            MenuPlaySe(4);
            t->w->sel++;
            t->w->sel &= 1;
        }
    } else {
        bits = lbl_80311A60[0]->held;
        if (bits & 0x100) {
            if (t->w->cnt == 0) {
                MenuPlaySe(3);
            } else if (t->w->sel != 2) {
                MenuPlaySe(2);
                if (t->w->sel == 0) {
                    UiObjSetCommand(&t->w->p[3]->obj->o, 0x14, 0);
                    UiObjMoveToX(&t->w->p[4]->obj->o, 6, 5, -340.0f);
                    UiObjSetCommand(&t->w->p[4]->obj->o, 0xf, 0);
                } else {
                    UiObjMoveToX(&t->w->p[3]->obj->o, 6, 5, -340.0f);
                    UiObjSetCommand(&t->w->p[3]->obj->o, 0xf, 0);
                    UiObjSetCommand(&t->w->p[4]->obj->o, 0x14, 0);
                }
                fn_801A64B4((void *)(t), 0x11);
                t->state = 5;
            } else {
                goto cancel;
            }
        } else if (bits & 0x200) {
        cancel:
            UiObjSetCommand(&t->w->p[3]->obj->o, 0x14, 0);
            UiObjSetCommand(&t->w->p[4]->obj->o, 0x14, 0);
            t->state = 0x1c;
        } else if (bits & 0x400) {
            t->state = 0x1e;
        } else {
            fn_801A20AC(t);
            if (t->w->cnt != 0) {
                v = 0xb;
                if (t->w->f1 == 0) v = 1;
                arg = v;
            } else {
                arg = 4;
            }
            fn_801A64B4((void *)(t), arg);
        }
    }
}

void fn_801A1494(Self_801A1494* o) {
    u32 f;
    s32 k;
    if (fn_801A6554(o) == 0 || ((f = lbl_80311A60[0]->held) & 0x100)) {
        fn_801A64E0(o);
        o->state = 4;
    } else if (f & 0x400) {
        o->state = 0x1e;
    }
    if (lbl_803081CC[0].busy == 0 && lbl_803081CC[1].busy == 0) {
        o->ctx->slot[0] = fn_801A28AC(0);
        o->ctx->slot[1] = fn_801A28AC(1);
        o->ctx->x3 = o->ctx->x2;
        o->ctx->x2 = 0;
        if (o->ctx->slot[0] != 1) o->ctx->x2++;
        if (o->ctx->slot[1] != 1) o->ctx->x2++;
    }
    if (o->ctx->x2 != 0) {
        k = (o->ctx->x1 == 0) ? 1 : 0xb;
    } else {
        k = 4;
    }
    fn_801A64B4(o, k);
}

void SaveLoadCreateParts(Self_801A0C3C *o) {
    s32 k;
    if (lbl_80347508 != 0) return;
    o->ctx->objs[0] = fn_801A51A8(o);
    UiObjMoveTo(&o->ctx->objs[0]->obj->o, 6, 4, 24.0f, 384.0f);
    UiObjSetCommand(&o->ctx->objs[0]->obj->o, 0xf, 0);
    o->ctx->objs[2] = fn_801A6244(o, o->ctx->x1 == 1);
    UiObjMoveToX(&o->ctx->objs[2]->obj->o, 6, -1, -8.0f);
    UiObjSetCommand(&o->ctx->objs[2]->obj->o, 0xf, 0);
    o->ctx->objs[3] = fn_801A5EB4(o, 0);
    UiObjMoveToX(&o->ctx->objs[3]->obj->o, 6, 4, -8.0f);
    UiObjSetCommand(&o->ctx->objs[3]->obj->o, 0xf, 2);
    o->ctx->objs[4] = fn_801A5EB4(o, 1);
    UiObjMoveToX(&o->ctx->objs[4]->obj->o, 6, 4, -8.0f);
    UiObjSetCommand(&o->ctx->objs[4]->obj->o, 0xf, 4);
    o->ctx->objs[1] = SaveLoadCursorCreate(o);
    if (lbl_803081CC[0].busy == 0 && lbl_803081CC[1].busy == 0) {
        o->ctx->slot[0] = fn_801A28AC(0);
        o->ctx->slot[1] = fn_801A28AC(1);
        o->ctx->x3 = o->ctx->x2;
        o->ctx->x2 = 0;
        if (o->ctx->slot[0] != 1) o->ctx->x2++;
        if (o->ctx->slot[1] != 1) o->ctx->x2++;
    }
    k = (o->ctx->x1 == 0) ? 1 : 0xb;
    if (o->ctx->slot[0] == 0) {
        o->ctx->idx = 0;
    } else if (o->ctx->slot[1] == 0) {
        o->ctx->idx = 1;
    } else {
        o->ctx->idx = 2;
        k = 4;
    }
    fn_801A64B4(o, k);
    o->state = 3;
}

void fn_801A1834(Self_801A1834 *o) {
    if (o->ctx->b1 == 1 && lbl_80347508 != 0) {
        return;
    }
    fn_801A47D8();
    if (o->ctx->b1 == 1 && o->ctx->b0 == 0) {
        fn_80227068(0);
    }
    fn_801A69DC();
    if (o->ctx->b1 == 0) {
        if (o->ctx->h10 >= 0x3c) {
            fn_801A686C(o);
        }
        fn_801A68C4(o);
    }
    o->ctx->p208 = fn_801A4AF4(o);
    fn_801C09A4();
    fn_801CBC30();
    fn_801CBBD8();
    fn_801CBB9C(8.0f);
    o->state19 = 2;
}

void fn_801A18FC(Task *t) {
    if (((u8 *)t->work)[0x1] == 1) {
        fn_801CBBAC(8.0f);
    } else {
        Ui2DBegin();
        ((u8 *)t->work)[0x2] = 0xFF;
    }
    t->state = 0x1;
}

void fn_801A1958(Self_801A0C3C *o, s32 st) {
    s32 v;
    if (fn_801C09F8(0, 4) != 0) {
        if (o->ctx->x5 == 0) {
            if (o->ctx->x6 != 0) {
                ScrollUp(o, st);
            }
        } else {
            MenuPlaySe(4);
            o->ctx->x5--;
        }
    } else if (fn_801C09F8(0, 5) != 0) {
        if (o->ctx->x5 == 2) {
            if (o->ctx->x6 != 4) {
                ScrollDown(o, st);
            }
        } else {
            MenuPlaySe(4);
            o->ctx->x5++;
        }
    }
    o->ctx->x7 = o->ctx->x5 + o->ctx->x6;
    if (o->ctx->x1 == 1) {
        switch (o->ctx->items[o->ctx->x7].kind) {
        case 2:
        case 4: v = 0xd; break;
        case 3:
        default: v = 0xc; break;
        }
    } else {
        v = 5;
    }
    fn_801A64B4(o, v);
}

void fn_801A1B98(Self_801A0C3C *o, u8 mode) {
    s32 i;
    s32 k = 4 - o->ctx->x6;
    const f32 *tb;
    if (mode == 0) {
        tb = &lbl_802B4920[k];
        for (i = 0; i < 7; i++) {
            if (o->ctx->objs[lbl_802B494C[i].idx] == 0) {
                f32 f;
                o->ctx->objs[lbl_802B494C[i].idx] = fn_801A53D4(o, lbl_802B494C[i].b1);
                f = tb[i];
                o->ctx->objs[lbl_802B494C[i].idx]->obj->o.ty = f;
                o->ctx->objs[lbl_802B494C[i].idx]->obj->o.y = f;
            }
            UiObjMoveToX(&o->ctx->objs[lbl_802B494C[i].idx]->obj->o, 6, 4, 336.0f);
            UiObjSetCommand(&o->ctx->objs[lbl_802B494C[i].idx]->obj->o, 0xf, lbl_802B494C[i].b2);
        }
    } else {
        tb = &lbl_802B4920[k];
        for (i = 0; i < 7; i++) {
            if (i != o->ctx->x7) {
                if (o->ctx->objs[lbl_802B494C[i].idx] == 0) {
                    f32 f;
                    o->ctx->objs[lbl_802B494C[i].idx] = fn_801A53D4(o, lbl_802B494C[i].b1);
                    f = tb[i];
                    o->ctx->objs[lbl_802B494C[i].idx]->obj->o.ty = f;
                    o->ctx->objs[lbl_802B494C[i].idx]->obj->o.y = f;
                }
                UiObjMoveToX(&o->ctx->objs[lbl_802B494C[i].idx]->obj->o, 6, 4, 336.0f);
                UiObjSetCommand(&o->ctx->objs[lbl_802B494C[i].idx]->obj->o, 0xf, lbl_802B494C[i].b4);
            }
        }
    }
}

void fn_801A1DB4(Self_801A1DB4 *o) {
    s32 i;
    u32 best = 0;
    Key_801A1DB4 cur;
    Key_801A1DB4 tmp;
    o->ctx->x6 = 0;
    o->ctx->x5 = 0;
    o->ctx->x7 = 0;
    cur.a = 0;
    cur.c = 0;
    cur.b[5] = 0;
    cur.b[4] = 0;
    cur.b[3] = 0;
    cur.b[2] = 0;
    cur.b[1] = 0;
    cur.b[0] = 0;
    for (i = 0; i < 7; i++) {
        Item_801A1DB4 *it = &((Item_801A1DB4 *)((u8 *)o->ctx + 0x14))[i];
        if (it->kind == 1) {
            tmp.a = it->h32;
            tmp.b[0] = it->b34[0];
            tmp.b[1] = it->b34[1];
            tmp.b[2] = it->b34[2];
            tmp.b[3] = it->b34[3];
            tmp.b[4] = it->b34[4];
            tmp.b[5] = it->b34[5];
            tmp.c = 0;
            if (fn_8000743C(&tmp, &cur) >= 0) {
                best = i;
                cur = tmp;
            }
        }
    }
    switch (best) {
    case 0:
    default: o->ctx->x6 = 0; o->ctx->x5 = 0; break;
    case 1: o->ctx->x6 = 1; o->ctx->x5 = 0; break;
    case 2: o->ctx->x6 = 2; o->ctx->x5 = 0; break;
    case 3: o->ctx->x6 = 3; o->ctx->x5 = 0; break;
    case 4: o->ctx->x6 = 4; o->ctx->x5 = 0; break;
    case 5: o->ctx->x6 = 4; o->ctx->x5 = 1; break;
    case 6: o->ctx->x6 = 4; o->ctx->x5 = 2; break;
    }
    o->ctx->x7 = o->ctx->x6 + o->ctx->x5;
}

void fn_801A1FBC(Self_801A0C3C* o) {
    SpriteObjScaled so;
    so.texlist = (NJS_TEXLIST*)menu_sprites.textlistC;
    so.a = 1.0f;
    so.b = o->ctx->x18;
    so.sx = 1.0f;
    so.sy = 1.0f;
    so.flags = 1;
    if (o->ctx->x6 != 0) {
        so.sprite = fn_801D68C4(menu_sprites.banks[0], 0xf);
        so.x = 480.0f;
        so.y = 40.0f;
        so.z = -4400.0f;
        so.flip = 1;
        SpriteObjDrawScaled(&so);
    }
    if (o->ctx->x6 != 4) {
        so.sprite = fn_801D68C4(menu_sprites.banks[0], 0x10);
        so.x = 480.0f;
        so.y = 360.0f;
        so.z = -4399.9f;
        so.flip = 1;
        SpriteObjDrawScaled(&so);
    }
}

void fn_801A20AC(SaveTask* t) {
    s32 b = 0;
    s32 a = 0;
    u16 cmd;
    UiObj *ui;
    if (t->w->sel == 2) {
        if (t->w->st[1] != 1) {
            t->w->sel = 1;
            b = 1;
        }
        if (t->w->st[0] != 1) {
            t->w->sel = 0;
            a = 1;
        }
    } else {
        if (t->w->st[0] != 1) {
            a = 1;
        } else if (t->w->st[1] != 1) {
            t->w->sel = 1;
        }
        if (t->w->st[1] != 1) {
            b = 1;
        } else if (t->w->st[0] != 1) {
            t->w->sel = 0;
        }
    }
    ui = &t->w->p[3]->obj->o;
    if (a != 0) {
        s32 c = 0x14;
        if (t->w->sel == 0) {
            c = 0x15;
        }
        cmd = c;
    } else {
        cmd = 0x14;
    }
    UiObjSetCommand(ui, cmd, 0);
    ui = &t->w->p[4]->obj->o;
    if (b != 0) {
        s32 c = 0x14;
        if (t->w->sel == 1) {
            c = 0x15;
        }
        cmd = c;
    } else {
        cmd = 0x14;
    }
    UiObjSetCommand(ui, cmd, 0);
}

SaveTask* SaveLoadOpenSave(void* parent, u16 id) {
    SaveTask* t;
    lbl_803473C4 = 0;
    t = fn_802267AC(parent, SaveLoadTask);
    t->w = fn_801E1A74(1, 0x270);
    t->w->f1 = 0;
    t->w->f18 = 1.0f;
    t->w->h10 = id;
    t->w->p[0] = 0;
    t->w->p[1] = 0;
    t->w->p[2] = 0;
    t->w->p[3] = 0;
    t->w->p[4] = 0;
    t->w->p[5] = 0;
    t->w->p[6] = 0;
    t->w->p[7] = 0;
    t->w->p[8] = 0;
    t->w->p[9] = 0;
    t->w->p[10] = 0;
    t->w->p[11] = 0;
    t->w->p[12] = 0;
    t->w->p[13] = 0;
    t->w->p[14] = 0;
    t->w->p[15] = 0;
    t->w->x0 = 0;
    return t;
}

SaveTask* SaveLoadOpenLoad(void* parent, u8 mode) {
    SaveTask* t;
    int i;
    lbl_803473C4 = 0;
    if (lbl_80347568 == 0) {
        return 0;
    }
    t = fn_802267AC(parent, SaveLoadTask);
    t->w = fn_801E1A74(1, 0x270);
    t->w->f1 = 1;
    t->w->f18 = 1.0f;
    for (i = 0; i < 16; i++) {
        t->w->p[i] = 0;
    }
    t->w->fa = 0;
    t->w->x0 = mode;
    return t;
}


void fn_801A2424(s32 n, s32 idx, char* buf, s32 len) {
    char* s = lbl_802B9428[idx];
    char* p;
    s32 lim;
    s32 i;
    if (strlen(s) < (lim = len - 4)) {
        sprintf(buf, "#%d %s", n, s);
    } else {
        buf[0] = '#';
        buf[1] = n + '0';
        buf[2] = ' ';
        p = buf + 3;
        lim--;
        for (i = 3; i < lim; i++) {
            if (*s == 0) break;
            *p = *s;
            s++;
            p++;
        }
        *p = 0;
    }
}

s32 fn_801A2500(s32 chan, s32 *out) {
    s32 code;
    s32 xfer;
    s32 r;

    if (lbl_8034718C[chan] == 0) {
        lbl_8034718C[chan] = fn_801E1C7C(0xa000);
    }
    fn_80248DCC(chan, lbl_8034718C[chan], chan == 0 ? fn_801A2CC4 : fn_801A2C58, 0);
    code = CardWait(chan);
    switch (code) {
    case 0:
    case -6:
        CARDCheckExAsync(chan, &xfer, 0);
        code = CardWait(chan);
        if (code != 0) {
            CardRelease(chan);
            r = 0;
        } else {
            lbl_80347184[chan] = 1;
            r = 1;
        }
        break;
    default:
        CardRelease(chan);
        r = 0;
        break;
    }
    if (out != 0) {
        *out = code;
    }
    return r;
}

s32 fn_801A2670(s32 idx, s32 *out)
{
    s32 done = 0;
    s32 r;
    s32 t;
    switch (lbl_80347180) {
    case 0:
        if (lbl_8034718C[idx] == 0) {
            lbl_8034718C[idx] = fn_801E1C7C(0xA000);
        }
        CARDMountAsync(idx, lbl_8034718C[idx], idx == 0 ? fn_801A2CC4 : fn_801A2C58, 0);
        do {
            fn_801DC214();
            r = CARDGetResultCode(idx);
        } while (r == -1);
        switch (r) {
        case 0:
        case -6:
        case -13:
            lbl_80347180 = 1;
            break;
        default:
            *out = r;
            done = 1;
            break;
        }
        break;
    case 1:
        r = CARDFormatAsync(idx, fn_801A28A8);
        if (r == 0 || r == -1) {
            lbl_80347180 = 2;
        } else {
            if (lbl_8034718C[idx] != 0) {
                fn_801DC214();
                t = CARDUnmount(idx);
                if (t == 0 || t == -3) {
                    fn_801E17E0(lbl_8034718C[idx]);
                    lbl_8034718C[idx] = 0;
                }
            }
            *out = r;
            done = 1;
        }
        break;
    case 2:
        r = CARDGetResultCode(idx);
        if (r != -1) {
            if (r == 0) {
                if (lbl_8034718C[idx] != 0) {
                    fn_801DC214();
                    t = CARDUnmount(idx);
                    if (t == 0 || t == -3) {
                        fn_801E17E0(lbl_8034718C[idx]);
                        lbl_8034718C[idx] = 0;
                    }
                }
                *out = 0;
                done = 1;
            } else {
                if (lbl_8034718C[idx] != 0) {
                    fn_801DC214();
                    t = CARDUnmount(idx);
                    if (t == 0 || t == -3) {
                        fn_801E17E0(lbl_8034718C[idx]);
                        lbl_8034718C[idx] = 0;
                    }
                }
                *out = r;
                done = 1;
            }
        }
        break;
    default:
        *out = -0x80;
        done = 1;
        break;
    }
    return done;
}

void fn_801A289C(void) {
    lbl_80347180 = 0;
}

void fn_801A28A8(void) {
}

s32 fn_801A28AC(s32 obj) {
    s32 r;
    fn_801DC214();
    do {
        r = fn_80248708(obj, 0, 0);
    } while (r == -1);
    return fn_801A6A04(r);
}

void fn_801A2C40(void) {
    lbl_80347178 = 0;
    lbl_80347170[0] = 1;
    lbl_80347170[0] = 1;
}

void fn_801A2C58(void) {
    if (lbl_8034718C[1] != 0) {
        s32 r;
        fn_801DC214();
        r = CARDUnmount(1);
        if (r == 0 || r == -3) {
            fn_801E17E0(lbl_8034718C[1]);
            lbl_8034718C[1] = 0;
        }
    }
    lbl_80347184[1] = 0;
}

void fn_801A2CC4(void) {
    if (lbl_8034718C[0] != 0) {
        s32 r;
        fn_801DC214();
        r = CARDUnmount(0);
        if (r == 0 || r == -3) {
            fn_801E17E0(lbl_8034718C[0]);
            lbl_8034718C[0] = 0;
        }
    }
    lbl_80347184[0] = 0;
}
