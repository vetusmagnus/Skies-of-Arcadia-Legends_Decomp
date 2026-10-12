typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

typedef struct { int a; int b; void* c; } Ent12;
extern Ent12* lbl_80347894;
void fn_80005954(int i) { lbl_80347894[i].a = -1; }

extern int lbl_803478A0, lbl_803478A4;
void fn_80007514(int* a, int* b) { *b = lbl_803478A0; *a = lbl_803478A4; }

typedef struct { u8 pad[0x34]; u32 x34; } S34;
extern S34* lbl_803478DC;
int fn_80008258(u32* out) { *out = (lbl_803478DC->x34 + 0x1f) & ~0x1f; return 1; }

typedef struct { short s; short pad; int x4; } S4;
void fn_80009860(int v, S4* p) { if (p->s >= 0) p->x4 = v; }

void fn_80009FBC(u8* p) { if (p[0x19] == 0xff) p[0x18] |= 0x40; }

extern u8* lbl_80346AA4;
void fn_8000A38C(void) { if (lbl_80346AA4) lbl_80346AA4[0x19] = 3; }

typedef struct { int x0; int x4; u32 x8; } S8;
extern S8 lbl_80309E5C;
void fn_8000CC84(int f) {
    if (f == 1) lbl_80309E5C.x8 |= 0x01000000;
    else lbl_80309E5C.x8 &= ~0x01000000;
}

extern int lbl_802DAFA8[];
int fn_8000F0A4(short i) { return lbl_802DAFA8[i]; }

extern u8 lbl_8030B7F4[];
short fn_80010CBC(short i) {
    s8 c = lbl_8030B7F4[i + 0x328];
    return *(short*)(lbl_8030B7F4 + c * 0x5c + 0x1c);
}
