typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef short s16; typedef unsigned int u32;
typedef long long s64; typedef unsigned long long u64;
typedef struct { u32 a:1; u32 b:1; u32 c:6; u32 d:8; u32 e:16; } BF2;
typedef struct { u8 f0:4; u8 f1:4; u8 g; s16 h; } BF3;
typedef struct Node { struct Node* next; int val; float f; u8 flag; } Node;
extern void ext(int); extern int exti(void); extern void extp(void*); extern float extf(float);
extern int printf(const char*, ...);
extern Node* gnode; extern BF2 gbf; extern u8 gflags; extern s16 gs16[];

static inline int sq(int x) { return x * x; }
static int helper(int a, int b) { return a * 3 + b; }
int u_inline(int a) { return sq(a) + sq(a + 1); }
int u_static(int a) { return helper(a, 2) + helper(a, 5); }
void u_bf2(BF2* p) { p->a = 1; p->b = 0; p->c = 33; if (p->d) p->e++; }
int u_bf3(BF3* p) { p->f1 = p->f0 + 1; return p->g & 0x0f; }
int u_gbf(void) { gbf.c++; return gbf.a ? gbf.e : -1; }
void u_flags(int s) { if (s) gflags |= 0x80; else gflags &= 0x7f; gflags ^= 1; }
int u_list(int v) { Node* n; for (n = gnode; n; n = n->next) if (n->val == v) return 1; return 0; }
float u_listf(void) { Node* n; float s = 0.0f; for (n = gnode; n; n = n->next) if (n->flag & 1) s += n->f; return s; }
s64 u_ll(s64 a, s64 b) { return a * b + (a >> 3); }
u64 u_ulldiv(u64 a, u32 b) { return a / b; }
int u_printf(int a, float f) { return printf("%d %f\n", a, f); }
void u_big(int* p, int n) { int i, j; for (i = 0; i < n; i++) for (j = 0; j < 4; j++) p[i*4+j] = sq(i) + j * exti(); }
int u_jt(int a, int b) { switch (a) { case 10: b += 1; break; case 11: b *= 2; break; case 12: ext(b); break; case 13: b -= 7; break; case 14: b = exti(); break; case 15: b ^= 3; break; case 16: return 0; } return b + a; }
void u_s16(int i, int v) { gs16[i] += (s16)v; if (gs16[i] > 100) gs16[i] = 100; else if (gs16[i] < -100) gs16[i] = -100; }
int u_loop_unroll(int* p) { int i, s = 0; for (i = 0; i < 64; i++) s += p[i]; return s; }
void u_memcpy(u8* d, u8* s, int n) { while (n--) *d++ = *s++; }
float u_fcmp(float a, float b, float c) { if (a < b && b < c) return b; if (a >= c) return a - c; return c; }
int u_regs(Node* n, int a, int b, int c) { int x = n->val + a; ext(x); x += b * n->val; extp(n); x -= c; ext(x); return x + n->flag; }
void u_vec(float* o, float* m, float* v) { o[0] = m[0]*v[0]+m[1]*v[1]+m[2]*v[2]+m[3]; o[1] = m[4]*v[0]+m[5]*v[1]+m[6]*v[2]+m[7]; o[2] = m[8]*v[0]+m[9]*v[1]+m[10]*v[2]+m[11]; }
u8 u_clampu8(int v) { return v < 0 ? 0 : v > 255 ? 255 : v; }
int u_cond(int a, int b) { int r = 0; if (a & 1) r |= 2; if (b & 4) r |= 8; if ((a ^ b) & 0x10) r |= 0x20; return r; }
int u_ternary_chain(s8 a) { return a > 10 ? 3 : a > 5 ? 2 : a > 0 ? 1 : 0; }
int u_local_arr(int a) { int t[8]; int i; for (i = 0; i < 8; i++) t[i] = a + i; extp(t); return t[3]; }
int u_struct_ret(Node* n) { Node c = *n; c.val++; extp(&c); return c.val; }
