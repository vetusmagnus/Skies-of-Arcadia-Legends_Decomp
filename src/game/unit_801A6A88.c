#include "game/shop.h"

const u32 lbl_802B6A18[19] = {
    0x001E001F, 0x00200021, 0x00220023, 0x00240026, 0x00250027, 0x00280029,
    0x002A002B, 0x002C002D, 0x002E002F, 0x00300031, 0x00320033, 0x00340035,
    0x000F0010, 0x00110012, 0x00130014, 0x000E000F, 0x00100011, 0x00120013,
    0x00140035,
};
const LayoutPart lbl_802B6A64[7] = {
    {0x3, 0x27, 16.0f, 12.0f, -37.5f, 0x0, 0x1},
    {0x3, 0x34, 336.0f, 12.0f, -37.5f, 0x0, 0x1},
    {0x3, 0x27, 16.0f, 12.0f, -37.5f, 0x0, 0x1},
    {0x3, 0x34, 336.0f, 12.0f, -37.5f, 0x0, 0x1},
    {0x3, 0x33, 16.0f, 12.0f, -37.5f, 0x0, 0x1},
    {0x3, 0x34, 16.0f, 12.0f, -37.5f, 0x0, 0x1},
    {0x3, 0x24, 16.0f, 12.0f, -37.5f, 0x0, 0x1},
};
const u32 lbl_802B6AF0[4] = {
    0x001E0024, 0x00260025, 0x002F0033, 0x00350034,
};
const u32 lbl_802B6B00[3] = {
    0x001E001F, 0x00200021, 0x00220023,
};
const LayoutPart lbl_802B6B0C[4] = {
    {0x0, 0x38, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2, 0.0f, 41.0f, -40.0f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -50.0f, 0x1, 0x0},
    {0x0, 0x5, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
};
const LayoutPart lbl_802B6B5C[4] = {
    {0x0, 0x39, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x25, 0.0f, 1e+01f, -4e+01f, 0x0, 0x1},
    {0x1, 0x9, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x4, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B6BAC[4] = {
    {0x0, 0x3A, 16.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0xB, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x28, 88.0f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B6BFC[4] = {
    {0x0, 0x3B, 16.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0xB, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x28, 88.0f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B6C4C[4] = {
    {0x0, 0x3F, 16.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0xB, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x28, 88.0f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B6C9C[4] = {
    {0x0, 0x3C, 16.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0xB, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x23, 88.0f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B6CEC[4] = {
    {0x0, 0x52, 16.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0xB, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x23, 88.0f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B6D3C[4] = {
    {0x0, 0x3D, 16.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0xB, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x23, 88.0f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B6D8C[1] = {
    {0x0, 0x5, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutDef lbl_802B6DA0[6] = {
    {lbl_802B6BAC, 0x4},
    {lbl_802B6BFC, 0x4},
    {lbl_802B6C4C, 0x4},
    {lbl_802B6C9C, 0x4},
    {lbl_802B6D3C, 0x4},
    {lbl_802B6CEC, 0x4},
};
const LayoutPart lbl_802B6DD0[2] = {
    {0x0, 0x1C, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x1, 0x4, 0.0f, 0.0f, -50.0f, 0x1, 0x0},
};
const LayoutPart lbl_802B6DF8[4] = {
    {0x0, 0x42, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2A, 0.0f, 4.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x6, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x5, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B6E48[8] = {
    {0x0, 0x16, 0.0f, 2.0f, -43.0f, 0x1, 0x1},
    {0x0, 0x15, 0.0f, 166.0f, -42.5f, 0x1, 0x1},
    {0x1, 0x3, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x1, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
    {0x0, 0x16, 0.0f, 2.0f, -43.0f, 0x1, 0x1},
    {0x0, 0x15, 0.0f, 166.0f, -42.5f, 0x1, 0x1},
    {0x1, 0x3, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x1, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B6EE8[4] = {
    {0x0, 0x50, 0.0f, 2.0f, -2e+03f, 0x1, 0x1},
    {0x0, 0x51, 0.0f, 214.0f, -2e+03f, 0x1, 0x1},
    {0x1, 0xB, 0.0f, 0.0f, -3e+03f, 0x1, 0x0},
    {0x0, 0x4F, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B6F38[10] = {
    {0x0, 0x40, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2F, 0.0f, 4.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x7, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x3, 0xE, 2.5e+02f, 6.0f, -37.15f, 0x0, 0x1},
    {0x3, 0xF, 304.0f, 6.0f, -37.2f, 0x0, 0x1},
    {0x3, 0x10, 358.0f, 6.0f, -37.25f, 0x0, 0x1},
    {0x3, 0x11, 412.0f, 6.0f, -37.3f, 0x0, 0x1},
    {0x3, 0x12, 466.0f, 6.0f, -37.35f, 0x0, 0x1},
    {0x3, 0x13, 5.2e+02f, 6.0f, -37.4f, 0x0, 0x1},
    {0x3, 0x14, 574.0f, 6.0f, -37.45f, 0x0, 0x1},
};
const LayoutPart lbl_802B7000[6] = {
    {0x0, 0x41, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x30, 0.0f, 4.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x8, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x3, 0xE, 2.5e+02f, 6.0f, -37.35f, 0x0, 0x1},
    {0x3, 0x12, 304.0f, 6.0f, -37.4f, 0x0, 0x1},
    {0x3, 0x17, 358.0f, 6.0f, -37.45f, 0x0, 0x1},
};
const LayoutPart lbl_802B7078[7] = {
    {0x0, 0x41, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x31, 0.0f, 4.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x8, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x3, 0xF, 2.5e+02f, 6.0f, -37.3f, 0x0, 0x1},
    {0x3, 0x11, 304.0f, 6.0f, -37.35f, 0x0, 0x1},
    {0x3, 0x13, 358.0f, 6.0f, -37.4f, 0x0, 0x1},
    {0x3, 0x14, 412.0f, 6.0f, -37.45f, 0x0, 0x1},
};
const LayoutPart lbl_802B7104[3] = {
    {0x0, 0x41, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x32, 0.0f, 4.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x8, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B7140[2] = {
    {0x0, 0x48, 83.0f, -11.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x4A, 83.0f, -11.0f, -32.4f, 0x1, 0x1},
};
const LayoutPart lbl_802B7168[1] = {
    {0x0, 0x49, 83.0f, -11.0f, -32.45f, 0x1, 0x1},
};
const LayoutDef lbl_802B717C[4] = {
    {lbl_802B6F38, 0xA},
    {lbl_802B7078, 0x7},
    {lbl_802B7000, 0x6},
    {lbl_802B7104, 0x3},
};
const LayoutPart lbl_802B719C[4] = {
    {0x0, 0x8, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
    {0x0, 0x9, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
    {0x0, 0x9, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
    {0x0, 0x9, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
};
const LayoutPart lbl_802B71EC[3] = {
    {0x0, 0x15, 0.0f, 164.0f, -42.5f, 0x1, 0x1},
    {0x1, 0x3, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x1, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B7228[2] = {
    {0x0, 0x25, 68.0f, -26.0f, 0.0f, 0x1, 0x1},
    {0x0, 0x17, 0.0f, -26.0f, -0.2f, 0x1, 0x1},
};
const LayoutPart lbl_802B7250[2] = {
    {0x0, 0x47, 116.0f, -26.0f, 0.0f, 0x1, 0x1},
    {0x0, 0x18, 0.0f, -26.0f, -0.2f, 0x1, 0x1},
};
const LayoutPart lbl_802B7278[2] = {
    {0x0, 0x24, 164.0f, -26.0f, 0.0f, 0x1, 0x1},
    {0x0, 0x19, 0.0f, -26.0f, -0.2f, 0x1, 0x1},
};
const LayoutPart lbl_802B72A0[2] = {
    {0x0, 0x26, 212.0f, -26.0f, 0.0f, 0x1, 0x1},
    {0x0, 0x1A, 0.0f, -26.0f, -0.2f, 0x1, 0x1},
};
const LayoutPart lbl_802B72C8[2] = {
    {0x0, 0x35, 2.6e+02f, -26.0f, 0.0f, 0x1, 0x1},
    {0x0, 0x1B, 0.0f, -26.0f, -0.2f, 0x1, 0x1},
};
const LayoutPart lbl_802B72F0[1] = {
    {0x0, 0x16, 0.0f, 2.0f, 0.0f, 0x1, 0x1},
};
const LayoutDef lbl_802B7304[5] = {
    {lbl_802B7228, 0x2},
    {lbl_802B7250, 0x2},
    {lbl_802B7278, 0x2},
    {lbl_802B72A0, 0x2},
    {lbl_802B72C8, 0x2},
};
const LayoutPart lbl_802B732C[2] = {
    {0x0, 0x37, 53.0f, -25.0f, -5.0f, 0x1, 0x1},
    {0x0, 0x36, 95.0f, -25.0f, -5.0f, 0x1, 0x1},
};
const LayoutPart lbl_802B7354[2] = {
    {0x0, 0x4C, 24.0f, 156.0f, -5.0f, 0x1, 0x1},
    {0x0, 0x4D, 338.0f, 156.0f, -5.0f, 0x1, 0x1},
};
const LayoutPart lbl_802B737C[2] = {
    {0x0, 0x37, 14.0f, 17.0f, -5.0f, 0x1, 0x1},
    {0x0, 0x36, 54.0f, 17.0f, -5.0f, 0x1, 0x1},
};
const AnimDef lbl_802B73A4[5] = {
    {lbl_802B7354, 0x2, 0x0, 0x1, 0x2},
    {lbl_802B732C, 0x2, 0x1, 0x1, 0x2},
    {lbl_802B7354, 0x2, 0x0, 0x1, 0x2},
    {lbl_802B737C, 0x2, 0x1, 0x1, 0x2},
    {lbl_802B737C, 0x2, 0x1, 0x1, 0x2},
};
const LayoutPart lbl_802B73F4[4] = {
    {0x0, 0xE, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2B, 0.0f, 6.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x2, 0.0f, 0.0f, -5e+01f, 0x1, 0x1},
    {0x0, 0x3, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B7444[11] = {
    {0x0, 0x1D, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2C, 14.0f, 6.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x5, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x7, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
    {0x3, 0xE, 4.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0xF, 76.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x10, 148.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x11, 2.2e+02f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x12, 4.0f, 54.0f, -32.5f, 0x0, 0x1},
    {0x3, 0x13, 76.0f, 54.0f, -32.5f, 0x0, 0x1},
    {0x3, 0x14, 148.0f, 54.0f, -32.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7520[8] = {
    {0x0, 0xE, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2D, 0.0f, 6.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x2, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x3, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
    {0x3, 0xE, 9.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x12, 81.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x17, 153.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x35, 225.0f, 34.0f, -32.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B75C0[16] = {
    {0x0, 0xE, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2D, 0.0f, 6.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x2, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x3, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
    {0x3, 0xF, 9.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x11, 81.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x13, 153.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x14, 225.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x0, 0xE, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2E, -6.0f, 28.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x2, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x3, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
    {0x3, 0xF, 4.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x11, 76.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x13, 148.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x14, 2.2e+02f, 3e+01f, -32.5f, 0x0, 0x1},
};
const LayoutDef lbl_802B7700[4] = {
    {lbl_802B7444, 0xB},
    {lbl_802B75C0, 0x8},
    {lbl_802B7520, 0x8},
    {lbl_802B73F4, 0x4},
};
const LayoutPart lbl_802B7720[4] = {
    {0x0, 0x43, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2B, 6.0f, 2e+01f, -4e+01f, 0x0, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x0, 0x2, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B7770[3] = {
    {0x0, 0xD, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x0, 85.0f, 3e+01f, -4e+01f, 0x0, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B77AC[1] = {
    {0x0, 0x2, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
};
const LayoutPart lbl_802B77C0[3] = {
    {0x0, 0xC, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x1, 1e+02f, 13.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B77FC[7] = {
    {0x0, 0xF, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x10, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x11, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x12, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x13, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x14, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
    {0x0, 0x3E, 24.0f, -2.0f, -32.5f, 0x1, 0x1},
};
const u32 lbl_802B7888[3] = {
    0x45717569, 0x70706564, 0x00000000,
};
const LayoutDef lbl_802B7894[7] = {
    {lbl_802B7770, 0x3},
    {lbl_802B7770, 0x3},
    {lbl_802B7770, 0x3},
    {lbl_802B7770, 0x3},
    {lbl_802B7770, 0x3},
    {lbl_802B7770, 0x3},
    {lbl_802B77C0, 0x3},
};
const LayoutPart lbl_802B78CC[7] = {
    {0x0, 0xD, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2D, 6.0f, 6.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x3, 0xE, 16.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x12, 88.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x17, 1.6e+02f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x35, 232.0f, 34.0f, -32.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7958[7] = {
    {0x0, 0xD, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x2D, 6.0f, 6.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x3, 0xF, 16.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x11, 88.0f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x13, 1.6e+02f, 3e+01f, -32.5f, 0x0, 0x1},
    {0x3, 0x14, 232.0f, 3e+01f, -32.5f, 0x0, 0x1},
};
const LayoutDef lbl_802B79E4[2] = {
    {lbl_802B78CC, 0x7},
    {lbl_802B7958, 0x7},
};
const LayoutPart lbl_802B79F4[3] = {
    {0x0, 0xE, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
    {0x3, 0x24, 28.0f, 6.0f, -42.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7A30[2] = {
    {0x0, 0x27, 28.0f, 6.0f, -4e+01f, 0x1, 0x1},
    {0x3, 0x1B, 3e+01f, 3e+01f, -27.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7A58[2] = {
    {0x0, 0x28, 76.0f, 6.0f, -4e+01f, 0x1, 0x1},
    {0x3, 0x1C, 78.0f, 3e+01f, -27.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7A80[2] = {
    {0x0, 0x29, 172.0f, 6.0f, -4e+01f, 0x1, 0x1},
    {0x3, 0x1D, 174.0f, 3e+01f, -27.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7AA8[2] = {
    {0x0, 0x2A, 124.0f, 6.0f, -4e+01f, 0x1, 0x1},
    {0x3, 0x1E, 126.0f, 3e+01f, -27.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7AD0[2] = {
    {0x0, 0x2B, 2.2e+02f, 6.0f, -4e+01f, 0x1, 0x1},
    {0x3, 0x1F, 222.0f, 3e+01f, -27.5f, 0x0, 0x1},
};
const LayoutPart lbl_802B7AF8[2] = {
    {0x0, 0x2C, 268.0f, 6.0f, -4e+01f, 0x1, 0x1},
    {0x3, 0x20, 2.7e+02f, 3e+01f, -27.5f, 0x0, 0x1},
};
const LayoutDef lbl_802B7B20[6] = {
    {lbl_802B7A30, 0x2},
    {lbl_802B7A58, 0x2},
    {lbl_802B7AA8, 0x2},
    {lbl_802B7A80, 0x2},
    {lbl_802B7AD0, 0x2},
    {lbl_802B7AF8, 0x2},
};
const LayoutPart lbl_802B7B50[1] = {
    {0x0, 0x2, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutDef lbl_802B7B64[6] = {
    {lbl_802B7444, 0xB},
    {lbl_802B7444, 0xB},
    {lbl_802B75C0, 0x8},
    {lbl_802B75C0, 0x8},
    {lbl_802B75C0, 0x8},
    {lbl_802B75C0, 0x8},
};
const LayoutDef lbl_802B7B94[6] = {
    {lbl_802B7444, 0xB},
    {lbl_802B7444, 0xB},
    {lbl_802B7520, 0x8},
    {lbl_802B7520, 0x8},
    {lbl_802B75C0, 0x8},
    {lbl_802B75C0, 0x8},
};
const LayoutPart lbl_802B7BC4[3] = {
    {0x0, 0x43, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x22, 0.0f, 41.0f, -4e+01f, 0x0, 0x1},
    {0x1, 0x1, 0.0f, 0.0f, -5e+01f, 0x1, 0x0},
};
const LayoutPart lbl_802B7C00[1] = {
    {0x0, 0x2, 0.0f, 0.0f, -4e+03f, 0x1, 0x1},
};
const LayoutPart lbl_802B7C14[4] = {
    {0x0, 0x44, 0.0f, 0.0f, -42.5f, 0x1, 0x1},
    {0x3, 0x29, 12.0f, 9.0f, -40.0f, 0x0, 0x1},
    {0x1, 0xA, 0.0f, 0.0f, -50.0f, 0x1, 0x0},
    {0x0, 0xA, 0.0f, 0.0f, -4000.0f, 0x1, 0x1},
};
const char lbl_802B7C64[0x1C] = "Baltor the Black Bearded";
const char lbl_802B7C80[0x18] = "Rupee of the Larso Clan";
const char lbl_802B7C98[0x10] = "Gordo the Round";
const char lbl_802B7CA8[0x14] = "Loose Cannon Lapen";
const char lbl_802B7CBC[0x14] = "The Ixa'ness Demons";
const char lbl_802B7CD0[0x18] = "Vyse the Fallen Pirate";
const char lbl_802B7CE8[0x18] = "Daikokuya the Wealthy";
const char lbl_802B7D00[0x14] = "Lord Zivilyn Bane";
const char lbl_802B7D14[0x30] = "A despicable Pirate who will attack anything.";
const char lbl_802B7D44[0x2C] = "A Nasr Pirate who attack non-Nasr airships.";
const char lbl_802B7D70[0x30] = "A Pirate who will do anything for good food.";
const char lbl_802B7DA0[0x30] = "A loner who attacks using machines he built.";
const char lbl_802B7DD0[0x30] = "Female triplets who attack ships carrying men.";
const char lbl_802B7E00[0x34] = "A Pirate who thinks he can hide behind his name.";
const char lbl_802B7E34[0x30] = "A Pirate with enough money to buy the world.";
const char lbl_802B7E64[0x2C] = "The mysterious leader of a bandit tribe.";
const char lbl_802B7E90[0xF8] = "He is known for attacking\012towns and ships throughout\012the Mid Ocean area. He is\012known for a lack of mercy.\012His favorite tactic is to\012weaken his enemy using\012The Blackbeard, his ship,\012before boarding to loot.\012Beware the power of\012his ship's cannons.";
const char lbl_802B7F88[0xEC] = "Baltor, along with his\012ship, The Blackbeard, was\012defeated by Vyse the Blue\012Rogue, but managed to\012escape. Thanks to Vyse,\012trade routes through Nasr\012and Mid Ocean are much\012safer. Rumor has it that\012Baltor has sworn vengeance\012against Vyse.";
const char lbl_802B8074[0xF8] = "He is the leader of the\012legendary Larso Clan. The\012former leader recently\012passed away, so it was\012thought that they had\012disbanded, but they have\012recently attacked Maramba.\012They are known for fierce\012strength, so prepare to\012defend and heal yourself.";
const char lbl_802B816C[0xF8] = "The new leader of the\012Larso Clan was nothing but\012a young boy. In a strange\012turn of events, that same\012boy has given up life as a\012Pirate, and has joined his\012mother in her carpet\012making business. His giant\012of a bodyguard has also\012decided to join him.";
const char lbl_802B8264[0xF8] = "An Air Pirate that only\012attacks ships carrying\012food cargo in the North\012Ocean area. He has taken\012a liking to the spice\012trade between valua and\012Ixa'taka. Learning from\012his chefs, he uses fire to\012not only cook his meals,\012but his opponents as well.";
const char lbl_802B835C[0xD8] = "There have been reports\012that after being defeated\012by the Blue Rogue, Vyse,\012Gordo has given up his\012pirate life. Apparently,\012he has opened up his own\012restaurant, a perfect fit\012for the self-proclaimed\012\"Gourmet Pirate.\"";
const char lbl_802B8434[0xF4] = "Using Gunarm, a machine of\012his own creation, this\012Pirate seems to enjoy\012wanton destruction of\012property. But, even his\012machine is capable of\012producing a multitude of\012smaller drones, as well\012as having a large arsenal\012of weaponry stored inside.";
const char lbl_802B8528[0xF0] = "It is now known that Lapen\012is the adopted son of the\012Blue Rogue, Centime. After\012being defeated by Vyse,\012Lapen realized the error\012of his ways, and started a\012new life as an engineer.\012His goal is to one day\012surpass his own father in\012skill.";
const char lbl_802B8618[0xF4] = "They target only ships that\012have handsome men as crew\012members. Knowing that,\012some men who have been\012left behind in raids have\012been psychologically\012traumatized. They are\012fierce in battle, as each\012covers the weaknesses of\012the others. Be careful.";
const char lbl_802B870C[0xFC] = "According to reports from\012Vyse the Blue Rogue, the\012men who were thought to\012have been kidnapped did in\012fact go of their own\012volition. The triplets\012have, however, agreed to\012not cause any more trouble\012but will not give up their\012search for handsome men.";
const char lbl_802B8808[0xDC] = "Once thought to be a hero,\012the once-Blue-Rogue Vyse\012has been reported to be\012robbing the people of\012Nasrad, along with his two\012female accomplices.\012Perhaps Vyse is nothing\012but a lowly scumbag of a\012Black Pirate after all.";
const char lbl_802B88E4[0xDC] = "It has been revealed that\012it was not Vyse who\012committed all those\012dastardly deeds, but a\012fake who used his name to\012further his own greed. The\012fake has decided to give\012up Piracy, and has started\012a Vyse look-alike show.";
const char lbl_802B89C0[0xFC] = "Riding aboard a gawdy ship\012plated in gold, this\012Pirate has been known to\012attack all who cross his\012path. A wealthy Yafutoman,\012he has been seen traveling\012near the Lands of Ice. It\012is said that he throws\012money at his opponents,\012confusing them in a fight.";
const char lbl_802B8ABC[0xF4] = "Lost in the Lands of Ice\012region, he was rescued by\012the Blue Rogue, Vyse. He\012promised not to cause any\012more trouble, but refused\012to give up on his dream to\012travel the world. He has\012been spotted in various\012cities buying gifts by\012the boatload.";
const char lbl_802B8BB0[0xF4] = "The supposed leader of an\012infamous clan of bandits,\012nothing is known about his\012true identity. Nobody\012knows where he is from.\012Little is known about his\012fighting tactics, other\012than his use of \"Explosive\012Powder.\" Avoid this attack\012at all costs.";
const char lbl_802B8CA4[0xB8] = "Rumor has it that Vyse\012defeated him on the new\012continent, Soltis, but it\012has yet to be confirmed.\012Perhaps now nobody will\012ever know his true\012identity, now that he is\012gone for good.";
const char lbl_802B8D5C[0xC] = "Buy Info.";
const char lbl_802B8D68[0xC] = "Sell Info.";
const char lbl_802B8D74[0xC] = "Wanted List";
const char lbl_802B8D80[0x14] = "Nothing Equipped";
const char lbl_802B8D94[0x14] = "Cannot Be Equipped";
const char lbl_802B8DA8[0x14] = "Already Equipped";
const char lbl_802B8DBC[0x10] = "Cannot Be Sold";
const char lbl_802B8DCC[0x14] = "Cannot Change Color";
const char lbl_802B8DE0[0x10] = "No Ship Owned";
const char lbl_802B8DF0[0x10] = "No Info to Buy";
const char lbl_802B8E00[0x10] = "No Info to Sell";
const char lbl_802B8E10[0x10] = "Found By Vyse";
const u32 lbl_802B8E20[5] = {
    0x466F756E, 0x64204279, 0x20446F6D, 0x696E676F, 0x00000000,
};
const u32 lbl_802B8E34[6] = {
    0xFF20FF0A, 0xFFFF4020, 0xFFC800FF, 0xFF0096FF, 0xFFFFC800, 0xFFDCDCDC,
};
const ShopCmpPos lbl_802B8E4C[14] = {
    {240.0f, 0.0f},
    {294.0f, 0.0f},
    {348.0f, 0.0f},
    {402.0f, 0.0f},
    {456.0f, 0.0f},
    {510.0f, 0.0f},
    {564.0f, 0.0f},
    {41.0f, 0.0f},
    {113.0f, 0.0f},
    {185.0f, 0.0f},
    {257.0f, 0.0f},
    {41.0f, 24.0f},
    {113.0f, 24.0f},
    {185.0f, 24.0f},
};
const s16 lbl_802B8EBC[8] = {0xF0, 0x126, 0x15C, 0x1AE, 0x29, 0x71, 0xB9, 0x118};
const s16 lbl_802B8ECC[8] = {0xF0, 0x126, 0x15C, 0x192, 0x29, 0x71, 0xB9, 0x101};


void fn_801A6A88(Task_801A6A88 *t, u16 idx, f32 off) {
    extern void TextPrintNumber(s32 x, s32 y, s32 value, u32 flags);
    f32 z = TextGetZ();
    TextPushColor();
    TextSetColor(0xFF2222F0);
    TextSetZ(-27.5f + t->ctx->h[idx]->ui->o.z);
    TextPrint((s32)(336.0f + (t->ctx->h[idx]->ui->o.x + t->ctx->h[idx]->ui->o.rdx)),
              (s32)(off + (t->ctx->h[idx]->ui->o.y - t->ctx->h[idx]->ui->o.rdy)), "\x81\x7e");
    TextPrintNumber((s32)(360.0f + (t->ctx->h[idx]->ui->o.x + t->ctx->h[idx]->ui->o.rdx)),
                    (s32)(off + (t->ctx->h[idx]->ui->o.y - t->ctx->h[idx]->ui->o.rdy)), t->ctx->h4, 0xC002);
    TextPopColor(1);
    TextSetZ(z);
}

void fn_801A6BDC(ShopTask* t) {
    extern void TextPrintNumber(s32 x, s32 y, s32 value, u32 flags);
    f32 z;
    f32 y;
    f32 a;
    ShopPart* p;
    ShopEntry* e;
    u16 price;
    s32 page;
    s32 row;
    s32 i;
    u32 n;
    s32 d;
    u8 d8;
    s32 cmd;
    s32 old;
    s32 cnt;
    UiObj* o;

    switch (t->w->state) {
    case 0:
        fn_801C12C8();
        fn_801AB580((Self_801AB580*)t);
        t->w->parts[4]->flag->b0 = 1;
        t->w->parts[5]->flag->b0 = 1;
        t->w->parts[7] = (ShopPart*)fn_801B6320(t, -4450.0f);
        t->w->parts[8] = (ShopPart*)fn_801B5C4C(t);
        t->w->parts[9] = (ShopPart*)fn_801B54D4(t);
        t->w->parts[2] = (ShopPart*)fn_801B2678(t, 0);
        t->w->parts[2]->flag->b0 = 1;
        t->w->parts[8]->list->page = 0;
        t->w->parts[8]->list->row = 0;
        t->w->qty = 1;
        t->w->state = 1;
        SHOP_LIST_SET_Y(t->w->parts[8]);
    case 1:
        UiObjMoveTo(&t->w->parts[7]->obj->o, 6, -1, 24.0f, 384.0f);
        UiObjSetCommand(&t->w->parts[7]->obj->o, 15, 0);
        SHOP_CUR_ENTRY(e, t, t->w->parts[8]);
        fn_801B6400(fn_801F48AC(e->id));
        UiObjMoveToX(&t->w->parts[8]->obj->o, 6, -1, 240.0f);
        UiObjSetCommand(&t->w->parts[8]->obj->o, 15, 0);
        SHOP_CUR_ENTRY(e, t, t->w->parts[8]);
        fn_801B5644(t->w->parts[9], e->id);
        t->w->state = 2;
        break;
    case 2:
        if (UiObjIsBusy(&t->w->parts[7]->obj->o) == 0 || PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
            t->w->state = 3;
        }
        break;
    case 3:
        p = t->w->parts[8];
        page = p->list->page;
        row = p->list->row;
        if (fn_801C09F8(0, 1)) {
            t->w->state = 0x18;
            t->w->parts[8]->x38->state = 0;
            MenuPlaySe(5);
        } else {
            if (fn_801C09F8(0, 4)) {
                if (p->list->row == 0) {
                    p->list->row = 5;
                    for (i = 0; i < 6 - p->list->row; i++) {
                        if (t->buf->out[(u8)p->list->page * 6 + (u8)p->list->row].id != -1) {
                            break;
                        }
                        p->list->row--;
                    }
                } else {
                    p->list->row--;
                }
            } else if (fn_801C09F8(0, 5)) {
                p->list->row++;
                if (p->list->row == 6) {
                    p->list->row = 0;
                }
                SHOP_CUR_ENTRY(e, t, p);
                if (e->id == -1) {
                    p->list->row = 0;
                }
            } else {
                if (fn_801C09F8(0, 6)) {
                    if (p->list->page == 0) {
                        p->list->page = t->buf->pages;
                    }
                    p->list->page--;
                    if (page != p->list->page) {
                        t->w->parts[8]->x38->angle = 0;
                    }
                } else if (fn_801C09F8(0, 7)) {
                    p->list->page++;
                    if (p->list->page == t->buf->pages) {
                        p->list->page = 0;
                    }
                    if (page != p->list->page) {
                        t->w->parts[8]->x38->angle = 0;
                    }
                } else {
                    goto no_move;
                }
                SHOP_CUR_ENTRY(e, t, p);
                if (e->id == -1) {
                    for (i = 0; i < 6 - p->list->row; i++) {
                        if (t->buf->out[(u8)p->list->page * 6 + (u8)p->list->row].id != -1) {
                            break;
                        }
                        p->list->row--;
                    }
                }
            }
            if (page != p->list->page || row != p->list->row) {
                MenuPlaySe(4);
            }
            p = t->w->parts[8];
            SHOP_CUR_ENTRY(e, t, p);
            fn_801B571C(t->w->parts[9], e->id);
            p->list->angle = 0;
            goto tail3;
        no_move: /* no direction pressed */
            if (PAD_A) {
            SHOP_CUR_ENTRY(e, t, t->w->parts[8]);
            if (e->flag == 0) {
                t->w->item = e->id;
                fn_801C0FBC(t->w->item);
                t->w->qty = 1;
                price = fn_801F477C(t->w->item);
                t->w->cost = price * t->w->qty;
                t->w->left = (s32)(lbl_8030B7F4.w34c - t->w->cost) <= 0 ? 0 : lbl_8030B7F4.w34c - t->w->cost;
                UiObjMoveToX(&t->w->parts[9]->obj->o, 6, -1, -624.0f);
                UiObjSetCommand(&t->w->parts[9]->obj->o, 15, 0);
                t->w->parts[2]->flag->b0 = 0;
                UiObjMoveToX(&t->w->parts[2]->obj->o, 6, -1, -8.0f);
                UiObjSetCommand(&t->w->parts[2]->obj->o, 15, 1);
                t->w->parts[8]->x38->state = 0;
                fn_801C08B4(2);
                t->w->state = 4;
            } else {
                fn_801C08B4(3);
            }
            }
        }
    tail3:
        SHOP_LIST_SET_Y(t->w->parts[8]);
        SHOP_CUR_ENTRY(e, t, t->w->parts[8]);
        fn_801B6400(fn_801F48AC(e->id));
        break;
    case 4:
        if (UiObjIsBusy(&t->w->parts[2]->obj->o) == 0 && UiObjIsBusy(&t->w->parts[9]->obj->o) == 0) {
            t->w->state = 5;
            t->w->parts[9]->flag->b0 = 1;
            t->w->parts[8]->list->part = 1;
        } else if (PAD_A) {
            MenuPartsFinish((MenuTask*)t);
        }
        break;
    case 5:
        if (fn_801C09F8(0, 1)) {
            t->w->state = 9;
            MenuPlaySe(5);
        back_to_list:
            ShopBackToList(t);
            break;
        }
        if (fn_801C09F8(0, 4)) {
            t->w->qty = fn_801AB82C(8, t->w->qty, t->w->item);
        } else if (fn_801C09F8(0, 5)) {
            t->w->qty = fn_801AB82C(4, t->w->qty, t->w->item);
        } else if (fn_801C09F8(0, 6)) {
            t->w->qty = fn_801AB82C(1, t->w->qty, t->w->item);
        } else if (fn_801C09F8(0, 7)) {
            t->w->qty = fn_801AB82C(2, t->w->qty, t->w->item);
        } else if (PAD_A) {
            t->w->state = 6;
            t->w->parts[8]->list->part = 0xFF;
            MenuPlaySe(2);
            fn_801C08B4(0x19);
        }
        y = t->w->parts[8]->list->row * 24 + 12;
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF2222F0);
        TextSetZ(-27.5f + t->w->parts[8]->obj->o.z);
        TextPrint((s32)(336.0f + (t->w->parts[8]->obj->o.x + t->w->parts[8]->obj->o.rdx)),
                  (s32)(y + (t->w->parts[8]->obj->o.y - t->w->parts[8]->obj->o.rdy)), "\x81\x7e");
        TextPrintNumber((s32)(360.0f + (t->w->parts[8]->obj->o.x + t->w->parts[8]->obj->o.rdx)),
                        (s32)(y + (t->w->parts[8]->obj->o.y - t->w->parts[8]->obj->o.rdy)), t->w->qty, 0xC002);
        TextPopColor(1);
        TextSetZ(z);
        price = fn_801F477C(t->w->item);
        t->w->cost = price * t->w->qty;
        t->w->left = (s32)(lbl_8030B7F4.w34c - t->w->cost) <= 0 ? 0 : lbl_8030B7F4.w34c - t->w->cost;
        fn_801C0814(t);
        break;
    case 6:
        if (PAD_A) {
            lbl_8030B7F4.w34c -= t->w->cost;
            t->w->cost = 0;
        } else if (t->w->cost <= t->w->step) {
            lbl_8030B7F4.w34c -= t->w->cost;
            t->w->cost = 0;
        } else {
            t->w->cost -= t->w->step;
            lbl_8030B7F4.w34c -= t->w->step;
        }
        if (t->w->cost == 0) {
            fn_801C1148(t->w->item, t->w->qty);
            fn_801AB580((Self_801AB580*)t);
            t->w->state = 7;
            fn_801C08B4(0x18);
            t->w->step = 0;
        }
        break;
    case 7:
        t->w->who[3] = -1;
        t->w->who[2] = -1;
        t->w->who[1] = -1;
        t->w->who[0] = -1;
        t->w->xb = 0;
        t->w->parts[17] = 0;
        t->w->parts[16] = 0;
        t->w->parts[15] = 0;
        t->w->parts[14] = 0;
        fn_801C0FBC(t->w->item);
        for (i = 0; i < 4; i++) {
            t->w->stat[i][3] = 0;
            t->w->stat[i][2] = 0;
            t->w->stat[i][1] = 0;
            t->w->stat[i][0] = 0;
        }
        switch (fn_801F4C24(t->w->item)) {
        case 0:
            if (fn_801C0CA0(t->w->item)) {
                t->w->who[0] = fn_801C0C14(t->w->item);
                t->w->b34 = fn_801C2C84(t->w->who[0]);
                t->w->xb = 1;
                ShopShowEquip(t);
            } else {
                t->w->state = 10;
            }
            break;
        case 1:
        case 2:
            t->w->xa = 0;
            for (i = 0; i < 4; i++) {
                if (fn_801F3FD0(lbl_803471B8->w->m[i].id, t->w->item)) {
                    t->w->who[t->w->xb] = i;
                    t->w->stat[i][0] = lbl_803471B8->w->m[i].ha;
                    t->w->stat[i][1] = lbl_803471B8->w->m[i].hc;
                    t->w->stat[i][2] = lbl_803471B8->w->m[i].he;
                    t->w->xb++;
                    if (fn_801C0B88(t->w->item, i)) {
                        t->w->xa++;
                    }
                }
            }
            if (t->w->xa == t->w->xb) {
                t->w->xa = 4;
            }
            if (t->w->xb == 0) {
                t->w->state = 10;
            } else {
                ShopShowEquip(t);
            }
            break;
        case 5:
        case 6:
            switch (lbl_80310A1C[6]) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 12:
                t->w->state = 10;
                break;
            default:
                if (fn_801F3FD0(0, t->w->item) == 2 && lbl_8030B7F4.x1568.b1568 != -1) {
                    ShopShowEquip(t);
                } else {
                    t->w->state = 10;
                }
                break;
            }
            break;
        case 3:
        case 4:
        case 7:
            t->w->state = 10;
            break;
        }
        break;
    case 8:
        if (UiObjIsBusy(&t->w->parts[2]->obj->o)) {
            if (!PAD_A) {
                break;
            }
            MenuPartsFinish((MenuTask*)t);
        }
        switch (fn_801F4C24(t->w->item)) {
        case 0:
            ShopHideList(t);
            t->w->xa = 0;
            t->w->parts[12] = (ShopPart*)fn_801B1104(t);
            t->w->parts[18] = (ShopPart*)fn_801B0470(t);
            t->w->parts[10] = fn_801AD00C(t, 0, t->w->who[0]);
            t->w->parts[11] = fn_801AD00C(t, 1, t->w->who[0]);
            t->w->parts[13] = fn_801B057C(t, 0, t->w->who[0]);
            UiObjMoveToX(&t->w->parts[13]->obj->o, 6, 4, -8.0f);
            UiObjSetCommand(&t->w->parts[13]->obj->o, 15, 2);
            t->w->stat[0][0] = lbl_803471B8->w->m[t->w->who[0]].ha;
            fn_801C1FC0(t->w->item, t->w->who[0]);
            t->w->parts[14] = fn_801B0DF8(t);
            t->w->parts[14]->list->page = fn_801AB6E8(0, fn_801C2C84(t->w->who[0]));
            t->w->xc[t->w->who[0]] = 0;
            UiObjMoveToX(&t->w->parts[14]->obj->o, 6, 4, -8.0f);
            UiObjSetCommand(&t->w->parts[14]->obj->o, 15, 4);
            UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -8.0f);
            UiObjSetCommand(&t->w->parts[12]->obj->o, 15, 0);
            UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -8.0f);
            UiObjSetCommand(&t->w->parts[18]->obj->o, 15, 6);
            ShopShowCompare(t);
            t->w->state = 11;
            break;
        case 1:
        case 2:
            ShopHideList(t);
            t->w->parts[12] = (ShopPart*)fn_801B1104(t);
            t->w->parts[18] = (ShopPart*)fn_801B0470(t);
            t->w->xc[3] = 0;
            t->w->xc[2] = 0;
            t->w->xc[1] = 0;
            t->w->xc[0] = 0;
            n = 0;
            for (i = 0; i < t->w->xb; i++) {
                if (fn_801C0B88(t->w->item, t->w->who[i])) {
                    a = 0.7f;
                    n++;
                } else {
                    a = 1.0f;
                }
                fn_801C1FC0(t->w->item, t->w->who[i]);
                t->w->parts[lbl_802B69E8[i].idx] = fn_801B06CC(t, i, t->w->who[i], a);
                UiObjMoveToX(&t->w->parts[lbl_802B69E8[i].idx]->obj->o, 6, 4, lbl_802B69E8[i].x);
                UiObjSetCommand(&t->w->parts[lbl_802B69E8[i].idx]->obj->o, 15, i * 2 + 2);
            }
            if (n == t->w->xb) {
                t->w->xa = 4;
                i = 0;
            } else {
                for (i = 0; i < t->w->xb; i++) {
                    if (fn_801C0B88(t->w->item, t->w->who[i]) == 0) {
                        break;
                    }
                }
                t->w->xa = i;
            }
            t->w->parts[10] = fn_801AD00C(t, 0, t->w->who[i]);
            t->w->parts[11] = fn_801AD00C(t, 1, t->w->who[i]);
            d8 = t->w->xb * 2 + 2;
            UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -8.0f);
            UiObjSetCommand(&t->w->parts[12]->obj->o, 15, 0);
            UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -8.0f);
            UiObjSetCommand(&t->w->parts[18]->obj->o, 15, d8);
            ShopShowCompare(t);
            t->w->state = 15;
            break;
        case 5:
            t->w->b37 = 0;
            t->w->xa = 0;
            t->w->xc[3] = 0;
            t->w->xc[2] = 0;
            t->w->xc[1] = 0;
            t->w->xc[0] = 0;
            t->w->parts[10] = fn_801AD00C(t, 2, fn_801C16D0(t->w->item));
            t->w->parts[11] = fn_801AD00C(t, 3, fn_801C16D0(t->w->item));
            t->w->stat[0][0] = lbl_803471B8->w->d8[0].v;
            t->w->stat[0][1] = lbl_803471B8->w->d8[1].v;
            t->w->stat[0][2] = lbl_803471B8->w->d8[2].v;
            t->w->stat[0][3] = lbl_803471B8->w->d8[3].v;
            fn_801C1728(t->w->item, 0);
            fn_801C1728(t->w->item, 1);
            fn_801C1728(t->w->item, 2);
            fn_801C1728(t->w->item, 3);
            for (i = 0; i < 4; i++) {
                t->w->parts[lbl_802B69E8[i].idx] = fn_801AFBE8(t, i, 0, lbl_8030B7F4.x1568.s158a[i] == t->w->item ? 0.7f : 1.0f);
                UiObjMoveToX(&t->w->parts[lbl_802B69E8[i].idx]->obj->o, 6, 4, lbl_802B69E8[i].x);
                UiObjSetCommand(&t->w->parts[lbl_802B69E8[i].idx]->obj->o, 15, i * 2 + 2);
            }
            goto accessory; /* types 5 and 6 share their tail */
        case 6:
            t->w->xa = 0;
            t->w->b37 = 1;
            t->w->xc[3] = 0;
            t->w->xc[2] = 0;
            t->w->xc[1] = 0;
            t->w->xc[0] = 0;
            t->w->parts[10] = fn_801AD00C(t, 4, 0);
            t->w->parts[11] = fn_801AD00C(t, 5, 0);
            t->w->stat[0][0] = lbl_803471B8->w->h10a[0];
            t->w->stat[0][1] = lbl_803471B8->w->h10a[1];
            t->w->stat[0][2] = lbl_803471B8->w->h10a[2];
            fn_801C1728(t->w->item, 0);
            fn_801C1728(t->w->item, 1);
            fn_801C1728(t->w->item, 2);
            for (i = 0; i < 3; i++) {
                t->w->parts[lbl_802B69E8[i].idx] = fn_801AFBE8(t, i, 1, lbl_8030B7F4.x1568.s1580[i] == t->w->item ? 0.7f : 1.0f);
                UiObjMoveToX(&t->w->parts[lbl_802B69E8[i].idx]->obj->o, 6, 4, lbl_802B69E8[i].x);
                UiObjSetCommand(&t->w->parts[lbl_802B69E8[i].idx]->obj->o, 15, i * 2 + 2);
            }
        accessory:
            ShopHideList(t);
            t->w->parts[12] = (ShopPart*)fn_801B1104(t);
            t->w->parts[18] = (ShopPart*)fn_801B0470(t);
            UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -8.0f);
            UiObjSetCommand(&t->w->parts[12]->obj->o, 15, 0);
            UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -8.0f);
            UiObjSetCommand(&t->w->parts[18]->obj->o, 15, (u8)(i * 2 + 2));
            ShopShowCompare(t);
            t->w->state = 19;
            break;
        case 3:
        case 4:
        case 7:
            t->w->xa = 0;
            t->w->state = 10;
            break;
        }
        if (PAD_A) {
            MenuPartsFinish((MenuTask*)t);
        }
        break;
    case 10:
        t->w->state = 9;
        goto back_to_list; /* the original jumps into state 5's code */
    case 9:
        if (fn_801C09F8(0, 1) || PAD_B) {
            MenuPartsFinish((MenuTask*)t);
        list_ready:
            t->w->parts[2]->flag->b0 = 1;
            t->w->state = 3;
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
        } else if (UiObjIsBusy(&t->w->parts[2]->obj->o) == 0 && UiObjIsBusy(&t->w->parts[9]->obj->o) == 0) {
            goto list_ready; /* shared with the cancel path above */
        }
        break;
    case 11:
        if (UiObjIsBusy(&t->w->parts[18]->obj->o) == 0 && UiObjIsBusy(&t->w->parts[11]->obj2->o) == 0) {
            ShopCompareDone(t);
        } else if (PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            ShopCompareDone(t);
        }
        break;
    case 12:
        if (PAD_B) {
            if (t->w->xa == 4) {
                break;
            }
            t->w->parts[14]->x38->state = 1;
            t->w->xc[t->w->who[0]] = 0;
            lbl_803471B8->chr->c[t->w->who[0]].h6c = -1;
            fn_801C0AB4(t->w->stat[0][0], t->w->who[0]);
            fn_801C2C4C(t->w->who[0], t->w->b34);
            fn_801C12C8();
            fn_801C0FBC(t->w->item);
            fn_801AAFAC(t);
        } else if (PAD_A) {
            switch (t->w->xa) {
            case 0:
            case 1:
            case 2:
            case 3:
                if (t->w->x9 != 0 && t->w->parts[14]->x38->state != 0) {
                    fn_801C0AB4(t->w->item, t->w->who[0]);
                    if (fn_801F4CA0()) {
                        fn_801C2C4C(t->w->who[0], t->w->parts[14]->list->page);
                        lbl_803471B8->chr->c[t->w->who[0]].h6c = t->w->parts[14]->list->page;
                        t->w->xc[t->w->who[0]] = 1;
                    } else {
                        fn_801C2C4C(t->w->who[0], t->w->b34);
                        lbl_803471B8->chr->c[t->w->who[0]].h6c = t->w->b34;
                        t->w->xc[t->w->who[0]] = 1;
                    }
                    fn_801C12C8();
                    fn_801C0FBC(t->w->item);
                    if (fn_801AAFAC(t)) {
                        t->w->xa = 4;
                    }
                    fn_801C08B4(0x16);
                    SHOP_SLOT_CMDS(t, cmd, o);
                    t->w->parts[14]->x38->state = 0;
                } else {
                    fn_801C08B4(3);
                }
                break;
            case 4:
                fn_801C08B4(2);
                UiObjMoveToX(&t->w->parts[13]->obj->o, 6, 5, -348.0f);
                UiObjSetCommand(&t->w->parts[13]->obj->o, 15, 4);
                UiObjMoveToX(&t->w->parts[14]->obj->o, 6, 5, -348.0f);
                UiObjSetCommand(&t->w->parts[14]->obj->o, 15, 2);
                UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -348.0f);
                UiObjSetCommand(&t->w->parts[12]->obj->o, 15, 6);
                UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -348.0f);
                UiObjSetCommand(&t->w->parts[18]->obj->o, 15, 0);
                UiObjMoveToX(&t->w->parts[10]->obj->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[10]->obj->o, 15, 6);
                UiObjMoveToX(&t->w->parts[10]->obj2->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[10]->obj2->o, 15, 4);
                UiObjMoveToX(&t->w->parts[11]->obj->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[11]->obj->o, 15, 2);
                UiObjMoveToX(&t->w->parts[11]->obj2->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[11]->obj2->o, 15, 0);
                t->w->state = 14;
                break;
            }
        } else if (fn_801AB094((Task_801AB094*)t) == 0) {
            if (fn_801C09F8(0, 6)) {
                if (t->w->xa == 0 && t->w->parts[14]->x38->state != 0 &&
                    t->w->stat[0][0] == lbl_803471B8->w->m[t->w->who[0]].ha) {
                    page = t->w->parts[14]->list->page;
                    t->w->parts[14]->list->page = fn_801AB6E8(-1, page);
                    if (page != t->w->parts[14]->list->page) {
                        MenuPlaySe(0);
                    }
                }
            } else if (fn_801C09F8(0, 7)) {
                if (t->w->xa == 0 && t->w->parts[14]->x38->state != 0 &&
                    t->w->stat[0][0] == lbl_803471B8->w->m[t->w->who[0]].ha) {
                    page = t->w->parts[14]->list->page;
                    t->w->parts[14]->list->page = fn_801AB6E8(1, page);
                    if (page != t->w->parts[14]->list->page) {
                        MenuPlaySe(0);
                    }
                }
            }
        }
        break;
    case 14:
        if (fn_801C09F8(0, 1) || PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            ShopFreeCompare(t);
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 3;
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
        } else if (UiObjIsBusy(&t->w->parts[10]->obj->o) == 0) {
            ShopFreeCompare(t);
            t->w->state = 0x17;
        }
        break;
    case 15:
        if (UiObjIsBusy(&t->w->parts[18]->obj->o) == 0 && UiObjIsBusy(&t->w->parts[11]->obj2->o) == 0) {
            t->w->state = 16;
        } else if (PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 16;
        }
        break;
    case 16:
        if (PAD_B) {
            if (t->w->xa == 4) {
                break;
            }
            switch (fn_801F4C24(t->w->item)) {
            default:
                return;
            case 1:
                if (t->w->item == t->w->stat[t->w->who[t->w->xa]][1]) {
                    return;
                }
                t->w->xc[t->w->who[t->w->xa]] = 0;
                fn_801F4E38(lbl_803471B8->w->m[t->w->who[t->w->xa]].id, t->w->stat[t->w->who[t->w->xa]][1]);
                break;
            case 2:
                if (t->w->item == t->w->stat[t->w->who[t->w->xa]][2]) {
                    return;
                }
                t->w->xc[t->w->who[t->w->xa]] = 0;
                fn_801F4E04(lbl_803471B8->w->m[t->w->who[t->w->xa]].id, t->w->stat[t->w->who[t->w->xa]][2]);
                break;
            }
        armor_changed:
            fn_801C12C8();
            fn_801C0FBC(t->w->item);
            if (fn_801AAFAC(t)) {
                t->w->xa = 4;
            }
            fn_801AAFAC(t);
        } else if (PAD_A) {
            switch (t->w->xa) {
            case 0:
            case 1:
            case 2:
            case 3:
                if (t->w->x9 != 0 && fn_801C0B88(t->w->item, t->w->who[t->w->xa]) == 0) {
                    t->w->xc[t->w->who[t->w->xa]] = 1;
                    fn_801C0AB4(t->w->item, t->w->who[t->w->xa]);
                    fn_801C08B4(0x16);
                    goto armor_changed; /* shared with the cancel path above */
                }
                fn_801C08B4(3);
                break;
            case 4:
                fn_801C08B4(2);
                fn_801AAFAC(t);
                d = t->w->xb * 2;
                for (cnt = 0; cnt < (i = t->w->xb); cnt++, d -= 2) {
                    UiObjMoveToX(&t->w->parts[lbl_802B69E8[cnt].idx]->obj->o, 6, 5, lbl_802B69E8[cnt].x2);
                    UiObjSetCommand(&t->w->parts[lbl_802B69E8[cnt].idx]->obj->o, 15, d);
                }
                UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -348.0f);
                UiObjSetCommand(&t->w->parts[12]->obj->o, 15, (u8)(i * 2 + 2));
                UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -348.0f);
                UiObjSetCommand(&t->w->parts[18]->obj->o, 15, 0);
                UiObjMoveToX(&t->w->parts[10]->obj->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[10]->obj->o, 15, 6);
                UiObjMoveToX(&t->w->parts[10]->obj2->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[10]->obj2->o, 15, 4);
                UiObjMoveToX(&t->w->parts[11]->obj->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[11]->obj->o, 15, 2);
                UiObjMoveToX(&t->w->parts[11]->obj2->o, 6, -1, 648.0f);
                UiObjSetCommand(&t->w->parts[11]->obj2->o, 15, 0);
                t->w->state = 17;
                break;
            }
        } else if (fn_801AB094((Task_801AB094*)t)) {
            if (t->w->xa != 4 && (old = t->w->who[t->w->xa]) != -1) {
                t->w->parts[11]->obj->h56 = old;
                t->w->parts[10]->obj->h56 = old;
            }
        }
        break;
    case 17:
        if (fn_801C09F8(0, 1) || PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            MenuPartFree((MenuTask*)t, 12);
            MenuPartFree((MenuTask*)t, 18);
            MenuPartFree((MenuTask*)t, 10);
            MenuPartFree((MenuTask*)t, 11);
            for (i = 0; i < 4; i++) {
                MenuPartFree((MenuTask*)t, i + 14);
            }
            fn_801AB328((Self_801AB328*)t);
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 3;
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
        } else if (UiObjIsBusy(&t->w->parts[12]->obj->o) == 0) {
            MenuPartFree((MenuTask*)t, 12);
            MenuPartFree((MenuTask*)t, 18);
            MenuPartFree((MenuTask*)t, 10);
            MenuPartFree((MenuTask*)t, 11);
            for (i = 0; i < 4; i++) {
                MenuPartFree((MenuTask*)t, i + 14);
            }
            fn_801AB328((Self_801AB328*)t);
            t->w->state = 3;
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
        }
        break;
    case 18:
        t->w->state = 18;
        break;
    case 19:
        fn_801C0FBC(t->w->item);
        if (UiObjIsBusy(&t->w->parts[18]->obj->o) == 0 && UiObjIsBusy(&t->w->parts[11]->obj2->o) == 0) {
            t->w->state = 20;
            if (fn_801AACB0(t)) {
                t->w->xa = 4;
            }
            fn_801AACB0(t);
            SHOP_SLOT_CMDS(t, cmd, o);
        } else if (PAD_A) {
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 20;
            if (fn_801AACB0(t)) {
                t->w->xa = 4;
            }
            fn_801AACB0(t);
            SHOP_SLOT_CMDS(t, cmd, o);
        }
        break;
    case 20:
        if (fn_801C09F8(0, 1)) {
            if (t->w->xa >= 4 || t->w->xc[t->w->xa] == 0) {
                break;
            }
            if (t->w->b37 == 0) {
                lbl_8030B7F4.x1568.s1580[t->w->xa] = t->w->stat[0][t->w->xa];
            } else {
                lbl_8030B7F4.x1568.s158a[t->w->xa] = t->w->stat[0][t->w->xa];
            }
            t->w->xc[t->w->xa] = 0;
            fn_8021B1CC(lbl_8030B4D4 + 0x2dc, &lbl_8030B7F4.x1568.b1568);
            fn_801C1E48();
            fn_801C0FBC(t->w->item);
            fn_801AACB0(t);
            SHOP_SLOT_CMDS(t, cmd, o);
        } else if (PAD_A) {
            switch (t->w->xa) {
            case 0:
            case 1:
            case 2:
            case 3:
                if (t->w->b37 == 0) {
                    if (lbl_8030B7F4.x1568.s1580[(u8)t->w->xa] != t->w->item && t->w->x9 != 0) {
                        lbl_8030B7F4.x1568.s1580[(u8)t->w->xa] = t->w->item;
                        t->w->xc[t->w->xa] = 1;
                        fn_801C08B4(0x16);
                    } else {
                        fn_801C08B4(3);
                        break;
                    }
                } else {
                    old = lbl_8030B7F4.x1568.s158a[(u8)t->w->xa] == (s16)t->w->item;
                    if (!old && t->w->x9 != 0) {
                        lbl_8030B7F4.x1568.s158a[t->w->xa] = t->w->item;
                        t->w->xc[t->w->xa] = 1;
                        fn_801C08B4(0x16);
                    } else {
                        fn_801C08B4(3);
                        break;
                    }
                }
                fn_801C08B4(2);
                fn_8021B1CC(lbl_8030B4D4 + 0x2dc, &lbl_8030B7F4.x1568.b1568);
                fn_801C1E48();
                fn_801C0FBC(t->w->item);
                if (fn_801AACB0(t)) {
                    t->w->xa = 4;
                }
                fn_801AACB0(t);
                SHOP_SLOT_CMDS(t, cmd, o);
                break;
            case 4:
                if (t->w->b37 == 0) {
                    for (cnt = 0, d = 8; cnt < 4; cnt++, d -= 2) {
                        UiObjMoveToX(&t->w->parts[lbl_802B69E8[cnt].idx]->obj->o, 6, 4, lbl_802B69E8[cnt].x2);
                        UiObjSetCommand(&t->w->parts[lbl_802B69E8[cnt].idx]->obj->o, 15, d + 2);
                    }
                    UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -348.0f);
                    UiObjSetCommand(&t->w->parts[12]->obj->o, 15, 12);
                    UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -348.0f);
                    UiObjSetCommand(&t->w->parts[18]->obj->o, 15, 0);
                    UiObjMoveToX(&t->w->parts[10]->obj->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[10]->obj->o, 15, 6);
                    UiObjMoveToX(&t->w->parts[10]->obj2->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[10]->obj2->o, 15, 4);
                    UiObjMoveToX(&t->w->parts[11]->obj->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[11]->obj->o, 15, 2);
                    UiObjMoveToX(&t->w->parts[11]->obj2->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[11]->obj2->o, 15, 0);
                } else {
                    for (cnt = 0, d = 6; cnt < 3; cnt++, d -= 2) {
                        UiObjMoveToX(&t->w->parts[lbl_802B69E8[cnt].idx]->obj->o, 6, 4, lbl_802B69E8[cnt].x2);
                        UiObjSetCommand(&t->w->parts[lbl_802B69E8[cnt].idx]->obj->o, 15, d + 2);
                    }
                    UiObjMoveToX(&t->w->parts[12]->obj->o, 6, 5, -348.0f);
                    UiObjSetCommand(&t->w->parts[12]->obj->o, 15, 10);
                    UiObjMoveToX(&t->w->parts[18]->obj->o, 6, 5, -348.0f);
                    UiObjSetCommand(&t->w->parts[18]->obj->o, 15, 0);
                    UiObjMoveToX(&t->w->parts[10]->obj->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[10]->obj->o, 15, 6);
                    UiObjMoveToX(&t->w->parts[10]->obj2->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[10]->obj2->o, 15, 4);
                    UiObjMoveToX(&t->w->parts[11]->obj->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[11]->obj->o, 15, 2);
                    UiObjMoveToX(&t->w->parts[11]->obj2->o, 6, -1, 648.0f);
                    UiObjSetCommand(&t->w->parts[11]->obj2->o, 15, 0);
                }
                t->w->state = 21;
                fn_801C08B4(2);
                break;
            }
        } else if (fn_801C09F8(0, 4)) {
            row = t->w->xa;
            if (t->w->b37 == 0) {
                if (t->w->xa == 0) {
                    t->w->xa = 4;
                } else {
                    t->w->xa--;
                }
            } else if (t->w->xa == 0) {
                t->w->xa = 4;
            } else if (t->w->xa == 4) {
                t->w->xa = 2;
            } else {
                t->w->xa--;
            }
            if ((n = t->w->xa) != 4) {
                t->w->parts[11]->obj->h56 = n;
                t->w->parts[10]->obj->h56 = n;
            }
            if (row != t->w->xa) {
                MenuPlaySe(4);
            }
            SHOP_SLOT_CMDS(t, cmd, o);
        } else if (fn_801C09F8(0, 5)) {
            row = t->w->xa;
            if (t->w->b37 == 0) {
                t->w->xa++;
                if (t->w->xa == 5) {
                    t->w->xa = 0;
                }
            } else {
                t->w->xa++;
                if (t->w->xa == 3) {
                    t->w->xa = 4;
                } else if (t->w->xa == 5) {
                    t->w->xa = 0;
                }
            }
            if ((n = t->w->xa) != 4) {
                t->w->parts[11]->obj->h56 = n;
                t->w->parts[10]->obj->h56 = n;
            }
            SHOP_SLOT_CMDS(t, cmd, o);
            if (row != t->w->xa) {
                MenuPlaySe(4);
            }
        }
        break;
    case 21:
        if (fn_801C09F8(0, 1) || PAD_A) {
            MenuPartsFinish((MenuTask*)t);
        } else if (UiObjIsBusy(&t->w->parts[12]->obj->o)) {
            break;
        }
        MenuPartFree((MenuTask*)t, 12);
        MenuPartFree((MenuTask*)t, 18);
        MenuPartFree((MenuTask*)t, 10);
        MenuPartFree((MenuTask*)t, 11);
        MenuPartFree((MenuTask*)t, 14);
        MenuPartFree((MenuTask*)t, 14);
        MenuPartFree((MenuTask*)t, 15);
        MenuPartFree((MenuTask*)t, 16);
        MenuPartFree((MenuTask*)t, 17);
        fn_801AB328((Self_801AB328*)t);
        t->w->state = 0x17;
        break;
    case 23:
        if (UiObjIsBusy(&t->w->parts[1]->obj->o) == 0) {
            t->w->state = 3;
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
        } else if (PAD_A || fn_801C09F8(0, 1)) {
            MenuPartsFinish((MenuTask*)t);
            t->w->state = 3;
            t->w->parts[8]->x38->state = 1 < t->buf->pages;
        }
        break;
    case 24:
        UiObjMoveTo(&t->w->parts[7]->obj->o, 6, -1, 640.0f, 480.0f);
        UiObjSetCommand(&t->w->parts[7]->obj->o, 15, 0);
        UiObjMoveToX(&t->w->parts[8]->obj->o, 6, -1, 648.0f);
        UiObjSetCommand(&t->w->parts[8]->obj->o, 15, 0);
        UiObjMoveToX(&t->w->parts[9]->obj->o, 6, -1, -624.0f);
        UiObjSetCommand(&t->w->parts[9]->obj->o, 15, 0);
        UiObjMoveToX(&t->w->parts[9]->obj2->o, 6, -1, -624.0f);
        UiObjSetCommand(&t->w->parts[9]->obj2->o, 15, 0);
        t->w->state = 25;
    case 25:
        if (fn_801C09F8(0, 1)) {
            MenuPartFree((MenuTask*)t, 7);
            MenuPartFree((MenuTask*)t, 8);
            MenuPartFree((MenuTask*)t, 9);
            MenuPartFree((MenuTask*)t, 2);
            t->w->parts[4]->flag->b0 = 0;
            t->w->parts[5]->flag->b0 = 0;
            t->w->state = 26;
        } else if (UiObjIsBusy(&t->w->parts[7]->obj->o) == 0) {
            MenuPartFree((MenuTask*)t, 7);
            MenuPartFree((MenuTask*)t, 8);
            MenuPartFree((MenuTask*)t, 9);
            MenuPartFree((MenuTask*)t, 2);
            t->w->parts[4]->flag->b0 = 0;
            t->w->parts[5]->flag->b0 = 0;
            t->w->state = 26;
        }
        break;
    case 26:
        t->state = 5;
        break;
    }
}

s32 fn_801AACB0(ShopTask* t) {
    s32 ret = 0;
    u32 n;
    u32 i;
    switch (fn_801F4C24(t->w->item)) {
    case 5:
        n = 0;
        if (t->w->x9 != 0) {
            if (fn_801C0B88(t->w->item, 0)) n = 1;
            if (fn_801C0B88(t->w->item, 1)) n++;
            if (fn_801C0B88(t->w->item, 2)) n++;
            if (fn_801C0B88(t->w->item, 3)) n++;
            if (n != 4) goto loop5;
        }
        ret = 1;
        t->w->parts[14]->obj->o.alpha = 0.7f;
        t->w->parts[15]->obj->o.alpha = 0.7f;
        t->w->parts[16]->obj->o.alpha = 0.7f;
        t->w->parts[17]->obj->o.alpha = 0.7f;
        break;
    loop5:
        for (i = 0; i < 4; i++) {
            if (fn_801C0B88(t->w->item, i)) t->w->parts[i + 14]->obj->o.alpha = 0.7f;
            else t->w->parts[i + 14]->obj->o.alpha = 1.0f;
        }
        break;
    case 6:
        n = 0;
        if (t->w->x9 != 0) {
            if (fn_801C0B88(t->w->item, 0)) n = 1;
            if (fn_801C0B88(t->w->item, 1)) n++;
            if (fn_801C0B88(t->w->item, 2)) n++;
            if (n != 3) goto loop6;
        }
        ret = 1;
        t->w->parts[14]->obj->o.alpha = 0.7f;
        t->w->parts[15]->obj->o.alpha = 0.7f;
        t->w->parts[16]->obj->o.alpha = 0.7f;
        break;
    loop6:
        for (i = 0; i < 3; i++) {
            if (fn_801C0B88(t->w->item, i)) t->w->parts[i + 14]->obj->o.alpha = 0.7f;
            else t->w->parts[i + 14]->obj->o.alpha = 1.0f;
        }
        break;
    }
    return ret;
}

s32 fn_801AAFAC(ShopTask *self) {
    u32 i;
    u32 n;
    s32 done = 0;

    for (i = n = 0; i < self->w->xb; i++) {
        if (fn_801C0B88(self->w->item, self->w->who[i])) {
            n++;
            self->w->parts[14 + i]->obj->o.alpha = 0.7f;
            if (n == self->w->xb) {
                done = 1;
            }
        } else if (self->w->x9 != 0) {
            self->w->parts[14 + i]->obj->o.alpha = 1.0f;
        } else {
            self->w->parts[14 + i]->obj->o.alpha = 0.7f;
            done = 1;
        }
    }
    return done;
}

s32 fn_801AB094(Task_801AB094* t)
{
    s32 ret = 0;
    u8 old = t->m->cur;
    s32 i, cmd;
    MP* s;
    UiObj* o;
    if (fn_801C09F8(0, 4)) {
        ret = 1;
        if (t->m->cur == 0) t->m->cur = 4; else t->m->cur--;
        if (t->m->slot[t->m->cur] == 0) {
            for (i = 0; i < 5; i++) {
                if (t->m->slot[t->m->cur] != 0) break;
                if (t->m->cur == 0) t->m->cur = 5; else t->m->cur--;
            }
        }
    } else if (fn_801C09F8(0, 5)) {
        ret = 1;
        t->m->cur++;
        if (t->m->cur == 5) t->m->cur = 0;
        if (t->m->slot[t->m->cur] == 0) {
            for (i = 0; i < 5; i++) {
                if (t->m->slot[t->m->cur] != 0) break;
                t->m->cur++;
                if (t->m->cur == 5) t->m->cur = 0;
            }
        }
    }
    if (old != t->m->cur) MenuPlaySe(0);
    cmd = 0x14;
    if (t->m->cur == 0) cmd = 0x15;
    UiObjSetCommand(&t->m->slot[0]->obj->o, cmd, 0);
    if ((s = t->m->slot[1]) != 0) {
        o = &s->obj->o;
        cmd = 0x14;
        if (t->m->cur == 1) cmd = 0x15;
        UiObjSetCommand(o, cmd, 0);
    }
    if ((s = t->m->slot[2]) != 0) {
        o = &s->obj->o;
        cmd = 0x14;
        if (t->m->cur == 2) cmd = 0x15;
        UiObjSetCommand(o, cmd, 0);
    }
    if ((s = t->m->slot[3]) != 0) {
        o = &s->obj->o;
        cmd = 0x14;
        if (t->m->cur == 3) cmd = 0x15;
        UiObjSetCommand(o, cmd, 0);
    }
    cmd = 0x14;
    if (t->m->cur == 4) cmd = 0x15;
    UiObjSetCommand(&t->m->slot[4]->obj->o, cmd, 0);
    return ret;
}

void fn_801AB328(Self_801AB328 *o) {
    o->ctx->x1f8->flag->b0 = 0;
    o->ctx->x204->flag->b0 = 0;
    o->ctx->x1fc->flag->b0 = 0;
    o->ctx->x218->flag->b0 = 0;
    o->ctx->x214->flag->b0 = 0;
    o->ctx->x1f8->flag->b0 = 0;
    UiObjMoveToX(&o->ctx->x1f8->obj->o, 6, 4, -8.0f);
    UiObjSetCommand(&o->ctx->x1f8->obj->o, 0xf, 0);
    o->ctx->x204->flag->b0 = 0;
    UiObjMoveToX(&o->ctx->x204->obj->o, 6, 4, -8.0f);
    UiObjSetCommand(&o->ctx->x204->obj->o, 0xf, 1);
    o->ctx->x1fc->flag->b0 = 0;
    UiObjMoveToX(&o->ctx->x1fc->obj->o, 6, 4, -8.0f);
    UiObjSetCommand(&o->ctx->x1fc->obj->o, 0xf, 2);
    o->ctx->x218->flag->b0 = 0;
    UiObjMoveToX(&o->ctx->x218->obj->o, 6, -1, 240.0f);
    UiObjSetCommand(&o->ctx->x218->obj->o, 0xf, 0);
    o->ctx->x214->flag->b0 = 0;
    UiObjMoveTo(&o->ctx->x214->obj->o, 6, -1, 24.0f, 384.0f);
    UiObjSetCommand(&o->ctx->x214->obj->o, 0xf, 1);
    o->ctx->x21c->flag->b0 = 0;
    UiObjMoveToX(&o->ctx->x21c->obj->o, 6, -1, -8.0f);
    UiObjSetCommand(&o->ctx->x21c->obj->o, 0xf, 1);
    o->ctx->x21c->flag->w8 = 0xffff;
    o->ctx->x218->flag30->b1e = 0;
}

void fn_801AB580(Self_801AB580 *self) {
    ShopData *row = &lbl_802EC0A0[lbl_803473BC];
    u32 i = 0;
    u32 n = 0;
    for (; i < 0x30; i++) {
        if (row->item[i] != -1) {
            s16 id;
            u8 flag;
            self->buf->out[i].id = row->item[i];
            self->buf->out[i].type = fn_801F4C24(row->item[i]);
            id = (u16)row->item[i];
            if (fn_801F477C(id) == 0) {
                flag = 1;
            } else if (lbl_8030B7F4.w34c / fn_801F477C(id) == 0) {
                flag = 1;
            } else if (fn_801F452C(id) == 99) {
                flag = 1;
            } else {
                flag = 0;
            }
            self->buf->out[i].flag = flag;
            n++;
        } else {
            self->buf->out[i].type = -1;
            self->buf->out[i].id = -1;
            self->buf->out[i].flag = -1;
        }
    }
    self->buf->count = n;
    self->buf->pages = n / 6 + (n % 6 != 0);
}

u8 fn_801AB6E8(s8 step, u8 start) {
    s32 d;
    s32 mask;
    s32 i;
    s32 n;
    mask = fn_801F4CA0();
    if (mask == 0) {
        return 0;
    }
    i = (s8)start + (d = step);
    if (i < 0) {
        i = 5;
    }
    if (i >= 6) {
        i = 0;
    }
    for (n = 0; n < 6; n++) {
        if (i == 7) {
            i = 0;
        }
        if (mask & (1 << i)) {
            return (u8)i;
        }
        i += d;
    }
    return start;
}

u8 fn_801AB82C(s32 mode, u8 cur, s32 idxp) {
    s16 idx = idxp;
    u32 max;
    u32 v;
    s32 lim;

    max = (u32)lbl_8030B7F4.w34c / fn_801F477C(idx);
    if (max == 0) {
        return 0;
    }
    if (max > 99) {
        max = 99;
    }
    lim = 99 - fn_801F452C(idx);
    if (max > lim) {
        max = lim;
    }
    v = cur;
    switch (mode) {
    case 4:
        if (v > 1) {
            v--;
        }
        break;
    case 8:
        if (v < max) {
            v++;
        }
        break;
    case 1:
        if (max + 1 < 10) {
            v = 1;
        } else {
            if (v < 10) {
                v = 1;
            } else {
                v -= 10;
            }
            if (v == 0) {
                v = 1;
            }
        }
        break;
    case 2:
        if (max + 1 < 10) {
            v = max;
        } else {
            v += 10;
            if (v >= max + 1) {
                v = max;
            }
        }
        break;
    }
    if (v != cur) {
        MenuPlaySe(0);
    }
    return v;
}

void fn_801AB98C(Obj_UNIT0000 *o)
{
    Sub_UNIT0000 *s = o->sub;
    s->fc = (float)(s32)(s->h1a * 0x18);
    o->sub->f8 = 0.0f;
}

void *fn_801AB9D0(s32 a) {
    u8 *obj = fn_80226670((u8 *)a, fn_801ABA30);
    *(void **)(obj + 0x24) = fn_801E1A74(1, 6);
    *(u8 *)(*(u8 **)(obj + 0x24) + 0x4) = *(s16 *)(lbl_8030B4D4 + 0x2D0);
    return obj;
}

void fn_801ABA30(void* a)
{
    Ent_801ABA30* t = a;
    SpriteObj obj;
    f32 pos[2];
    s32 i, j;
    f32 z;

    if (lbl_803475D8 != 0) {
        t->mode = 0xFF;
    }
    switch (t->mode) {
    case 0:
    case 0xFE:
        z = -10100.0f;
        obj.sprite = fn_801D68C4(menu_sprites.banks[1], 0);
        obj.z = -10100.0f;
        obj.b = 1.0f;
        obj.a = 1.0f;
        obj.texlist = menu_sprites.textlistC;
        obj.flags = 1;
        obj.colour = 0;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 10; j++) {
                obj.z = z;
                pos[0] = (f32)(j * 64);
                pos[1] = (f32)(i * 64);
                SpriteObjDrawAtEx(&obj, pos);
                z += 0.05f;
            }
        }
        obj.sprite = fn_801D68C4(menu_sprites.banks[0], 0);
        z += 0.05f;
        obj.flags = 3;
        obj.z = z;
        obj.texlist = menu_sprites.textlistC;
        SpriteObjDraw(&obj);
        obj.flags = 1;
        obj.texlist = menu_sprites.texlist8;
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 0);
        z += 0.05f;
        obj.z = z;
        SpriteObjDraw(&obj);
        z += 0.05f * (f32)fn_801D68C4(menu_sprites.banks[2], 0)->count;
        obj.z = z;
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 3);
        SpriteObjDraw(&obj);
        z += 0.05f * (f32)fn_801D68C4(menu_sprites.banks[2], 3)->count;
        obj.z = z;
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 1);
        SpriteObjDraw(&obj);
        obj.z = z + 0.05f * (f32)fn_801D68C4(menu_sprites.banks[2], 1)->count;
        obj.sprite = fn_801D68C4(menu_sprites.banks[2], 2);
        SpriteObjDraw(&obj);
        obj.texlist = menu_sprites.texlist8;
        obj.sprite = fn_801D68C4(menu_sprites.banks[3], 0xD);
        SpriteObjDraw(&obj);
        if (t->sub->flags & 0x40) {
            t->flags |= 0x40;
        }
        break;
    case 0xFF:
        t->flags |= 0x40;
        break;
    }
}

void fn_801ABD40(PanelTask_801ABD40* t) {
    f32 z;
    if (lbl_803475D8 != 0) {
        t->state = 0xFF;
    }
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B6B0C, 4, &t->pan->o.x, t->pan->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextSetZ(-4027.5f);
        TextPushColor();
        TextSetColor(0xFF201008);
        TextPrint(24.0f + t->pan->o.x, 20.0f + t->pan->o.y, lbl_80346810[t->pan->h56]);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

Node* fn_801ABE90(void* a)
{
    Node* o = fn_802267AC(a, fn_801ABD40);
    o->w = fn_801E1A74(1, 0x58);
    o->obj = fn_801E1A74(1, 0x6c);
    o->obj->o.alpha_en = 0;
    o->w->b0 = 0;
    o->obj->o.x = -260.0f;
    o->obj->o.tx = -260.0f;
    o->obj->o.y = 324.0f;
    o->obj->o.ty = 324.0f;
    o->obj->o.rdx = 0.0f;
    o->obj->o.rdy = 0.0f;
    o->obj->o.f38 = 1.0f;
    o->obj->o.alpha = 1.0f;
    o->obj->o.z = -4250.0f;
    o->x2c = 0;
    UiObjSetLowered(&o->obj->o);
    UiObjCalcRect(&o->obj->o);
    return o;
}

void fn_801ABF70(PanelTask_801ABF70* t) {
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->ui->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B7C14, 4, &t->ui->o.x, t->ui->o.z, 1.0f, 1.0f);
        fn_801C3F5C(19.0f + t->ui->o.x, 17.0f + t->ui->o.y, -27.5f + t->ui->o.z);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        TextSetZ(-27.5f + t->ui->o.z);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

Node* fn_801AC094(void* a)
{
    Node* o = fn_802267AC(a, fn_801ABF70);
    o->w = fn_801E1A74(1, 0x58);
    o->obj = fn_801E1A74(1, 0x6c);
    o->obj->o.alpha_en = 0;
    o->w->b0 = 0;
    o->obj->o.x = 640.0f;
    o->obj->o.tx = 640.0f;
    o->obj->o.y = 84.0f;
    o->obj->o.ty = 84.0f;
    o->obj->o.rdx = 0.0f;
    o->obj->o.rdy = 0.0f;
    o->obj->o.f38 = 1.0f;
    o->obj->o.alpha = 1.0f;
    o->obj->o.z = -4350.0f;
    o->x2c = 0;
    UiObjSetLowered(&o->obj->o);
    return o;
}

void fn_801AC16C(Task* task) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    MP* p = (MP*)task;
    f32 z;
    NJS_TEXLIST** tl;
    switch (task->state) {
    case 0:
    case 0xFE:
        if (*(u8*)task->work == 1) {
            return;
        }
        UiObjUpdate(&p->obj->o);
        UiObjCalcRect(&p->obj->o);
        tl = &menu_sprites.texlist8;
        UiLayoutDraw(tl, (void*)lbl_802B7BC4, 3, p->obj->o.rect, p->obj->o.z, 1.0f, 1.0f);
        UiLayoutDraw(tl, (void*)lbl_802B7C00, 1, &p->obj->o.rect[2], p->obj->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        TextSetZ(-27.5f + p->obj->o.z);
        if (p->obj->text != NULL) {
            TextPrint((s32)(24.0f + p->obj->o.rect[0]), (s32)(20.0f + p->obj->o.rect[1]), p->obj->text);
        }
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(task);
        task->flags |= 0x40;
        break;
    }
}

void* fn_801AC2E4(void* a) {
    T* t = fn_802267AC((void *)(a), (void *)(fn_801AC16C));
    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    switch (fn_801BE608(lbl_803471B8->w->item)) {
    case 0:
        t->obj->text = lbl_802ED258[lbl_803471B8->w->item].a;
        break;
    case 1:
        t->obj->text = lbl_802ED258[lbl_803471B8->w->item].c;
        break;
    case 2:
        t->obj->text = lbl_802ED258[lbl_803471B8->w->item].b;
        break;
    default:
        t->obj->text = NULL;
        break;
    }
    t->obj->o.alpha_en = 0;
    t->w[0] = 0;
    t->obj->o.x = -348.0f;
    t->obj->o.tx = -348.0f;
    t->obj->o.y = 36.0f;
    t->obj->o.ty = 36.0f;
    t->obj->o.rdx = 0.0f;
    t->obj->o.rdy = 0.0f;
    *(f32*)((u8*)t->obj + 0x38) = 1.0f;
    t->obj->o.alpha = 1.0f;
    t->obj->o.z = -4300.0f;
    t->x2c = 0;
    UiObjSetLowered(&t->obj->o);
    UiObjCalcRect(&t->obj->o);
    return t;
}

void fn_801AC48C(ShopPart* t) {
    f32 z;
    ShopList* p;
    UiObj* ui;
    NJS_TEXLIST** tl;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        tl = &menu_sprites.texlist8;
        UiLayoutDraw(tl, lbl_802B6EE8, 4, &t->obj->o.x, t->obj->o.z, 1.0f, 1.0f);
        lbl_80347198 = t->list->row;
        t->list->oy = (f32)(t->list->row * 0x18);
        p = t->list;
        ui = &t->obj->o;
        if ((p->flags & 1) && p->part != 0xff) {
            f32 a = 0.0f;
            if (p->flags & 2) {
                p->x = ui->x + p->ox;
                p->y = ui->y + p->oy;
                p->scale = 0.3f * njCos(p->angle) + 1.0f;
                p->angle += 0x800;
                a = p->scale;
            }
            UiLayoutDrawPart(tl, lbl_802B6A64, 1, &p->x, ui->z, a, 1.0f, p->part);
        }
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        fn_801B737C(t);
        TextSetZ(-27.5f + t->obj->o.z);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

void fn_801AC678(ShopPart* t) {
    f32 z;
    ShopList* p;
    UiObj* ui;
    NJS_TEXLIST** tl;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        tl = &menu_sprites.texlist8;
        UiLayoutDraw(tl, lbl_802B6E48, 4, &t->obj->o.x, t->obj->o.z, 1.0f, 1.0f);
        if (lbl_803471B8->buf->count != 0) {
            p = t->list;
            ui = &t->obj->o;
            if ((p->flags & 1) && p->part != 0xff) {
                f32 a = 0.0f;
                if (p->flags & 2) {
                    p->x = ui->x + p->ox;
                    p->y = ui->y + p->oy;
                    p->scale = 0.3f * njCos(p->angle) + 1.0f;
                    p->angle += 0x800;
                    a = p->scale;
                }
                UiLayoutDrawPart(tl, lbl_802B6A64, 1, &p->x, ui->z, a, 1.0f, p->part);
            }
        }
        if (lbl_803471B8->buf->pages != 0) {
            t->x38->idx = 2;
            t->x38->x = t->obj->o.x;
            t->x38->y = t->obj->o.y;
            fn_801B5D68(t);
        }
        z = TextGetZ();
        TextPushColor();
        fn_801AC87C(t);
        TextSetZ(-27.5f + t->obj->o.z);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

void fn_801AC87C(ShopPart* t) {
    s32 i;
    s32 k;
    s32 id;
    s32 n;
    if (t->flag->w8 == 0) {
        if (lbl_803471B8->buf->count == 0) {
            TextSetColor(0xff201008);
            TextPrint(40.0f + t->obj->o.x, 12.0f + t->obj->o.y, lbl_802EC04C[11]);
        } else {
            for (i = 0, k = 0; i < 6; i++, k += 0x18) {
                n = i + t->list->page * 6;
                id = lbl_803471B8->buf->out[n].id;
                if (id != -1) {
                    if (lbl_803471B8->buf->out[n].type != 0 || (s32)lbl_803471B8->buf->out[n].flag == 3) {
                        TextSetColor(0x40201008);
                    } else {
                        TextSetColor(0xff201008);
                    }
                    TextPrint(16.0f + t->obj->o.x, 12.0f + t->obj->o.y + (f32)k, fn_801BE17C(id));
                    TextPrintNumber(288.0f + t->obj->o.x, 12.0f + t->obj->o.y + (f32)k, fn_801BDEF4(id, 0), 0xC008);
                }
            }
        }
    } else {
        if (lbl_803471B8->buf->count == 0) {
            TextSetColor(0xff201008);
            TextPrint(40.0f + t->obj->o.x, 12.0f + t->obj->o.y, lbl_802EC04C[12]);
        } else {
            TextSetColor(0xff201008);
            for (i = 0; i < 6; i++) {
                id = lbl_803471B8->buf->out[i + t->list->page * 6].id;
                if (id != -1) {
                    TextPrint(16.0f + t->obj->o.x, 12.0f + t->obj->o.y + (f32)(i * 24), lbl_802ED258[id].b);
                    TextPrintNumber(288.0f + t->obj->o.x, 12.0f + t->obj->o.y + (f32)(i * 24), fn_801BDEF4(id, 1), 0xC008);
                }
            }
        }
    }
}

ShopPart* fn_801ACC00(void* arg, u16 slot) {
    ShopPart* t = fn_802267AC(arg, fn_801AC48C);
    t->flag = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->list = fn_801E1A74(1, 0x20);
    t->x38 = fn_801E1A74(1, 0x18);
    t->obj2 = 0;
    t->flag->w8 = slot;
    t->list->part = 4;
    t->list->flags = 3;
    t->list->page = 0;
    t->list->row = 0;
    t->obj->o.alpha_en = 0;
    ((u8*)t->flag)[0] = 0;
    t->obj->o.x = 648.0f;
    t->obj->o.tx = 648.0f;
    t->obj->o.y = 38.0f;
    t->obj->o.ty = 38.0f;
    t->obj->o.rdx = 0.0f;
    t->obj->o.rdy = 0.0f;
    *(f32*)((u8*)t->obj + 0x38) = 1.0f;
    t->obj->o.alpha = 1.0f;
    t->obj->o.z = -4500.0f;
    UiObjSetLowered(&t->obj->o);
    return t;
}

ShopPart* fn_801ACD38(void* arg, u16 slot) {
    ShopPart* t = fn_802267AC(arg, fn_801AC678);
    t->flag = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->list = fn_801E1A74(1, 0x20);
    t->x38 = fn_801E1A74(1, 0x18);
    t->obj2 = 0;
    t->flag->w8 = slot;
    t->list->part = 4;
    t->list->flags = 3;
    t->list->page = 0;
    t->list->row = 0;
    t->obj->o.alpha_en = 0;
    ((u8*)t->flag)[0] = 0;
    t->obj->o.x = 648.0f;
    t->obj->o.tx = 648.0f;
    t->obj->o.y = 38.0f;
    t->obj->o.ty = 38.0f;
    t->obj->o.rdx = 0.0f;
    t->obj->o.rdy = 0.0f;
    *(f32*)((u8*)t->obj + 0x38) = 1.0f;
    t->obj->o.alpha = 1.0f;
    t->obj->o.z = -4500.0f;
    UiObjSetLowered(&t->obj->o);
    return t;
}

void fn_801ACE70(Task* task) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    extern void fn_801AD1D4(Task* t);
    extern s32 fn_801C09F8(s32 a, s32 b);
    extern s32 UiLayoutDraw2(NJS_TEXLIST** t, void* parts, u32 count, f32* pos, f32 z, f32 a, f32 b);
    MP2* p = (MP2*)task;
    f32 z;
    NJS_TEXLIST** tl;
    switch (task->state) {
    case 0:
    case 0xFE:
        if (*(u8*)task->work == 1) {
            return;
        }
        UiObjUpdate(&p->obj->o);
        UiObjUpdate(&p->obj2->o);
        UiObjCalcRect(&p->obj->o);
        UiObjCalcRect(&p->obj2->o);
        tl = &menu_sprites.texlist8;
        UiLayoutDraw(tl, lbl_802B7B64[p->obj->h54].parts, lbl_802B7B64[p->obj->h54].count, p->obj->o.rect, p->obj->o.z, p->obj->o.alpha, 1.0f);
        UiLayoutDraw(tl, lbl_802B7B94[p->obj2->h54].parts, lbl_802B7B94[p->obj2->h54].count, p->obj2->o.rect, p->obj2->o.z, p->obj2->o.alpha, 1.0f);
        z = TextGetZ();
        TextPushColor();
        fn_801AD1D4(task);
        TextPopColor(1);
        TextSetZ(z);
        switch (p->obj->h54) {
        case 1:
            if (fn_801C09F8(0, 10) != 0) {
                ((W*)task->work)->v++;
                ((W*)task->work)->v &= 1;
                MenuPlaySe(4);
            }
            break;
        }
        break;
    case 0xFF:
        MenuDummy(task);
        task->flags |= 0x40;
        break;
    }
}
ShopPart* fn_801AD00C(ShopTask* t, u8 kind, u16 who) {
    ShopPart* p = fn_802267AC(t, fn_801ACE70);
    p->flag = fn_801E1A74(1, 0x58);
    p->obj = fn_801E1A74(1, 0x6c);
    p->obj->o.alpha_en = 0;
    p->obj->o.tx = p->obj->o.x = 648.0f;
    p->obj->o.ty = p->obj->o.y = lbl_802B8F40[kind];
    UiObjSetLowered(&p->obj->o);
    p->obj->o.z = kind == 0 ? -4600.0f : -4700.0f;
    p->obj->o.alpha = (kind & 1) == 0 ? 0.7f : 1.0f;
    p->obj->o.f38 = 1.0f;
    p->obj->h52 = 1;
    p->obj->h54 = kind;
    p->obj->h56 = who;
    p->obj2 = fn_801E1A74(1, 0x6c);
    p->obj2->o.alpha_en = 0;
    p->obj2->o.tx = p->obj2->o.x = 648.0f;
    p->obj2->o.ty = p->obj2->o.y = lbl_802B8F58[kind];
    UiObjSetLowered(&p->obj2->o);
    p->obj2->o.z = kind == 0 ? -4650.0f : -4750.0f;
    p->obj2->o.alpha = (kind & 1) == 0 ? 0.7f : 1.0f;
    p->obj2->o.f38 = 1.0f;
    p->obj2->h52 = 1;
    p->obj2->h54 = kind;
    p->flag->b0 = 0;
    return p;
}

void fn_801AFAA4(PanelTask_801AFAA4* t) {
    void (*cb)(PanelTask_801AFAA4*);
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->data->flag == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiObjCalcRect(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B79E4[t->pan->h54].parts,
                     lbl_802B79E4[t->pan->h54].count, t->pan->o.rect, t->pan->o.z, t->pan->o.alpha, 1.0f);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B77AC, 1, &t->pan->o.rect[2], t->pan->o.z, 1.0f, 1.0f);
        cb = t->data->cb;
        if (cb != 0) {
            z = TextGetZ();
            TextPushColor();
            cb(t);
            TextPopColor(1);
            TextSetZ(z);
        }
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

void* fn_801AFBE8(void* parent, u16 idx, u16 mode, f32 alpha) {
    PanelTask_801AFBE8* t = fn_802267AC(parent, fn_801AFAA4);

    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->obj->o.f38 = 1.0f;
    t->x2c = 0;
    t->obj->h56 = idx;
    t->obj->h54 = mode;
    t->obj->o.alpha_en = 0;
    t->obj->o.alpha = alpha;
    t->w->b0 = 0;
    t->obj->o.x = -348.0f;
    t->obj->o.tx = -348.0f;
    t->obj->o.y = lbl_802B8F20[idx].y;
    t->obj->o.ty = lbl_802B8F20[idx].y;
    t->obj->o.z = lbl_802B8F20[idx].z;
    t->obj->h52 = 1;
    if (mode != 0) {
        t->w->cb = fn_801AFD34;
    } else {
        t->w->cb = fn_801B0014;
    }
    UiObjSetLowered(&t->obj->o);
    return t;
}
void fn_801AFD34(void* arg) {
    PanelTask_801AFBE8* t = arg;
    MenuPanel* p;
    CmpEq eq;
    s16 id = lbl_8030B7F4.x1568.s158a[t->obj->h56];
    s32 x;
    s16 y;

    TextSetColor(0xFF201008);
    TextSetZ(-27.5f + t->obj->o.z);
    fn_801C2CF4(&eq, id);
    fn_801B6BB4(t->obj, t->obj->o.rect, id, -1, 0x14, 6, t->obj->o.alpha);
    if (id != -1) {
        p = t->obj;
        TextPrint(50.0f + p->o.rect[0], 5.0f + p->o.rect[1], fn_801C2CBC(id));
        y = 31.0f + t->obj->o.rect[1];
        x = (s16)(t->obj->o.rect[0] - 2.0f);
        TextPrintNumber(x + lbl_802B8ECC[4], y, eq.v[1], 0xC004);
        TextPrintNumber(x + lbl_802B8ECC[5], y, eq.v[2], 0xC004);
        TextPrintNumber(x + lbl_802B8ECC[6], y, eq.v[4], 0xC004);
        TextPrintNumber(x + lbl_802B8ECC[7], y, eq.v[7], 0xC004);
    } else {
        TextPrint(50.0f + t->obj->o.rect[0], 5.0f + t->obj->o.rect[1], lbl_802EC04C[0]);
        y = 31.0f + t->obj->o.rect[1];
        x = (s16)(t->obj->o.rect[0] - 2.0f);
        TextPrintNumber(x + lbl_802B8ECC[4], y, eq.v[1], 0xC004);
        TextPrintNumber(x + lbl_802B8ECC[5], y, eq.v[2], 0xC004);
        TextPrintNumber(x + lbl_802B8ECC[6], y, eq.v[4], 0xC004);
        TextPrintNumber(x + lbl_802B8ECC[7], y, eq.v[7], 0xC004);
    }
}

void fn_801B0014(void* arg) {
    PanelTask_801AFBE8* t = arg;
    MenuPanel* p;
    CmpEq eq;
    s16 id = lbl_8030B7F4.x1568.s1580[t->obj->h56];
    s32 x;
    s16 y;

    TextSetColor(0xFF201008);
    TextSetZ(-27.5f + t->obj->o.z);
    fn_801C2CF4(&eq, id);
    fn_801B6BB4(t->obj, t->obj->o.rect, id, -1, 0x14, 6, t->obj->o.alpha);
    if (id != -1) {
        p = t->obj;
        TextPrint(50.0f + p->o.rect[0], 5.0f + p->o.rect[1], fn_801C2CBC(id));
        y = 31.0f + t->obj->o.rect[1];
        x = (s16)(t->obj->o.rect[0] - 2.0f);
        TextPrintNumber(x + lbl_802B8EBC[4], y, eq.v[0], 0xC004);
        TextPrintNumber(x + lbl_802B8EBC[5], y, eq.v[3], 0xC004);
        TextPrintNumber(x + lbl_802B8EBC[6], y, eq.v[5], 0xC004);
        TextPrintNumber(x + lbl_802B8EBC[7], y, eq.v[6], 0xC001);
    } else {
        TextPrint(50.0f + t->obj->o.rect[0], 5.0f + t->obj->o.rect[1], lbl_802EC04C[0]);
        y = 31.0f + t->obj->o.rect[1];
        x = (s16)(t->obj->o.rect[0] - 2.0f);
        TextPrintNumber(x + lbl_802B8EBC[4], y, eq.v[0], 0xC004);
        TextPrintNumber(x + lbl_802B8EBC[5], y, eq.v[3], 0xC004);
        TextPrintNumber(x + lbl_802B8EBC[6], y, eq.v[5], 0xC004);
        TextPrintNumber(x + lbl_802B8EBC[7], y, eq.v[6], 0xC001);
    }
}

void fn_801B02F4(ShopPart* t) {
    void (*cb)(void* t);
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        UiObjCalcRect(&t->obj->o);
        UiLayoutDrawPart(&menu_sprites.texlist8, lbl_802B77FC, 1, t->obj->o.rect, t->obj->o.z, t->obj->o.alpha,
                         1.0f, t->flag->h6);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B7894[t->flag->h6].parts, lbl_802B7894[t->flag->h6].count,
                     t->obj->o.rect, t->obj->o.z, t->obj->o.alpha, 1.0f);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B77AC, 1, &t->obj->o.rect[2], t->obj->o.z, 1.0f, 1.0f);
        cb = t->flag->cb;
        if (cb != 0) {
            z = TextGetZ();
            TextPushColor();
            cb(t);
            TextPopColor(1);
            TextSetZ(z);
        }
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

Task2_801B0470* fn_801B0470(void* arg) {
    Task2_801B0470* t = fn_802267AC(arg, fn_801B02F4);
    t->data = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->o.alpha = 1.0f;
    t->pan->h54 = 4;
    t->data->s6 = 6;
    t->f2C = 0;
    t->data->cb = fn_801B0B2C;
    t->pan->o.alpha_en = 0;
    t->data->b0 = 0;
    t->pan->o.x = -348.0f;
    t->pan->o.tx = -348.0f;
    t->pan->o.y = 356.0f;
    t->pan->o.ty = 356.0f;
    t->pan->o.z = -4150.0f;
    t->pan->h52 = 1;
    t->pan->text = lbl_802EBF60[6];
    UiObjSetLowered(&t->pan->o);
    return t;
}

ShopPart* fn_801B057C(ShopTask* t, u16 kind, u16 who) {
    ShopPart* p = fn_802267AC(t, fn_801B02F4);
    p->flag = fn_801E1A74(1, 0x58);
    p->obj = fn_801E1A74(1, 0x6c);
    p->obj->o.f38 = 1.0f;
    p->obj->o.alpha = 1.0f;
    p->obj->h56 = who;
    p->obj->h54 = kind;
    p->flag->h6 = lbl_803471B8->w->m[who].id;
    p->flag->cb = fn_801B0838;
    p->obj->o.alpha_en = 0;
    p->flag->b0 = 0;
    p->obj->o.tx = p->obj->o.x = -348.0f;
    p->obj->o.ty = p->obj->o.y = lbl_802B8F20[kind].y;
    p->obj->o.z = lbl_802B8F20[kind].z;
    p->obj->h52 = 1;
    p->obj->text = lbl_803471B8->w->m[who].name;
    UiObjSetLowered(&p->obj->o);
    return p;
}

ShopPart* fn_801B06CC(ShopTask* t, u16 kind, u16 who, f32 alpha) {
    ShopPart* p = fn_802267AC(t, fn_801B02F4);
    p->flag = fn_801E1A74(1, 0x58);
    p->obj = fn_801E1A74(1, 0x6c);
    p->obj->o.f38 = 1.0f;
    p->obj2 = NULL;
    p->obj->h56 = who;
    p->obj->h54 = kind;
    p->flag->h6 = lbl_803471B8->w->m[who].id;
    p->flag->cb = fn_801B0838;
    p->obj->o.alpha_en = 0;
    p->obj->o.alpha = alpha;
    p->flag->b0 = 0;
    p->obj->o.tx = p->obj->o.x = -348.0f;
    p->obj->o.ty = p->obj->o.y = lbl_802B8F20[kind].y;
    p->obj->o.z = lbl_802B8F20[kind].z;
    p->obj->h52 = 1;
    p->obj->text = lbl_803471B8->w->m[who].name;
    UiObjSetLowered(&p->obj->o);
    return p;
}

void fn_801B0838(void* arg) {
    ShopPart* t = arg;
    TextSetColor(0xFF201008);
    TextPrint(86.0f + t->obj->o.rect[0], 6.0f + t->obj->o.rect[1], t->obj->text);
    TextPrint(224.0f + t->obj->o.rect[0], 6.0f + t->obj->o.rect[1], "Lv");
    TextPrint(86.0f + t->obj->o.rect[0], 30.0f + t->obj->o.rect[1], "Hp    /");
    TextPrint(224.0f + t->obj->o.rect[0], 30.0f + t->obj->o.rect[1], "Mp  /");
    if (t->obj->h54 != 4) {
        TextPrintNumber(248.0f + t->obj->o.rect[0], 6.0f + t->obj->o.rect[1], lbl_803471B8->w->m[t->obj->h56].b5, 0xC002);
        TextPrintNumber(248.0f + t->obj->o.rect[0], 30.0f + t->obj->o.rect[1], lbl_803471B8->w->m[t->obj->h56].b6, 0xC002);
        TextPrintNumber(284.0f + t->obj->o.rect[0], 30.0f + t->obj->o.rect[1], lbl_803471B8->w->m[t->obj->h56].b7, 0xC002);
        TextPrintNumber(110.0f + t->obj->o.rect[0], 30.0f + t->obj->o.rect[1], lbl_803471B8->w->m[t->obj->h56].h10, 0xC004);
        TextPrintNumber(170.0f + t->obj->o.rect[0], 30.0f + t->obj->o.rect[1], lbl_803471B8->w->m[t->obj->h56].h12, 0xC004);
    }
}

void fn_801B0B2C(u8 *obj) {
    u8 *e;
    s32 x;
    s32 y;

    TextSetColor(0xFF201008);
    e = *(u8 **)(obj + 0x28);
    x = (s32)(lbl_8034B96C + *(f32 *)(e + 0x24));
    y = (s32)(lbl_8034B8B0 + *(f32 *)(e + 0x28));
    TextPrint(x, y, *(const char **)(e + 0x4C));
}

void fn_801B0B9C(ShopPart* t) {
    const LayoutDef* e;
    u32 i;
    u32 n;
    s32 mask;
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        UiObjCalcRect(&t->obj->o);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B79F4, 2, t->obj->o.rect, t->obj->o.z, t->obj->o.alpha, 1.0f);
        mask = fn_801F4CA0();
        i = n = 0;
        e = &lbl_802B7B20[i];
        do {
            if (mask & (1 << i)) {
                MenuPanel* pan = t->obj;
                UiLayoutDraw(&menu_sprites.texlist8, e->parts, e->count, pan->o.rect, pan->o.z,
                             i == t->list->page ? pan->o.alpha : pan->o.alpha - 0.5f, pan->o.f38);
                n++;
            }
            i++;
            e++;
        } while (i < 6);
        if (n == 0) {
            TextPrint(24.0f + (8.0f + t->obj->o.rect[0]), 17.0f + t->obj->o.rect[1], lbl_802EC04C[8]);
        } else if (n >= 2) {
            t->x38->idx = 3;
            t->x38->x = t->obj->o.rect[0] + (f32)(t->list->page * 0x30);
            t->x38->y = t->obj->o.rect[1];
            fn_801B5D68(t);
        }
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B7B50, 1, &t->obj->o.rect[2], t->obj->o.z, 1.0f, 1.0f);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

ShopPart* fn_801B0DF8(void* arg) {
    ShopPart* t = fn_802267AC(arg, fn_801B0B9C);
    t->flag = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->list = fn_801E1A74(1, 0x20);
    t->x38 = fn_801E1A74(1, 0x18);
    t->obj2 = 0;
    t->x38->idx = 3;
    t->x38->state = 0;
    *(f32*)((u8*)t->obj + 0x38) = 1.0f;
    t->obj->o.alpha = 1.0f;
    *(f32*)((u8*)t->obj + 0x38) = 1.0f;
    t->obj->o.alpha = 1.0f;
    t->obj->o.z = -4300.0f;
    t->obj->o.alpha_en = 0;
    t->obj->h54 = 0;
    t->obj->h52 = 0;
    ((u8*)t->flag)[0] = 0;
    t->obj->o.x = -348.0f;
    t->obj->o.tx = -348.0f;
    t->obj->o.y = 164.0f;
    t->obj->o.ty = 164.0f;
    UiObjSetLowered(&t->obj->o);
    t->x38->state = 1;
    return t;
}

void fn_801B0F1C(Task_801B0F1C *t) {
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B7720, 4, &t->pan->o.x, t->pan->o.z, 1.0f, 1.0f);
        fn_801B6BB4(t->pan, &t->pan->o.x, lbl_803471B8->w->item, -1, 0x18, 0x14, 1.0f);
        TextSetZ(-27.5f + t->pan->o.z);
        TextPrint(55.0f + t->pan->o.x, 20.0f + t->pan->o.y, t->pan->text);
        TextPrint(264.0f + t->pan->o.x, 20.0f + t->pan->o.y, "\x81\x7e");
        TextPrintNumber(288.0f + t->pan->o.x, 20.0f + t->pan->o.y, lbl_803471B8->w->x9, 0xC002);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

Node* fn_801B1104(void* a)
{
    Node* o = fn_802267AC(a, fn_801B0F1C);
    o->w = fn_801E1A74(1, 0x58);
    o->obj = fn_801E1A74(1, 0x6c);
    o->obj->o.f38 = 1.0f;
    o->obj->o.alpha = 1.0f;
    o->x2c = 0;
    o->obj->h54 = 0;
    o->w->b0 = 0;
    o->obj->o.x = -348.0f;
    o->obj->o.tx = -348.0f;
    o->obj->o.y = 36.0f;
    o->obj->o.ty = 36.0f;
    o->obj->o.z = -4050.0f;
    o->obj->h52 = 0;
    o->obj->text = fn_801F4AE4((s16)lbl_803471B8->w->item);
    UiObjSetLowered(&o->obj->o);
    return o;
}

void fn_801B11EC(Task_801B11EC* t) {
    f32 x;
    f32 y;
    f32 z;
    s16 id;
    CmpEq eq;
    CmpEq eq2;
    s16 ix;
    s16 iy;

    if (lbl_803475D8 != 0) {
        t->state = 0xff;
    }
    switch (t->state) {
    case 0:
    case 1:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B7700[t->obj->h52].parts,
                     lbl_802B7700[t->obj->h52].count, &t->obj->o.x, t->obj->o.z, 1.0f, 1.0f);
        TextSetZ(-27.5f + t->obj->o.z);
        id = fn_801B93E8(lbl_803471B8);
        switch (fn_801F4C24(id)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 7:
            fn_801C2E48(&eq, id);
            break;
        case 5:
        case 6:
            fn_801C2CF4(&eq2, id);
            break;
        }
        TextSetColor(0xFF201008);
        switch (t->obj->h52) {
        case 0:
            IT_HEAD(t, id);
            y = 30.0f + t->obj->o.y;
            x = t->obj->o.x - 14.0f;
            IT_NUM(eq.v[0], x, y, 7);
            IT_NUM(eq.v[1], x, y, 8);
            IT_NUM(eq.v[2], x, y, 9);
            IT_NUM(eq.v[3], x, y, 10);
            IT_NUM(eq.v[4], x, y, 11);
            IT_NUM(eq.v[5], x, y, 12);
            IT_NUM(eq.v[6], x, y, 13);
            break;
        case 2:
            IT_HEAD(t, id);
            iy = 30.0f + t->obj->o.y;
            ix = t->obj->o.x - 14.0f;
            IT_SNUM(eq2.v[0], ix, iy, lbl_802B8EBC, 4, 0xC004);
            IT_SNUM(eq2.v[3], ix, iy, lbl_802B8EBC, 5, 0xC004);
            IT_SNUM(eq2.v[5], ix, iy, lbl_802B8EBC, 6, 0xC004);
            IT_SNUM(eq2.v[6], ix, iy, lbl_802B8EBC, 7, 0xC001);
            break;
        case 1:
            IT_HEAD(t, id);
            iy = 30.0f + t->obj->o.y;
            ix = t->obj->o.x - 14.0f;
            IT_SNUM(eq2.v[1], ix, iy, lbl_802B8ECC, 4, 0xC004);
            IT_SNUM(eq2.v[2], ix, iy, lbl_802B8ECC, 5, 0xC004);
            IT_SNUM(eq2.v[4], ix, iy, lbl_802B8ECC, 6, 0xC004);
            IT_SNUM(eq2.v[7], ix, iy, lbl_802B8ECC, 7, 0xC004);
            break;
        case 3:
            IT_HEAD(t, id);
            break;
        }
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

ShopPart* fn_801B1A78(void* a)
{
    ShopPart* o = fn_802267AC(a, fn_801B11EC);
    o->flag = fn_801E1A74(1, 0x58);
    o->obj = fn_801E1A74(1, 0x6c);
    o->obj2 = 0;
    o->flag->b0 = 0;
    o->obj->o.x = 648.0f;
    o->obj->o.tx = 648.0f;
    o->obj->o.y = 282.0f;
    o->obj->o.ty = 282.0f;
    o->obj->h54 = 0;
    o->obj->h52 = 0;
    o->obj->o.f38 = 1.0f;
    o->obj->o.alpha = 1.0f;
    o->obj->o.z = -4400.0f;
    return o;
}

void fn_801B1B3C(ShopPart* t) {
    NJS_TEXLIST** tl;
    f32 z;
    f32 s;

    if (lbl_803475D8 != 0) {
        t->state = 0xFF;
    }
    switch (t->state) {
    case 0:
    case 1:
    case 0xFE:
        if (t->flag->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        tl = &menu_sprites.texlist8;
        UiLayoutDraw(tl, lbl_802B71EC, 3, &t->obj->o.x, t->obj->o.z, 1.0f, 1.0f);
        z = -42.75f + t->obj->o.z;
        if (fn_801B94F0()) {
            s32 i;
            const LayoutDef* p;
            UiLayoutDraw(tl, lbl_802B7304[t->list->tab].parts, lbl_802B7304[t->list->tab].count, &t->obj->o.x, z, 1.0f, 1.0f);
            z -= 0.25f;
            for (i = 0, p = lbl_802B7304; i < 5; i++, p++) {
                if (t->list->tab != i && fn_801B952C(i)) {
                    UiLayoutDraw(tl, p->parts, 2, &t->obj->o.x, z, 0.7f, 1.0f);
                    z -= 0.25f;
                }
            }
        } else {
            UiLayoutDraw(tl, lbl_802B72F0, 1, &t->obj->o.x, z, 1.0f, 1.0f);
        }
        switch (t->state) {
        case 0:
            if (fn_801B94F0()) {
                if (t->x38->state == 0) {
                    t->x38->state = 1;
                }
                t->x38->idx = 1;
                t->x38->x = t->obj->o.x + t->obj->o.rdx + (f32)(t->list->tab * 48);
                t->x38->y = t->obj->o.y + t->obj->o.rdy;
            } else {
                t->x38->state = 0;
            }
            break;
        case 1: {
            UiObj* ui;
            ShopList* c;
            t->x38->idx = 2;
            t->x38->x = t->obj->o.x;
            t->x38->y = t->obj->o.y;
            c = t->list;
            ui = &t->obj->o;
            if ((c->flags & 1) && c->part != 0xFF) {
                s = 0.0f;
                if (c->flags & 2) {
                    c->x = ui->x + c->ox;
                    c->y = ui->y + c->oy;
                    c->scale = 0.3f * njCos(c->angle) + 1.0f;
                    c->angle += 0x800;
                    s = c->scale;
                }
                UiLayoutDrawPart(tl, (void*)lbl_802B6A64, 1, &c->x, ui->z, s, 1.0f, c->part);
            }
            break;
        }
        }
        fn_801B5D68(t);
        fn_801B1EA0(t);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

/* Whether there is anything to sell. inline, like fn_801B952C: fn_801B1B3C (before them) calls
 * them, fn_801B7624 (after) has them inlined. */
inline s32 fn_801B94F0(void)
{
    u32 sum = lbl_803471B8->sell[3].n;
    sum += lbl_803471B8->sell[0].n;
    sum += lbl_803471B8->sell[1].n;
    sum += lbl_803471B8->sell[2].n;
    sum += lbl_803471B8->sell[4].n;
    return sum != 0;
}

/* How many items a sell tab lists. */
inline u16 fn_801B952C(u16 k)
{
    switch (k) {
    case 0:
        return (u16)lbl_803471B8->sell[3].n;
    case 1:
        return (u16)lbl_803471B8->sell[0].n;
    case 2:
        return (u16)lbl_803471B8->sell[1].n;
    case 3:
        return (u16)lbl_803471B8->sell[2].n;
    case 4:
        return (u16)lbl_803471B8->sell[4].n;
    default:
        return 0;
    }
}

Task3_801B2310* fn_801B2310(void* arg) {
    Task3_801B2310* t = fn_802267AC(arg, fn_801B1B3C);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->c = fn_801E1A74(1, 0x20);
    t->d = fn_801E1A74(1, 0x18);
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->o.alpha = 1.0f;
    t->d->sA = 0;
    t->f2C = 0;
    t->c->b1E = 0;
    t->c->s1C = 0;
    t->c->s18 = 0;
    t->c->s1A = 0;
    t->c->b1F = 3;
    t->pan->h54 = 0;
    t->pan->h56 = 0;
    t->a[0] = 0;
    t->pan->o.x = 648.0f;
    t->pan->o.tx = 648.0f;
    t->pan->o.y = 100.0f;
    t->pan->o.ty = 100.0f;
    t->pan->o.z = -4500.0f;
    UiObjSetLowered(&t->pan->o);
    return t;
}

void fn_801B2430(Task_801B0F1C *t) {
    f32 z;
    NJS_POINT3 pos;
    if (lbl_803475D8 != 0) {
        t->state = 0xff;
    }
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B6DF8, 4, &t->pan->o.x, t->pan->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        TextSetZ(-27.5f + t->pan->o.z);
        TextPrint(20.0f + t->pan->o.x, 5.0f + t->pan->o.y, t->pan->text);
        TextPrint(20.0f + t->pan->o.x, 32.0f + t->pan->o.y, lbl_802EC04C[5]);
        TextPopColor(1);
        pos.x = 84.0f + (97.0f + (t->pan->o.x + t->pan->o.rdx));
        pos.y = 7.0f + (t->pan->o.y - t->pan->o.rdy);
        pos.z = -32.0f + t->pan->o.z;
        UiDrawNumber(&pos, 0, 8, lbl_803471B8->w->cost, t->pan->o.alpha);
        pos.y = 34.0f + (t->pan->o.y - t->pan->o.rdy);
        pos.z = -31.5f + t->pan->o.z;
        UiDrawNumber(&pos, 0, 8, lbl_803471B8->w->left, t->pan->o.alpha);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

Task2_801B2678* fn_801B2678(void* arg, u16 sel) {
    Task2_801B2678* t = fn_802267AC(arg, fn_801B2430);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->pan->o.z = -4400.0f;
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->o.alpha = 1.0f;
    t->f2C = 0;
    t->pan->h54 = 0;
    t->a[0] = 0;
    t->pan->o.x = -240.0f;
    t->pan->o.tx = -240.0f;
    t->pan->o.y = 206.0f;
    t->pan->o.ty = 206.0f;
    if (sel == 0) {
        t->pan->text = lbl_802EC04C[3];
    } else {
        t->pan->text = lbl_802EC04C[4];
    }
    UiObjSetLowered(&t->pan->o);
    return t;
}

void fn_801B277C(Task* task) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    extern void fn_801B28D4(Task* t);
    extern s32 fn_801C09F8(s32 a, s32 b);
    MP* p = (MP*)task;
    if (lbl_803475D8 != 0) {
        task->state = 0xFF;
    }
    switch (task->state) {
    case 0:
    case 0xFE:
        if (*(u8*)task->work == 1) {
            return;
        }
        UiObjCalcRect(&p->obj->o);
        UiObjUpdate(&p->obj->o);
        if (p->obj->h52 != 4) {
            fn_801B28D4(task);
        }
        if (p->obj->h52 == 0) {
            if (fn_801C09F8(0, 10) != 0) {
                ((W*)task->work)->v++;
                if (((W*)task->work)->v == 3) {
                    ((W*)task->work)->v = 0;
                }
                MenuPlaySe(4);
            }
        } else if (p->obj->h52 == 1 || p->obj->h52 == 2) {
            if (fn_801C09F8(0, 10) != 0) {
                ((W*)task->work)->v++;
                ((W*)task->work)->v &= 1;
                MenuPlaySe(4);
            }
        }
        break;
    case 0xFF:
        MenuDummy(task);
        task->flags |= 0x40;
        break;
    }
}

void fn_801B42F8(ShopPart* t) {
    MenuPanel* o = t->obj;
    s32 i;
    s16 id;
    s16 ix;
    s16 iy;
    ShopRow* r;

    for (i = 0; i < 3; i++) {
        fn_801C1728(o->h56, i);
    }
    for (i = 0; i < 3; i++) {
        id = lbl_803471B8->w->h10a[i];
        if (id != -1) {
            if (id == o->h56) {
                TextSetColor(0x40201008);
                TextPrint(260.0f + o->o.rect[0], 60.0f + o->o.rect[1] + 25 * i, lbl_802EC04C[2]);
            } else {
                TextSetColor(0xff201008);
                ShopNums3(o, i);
            }
            TextPrint(44.0f + o->o.rect[0], 60.0f + o->o.rect[1] + 25 * i, fn_801F4AE4(lbl_803471B8->w->h10a[i]));
            fn_801B6BB4(o, &o->o.rect[0], lbl_803471B8->w->h10a[i], -1, 0x10, 0x3c + 25 * i, o->o.alpha);
        } else {
            TextSetColor(0xff201008);
            TextPrint(44.0f + o->o.rect[0], 60.0f + o->o.rect[1] + 25 * i, lbl_802EC04C[0]);
            ShopNums3(o, i);
        }
    }
}

void fn_801B46EC(void* arg) {
    ShopPart* t = arg;
    MenuPanel* v = t->obj;
    s16 id;
    s32 i;
    for (i = 0; i < 3; i++) {
        id = lbl_803471B8->w->h10a[i];
        if (id != -1) {
            if (id == v->h56) {
                TextSetColor(0x40201008);
                TextPrint(260.0f + v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 25), lbl_802EC04C[2]);
            } else {
                TextSetColor(0xFF201008);
                fn_801B4F78(v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 24), v->h56, lbl_803471B8->w->h10a[i]);
            }
            TextPrint(44.0f + v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 25), fn_801F4AE4(lbl_803471B8->w->h10a[i]));
            fn_801B6BB4(v, &v->o.rect[0], lbl_803471B8->w->h10a[i], -1, 0x10, 0x3C + i * 25, v->o.alpha);
        } else {
            TextSetColor(0xFF201008);
            TextPrint(44.0f + v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 25), lbl_802EC04C[0]);
            fn_801B4F78(v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 24), v->h56, lbl_803471B8->w->h10a[i]);
        }
    }
}

void fn_801B49B0(ShopPart* t) {
    MenuPanel* v = t->obj;
    s32 i;
    s32 sel;
    u32 color;
    f32 f;

    for (i = 0; i < 4; i++) {
        fn_801C1728(v->h56, i);
    }
    for (i = 0; i < 4; i++) {
        switch (fn_801C153C(i, v->h56)) {
        case 0:
            f = v->o.alpha;
            color = 0xFF201008;
            sel = -1;
            TextSetColor(color);
            ShopNums4(v, i);
            break;
        case 1:
            f = 0.7f * v->o.alpha;
            color = 0x40201008;
            sel = 2;
            break;
        case 2:
            f = 0.7f * v->o.alpha;
            color = 0x40201008;
            sel = 1;
            break;
        }
        TextSetColor(color);
        fn_801B6BB4(v, &v->o.rect[0], lbl_803471B8->w->d8[i].v, -1, 0x10, 0x3C + i * 25, f);
        TextPrint(44.0f + v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 25), fn_801F4AE4(lbl_803471B8->w->d8[i].v));
        if (sel != -1) {
            TextPrint(236.0f + v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 25), lbl_802EC04C[sel]);
        }
    }
}

void fn_801B4CF0(void* arg) {
    ShopPart* t = arg;
    MenuPanel* v = t->obj;
    s32 i;
    s32 sel;
    u32 color;
    f32 f;

    for (i = 0; i < 4; i++) {
        switch (fn_801C153C(i, v->h56)) {
        case 0:
            f = v->o.alpha;
            color = 0xFF201008;
            sel = -1;
            fn_801B4F78(v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 24), v->h56, lbl_803471B8->w->d8[i].v);
            break;
        case 1:
            f = 0.7f * v->o.alpha;
            color = 0x40201008;
            sel = 2;
            break;
        case 2:
            f = 0.7f * v->o.alpha;
            color = 0x40201008;
            sel = 1;
            break;
        }
        TextSetColor(color);
        fn_801B6BB4(v, &v->o.rect[0], lbl_803471B8->w->d8[i].v, -1, 0x10, 0x3C + i * 25, f);
        TextPrint(44.0f + v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 25), fn_801F4AE4(lbl_803471B8->w->d8[i].v));
        if (sel != -1) {
            TextPrint(236.0f + v->o.rect[0], 60.0f + v->o.rect[1] + (f32)(i * 25), lbl_802EC04C[sel]);
        }
    }
}

void* fn_801B54D4(void* a) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    T_801B54D4* t = fn_802267AC(a, fn_801B277C);
    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->obj2 = fn_801E1A74(1, 0x6c);
    t->p3c = fn_801E1A74(1, 0x9c);
    t->w->b0 = 0;
    t->w->h4 = 0;
    t->obj2->h54 = 0;
    t->obj->h54 = 0;
    t->obj2->h52 = 4;
    t->obj->h52 = 4;
    t->obj->o.z = -4700.0f;
    t->obj2->o.z = -4750.0f;
    t->obj2->o.alpha_en = 0;
    t->obj->o.alpha_en = 0;
    t->obj2->o.alpha = 1.0f;
    *(f32*)((u8*)t->obj2 + 0x38) = 1.0f;
    t->obj->o.alpha = 1.0f;
    *(f32*)((u8*)t->obj + 0x38) = 1.0f;
    t->obj2->o.x = -624.0f;
    t->obj2->o.tx = -624.0f;
    t->obj->o.x = -624.0f;
    t->obj->o.tx = -624.0f;
    t->obj2->o.y = 212.0f;
    t->obj2->o.ty = 212.0f;
    t->obj->o.y = 212.0f;
    t->obj->o.ty = 212.0f;
    UiObjSetLowered(&t->obj->o);
    t->w->w8 = -1;
    t->w->wc = 0;
    t->w->w10 = 0;
    return t;
}

void fn_801B5644(ShopPart* p, u16 id) {
    UiObjMoveToX(&p->obj->o, 6, -1, -8.0f);
    UiObjSetCommand(&p->obj->o, 15, 0);
    p->obj->o.z = -4700.0f;
    p->obj->h52 = ShopItemKind(id);
    p->obj->h56 = id;
}

void fn_801B571C(ShopPart* p, u16 id) {
    if (UiObjIsBusy(&p->obj->o)) {
        UiObjFinish(&p->obj->o);
    }
    if (p->obj->h52 != ShopItemKind(id)) {
        p->flag->w10 = 0;
    }
    p->obj->h52 = ShopItemKind(id);
    p->obj->h56 = id;
}

s32 fn_801B5868(s16 id) {
    s16 kind = fn_801F4C24(id);
    switch (kind) {
    case 0:
    case 1:
    case 2:
        return 0;
    case 5:
        return 2;
    case 6:
        return 1;
    case 3:
    case 4:
    case 7:
        return 3;
    default:
        return 4;
    }
}

Task3_801B5C4C* fn_801B5C4C(void* arg) {
    Task3_801B5C4C* t = fn_802267AC(arg, fn_801B58E0);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->c = fn_801E1A74(1, 0x20);
    t->d = fn_801E1A74(1, 0x18);
    t->f2C = 0;
    t->d->s8 = 0;
    t->d->sA = 0;
    t->c->b1E = 0;
    t->c->b1F = 3;
    t->pan->o.alpha_en = 0;
    t->a[0] = 0;
    t->pan->o.x = 648.0f;
    t->pan->o.tx = 648.0f;
    t->pan->o.y = 38.0f;
    t->pan->o.ty = 38.0f;
    t->pan->o.rdx = 0.0f;
    t->pan->o.rdy = 0.0f;
    *(f32*)((u8*)t->pan + 0x38) = 1.0f;
    t->pan->o.alpha = 1.0f;
    t->pan->o.z = -4500.0f;
    UiObjSetLowered(&t->pan->o);
    return t;
}

void fn_801B5D68(ShopPart* t) {
    if (t->x38 != 0) {
        switch (t->x38->state) {
        case 0:
            t->x38->f10 = 0;
            t->x38->angle = 0;
            t->x38->scale = 1.0f;
            break;
        case 1:
            t->x38->scale = 1.0f;
            t->x38->state = 2;
            t->x38->angle = 0;
        case 2:
            if (lbl_802B73A4[t->x38->idx].flag6 != 0) {
                t->x38->scale = 1.0f - 0.7f * njSin(t->x38->angle);
                t->x38->angle += 0x400;
                t->x38->angle &= 0x7F00;
            }
            UiLayoutDraw(&menu_sprites.texlist8, lbl_802B73A4[t->x38->idx].parts, 2,
                         (f32*)t->x38, -32.5f + t->obj->o.z, 1.0f, t->x38->scale);
            break;
        }
    }
}

void fn_801B5EA8(PanelTask_801ABF70* t) {
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->ui->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B6DD0, 2, &t->ui->o.x, t->ui->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        fn_801B6E5C(t);
        TextSetZ(-27.5f + t->ui->o.z);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

void fn_801B5FA8(PanelTask_801ABD40* t) {
    f32 z;
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B6DD0, 2, &t->pan->o.x, t->pan->o.z, 1.0f, 1.0f);
        if (t->pan->text != 0) {
            TextSetZ(-27.5f + t->pan->o.z);
            TextPrint(18.0f + t->pan->o.x, 12.0f + t->pan->o.y, t->pan->text);
            TextSetZ(z);
        }
        TextPopColor(1);
        break;
    case 0xFF:
        MenuDummy();
        t->flags |= 0x40;
        break;
    }
}

void fn_801B60E8(MP* p) {
    Tri t = lbl_802B8EF0;
    int i;
    VertexCol* v;
    f32 z = fn_801DBD9C(-0.1f);
    for (i = 0; i < 3; i++) {
        v = &t.v[i];
        v->x = 264.0f + (18.0f + v->x) + p->obj->o.x;
        v->y = 48.0f + (16.0f + v->y) + p->obj->o.y;
        v->z = z;
    }
    fn_80290ED4(t.v, 3, 0);
}

ShopPart* fn_801B6240(void* a, f32 x)
{
    ShopPart* o = fn_802267AC(a, fn_801B5EA8);
    o->flag = fn_801E1A74(1, 0x58);
    o->obj = fn_801E1A74(1, 0x6c);
    o->obj2 = 0;
    o->flag->b0 = 0;
    o->obj->o.alpha_en = 0;
    o->obj->o.x = 640.0f;
    o->obj->o.tx = 640.0f;
    o->obj->o.y = 480.0f;
    o->obj->o.ty = 480.0f;
    o->obj->o.rdx = 0.0f;
    o->obj->o.rdy = 0.0f;
    o->obj->o.alpha = 1.0f;
    o->obj->o.z = x;
    UiObjSetLowered(&o->obj->o);
    return o;
}

ShopPart* fn_801B6320(void* a, f32 x)
{
    ShopPart* o = fn_802267AC(a, fn_801B5FA8);
    o->flag = fn_801E1A74(1, 0x58);
    o->obj = fn_801E1A74(1, 0x6c);
    o->obj2 = 0;
    o->flag->b0 = 0;
    o->obj->o.alpha_en = 0;
    o->obj->o.x = 640.0f;
    o->obj->o.tx = 640.0f;
    o->obj->o.y = 480.0f;
    o->obj->o.ty = 480.0f;
    o->obj->o.rdx = 0.0f;
    o->obj->o.rdy = 0.0f;
    o->obj->o.alpha = 1.0f;
    o->obj->o.z = x;
    UiObjSetLowered(&o->obj->o);
    return o;
}

void fn_801B6400(const char* v) {
    ShopWork* w = lbl_803471B8->w;
    ShopPart* q = w->parts[7];
    if (q == 0) {
        return;
    }
    q->obj->text = v;
}

void fn_801B6420(Task* task) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    MP* p = (MP*)task;
    NJS_TEXLIST** tl;
    f32 z;
    if (lbl_803475D8 != 0) {
        task->state = 0xFF;
    }
    switch (task->state) {
    case 0:
    case 0xFE:
        if (*(u8*)task->work == 1) {
            return;
        }
        UiObjUpdate(&p->obj->o);
        UiObjCalcRect(&p->obj->o);
        tl = &menu_sprites.texlist8;
        UiLayoutDraw(tl, lbl_802B6DA0[p->obj->h54].parts, lbl_802B6DA0[p->obj->h54].count, p->obj->o.rect, p->obj->o.z, p->obj->o.alpha, 1.0f);
        UiLayoutDraw(tl, (void*)lbl_802B6D8C, 1, &p->obj->o.rect[2], p->obj->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextPushColor();
        TextSetColor(0xFF201008);
        TextSetZ(-27.5f + p->obj->o.z);
        TextPrint((s32)(p->obj->o.rect[0] + lbl_802EC01C[p->obj->h56].x), (s32)(17.0f + p->obj->o.rect[1]), p->obj->text);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(task);
        task->flags |= 0x40;
        break;
    }
}

T_801B65CC* fn_801B65CC(void* a, u16 idx, f32 y) {
    T_801B65CC* t = fn_802267AC(a, fn_801B6420);
    t->w = fn_801E1A74(1, 0x58);
    t->obj = fn_801E1A74(1, 0x6c);
    t->w2c = 0;
    t->w2c = 0;
    t->obj->h54 = idx;
    t->w->b0 = 0;
    t->obj->o.alpha_en = 1;
    t->obj->o.x = -260.0f;
    t->obj->o.tx = -260.0f;
    t->obj->o.y = y;
    t->obj->o.ty = y;
    t->obj->o.z = lbl_802B8EDC[idx];
    t->obj->o.rdx = 0.0f;
    t->obj->o.rdy = 0.0f;
    t->obj->o.alpha = 1.0f;
    t->obj->text = lbl_802EC01C[idx].text;
    t->obj->h56 = idx;
    UiObjSetLowered(&t->obj->o);
    return t;
}

void fn_801B66F8(PanelTask_801ABD40* t) {
    f32 z;
    if (lbl_803475D8 != 0) {
        t->state = 0xFF;
    }
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag[0] == 1) {
            return;
        }
        UiObjUpdate(&t->pan->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B6B0C, 4, &t->pan->o.x, t->pan->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextSetZ(-4027.5f);
        TextPushColor();
        TextSetColor(0xFF201008);
        TextPrint(20.0f + t->pan->o.x, 20.0f + t->pan->o.y, t->pan->text);
        TextPopColor(1);
        TextSetZ(z);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

Task2_801B6838* fn_801B6838(void* arg) {
    Task2_801B6838* t = fn_802267AC(arg, (void *)fn_801B66F8);
    t->a = fn_801E1A74(1, 0x58);
    t->pan = fn_801E1A74(1, 0x6c);
    t->a[0] = 0;
    t->pan->o.alpha_en = 0;
    t->pan->o.z = -4000.0f;
    t->pan->o.x = -260.0f;
    t->pan->o.tx = -260.0f;
    t->pan->o.y = 36.0f;
    t->pan->o.ty = 36.0f;
    t->pan->o.rdx = 0.0f;
    t->pan->o.rdy = 0.0f;
    t->pan->o.alpha = 1.0f;
    if (lbl_803473BF == 0) {
        t->pan->text = lbl_802EC0A0[lbl_803473BC].label;
    } else {
        t->pan->text = lbl_802ED218[lbl_803473BC].label;
    }
    UiObjSetRaised(&t->pan->o);
    return t;
}

void fn_801B6950(ShopPart* t) {
    f32 z;
    NJS_POINT3 pos;
    if (lbl_803475D8 != 0) {
        t->state = 0xFF;
    }
    switch (t->state) {
    case 0:
    case 0xFE:
        if (t->flag->b0 == 1) {
            return;
        }
        UiObjUpdate(&t->obj->o);
        UiLayoutDraw(&menu_sprites.texlist8, lbl_802B6B5C, 4, &t->obj->o.x, t->obj->o.z, 1.0f, 1.0f);
        z = TextGetZ();
        TextSetZ(-4427.5f);
        TextPushColor();
        TextSetColor(0xFF201008);
        TextPrint(20.0f + t->obj->o.x, 10.0f + t->obj->o.y, lbl_802EC04C[9]);
        TextPopColor(1);
        TextSetZ(z);
        pos.x = 182.0f + t->obj->o.x;
        pos.y = 14.0f + t->obj->o.y;
        pos.z = -4432.5f;
        UiDrawNumber(&pos, 0, 8, lbl_8030B7F4.w34c, t->obj->o.alpha);
        break;
    case 0xFF:
        MenuDummy(t);
        t->flags |= 0x40;
        break;
    }
}

ShopPart* fn_801B6AE8(void* a)
{
    ShopPart* o = fn_802267AC(a, fn_801B6950);
    o->flag = fn_801E1A74(1, 0x58);
    o->obj = fn_801E1A74(1, 0x6c);
    o->flag->b0 = 0;
    o->obj->o.alpha_en = 0;
    o->obj->o.z = -4400.0f;
    o->obj->o.x = -260.0f;
    o->obj->o.tx = -260.0f;
    o->obj->o.y = 100.0f;
    o->obj->o.ty = 100.0f;
    o->obj->o.rdx = 0.0f;
    o->obj->o.rdy = 0.0f;
    o->obj->o.alpha = 1.0f;
    UiObjSetRaised(&o->obj->o);
    return o;
}

void fn_801B71E8(s32 x, s32 y, s16 id) {
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    switch (lbl_80310A1C[0x64 + id]) {
    case 1:
    case 2:
        TextPrint(x, y, lbl_802EBFDC[id].a);
        break;
    case 3:
        TextPrint(x, y, lbl_802EBFDC[id].b);
        break;
    default:
        TextPrint(x, y, lbl_802B8F80);
        break;
    }
}

void fn_801B7274(s32 x, s32 y, s32 nx, s32 ny, s16 id) {
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void TextPrintNumber(s32 x, s32 y, s32 value, u32 flags);
    char buf[32];
    switch (lbl_80310A1C[0x64 + id]) {
    case 0:
        strcpy(buf, lbl_802B8F94);
        break;
    case 1:
    case 2:
        strcpy(buf, lbl_802EBF7C[id]);
        break;
    case 3:
        if (id != 5) {
            strcpy(buf, lbl_802EBF7C[id]);
        } else {
            strcpy(buf, lbl_802B8F70);
        }
        break;
    }
    TextPrint(x, y, buf);
    TextPrintNumber(nx, ny, lbl_802EBFBC[id], 0xC005);
}

void fn_801B737C(ShopPart* t)
{
    char buf[32];
    s32 i;
    s32 ok;
    for (i = 0; i < 8; i++) {
        ok = 0;
        switch (i) {
        case 0:
            strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
            ok = 1;
            break;
        case 1:
            if ((*(Fl*)&lbl_80310B3C).f4 & 0x10000000) {
                strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 2:
            if ((*(Fl*)&lbl_80310B3C).f18 & 0x100) {
                strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 3:
            if ((*(Fl*)&lbl_80310B3C).f1c & 0x04000000) {
                strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 4:
            if ((*(Fl*)&lbl_80310B3C).f168 & 0x40000000) {
                strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 5:
            if (((*(Fl*)&lbl_80310B3C).f30 & 0x10000) || (*(St_801B737C*)&lbl_80310A1C).seen[5] > 0) {
                ok = 1;
                if ((*(St_801B737C*)&lbl_80310A1C).seen[5] > 1) {
                    strcpy((void *)(buf), lbl_802B8F70);
                } else {
                    strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                }
            }
            break;
        case 6:
            if ((*(Fl*)&lbl_80310B3C).f170 & 0x80) {
                strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        case 7:
            if ((*(Fl*)&lbl_80310B3C).f30 & 0x1000000) {
                strcpy((void *)(buf), (void *)(((char**)lbl_802EBF7C)[i]));
                ok = 1;
            }
            break;
        }
        if (ok == 0) {
            TextSetColor(0x40201008);
            TextPrint((s32)(16.0f + t->obj->o.x), (s32)(12.0f + t->obj->o.y + (f32)(i * 24)), lbl_802B8F94);
            TextSetColor(0xFF201008);
        } else {
            TextPrint((s32)(16.0f + t->obj->o.x), (s32)(12.0f + t->obj->o.y + (f32)(i * 24)), (void *)(buf));
        }
        if ((*(St_801B737C*)&lbl_80310A1C).seen[i] == 0 && ok == 1) {
            (*(St_801B737C*)&lbl_80310A1C).seen[i] = 1;
        }
    }
}


void fn_801B8E68(Task_801B8E68* t)
{
    u32 n;
    Sub2* s = t->p24;

    n = s->w11c;
    if (n == 0) {
        return;
    }
    if (lbl_80311A60[0]->held & 0x100) {
        lbl_8030B7F4.w34c += n;
        s->w11c = 0;
        if (lbl_8030B7F4.w34c >= 99999999) {
            lbl_8030B7F4.w34c = 99999999;
        }
        return;
    }
    if (n <= s->w124) {
        lbl_8030B7F4.w34c += n;
        s->w11c = 0;
        if (lbl_8030B7F4.w34c >= 99999999) {
            lbl_8030B7F4.w34c = 99999999;
        }
        return;
    }
    s->w11c = n - s->w124;
    lbl_8030B7F4.w34c += t->p24->w124;
    if (lbl_8030B7F4.w34c >= 99999999) {
        lbl_8030B7F4.w34c = 99999999;
    }
}

s32 fn_801B8F48(s32 mode, s16* sel, s16 id) {
    extern void MenuDummy(Task* t);
    extern TextNode* TextPrint(s32 x, s32 y, const char *str);
    extern void* fn_802267AC(void* a, void (*b)(Task*));
    extern void* fn_801E1A74(s32 a, s32 b);
    extern u8 fn_801F464C(s32 id);
    extern u16 fn_801F477C(s32 id);
    extern s8 fn_801F452C(s32 id);
    extern u16 fn_801B995C(s32 id);
    u32 total;
    u32 cnt = fn_801F464C(id);
    s32 cur;
    s32 n;
    if (cnt == 0) {
        total = 0;
    } else {
        total = cnt * fn_801F477C(id) / 100;
    }
    if (total == 0) {
        return -1;
    }
    n = fn_801F452C(id) - fn_801B995C(id);
    cur = *sel;
    switch (mode) {
    case 4:
        if (cur > 1) {
            *sel = cur - 1;
        }
        break;
    case 8:
        if ((u32)cur < (u32)n) {
            *sel = cur + 1;
        }
        break;
    case 1:
        if ((u32)(n + 1) < 10) {
            *sel = 1;
        } else {
            if (cur < 10) {
                *sel = 1;
            } else {
                *sel = cur - 10;
            }
            if (*sel == 0) {
                *sel = 1;
            }
        }
        break;
    case 2:
        if ((u32)(n + 1) < 10) {
            *sel = n;
        } else {
            *sel = cur + 10;
            if ((u32)*sel >= (u32)(n + 1)) {
                *sel = n;
            }
            if (*sel == 0) {
                *sel = 1;
            }
        }
        break;
    }
    if ((u32)cur != (u32)*sel) {
        MenuPlaySe(0);
    }
    return total * (u16)*sel;
}

/* Item count (fn_801F464C) times per-unit value (fn_801F477C), divided by 100. */
u32 fn_801B90E4(s32 idx) {
    s16 id = idx;
    u32 cnt = fn_801F464C(id);

    if (cnt == 0) {
        return 0;
    }
    return cnt * fn_801F477C(id) / 100;
}

void fn_801B914C(ShopTask* t, u8 dir)
{
    u16 old;
    ShopPart* s;
    s32 i;
    u16 ok;
    s = t->w->parts[8];
    old = s->list->tab;
    switch (dir) {
    case 0:
        s->list->tab = 0;
        goto fwd;
    case 2:
        if (old == 4) s->list->tab = 0;
        else s->list->tab = old + 1;
    case 1:
    fwd:
        for (i = 0; i < 5; i++) {
            ok = fn_801B952C(t->w->parts[8]->list->tab);
            if (ok != 0) break;
            s->list->tab++;
            if (s->list->tab == 5) s->list->tab = 0;
        }
        if ((s32)old != s->list->tab) {
            s->list->page = 0;
            s->list->row = 0;
            s->x38->angle = 0;
        }
        return;
    case 3:
        if (old == 0) s->list->tab = 5;
        s->list->tab--;
        for (i = 0; i < 5; i++) {
            ok = fn_801B952C(t->w->parts[8]->list->tab);
            if (ok != 0) break;
            if (s->list->tab == 0) s->list->tab = 5;
            s->list->tab--;
        }
        if ((s32)old != s->list->tab) {
            s->list->page = 0;
            s->list->row = 0;
            s->x38->angle = 0;
        }
        break;
    }
}


s32 fn_801B93E8(ShopTask* t) {
    s32 r = -1;
    ShopList* s = t->w->parts[8]->list;
    u16 idx = s->row + s->page * 6;
    s16* p;
    switch (s->tab) {
    case 0:
        p = lbl_803471B8->sell[3].e[idx];
        if (p != 0) r = *p;
        break;
    case 1:
        p = lbl_803471B8->sell[0].e[idx];
        if (p != 0) r = *p;
        break;
    case 2:
        p = lbl_803471B8->sell[1].e[idx];
        if (p != 0) r = *p;
        break;
    case 3:
        p = lbl_803471B8->sell[2].e[idx];
        if (p != 0) r = *p;
        break;
    case 4:
        p = lbl_803471B8->sell[4].e[idx];
        if (p != 0) r = *p;
        break;
    }
    return r;
}
u32 fn_801B9810(Ent_801B9810* list, Ent_801B9810** out, u32 n) {
    u32 i;
    u32 k;
    Ent_801B9810** p = out;
    for (i = 0; i < n; i++) {
        *p++ = NULL;
    }
    i = 0;
    k = 0;
    for (; i < n; list++, i++) {
        if (list->id != -1 && list->count - fn_801B995C(list->id) > 0) {
            if (ItemTotal((u16)list->id) != 0) {
                *out++ = list;
                k++;
            }
        }
    }
    return k;
}

#ifdef NONMATCHING
/* Exact, but its s16 parameter changes fn_801B8F48: that caller then needs an s32 parameter and a narrowing copy, which is not real source. */
u16 fn_801B995C(s16 key) {
    u32 n;
    u32 i;
    switch (fn_801F4C24(key)) {
    case 0:
        n = 0;
        for (i = 0; i < lbl_803471B8->w->count; i++) {
            if (lbl_803471B8->w->m[i].ha == key) n++;
        }
        break;
    case 1:
        n = 0;
        for (i = 0; i < lbl_803471B8->w->count; i++) {
            if (lbl_803471B8->w->m[i].hc == key) n++;
        }
        break;
    case 2:
        n = 0;
        for (i = 0; i < lbl_803471B8->w->count; i++) {
            if (lbl_803471B8->w->m[i].he == key) n++;
        }
        break;
    case 5:
        n = 0;
        for (i = 0; i < 4; i++) {
            if (lbl_803471B8->w->d8[i].v == key) n++;
        }
        break;
    case 6:
        n = 0;
        for (i = 0; i < 3; i++) {
            if (lbl_803471B8->w->h10a[i] == key) n++;
        }
        break;
    default:
        n = 0;
        break;
    }
    return n;
}
#endif

void fn_801BC490(ShopTask* t)
{
    char buf[0x20];
    s32 cnt;
    s32 i;
    u32 bit;
    u32 held;

    if (lbl_803475D8 != 0) {
        t->w->state = 10;
    }
    cnt = 0;
    for (i = 0; i < 8; i++) {
        if (lbl_80310A1C[0x64 + i] != 0) {
            cnt++;
        }
    }
    switch (t->w->state) {
    case 0:
        t->w->b36 = 0;
        t->w->state = 1;
        lbl_803471A6 = 0x280;
        lbl_803471A4 = -0x280;
        SePlay(2, 1, 4);
        break;
    case 1:
        fn_801BCAF4(lbl_803471A6, lbl_803471A4, 1.0f, t->w->qty, 0);
        lbl_803471A6 -= 0x60;
        lbl_803471A4 += 0x60;
        if (lbl_803471A6 <= 0) {
            lbl_803471A6 = 0;
        }
        if (lbl_803471A4 >= 0) {
            lbl_803471A4 = 0;
        }
        if (lbl_803471A6 == 0 && lbl_803471A4 == 0) {
            t->w->state = 2;
        }
        break;
    case 2:
        fn_801BCAF4(0, 0, 1.0f, t->w->qty, cnt);
        bit = t->w->qty + 0xac8;
        lbl_80310B3C[bit >> 5] |= 1 << (bit & 31);
        held = lbl_80311A60[0]->held;
        if ((held & 0x40) && cnt > 1) {
            t->w->state = 3;
            lbl_803471A6 = 0;
            SePlay(2, 1, 4);
        } else if ((held & 0x20) && cnt > 1) {
            t->w->state = 4;
            lbl_803471A6 = 0;
            SePlay(2, 1, 4);
        } else if (held & 0x200) {
            t->w->state = 9;
            SePlay(2, 1, 4);
        }
        break;
    case 9:
        fn_801BCAF4(lbl_803471A6, lbl_803471A4, 1.0f, t->w->qty, 0);
        lbl_803471A6 += 0x60;
        lbl_803471A4 -= 0x60;
        if (lbl_803471A6 >= 0x280) {
            lbl_803471A6 = 0x280;
        }
        if (lbl_803471A4 <= -0x280) {
            lbl_803471A4 = -0x280;
        }
        if (lbl_803471A6 == 0x280 && lbl_803471A4 == -0x280) {
            t->w->state = 10;
        }
        break;
    case 10:
        t->state = 10;
        t->w->state = 0;
        UiObjMoveToX(&t->w->parts[0]->obj->o, 6, 4, -8.0f);
        UiObjSetCommand(&t->w->parts[0]->obj->o, 0xf, 0);
        UiObjMoveToY(&t->w->parts[5]->obj->o, 6, -1, 100.0f);
        UiObjSetCommand(&t->w->parts[5]->obj->o, 0xf, 1);
        fn_802275A4(lbl_803471A0->p4->x20, 1);
        fn_801E17E0(lbl_803471A0);
        lbl_803471A0 = 0;
        fn_801BD5A4();
        break;
    case 3:
        lbl_803471A6 += 0x60;
        lbl_803471A4 -= 0x60;
        fn_801BCAF4(lbl_803471A6, lbl_803471A4, 1.0f, t->w->qty, 0);
        if (lbl_803471A4 <= -0x280) {
            lbl_803471A4 = -0x280;
        }
        if (lbl_803471A6 >= 0x2e0) {
            lbl_803471A6 = 0x280;
            do {
                t->w->qty--;
                if (t->w->qty < 0) {
                    t->w->qty = 7;
                }
            } while (lbl_80310A1C[0x64 + t->w->qty] == 0);
            t->w->state = 5;
        }
        break;
    case 4:
        lbl_803471A6 += 0x60;
        lbl_803471A4 -= 0x60;
        fn_801BCAF4(lbl_803471A6, lbl_803471A4, 1.0f, t->w->qty, 0);
        if (lbl_803471A4 <= -0x280) {
            lbl_803471A4 = -0x280;
        }
        if (lbl_803471A6 >= 0x2e0) {
            lbl_803471A6 = 0x280;
            do {
                t->w->qty++;
                if (t->w->qty > 7) {
                    t->w->qty = 0;
                }
            } while (lbl_80310A1C[0x64 + t->w->qty] == 0);
            t->w->state = 5;
        }
        break;
    case 5:
        fn_802275A4(lbl_803471A0->p4->x20, 1);
        fn_801E17E0(lbl_803471A0);
        lbl_803471A0 = 0;
        sprintf(buf, "/field/wanted%02d", t->w->qty + 1);
        if (lbl_80310A1C[0x64 + t->w->qty] < 3) {
            strcat(buf, "a.mld");
        } else {
            strcat(buf, "b.mld");
        }
        lbl_803471A0 = fn_801DB244(buf);
        fn_80227810(lbl_803471A0->p4->x20);
        lbl_803471A6 = 0x280;
        t->w->state = 6;
        SePlay(2, 1, 4);
    case 6:
        fn_801BCAF4(lbl_803471A6, lbl_803471A4, 1.0f, t->w->qty, 0);
        lbl_803471A6 -= 0x60;
        lbl_803471A4 += 0x60;
        if (lbl_803471A4 >= 0) {
            lbl_803471A4 = 0;
        }
        if (lbl_803471A6 <= 0) {
            lbl_803471A6 = 0;
            t->w->state = 2;
        }
        break;
    }
}

void fn_801BCFAC(u8* obj, s32 idx) {
    s32 j = *(s32*)(*(u8**)(obj + 4) + idx * 0x34);
    *(f32*)(*(u8**)obj + j * 0x14 + 0xC) = 0.59f;
}
void fn_801BD5A4(void)
{
    if (lbl_803471A8 != 0) {
        fn_801D6944(lbl_803471A8);
        fn_801E17E0(lbl_803471A8);
        lbl_803471A8 = 0;
    }
    if (lbl_803471AC != 0) {
        fn_801D6944(lbl_803471AC);
        fn_801E17E0(lbl_803471AC);
        lbl_803471AC = 0;
    }
    if (lbl_803471B4 != 0) {
        fn_802275A4(((Obj4*)lbl_803471B4)->x4->x20, 0);
        fn_801E17E0(lbl_803471B4);
        lbl_803471B4 = 0;
    }
    if (lbl_803471B0 != 0) {
        fn_801E17E0(lbl_803471B0);
        lbl_803471B0 = 0;
    }
}

void fn_801BD644(void) {
    s32 b;
    void* buf;
    s32 a;
    void* src;
    void* s0;
    lbl_803471B0 = fn_801E49D8(lbl_802C39A0);
    a = fn_801E4974(lbl_803471B0, 2);
    b = fn_801E48A8(lbl_803471B0);
    buf = fn_801E1C7C(a);
    src = fn_801E4984(lbl_803471B0, 2);
    MemCopy(buf, src, a);
    lbl_803471B0 = fn_801E1584(lbl_803471B0, b - a);
    lbl_803471B4 = fn_801DB124(buf);
    fn_80227810(*(void**)((u8*)((void**)lbl_803471B4)[1] + 0x20));
    lbl_803471AC = fn_801E1C7C(0x14);
    s0 = fn_801E4984(lbl_803471B0, 0);
    fn_801D6998(lbl_803471AC, s0);
    lbl_803471A8 = fn_801E1C7C(0x14);
    fn_801D6998(lbl_803471A8, fn_801E4984(lbl_803471B0, 1));
}

inline s8 GuildRank(s16 x, u8 lvl) {
    int r;
    if (x == -1) {
        return -1;
    }
    if (lvl >= 0x18) {
        return -1;
    }
    r = 0;
    if (lvl >= lbl_802ED258[x].lo) {
        r = 2;
    } else if (lvl >= lbl_802ED258[x].hi) {
        r = 1;
    }
    return r;
}

inline s8 fn_801BE608(s16 x) {
    return GuildRank(x, lbl_803473BE);
}

s32 fn_801BD748(ShopTask_801BD748* t, ShopEntry_801BD748* tmp, s32 start) {
    int i;
    int j;
    int n;
    for (i = 0; i < 0x58; i++) {
        tmp[i].id = -1;
        tmp[i].flag = -1;
        tmp[i].type = 0;
        tmp[i].val = 0;
    }
    n = i = 0;
    for (; i < 0x58; i++) {
        if ((Test_801BD748(i + 0xc62) & 1) == 0 && Test_801BD748(i + 0xb54) == 1) {
            tmp[n].id = i;
            tmp[n].flag = fn_801BE608(i);
            tmp[n].val = lbl_802ED258[i].f24;
            n++;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (tmp[j].val < tmp[i].val) {
                s16 id = tmp[j].id;
                int f = tmp[j].flag;
                s16 v = tmp[j].val;
                tmp[j].val = tmp[i].val;
                tmp[j].flag = tmp[i].flag;
                tmp[j].id = tmp[i].id;
                tmp[i].val = v;
                tmp[i].flag = f;
                tmp[i].id = id;
            }
        }
    }
    for (i = 0; i < n; i++, start++) {
        t->buf->out[start].id = tmp[i].id;
        t->buf->out[start].flag = tmp[i].flag;
        t->buf->out[start].val = tmp[i].val;
    }
    return start;
}

s32 fn_801BDEF4(u16 id, u16 mode)
{
    s32 f;
    s32 rk;
    if (mode == 0) {
        f = FlagTest(id + 0xBAE);
        if (f != 0) {
            return lbl_802ED258[id].f10;
        }
        f = FlagTest(id + 0xC62);
        if (f != 0) {
            return lbl_802ED258[id].f10;
        }
        rk = Rank(id);
        switch ((s8)rk) {
        case 0:
        case 1:
            return lbl_802ED258[id].f14;
        case 2:
            return lbl_802ED258[id].f10;
        }
    } else {
        f = FlagTest(id + 0xBAE);
        if (f != 0) {
            return lbl_802ED258[id].f18;
        }
        rk = Rank(id);
        switch ((s8)rk) {
        case 0:
            return lbl_802ED258[id].f20;
        case 1:
            return lbl_802ED258[id].f1c;
        case 2:
            return lbl_802ED258[id].f1c;
        }
    }
    return 0;
}

void* fn_801BE17C(u16 id) {
    s32 f1 = FlagTest(id + 0xBAE);
    s32 f2;
    if (f1) {
        return lbl_802ED258[id].b;
    }
    f2 = FlagTest(id + 0xC62);
    if (f2) {
        return lbl_802ED258[id].b;
    }
    switch ((s8)Rank(id)) {
    case 0:
        return lbl_802ED258[id].a;
    case 1:
        return lbl_802ED258[id].c;
    case 2:
        return lbl_802ED258[id].c;
    }
    return NULL;
}

void fn_801BE2F0(ShopEntry* e, u8 mode) {
    u32 thr;
    s8 c;
    c = e->flag = Rank(e->id);
    if (mode == 0) {
        switch (c) {
        case 0:
            e->type = 1;
        default:
            return;
        case 1:
            thr = lbl_802ED258[e->id].f14;
            break;
        case 2:
            thr = lbl_802ED258[e->id].f10;
            break;
        }
        if (FlagTest(e->id + 0xC08) != 0 || FlagTest(e->id + 0xC62) != 0) {
            e->type = 1;
            return;
        }
        if (lbl_8030B7F4.w34c >= thr) {
            e->type = 0;
        } else {
            e->type = 1;
        }
    } else {
        e->type = 0;
    }
}
void fn_801BE468(void) {
    s32 i;
    s32 t;
    u16 lim;
    Pass1();
    if (lbl_80310B3C[0x80 / 4] & 0x400000) {
        return;
    }
    for (i = 0; i < 0x58; i++) {
        lim = lbl_802ED258[i].xc;
        t = FlagTest(i + 0xC62);
        if (!t) {
            if (lbl_803473BE >= lim) {
                FlagSet(i + 0xBAE);
            } else {
                FlagClear(i + 0xBAE);
            }
        }
    }
}

void fn_801BEA70(void *a, u32 idx, s32 mode) {
    lbl_803473BE = ((u8)mode <= 23) ? mode : 0;
    if (idx > lbl_8034BAC0[0] - 1) {
        fn_801BEB10(a, 1, 0, 0);
    } else {
        fn_801BEB10(a, 1, idx, 0);
    }
}

void fn_801BEAE4(void* a, s32 b) {
    fn_801BEB10(a, 0, b, 0);
}
