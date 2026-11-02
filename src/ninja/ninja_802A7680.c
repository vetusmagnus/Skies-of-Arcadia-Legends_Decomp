/* Sega Ninja library, 0x802A7680-0x802AC75C. The rest of Ninja from renderer 2's second
 * chunk-model pool (0x8034D3F0) on; its file edges aren't known yet. */

#include "ninja_lib.h"

void fn_802A7894(s16* p, s32 n, u32* data) {
    u8 type = n;
    u8 dif[4] = {0xff, 0xff, 0xff, 0xff};
    u8 spc[4] = {0, 0, 0, 0};
    u8 amb[4] = {0, 0, 0, 0};
    s32 tex;
    u16 size;
    s16 cnt;
    s16 kind;
    s16 c;
    s16 len;
    s16 fl;
    s32 alpha;
    s32 enable;
    u32 ambf;

    while ((c = *p++) != 0xff) {
        kind = c & 0xff;
        if (kind < 8) {
            switch (kind) {
            case 1:
                fn_8029D010(c);
                break;
            case 4:
                lbl_803458A8[(s16)((c >> 8) & 0xff)] = p;
                lbl_80347F24++;
                return;
            case 5:
                fn_802A7894(lbl_803458A8[(s16)((c >> 8) & 0xff)], n, data);
                lbl_80347F24--;
                break;
            }
        } else if (kind < 0x10) {
            fn_8029D0F4(c, *p++);
            if (*p & 0x18) {
                p += 8;
            }
        } else if (kind < 0x40) {
            len = *p++;
            fn_8029D698(c, p, dif, amb, spc);
            p += len;
        } else {
            cnt = p[1];
            size = *(u16*)p;  /* the chunk stream is s16; this field is unsigned */
            p += 2;
            if (_nj_control_3d_flag_ & 0x800) {
                c &= _nj_constant_attr_and_;
                c |= _nj_constant_attr_or_;
            }
            fl = (c >> 8) & 0x2a;
            lbl_80347EA0 = fl & 0x20;
            tex = fl & 2;
            if (tex) {
                enable = 1;
            } else {
                enable = 1;
            }
            if (fl & 8) {
                alpha = 1;
                if (lbl_80347E20 == 1) {
                    p += size - 1;
                    continue;
                }
            } else {
                alpha = 0;
                switch (lbl_80347E20) {
                case 2:
                case 3:
                case 4:
                    p += size - 1;
                    continue;
                }
            }
            ambf = 0;
            if (fl & 4) {
                ambf = 0x300;
            }
            fn_802A8F40(1);
            fn_8029D8B0(&lbl_80344DE0, kind, n, enable);
            switch (kind) {
            case 0x41:
            case 0x42:
                GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3c, 0, 0x7d);
                GXSetNumTexGens(1);
                switch (type) {
                case 0x29:
                    if (tex) {
                        fn_8029AA14(alpha);
                    } else {
                        fn_80299BD8(alpha);
                    }
                    fn_802A7D74(ambf | 2, 0, amb, 0, dif);
                    fn_8029DCD0(p, data, cnt, 1, kind);
                    break;
                case 0x2a:
                    if (fn_8029CFF0()) {
                        fn_802A7D74(ambf | 2, 0, amb, 0, dif);
                        fn_8029D8B0(&lbl_80344DE0, kind, 0x29, enable);
                        fn_8029CF04();
                        fn_8029A698(alpha, 0);
                        fn_8029DEDC(p, data, cnt, 1, kind);
                    } else {
                        fn_802A7D74(ambf | 4, 0, amb, 0, 0);
                        if (tex) {
                            fn_8029AA14(alpha);
                        } else {
                            fn_80299BD8(alpha);
                        }
                        fn_8029E1B4(p, data, cnt, 1, kind);
                    }
                    break;
                }
                break;
            case 0x40:
                switch (type) {
                case 0x29:
                    GXSetNumTexGens(0);
                    fn_8029A1C8(alpha);
                    fn_802A7D74(ambf | 1, 0, amb, 0, dif);
                    fn_8029EE78(p, data, cnt, 1);
                    break;
                case 0x2a:
                    if (fn_8029CFF0()) {
                        fn_802A7D74(ambf | 2, 0, amb, 0, dif);
                        fn_8029D8B0(&lbl_80344DE0, kind, 0x29, enable);
                        fn_8029CF04();
                        fn_80299FC8(alpha);
                        fn_8029F680(p, data, cnt, 1);
                    } else {
                        GXSetNumTexGens(0);
                        fn_8029A1C8(alpha);
                        fn_802A7D74(ambf | 4, 0, amb, 0, dif);
                        fn_8029F86C(p, data, cnt, 1);
                    }
                    break;
                }
                break;
            }
            p += size - 1;
        }
    }
}

