/* Near miss (not matched): fn_80293F20, ninja.c, between fn_80293EA8 and fn_80294100. 46 diff lines (1.3.2nj),
 * same instruction count (120). Cyclic Catmull-Rom over NJS_MKEY_F rows (interpPos[1] in lbl_803469F8).
 * The f32 span[2] = {1.0f, 1.0f} local is lbl_8034D220/224 (aggregate initializer); span[(s32)d > 0] gives the
 * neg/andc/rlwinm + lfsx select. Left: scheduling of the frame0 conversion vs the k1 index, the 0x43300000 double
 * constant register (f1 vs f4), GPRs r5-r10 of the index math. */
void fn_80293F20(void* table, s32 count, f32* out, f32 t) {
    f32 span[2] = {1.0f, 1.0f};
    NJS_MKEY_F* k;
    NJS_MKEY_F* k0;
    NJS_MKEY_F* k1;
    NJS_MKEY_F* k2;
    u32 i;
    u32 d;
    f32 u, u2, u3;
    f32 b0, b1, b2, b3;

    i = fn_80293AF4(table, 16, count, t);
    k = (NJS_MKEY_F*)table + i;
    k1 = (NJS_MKEY_F*)table + (i + 1) % count;
    d = k1->keyframe - k->keyframe;
    k0 = (NJS_MKEY_F*)table + (i + count - 1) % count;
    k2 = (NJS_MKEY_F*)table + (i + 2) % count;
    span[1] = d;
    u = (t - k->keyframe) / span[(s32)d > 0];
    u2 = u * u;
    u3 = u2 * u;
    b0 = 0.5f * (-u3 + 2.0f * u2 - u);
    b1 = 1.5f * u3 - 2.5f * u2 + 1.0f;
    b2 = -1.5f * u3 + 2.0f * u2 + 0.5f * u;
    b3 = 0.5f * (u3 - u2);
    out[0] = b0 * k0->key[0] + b1 * k->key[0] + b2 * k1->key[0] + b3 * k2->key[0];
    out[1] = b0 * k0->key[1] + b1 * k->key[1] + b2 * k1->key[1] + b3 * k2->key[1];
    out[2] = b0 * k0->key[2] + b1 * k->key[2] + b2 * k1->key[2] + b3 * k2->key[2];
}
