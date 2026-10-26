#include "types.h"
#include "ninja.h"
#include "game/task.h"
#include <math.h>

/* Story-flag event object (0x801E8CA4 - 0x801EA2DC): the event object task fn_801E8CA4 (waits for
 * the player in range of its story flag, runs the flag's event and sets it), its child model
 * object fn_801E9AE0 (a pulsing marker that follows a map point) and the sparkle task
 * fn_801E9EA8 (falling sparks around that point). All three share one model object layout.
 *
 * From 0x801EA2DC to 0x801EE140: the rest of the object's behaviour. fn_801EA2DC is the camera task
 * (flies a marker in on a button press), fn_801EAA08 the marker body task, fn_801EAF00 its
 * message stage, fn_801EB01C the marker task (fades it, projects it to the screen with
 * fn_801EB330 and picks the idle motion), fn_801EBA94 the colour cycle, fn_801EBC5C the state
 * machine that walks and turns the model (the movement choosers fn_801ECA2C, fn_801ED074,
 * fn_801ED69C and fn_801EDAC0 return the next state; fn_801EDF24 and fn_801EE140 pick a
 * walking direction in eighth turns) and fn_801EC854 the looping sound that fades with
 * distance. fn_801EA974 draws a debug line. Several of these are not matched yet. */

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
    u32 x2c;       /* 0x2C */
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
    u8 pad24[0x44 - 0x24];
    NJS_POINT3 target;     /* 0x44 */
    NJS_POINT3 rot;        /* 0x50 */
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
    NJS_POINT3 vel;          /* 0x5C */
    Angle rotv[3];           /* 0x68 */
    s16 x74;                 /* 0x74 */
    u8 pad76[0xB4 - 0x76];
    NJS_POINT3 pivotPos;     /* 0xB4 */
    u8 padC0[0xE4 - 0xC0];
    void* model;             /* 0xE4 */
    NJS_MOTION* motion;      /* 0xE8 */
    void* shape;             /* 0xEC */
    u8 padF0[0x100 - 0xF0];
    NJS_TEXLIST* texlist;    /* 0x100 */
    NJS_POINT3 home;         /* 0x104 */
    Angle tgt[3];            /* 0x110 */
    u8 pad11C[0x164 - 0x11C];
    f32 x164;                /* 0x164 */
    s16 state;               /* 0x168 */
    u8 pad16A[2];
    s16 pivot;               /* 0x16C */
    u8 pad16E[2];
    u16 motionId;            /* 0x170 */
    u16 x172;                /* 0x172 */
    u8 pad174[2];
    u16 id;                  /* 0x176 */
    u8 pad178[8];
    s32 x180;                /* 0x180 */
    s32 hidden;              /* 0x184 */
    u8 pad188[4];
    f32 x18c;                /* 0x18C */
    f32 speed;               /* 0x190 */
    u8 pad194[4];
    s32 x198;                /* 0x198 */
    u8 pad19C[0x1BC - 0x19C];
    void* x1bc;              /* 0x1BC */
    u8 pad1C0[0x1C8 - 0x1C0];
    EvExt* ext;              /* 0x1C8 */
    u8 pad1CC[0x1EC - 0x1CC];
    s8 x1ec;                 /* 0x1EC */
    s8 x1ed;                 /* 0x1ED */
    s8 x1ee;                 /* 0x1EE */
    u8 pad1EF[0x1FC - 0x1EF];
    s16 x1fc;                /* 0x1FC */
    s16 x1fe;                /* 0x1FE */
    s16 x200;                /* 0x200 */
    s16 x202;                /* 0x202 */
    s16 x204;                /* 0x204 */
    s16 x206;                /* 0x206 */
    s16 x208;                /* 0x208 */
    s16 x20a;                /* 0x20A */
    Angle x20c;              /* 0x20C */
    u32 x210;                /* 0x210 */
    u8 pad214[0x21C - 0x214];
    u8 x21c;                 /* 0x21C */
    u8 x21d;                 /* 0x21D */
    u8 x21e;                 /* 0x21E */
    u8 x21f;                 /* 0x21F */
    u8 pad220[0x22C - 0x220];
    u16 x22c;                /* 0x22C frame counter */
    u16 x22e;                /* 0x22E colour key index */
    u16 x230;                /* 0x230 */
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
    NJS_POINT3 d; /* 0x24 */
    NJS_POINT3 e; /* 0x30 */
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
extern Angle lbl_803136E4[30][3];
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
    if (w != NULL && m != w->motionId) {
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

typedef struct {
    f32* in;
    u8* col;
    s32* out;
    s32 n;
} LineArgs;

typedef struct {
    u32 state;  /* 0x00: 2 = finished */
    u32 pad4;
    void* data; /* 0x08 */
} EvMsg;

typedef struct {
    u8 pad0[0x15C8];
    s32 x15c8;
} Global8030CEA0;

typedef struct {
    f32 v[3];
} Col3;

typedef struct {
    Col3 c[7];
} ColKeys;

typedef struct {
    s32 next[7];
} ColNext;

extern EvMsg* lbl_80347788;
extern s32 lbl_80347798;
extern u8 lbl_802C4824[];
extern Global8030CEA0 lbl_8030CEA0;
extern ColKeys lbl_802C47B4;
extern ColNext lbl_802C4808;
extern f32 lbl_802F6810[3];
extern Angle lbl_802F681C[3];
extern NJS_POINT3 lbl_802F6828;
extern f32 fn_80290008(NJS_POINT3* a, NJS_POINT3* b);
extern s32 SePlay(s32 bank, s8 arg1, s8 id);
extern void fn_802AA2F0(LineArgs*, s32, s32);
extern void fn_801EA974(NJS_POINT3* a, NJS_POINT3* b);
extern void fn_801EBC5C(EvObj* obj);
extern void fn_801E3874(EvObj* obj, NJS_POINT3* out, Angle ang);
extern s32 fn_801EB330(EvObj* obj, f32 dist);
extern void fn_801EBA94(EvObj* obj, s32 n);
extern void fn_801C5DEC(EvObj* obj);
extern void fn_80222838(void* p);
extern u32 fn_80222E00(s32 a, void* p);
extern EvMsg* fn_801E1A2C(s32 a, s32 b);
extern void fn_800CD0B8(s32 a, s32 b, s32 c, EvMsg* msg);
extern void fn_800CCF68(s32 a);
extern void fn_801EFF0C(s16 a);
extern void njPushMatrix(void* m);
extern void njProjectScreen(void* m, NJS_POINT3* p, f32* out);
extern void fn_80291E18(s32 n);
extern s32 fn_800E1894(NJS_POINT3* look, EvObj* obj);
extern s32 fn_801C5F84(EvObj* obj);
extern void RotateDirection(Angle* ang, NJS_VECTOR* out, f32 len);
extern u16 fn_801ECA2C(EvObj* obj, s32 force);
extern u16 fn_801ED074(EvObj* obj, s32 force);
extern u16 fn_801ED69C(EvObj* obj, s32 force);
extern u16 fn_801EDAC0(EvObj* obj, s32 force);
extern u8 fn_801EDF24(EvObj* obj, u8 dir);
extern u8 fn_801EE140(EvObj* obj, u8 dir, u8 range);
extern void fn_802172C8(void* p, s8 vol);
extern f32 fn_801C59F8(NJS_POINT3* a, NJS_POINT3* b);
extern void fn_801C588C(NJS_POINT3* from, NJS_POINT3* to, Angle* out);
extern void fn_801C5AB4(EvObj* obj, Angle* out);
extern s32 fn_801C57F4(NJS_POINT3* a, NJS_POINT3* b, f32 r);

/* The event camera state and per-point tables are defined in this file's .bss. */
EvCam lbl_803136A8;
Angle lbl_803136E4[30][3];
NJS_POINT3 lbl_8031384C[30];
NJS_POINT3 lbl_803139B4[30];

inline f32 CamDist(EvObj* obj) {
    NJS_POINT3 b;
    NJS_POINT3 a;
    a.x = lbl_80347450->pos.x;
    a.y = lbl_80347450->pos.y;
    a.z = lbl_80347450->pos.z;
    b.x = obj->x24c.x;
    b.y = obj->x24c.y;
    b.z = obj->x24c.z;
    return fn_80290008(&a, &b);
}

inline void ObjSetIdleMotion(EvObj* w, u16 m, f32 k) {
    if (w != NULL) {
        f32 s = 0.0f;
        if (fn_801C6068(w, 15)) {
            s = (f32)w->ext->info->speed * k;
        }
        w->x164 = s;
        w->x172 = m;
    }
}

inline void VecAdd(NJS_POINT3* a, NJS_POINT3* b) {
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
}

inline void VecSub2(NJS_POINT3* a, NJS_POINT3* b) {
    a->x -= 2.0 * b->x;
    a->y -= 2.0 * b->y;
    a->z -= 2.0 * b->z;
}

inline void VecFade(NJS_POINT3* v) {
    s32 i;
    f32* p;
    for (i = 0, p = &v->x; i < 3; i++, p++) {
        *p -= 0.1f;
        if (*p < 0.0f) {
            *p = 0.0f;
        }
    }
}

inline void EvStart(EvObj* o) {
    o->x202 = 1;
    o->x206 = 0x48;
    o->x1ec = 1;
    o->x1fe = 0;
}

inline f32 Shift(void) {
    return 16384.0f * (5.0f * ((f32)lbl_8034777C / 10.0f) * 0.0078125f) * 0.0078125f;
}

inline void Quadrant(f32* s) {
    if (s[0] <= 320.0f && s[1] <= 270.0f) {
        lbl_80347794 = 3;
    }
    if (s[0] <= 320.0f && s[1] > 270.0f) {
        lbl_80347794 = 4;
    }
    if (s[0] > 320.0f && s[1] <= 270.0f) {
        lbl_80347794 = 5;
    }
    if (s[0] > 320.0f && s[1] > 270.0f) {
        lbl_80347794 = 6;
    }
}

inline void ObjDrawNow(EvObj* w) {
    if (w != NULL) {
        fn_801E5DF0(w);
    }
}

inline void ObjDraw(EvObj* w) {
    if (w != NULL) {
        ObjDrawNow(w);
    }
}

inline s16 Dec(s16 v) {
    if (v > 0) {
        v--;
    }
    return v;
}

inline s16 DecL(s32 v) {
    if (v > 0) {
        v--;
    }
    return v;
}

inline s32 ObjReady(EvObj* w) {
    s32 r = 0;
    if (w != NULL && fn_801C5F84(w) && fn_801C6068(w, 15)) {
        r = 1;
    }
    return r;
}

inline void ObjRotDir(EvObj* w, Angle* ang) {
    if (w != NULL && ang != NULL) {
        RotateDirection(ang, &w->vel, w->x164);
        w->vel.y = 0.0f;
    }
}

inline void ObjFace(EvObj* w, Angle a) {
    if (w != NULL) {
        lbl_802F681C[1] = a;
        ObjRotDir(w, lbl_802F681C);
    }
}

inline s32 ObjMove(EvObj* w) {
    s32 r = 0;
    if (w != NULL) {
        w->pos.x += w->vel.x;
        w->pos.y += w->vel.y;
        w->pos.z += w->vel.z;
        fn_801C5DEC(w);
        r = 1;
    }
    return r;
}

inline void ObjHalt(EvObj* w) {
    if (w != NULL) {
        w->vel.x = 0.0f;
        w->vel.y = 0.0f;
        w->vel.z = 0.0f;
        w->x180 = 15;
    }
}

/* The state machine below (fn_801EBC5C) and the movement choosers use these small object helpers. */
inline void ObjStopIdle(EvObj* w) {
    if (w != NULL) {
        ObjSetMotion(w, w->x172);
        ObjHalt(w);
    }
}

inline void ObjTick(EvObj* w) {
    s16 t;
    if (w != NULL) {
        ObjDraw(w);
        t = DecL(w->x180);
        w->x180 = t;
        if (t <= 0) {
            w->x198 = 0;
        }
    }
}

inline s32 ObjTurnVel(EvObj* w) {
    s32 r = 0;
    if (w != NULL) {
        s16 d = w->tgt[1] - w->ang[1];
        if (d < 0) {
            r = -0x888;
        } else if (d > 0) {
            r = 0x888;
        }
    }
    return r;
}

inline void ObjTurnSet(EvObj* w, s16 a) {
    if (w != NULL) {
        w->rotv[0] = 0;
        w->rotv[1] = 0;
        w->rotv[2] = 0;
        w->vel.x = 0.0f;
        w->vel.y = 0.0f;
        w->vel.z = 0.0f;
        w->ang[1] = (s16)w->ang[1];
        w->tgt[0] = w->ang[0];
        w->tgt[1] = w->ang[1];
        w->tgt[2] = w->ang[2];
        w->tgt[1] = a;
        w->rotv[1] = ObjTurnVel(w);
    }
}

inline void ObjTurnTo(EvObj* w, Angle a) {
    if (w != NULL) {
        ObjTurnSet(w, a);
        ObjSetMotion(w, w->x172);
    }
}

inline s32 ObjTurnStep(EvObj* w) {
    s32 done = 1;
    if (w != NULL) {
        s16 d;
        done = 0;
        w->ang[1] += w->rotv[1];
        d = w->tgt[1] - w->ang[1];
        if ((w->rotv[1] > 0 && d <= 0) || (w->rotv[1] <= 0 && d >= 0)) {
            done = 1;
            w->ang[0] = w->tgt[0];
            w->ang[1] = w->tgt[1];
            w->ang[2] = w->tgt[2];
        }
    }
    return done;
}

inline void ObjTurnDamp(EvObj* w) {
    if (w != NULL && w->rotv[1] != 0) {
        s32 v = w->rotv[1];
        s32 n = (f32)v - 0.016666668f * (f32)v;
        if (n == 0) {
            n = v;
        }
        w->rotv[1] = n;
    }
}

inline s32 ObjTurnUpdate(EvObj* w) {
    s32 done = 1;
    if (w != NULL) {
        done = ObjTurnStep(w);
        fn_801C5DEC(w);
        ObjTurnDamp(w);
        ObjDraw(w);
        if (done) {
            w->speed = 1.0f;
        }
    }
    return done;
}

inline void ObjStop(EvObj* w, u16 m) {
    if (w != NULL) {
        w->vel.x = 0.0f;
        w->vel.y = 0.0f;
        w->vel.z = 0.0f;
        w->home.x = w->pos.x;
        w->home.y = w->pos.y;
        w->home.z = w->pos.z;
        ObjSetMotion(w, m);
    }
}

inline void ObjAngleTo(EvObj* w, Angle* out) {
    if (w != NULL && w->ext != NULL && out != NULL) {
        fn_801C588C(&w->pos, &w->ext->target, out);
    }
}

inline u8 ObjDir8(EvObj* w, s32 ang) {
    Angle cur[3];
    u8 r = 0;

    if (w != NULL) {
        s32 d;
        fn_801C5AB4(w, cur);
        d = (s8)(((ang - cur[1] + 0x1000) / 0x2000) % 8);
        if (d < 0) {
            d += 8;
        }
        r = d;
    }
    return r;
}

inline s32 ObjDirAngle(EvObj* w, u8 d) {
    Angle cur[3];
    s32 r = 0;

    if (w != NULL) {
        fn_801C5AB4(w, cur);
        r = cur[1] + (d << 13);
        r = r % 0x10000;
    }
    return r;
}

inline s32 ObjTargetDir(EvObj* w) {
    Angle a[3];
    s32 r = 0;

    if (w != NULL) {
        ObjAngleTo(w, a);
        r = ObjDir8(w, a[1]);
    }
    return r;
}

inline u16 ObjTurn(EvObj* w, s32 d, u16 stop, u16 next) {
    u16 r = 0x16;

    if (w != NULL) {
        if (d == 8) {
            r = stop;
        } else if (w->x20c != ObjDirAngle(w, d)) {
            w->x20c = ObjDirAngle(w, d);
            w->x21d = next;
            r = 7;
        } else {
            r = next;
        }
    }
    return r;
}

inline s32 ObjNearTarget(EvObj* w) {
    s32 has;
    s32 ok = 1;

    if (w != NULL) {
        ok = has = 0;
        if (fn_801C6068(w, 15) && 0.0f != (f32)w->ext->info->x2c) {
            has = 1;
        }
        if (has && fn_801C59F8(&w->pos, &w->ext->target) >= (f32)w->ext->info->x2c) {
            ok = 1;
        }
    }
    return ok;
}

inline u8 ObjTurnTarget(EvObj* w) {
    u8 r = 8;

    if (w != NULL && w->ext != NULL) {
        r = fn_801EE140(w, ObjTargetDir(w), 1);
    }
    return r;
}

inline u8 ObjWalkTarget(EvObj* w) {
    u8 r = 8;

    if (w != NULL && w->ext != NULL) {
        r = fn_801EDF24(w, ObjTargetDir(w));
    }
    return r;
}

/* Variants used by fn_801ED69C (its direction helper returns u8). */
inline u8 ObjTargetDir8(EvObj* w) {
    Angle a[3];
    s32 r = 0;

    if (w != NULL) {
        ObjAngleTo(w, a);
        r = ObjDir8(w, a[1]);
    }
    return r;
}

inline u8 ObjTurnTarget8(EvObj* w) {
    u8 r = 8;

    if (w != NULL && w->ext != NULL) {
        r = fn_801EE140(w, ObjTargetDir8(w), 1);
    }
    return r;
}

inline u32 DirDiff(u8 a, u8 b) {
    u32 d = fabsf(a - b);
    d %= 8;
    if (d > 4) {
        d = 8 - d;
    }
    return d;
}

inline u8 DirFilter(u8* src, u8* dst, u8 dir, u8 range) {
    s32 i;
    s32 n;

    if (src != NULL && dst != NULL) {
        n = 0;
        for (i = 0; i < 8; i++) {
            if (DirDiff(*src, dir) <= range) {
                dst[n++] = *src;
            }
            src++;
        }
    }
    return n;
}

inline u8 DirPick(u8* list, u8 n) {
    u8 r = 8;
    if (list != NULL) {
        u32 i = (f32)(n + 1) * (3.0517578125e-05f * fn_8025ECC4());
        if (i < n) {
            r = list[i];
        } else {
            r = 8;
        }
    }
    return r;
}

inline s32 ObjTurnDir(EvObj* obj, u8 dir) {
    Angle ang[3];
    s32 ok = 0;
    if (obj != NULL && obj->ext != NULL) {
        fn_801C5AB4(obj, ang);
        ang[1] += dir << 13;
        ok = 1;
    }
    return ok;
}

/* The chooser fn_801EDAC0 and the direction pickers use these forms; they compile differently
 * from VecSet and ObjDirAngle above. */
inline void VecSetEach(NJS_POINT3* p, f32 v) {
    p->x = v;
    p->y = v;
    p->z = v;
}

inline void ObjStopAt(EvObj* obj, u16 m) {
    if (obj != NULL) {
        VecSetEach(&obj->vel, 0.0f);
        VecCopy(&obj->home, &obj->pos);
        ObjSetMotion(obj, m);
    }
}

inline u8 AngleDir(s32 ang) {
    s32 d = (s8)(((ang + 0x1000) / 0x2000) % 8);
    if (d < 0) {
        d += 8;
    }
    return d;
}

inline u8 ObjRelDir(EvObj* obj, s32 ang) {
    Angle a[3];
    u8 d = 0;
    if (obj != NULL) {
        fn_801C5AB4(obj, a);
        d = AngleDir(ang - a[1]);
    }
    return d;
}

inline void ObjAngleToHome(EvObj* obj, Angle* out) {
    if (obj != NULL && obj->ext != NULL && out != NULL) {
        fn_801C588C(&obj->pos, &obj->ext->target, out);
    }
}

inline u8 ObjDirToHome(EvObj* obj) {
    Angle a[3];
    u8 d = 0;
    if (obj != NULL) {
        ObjAngleToHome(obj, a);
        d = ObjRelDir(obj, a[1]);
    }
    return d;
}

inline u8 ObjWalkHomeDir(EvObj* obj) {
    u8 d = 8;
    if (obj != NULL && obj->ext != NULL) {
        d = fn_801EE140(obj, ObjDirToHome(obj), 1);
    }
    return d;
}

inline s32 ObjDirAngleH(EvObj* obj, u8 d) {
    Angle a[3];
    s32 r = 0;
    if (obj != NULL) {
        fn_801C5AB4(obj, a);
        r = (a[1] + (d << 13)) % 0x10000;
    }
    return r;
}

inline u16 ObjStartTurn(EvObj* obj, u8 d, u16 none, u16 same, u8 next) {
    u16 r = 0x16;
    if (obj != NULL) {
        if (d == 8) {
            r = none;
        } else if (obj->x20c != ObjDirAngleH(obj, d)) {
            obj->x20c = ObjDirAngleH(obj, d);
            obj->x21d = next;
            r = 7;
        } else {
            r = same;
        }
    }
    return r;
}

inline s32 ObjAwayFromHome(EvObj* obj) {
    s32 away = 1;
    if (obj != NULL) {
        s32 check = 0;
        away = 0;
        if (fn_801C6068(obj, 0xF) && 0.0f != obj->ext->info->x2c) {
            check = 1;
        }
        if (check && fn_801C59F8(&obj->pos, &obj->ext->target) >= obj->ext->info->x2c) {
            away = 1;
        }
    }
    return away;
}

void fn_801EA2DC(Task* task) {
    EvCam* cam = &lbl_803136A8;
    EvObj* obj;
    f32 dist;
    Angle ang[3];
    s32 i;
    f32* p;
    double r;

    if (task->parent->flags & 0x40) {
        task->flags |= 0x40;
        return;
    }
    obj = task->work;
    dist = CamDist(obj);
    fn_801DD5E8(ang, &lbl_803119E0[1]);
    switch (obj->x202) {
    case 0:
        if (lbl_80347778 == 2) {
            if (lbl_80347784 == 2 && obj->x1ec == 0) {
                obj->x202 = 1;
                SePlay(0, 1, 0x22);
                obj->x1ec = 1;
                lbl_80347794 = 9;
            }
        } else if (lbl_80347440 == 1) {
            if (dist < (f32)obj->ext->info->nearDist && (lbl_80311A60.pad->x8 & 0x100) && lbl_803477A0 == 0 && obj->x1ec == 0) {
                if (lbl_80347794 != 0) {
                    if (lbl_80347794 == 8) {
                        obj->x202 = 1;
                        SePlay(0, 1, 0x22);
                        obj->x1ec = 1;
                        lbl_80347794 = 9;
                    }
                } else {
                    lbl_803477A0 = 1;
                    SePlay(0, 1, 3);
                }
            }
        }
        if (lbl_803477A0 > 0) {
            if (lbl_803477A0++ > 30) {
                lbl_803477A0 = 0;
            }
        }
        break;
    case 1:
        fn_801DD5E8(ang, &lbl_803119E0[1]);
        r = -1.6 * sin(9.587378e-05f * ang[0]);
        cam->e.x = 3.75f * lbl_803119E0[1].x + (lbl_803119E0[0].x + sin(9.587378e-05f * ang[1]) * r);
        cam->e.y = 3.75f * lbl_803119E0[1].y + (lbl_803119E0[0].y + -1.6 * cos(9.587378e-05f * ang[0]));
        r = -1.6 * sin(9.587378e-05f * ang[0]);
        cam->e.z = 3.75f * lbl_803119E0[1].z + (lbl_803119E0[0].z + cos(9.587378e-05f * ang[1]) * r);
        VecCopy(&obj->pos, &cam->e);
        obj->ang[0] = -ang[0];
        obj->ang[1] = ang[1] - 0x8000;
        obj->ang[2] = ang[2];
        cam->d.x = (lbl_803139B4[obj->point].x - lbl_803119E0[0].x) / 10.0f;
        cam->d.z = (lbl_803139B4[obj->point].z - lbl_803119E0[0].z) / 10.0f;
        cam->d.y = (2.5f + lbl_803139B4[obj->point].y - lbl_803119E0[0].y) / 10.0f;
        obj->x206 = 0;
        obj->motionId = 0;
        obj->x202 = 2;
        obj->x204 = 0;
        obj->scl.x = 1.0f;
        obj->scl.y = 1.0f;
        obj->scl.z = 1.0f;
    case 2:
        VecAdd(&obj->pos, &cam->d);
        fn_801EA974(&cam->e, &obj->pos);
        if (obj->x206++ > 9) {
            obj->x202 = 3;
            obj->x206 = 0;
        }
        obj->x18c = 0.0f;
        fn_801E5DF0(obj);
        break;
    case 3:
        if (obj->x204 == 0) {
            ObjSetMotion(obj, 14);
        }
        if (obj->x18c >= (f32)obj->motion->nbFrame - 1.0f) {
            SePlay(0, 1, 0x25);
            obj->x18c = 0.0f;
        }
        for (i = 0, p = &obj->scl.x; i < 3; i++, p++) {
            if (obj->x204 == 0) {
                *p += 0.5f;
                if (*p > 3.5f) {
                    *p = 3.5f;
                    obj->x204 = 1;
                    lbl_8034779C = 1;
                }
            } else {
                *p -= 0.5f;
                if (*p < 1.0f) {
                    *p = 1.0f;
                    obj->x204 = 2;
                    obj->x202 = 4;
                }
            }
        }
        fn_801EA974(&cam->e, &obj->pos);
        fn_801E5DF0(obj);
        break;
    case 4:
        VecSub2(&obj->pos, &cam->d);
        fn_801EA974(&cam->e, &obj->pos);
        if (obj->x206++ >= 4) {
            obj->x202 = 0;
            obj->x206 = 0;
            obj->x1ec = 2;
        }
        obj->x18c = 0.0f;
        fn_801E5DF0(obj);
        break;
    }
}

void fn_801EA974(NJS_POINT3* a, NJS_POINT3* b) {
    f32 in[6];
    u8 col[8];
    s32 out[2];
    LineArgs args;
    args.in = in;
    args.col = col;
    args.out = out;
    args.n = 1;
    in[0] = a->x;
    in[1] = a->y;
    in[2] = a->z;
    in[3] = b->x;
    in[4] = b->y;
    in[5] = b->z;
    col[0] = 0xFF;
    col[1] = 0x80;
    col[2] = 0xFF;
    col[3] = 0xFF;
    fn_802AA2F0(&args, 2, 0x40);
}

void fn_801EAA08(Task* task) {
    EvObj* obj = task->work;
    f32 dist;
    f32 s;
    Angle ang[3];

    dist = CamDist(obj);
    fn_801DD5E8(ang, &lbl_803119E0[1]);
    obj->pos.x = lbl_803119E0[0].x;
    obj->pos.y = lbl_803119E0[0].y - obj->pivotPos.y;
    obj->pos.z = lbl_803119E0[0].z;
    obj->ang[0] = -(ang[0] + (s32)(182.04445f * obj->state));
    obj->ang[1] = ang[1] - 0x8000;
    if (lbl_80347778 != 2) {
        if ((lbl_80311A60.pad->x8 & 0x100) && lbl_80347794 == 8 && obj->x202 != 1 && obj->x1ec == 0 && dist < (f32)obj->ext->info->nearDist) {
            EvStart(obj);
        }
    } else if (lbl_80347784 == 2 && obj->x202 != 1 && obj->x1ec == 0) {
        EvStart(obj);
    }
    if (obj->x202 == 1) {
        s = 0.5 * sin((f32)(3.14 * obj->x206 / 180.0));
        obj->pos.x -= lbl_803119E0[1].x * s;
        obj->pos.y -= lbl_803119E0[1].y * s;
        obj->pos.z -= lbl_803119E0[1].z * s;
        obj->x206 += 0x12;
        if (obj->x206 >= 0xb4) {
            obj->x202 = 0;
            obj->x206 = 0x48;
            VecCopy(&obj->pos, &lbl_803119E0[0]);
            obj->x1ec = 1;
        }
    }
    if (obj->x1ec == 1) {
        if (obj->x1fe++ > obj->x20a + 0x10) {
            obj->x1fe = 0;
            obj->x1ec = 2;
        }
    }
    if (obj->x1ec == 2) {
        s = 0.5 * sin((f32)(3.14 * obj->x206 / 180.0));
        obj->pos.x -= lbl_803119E0[1].x * s;
        obj->pos.y -= lbl_803119E0[1].y * s;
        obj->pos.z -= lbl_803119E0[1].z * s;
        obj->x206 += 0x12;
        if (obj->x206 >= 0xb4) {
            obj->x202 = 0;
            obj->x206 = 0x48;
            VecCopy(&obj->pos, &lbl_803119E0[0]);
            obj->x1ec = 3;
        }
        lbl_80347794 = 9;
    }
    if (obj->x1ec > 2) {
        obj->pivotPos.y += 0.2f;
        if (obj->pivotPos.y >= 2.0f) {
            obj->pivotPos.y = 2.0f;
        }
    } else if (obj->pivotPos.y != 0.0f) {
        obj->pivotPos.y -= 0.2f;
        if (obj->pivotPos.y <= 0.0f) {
            obj->pivotPos.y = 0.0f;
            obj->state = 1;
        }
    }
    if (dist < (f32)obj->ext->info->nearDist) {
        fn_801C5DEC(obj);
        fn_80222838(obj->x1bc);
        if (fn_80222E00(0x2800, obj->x1bc) != 0) {
            lbl_80347798 = 1;
        } else {
            lbl_80347798 = 0;
        }
    } else {
        lbl_80347798 = 0;
    }
    if (dist < (f32)obj->ext->info->nearDist || lbl_80347778 == 2) {
        if (obj != NULL) {
            fn_801E5DF0(obj);
        }
    }
}

void fn_801EAF00(EvObj* obj) {
    switch (obj->x1ec) {
    case 3:
        if (lbl_80347778 != 2) {
            SePlay(4, 1, 11);
            lbl_80347788 = fn_801E1A2C(1, 12);
            lbl_80347788->state = 0;
            lbl_80347788->data = lbl_802C4824;
            lbl_8030CEA0.x15c8 = 1;
            fn_800CD0B8(5, 0, 0, lbl_80347788);
        }
        obj->x1ec = 4;
        break;
    case 4:
        if (lbl_80347778 != 2) {
            if (lbl_80347788->state == 2) {
                fn_800CCF68(5);
                fn_801EFF0C(0x168);
                obj->x1ec = 5;
                lbl_8030CEA0.x15c8 = 0;
                obj->x208 = 1;
            }
        } else {
            obj->x1ec = 5;
            obj->x208 = 1;
        }
        break;
    }
}

void fn_801EB01C(Task* task) {

    EvObj* obj;
    f32 dist;
    s32 far;

    if (task->parent->flags & 0x40) {
        task->flags |= 0x40;
        return;
    }
    obj = task->work;
    dist = CamDist(obj);
    if (lbl_8034779C == 1) {
        if (dist < (f32)obj->ext->info->nearDist || lbl_80347778 == 2) {
            VecFade(&lbl_803136A8.a);
        }
    }
    VecCopy(&obj->scl, &lbl_803136A8.a);
    obj->hidden = lbl_80347440 == 0;
    if (lbl_80347790 == 0) {
        obj->hidden = 1;
    }
    if (lbl_80347778 != 0) {
        obj->hidden = 0;
    }
    fn_801EBC5C(obj);
    fn_801E3874(obj, &lbl_8031384C[obj->point], lbl_803136E4[obj->point][1]);
    if (dist < (f32)obj->ext->info->nearDist) {
        lbl_80347794 = fn_801EB330(obj, dist);
    }
    if (lbl_803477A0 != 0) {
        lbl_80347794 = 0;
    }
    far = 0;
    if (dist > (f32)obj->ext->info->nearDist) {
        far = 1;
        ObjSetIdleMotion(obj, 11, 0.03f);
    } else {
        ObjSetIdleMotion(obj, 12, 0.06f);
    }
    fn_801EBA94(obj, far);
}

s32 fn_801EB330(EvObj* obj, f32 dist) {
    NJS_POINT3* look = lbl_803119E0;
    f32 s[2];
    f32 v[2];
    s32 n;
    s32 st;
    s32 a;
    s32 b;

    njPushMatrix(0);
    njProjectScreen(0, &lbl_803139B4[obj->point], s);
    fn_80291E18(1);
    if (lbl_80347778 == 2 && lbl_80347784 == 1) {
        lbl_80347794 = 8;
    }
    st = lbl_80347794;
    n = st != 0 ? -1 : 0;
    if (lbl_8034779C == 1) {
        n = 0;
    }
    v[0] = v[1] = 0.0f;
    switch (st) {
    case 0:
        obj->x1fc = 0;
        break;
    case 9:
        n = -1;
        break;
    case 7:
        obj->x1fc++;
        if (obj->x1fc < 2) {
            Quadrant(s);
            lbl_8034777C -= 100;
        } else {
            lbl_80347794 = 8;
        }
        break;
    case 1:
        lbl_8034777C = 300;
        lbl_80347794 = 2;
    case 2:
        Quadrant(s);
        break;
    case 3:
        b = 0;
        a = 0;
        if (s[0] < 320.0f) {
            v[1] = Shift();
        } else {
            a = 1;
        }
        if (s[1] < 270.0f) {
            v[0] = Shift();
        }
        if (!(s[1] < 270.0f)) {
            b = 1;
        }
        if (a == 1 && b == 1) {
            lbl_80347794 = 7;
        }
        break;
    case 4:
        b = 0;
        a = 0;
        if (s[0] < 320.0f) {
            v[1] = Shift();
        } else {
            a = 1;
        }
        if (s[1] >= 270.0f) {
            v[0] = -Shift();
        }
        if (!(s[1] >= 270.0f)) {
            b = 1;
        }
        if (a == 1 && b == 1) {
            lbl_80347794 = 7;
        }
        break;
    case 5:
        b = 0;
        a = 0;
        if (s[0] >= 320.0f) {
            v[1] = -Shift();
        } else {
            a = 1;
        }
        if (s[1] < 270.0f) {
            v[0] = Shift();
        }
        if (!(s[1] < 270.0f)) {
            b = 1;
        }
        if (a == 1 && b == 1) {
            lbl_80347794 = 7;
        }
        break;
    case 6:
        b = 0;
        a = 0;
        if (s[0] >= 320.0f) {
            v[1] = -Shift();
        } else {
            a = 1;
        }
        if (s[1] >= 270.0f) {
            v[0] = -Shift();
        }
        if (!(s[1] >= 270.0f)) {
            b = 1;
        }
        if (a == 1 && b == 1) {
            lbl_80347794 = 7;
        }
        break;
    }
    fn_80095630(v, n);
    if (lbl_80347794 != 0) {
        return lbl_80347794;
    }
    if (lbl_80347798 != 0) {
        return 0;
    }
    if (dist > (f32)obj->ext->info->nearDist) {
        return 0;
    }
    if (lbl_80347440 == 0 && lbl_80347778 != 2) {
        return 0;
    }
    if (s[0] > 267.0f && s[0] < 383.0f && s[1] > 218.0f && s[1] < 322.0f) {
        return fn_800E1894(look, obj);
    }
    return 0;
}

void fn_801EBA94(EvObj* obj, s32 n) {
    f32 step[3];
    ColKeys keys = lbl_802C47B4;
    ColNext next = lbl_802C4808;
    s32 i;
    f32 t;

    obj->colour.r = lbl_802F6810[0];
    obj->colour.g = lbl_802F6810[1];
    obj->colour.b = lbl_802F6810[2];
    for (i = 0; i < 3; i++) {
        step[i] = (keys.c[next.next[obj->x22e]].v[i] - keys.c[obj->x22e].v[i]) / (f32)(n * 30 + 30);
        lbl_802F6810[i] += step[i];
        t = keys.c[next.next[obj->x22e]].v[i];
        if (t >= 0.0) {
            if (lbl_802F6810[i] >= t) {
                lbl_802F6810[i] = t;
            }
        } else {
            if (lbl_802F6810[i] <= t) {
                lbl_802F6810[i] = t;
            }
        }
    }
    obj->x22c++;
    if (obj->x22c > n * 30 + 29) {
        obj->x22c = 0;
        obj->x22e++;
        if (obj->x22e > 6) {
            obj->x22e = 0;
        }
    }
}

void fn_801EBC5C(EvObj* obj) {
    s32 moved;

    if ((obj->state != 21 && lbl_80347794 != 0) || obj->x204 == 1) {
        obj->x200 = obj->state;
        obj->state = 21;
        obj->x1ee = obj->motionId;
        ObjSetMotion(obj, 13);
    }
    if (lbl_80347778 != 2 || (lbl_80347778 == 2 && lbl_80347794 != 0)) {
        if (obj != NULL) {
            switch (obj->state) {
            case 0:
            case 1:
                obj->x21d = 22;
                if (ObjReady(obj) == 0) {
                    obj->state = 22;
                    break;
                }
                obj->home.x = obj->pos.x;
                obj->home.y = obj->pos.y;
                obj->home.z = obj->pos.z;
                obj->x1fc = 90;
                obj->x1fe = 300;
                obj->x20c = obj->ang[1];
                obj->state = 2;
            case 2:
                ObjFace(obj, obj->x20c);
                ObjSetMotion(obj, obj->x172);
            case 3:
                obj->state = 3;
                obj->x1fc = Dec(obj->x1fc);
                obj->x1fe = Dec(obj->x1fe);
                obj->state = fn_801ECA2C(obj, ObjMove(obj) == 0);
                if (obj->x1fc <= 0) {
                    obj->x1fc = 90;
                }
                if (obj->x1fe <= 0) {
                    obj->x1fe = 300;
                }
                fn_801E5DF0(obj);
                break;
            case 4:
                ObjStopIdle(obj);
            case 5:
                obj->state = 5;
                obj->x1fe = Dec(obj->x1fe);
                obj->x1fc = Dec(obj->x1fc);
                ObjTick(obj);
                obj->state = 6;
                break;
            case 6:
                obj->x1fe = Dec(obj->x1fe);
                obj->x1fc = Dec(obj->x1fc);
                fn_801E5DF0(obj);
                if (obj->x198 != 0) {
                    obj->state = fn_801ECA2C(obj, 1);
                    if (obj->state != 4) {
                        obj->x1fc = 90;
                    }
                    if (obj->x1fe <= 0) {
                        obj->x1fe = 300;
                    }
                }
                break;
            case 7:
                ObjTurnTo(obj, obj->x20c);
            case 8:
                obj->state = 8;
                if (ObjTurnUpdate(obj)) {
                    obj->state = obj->x21d;
                }
                break;
            case 9:
                ObjFace(obj, obj->x20c);
                ObjSetMotion(obj, obj->x172);
            case 10:
                obj->state = 10;
                obj->x1fc = Dec(obj->x1fc);
                moved = ObjMove(obj);
                obj->state = fn_801EDAC0(obj, moved == 0);
                if (moved && obj->state != 10 && obj->state != 13) {
                    obj->home.x = obj->pos.x;
                    obj->home.y = obj->pos.y;
                    obj->home.z = obj->pos.z;
                }
                if (obj->x1fc <= 0) {
                    obj->x1fc = 90;
                }
                fn_801E5DF0(obj);
                break;
            case 11:
                ObjStopIdle(obj);
            case 12:
                obj->state = 12;
                obj->x1fc = Dec(obj->x1fc);
                ObjTick(obj);
                obj->state = 13;
                break;
            case 13:
                obj->x1fc = Dec(obj->x1fc);
                fn_801E5DF0(obj);
                if (obj->x198 != 0) {
                    obj->state = fn_801EDAC0(obj, 1);
                    if (obj->state != 11) {
                        obj->x1fc = 90;
                    }
                }
                break;
            case 14:
                ObjFace(obj, obj->x20c);
                ObjSetMotion(obj, obj->x172);
            case 15:
                obj->state = 15;
                obj->x1fc = Dec(obj->x1fc);
                moved = ObjMove(obj);
                obj->state = fn_801ED69C(obj, moved == 0);
                if (moved && obj->state != 15 && obj->state != 18) {
                    obj->home.x = obj->pos.x;
                    obj->home.y = obj->pos.y;
                    obj->home.z = obj->pos.z;
                }
                if (obj->x1fc <= 0) {
                    obj->x1fc = 90;
                }
                fn_801E5DF0(obj);
                break;
            case 16:
                ObjStopIdle(obj);
            case 17:
                obj->state = 17;
                obj->x1fc = Dec(obj->x1fc);
                ObjTick(obj);
                obj->state = 18;
                break;
            case 18:
                obj->x1fc = Dec(obj->x1fc);
                fn_801E5DF0(obj);
                if (obj->x198 != 0) {
                    obj->state = fn_801ED69C(obj, 1);
                    if (obj->state != 16) {
                        obj->x1fc = 90;
                    }
                }
                break;
            case 19:
                ObjSetMotion(obj, (s32)obj->x21c);
            case 20:
                obj->state = 20;
                fn_801E5DF0(obj);
                if (obj->x198 != 0) {
                    obj->state = fn_801ED074(obj, 1);
                }
                break;
            case 21:
                fn_801E5DF0(obj);
                if (lbl_80347794 == 0) {
                    obj->x18c = 0.0f;
                    obj->state = obj->x200;
                    ObjSetMotion(obj, obj->x1ee);
                }
                return;
            case 22:
                break;
            }
        }
    } else {
        ObjSetMotion(obj, 12);
        fn_801E5DF0(obj);
    }
    obj->pos.y += 0.1 * sin((f32)(3.14 * obj->x230 / 180.0));
    obj->x230 += 6;
    lbl_803139B4[obj->point].x = obj->pos.x;
    lbl_803139B4[obj->point].y = obj->pos.y;
    lbl_803139B4[obj->point].z = obj->pos.z;
    lbl_803136E4[obj->point][0] = obj->ang[0];
    lbl_803136E4[obj->point][1] = obj->ang[1];
    lbl_803136E4[obj->point][2] = obj->ang[2];
}

void fn_801EC854(EvObj* obj, s32 dist) {
EvInfo* info; f32 p, d, nr, act; s16 v;
    if (dist < (f32)obj->ext->info->nearDist) {
        if (obj->x21e) {
            fn_80217830(obj->x23c);
            obj->x21e = 0;
        }
        if (!obj->x21f) {
            obj->x240 = (void*)SePlay(0, 1, 0x24);
            obj->x21f = 1;
            fn_802172C8(obj->x240, 0x7F);
        }
    } else {
        if (obj->x21f) {
            fn_80217830(obj->x240);
            obj->x21f = 0;
        }
        if (!obj->x21e) {
            obj->x23c = (void*)SePlay(0, 1, 0x23);
            obj->x21e = 1;
        }
        p = 100.0f - (dist - (f32)obj->ext->info->nearDist) * (100.0f / ((f32)obj->ext->info->actDist - (f32)obj->ext->info->nearDist));
        v = 10 * (s32)(p / 10.0f);
        fn_802172C8(obj->x23c, (s8)(s32)(1.27 * v));
    }
}

u16 fn_801ECA2C(EvObj* obj, s32 force) {
    f32 dist;
    u16 ret = 0x16;

    if (obj != NULL) {
        dist = fn_801C59F8(&obj->pos, &obj->home);
        if (obj->x1fc <= 0) {
            u8 m = 0;
            if (3.0517578125e-05f * fn_8025ECC4() < 0.5f) {
                m = obj->x21c;
            }
            if (m) {
                ObjStop(obj, m);
                return 6;
            }
        }
        if (dist >= (f32)obj->ext->info->x2c && ObjNearTarget(obj)) {
            ret = ObjTurn(obj, ObjTurnTarget(obj), 0xB, 9);
        } else if (obj->x1fe <= 0 && 3.0517578125e-05f * fn_8025ECC4() < 0.5f) {
            obj->x1fe = 300;
            ret = ObjTurn(obj, ObjWalkTarget(obj), 0x10, 0xE);
        } else if (force != 0 || dist >= 16.0f) {
            ret = ObjTurn(obj, fn_801EDF24(obj, ObjDir8(obj, obj->x20c)), 4, 2);
        } else {
            ret = obj->state;
        }
    }
    return ret;
}

u16 fn_801ED074(EvObj* obj, s32 force) {
    f32 dist;
    u16 ret = 0x16;

    if (obj != NULL) {
        dist = fn_801C59F8(&obj->pos, &obj->home);
        if (obj->x1fc <= 0) {
            u8 m = 0;
            if (3.0517578125e-05f * fn_8025ECC4() < 0.5f) {
                m = obj->x21c;
            }
            if (m) {
                ObjStop(obj, m);
                return 6;
            }
        }
        if (dist >= 4.0f && ObjNearTarget(obj)) {
            ret = ObjTurn(obj, ObjTurnTarget(obj), 0xB, 9);
        } else if (obj->x1fe <= 0 && 3.0517578125e-05f * fn_8025ECC4() < 0.5f) {
            obj->x1fe = 300;
            ret = ObjTurn(obj, ObjWalkTarget(obj), 0x10, 0xE);
        } else if (force != 0 || dist >= 16.0f) {
            ret = ObjTurn(obj, fn_801EDF24(obj, ObjDir8(obj, obj->x20c)), 4, 2);
        } else {
            ret = obj->state;
        }
    }
    return ret;
}

u16 fn_801ED69C(EvObj* obj, s32 force) {
    f32 dist;
    u16 ret = 0x16;
    Angle a[3];

    if (obj != NULL) {
        dist = fn_801C59F8(&obj->pos, &obj->home);
        if (fn_801C57F4(&obj->pos, &obj->ext->target, 0.5f * obj->x164)) {
            obj->pos.x = obj->ext->target.x;
            obj->pos.y = obj->ext->target.y;
            obj->pos.z = obj->ext->target.z;
            fn_801C5AB4(obj, a);
            obj->x20c = a[1];
            obj->x21d = 0x13;
            return 7;
        }
        if (obj->x1fc <= 0) {
            u8 m = 0;
            if (3.0517578125e-05f * fn_8025ECC4() < 0.5f) {
                m = obj->x21c;
            }
            if (m) {
                ObjStop(obj, m);
                return 0x12;
            }
        }
        if (dist >= 4.0f && ObjNearTarget(obj)) {
            ret = ObjTurn(obj, ObjTurnTarget8(obj), 0xB, 9);
        } else if (force != 0 || dist >= 16.0f) {
            lbl_802F6828.z = obj->x164;
            ObjAngleTo(obj, a);
            obj->x20c = a[1];
            obj->x21d = 0xE;
            return 7;
        } else {
            ret = obj->state;
        }
    }
    return ret;
}

u16 fn_801EDAC0(EvObj* obj, s32 force) {
    f32 dist;
    u8 m;
    u16 r = 0x16;

    if (obj != NULL) {
        dist = fn_801C59F8(&obj->pos, &obj->home);
        if (obj->x1fc <= 0) {
            m = 0;
            if (3.0517578125e-05f * fn_8025ECC4() < 0.5f) {
                m = obj->x21c;
            }
            if (m) {
                ObjStopAt(obj, m);
                return 0xD;
            }
        }
        if (force || dist >= 4.0f) {
            if (ObjAwayFromHome(obj)) {
                r = ObjStartTurn(obj, ObjWalkHomeDir(obj), 0xB, 9, 9);
            } else {
                r = ObjStartTurn(obj, fn_801EDF24(obj, ObjRelDir(obj, obj->x20c)), 4, 2, 2);
            }
        } else {
            r = obj->state;
        }
    }
    return r;
}

u8 fn_801EDF24(EvObj* obj, u8 dir) {
    u8 order[8];
    u8 cand[8];
    u8 n;
    u8 result = 8;

    if (obj != NULL && obj->ext != NULL && dir < 8) {
        order[0] = 0;
        order[1] = 1;
        order[2] = 2;
        order[3] = 3;
        order[4] = 4;
        order[5] = 5;
        order[6] = 6;
        order[7] = 7;
        n = 8;
        if (3.0517578125e-05f * fn_8025ECC4() < 0.9f) {
            n = DirFilter(order, cand, dir, 1);
        }
        result = DirPick(cand, n);
        if (result != 8 && !ObjTurnDir(obj, result)) {
            result = 8;
        }
    }
    return result;
}

u8 fn_801EE140(EvObj* obj, u8 dir, u8 range) {
    u8 order[8];
    u8 cand[8];
    u8 n;
    u8 r;
    u8 result = 8;

    if (obj != NULL && obj->ext != NULL && dir < 8) {
        order[0] = 0;
        order[1] = 1;
        order[2] = 2;
        order[3] = 3;
        order[4] = 4;
        order[5] = 5;
        order[6] = 6;
        order[7] = 7;
        n = DirFilter(order, cand, dir, range);
        r = DirPick(cand, n);
        result = r;
        if (r != 8 && !ObjTurnDir(obj, r)) {
            result = 8;
        }
    }
    return result;
}


typedef struct Ent_801EE324 {
    s8 kind;                /* 0x00 */
    u8 pad1;
    s16 val;                /* 0x02 */
} Ent_801EE324;
typedef struct { s8 stat; u8 pad; s16 val; } StatMod;
typedef struct {
    u8 pad0[0x11];
    u8 f11;
    u8 pad12[6];
    s16 a18;
    s16 a1a;
    StatMod mod;
} TblA;
typedef struct {
    u8 pad0[0x18];
    StatMod mods[4];
    u8 pad28[0];
} TblB;
typedef struct {
    u8 pad0[0x14];
    s16 a14;
    s16 a16;
    u8 pad18[2];
    StatMod mods[1];
    u8 pad1e[6];
} TblC;
typedef struct {
    u8 pad0[0x12];
    StatMod mods[4];
    u8 pad22[6];
} TblD;
/* 0x28 */

extern TblA lbl_802C5790[];
extern TblB lbl_802C6190[];
extern TblB lbl_802C6E10[];
extern TblC lbl_802D7E4C[];
extern TblD lbl_802D83EC[];
extern s32 fn_801F4C24(void);
typedef struct {
    u8 pad0[0x48];
    s16 x48;
    u8 pad4a[2];
    s16 x4c;
    s16 x4e;
    u8 pad50[2];
    s16 x52;
    s16 x54;
    s16 x56;
    s16 x58;
    s16 x5a;
} Chr_801EF054;
typedef struct Char {
    s16 x0;
    u8 pad2[0xb];
    s8 mp;                  /* 0x0d */
    s8 mpMax;
    u8 pad0f;
    s16 slot0;              /* 0x10 */
    s16 slot1;
    s16 slot2;
    u8 pad16[2];
    s16 hp;                 /* 0x18 */
    s16 hpMax;
    u8 pad1c[0xc];
    f32 x28;
    u8 pad2c[0xe];
    s16 s3a;
    s16 s3c;
    s16 s3e;
    s16 s40;
    s16 s42;
    u8 pad44[0x18];
} Char;
/* 0x5c */
typedef struct { s16 id; s8 cnt; u8 pad; } InvEnt;
typedef InvEnt Slot;
typedef struct Game {
    Char chr[8];                /* 0x000 */
    u8 pad2e0[0x328 - 0x2e0];
    s8 party[4];                /* 0x328 */
    u8 pad32c[2];
    s8 x32e;
    s8 x32f;
    s8 x330;
    u8 pad331[0x354 - 0x331];
    Slot s354[0x50];
    Slot s494[0x50];
    Slot s5d4[0x50];
    Slot s714[0x50];
    Slot s854[0x50];
    Slot s994[0x1e];
    Slot sa0c[0x28];
    Slot saac[0x28];
    u8 xb4c;
    u8 padb4d[0x1569 - 0xb4d];
    u8 x1569;
    u8 pad156a[0x12];
    s32 x157c;
    s16 s1580[5];
    s16 s158a[5];
} Game;
extern Game lbl_8030B7F4;
extern s16 fn_801EE344(s16 item, s32 stat);
extern void fn_801EFB74(s16 id, u32 kind);
extern void fn_801EFDC0(s16 id, u32 kind);
extern void* fn_801CC3C4(const char* name);
extern void fn_801E17E0(void* p);
extern void fn_801EF9A8(s32 i);
extern void fn_801F0020(void* p);
extern void fn_801EF7E0(void);
extern void fn_8021BED0(void);
extern void fn_8021B2B4(void);
extern const char lbl_802C4848[];
extern u8 lbl_80313B20[];
extern void* lbl_803474D8;
typedef struct Item {
    u8 pad00[0x12];
    s8 kind;
    u8 flag;
    u8 chance;
    u8 pad15[7];
    s16 amount;
    u8 pad1e[6];
} Item;
typedef struct Cfg {
    u8 pad[0x2dc];
    int limit;
} Cfg;
extern Cfg lbl_8030B4D4;
extern Item lbl_802D8A2C[];
extern Item lbl_802C7C34[];
extern void fn_801EFC88(s16 idx);
extern void fn_801EFFD8(s16 id);
extern void fn_801EFFFC(s16 id);
extern void fn_801F28CC(int);
void fn_801F11C8(int unused, int kind, int idx);
int fn_801F0588(int who, int idx, s8 kind);
int fn_801F039C(int a, s16 kind);
typedef struct Ent_801F11C8 {
    u8 pad0[0x15];
    s8 b15;                 /* 0x15 */
    u8 pad16[0x1C - 0x16];
    s16 s1c;                /* 0x1C */
    u8 pad1E[0x2A - 0x1E];
    s16 s2a;                /* 0x2A */
} Ent_801F11C8;
typedef struct Big {
    u8 pad0[0x157C];
    s32 c;                  /* 0x157C */
} Big;
typedef struct Sm {
    u8 pad0[0x18];
    s16 cur;                /* 0x18 */
    s16 max;                /* 0x1A */
} Sm;
extern u8 lbl_802C4BF0[];
typedef struct Entry {
    u8 f0; s8 f1; s8 f2; u8 pad3; s16 f4; s16 id; s16 f8; u8 padA[2]; void *p1c; void *p20;
} Entry;
typedef struct Menu {
    s32 chr;       /* 0x00 */
    s32 mode;      /* 0x04 */
    s8 x8;
    u8 x9;
    u8 xa;
    u8 padb[5];
    Entry e[6];    /* 0x10 */
} Menu;
extern s32 fn_801F3FD0(s32, s16);
extern void fn_801F1590(Menu *, Slot *, s32, s32);
typedef struct Cur {
    u8 pad0[0x10];
    u8 f0; s8 f1; s8 f2; u8 pad3; s16 f4; s16 id; s16 f8; u8 padA[2]; void *p1c; void *p20;
} Cur;
extern void *fn_801F4AE4(s16);
extern void *fn_801F48AC(s16);
extern void fn_801F1F80(Menu *, Slot *, s32, s32);

s32 fn_801EE324(Ent_801EE324* e, s32 key) {
    s32 r = 0;
    if (e->kind == key) {
        r = e->val;
    }
    return r;
}

s16 fn_801EE344(s16 id, s32 stat) {
    s16 total = 0;
    s32 i = 0;
    s32 r = fn_801F4C24();
    switch (r) {
    case 0: {
        StatMod* m = &lbl_802C5790[id].mod;
        if (m->stat == stat) total = m->val;
        if (stat == 0x10) total += lbl_802C5790[id].a18;
        if (stat == 0x13) total += lbl_802C5790[id].a1a;
        break;
    }
    case 1: {
        StatMod* m = lbl_802C6190[id - 0x50].mods;
        do {
            if (m->stat == stat) total += m->val;
            i++;
            m++;
        } while (i < 4);
        break;
    }
    case 2: {
        StatMod* m = lbl_802C6E10[id - 0xa0].mods;
        do {
            if (m->stat == stat) total += m->val;
            i++;
            m++;
        } while (i < 4);
        break;
    }
    case 5: {
        StatMod* m = lbl_802D7E4C[id - 0x190].mods;
        do {
            if (m->stat == stat) total += m->val;
            i++;
            m++;
        } while (i < 1);
        if (stat == 0x10) total += lbl_802D7E4C[id - 0x190].a14;
        if (stat == 0x13) total += lbl_802D7E4C[id - 0x190].a16;
        break;
    }
    case 6: {
        StatMod* m = lbl_802D83EC[id - 0x1b8].mods;
        do {
            if (m->stat == stat) total += m->val;
            i++;
            m++;
        } while (i < 4);
        break;
    }
    default:
        break;
    }
    return total;
}

s8 fn_801EF000(s16 id, s32 stat) {
    s8 r = -1;
    StatMod* m = lbl_802C6E10[id - 0xa0].mods;
    s32 i = 0;
    do {
        if (m->stat == stat) {
            r = m->val;
            break;
        }
        i++;
        m++;
    } while (i < 4);
    return r;
}

void fn_801EF054(Chr_801EF054 *p, s32 idx)
{
    s16 sum = 0;

    p->x52 = p->x48;
    if (lbl_8030B7F4.chr[idx].slot0 != -1) {
        sum = (s16)(fn_801EE344(lbl_8030B7F4.chr[idx].slot0, 0x10));
    }
    if (lbl_8030B7F4.chr[idx].slot1 != -1) {
        sum = sum + fn_801EE344(lbl_8030B7F4.chr[idx].slot1, 0x10);
    }
    if (lbl_8030B7F4.chr[idx].slot2 != -1) {
        sum = sum + fn_801EE344(lbl_8030B7F4.chr[idx].slot2, 0x10);
    }
    p->x52 += sum;
    if (p->x52 > 999) {
        p->x52 = 999;
    }

    p->x54 = p->x4c;
    sum = 0;
    if (lbl_8030B7F4.chr[idx].slot0 != -1) {
        sum = (s16)(fn_801EE344(lbl_8030B7F4.chr[idx].slot0, 0x11));
    }
    if (lbl_8030B7F4.chr[idx].slot1 != -1) {
        sum = sum + fn_801EE344(lbl_8030B7F4.chr[idx].slot1, 0x11);
    }
    if (lbl_8030B7F4.chr[idx].slot2 != -1) {
        sum = sum + fn_801EE344(lbl_8030B7F4.chr[idx].slot2, 0x11);
    }
    p->x54 += sum;
    if (p->x54 > 999) {
        p->x54 = 999;
    }

    p->x56 = p->x4c;
    sum = 0;
    if (lbl_8030B7F4.chr[idx].slot0 != -1) {
        sum = (s16)(fn_801EE344(lbl_8030B7F4.chr[idx].slot0, 0x12));
    }
    if (lbl_8030B7F4.chr[idx].slot1 != -1) {
        sum = sum + fn_801EE344(lbl_8030B7F4.chr[idx].slot1, 0x12);
    }
    if (lbl_8030B7F4.chr[idx].slot2 != -1) {
        sum = sum + fn_801EE344(lbl_8030B7F4.chr[idx].slot2, 0x12);
    }
    p->x56 += sum;
    if (p->x56 > 999) {
        p->x56 = 999;
    }

    sum = 0;
    if (lbl_8030B7F4.chr[idx].slot0 != -1) {
        sum = (s16)(fn_801EE344(lbl_8030B7F4.chr[idx].slot0, 0x13));
    }
    if (lbl_8030B7F4.chr[idx].slot1 != -1) {
        sum = sum + fn_801EE344(lbl_8030B7F4.chr[idx].slot1, 0x13);
    }
    if (lbl_8030B7F4.chr[idx].slot2 != -1) {
        sum = sum + fn_801EE344(lbl_8030B7F4.chr[idx].slot2, 0x13);
    }
    p->x58 = sum;
    if (p->x58 > 999) {
        p->x58 = 999;
    }

    p->x5a = p->x4e;
    sum = 0;
    if (lbl_8030B7F4.chr[idx].slot0 != -1) {
        sum = (s16)(fn_801EE344(lbl_8030B7F4.chr[idx].slot0, 0x14));
    }
    if (lbl_8030B7F4.chr[idx].slot1 != -1) {
        sum = sum + fn_801EE344(lbl_8030B7F4.chr[idx].slot1, 0x14);
    }
    if (lbl_8030B7F4.chr[idx].slot2 != -1) {
        sum = sum + fn_801EE344(lbl_8030B7F4.chr[idx].slot2, 0x14);
    }
    p->x5a += sum;
    if (p->x5a > 999) {
        p->x5a = 999;
    }
}

void fn_801EFB74(s16 id, u32 kind)
{
    InvEnt *tbl;
    InvEnt *p;
    s32 i;
    s32 n;

    switch (kind) {
    case 0: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x354); n = 0x50; break;
    case 1: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x494); n = 0x50; break;
    case 2: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x5d4); n = 0x50; break;
    case 3: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x714); n = 0x50; break;
    case 4: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x854); n = 0x50; break;
    case 5: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0xa0c); n = 0x28; break;
    case 6: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0xaac); n = 0x28; break;
    case 7: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x994); n = 0x1e; break;
    }
    p = tbl;
    i = 0;
    do {
        if (id == p->id) {
            tbl[i].cnt--;
            if (tbl[i].cnt <= 0) {
                tbl[i].id = -1;
            }
            return;
        }
        i++;
        p++;
    } while (i < n);
}