void fn_802A7D74(u32 flags, s32 unused1, u8* amb, s32 unused2, u8* mat) {
    GXColor a;
    GXColor c;
    s32 i;
    u32 r, g, bl;
    NjLightTbl* t;

    switch (flags & 0xf) {
    case 1:
        c.a = mat[3];
        c.r = mat[0];
        c.g = mat[1];
        c.b = mat[2];
        GXSetChanMatColor(GX_COLOR0A0, c);
        break;
    case 2:
        c.a = mat[3];
        c.r = 0xff;
        c.g = 0xff;
        c.b = 0xff;
        GXSetChanMatColor(GX_COLOR0A0, c);
        break;
    case 4:
        break;
    }
    switch (flags & 0xf00) {
    case 0x100:
        a.r = amb[0];
        a.g = amb[1];
        a.b = amb[2];
        a.a = amb[3];
        break;
    case 0x300:
        a.r = 0;
        a.g = 0;
        a.b = 0;
        a.a = 0xff;
        break;
    case 0x200:
    default:
        r = amb[0] * lbl_80344DE0.amb.r;
        g = amb[1] * lbl_80344DE0.amb.g;
        bl = amb[2] * lbl_80344DE0.amb.b;
        a.r = r >> 8;
        a.g = g >> 8;
        a.b = bl >> 8;
        a.a = 0xff;
        break;
    }
    GXSetChanAmbColor(GX_COLOR0A0, a);
    t = &lbl_80344DE0;
    if (t->dirty) {
        t->dirty = 0;
        for (i = 0; i < 8; i++) {
            if (t->light[i].mask) {
                GXInitLightColor(&lbl_80344BE0[i], t->light[i].col);
                GXInitLightPos(&lbl_80344BE0[i], t->light[i].vpos.x, t->light[i].vpos.y, t->light[i].vpos.z);
                GXInitLightDistAttn(&lbl_80344BE0[i], t->light[i].f48, t->light[i].f50, t->light[i].s54);
                GXInitLightSpot(&lbl_80344BE0[i], t->light[i].f58, t->light[i].s5c);
                GXLoadLightObjImm(&lbl_80344BE0[i], t->light[i].mask);
            }
        }
    }
}

void fn_802A88C0(u32 flags, s32 unused1, u8* amb, s32 unused2, u8* mat) {
    GXColor a;
    GXColor c;
    s32 i;
    u32 r, g, bl;
    NjLightTbl* t;

    switch (flags & 0xf) {
    case 1:
        c.a = mat[3];
        c.r = mat[0];
        c.g = mat[1];
        c.b = mat[2];
        GXSetChanMatColor(GX_COLOR0A0, c);
        break;
    case 2:
        c.a = mat[3];
        c.r = 0xff;
        c.g = 0xff;
        c.b = 0xff;
        GXSetChanMatColor(GX_COLOR0A0, c);
        break;
    case 4:
        break;
    }
    t = &lbl_80345350;
    if (t->dirty) {
        t->dirty = 0;
        for (i = 0; i < 8; i++) {
            if (t->light[i].mask) {
                GXInitLightColor(&lbl_80345150[i], t->light[i].col);
                GXInitLightPos(&lbl_80345150[i], t->light[i].vpos.x, t->light[i].vpos.y, t->light[i].vpos.z);
                GXInitLightDistAttn(&lbl_80345150[i], t->light[i].f48, t->light[i].f50, t->light[i].s54);
                GXInitLightSpot(&lbl_80345150[i], t->light[i].f58, t->light[i].s5c);
                GXLoadLightObjImm(&lbl_80345150[i], t->light[i].mask);
            }
        }
    }
    switch (flags & 0xf00) {
    case 0x100:
        a.r = amb[0];
        a.g = amb[1];
        a.b = amb[2];
        a.a = amb[3];
        break;
    case 0x300:
        a.r = 0;
        a.g = 0;
        a.b = 0;
        a.a = 0xff;
        break;
    case 0x200:
    default:
        r = amb[0] * lbl_80345350.amb.r;
        g = amb[1] * lbl_80345350.amb.g;
        bl = amb[2] * lbl_80345350.amb.b;
        a.r = r >> 8;
        a.g = g >> 8;
        a.b = bl >> 8;
        a.a = 0xff;
        break;
    }
    GXSetChanAmbColor(GX_COLOR0A0, a);
}

