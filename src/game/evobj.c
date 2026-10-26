#include "types.h"
#include "ninja.h"
#include "game/task.h"

/* Story-flag event object (0x801E8CA4 - 0x801EA2DC): the event object task fn_801E8CA4 (waits for
 * the player in range of its story flag, runs the flag's event and sets it), its child model
 * object fn_801E9AE0 (a pulsing marker that follows a map point) and the sparkle task
 * fn_801E9EA8 (falling sparks around that point). All three share one model object layout. */

typedef struct {
    void* model;          /* 0x00 */
    u32 pad4;
    NJS_TEXLIST texlist;  /* 0x08 */
} ModelFile;

typedef struct {
    u8 pad0[8];
    ModelFile* body;    /* 0x08 */
    ModelFile* extra;   /* 0x0C */
    ModelFile* spark;   /* 0x10 */
} ModelFiles;

typedef struct {
    s32 count;
    void* items[1]; /* count entries */
} ItemList;

typedef struct {
    u8 pad0[0x24];
    u32 nearDist;  /* 0x24 */
    u32 actDist;   /* 0x28 */
    u8 pad2C[4];
    u32 speed;     /* 0x30 */
    u8 pad34[4];
    s32 mode;      /* 0x38 */
    u32 flag;      /* 0x3C story flag */
} EvInfo;

typedef struct {
    u8 pad0[0x10];
    EvInfo* info;          /* 0x10 */
    ModelFiles* files;     /* 0x14 */
    u8 pad18[4];
    ItemList* items;       /* 0x1C */
    NJS_TEXLIST* texlist;  /* 0x20 */
} EvExt;

/* Only nbFrame is used here; see model.c for the field meanings. */
typedef struct NJS_MOTION {
    void** mdata;
    u32 nbFrame;
    u16 type;
    u16 inp_fn;
} NJS_MOTION;

/* The game's model object (see model.c) with the fields these three tasks use. */
typedef struct {
    u8 pad0[4];
    s32 kind;                /* 0x04 */
    u8 pad8[0x1C - 0x08];
    NJS_ARGB colour;         /* 0x1C */
    u8 pad2C[0x38 - 0x2C];
    NJS_POINT3 pos;          /* 0x38 */
    Angle ang[3];            /* 0x44 */
    NJS_POINT3 scl;          /* 0x50 */
    u8 pad5C[0x74 - 0x5C];
    s16 x74;                 /* 0x74 */
    u8 pad76[0xB4 - 0x76];
    NJS_POINT3 pivotPos;     /* 0xB4 */
    u8 padC0[0xE4 - 0xC0];
    void* model;             /* 0xE4 */
    NJS_MOTION* motion;      /* 0xE8 */
    void* shape;             /* 0xEC */
    u8 padF0[0x100 - 0xF0];
    NJS_TEXLIST* texlist;    /* 0x100 */
    u8 pad104[0x164 - 0x104];
    f32 x164;                /* 0x164 */
    s16 state;               /* 0x168 */
    u8 pad16A[2];
    s16 pivot;               /* 0x16C */
    u8 pad16E[2];
    u16 motionId;            /* 0x170 */
    u16 x172;                /* 0x172 */
    u8 pad174[2];
    u16 id;                  /* 0x176 */
    u8 pad178[0x184 - 0x178];
    s32 hidden;              /* 0x184 */
    u8 pad188[0x190 - 0x188];
    f32 speed;               /* 0x190 */
    u8 pad194[0x1C8 - 0x194];
    EvExt* ext;              /* 0x1C8 */
    u8 pad1CC[0x1EC - 0x1CC];
    s8 x1ec;                 /* 0x1EC */
    s8 x1ed;                 /* 0x1ED */
    u8 pad1EE[0x1FC - 0x1EE];
    s16 x1fc;                /* 0x1FC */
    u8 pad1FE[0x202 - 0x1FE];
    s16 x202;                /* 0x202 */
    u8 pad204[0x208 - 0x204];
    s16 x208;                /* 0x208 */
    s16 x20a;                /* 0x20A */
    u8 pad20C[0x210 - 0x20C];
    u32 x210;                /* 0x210 */
    u8 pad214[0x21E - 0x214];
    u8 x21e;                 /* 0x21E */
    u8 x21f;                 /* 0x21F */
    u8 pad220[0x22C - 0x220];
    s16 x22c;                /* 0x22C */
    s16 x22e;                /* 0x22E */
    s16 x230;                /* 0x230 */
    u16 point;               /* 0x232 */
    u8 pad234[0x23C - 0x234];
    void* x23c;              /* 0x23C */
    void* x240;              /* 0x240 */
    u8 pad244[0x24C - 0x244];
    NJS_POINT3 x24c;         /* 0x24C */
} EvObj;

