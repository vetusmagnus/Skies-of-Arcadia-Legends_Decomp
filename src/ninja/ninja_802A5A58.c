/* Sega Ninja library, 0x802A5A58-0x802A6184. Paired-single vertex transforms; fn_802A5F2C owns the
 * double at 0x8034D3B8. */

#include "ninja_lib.h"

asm void fn_802A5A58(register s32 n, register NJS_VECTOR* dst, register NJS_VECTOR* src) {
    nofralloc
    lwz r6, lbl_80347EB4(r13)
    li r0, 0x10
    psq_l f6, 0x0(r6), 0, 0
    psq_l f7, 0x8(r6), 0, 0
    psq_l f8, 0x10(r6), 0, 0
    psq_l f9, 0x18(r6), 0, 0
    psq_l f10, 0x20(r6), 0, 0
    psq_l f11, 0x28(r6), 0, 0
    mtctr r3
L_802A5A7C:
    dcbt r5, r0
    psq_l f12, 0x0(r5), 0, 0
    ps_mul f0, f6, f12
    ps_mul f1, f8, f12
    psq_l f13, 0x8(r5), 1, 0
    ps_mul f2, f10, f12
    ps_madd f3, f7, f13, f0
    ps_madd f4, f9, f13, f1
    ps_madd f5, f11, f13, f2
    ps_sum0 f3, f3, f3, f3
    psq_st f3, 0x0(r4), 1, 0
    ps_sum0 f4, f4, f4, f4
    psq_st f4, 0x4(r4), 1, 0
    ps_sum0 f5, f5, f5, f5
    psq_st f5, 0x8(r4), 1, 0
    lwz r3, 0xc(r5)
    addi r5, r5, 0x10
    stw r3, 0xc(r4)
    addi r4, r4, 0x10
    bdnz L_802A5A7C
    blr
}

asm void fn_802A5AD0(register s32 n, register NJS_VECTOR* dst, register NJS_VECTOR* src) {
    nofralloc
    lwz r6, lbl_80347EB4(r13)
    li r0, 0x10
    psq_l f6, 0x0(r6), 0, 0
    psq_l f7, 0x8(r6), 0, 0
    psq_l f8, 0x10(r6), 0, 0
    psq_l f9, 0x18(r6), 0, 0
    psq_l f10, 0x20(r6), 0, 0
    psq_l f11, 0x28(r6), 0, 0
    mtctr r3
L_802A5AF4:
    dcbt r5, r0
    psq_l f12, 0x0(r5), 0, 0
    ps_mul f0, f6, f12
    ps_mul f1, f8, f12
    psq_l f13, 0x8(r5), 1, 0
    ps_mul f2, f10, f12
    ps_madd f3, f7, f13, f0
    ps_madd f4, f9, f13, f1
    ps_madd f5, f11, f13, f2
    ps_sum0 f3, f3, f3, f3
    psq_st f3, 0x0(r4), 1, 0
    ps_sum0 f4, f4, f4, f4
    psq_st f4, 0x4(r4), 1, 0
    ps_sum0 f5, f5, f5, f5
    psq_st f5, 0x8(r4), 1, 0
    lwz r3, 0xc(r5)
    addi r5, r5, 0x10
    stw r3, 0xc(r4)
    addi r4, r4, 0x10
    bdnz L_802A5AF4
    blr
}