s32 fn_802A8ADC(void) { return lbl_80346A50; }

void fn_802A8AE4(NgDlHdr* h) {
    NgGd* gd;
    if (h->magic != 0x4E47444C) return;
    fn_8029CA58();
    if (h->off[0] != 0xFFFFFFFF) {
        gd = (NgGd*)((u8*)h + h->off[0]);  /* NGGD block at a byte offset from the NGDL header */
        if (gd->magic != 0x4E474744) return;
        GXCallDisplayList(gd->dl.data, gd->dl.size);
    }
    if (h->off[1] != 0xFFFFFFFF) {
        gd = (NgGd*)((u8*)h + h->off[1]);  /* NGGD block at a byte offset from the NGDL header */
        if (gd->magic != 0x4E474744) return;
        GXCallDisplayList(gd->dl.data, gd->dl.size);
    }
    lbl_80347F6C = 2;
    lbl_80347F70 = 5;
    lbl_803457A8.w48 = -1;
    lbl_803457A8.w4c = -1;
}

void fn_802A8F40(s32 v) { lbl_80347FB4 = v; }

static inline void NgStep(void) {
    u8* p;
    /* step to the next motion record; the record holds `stride`-byte key-pointer tables (as fn_80293C2C) */
    p = lbl_80347FBC->base;
    p += lbl_80347FBC->step;
    lbl_80347FBC->base = p;
    lbl_80347FBC->arrA = (void**)p;
    lbl_80347FBC->arrB = (void**)(p + lbl_80347FBC->stride);
    lbl_80347FBC->idx = 0;
}

void fn_802A8F48(u32** in, u32** out) {
    fn_802A9714(in, out);
    NgStep();
}

void fn_802A8FA0(s32 v) { lbl_80347FB8 = v; }

#pragma optimization_level 1
void fn_802A8FA8(s32 i) { lbl_80347FBC = &lbl_80346690[i]; }

#pragma optimization_level reset
void fn_802A9040(void) {
    u8* p;
    /* step to the next motion record; the record holds `stride`-byte key-pointer tables (as fn_80293C2C) */
    p = lbl_80347FBC->base;
    p += lbl_80347FBC->step;
    lbl_80347FBC->base = p;
    lbl_80347FBC->arrA = (void**)p;
    lbl_80347FBC->arrB = (void**)(p + lbl_80347FBC->stride);
    lbl_80347FBC->idx = 0;
}

inline void fn_802A907C(NjObj* obj) {
    NjDrawCtx* ctx;
    u32* tmp;
    NjModel* m;
    u32* saved;

    ctx = lbl_80346A18;
    do {
        njPushMatrixEx();
        fn_802954EC(obj);
        if (!(obj->evalflags & 0x80)) {
            m = obj->model;
            if (m != 0 && !(obj->evalflags & 8)) {
                fn_802A8F48(&m->vlist, &tmp);
                saved = m->vlist;
                m->vlist = tmp;
                ctx->drawModel(m);
                m->vlist = saved;
            } else {
                fn_802A9040();
            }
        } else if (obj->model != 0 && !(obj->evalflags & 8)) {
            ctx->drawModel(obj->model);
        }
        if (obj->child != 0) {
            fn_802A907C(obj->child);
        }
        njPopMatrixEx();
        obj = obj->sibling;
    } while (obj != 0);
}

void fn_802A9338(NjObj* obj, NJS_MOTION* mot, NJS_MOTION* shape, NjModelCb cb, f32 frame) {
    NjDrawCtx* ctx = lbl_80346A18;
    fn_802956F0(mot, frame);
    ctx->drawModel = cb;
    if (shape == 0) {
        fn_80295738(obj);
    } else {
        fn_802A8FA8(0);
        fn_802A8FC0(shape, frame);
        fn_802A907C(obj);
    }
}