void fn_801EFC88(s16 p) {
    s32 v = fn_801F4C24();
    fn_801EFB74(p, v);
}

s8 fn_801EFCC4(s16 id, u32 kind)
{
    InvEnt *tbl;
    InvEnt *p;
    s32 i;
    s32 n;

    switch (kind) {
    case 0: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x354); n = 0x50; break;
    case 1: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x494); n = 0x50; break;
    case 2: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x5d4); n = 0x50; break;
    case 3: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x714); n = 0x50; break;
    case 4: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x854); n = 0x50; break;
    case 5: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0xa0c); n = 0x28; break;
    case 6: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0xaac); n = 0x28; break;
    case 7: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x994); n = 0x1e; break;
    }
    p = tbl;
    i = 0;
    do {
        if (id == p->id) {
            return tbl[i].cnt;
        }
        i++;
        p++;
    } while (i < n);
    return 0;
}

void fn_801EFDC0(s16 id, u32 kind)
{
    InvEnt *tbl;
    InvEnt *p;
    s32 i;
    s32 n;

    switch (kind) {
    case 0: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x354); n = 0x50; break;
    case 1: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x494); n = 0x50; break;
    case 2: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x5d4); n = 0x50; break;
    case 3: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x714); n = 0x50; break;
    case 4: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x854); n = 0x50; break;
    case 5: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0xa0c); n = 0x28; break;
    case 6: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0xaac); n = 0x28; break;
    case 7: tbl = (InvEnt *)((u8 *)&lbl_8030B7F4 + 0x994); n = 0x1e; break;
    }
    p = tbl;
    i = 0;
    do {
        if (id == p->id) {
            if (tbl[i].cnt < 99) {
                tbl[i].cnt++;
            }
            return;
        }
        i++;
        p++;
    } while (i < n);
    i = 0;
    p = tbl;
    do {
        if (p->id == -1) {
            tbl[i].id = id;
            tbl[i].cnt = 1;
            return;
        }
        i++;
        p++;
    } while (i < n);
}

