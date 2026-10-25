#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"

/* Game model objects: draw state setup, transform, motion playback and draw
 * (fn_801E4C2C .. fn_801E5F8C). */

/* Only nbFrame is used here; see motion.c for the field meanings. */
typedef struct NJS_MOTION {
    void** mdata;
    u32 nbFrame;
    u16 type;
    u16 inp_fn;
} NJS_MOTION;

typedef struct {
    f32 x, y;
} NJS_POINT2;

/* Ninja NJS_POINT2COL: a 2D polygon with per-vertex colours. */
typedef struct {
    NJS_POINT2* p;
    u32* col;
    NJS_POINT2* tex;
    u32 num;
} NJS_POINT2COL;

/* Frame-stepped value table (e.g. texture animation): value = table[index], stepping index by
 * step every delay ticks. */
typedef struct {
    s16 value;  /* 0x00 current value, table[index] */
    s16 count;  /* 0x02 */
    s32* table; /* 0x04 */
    s32 done;   /* 0x08 set when index wraps */
    s16 index;  /* 0x0C */
    s16 timer;  /* 0x0E ticks left */
    s16 delay;  /* 0x10 ticks per step */
    s16 step;   /* 0x12 */
} FrameAnim;

typedef struct {
    s32 size;
    u8 pad4[0x10];
    s32 flags; /* 0x14, valid when size > 4 */
} ModelExtInfo;

typedef struct {
    u8 pad0[0x10];
    ModelExtInfo* info; /* 0x10 */
} ModelExt;

typedef struct {
    u8 pad0[4];
    s32 kind;                /* 0x04 */
    s32 lit;                 /* 0x08 1 = njControl3D 0x40 on */
    u8 padC[8];
    u32 attr_and;            /* 0x14 */
    u32 attr_or;             /* 0x18 */
    NJS_ARGB colour;         /* 0x1C; alpha <= -1 means not drawn */
    s32 fog;                 /* 0x2C */
    s32 blend_src;           /* 0x30 */
    s32 blend_dst;           /* 0x34 */
    NJS_POINT3 pos;          /* 0x38 */
    Angle ang[3];            /* 0x44 */
    NJS_POINT3 scl;          /* 0x50 */
    u8 pad5C[0xB4 - 0x5C];
    NJS_POINT3 pivotPos;     /* 0xB4 offset when pivoting */
    Angle pivotAng[3];       /* 0xC0 */
    u8 padCC[0xE4 - 0xCC];
    void* model;             /* 0xE4 */
    NJS_MOTION* motion;      /* 0xE8 */
    void* shape;             /* 0xEC */
    NJS_MOTION* motion2;     /* 0xF0 blend source motion */
    u32 shapeArg;            /* 0xF4 */
    u8 padF8[0x100 - 0xF8];
    NJS_TEXLIST* texlist;    /* 0x100 */
    u8 pad104[0x16C - 0x104];
    s16 pivot;               /* 0x16C */
    s16 rotOrder;            /* 0x16E */
    u8 pad170[0x176 - 0x170];
    u16 id;                  /* 0x176 */
    u8 pad178[2];
    u16 id2;                 /* 0x17A */
    u8 pad17C[0x184 - 0x17C];
    s32 hidden;              /* 0x184 */
    u8 pad188[4];
    f32 frame;               /* 0x18C */
    f32 speed;               /* 0x190 */
    u8 pad194[4];
    s32 looped;              /* 0x198 */
    s32 blendDone;           /* 0x19C */
    f32 frame2;              /* 0x1A0 */
    f32 blend;               /* 0x1A4 */
    f32 blendSpeed;          /* 0x1A8 */
    u8 pad1AC[0x1B0 - 0x1AC];
    FrameAnim* anim;         /* 0x1B0 */
    u8 pad1B4[0x1C8 - 0x1B4];
    ModelExt* ext;           /* 0x1C8 */
} ModelObj;

typedef struct {
    NJS_MOTION* motion2;
    NJS_MOTION* motion;
    f32 frame2;
    f32 frame;
} MotionBlend;

typedef struct {
    u32 arg;
    void* shape;
    f32 frame2;
    f32 frame;
} ShapeBlend;

typedef struct {
    s32 map;
    s32 unk4;
    char room;
} MapInfo;

