#include "dolphin/mtx.h"
#include <math.h>

#define SKIES_QUAT_THRESH 0.99999f

void C_QUATAdd(const Quaternion *p, const Quaternion *q, Quaternion *r) {
  r->x = p->x + q->x;
  r->y = p->y + q->y;
  r->z = p->z + q->z;
  r->w = p->w + q->w;
}

void C_QUATMultiply(const Quaternion *p, const Quaternion *q, Quaternion *pq) {
  Quaternion *r;
  Quaternion pqTmp;
  if (p == pq || q == pq) {
    r = &pqTmp;
  } else {
    r = pq;
  }
  r->w = p->w * q->w - p->x * q->x - p->y * q->y - p->z * q->z;
  r->x = p->w * q->x + p->x * q->w + p->y * q->z - p->z * q->y;
  r->y = p->w * q->y + p->y * q->w + p->z * q->x - p->x * q->z;
  r->z = p->w * q->z + p->z * q->w + p->x * q->y - p->y * q->x;
  if (r == &pqTmp) {
    *pq = pqTmp;
  }
}

void C_QUATInverse(const Quaternion *src, Quaternion *inv) {
  f32 mag, norminv;
  mag = src->x * src->x + src->y * src->y + src->z * src->z + src->w * src->w;
  if (mag == 0.0f) {
    mag = 1.0f;
  }
  norminv = 1.0f / mag;
  inv->x = -src->x * norminv;
  inv->y = -src->y * norminv;
  inv->z = -src->z * norminv;
  inv->w = src->w * norminv;
}

void C_QUATSlerp(const Quaternion *p, const Quaternion *q, Quaternion *r, f32 t) {
  f32 theta, sin_th, cos_th;
  f32 tp, tq = 1.0f;

  cos_th = p->x * q->x + p->y * q->y + p->z * q->z + p->w * q->w;
  if (cos_th < 0.0f) {
    cos_th = -cos_th;
    tq = -tq;
  }

  if (cos_th <= SKIES_QUAT_THRESH) {
    theta = acosf(cos_th);
    sin_th = sinf(theta);
    tp = sinf((1.0f - t) * theta) / sin_th;
    tq *= sinf(t * theta) / sin_th;
  } else {
    tp = 1.0f - t;
    tq *= t;
  }

  r->x = tp * p->x + tq * q->x;
  r->y = tp * p->y + tq * q->y;
  r->z = tp * p->z + tq * q->z;
  r->w = tp * p->w + tq * q->w;
}