void fn_801EFF0C(s16 p) {
    s32 v = fn_801F4C24();
    fn_801EFDC0(p, v);
}

void fn_801EFF48(s16 p) {
    fn_801EFB74(p, 2);
}

void fn_801EFF6C(s16 p) {
    fn_801EFDC0(p, 2);
}

void fn_801EFF90(s16 p) {
    fn_801EFB74(p, 1);
}

void fn_801EFFB4(s16 p) {
    fn_801EFDC0(p, 1);
}

void fn_801EFFD8(s16 p) {
    fn_801EFB74(p, 0);
}

void fn_801EFFFC(s16 p) {
    fn_801EFDC0(p, 0);
}

void fn_801F01E4(void) {
    void* buf = fn_801CC3C4(lbl_802C4848);
    MemCopy(lbl_80313B20, buf, 0xB74);
    lbl_803474D8 = lbl_80313B20;
    fn_801E17E0(buf);
    {
        s32 i;
        for (i = 0; i < 6; i++) {
            fn_801EF9A8(i);
        }
    }
    fn_801F0020((u8 *)&lbl_8030B7F4 + 0x328);
    fn_801F0020((u8 *)&lbl_8030B7F4 + 0xC48);
    fn_8021BED0();
    fn_801EF7E0();
    fn_8021B2B4();
}