void fn_802A9714(u32** in, u32** out) {
    void* a;
    void* b;
    void* c;
    void* d;

    if (*in == 0) {
        *out = 0;
        return;
    }
    if (lbl_80347FBC->flags & 0x10) {
        a = lbl_80347FBC->arrA[lbl_80347FBC->idx];
        if (a != 0) {
            b = lbl_80347FBC->arrB[lbl_80347FBC->idx];
        }
        lbl_80347FBC->idx++;
    } else {
        a = 0;
    }
    if (lbl_80347FBC->flags & 0x20) {
        c = lbl_80347FBC->arrA[lbl_80347FBC->idx];
        if (c != 0) {
            d = lbl_80347FBC->arrB[lbl_80347FBC->idx];
        }
        lbl_80347FBC->idx++;
    } else {
        c = 0;
    }
    if (a != 0 || c != 0) {
        fn_802A93CC(a, b, c, d, *in, out, lbl_80347FBC->t);
    } else {
        *out = *in;
    }
}

void fn_802A9804(u32** in, u32** out) {
    fn_802AA110(in, out);
    fn_802A8FA8(1);
    fn_802A9040();
    fn_802A8FA8(0);
    fn_802A9040();
}

void fn_802A983C(void) {
    fn_802A8FA8(1);
    fn_802A9040();
    fn_802A8FA8(0);
    fn_802A9040();
}

void fn_802A9870(NJS_MOTION_LINK* p, f32 v) {
    fn_802A8FA8(1);
    fn_802A8FC0(p->motion[1], p->frame[1]);
    fn_802A8FA8(0);
    fn_802A8FC0(p->motion[0], p->frame[0]);

    lbl_80347FC0 = v;
}

inline void fn_802A98D8(NjObj* obj) {
    NjDrawCtx* ctx;
    u32* tmp;
    NjModel* m;
    u32* saved;

    ctx = lbl_80346A18;
    do {
        njPushMatrixEx();
        fn_802947D4(obj);
        if (!(obj->evalflags & 0x80)) {
            m = obj->model;
            if (m != 0 && !(obj->evalflags & 8)) {
                fn_802A9804(&m->vlist, &tmp);
                saved = m->vlist;
                m->vlist = tmp;
                ctx->drawModel(m);
                m->vlist = saved;
            } else {
                fn_802A983C();
            }
        } else if (obj->model != 0 && !(obj->evalflags & 8)) {
            ctx->drawModel(obj->model);
        }
        if (obj->child != 0) {
            fn_802A98D8(obj->child);
        }
        njPopMatrixEx();
        obj = obj->sibling;
    } while (obj != 0);
}

void fn_802A9B94(NjObj* obj, NJS_MOTION_LINK* link, NJS_MOTION_LINK* shape, NjModelCb cb, f32 rate) {
    NjDrawCtx* ctx = lbl_80346A18;
    fn_802949A4(link, rate);
    ctx->drawModel = cb;
    if (shape == 0) {
        fn_80294A0C(obj);
    } else {
        fn_802A9870(shape, rate);
        fn_802A98D8(obj);
    }
}

void fn_802AA110(u32** in, u32** out) {
    void* p3b;
    void* p4b;
    void* p1a;
    void* p2a;
    void* p1b;
    void* p2b;
    void* p3a;
    void* p4a;
    f32 t0;
    f32 t1;

    if (*in == 0) {
        *out = 0;
        return;
    }
    fn_802A8FA8(1);
    if (lbl_80347FBC->flags & 0x10) {
        p1a = lbl_80347FBC->arrA[lbl_80347FBC->idx];
        if (p1a != 0) {
            p1b = lbl_80347FBC->arrB[lbl_80347FBC->idx];
        }
        lbl_80347FBC->idx++;
    } else {
        p1a = 0;
    }
    if (lbl_80347FBC->flags & 0x20) {
        p2a = lbl_80347FBC->arrA[lbl_80347FBC->idx];
        if (p2a != 0) {
            p2b = lbl_80347FBC->arrB[lbl_80347FBC->idx];
        }
        lbl_80347FBC->idx++;
    } else {
        p2a = 0;
    }
    t0 = lbl_80347FBC->t;
    fn_802A8FA8(0);
    if (lbl_80347FBC->flags & 0x10) {
        p3a = lbl_80347FBC->arrA[lbl_80347FBC->idx];
        if (p3a != 0) {
            p3b = lbl_80347FBC->arrB[lbl_80347FBC->idx];
        }
        lbl_80347FBC->idx++;
    } else {
        p3a = 0;
    }
    if (lbl_80347FBC->flags & 0x20) {
        p4a = lbl_80347FBC->arrA[lbl_80347FBC->idx];
        if (p4a != 0) {
            p4b = lbl_80347FBC->arrB[lbl_80347FBC->idx];
        }
        lbl_80347FBC->idx++;
    } else {
        p4a = 0;
    }
    t1 = lbl_80347FBC->t;
    if (p3a != 0 || p4a != 0 || p1a != 0 || p2a != 0) {
        fn_802A9C20(p3a, p3b, t1, t0, lbl_80347FC0, p4a, p4b, p1a, p1b, p2a, p2b, *in, out);
    } else {
        *out = *in;
    }
}