extern s32 lbl_80313698[3];
extern f32 lbl_802F67C0[];
extern void* lbl_80347770;
extern s32 lbl_80347530;
extern s32 lbl_80347540;
extern NJS_ARGB lbl_8030E820;
extern MapInfo lbl_80311AC0;
extern s32 lbl_80347E68;

extern void fn_80296BE4(f32 v, s32 a, s32 b, s32 c);
extern void fn_8029D000(void (*f)(s32));
extern void fn_801C8994(void** p);
extern void fn_801C8634(void* model);
extern void fn_801C84EC(void* model);
extern void fn_801CF128(void* model, s32 v);
extern void fn_801CF158(void* model, s32 v);
extern void fn_801CF0C8(void* model, s32 v);
extern void fn_801CF0F8(void* model, s32 v);
extern void fn_801D184C(void* model, NJS_ARGB* p);
extern f32 fn_801DBD9C(f32 z);
extern void fn_8000610C(NJS_POINT2COL* p, s32 n, s32 attr);
extern void fn_80299040(NJS_TEXLIST* texlist);
extern void njPushMatrixEx(void);
extern void njPopMatrixEx(void);
extern void fn_80286EE8(void);
extern void fn_8028B498(void);
extern void njTranslate(NJS_MATRIX* m, f32 x, f32 y, f32 z);
extern void njRotateZXY(NJS_MATRIX* m, Angle x, Angle y, Angle z);
extern void njScale(NJS_MATRIX* m, f32 x, f32 y, f32 z);
extern void fn_8022BC24(NJS_MATRIX* m, Angle x, Angle y, Angle z);
extern void fn_8022BBF4(NJS_MATRIX* m, Angle x, Angle y, Angle z);
extern void fn_8022BBC4(NJS_MATRIX* m, Angle x, Angle y, Angle z);
extern void fn_8022BB94(NJS_MATRIX* m, Angle x, Angle y, Angle z);
extern void fn_8022BB5C(NJS_MATRIX* m, Angle x, Angle y, Angle z);
extern void fn_80296EEC(s32 a, s32 b, s32 c);
extern void fn_801C8930(void* model);
extern void fn_801E6F88(u16 id, void* model, MotionBlend* motion, ShapeBlend* shape, f32 blend);
extern void fn_801E7194(u16 id, void* model, NJS_MOTION* motion, void* shape, f32 frame);
extern void fn_802947CC(s32 x);
extern void fn_801E6148(ModelObj* obj);
extern void fn_801E6438(ModelObj* obj);

void fn_801E4CB0(s32 id, void* model);
void fn_801E4DA0(u32* colors, s16 x0, s16 y0, s16 x1, s16 y1, f32 z);
void fn_801E4FD4(ModelObj* obj);
void fn_801E5608(ModelObj* obj, s32 texIndex, u32 texCount);
void fn_801E583C(ModelObj* obj, s32 texIndex, u32 texCount, u32 hold);
void fn_801E5F8C(ModelObj* obj, s32 doAnim, s32 doFrames);

void fn_801E4C2C(s32 i) {
    fn_80296BE4(lbl_802F67C0[i], lbl_80313698[0], lbl_80313698[1], lbl_80313698[2]);
}

void fn_801E4C70(void) {
    lbl_80313698[0] = 1;
    lbl_80313698[1] = 1;
    lbl_80313698[2] = 0;
    fn_8029D000(fn_801E4C2C);
}

/* Draws a model without motion. */
void fn_801E4CB0(s32 id, void* model) {
    void* obj = model;
    lbl_80347770 = model;
    fn_801C8994(&obj);
    if ((id & 0x7F) >= 5 && lbl_80347540 != -1) {
        id -= 5;
    }
    fn_801C8634(obj);
    switch (id & 0x7F) {
    case 0: fn_801CF128(obj, id); break;
    case 1: fn_801CF158(obj, id); break;
    case 2: fn_801CF0C8(obj, id); break;
    case 3: fn_801CF0F8(obj, id); break;
    case 5: case 6: case 7: case 8:
        fn_801D184C(obj, &lbl_8030E820);
        break;
    }
    fn_801C84EC(obj);
}

/* Draws a screen rectangle (clamped to 640x480) with four corner colours.
 * Note: the original clamps x0 (not x1) when x1 is out of range. */