int fn_801F0284(int a, int who, int kind, int idx, int all)
{
    switch (kind) {
    case 0: {
        int i;
        lbl_8030B7F4.chr[a].mp--;
        if (all == 1) {
            fn_801F11C8(a, who, idx);
        } else {
            for (i = 0; i < 4; i++) {
                int id = lbl_8030B7F4.party[i];
                if (id != -1) {
                    fn_801F11C8(a, id, idx);
                }
            }
        }
        break;
    }
    case 1: {
        Item *it = &lbl_802C7C34[idx - 0xf0];
        fn_801F0588(who, idx, it->kind);
        break;
    }
    case 5: {
        Item *it = &lbl_802D8A2C[idx - 0x1e0];
        fn_801F039C(idx, (u8)it->kind);
        break;
    }
    }
    return 1;
}

static inline void ItemChance(s16 idx)
{
    if (idx >= 0x1e0 && idx <= 0x1fd) {
        s8 chance = lbl_802D8A2C[idx - 0x1e0].chance;
        if (chance != 0 && chance > fn_8025ECC4() % 100) {
            fn_801EFC88(idx);
        }
    }
}

int fn_801F039C(int a, s16 kind)
{
    Item *it = &lbl_802D8A2C[a - 0x1e0];
    Game *g = &lbl_8030B7F4;
    Cfg *cfg = &lbl_8030B4D4;

    switch (kind) {
    case 0x64:
        g->x157c += it->amount * 10;
        if (g->x157c > cfg->limit) {
            g->x157c = cfg->limit;
        }
        ItemChance(a);
        break;
    case 0x65:
        g->x157c = cfg->limit;
        ItemChance(a);
        break;
    case 0x73:
        g->x1569++;
        fn_8021B2B4();
        ItemChance(a);
        break;
    }
    fn_801EF7E0();
    return 1;
}

