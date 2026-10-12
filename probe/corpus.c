typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct { u32 a:3; u32 b:5; u32 c:8; u32 d:16; } BF;
typedef struct { float x, y, z; } Vec;
typedef struct { u8 b0, b1; u16 h; int w; float f; } Mix;
extern void ext(int); extern int exti(void); extern float extf(float);
extern float gf; extern double gd; extern int gi; extern u8 gb[];

int t_bf_get(BF* p) { return p->b + p->c; }
void t_bf_set(BF* p, int v) { p->b = v; p->c = v + 1; }
u8 t_mask(u32 v) { return (u8)(v & 0xff) + (u8)(v >> 8); }
int t_u8add(u8 a, u8 b) { u8 c = a + b; return c; }
int t_s8(s8 a) { return a * 3; }
float t_i2f(int i) { return (float)i * 0.5f; }
int t_f2i(float f) { return (int)f; }
u32 t_f2u(float f) { return (u32)f; }
float t_u2f(u32 u) { return (float)u; }
float t_u8f(u8 u) { return (float)u; }
float t_vlen(Vec* v) { return v->x * v->x + v->y * v->y + v->z * v->z; }
void t_vscale(Vec* o, Vec* a, float s) { o->x = a->x * s; o->y = a->y * s; o->z = a->z * s; }
float t_fsel(float a, float b) { return a > b ? a : b; }
int t_div(int a) { return a / 10 + a % 7; }
u32 t_udiv(u32 a) { return a / 3; }
int t_div2(int a) { return a / 2; }
int t_switch(int a) { switch (a) { case 0: return 5; case 1: return 9; case 2: return 13; case 3: return 2; case 4: return 7; case 5: return 1; default: return 0; } }
void t_loop(int* p, int n) { int i; for (i = 0; i < n; i++) p[i] = i * 2; }
void t_loopcall(int n) { int i; for (i = 0; i < n; i++) ext(i); }
int t_loopsum(u8* p) { int i, s = 0; for (i = 0; i < 16; i++) s += p[i]; return s; }
void t_copy(Mix* a, Mix* b) { *a = *b; }
void t_mem(int* p) { int i; for (i = 0; i < 8; i++) p[i] = 0; }
int t_calls(int a, int b) { int x = exti(); ext(a + x); ext(b); return x + a * b; }
float t_fcall(float a) { float r = extf(a) + gf; return r * extf(r); }
double t_dbl(double a) { return a * gd + 1.0; }
int t_cmpchain(int a) { return a == 1 || a == 3 || a == 7 || a == 12; }
int t_bool(int a, int b) { return (a > b) + (a == 0); }
int t_abs(int a) { return a < 0 ? -a : a; }
int t_min(int a, int b) { return a < b ? a : b; }
void t_arr2(short (*a)[4], int i, int j) { a[i][j] += 3; }
int t_ptrdiff(int* a, int* b) { return b - a; }
int t_sdata(void) { return gi + gb[gi]; }
int t_manyregs(int a, int b, int c, int d, int e, int f, int g, int h) { int x = exti(); ext(a); ext(b); ext(c); ext(d); ext(e); ext(f); ext(g); ext(h); return a+b+c+d+e+f+g+h+x; }
float t_manyf(float a, float b, float c, float d) { float x = extf(a); x += extf(b); x += extf(c); return x * d + a * b - c; }