void fn_801E4DA0(u32* colors, s16 x0, s16 y0, s16 x1, s16 y1, f32 z) {
    NJS_POINT2COL p2c;
    u32 col[4];
    NJS_POINT2 pts[4];

    if (x0 < 0) {
        x0 = 0;
    } else if (x0 > 640) {
        x0 = 640;
    }
    if (x1 < 0) {
        x0 = 0;
    } else if (x1 > 640) {
        x0 = 640;
    }
    if (y0 < 0) {
        y0 = 0;
    } else if (y0 > 480) {
        y0 = 480;
    }
    if (y1 < 0) {
        y1 = 0;
    } else if (y1 > 480) {
        y1 = 480;
    }
    p2c.p = pts;
    p2c.col = col;
    p2c.tex = NULL;
    p2c.num = 4;
    p2c.p[0].x = x0;
    p2c.p[0].y = y0;
    p2c.col[0] = colors[0];
    p2c.p[1].x = x1;
    p2c.p[1].y = y0;
    p2c.col[1] = colors[1];
    p2c.p[2].x = x1;
    p2c.p[2].y = y1;
    p2c.col[2] = colors[3];
    p2c.p[3].x = x0;
    p2c.p[3].y = y1;
    p2c.col[3] = colors[2];
    fn_801DBD9C(z);
    fn_8000610C(&p2c, 4, 0);
}

/* Draws a single-colour screen rectangle. */
void fn_801E4F88(u32 color, s16 x0, s16 y0, s16 x1, s16 y1, f32 z) {
    u32 v[4];
    v[3] = color;
    v[2] = color;
    v[1] = color;
    v[0] = color;
    fn_801E4DA0(v, x0, y0, x1, y1, z);
}

/* 1 if the ARGB colour is not fully opaque. */
u32 fn_801E4FBC(u32 x) {
    return (x >> 24) != 0xFF;
}

/* Pushes a draw state built from the object's material settings. */
void fn_801E4FD4(ModelObj* o) {
    DrawState s;
    DrawStateGet(&s);
    if (lbl_80347530 == 1) {
        s.control3d &= ~0x100;
    }
    s.control3d = (s.control3d & ~0x4) | 0x800;
    if (o->colour.a == 1.0f) {
        s.attr_or &= ~0x800;
    } else {
        s.attr_or |= 0x800;
    }
    if (o->kind == 1) {
        if ((o->id & 0x7F) < 5) {
            if (lbl_80347540 != -1) {
                s.control3d |= 0x400;
            } else {
                s.control3d &= ~0x400;
            }
        } else {
            s.control3d |= 0x400;
        }
    } else {
        s.control3d &= ~0x400;
    }
    s.colour = o->colour;
    s.attr_and &= o->attr_and;
    s.attr_or &= ~0x6000;
    s.attr_or |= o->attr_or;
    if (o->lit == 1) {
        s.control3d |= 0x40;
    } else {
        s.control3d &= ~0x40;
    }
    s.blend_src = o->blend_src;
    s.blend_dst = o->blend_dst;
    s.fog = o->fog;
    DrawStatePush(&s);
}