static inline void ItemChanceB(s16 idx)
{
    if (idx >= 0xf0 && idx < 0x140) {
        s8 chance = lbl_802C7C34[idx - 0xf0].chance;
        if (chance != 0 && chance > fn_8025ECC4() % 100) {
            fn_801EFC88(idx);
        }
    }
}

static inline void ApplyHp(Char *c, Item *it)
{
    switch (it->kind) {
    case 0x1f:
    case 0x32:
        c->hp += it->amount;
        if (c->hp > c->hpMax) {
            c->hp = c->hpMax;
        }
        break;
    case 0x20:
    case 0x33:
        c->hp = c->hpMax;
        break;
    }
}

static inline void ApplyMp(Char *c, Item *it)
{
    switch (it->kind) {
    case 0x30:
    case 0x32:
        c->mp += it->amount;
        if (c->mp > c->mpMax) {
            c->mp = c->mpMax;
        }
        break;
    case 0x31:
    case 0x33:
        c->mp = c->mpMax;
        break;
    }
}

int fn_801F0588(int who, int idx, s8 kind)
{
    Item *it = &lbl_802C7C34[idx - 0xf0];
    Game *g = &lbl_8030B7F4;
    Char *c = &g->chr[who];
    int flag = it->flag;
    int i;

    switch (kind) {
    case 0x1f:
    case 0x20:
        if (flag == 1) {
            ApplyHp(c, it);
        } else {
            for (i = 0; i < 4; i++) {
                int id = lbl_8030B7F4.party[i];
                if (id != -1) {
                    ApplyHp(&lbl_8030B7F4.chr[id], it);
                }
            }
        }
        ItemChanceB(idx);
        break;
    case 0x30:
    case 0x31:
        if (flag == 1) {
            ApplyMp(c, it);
        } else {
            for (i = 0; i < 4; i++) {
                int id = lbl_8030B7F4.party[i];
                if (id != -1) {
                    ApplyMp(&lbl_8030B7F4.chr[id], it);
                }
            }
        }
        ItemChanceB(idx);
        break;
    case 0x32:
    case 0x33:
        if (flag == 1) {
            ApplyHp(c, it);
            ApplyMp(c, it);
        } else {
            for (i = 0; i < 4; i++) {
                int id = lbl_8030B7F4.party[i];
                if (id != -1) {
                    ApplyHp(&lbl_8030B7F4.chr[id], it);
                    ApplyMp(&lbl_8030B7F4.chr[id], it);
                }
            }
        }
        ItemChanceB(idx);
        break;
    case 0x36:
        c->s3a += it->amount;
        if (c->s3a > 999) {
            c->s3a = 999;
        }
        ItemChanceB(idx);
        break;
    case 0x37:
        c->s3c += it->amount;
        if (c->s3c > 999) {
            c->s3c = 999;
        }
        ItemChanceB(idx);
        break;
    case 0x38:
        c->s3e += it->amount;
        if (c->s3e > 999) {
            c->s3e = 999;
        }
        ItemChanceB(idx);
        break;
    case 0x39:
        c->s40 += it->amount;
        if (c->s40 > 999) {
            c->s40 = 999;
        }
        ItemChanceB(idx);
        break;
    case 0x3a:
        c->s42 += it->amount;
        if (c->s42 > 999) {
            c->s42 = 999;
        }
        ItemChanceB(idx);
        break;
    case 0x3b:
        c->hpMax += it->amount;
        if (c->hpMax > 9999) {
            c->hpMax = 9999;
        }
        ItemChanceB(idx);
        break;
    case 0x3c:
        c->mpMax += it->amount;
        c->x28 += it->amount;
        if (c->mpMax > 99) {
            c->mpMax = 99;
            c->x28 = 99.0f;
        }
        ItemChanceB(idx);
        break;
    case 0x35:
        g->x330++;
        ItemChanceB(idx);
        fn_801F28CC(0x103);
        lbl_8030B7F4.xb4c = 1;
        break;
    case 0x4b:
        g->x32f++;
        ItemChanceB(idx);
        fn_801F28CC(0x121);
        lbl_8030B7F4.xb4c = 2;
        break;
    case 0x4c: {
        int n = g->x330;
        for (i = 0; i < n; i++) {
            fn_801EFDC0(0x103, 3);
        }
        n = lbl_8030B7F4.x32f;
        for (i = 0; i < n; i++) {
            fn_801EFDC0(0x121, 3);
        }
        g->x330 = 0;
        lbl_8030B7F4.x32f = 0;
        lbl_8030B7F4.x32e = 0x20;
        fn_801EFFD8(lbl_8030B7F4.chr[2].slot0);
        fn_801EFFFC(0x20);
        lbl_8030B7F4.chr[2].slot0 = 0x20;
        lbl_8030B7F4.xb4c = 3;
        ItemChanceB(idx);
        break;
    }
    default:
        return 0;
    }
    fn_801EF7E0();
    return 1;
}

