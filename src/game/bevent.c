/* Battle event handlers (0x8002A034 - 0x8002BC4C): the command-slot builder fn_8002A034, the quad
 * draw fn_8002B970, the encounter-drop roll fn_8002BA8C with its condition callbacks
 * (fn_8002BBAC .. fn_8002BC44, table lbl_802DBC4C) and the defeat handler fn_8002BC4C. The unit
 * array lbl_80309DE4 is typed as in battle.c; types used by one function are local to it. */
#include "types.h"
#include "ninja.h"
#include "game/drawstate.h"
#include <dolphin/os/OSFastCast.h>

typedef struct {
    u8 pad0[0x1a];
    s16 id;     /* 0x1a */
    u8 pad1c[2];
    s16 mode;   /* 0x1e */
    u8 pad20[2];
    u8 val;     /* 0x22 */
    u8 pad23;
    u8 pad24[0x24 - 0x24];
} Slot;
typedef struct {
    u8 pad0[8];
    s32 i8;
    u8 padc[4];
    s16 s10;      /* 0x10 */
    s16 s12;      /* 0x12 */
    u8 pad14[0x3c - 0x14];
    u16 h3c;
    u16 h3e;
    u16 h40;
    u8 pad42[0x6c - 0x42];
    s16 s6c;
    u8 pad6e[0x9c - 0x6e];
    Slot slots[8];
} Obj;
typedef struct {
    f32 x, y, z, u, v;
    u32 col;
} Vtx;
extern Vtx lbl_80302A50[4];
extern s32 fn_801E4FBC(u32 col);
extern void fn_80291064(Vtx* v, s32 n, s32 tex);
typedef struct {
    s16 chance;
    s16 a;
    s16 b;
} Ent;
typedef struct {
    u8 pad[0x72];
    Ent e[4];
} Blk;
/* Battle unit record lbl_80309DE4[n]; +0x110 is read as a Blk* in fn_8002BA8C and a Stat* in fn_8002BC4C. */
typedef struct BUnit {
    s16 x0;
    s16 x2;
    u8 b4, b5, b6;
    u8 pad7[5];
    s16 xc;
    s16 xe;
    u8 pad10[4];
    s32 cnt;
    u8 pad18[4];
    u32 flags;
    u8 pad20[0x106 - 0x20];
    u8 b106;
    u8 pad107;
    s16 s108;
    u8 pad10a[6];
    void* p110;
} BUnit;
typedef struct {
    u8 pad0[0x1e];
    u16 a;
    u16 b;
} Stat;
typedef struct {
    u8 pad0[0xc];
    s16 c;
    u8 padE[0x30 - 0xe];
    s32 sum1;
    s32 sum2;
} Glob;
extern BUnit* lbl_80309DE4[12];
extern s16* lbl_80347390;
extern s32 (*lbl_802DBC4C[])(void);
extern s32 rand(void);
extern s8 lbl_80347334;
extern void fn_8002D684(void* u);
extern void fn_8002BA8C(s16 idx);

