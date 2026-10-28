#include "dolphin/mtx.h"
#include <math.h>

#define SKIES_QUAT_THRESH 0.99999f

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