void fn_801F11C8(int unused, int kind, int idx) {
    Ent_801F11C8* e = (Ent_801F11C8*)(lbl_802C4BF0 + idx * 0x30);
    if (kind == 6) {
        Big* big = (Big*)&lbl_8030B7F4;
        Cfg* oth = &lbl_8030B4D4;
        if (e->b15 == 0x1F) {
            s32 t = big->c + e->s2a * 10;
            big->c = t;
            if (t > oth->limit) {
                big->c = oth->limit;
            }
        } else {
            big->c = oth->limit;
        }
    } else {
        Sm* sm = (Sm*)((u8*)&lbl_8030B7F4 + kind * 0x5C);
        if (e->b15 == 0x1F) {
            sm->cur = sm->cur + e->s1c;
            if (sm->cur > sm->max) {
                sm->cur = sm->max;
            }
        } else {
            sm->cur = sm->max;
        }
    }
}

static inline s32 has_s354(s32 chr)
{
    s32 i;
    for (i = 0; i < 80; i++) {
        if (lbl_8030B7F4.s354[i].id != -1 && fn_801F3FD0(chr, lbl_8030B7F4.s354[i].id) == 2) return 1;
    }
    return 0;
}

static inline s32 has_s494(s32 chr)
{
    s32 i;
    for (i = 0; i < 80; i++) {
        if (lbl_8030B7F4.s494[i].id != -1 && fn_801F3FD0(chr, lbl_8030B7F4.s494[i].id) == 2) return 1;
    }
    return 0;
}