asm void fn_802A5B48(register s32 n, register NJS_VECTOR* dst, register NJS_VECTOR* src) {
    nofralloc
    stwu r1, -0x130(r1)
    stfd f31, 0x120(r1)
    psq_st f31, 0x128(r1), 0, 0
    stfd f30, 0x110(r1)
    psq_st f30, 0x118(r1), 0, 0
    stfd f29, 0x100(r1)
    psq_st f29, 0x108(r1), 0, 0
    stfd f28, 0xf0(r1)
    psq_st f28, 0xf8(r1), 0, 0
    stfd f27, 0xe0(r1)
    psq_st f27, 0xe8(r1), 0, 0
    stfd f26, 0xd0(r1)
    psq_st f26, 0xd8(r1), 0, 0
    stfd f25, 0xc0(r1)
    psq_st f25, 0xc8(r1), 0, 0
    stfd f24, 0xb0(r1)
    psq_st f24, 0xb8(r1), 0, 0
    stfd f23, 0xa0(r1)
    psq_st f23, 0xa8(r1), 0, 0
    stfd f22, 0x90(r1)
    psq_st f22, 0x98(r1), 0, 0
    stfd f21, 0x80(r1)
    psq_st f21, 0x88(r1), 0, 0
    stfd f20, 0x70(r1)
    psq_st f20, 0x78(r1), 0, 0
    stfd f19, 0x60(r1)
    psq_st f19, 0x68(r1), 0, 0
    stfd f18, 0x50(r1)
    psq_st f18, 0x58(r1), 0, 0
    stfd f17, 0x40(r1)
    psq_st f17, 0x48(r1), 0, 0
    stfd f16, 0x30(r1)
    psq_st f16, 0x38(r1), 0, 0
    stfd f15, 0x20(r1)
    psq_st f15, 0x28(r1), 0, 0
    stfd f14, 0x10(r1)
    psq_st f14, 0x18(r1), 0, 0
    lwz r6, lbl_80347EB4(r13)
    li r0, 0x1c
    psq_l f6, 0x0(r6), 0, 0
    psq_l f7, 0x8(r6), 0, 0
    psq_l f8, 0x10(r6), 0, 0
    psq_l f9, 0x18(r6), 0, 0
    psq_l f31, 0x20(r6), 0, 0
    psq_l f30, 0x28(r6), 0, 0
    mtctr r3
L_802A5C00:
    dcbt r5, r0
    psq_l f29, 0x0(r5), 0, 0
    ps_mul f0, f6, f29
    ps_mul f1, f8, f29
    psq_l f28, 0x8(r5), 1, 0
    ps_mul f2, f31, f29
    ps_madd f3, f7, f28, f0
    psq_l f29, 0xc(r5), 0, 0
    ps_madd f4, f9, f28, f1
    ps_madd f5, f30, f28, f2
    ps_sum0 f3, f3, f3, f3
    psq_st f3, 0x0(r4), 1, 0
    ps_sum0 f4, f4, f4, f4
    ps_sum0 f5, f5, f5, f5
    psq_st f4, 0x4(r4), 1, 0
    ps_mul f10, f6, f29
    psq_st f5, 0x8(r4), 1, 0
    ps_mul f11, f8, f29
    ps_mul f12, f31, f29
    psq_l f28, 0x14(r5), 1, 0
    ps_sum0 f10, f10, f10, f10
    ps_sum0 f11, f11, f11, f11
    ps_sum0 f12, f12, f12, f12
    ps_madd f13, f7, f28, f10
    psq_st f13, 0xc(r4), 1, 0
    ps_madd f14, f9, f28, f11
    ps_madd f15, f30, f28, f12
    psq_st f14, 0x10(r4), 1, 0
    lwz r3, 0x18(r5)
    stw r3, 0x18(r4)
    psq_st f15, 0x14(r4), 1, 0
    addi r4, r4, 0x1c
    addi r5, r5, 0x1c
    bdnz L_802A5C00
    psq_l f31, 0x128(r1), 0, 0
    lfd f31, 0x120(r1)
    psq_l f30, 0x118(r1), 0, 0
    lfd f30, 0x110(r1)
    psq_l f29, 0x108(r1), 0, 0
    lfd f29, 0x100(r1)
    psq_l f28, 0xf8(r1), 0, 0
    lfd f28, 0xf0(r1)
    psq_l f27, 0xe8(r1), 0, 0
    lfd f27, 0xe0(r1)
    psq_l f26, 0xd8(r1), 0, 0
    lfd f26, 0xd0(r1)
    psq_l f25, 0xc8(r1), 0, 0
    lfd f25, 0xc0(r1)
    psq_l f24, 0xb8(r1), 0, 0
    lfd f24, 0xb0(r1)
    psq_l f23, 0xa8(r1), 0, 0
    lfd f23, 0xa0(r1)
    psq_l f22, 0x98(r1), 0, 0
    lfd f22, 0x90(r1)
    psq_l f21, 0x88(r1), 0, 0
    lfd f21, 0x80(r1)
    psq_l f20, 0x78(r1), 0, 0
    lfd f20, 0x70(r1)
    psq_l f19, 0x68(r1), 0, 0
    lfd f19, 0x60(r1)
    psq_l f18, 0x58(r1), 0, 0
    lfd f18, 0x50(r1)
    psq_l f17, 0x48(r1), 0, 0
    lfd f17, 0x40(r1)
    psq_l f16, 0x38(r1), 0, 0
    lfd f16, 0x30(r1)
    psq_l f15, 0x28(r1), 0, 0
    lfd f15, 0x20(r1)
    psq_l f14, 0x18(r1), 0, 0
    lfd f14, 0x10(r1)
    addi r1, r1, 0x130
    blr
}

