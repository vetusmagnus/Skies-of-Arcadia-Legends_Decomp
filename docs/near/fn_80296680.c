/* Near miss (not matched): fn_80296680, ninja.c, goes right after fn_80296424. 10 diff lines (1.3.2nj), was 46.
 * Key: cnt /= sz; as a statement before the call (46 -> 18); declaration order a, cnt, fl, b, sz (18 -> 10, hill-climb).
 * Left: the first block's loads (the original loads lbl_80347E84 before lbl_80347E80, and c is r8). */
void fn_80296680(u32* p, u32 n) {
    NjCacheCtx* c;
    NjCacheEnt* e;
    u16* a;
    s32 cnt;
    s32 fl;
    u16* b;
    s32 sz;
    u16 key;

    c = lbl_80347E88;
    e = &lbl_80347E84[c->idx];
    key = c->rec->key;
    a = (*lbl_80347E80)[e->a].keys[key];
    b = (*lbl_80347E80)[e->b].keys[key];
    switch ((u8)n) {
    case 0x22: fl = 1; break;
    case 0x23: fl = 5; break;
    case 0x24: fl = 9; break;
    case 0x29: fl = 3; break;
    case 0x2A: fl = 7; break;
    case 0x2B: fl = 0xB; break;
    case 0x2C: fl = 0xB; break;
    default: return;
    }
    cnt = *a++;
    switch ((u8)*a++) {
    case 0x22: fl |= 0x10; sz = 3; break;
    case 0x23: fl |= 0x50; sz = 4; break;
    case 0x29: fl |= 0x30; sz = 6; break;
    case 0x2A: fl |= 0x70; sz = 7; break;
    case 0x82: fl |= 0x40; sz = 1; break;
    case 0x80: fl |= 0x20; sz = 3; break;
    case 0x81: fl |= 0x60; sz = 4; break;
    default: return;
    }
    cnt /= sz;
    fn_80296424((f32*)p, (f32*)a, (f32*)(b + 2), cnt | fl << 16, e->frac);
}