static inline s32 has_s5d4(s32 chr)
{
    s32 i;
    for (i = 0; i < 80; i++) {
        if (lbl_8030B7F4.s5d4[i].id != -1 && fn_801F3FD0(chr, lbl_8030B7F4.s5d4[i].id) == 2) return 1;
    }
    return 0;
}

static inline s32 has_sa0c(s32 chr)
{
    s32 i;
    for (i = 0; i < 40; i++) {
        if (lbl_8030B7F4.sa0c[i].id != -1 && fn_801F3FD0(chr, lbl_8030B7F4.sa0c[i].id) == 2) return 1;
    }
    return 0;
}

static inline s32 has_saac(s32 chr)
{
    s32 i;
    for (i = 0; i < 40; i++) {
        if (lbl_8030B7F4.saac[i].id != -1 && fn_801F3FD0(chr, lbl_8030B7F4.saac[i].id) == 2) return 1;
    }
    return 0;
}

void fn_801F1280(Menu *m)
{
    s32 mode;
    s32 chr;
    s32 i;

    m->xa = 0;
    mode = m->mode;
    chr = m->chr;
    for (i = 0; i < 6; i++) {
        m->e[i].id = -1;
        m->e[i].f0 = 0;
        m->e[i].p1c = 0;
        m->e[i].p20 = 0;
    }
    switch (mode) {
    case 1:
        if (!has_s354(chr)) { m->mode = -1; break; }
        fn_801F1590(m, lbl_8030B7F4.s354, 80, mode);
        break;
    case 2:
        if (!has_s494(chr)) { m->mode = -1; break; }
        fn_801F1590(m, lbl_8030B7F4.s494, 80, mode);
        break;
    case 3:
        if (!has_s5d4(chr)) { m->mode = -1; break; }
        fn_801F1590(m, lbl_8030B7F4.s5d4, 80, mode);
        break;
    case 6:
        if (!has_sa0c(chr)) { m->mode = -1; break; }
        fn_801F1590(m, lbl_8030B7F4.sa0c, 40, mode);
        break;
    case 7:
        if (!has_saac(chr)) { m->mode = -1; break; }
        fn_801F1590(m, lbl_8030B7F4.saac, 40, mode);
        break;
    }
}