void fn_802AB23C(NjObj* obj) {
    if (!(obj->evalflags & 0x10000)) {
        lbl_80347FC8 = 0;
        lbl_80347FCC = 0;
        fn_80288DE4(obj, fn_802AB2C4);
        if (lbl_80347FC8 != 1) {
            obj->evalflags |= 0x4000;
        }
        if (lbl_80347FCC != 1) {
            obj->evalflags |= 0x8000;
        }
        obj->evalflags |= 0x10000;
    }
}

s32 fn_802AB2C4(NjModel* m) {
    u32* p;
    if (m->vlist != 0) {
        p = m->vlist;
        while ((p[0] & 0xFF) != 0xFF) {
            u32 hdr = p[0];
            u32 n = hdr >> 16;
            s32 cmd = hdr & 0xFF;
            p += 2;
            if (cmd == 0x2C) {
                lbl_80347FC8 = 1;
            }
            p += n - 1;
        }
    }
    if (m->plist != 0) {
        fn_802AB340(m->plist);
    }
    return 0;
}

void fn_802AB340(s16* list) {
    s16* p = list;
    s16 h;
    s16 t;
    while ((h = *p++) != 0xFF) {
        t = h & 0xFF;
        if (t < 8) {
            switch (t) {
            case 0:
            case 1:
            case 2:
            case 3:
                break;
            case 4:
                lbl_803458A8[(s16)((h >> 8) & 0xFF)] = p;
                lbl_80347F24++;
                return;
            case 5:
                fn_802AB340(lbl_803458A8[(s16)((h >> 8) & 0xFF)]);
                lbl_80347F24--;
                break;
            }
        } else if (t < 16) {
            if (*++p & 0x18) {
                p += 8;
            }
        } else if (t < 64) {
            h = *p++;
            p += h;
        } else {
            s32 n;
            s16 fl = (h >> 8) & 8;
            n = *(u16*)p;  /* the chunk stream is s16; this field is unsigned */
            p += 2;
            if (fl & 8) {
                lbl_80347FCC = 1;
            }
            p += n - 1;
        }
    }
}

void fn_802AC2EC(s32 v) { lbl_80346A5C = v; }

void fn_802AC2F4(NjObj* obj) {
    fn_80288DE4(obj, fn_802AC31C);
}

asm void fn_802AC694(register void* dst, register void* src, register s32 n) {
    nofralloc
    cmpwi r5, 0x0
    blelr
    cmplw r3, r4
    bne L_802AC6A8
    bclr 20, 0 /* blr spelled out: the inline assembler folds bne+blr into beqlr */
L_802AC6A8:
    li r6, 0x8
    li r7, 0x28
    mtctr r5
    subi r4, r4, 0x8
    subi r5, r3, 0x8
L_802AC6BC:
    dcbz r6, r5
    dcbt r7, r4
    lfdu f0, 0x8(r4)
    lfdu f1, 0x8(r4)
    lfdu f2, 0x8(r4)
    lfdu f3, 0x8(r4)
    stfdu f0, 0x8(r5)
    stfdu f1, 0x8(r5)
    stfdu f2, 0x8(r5)
    stfdu f3, 0x8(r5)
    bdnz L_802AC6BC
    blr
}

void njMemCopy(void* dst, const void* src, s32 count) {
    memmove(dst, src, count << 2);
}

void* fn_802AC710(void* dst, const void* src, u32 n) {
    return memmove(dst, src, n);
}

void fn_802AC730(void* dst, u8 c, s32 n) {
    if (n > 0) {
        memset(dst, c, n);
    }
}
