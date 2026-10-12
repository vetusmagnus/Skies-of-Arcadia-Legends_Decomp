typedef unsigned char u8; typedef short s16;
typedef struct { float x, y, z; } Vec;
typedef float Mtx[3][4];
extern float sqrtf(float); extern float sinf(float); extern float cosf(float);
extern void extv(Vec*); extern float extf(float); extern float gf; extern Vec gv;
void f_mtxmul(Mtx a, Mtx b, Mtx ab) { int i; for (i = 0; i < 3; i++) { ab[i][0] = a[i][0]*b[0][0] + a[i][1]*b[1][0] + a[i][2]*b[2][0]; ab[i][1] = a[i][0]*b[0][1] + a[i][1]*b[1][1] + a[i][2]*b[2][1]; ab[i][2] = a[i][0]*b[0][2] + a[i][1]*b[1][2] + a[i][2]*b[2][2]; ab[i][3] = a[i][0]*b[0][3] + a[i][1]*b[1][3] + a[i][2]*b[2][3] + a[i][3]; } }
void f_rotY(Mtx m, float a) { float s = sinf(a), c = cosf(a); m[0][0] = c; m[0][1] = 0.0f; m[0][2] = s; m[0][3] = 0.0f; m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f; m[2][0] = -s; m[2][1] = 0.0f; m[2][2] = c; m[2][3] = 0.0f; }
float f_norm(Vec* v) { float l = sqrtf(v->x*v->x + v->y*v->y + v->z*v->z); if (l > 0.0f) { v->x /= l; v->y /= l; v->z /= l; } return l; }
void f_lerp(Vec* o, Vec* a, Vec* b, float t) { o->x = a->x + (b->x - a->x) * t; o->y = a->y + (b->y - a->y) * t; o->z = a->z + (b->z - a->z) * t; }
void f_cross(Vec* o, Vec* a, Vec* b) { Vec t; t.x = a->y*b->z - a->z*b->y; t.y = a->z*b->x - a->x*b->z; t.z = a->x*b->y - a->y*b->x; *o = t; }
void f_mix(Vec* o, s16* in, u8 sc) { float f = (float)sc / 255.0f; o->x = in[0] * f; o->y = in[1] * f; o->z = in[2] * f; }
void f_store(Vec* o) { Vec t; t.x = gf; t.y = gf * 2.0f; t.z = 0.0f; extv(&t); *o = t; gv = t; }
float f_dist(Vec* a, Vec* b) { float dx = a->x - b->x, dy = a->y - b->y, dz = a->z - b->z; return sqrtf(dx*dx + dy*dy + dz*dz); }
void f_apply(Mtx m, Vec* v, Vec* o, int n) { int i; for (i = 0; i < n; i++, v++, o++) { o->x = m[0][0]*v->x + m[0][1]*v->y + m[0][2]*v->z + m[0][3]; o->y = m[1][0]*v->x + m[1][1]*v->y + m[1][2]*v->z + m[1][3]; o->z = m[2][0]*v->x + m[2][1]*v->y + m[2][2]*v->z + m[2][3]; } }
void f_clamp(float* p, int n, float lo, float hi) { int i; for (i = 0; i < n; i++) { if (p[i] < lo) p[i] = lo; else if (p[i] > hi) p[i] = hi; } }
void f_swap(Vec* a, Vec* b) { Vec t = *a; *a = *b; *b = t; }
void f_mtxcopy(Mtx s, Mtx d) { int i, j; for (i = 0; i < 3; i++) for (j = 0; j < 4; j++) d[i][j] = s[i][j]; }
void f_scaleadd(Vec* o, Vec* a, float s, Vec* b) { float x = a->x * s, y = a->y * s, z = a->z * s; o->x = x + b->x; o->y = y + b->y; o->z = z + b->z; }
float f_poly(float x) { return ((x * 0.1f + 0.2f) * x + 0.3f) * x + extf(x); }
void f_dbl(double* d, float* f, int n) { int i; for (i = 0; i < n; i++) d[i] = f[i] * 0.5; }