void fn_801F1590(Menu *m, Slot *arr, s32 n, s32 mode)
{
    Cur *e;
    s16 *pa;
    s16 *pc;
    s16 *pd;
    s16 *pb;
    s16 *pe;
    s32 id;
    s32 i;
    s32 k;
    s32 cnt;
    s32 chr;

    e = (Cur *)m;
    cnt = 0;
    k = 0;
    i = 0;
    chr = m->chr;
    pa = &lbl_8030B7F4.chr[chr].slot0;
    pb = &lbl_8030B7F4.s1580[chr];
    pc = &lbl_8030B7F4.chr[chr].slot1;
    pd = &lbl_8030B7F4.chr[chr].slot2;
    pe = &lbl_8030B7F4.s158a[chr];
    for (; i < n; arr++, i++) {
        id = arr->id;
        if (id == -1) continue;
        if (fn_801F3FD0(chr, id) != 2) continue;
        if (m->x8 * 6 <= k && cnt < 6) {
            e->id = id;
            e->f0 = 1;
            e->f1 = -2;
            e->p1c = fn_801F4AE4(id);
            e->p20 = fn_801F48AC(id);
            switch (mode) {
            case 1:
                if (id == *pa) e->f1 = -1;
                e->f2 = lbl_802C5790[id].f11;
                break;
            case 2:
                if (id == *pc) e->f1 = -1;
                break;
            case 3:
                if (id == *pd) e->f1 = -1;
                break;
            case 6:
                if (*pb == id) e->f1 = -1;
                break;
            case 7:
                if (*pe == id) e->f1 = -1;
                break;
            }
            e = (Cur *)((u8 *)e + 0x14);
            cnt++;
        }
        k++;
    }
    i = k / 6;
    if (k % 6 != 0) i++;
    m->x9 = i;
}

static inline s32 has_s714(void)
{
    s32 i;
    for (i = 0; i < 80; i++) {
        if (lbl_8030B7F4.s714[i].id != -1) return 1;
    }
    return 0;
}

static inline s32 has2_s354(void)
{
    s32 i;
    for (i = 0; i < 80; i++) {
        if (lbl_8030B7F4.s354[i].id != -1) return 1;
    }
    return 0;
}

static inline s32 has2_s494(void)
{
    s32 i;
    for (i = 0; i < 80; i++) {
        if (lbl_8030B7F4.s494[i].id != -1) return 1;
    }
    return 0;
}

static inline s32 has2_s5d4(void)
{
    s32 i;
    for (i = 0; i < 80; i++) {
        if (lbl_8030B7F4.s5d4[i].id != -1) return 1;
    }
    return 0;
}

static inline s32 has_s994(void)
{
    s32 i;
    for (i = 0; i < 110; i++) {
        if (lbl_8030B7F4.s994[i].id != -1) return 1;
    }
    return 0;
}

static inline s32 has_s854(void)
{
    s32 i;
    for (i = 0; i < 80; i++) {
        if (lbl_8030B7F4.s854[i].id != -1) return 1;
    }
    return 0;
}

void fn_801F1774(Menu *m)
{
    s32 i;
    s32 mode;

    m->xa = 0;
    mode = m->mode;
    for (i = 0; i < 6; i++) {
        m->e[i].id = -1;
        m->e[i].f0 = 0;
        m->e[i].p1c = 0;
        m->e[i].p20 = 0;
    }
    switch (mode) {
    case 0:
        if (!has_s714()) { m->mode = -1; break; }
        fn_801F1F80(m, lbl_8030B7F4.s714, 80, mode);
        break;
    case 1:
        if (!has2_s354()) { m->mode = -1; break; }
        fn_801F1F80(m, lbl_8030B7F4.s354, 80, mode);
        break;
    case 2:
        if (!has2_s494()) { m->mode = -1; break; }
        fn_801F1F80(m, lbl_8030B7F4.s494, 80, mode);
        break;
    case 3:
        if (!has2_s5d4()) { m->mode = -1; break; }
        fn_801F1F80(m, lbl_8030B7F4.s5d4, 80, mode);
        break;
    case 4:
        if (!has_s994()) { m->mode = -1; break; }
        fn_801F1F80(m, lbl_8030B7F4.s994, 110, mode);
        break;
    case 5:
        if (!has_s854()) { m->mode = -1; break; }
        fn_801F1F80(m, lbl_8030B7F4.s854, 80, mode);
        break;
    }
}