u8 fn_8002A034(Obj* o, s32 flag) {
    Slot* arr = o->slots;
    s32 sel = 0;
    u8 n = 0;
    u8 i;
    u16 v;
    if (flag != 0) {
        if (o->s10 < 4 && o->i8 == 0) {
            o->h3c &= 2;
        }
        if (o->s12 != 4 && o->s12 != 5) {
            v = o->h3c;
        } else {
            v = o->h3e;
            if (v != 0) sel = 1;
        }
        if (v & 1) {
            arr[n].id = 0;
            if (o->h40 & 1) {
                arr[n].val = o->s6c;
                arr[n].mode = 2;
            } else {
                arr[n].val = 0xff;
                arr[n].mode = sel;
            }
            n++;
            if ((u8)n >= 8) return 8;
        }
        if (v & 2) {
            arr[n].id = 1;
            if (o->h40 & 2) {
                arr[n].val = o->s6c;
                arr[n].mode = 2;
            } else {
                arr[n].val = 0xff;
                arr[n].mode = sel;
            }
            n++;
            if ((u8)n >= 8) return 8;
        }
        if (v & 4) {
            arr[n].id = 2;
            if (o->h40 & 4) {
                arr[n].val = o->s6c;
                arr[n].mode = 2;
            } else {
                arr[n].val = 0xff;
                arr[n].mode = sel;
            }
            n++;
            if ((u8)n >= 8) return 8;
        }
        if (v & 8) {
            arr[n].id = 3;
            if (o->h40 & 8) {
                arr[n].val = o->s6c;
                arr[n].mode = 2;
            } else {
                arr[n].val = 0xff;
                arr[n].mode = sel;
            }
            n++;
            if ((u8)n >= 8) return 8;
        }
        if (v & 16) {
            arr[n].id = 4;
            if (o->h40 & 16) {
                arr[n].val = o->s6c;
                arr[n].mode = 2;
            } else {
                arr[n].val = 0xff;
                arr[n].mode = sel;
            }
            n++;
            if ((u8)n >= 8) return 8;
        }
        if (v & 32) {
            arr[n].id = 5;
            if (o->h40 & 32) {
                arr[n].val = o->s6c;
                arr[n].mode = 2;
            } else {
                arr[n].val = 0xff;
                arr[n].mode = sel;
            }
            n++;
            if ((u8)n >= 8) return 8;
        }
        if (v & 64) {
            arr[n].id = 6;
            if (o->h40 & 64) {
                arr[n].val = o->s6c;
                arr[n].mode = 2;
            } else {
                arr[n].val = 0xff;
                arr[n].mode = sel;
            }
            n++;
            if ((u8)n >= 8) return 8;
        }
        if (v & 128) {
            arr[n].id = 7;
            if (o->h40 & 128) {
                arr[n].val = o->s6c;
                arr[n].mode = 2;
            } else {
                arr[n].val = 0xff;
                arr[n].mode = sel;
            }
            n++;
            if ((u8)n >= 8) return 8;
        }
        if (v & 256) {
            arr[n].id = 8;
            if (o->h40 & 256) {
                arr[n].val = o->s6c;
                arr[n].mode = 2;
            } else {
                arr[n].val = 0xff;
                arr[n].mode = sel;
            }
            n++;
            if ((u8)n >= 8) return 8;
        }
        if (v & 512) {
            arr[n].id = 9;
            if (o->h40 & 512) {
                arr[n].val = o->s6c;
                arr[n].mode = 2;
            } else {
                arr[n].val = 0xff;
                arr[n].mode = sel;
            }
            n++;
            if ((u8)n >= 8) return 8;
        }
        if (v & 1024) {
            arr[n].id = 10;
            if (o->h40 & 1024) {
                arr[n].val = o->s6c;
                arr[n].mode = 2;
            } else {
                arr[n].val = 0xff;
                arr[n].mode = sel;
            }
            n++;
            if ((u8)n >= 8) return 8;
        }
    } else {
        arr[0].id = 11;
        arr[0].val = 0xff;
        arr[0].mode = 3;
        n = 1;
    }
    for (i = n; i < 8; i++) {
        arr[i].id = -1;
    }
    if (o->s6c <= 0) {
        o->h40 = 0;
    }
    return n;
}

typedef struct { u8 pad[0x40c]; void* cur; u8 pad2[0xf4]; } T98;
extern T98 lbl_803098C8;
extern u32 lbl_80302AB0[12];
typedef struct EvC { u8 pad[0x20]; void* v; } EvC;
typedef struct EvB { u8 pad[4]; EvC* c; } EvB;
typedef struct EvA { u8 pad[8]; EvB* b; } EvA;
extern void* lbl_80346BB0;
extern char lbl_802AD0DC[];
extern char lbl_802AD0E8[];

extern void fn_8006EA90(char* a, char* b, void* out);
extern void fn_8006EA70(char* a, char* b, void* out, void* arg);
extern void fn_801E1DF8(s32 a, void* b);
extern void fn_80227810(void* p);

void fn_8002B124(void) {
    EvA* out;
    s32 i;
    void* res = lbl_803098C8.cur;
    if (res == 0) {
        fn_8006EA90(lbl_802AD0DC, lbl_802AD0E8, &out);
    } else {
        fn_801E1DF8(0, res);
        fn_8006EA70(lbl_802AD0DC, lbl_802AD0E8, &out, res);
        lbl_803098C8.cur = 0;
    }
    lbl_80346BB0 = out->b->c->v;
    fn_80227810(lbl_80346BB0);
    for (i = 0; i < sizeof(lbl_80302AB0) / sizeof(lbl_80302AB0[0]); i++) {
        lbl_80302AB0[i] = 0;
    }
}

typedef struct {
    f32 x, y, z;
    u32 colour;
} VertexCol;

extern s16 lbl_80346740;
extern s32 lbl_80346744;

extern f32 fn_801DBD9C(f32 z);
extern void fn_80290ED4(VertexCol* v, s32 count, s32 flag);

typedef struct {
    s16 x0, y0, x1, y1;
} SRect;