/* Draws the object blending from motion2 into motion. */
void fn_801E5148(ModelObj* obj) {
    MotionBlend mb;
    ShapeBlend sb;

    if (obj->model == NULL) {
        return;
    }
    if (obj->motion2 == NULL) {
        fn_801E5608(obj, 0, obj->texlist != NULL ? obj->texlist->nbTexture : 0);
        return;
    }
    if (obj->hidden != 0 || -1.0f >= obj->colour.a) {
        if (obj->motion != NULL) {
            if ((obj->blend += obj->blendSpeed) > 1.0f - obj->blendSpeed) {
                obj->blendDone = 1;
                obj->blend = 0.0f;
            }
        } else {
            obj->blendDone = 1;
        }
        return;
    }

    if (obj->texlist != NULL) {
        fn_80299040(obj->texlist);
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    fn_801E4FD4(obj);
    if (obj->pivot == 0) {
        Angle x, y, z;
        njTranslate(NULL, obj->pos.x, obj->pos.y, obj->pos.z);
        z = obj->ang[2];
        y = obj->ang[1];
        x = obj->ang[0];
        switch (obj->rotOrder) {
        case 0:
            njRotateZXY(NULL, x, y, z);
            break;
        case 1:
            fn_8022BC24(NULL, 0, 0, 0);
            break;
        case 2:
            fn_8022BBF4(NULL, 0, y, z);
            break;
        case 3:
            fn_8022BBC4(NULL, x, 0, z);
            break;
        case 4:
            fn_8022BB94(NULL, x, y, 0);
            break;
        case 5:
            fn_8022BB5C(NULL, 0, 0, z);
            break;
        }
    } else {
        njTranslate(NULL, obj->pos.x, obj->pos.y, obj->pos.z);
        njRotateZXY(NULL, obj->ang[0], obj->ang[1], obj->ang[2]);
        njTranslate(NULL, obj->pivotPos.x, obj->pivotPos.y, obj->pivotPos.z);
        switch (obj->rotOrder) {
        case 0:
            njRotateZXY(NULL, obj->pivotAng[0], obj->pivotAng[1], obj->pivotAng[2]);
            break;
        case 1:
            fn_8022BC24(NULL, -obj->ang[0], -obj->ang[1], -obj->ang[2]);
            break;
        case 2:
            fn_8022BBF4(NULL, -obj->ang[0], obj->pivotAng[1], obj->pivotAng[2]);
            break;
        case 3:
            fn_8022BBC4(NULL, obj->pivotAng[0], -obj->ang[1], obj->pivotAng[2]);
            break;
        case 4:
            fn_8022BB94(NULL, obj->pivotAng[0], obj->pivotAng[1], -obj->ang[2]);
            break;
        case 5:
            fn_8022BB5C(NULL, -obj->ang[0], -obj->ang[1], obj->pivotAng[2]);
            break;
        }
    }
    njScale(NULL, obj->scl.x, obj->scl.y, obj->scl.z);
    if (obj->motion != NULL) {
        fn_801C8930(obj->model);
        mb.motion2 = obj->motion2;
        mb.motion = obj->motion;
        mb.frame2 = obj->frame2;
        mb.frame = obj->frame;
        if (mb.frame2 >= (f32)mb.motion2->nbFrame) {
            mb.frame2 = (f32)(mb.motion2->nbFrame - 1);
        } else if (mb.frame2 < 0.0f) {
            mb.frame2 = 0.0f;
        }
        if (mb.frame >= (f32)obj->motion->nbFrame) {
            mb.frame = (f32)(obj->motion->nbFrame - 1);
        } else if (mb.frame < 0.0f) {
            mb.frame = 0.0f;
        }
        if (obj->blend >= 1.0f) {
            obj->blend = 0.9999f;
        } else if (obj->blend < 0.0f) {
            obj->blend = 0.0f;
        }
        if (obj->shape != NULL) {
            sb.arg = obj->shapeArg;
            sb.shape = obj->shape;
            sb.frame2 = mb.frame2;
            sb.frame = mb.frame;
            fn_801E6F88(obj->id, obj->model, &mb, &sb, obj->blend);
        } else {
            fn_801E6F88(obj->id, obj->model, &mb, NULL, obj->blend);
        }
        if ((obj->blend += obj->blendSpeed) >= 1.0f) {
            obj->blendDone = 1;
            obj->blend = 0.0f;
        }
    } else {
        fn_801E4CB0(obj->id, obj->model);
        obj->blendDone = 1;
    }
    DrawStatePop(NULL);
    njPopMatrixEx();
}

/* Draws the object, with a per-map list of objects that are drawn with fn_802947CC(0). */
void fn_801E5608(ModelObj* obj, s32 texIndex, u32 texCount) {
    s32 saved;
    s32 flag = 0;
    s32 set = 0;

    if (lbl_80311AC0.map == 0xD && lbl_80311AC0.room == 'a') {
        if (obj->id2 == 0x3F0) {
            set = 1;
        } else if (obj->id2 == 0x3F2) {
            set = 1;
        } else if (obj->id2 == 0x3F5) {
            set = 1;
        }
    }
    if (lbl_80311AC0.map == 0xD && lbl_80311AC0.room == 'd') {
        if (obj->id2 == 0x3EE) {
            set = 1;
        }
    }
    if (lbl_80311AC0.map == 0x1C && lbl_80311AC0.room == 'a') {
        if (obj->id2 == 0x1450) {
            set = 1;
        } else if (obj->id2 == 0x1455) {
            set = 1;
        } else if (obj->id2 == 0x1456) {
            set = 1;
        }
    }
    if (lbl_80311AC0.map == 0x11 && lbl_80311AC0.room == 'f') {
        if (obj->id2 == 0xBC6) {
            set = 1;
            flag = 1;
        }
    }
    if (lbl_80311AC0.map == 0x11 && lbl_80311AC0.room == 'f') {
        if (obj->id2 == 0xBC6) {
            set = 1;
            flag = 1;
        }
    }
    if (lbl_80311AC0.map == 0x11 && lbl_80311AC0.room == 'i') {
        if (obj->id2 == 0x7594) {
            set = 1;
            flag = 1;
        }
    }
    if (lbl_80311AC0.map == 0xFA && lbl_80311AC0.room == 'a') {
        u16 id = obj->id2;
        if (id == 0x7D00 || (u16)(id - 0x7D01) <= 2 || id == 0x7D04) {
            set = 1;
            flag = 1;
        }
    }
    if (lbl_80311AC0.map == 0xA && lbl_80311AC0.room == 'a') {
        if (obj->id2 == 0xDAF) {
            set = 1;
            flag = 1;
        }
    }
    saved = lbl_80347E68;
    if (set) {
        fn_802947CC(0);
    }
    fn_801E583C(obj, texIndex, texCount, flag);
    fn_802947CC(saved);
}

inline s32 ModelExtFlags(ModelExt* ext) {
    ModelExtInfo* info = ext->info;
    return info->size > 4 ? info->flags : 0;
}

/* Draws the object at its current frame and advances the frame (looping, keeping `hold`
 * frames at the end). */
void fn_801E583C(ModelObj* obj, s32 texIndex, u32 texCount, u32 hold) {
    NJS_TEXLIST tl;

    if (obj->model == NULL) {
        return;
    }
    if (obj->hidden != 0 || -1.0f >= obj->colour.a) {
        if (obj->motion != NULL) {
            obj->frame += obj->speed;
            if (0.0f > obj->speed) {
                if (0.0f > obj->frame) {
                    obj->looped = 1;
                    do {
                        obj->frame = (f32)obj->motion->nbFrame + obj->frame;
                    } while (obj->frame < 0.0f);
                }
            } else if (obj->frame > (f32)obj->motion->nbFrame - 1.0f) {
                obj->looped = 1;
                if (obj->frame >= (f32)obj->motion->nbFrame) {
                    obj->frame = 0.0f;
                }
            }
        } else {
            obj->looped = 1;
        }
        return;
    }

    if (obj->texlist != NULL) {
        tl.nbTexture = texCount;
        tl.textures = &obj->texlist->textures[texIndex];
        fn_80299040(&tl);
    }
    njPushMatrixEx();
    fn_80286EE8();
    fn_8028B498();
    fn_801E4FD4(obj);
    if (obj->pivot == 0) {
        Angle x, y, z;
        njTranslate(NULL, obj->pos.x, obj->pos.y, obj->pos.z);
        z = obj->ang[2];
        y = obj->ang[1];
        x = obj->ang[0];
        switch (obj->rotOrder) {
        case 0:
            njRotateZXY(NULL, x, y, z);
            break;
        case 1:
            fn_8022BC24(NULL, 0, 0, 0);
            break;
        case 2:
            fn_8022BBF4(NULL, 0, y, z);
            break;
        case 3:
            fn_8022BBC4(NULL, x, 0, z);
            break;
        case 4:
            fn_8022BB94(NULL, x, y, 0);
            break;
        case 5:
            fn_8022BB5C(NULL, 0, 0, z);
            break;
        }
    } else {
        njTranslate(NULL, obj->pos.x, obj->pos.y, obj->pos.z);
        njRotateZXY(NULL, obj->ang[0], obj->ang[1], obj->ang[2]);
        njTranslate(NULL, obj->pivotPos.x, obj->pivotPos.y, obj->pivotPos.z);
        switch (obj->rotOrder) {
        case 0:
            njRotateZXY(NULL, obj->pivotAng[0], obj->pivotAng[1], obj->pivotAng[2]);
            break;
        case 1:
            fn_8022BC24(NULL, -obj->ang[0], -obj->ang[1], -obj->ang[2]);
            break;
        case 2:
            fn_8022BBF4(NULL, -obj->ang[0], obj->pivotAng[1], obj->pivotAng[2]);
            break;
        case 3:
            fn_8022BBC4(NULL, obj->pivotAng[0], -obj->ang[1], obj->pivotAng[2]);
            break;
        case 4:
            fn_8022BB94(NULL, obj->pivotAng[0], obj->pivotAng[1], -obj->ang[2]);
            break;
        case 5:
            fn_8022BB5C(NULL, -obj->ang[0], -obj->ang[1], obj->pivotAng[2]);
            break;
        }
    }
    njScale(NULL, obj->scl.x, obj->scl.y, obj->scl.z);
    if (obj->ext != NULL && (ModelExtFlags(obj->ext) & 1)) {
        fn_80296EEC(1, 3, 0);
    }
    if (obj->motion != NULL) {
        u32 count = obj->motion->nbFrame;
        if (obj->frame >= (f32)count) {
            obj->frame = (f32)(count - 1);
        } else if (obj->frame < 0.0f) {
            obj->frame = 0.0f;
        }
        fn_801E7194(obj->id, obj->model, obj->motion, obj->shape, obj->frame);
        obj->frame += obj->speed;
        if (0.0f > obj->speed) {
            if (0.0f > obj->frame) {
                obj->looped = 1;
                do {
                    obj->frame = (f32)obj->motion->nbFrame + obj->frame;
                } while (obj->frame < 0.0f);
            }
        } else if (obj->frame > (f32)(obj->motion->nbFrame - (hold + 1))) {
            obj->looped = 1;
            if (obj->frame > (f32)obj->motion->nbFrame - (obj->speed + (f32)hold)) {
                obj->frame = obj->frame - (f32)obj->motion->nbFrame;
            }
        }
    } else {
        fn_801E4CB0(obj->id, obj->model);
        obj->looped = 1;
    }
    if (obj->ext != NULL && (ModelExtFlags(obj->ext) & 1)) {
        fn_80296EEC(1, 3, 1);
    }
    DrawStatePop(NULL);
    njPopMatrixEx();
}

void fn_801E5DF0(ModelObj* obj) {
    fn_801E5608(obj, 0, obj->texlist ? obj->texlist->nbTexture : 0);
}

void fn_801E5E2C(ModelObj* obj) {
    fn_801E5F8C(obj, 1, 1);
}

void fn_801E5E54(ModelObj* obj) {
    fn_801E5F8C(obj, 0, 1);
}

void fn_801E5E7C(ModelObj* obj) {
    fn_801E5F8C(obj, 1, 0);
}

/* Restarts the frame animation at entry i (0 if out of range). */
void fn_801E5EA4(ModelObj* o, s16 i) {
    FrameAnim* a = o->anim;
    if (a == 0) return;
    if (a->table != 0) {
        if (i >= 0 && i < a->count) {
            a->index = i;
        } else {
            i = 0;
            a->index = 0;
        }
        a->done = 0;
        a->value = a->table[i];
        a->timer = a->delay;
    } else {
        a->value = 0;
    }
}

/* Restarts the frame animation with the given step, from the first or last entry. */
void fn_801E5F1C(ModelObj* o, s16 step) {
    FrameAnim* a = o->anim;
    if (a == 0) return;
    if (a->table != 0) {
        a->step = step;
        if (step >= 0) {
            a->index = 0;
        } else {
            a->index = a->count - 1;
        }
        a->done = 0;
        a->value = a->table[a->index];
        a->timer = a->delay;
    } else {
        a->value = 0;
    }
}

/* Per-frame update: advances the motion frame (looping) and steps the frame animation. */
void fn_801E5F8C(ModelObj* obj, s32 doAnim, s32 doFrames) {
    if (doFrames) {
        fn_801E6148(obj);
        if (obj->motion != NULL) {
            obj->frame += obj->speed;
            if (0.0f > obj->speed) {
                if (0.0f > obj->frame) {
                    obj->looped = 1;
                    obj->frame = (f32)obj->motion->nbFrame - 1.0f;
                }
            } else if (obj->frame > (f32)obj->motion->nbFrame - 1.0f) {
                obj->looped = 1;
                obj->frame = 0.0f;
            }
        }
    } else {
        fn_801E6438(obj);
        obj->looped = 1;
    }
    if (doAnim && obj->anim != NULL && obj->anim->table != NULL) {
        obj->anim->timer--;
        if (obj->anim->timer <= 0) {
            obj->anim->index += obj->anim->step;
            if (obj->anim->index < 0 || obj->anim->count <= obj->anim->index) {
                if (obj->anim->step >= 0) {
                    obj->anim->index = 0;
                } else {
                    obj->anim->index = obj->anim->count - 1;
                }
                obj->anim->done = 1;
            }
            obj->anim->value = obj->anim->table[obj->anim->index];
            obj->anim->timer = obj->anim->delay;
        }
    }
}