typedef struct {
    NJS_POINT3 a; /* 0x00 */
    NJS_POINT3 b; /* 0x0C */
    NJS_POINT3 c; /* 0x18 */
} EvCam;

typedef struct {
    u32 w[4];
    s16 flag; /* 0x10 */
    u16 pad;
} Obj14;

typedef struct {
    f32 x, y;      /* 0x00 */
    f32 pad08;     /* 0x08 */
    f32 sx, sy;    /* 0x0C */
    u32 colour;    /* 0x14 */
    NJS_TEXLIST* texlist; /* 0x18 */
    Obj14* data;   /* 0x1C */
} Obj20;

typedef struct { u8 pad[0x8]; u32 x8; } PadState;
typedef struct { PadState* pad; u8 pad4[0x14]; } PadInfo;

extern u32 lbl_80310B3C[];
extern EvCam lbl_803136A8;
extern NJS_POINT3 lbl_803119E0[2]; /* [1] is the camera look-at */
extern NJS_POINT3 lbl_803139B4[30];
extern NJS_POINT3 lbl_8031384C[];
extern PadInfo lbl_80311A60;
extern Obj14 lbl_802C47A0;
extern s32 lbl_80347408;
extern s32 lbl_80347440;
extern EvObj* lbl_80347450;
extern s32 lbl_80347778;
extern s32 lbl_8034777C;
extern Task* lbl_80347780;
extern s16 lbl_80347784;
extern s32 lbl_8034778C;
extern s32 lbl_80347790;
extern s32 lbl_80347794;
extern s32 lbl_8034779C;
extern s32 lbl_803477A0;
extern s32 fn_801161B4(void);
extern void fn_8015ED90(Task* task);
extern void fn_80116020(s32 n);
extern void fn_80227810(NJS_TEXLIST* texlist);
extern void fn_801173DC(s32 a, EvObj* obj);
extern Task* fn_801C6180(Task* parent, void (*func)(Task*));
extern void fn_801C5BF4(EvObj* obj, u16 motion);
extern f32 fn_801C5D04(EvObj* obj, s32 n);
extern s32 fn_801C6068(EvObj* obj, s32 n);
extern void fn_8015E600(EvObj* obj);
extern f32 fn_80290008(NJS_POINT3* a, NJS_POINT3* b);
extern void fn_801EAA08(Task* task);
extern f32 fn_801DBD9C(f32 z);
extern void fn_80005D98(Obj20* obj, s32 a, s32 b, f32 z);
extern void fn_801EC854(EvObj* obj, s32 dist);
extern void fn_80217830(void* p);
extern void fn_801EAF00(EvObj* obj);
extern void fn_80095630(f32* v, s32 n);
extern void fn_802275A4(NJS_TEXLIST* texlist, s32 a);
extern void fn_8015EBF4(EvObj* obj);
extern void fn_80100B74(Task* task);
extern void fn_801E9AE0(Task* task);
extern void fn_801E9EA8(Task* task);
extern void fn_801EA2DC(Task* task);
extern void fn_801EB01C(Task* task);
extern int fn_8025ECC4(void);
extern void fn_801DD5E8(Angle* out, NJS_POINT3* p);
extern void fn_801E5DF0(EvObj* obj);
extern double sin(double);
extern double cos(double);

inline void VecSet(NJS_POINT3* p, f32 v) {
    p->x = p->y = p->z = v;
}