asm void fn_802A5D20(register s32 n, register NJS_VECTOR* dst, register NJS_VECTOR* src) {
    nofralloc
    stwu r1, -0x130(r1)
    stfd f31, 0x120(r1)
    psq_st f31, 0x128(r1), 0, 0
    stfd f30, 0x110(r1)
    psq_st f30, 0x118(r1), 0, 0
    stfd f29, 0x100(r1)
    psq_st f29, 0x108(r1), 0, 0
    stfd f28, 0xf0(r1)
    psq_st f28, 0xf8(r1), 0, 0
    stfd f27, 0xe0(r1)
    psq_st f27, 0xe8(r1), 0, 0
    stfd f26, 0xd0(r1)
    psq_st f26, 0xd8(r1), 0, 0
    stfd f25, 0xc0(r1)
    psq_st f25, 0xc8(r1), 0, 0
    stfd f24, 0xb0(r1)
    psq_st f24, 0xb8(r1), 0, 0
    stfd f23, 0xa0(r1)
    psq_st f23, 0xa8(r1), 0, 0
    stfd f22, 0x90(r1)
    psq_st f22, 0x98(r1), 0, 0
    stfd f21, 0x80(r1)
    psq_st f21, 0x88(r1), 0, 0
    stfd f20, 0x70(r1)
    psq_st f20, 0x78(r1), 0, 0
    stfd f19, 0x60(r1)
    psq_st f19, 0x68(r1), 0, 0
    stfd f18, 0x50(r1)
    psq_st f18, 0x58(r1), 0, 0
    stfd f17, 0x40(r1)
    psq_st f17, 0x48(r1), 0, 0
    stfd f16, 0x30(r1)
    psq_st f16, 0x38(r1), 0, 0
    stfd f15, 0x20(r1)
    psq_st f15, 0x28(r1), 0, 0
    stfd f14, 0x10(r1)
    psq_st f14, 0x18(r1), 0, 0
    lwz r6, lbl_80347EB4(r13)
    li r0, 0x1c
    psq_l f6, 0x0(r6), 0, 0
    psq_l f7, 0x8(r6), 0, 0
    psq_l f8, 0x10(r6), 0, 0
    psq_l f9, 0x18(r6), 0, 0
    psq_l f31, 0x20(r6), 0, 0
    psq_l f30, 0x28(r6), 0, 0
    mtctr r3
L_802A5DD8:
    dcbt r5, r0
    psq_l f29, 0x0(r5), 0, 0
    ps_mul f0, f6, f29
    ps_mul f1, f8, f29
    psq_l f28, 0x8(r5), 1, 0
    ps_mul f2, f31, f29
    ps_madd f3, f7, f28, f0
    psq_l f29, 0xc(r5), 0, 0
    ps_madd f4, f9, f28, f1
    ps_madd f5, f30, f28, f2
    ps_sum0 f3, f3, f3, f3
    psq_st f3, 0x0(r4), 1, 0
    ps_sum0 f4, f4, f4, f4
    ps_sum0 f5, f5, f5, f5
    psq_st f4, 0x4(r4), 1, 0
    ps_mul f10, f6, f29
    psq_st f5, 0x8(r4), 1, 0
    ps_mul f11, f8, f29
    ps_mul f12, f31, f29
    psq_l f28, 0x14(r5), 1, 0
    ps_sum0 f10, f10, f10, f10
    ps_sum0 f11, f11, f11, f11
    ps_sum0 f12, f12, f12, f12
    ps_madd f13, f7, f28, f10
    psq_st f13, 0xc(r4), 1, 0
    ps_madd f14, f9, f28, f11
    ps_madd f15, f30, f28, f12
    psq_st f14, 0x10(r4), 1, 0
    lwz r3, 0x18(r5)
    stw r3, 0x18(r4)
    psq_st f15, 0x14(r4), 1, 0
    addi r4, r4, 0x1c
    addi r5, r5, 0x1c
    bdnz L_802A5DD8
    psq_l f31, 0x128(r1), 0, 0
    lfd f31, 0x120(r1)
    psq_l f30, 0x118(r1), 0, 0
    lfd f30, 0x110(r1)
    psq_l f29, 0x108(r1), 0, 0
    lfd f29, 0x100(r1)
    psq_l f28, 0xf8(r1), 0, 0
    lfd f28, 0xf0(r1)
    psq_l f27, 0xe8(r1), 0, 0
    lfd f27, 0xe0(r1)
    psq_l f26, 0xd8(r1), 0, 0
    lfd f26, 0xd0(r1)
    psq_l f25, 0xc8(r1), 0, 0
    lfd f25, 0xc0(r1)
    psq_l f24, 0xb8(r1), 0, 0
    lfd f24, 0xb0(r1)
    psq_l f23, 0xa8(r1), 0, 0
    lfd f23, 0xa0(r1)
    psq_l f22, 0x98(r1), 0, 0
    lfd f22, 0x90(r1)
    psq_l f21, 0x88(r1), 0, 0
    lfd f21, 0x80(r1)
    psq_l f20, 0x78(r1), 0, 0
    lfd f20, 0x70(r1)
    psq_l f19, 0x68(r1), 0, 0
    lfd f19, 0x60(r1)
    psq_l f18, 0x58(r1), 0, 0
    lfd f18, 0x50(r1)
    psq_l f17, 0x48(r1), 0, 0
    lfd f17, 0x40(r1)
    psq_l f16, 0x38(r1), 0, 0
    lfd f16, 0x30(r1)
    psq_l f15, 0x28(r1), 0, 0
    lfd f15, 0x20(r1)
    psq_l f14, 0x18(r1), 0, 0
    lfd f14, 0x10(r1)
    addi r1, r1, 0x130
    blr
}

