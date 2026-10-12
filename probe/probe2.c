typedef unsigned char u8; typedef unsigned short u16;

float fn_8009E4F8(u8 v) { return (float)(v - 255) * 0.5f; }

typedef struct { u8 pad[0x24]; float x24, x28, x2c; } Inner;
typedef struct { u8 pad[0x24]; Inner* x24; } Outer;
extern Outer* lbl_80346F10;
void fn_8012ADE8(int v) { if (v > 99) v = 99; lbl_80346F10->x24->x2c = (float)v; }
void fn_8012AE28(int v) { if (v > 99) v = 99; lbl_80346F10->x24->x28 = (float)v; }

typedef struct { u8 pad[8]; float x8; float xc; u8 pad2[0x1a - 0x10]; u16 x1a; } Obj30;
typedef struct { u8 pad[0x30]; Obj30* x30; } Obj;
void fn_801AB98C(Obj* p) { p->x30->xc = (float)(p->x30->x1a * 0x18); p->x30->x8 = 1.0f; }