inline void VecCopy(NJS_POINT3* d, NJS_POINT3* s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

inline s32 FlagTest(u32 b) {
    return (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
}

inline void* ItemGet(ItemList* list, s32 i) {
    return list->count > i ? list->items[i] : 0;
}

inline void ObjSetMotionNow(EvObj* w, u16 m) {
    if (w != NULL) {
        w->motionId = m;
        fn_801C5BF4(w, w->motionId);
    }
}

inline void ObjSetMotion(EvObj* w, u16 m) {
    if (w != NULL && w->motionId != m) {
        ObjSetMotionNow(w, m);
    }
}

inline void EvDrawOverlay(EvObj* obj, s16 flag) {
    f32 z = 0.0f / (f32)obj->ext->info->nearDist;
    Obj20 o;
    Obj14 data = lbl_802C47A0;

    if (lbl_803477A0 == 0) {
        o.colour = obj->x210 += 0x16C;
    } else {
        o.colour = obj->x210;
    }
    o.texlist = obj->ext->texlist;
    o.sx = 0.5f;
    o.sy = 0.5f;
    o.x = 320.0f;
    o.y = 240.0f;
    o.data = &data;
    o.data->flag = (flag == 0 || lbl_803477A0 != 0) == 0;
    fn_80005D98(&o, 0, 0x21, fn_801DBD9C(-1.08f + z));
}

void fn_801E8CA4(Task* task) {
    EvCam* cam = &lbl_803136A8;
    s32 busy = fn_801161B4();
    EvObj* obj = task->work;
    EvObj* w;
    Task* t;
    s32 i;
    s32 j;
    f32 dist;
    f32 v[2];
    NJS_POINT3 a;
    NJS_POINT3 b;

    switch (task->state) {
    case 0:
        fn_8015ED90(task);
        lbl_80347794 = 0;
        lbl_803477A0 = 0;
        VecSet(&cam->b, 0.0f);
        VecSet(&cam->a, 1.0f);
        lbl_8034779C = 0;
        obj->x1ed = 0;
        obj->x1ec = 0;
        obj->x208 = 0;
        lbl_80347790 = 0;
        lbl_8034778C = 0;
        fn_80116020(0);
        lbl_80347778 = obj->ext->info->mode;
        lbl_80347784 = 0;
        obj->point = obj->ext->info->flag - 0xAF0;
        obj->pivotPos.y = 0.5f;
        obj->state = 0;
        obj->x1fc = 0;
        lbl_8034777C = 300;
        if (FlagTest(obj->ext->info->flag) != 0) {
            task->state = 8;
        } else {
            task->state = 1;
        }
        break;
    case 1:
        if (obj->texlist != NULL) {
            fn_80227810(obj->texlist);
        }
        if (obj->ext->texlist != NULL) {
            fn_80227810(obj->ext->texlist);
        }
        obj->x24c.x = obj->pos.x;
        obj->x24c.y = obj->pos.y;
        obj->x24c.z = obj->pos.z;
        obj->shape = ItemGet(obj->ext->items, 1);
        fn_801173DC(0, obj);
        obj->x74 = 0;
        obj->kind = 0;
        task->state = 5;
        obj->state = 0;

        lbl_80347780 = fn_801C6180(task, fn_801EB01C);
        ((EvObj*)lbl_80347780->work)->model = obj->ext->files->body->model;
        ((EvObj*)lbl_80347780->work)->texlist = &obj->ext->files->body->texlist;
        ((EvObj*)lbl_80347780->work)->ext = obj->ext;
        ObjSetMotion(lbl_80347780->work, 10);
        fn_80227810(((EvObj*)lbl_80347780->work)->texlist);
        ((EvObj*)lbl_80347780->work)->pos.x = obj->pos.x;
        ((EvObj*)lbl_80347780->work)->pos.y = obj->pos.y;
        ((EvObj*)lbl_80347780->work)->pos.z = obj->pos.z;
        ((EvObj*)lbl_80347780->work)->ang[0] = obj->ang[0];
        ((EvObj*)lbl_80347780->work)->ang[1] = obj->ang[1];
        ((EvObj*)lbl_80347780->work)->ang[2] = obj->ang[2];
        ((EvObj*)lbl_80347780->work)->pivot = 1;
        ((EvObj*)lbl_80347780->work)->state = 1;
        ((EvObj*)lbl_80347780->work)->x1ec = 0;
        ((EvObj*)lbl_80347780->work)->speed = fn_801C5D04(obj, 12);
        w = lbl_80347780->work;
        if (w != NULL) {
            f32 s = 0.0f;
            if (fn_801C6068(w, 15)) {
                s = (f32)w->ext->info->speed;
                s *= 0.03f;
            }
            w->x164 = s;
            w->x172 = 11;
        }
        w = lbl_80347780->work;
        w->x24c.x = obj->pos.x;
        w->x24c.y = obj->pos.y;
        w->x24c.z = obj->pos.z;
        ((EvObj*)lbl_80347780->work)->x22c = 0;
        ((EvObj*)lbl_80347780->work)->x22e = 0;
        ((EvObj*)lbl_80347780->work)->x230 = 0;
        ((EvObj*)lbl_80347780->work)->point = obj->ext->info->flag - 0xAF0;
        ((EvObj*)lbl_80347780->work)->id = obj->id;

        if (lbl_80310B3C[18] & 0x10) {
            t = fn_801C6180(task, fn_801EA2DC);
            ((EvObj*)t->work)->model = obj->ext->files->extra->model;
            ((EvObj*)t->work)->texlist = &obj->ext->files->extra->texlist;
            ((EvObj*)t->work)->ext = obj->ext;
            fn_80227810(((EvObj*)t->work)->texlist);
            ObjSetMotion(t->work, 14);
            ((EvObj*)t->work)->pivotPos.x = 0.0f;
            ((EvObj*)t->work)->pivotPos.y = 0.0f;
            ((EvObj*)t->work)->pivotPos.z = 0.0f;
            ((EvObj*)t->work)->pivot = 1;
            ((EvObj*)t->work)->state = 2;
            ((EvObj*)t->work)->speed = 1.0f;
            ((EvObj*)t->work)->id = obj->id;
            w = t->work;
            w->x24c.x = obj->pos.x;
            w->x24c.y = obj->pos.y;
            w->x24c.z = obj->pos.z;
            ((EvObj*)t->work)->x202 = 0;
            obj->x20a = ((EvObj*)t->work)->motion->nbFrame;
            ((EvObj*)t->work)->point = obj->ext->info->flag - 0xAF0;
        }

        obj->x210 = 0;
        for (i = 0; i < 4; i++) {
            t = fn_801C6180(task, fn_801E9AE0);
            ((EvObj*)t->work)->model = obj->ext->files->spark->model;
            ((EvObj*)t->work)->texlist = &obj->ext->files->spark->texlist;
            ((EvObj*)t->work)->ext = obj->ext;
            ((EvObj*)t->work)->shape = ItemGet(obj->ext->items, 3);
            fn_80227810(((EvObj*)t->work)->texlist);
            ((EvObj*)t->work)->scl.x = ((EvObj*)t->work)->scl.y = ((EvObj*)t->work)->scl.z = 0.4f * i + 0.5f;
            ((EvObj*)t->work)->state = i * -5;
            ((EvObj*)t->work)->id = obj->id;
            ((EvObj*)t->work)->x20a = 0;
            w = t->work;
            w->x24c.x = obj->pos.x;
            w->x24c.y = obj->pos.y;
            w->x24c.z = obj->pos.z;
            ((EvObj*)t->work)->point = obj->ext->info->flag - 0xAF0;
        }
        for (i = 0; i < 30; i++) {
            t = fn_801C6180(task, fn_801E9EA8);
            ((EvObj*)t->work)->model = obj->ext->files->spark->model;
            ((EvObj*)t->work)->texlist = &obj->ext->files->spark->texlist;
            ((EvObj*)t->work)->ext = obj->ext;
            ((EvObj*)t->work)->shape = ItemGet(obj->ext->items, 3);
            fn_80227810(((EvObj*)t->work)->texlist);
            ((EvObj*)t->work)->state = 0;
            ((EvObj*)t->work)->motionId = 0;
            ((EvObj*)t->work)->x172 = 0;
            ((EvObj*)t->work)->id = obj->id;
            w = t->work;
            w->x24c.x = obj->pos.x;
            w->x24c.y = obj->pos.y;
            w->x24c.z = obj->pos.z;
            ((EvObj*)t->work)->point = obj->ext->info->flag - 0xAF0;
        }
        break;
    default:
        fn_8015E600(obj);
        a.x = lbl_80347450->pos.x;
        a.y = lbl_80347450->pos.y;
        a.z = lbl_80347450->pos.z;
        b.x = obj->x24c.x;
        b.y = obj->x24c.y;
        b.z = obj->x24c.z;
        dist = fn_80290008(&a, &b);
        if (lbl_80347778 != 2) {
            VecCopy(&cam->b, &cam->c);
            VecCopy(&cam->c, &lbl_803119E0[0]);
            if (busy == 0 && lbl_80347440 == 1 && cam->b.x == cam->c.x && cam->b.y == cam->c.y &&
                cam->b.z == cam->c.z && (lbl_80310B3C[18] & 0x10)) {
                lbl_80347790 = 1;
                if (obj->x1fc++ >= 15) {
                    fn_801EAA08(task);
                    if (dist < (f32)obj->ext->info->nearDist && obj->x1ec == 0) {
                        s16 flag = 0;
                        if (lbl_80347794 == 8) {
                            flag = 1;
                        }
                        EvDrawOverlay(obj, flag);
                        if (obj->state == 0) {
                            lbl_80347794 = 0;
                        }
                    }
                    obj->x1fc = 15;
                }
            } else {
                lbl_80347790 = 0;
                lbl_80347794 = 0;
                obj->pivotPos.y = 0.5f;
                obj->state = 0;
                obj->x1fc = 0;
                lbl_8034779C = 0;
                lbl_8034777C = 300;
            }
        } else {
            lbl_80347790 = 1;
            if (lbl_80347784 >= 1) {
                fn_801EAA08(task);
            }
            if (obj->x1ec == 0) {
                s16 flag = 0;
                if (lbl_80347794 == 8) {
                    flag = 1;
                }
                if (lbl_80347784 == 1) {
                    EvDrawOverlay(obj, flag);
                }
                if (obj->state == 0) {
                    lbl_80347794 = 0;
                }
            }
        }
        if (obj->x1ed++ >= 45) {
            if ((obj->x1ec < 3 && (!(lbl_80310B3C[32] & 1) || obj->point == 0x11) &&
                 !(lbl_80310B3C[88] & 0x80000000) && (lbl_80310B3C[18] & 0x10) && lbl_80347408 == 0 &&
                 dist <= (f32)obj->ext->info->actDist && busy == 0) ||
                (lbl_80347778 != 0 && dist <= (f32)obj->ext->info->actDist)) {
                fn_801EC854(obj, dist);
            } else {
                if (obj->x21e) {
                    fn_80217830(obj->x23c);
                    obj->x21e = 0;
                }
                if (obj->x21f) {
                    fn_80217830(obj->x240);
                    obj->x21f = 0;
                }
            }
            obj->x1ed = 45;
        }
        if (dist < (f32)obj->ext->info->nearDist || lbl_80347778 == 2) {
            fn_801EAF00(obj);
            fn_80116020(obj->x1ec);
        }
        if (obj->x1ec == 5) {
            u32 f;
            task->state = 0xFF;
            f = obj->ext->info->flag;
            lbl_80310B3C[f >> 5] |= 1 << (f & 31);
        }
        if (lbl_80347778 == 2 && (lbl_80311A60.pad->x8 & 0x100) && lbl_80347784 < 2) {
            lbl_80347784++;
        }
        break;
    case 7:
    case 0xFF:
        lbl_80347794 = 0;
        obj->x1ec = 0;
        v[0] = v[1] = 0.0f;
        fn_80095630(v, 0);
        fn_80116020(0);
        lbl_803477A0 = 0;
        VecSet(&cam->a, 1.0f);
        if (obj->texlist != NULL && obj->texlist->nbTexture != 0) {
            fn_802275A4(obj->texlist, 0);
        }
        if (obj->x21e) {
            fn_80217830(obj->x23c);
            obj->x21e = 0;
        }
        if (obj->x21f) {
            fn_80217830(obj->x240);
            obj->x21f = 0;
        }
    case 8:
        fn_8015EBF4(obj);
        fn_80100B74(task);
        break;
    case 0xFE:
        break;
    }
}

void fn_801E9AE0(Task* self) {
    EvObj* m;
    EvObj* t;
    EvObj* cam;
    s32 i;
    f32* sp;
    f32 dist;
    Angle ang[3];
    NJS_POINT3 a;
    NJS_POINT3 b;
    NJS_POINT3 a2;
    NJS_POINT3 b2;

    if (self->parent->flags & 0x40) {
        self->flags |= 0x40;
        return;
    }
    cam = lbl_80347450;
    t = self->work;
    a.x = cam->pos.x;
    a.y = cam->pos.y;
    a.z = cam->pos.z;
    b.x = t->x24c.x;
    b.y = t->x24c.y;
    b.z = t->x24c.z;
    dist = fn_80290008(&a, &b);
    m = self->work;
    fn_801DD5E8(ang, &lbl_803119E0[1]);
    m->ang[0] = ang[0] - 0x4000;
    m->ang[1] = ang[1];
    m->ang[2] = ang[2];
    m->pos.y = lbl_803139B4[m->point].y + lbl_8031384C[m->point].y;
    m->pos.x = lbl_803139B4[m->point].x + lbl_8031384C[m->point].x;
    m->pos.z = lbl_803139B4[m->point].z + lbl_8031384C[m->point].z;
    if (m->state == 0) {
        for (i = 0, sp = &m->scl.x; i < 3; i++, sp++) {
            *sp += 0.05f;
            if (lbl_80347794 != 0) {
                *sp += 0.05f;
            }
            if (*sp >= 2.0f) {
                m->state = 1;
                *sp = 2.0f;
            }
        }
    } else {
        for (i = 0, sp = &m->scl.x; i < 3; i++, sp++) {
            *sp -= 0.05f;
            if (lbl_80347794 != 0) {
                *sp -= 0.05f;
            }
            if (*sp <= 0.5f) {
                m->state = 0;
                *sp = 0.5f;
            }
        }
    }
    if (lbl_8034779C == 1) {
        m->hidden = 1;
        if (dist < (f32)m->ext->info->actDist) {
            self->flags |= 0x40;
        }
    } else {
        m->hidden = 0;
        if (lbl_80347794 == 0) {
            fn_801E5DF0(m);
        } else {
            a2.x = lbl_80347450->pos.x;
            a2.y = lbl_80347450->pos.y;
            a2.z = lbl_80347450->pos.z;
            b2.x = m->x24c.x;
            b2.y = m->x24c.y;
            b2.z = m->x24c.z;
            dist = fn_80290008(&a2, &b2);
            if (dist < (f32)m->ext->info->nearDist || lbl_80347778 != 0) {
                fn_801E5DF0(m);
            }
        }
    }
}

void fn_801E9EA8(Task* task) {
    EvObj* obj;
    f32 scl;
    f32 rad;
    f32 ang;
    f32 y;
    Angle out[3];

    if (task->parent->flags & 0x40) {
        task->flags |= 0x40;
        return;
    }
    obj = task->work;
    switch (obj->state) {
    case 0:
        scl = 0.5f * (3.0517578125e-05f * fn_8025ECC4()) + 0.01f;
        ang = 0.017453289f * (fn_8025ECC4() % 360);
        rad = 1.8f * (3.0517578125e-05f * fn_8025ECC4());
        y = 5.0f * (3.0517578125e-05f * fn_8025ECC4()) + -3.0f;
        obj->scl.x = scl;
        obj->scl.y = scl;
        obj->scl.z = scl;
        obj->pos.x = lbl_803139B4[obj->point].x + rad * sin(ang);
        obj->pos.z = lbl_803139B4[obj->point].z + rad * cos(ang);
        if (obj->motionId == 0) {
            obj->pos.y = (y + lbl_803139B4[obj->point].y) - 30.0f * (3.0517578125e-05f * fn_8025ECC4());
            obj->motionId = 1;
        } else {
            obj->pos.y = y + lbl_803139B4[obj->point].y;
        }
        obj->colour.a = 255.0f;
        obj->pivotPos.y = 0.2f * (3.0517578125e-05f * fn_8025ECC4()) + 0.1f;
        obj->x172 = fn_8025ECC4() % 8;
        obj->state++;
        break;
    case 1:
        obj->pos.y -= obj->pivotPos.y;
        obj->colour.a -= (f32)(fn_8025ECC4() % 15 + 5);
        if (obj->colour.a <= 0.0f) {
            obj->colour.a = 0.0f;
            obj->state = 0;
            if (lbl_8034779C == 1) {
                obj->state = 2;
            }
        }
        fn_801DD5E8(out, &lbl_803119E0[1]);
        obj->ang[0] = out[0] - 0x4000;
        obj->ang[1] = out[1];
        obj->ang[2] = out[2];
        fn_801E5DF0(obj);
        if (obj->x172 < 4) {
            obj->scl.x += 0.05f;
            obj->scl.y += 0.05f;
            obj->scl.z += 0.05f;
        } else {
            obj->scl.x -= 0.05f;
            obj->scl.y -= 0.05f;
            obj->scl.z -= 0.05f;
        }
        if (obj->x172++ >= 8) {
            obj->x172 = 0;
        }
        break;
    case 2:
        if (lbl_8034779C == 0) {
            obj->state = 0;
        }
        break;
    }
}
