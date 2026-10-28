#include "dolphin/mtx.h"

asm void PSVECSubtract(const register Vec *a, const register Vec *b, register Vec *a_b) {
  // clang-format off
  nofralloc;
  psq_l f2, 0(a), 0, 0;
  psq_l f4, 0(b), 0, 0;
  ps_sub f6, f2, f4;
  psq_st f6, 0(a_b), 0, 0;
  psq_l f3, 8(a), 1, 0;
  psq_l f5, 8(b), 1, 0;
  ps_sub f7, f3, f5;
  psq_st f7, 8(a_b), 1, 0;
  blr;
  // clang-format on
}

void PSVECNormalize(const register Vec *vec1, register Vec *ret) {
  register f32 half = 0.5f;
  register f32 three = 3.0f;
  register f32 xx_zz, xx_yy;
  register f32 square_sum;
  register f32 ret_sqrt;
  register f32 n_0, n_1;

  // clang-format off
  asm {
    psq_l       f2, 0(vec1), 0, 0;
    ps_mul      xx_yy, f2, f2;
    psq_l       f3, 8(vec1), 1, 0;
    ps_madd     xx_zz, f3, f3, xx_yy;
    ps_sum0     square_sum, xx_zz, f3, xx_yy;
    frsqrte     ret_sqrt, square_sum;
    fmuls       n_0, ret_sqrt, ret_sqrt;
    fmuls       n_1, ret_sqrt, half;
    fnmsubs     n_0, n_0, square_sum, three;
    fmuls       ret_sqrt, n_0, n_1;
    ps_muls0    f2, f2, ret_sqrt;
    psq_st      f2, 0(ret), 0, 0;
    ps_muls0    f3, f3, ret_sqrt;
    psq_st      f3, 8(ret), 1, 0;
  }
  // clang-format on
}

asm f32 PSVECSquareMag(const register Vec *v) {
  // clang-format off
  nofralloc;
  psq_l f0, 0(v), 0, 0;
  ps_mul f0, f0, f0;
  lfs f1, 8(v);
  ps_madd f1, f1, f1, f0;
  ps_sum0 f1, f1, f0, f0;
  blr;
  // clang-format on
}

f32 PSVECMag(const register Vec *v) {
  register f32 v_xy, v_z, sq, zero, rsq, t, three, half = 0.5f;

  // clang-format off
  asm {
    psq_l v_xy, 0(v), 0, 0;
    ps_mul v_xy, v_xy, v_xy;
    lfs v_z, 8(v);
    fsubs zero, half, half;
    ps_madd sq, v_z, v_z, v_xy;
    ps_sum0 sq, sq, v_xy, v_xy;
  }
  // clang-format on

  if (sq != zero) {
    // clang-format off
    asm {
      frsqrte rsq, sq;
    }
    // clang-format on
    three = 3.0f;
    // clang-format off
    asm {
      fmuls t, rsq, rsq;
      fmuls rsq, rsq, half;
      fnmsubs t, t, sq, three;
      fmuls rsq, t, rsq;
      fmuls sq, sq, rsq;
    }
    // clang-format on
  }
  return sq;
}

asm f32 PSVECDotProduct(const register Vec *a, const register Vec *b) {
  // clang-format off
  nofralloc;
  psq_l f2, 4(a), 0, 0;
  psq_l f3, 4(b), 0, 0;
  ps_mul f2, f2, f3;
  psq_l f5, 0(a), 0, 0;
  psq_l f4, 0(b), 0, 0;
  ps_madd f3, f5, f4, f2;
  ps_sum0 f1, f3, f2, f2;
  blr;
  // clang-format on
}

asm void PSVECCrossProduct(register const Vec *a, register const Vec *b, register Vec *axb) {
  // clang-format off
  nofralloc
  psq_l          f1, 0(b), 0, 0
  lfs            f2, 8(a)
  psq_l          f0, 0(a), 0, 0
  ps_merge10     f6, f1, f1
  lfs            f3, 8(b)
  ps_mul         f4, f1, f2
  ps_muls0       f7, f1, f0
  ps_msub        f5, f0, f3, f4
  ps_msub        f8, f0, f6, f7
  ps_merge11     f9, f5, f5
  ps_merge01     f10, f5, f8
  psq_st         f9, 0(axb), 1, 0
  ps_neg         f10, f10
  psq_st         f10, 4(axb), 0, 0
  blr
  // clang-format on
}