static inline void quad(SRect* r, f32 z, u32 col, u32 flag) {
    VertexCol v[4];
    OSs16tof32(&r->x0, &v[0].x);
    OSs16tof32(&r->y0, &v[0].y);
    v[0].z = z;
    v[0].colour = col;
    v[1].x = v[0].x;
    OSs16tof32(&r->y1, &v[1].y);
    v[1].z = z;
    v[1].colour = col;
    OSs16tof32(&r->x1, &v[2].x);
    v[2].y = v[0].y;
    v[2].z = z;
    v[2].colour = col;
    v[3].x = v[2].x;
    v[3].y = v[1].y;
    v[3].z = z;
    v[3].colour = col;
    fn_80290ED4(v, 4, flag);
}

void fn_8002B40C(s16 x0, s16 y0, s16 x1, s16 y1, s32 sel) {
    DrawState s;
    SRect r;
    u32 col;
    u32 flag;
    f32 z;
    r.x0 = x0;
    r.y0 = y0;
    r.x1 = x1;
    r.y1 = y1;
    DrawStateDefault2D(&s);
    s.blend_src = 8;
    s.blend_dst = 10;
    if (DrawStatePush(&s)) {
        if (lbl_80346744) {
            lbl_80346740 -= 3;
            if (lbl_80346740 <= 10) {
                lbl_80346740 = 10;
                lbl_80346744 = 0;
            }
        } else {
            lbl_80346740 += 3;
            if (lbl_80346740 >= 100) {
                lbl_80346740 = 100;
                lbl_80346744 = 1;
            }
        }
        col = sel == 0 ? 0x32FF32 : 0xFF9632;
        col |= lbl_80346740 << 24;
        flag = fn_801E4FBC(col);
        z = fn_801DBD9C(-1.0f);
        quad(&r, z, col, flag);
        DrawStatePop(0);
    }
}

void fn_8002B970(f32 z, f32* pos, f32* uv, u32 col) {
    s32 tex = fn_801E4FBC(col);
    Vtx* v = lbl_80302A50;
    v[0].x = pos[2];
    v[0].y = pos[0];
    v[0].z = z;
    v[0].col = col;
    v[1].x = pos[2];
    v[1].y = pos[1];
    v[1].z = z;
    v[1].col = col;
    v[2].x = pos[3];
    v[2].y = pos[0];
    v[2].z = z;
    v[2].col = col;
    v[3].x = pos[3];
    v[3].y = pos[1];
    v[0].z = z;
    v[0].u = uv[0];
    v[0].v = uv[1];
    v[0].col = col;
    v[1].z = z;
    v[1].u = uv[2];
    v[1].v = uv[3];
    v[1].col = col;
    v[2].z = z;
    v[2].u = uv[4];
    v[2].v = uv[5];
    v[2].col = col;
    v[3].z = z;
    v[3].u = uv[6];
    v[3].v = uv[7];
    v[3].col = col;
    fn_80291064(v, 4, tex);
}

void fn_8002BA8C(s16 idx) {
    Blk* base = lbl_80309DE4[idx]->p110;
    s32 i = 0;
    for (; i < 4; i++) {
        u8 c = base->e[i].chance;
        if (c == 0xff) continue;
        if (c <= 100) {
            if (rand() % 100 < c) {
                lbl_80347390[idx * 2 - 1] = base->e[i].a;
                lbl_80347390[idx * 2] = base->e[i].b;
                break;
            }
        } else {
            if (lbl_802DBC4C[c - 101]() != 0) {
                lbl_80347390[idx * 2 - 1] = base->e[i].a;
                lbl_80347390[idx * 2] = base->e[i].b;
                break;
            }
        }
    }
}

s32 fn_8002BBAC(void) {
    return 0;
}

s32 fn_8002BBB4(void) {
    return rand() % 5 == 0;
}

s32 fn_8002BBFC(void) {
    return rand() % 10 == 0;
}

s32 fn_8002BC44(void) {
    return 1;
}

void fn_8002BC4C(s16 idx) {
    BUnit* u = lbl_80309DE4[idx];
    if (u->cnt <= 0) {
        u->flags &= 8;
        u->flags |= 0x100;
        u->xe = 0;
        fn_8002D684(u);
        u->x0 = 0;
        u->x2 = 0;
        u->b4 = 0;
        u->b5 = 0;
        u->b6 = 0;
        u->xc = 1;
        if (idx >= 4) {
            Stat* st = u->p110;
            if (((Glob*)lbl_80347390)->c < 0x7fff) {
                ((Glob*)lbl_80347390)->c++;
            }
            ((Glob*)lbl_80347390)->sum1 += st->a;
            ((Glob*)lbl_80347390)->sum2 += st->b;
            fn_8002BA8C(idx);
            if (lbl_80347334 <= 3) {
                BUnit* t = lbl_80309DE4[lbl_80347334];
                if (t->s108 < 0x7fff) {
                    t->s108++;
                }
            }
        } else {
            if (u->b106 != 0xff) {
                u->b106++;
            }
        }
    }
}