void fn_802A5EF8(s32 count, NJS_POINT3* dst, NJS_POINT3* src) {
    PSMTXMultVecArray(lbl_80347EB4, src, dst, count);
}

/* 2^52, the int-to-double magic fn_802A5F2C loads with lfd (its own pool, 0x8034D3B8). */
const f64 lbl_8034D3B8 = 4503599627370496.0;

asm void fn_802A5F2C(register s32 n, register void* dst, register void* src, register u32 flag) {
    nofralloc
    stwu r1, -0x140(r1)
    stfd f31, 0x130(r1)
    psq_st f31, 0x138(r1), 0, 0
    stfd f30, 0x120(r1)
    psq_st f30, 0x128(r1), 0, 0
    stfd f29, 0x110(r1)
    psq_st f29, 0x118(r1), 0, 0
    stfd f28, 0x100(r1)
    psq_st f28, 0x108(r1), 0, 0
    stfd f27, 0xf0(r1)
    psq_st f27, 0xf8(r1), 0, 0
    stfd f26, 0xe0(r1)
    psq_st f26, 0xe8(r1), 0, 0
    stfd f25, 0xd0(r1)
    psq_st f25, 0xd8(r1), 0, 0
    stfd f24, 0xc0(r1)
    psq_st f24, 0xc8(r1), 0, 0
    stfd f23, 0xb0(r1)
    psq_st f23, 0xb8(r1), 0, 0
    stfd f22, 0xa0(r1)
    psq_st f22, 0xa8(r1), 0, 0
    stfd f21, 0x90(r1)
    psq_st f21, 0x98(r1), 0, 0
    stfd f20, 0x80(r1)
    psq_st f20, 0x88(r1), 0, 0
    stfd f19, 0x70(r1)
    psq_st f19, 0x78(r1), 0, 0
    stfd f18, 0x60(r1)
    psq_st f18, 0x68(r1), 0, 0
    stfd f17, 0x50(r1)
    psq_st f17, 0x58(r1), 0, 0
    stfd f16, 0x40(r1)
    psq_st f16, 0x48(r1), 0, 0
    stfd f15, 0x30(r1)
    psq_st f15, 0x38(r1), 0, 0
    stfd f14, 0x20(r1)
    psq_st f14, 0x28(r1), 0, 0
    lwz r7, lbl_80347EB4(r13)
    extrwi r6, r6, 8, 16
    lfs f6, lbl_80347ED8(r13)
    psq_l f7, 0x0(r7), 0, 0
    psq_l f8, 0x8(r7), 0, 0
    psq_l f9, 0x10(r7), 0, 0
    psq_l f13, 0x18(r7), 0, 0
    psq_l f31, 0x20(r7), 0, 0
    psq_l f30, 0x28(r7), 0, 0
L_802A5FE4:
    psq_l f26, 0x0(r5), 0, 0
    ps_mul f0, f7, f26
    ps_mul f1, f9, f26
    psq_l f27, 0x8(r5), 1, 0
    ps_mul f2, f31, f26
    ps_madd f3, f8, f27, f0
    psq_l f25, 0xc(r5), 0, 0
    ps_madd f4, f13, f27, f1
    ps_madd f5, f30, f27, f2
    psq_l f24, 0x14(r5), 1, 0
    lwz r8, 0x18(r5)
    lis r0, 0x4330
    ps_mul f10, f7, f25
    srwi r7, r8, 16
    stw r0, 0x10(r1)
    ps_mul f11, f9, f25
    lfd f26, lbl_8034D3B8(r2)
    ps_mul f12, f31, f25
    stw r7, 0x14(r1)
    ps_sum0 f10, f10, f10, f10
    ps_sum0 f11, f11, f11, f11
    lfd f27, 0x10(r1)
    clrlwi r0, r8, 16
    ps_sum0 f29, f3, f29, f3
    mulli r0, r0, 0x18
    fsubs f27, f27, f26
    ps_sum0 f12, f12, f12, f12
    ps_madd f25, f8, f24, f10
    add r7, r4, r0
    ps_madd f14, f13, f24, f11
    stfs f27, 0x8(r1)
    fmuls f27, f27, f6
    ps_sum1 f29, f4, f29, f4
    ps_merge00 f25, f25, f14
    stfs f27, 0x8(r1)
    ps_sum0 f28, f5, f28, f5
    ps_madd f24, f30, f24, f12
    psq_l f21, 0x8(r1), 1, 0
    cmpwi r6, 0x0
    addi r5, r5, 0x1c
    ps_merge00 f21, f21, f21
    bne L_802A60B0
    ps_mul f29, f21, f29
    ps_mul f28, f21, f28
    psq_st f29, 0x0(r7), 0, 0
    psq_st f28, 0x8(r7), 1, 0
    ps_mul f25, f21, f25
    ps_mul f24, f21, f24
    psq_st f25, 0xc(r7), 0, 0
    psq_st f24, 0x14(r7), 1, 0
    b L_802A60E0
L_802A60B0:
    psq_l f26, 0x0(r7), 0, 0
    psq_l f27, 0x8(r7), 1, 0
    ps_madd f26, f29, f21, f26
    psq_l f23, 0xc(r7), 0, 0
    ps_madd f27, f28, f21, f27
    psq_l f22, 0x14(r7), 1, 0
    ps_madd f23, f25, f21, f25
    psq_st f26, 0x0(r7), 0, 0
    ps_madd f22, f24, f21, f24
    psq_st f27, 0x8(r7), 1, 0
    psq_st f23, 0xc(r7), 0, 0
    psq_st f22, 0x14(r7), 1, 0
L_802A60E0:
    nop
    subic. r3, r3, 0x1
    bne L_802A5FE4
    psq_l f31, 0x138(r1), 0, 0
    lfd f31, 0x130(r1)
    psq_l f30, 0x128(r1), 0, 0
    lfd f30, 0x120(r1)
    psq_l f29, 0x118(r1), 0, 0
    lfd f29, 0x110(r1)
    psq_l f28, 0x108(r1), 0, 0
    lfd f28, 0x100(r1)
    psq_l f27, 0xf8(r1), 0, 0
    lfd f27, 0xf0(r1)
    psq_l f26, 0xe8(r1), 0, 0
    lfd f26, 0xe0(r1)
    psq_l f25, 0xd8(r1), 0, 0
    lfd f25, 0xd0(r1)
    psq_l f24, 0xc8(r1), 0, 0
    lfd f24, 0xc0(r1)
    psq_l f23, 0xb8(r1), 0, 0
    lfd f23, 0xb0(r1)
    psq_l f22, 0xa8(r1), 0, 0
    lfd f22, 0xa0(r1)
    psq_l f21, 0x98(r1), 0, 0
    lfd f21, 0x90(r1)
    psq_l f20, 0x88(r1), 0, 0
    lfd f20, 0x80(r1)
    psq_l f19, 0x78(r1), 0, 0
    lfd f19, 0x70(r1)
    psq_l f18, 0x68(r1), 0, 0
    lfd f18, 0x60(r1)
    psq_l f17, 0x58(r1), 0, 0
    lfd f17, 0x50(r1)
    psq_l f16, 0x48(r1), 0, 0
    lfd f16, 0x40(r1)
    psq_l f15, 0x38(r1), 0, 0
    lfd f15, 0x30(r1)
    psq_l f14, 0x28(r1), 0, 0
    lfd f14, 0x20(r1)
    addi r1, r1, 0x140
    blr
}
