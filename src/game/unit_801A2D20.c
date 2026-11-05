#include "game/shop.h"



void fn_801A2D20(SaveTask *t, u32 a, u32 b) {
    f32 done = a;
    f32 total = b;
    t->w->f1c = done / total;
}

/* Scans a memory card's save files (the task fn_801A343C starts), filling the save menu's
 * slot summaries. */
void fn_801A2D60(Task_801A343C* t) {
    s32 code;
    s32 flag;
    s32 files;
    s32 bytes;
    char num[8];
    CARDFileInfo info;
    CardSaveData* save;
    SaveTask* par;
    s32* st;
    s32 chan;
    s32 n;

    chan = t->p24->w10;
    par = t->parent;
    st = &par->w->st[chan];
    if (t->state > 0xfe && lbl_80347184[chan] == 0) {
        *st = 1;
        t->state = 4;
    }
    switch (t->state) {
    case 0:
    case 0xfe:
        lbl_803475D0 = 1;
        t->p24->b14 = 0;
        if (fn_801A2500(t->p24->w10, &code) == 0) {
            *st = fn_801A6A04(code);
            t->p24->w08 = 0;
            t->state = 4;
            break;
        }
        t->p24->w0c = 0;
        par->w->w14 = 0;
        {
            s32 c = t->p24->w10;
            s32 r;
            do {
                r = CARDFreeBlocks(c, &bytes, &files);
            } while (r == -1);
            if (r == 0) {
                if (files <= 0) {
                    n = 0;
                } else {
                    n = bytes / 0x6000;
                    if (n > 7) {
                        n = 7;
                    }
                }
            } else {
                n = 0;
            }
        }
        t->p24->w08 = n;
        *st = 0;
        t->state = 1;
        break;
    case 1:
        sprintf(num, lbl_8034B6A0, t->p24->b14);
        strcpy(lbl_80308178, lbl_802B4978);
        strcat(lbl_80308178, num);
        code = fn_801A388C(t->p24->w10, lbl_80308178, &flag);
        if (code == 0) {
            if (flag != 0) {
                par->w->ent[t->p24->b14].f0 = 2;
                t->p24->w0c++;
                goto next;
            }
            t->p24->w0c++;
            t->state = 2;
            break;
        }
        if (code == -4) {
            if (t->p24->w08 > 0) {
                par->w->ent[t->p24->b14].f0 = 0;
                t->p24->w0c++;
                t->p24->w08--;
            } else {
                par->w->ent[t->p24->b14].f0 = 3;
            }
        next:
            t->p24->b14++;
            t->p24->h16++;
            if (t->p24->b14 >= t->p24->b15) {
                t->p24->b1a = 0;
                t->p24->b1b = 0;
                t->state = 4;
            }
            break;
        }
        *st = fn_801A6A04(code);
        t->state = 4;
        break;
    case 2:
        t->p24->w04 = 3;
        par->w->ent[t->p24->b14].f0 = 1;
        t->buf = fn_801E1C7C(0x6000);
        do {
            code = CARDOpen(t->p24->w10, lbl_80308178, &info);
        } while (code == -1);
        if (code == 0) {
            do {
                code = CARDRead(&info, t->buf, t->p24->w04 << 13, 0);
            } while (code == -1);
            CARDClose(&info);
        }
        if (code != 0) {
            t->p24->w0c = 0;
            par->w->w14 = 0;
            t->state = 4;
            *st = 1;
            break;
        }
        t->state = 3;
        break;
    case 3:
        save = &t->buf->save;
        if (save->sum != CardSum(save)) {
            par->w->ent[t->p24->b14].f0 = 2;
        } else if (strcmp(save->magic, lbl_802EBDD0) != 0) {
            par->w->ent[t->p24->b14].f0 = 4;
        } else {
            par->w->ent[t->p24->b14].f0 = 1;
            par->w->ent[t->p24->b14].h4 = save->x31ea;
            par->w->ent[t->p24->b14].h6 = save->x31e8;
            par->w->ent[t->p24->b14].w8 = save->x31ec;
            par->w->ent[t->p24->b14].hc = save->data.chr[0].xb;
            par->w->ent[t->p24->b14].fe[0] = save->data.party[0];
            par->w->ent[t->p24->b14].fe[1] = save->data.party[1];
            par->w->ent[t->p24->b14].fe[2] = save->data.party[2];
            par->w->ent[t->p24->b14].fe[3] = save->data.party[3];
            memcpy(&par->w->ent[t->p24->b14].stamp, save->stamp, 8);
        }
        fn_801E17E0(t->buf);
        t->buf = NULL;
        t->state = 1;
        goto next;
    case 4:
        CardRelease(t->p24->w10);
        par->w->w14 = t->p24->w0c;
        par->w->w250 = 1;
        lbl_803475D0 = 0;
    case 0xff:
        if (t->buf != NULL) {
            fn_801E17E0(t->buf);
            t->buf = NULL;
        }
        t->flags |= 0x40;
        return;
    }
    par->w->f1c = (f32)t->p24->h16 / (f32)t->p24->h18;
}

void* fn_801A343C(Task_801A343C* a)
{
    Task_801A343C* o = fn_802267AC(a, fn_801A2D60);
    o->p24 = fn_801E1C7C(0x24);
    o->buf = NULL;
    o->p24->w10 = A24(a)->b04;
    o->p24->b15 = 7;
    A24(a)->h12 = 7;
    o->p24->w0c = 0;
    A24(a)->w14 = 0;
    A24(a)->w250 = 0;
    o->p24->h16 = 0;
    if (A24(a)->b01 == 0) {
        o->p24->h18 = o->p24->b15 + 1;
    } else {
        o->p24->h18 = o->p24->b15 + 3;
    }
    return o;
}
s32 fn_801A3510(void) {
    s32 i;
    s32 result;
    s32 more;
    more = 1;
    i = 0;
    result = 0;
    while (more != 0) {
        s32 r = CARDProbeEx(i, 0, 0);
        if (r == -1) {
            lbl_8034717C[i] |= 0x20;
        } else if (r == 0) {
            u8 b = lbl_8034717C[i];
            if (b & 1) {
                lbl_8034717C[i] &= ~0x20;
                if (lbl_8034717C[i] & 2) result = 1;
            } else if (b & 8) {
                if (fn_801A37D8(i) != 0) lbl_8034717C[i] |= 2;
                fn_801DC214();
                CARDUnmount(i);
                if (lbl_8034718C[i] != 0) {
                    fn_801E17E0(lbl_8034718C[i]);
                    lbl_8034718C[i] = 0;
                }
                lbl_8034717C[i] |= 1;
                lbl_8034717C[i] &= ~0x20;
            } else if (b & 4) {
                s32 c = CARDGetResultCode(i);
                if (c == 0) {
                    lbl_8034717C[i] &= ~4;
                    lbl_8034717C[i] |= 8;
                } else if (c != -1) {
                    lbl_8034717C[i] |= 0x10;
                    lbl_8034717C[i] |= 1;
                    lbl_8034717C[i] &= ~0x20;
                }
            } else if ((b & 0x10) == 0) {
                void (*cb)(void);
                if (i == 0) cb = fn_801A2CC4; else cb = fn_801A2C58;
                if (lbl_8034718C[i] == 0) lbl_8034718C[i] = fn_801E1C7C(0xA000);
                CARDMountAsync(i, lbl_8034718C[i], cb, 0);
                lbl_8034717C[i] |= 0x24;
            }
        } else {
            lbl_8034717C[i] = 0;
        }
        if (i == 0) {
            if (lbl_8034717C[i] & 0x20) {
                more = 0;
                if ((lbl_8034717C[1] & 1) && (lbl_8034717C[1] & 2)) result = 1;
            }
        } else {
            more = 0;
        }
        i++;
    }
    return result;
}

void fn_801A372C(void) {
    Unmount(0);
    Unmount(1);
}

void fn_801A37C4(void) {
    u8* p = lbl_8034717C;
    p[1] = 0;
    lbl_8034717C[0] = 0;
}

s32 fn_801A37D8(s32 chan) {
    char buf[8];
    char name[0x20];
    s32 i;
    s32 found;
    s32 done;
    s32 r;

    i = 0;
    found = 0;
    done = 0;
    for (; i < 7 && done == 0; i++) {
        SlotName(buf, i);
        strcpy(name, lbl_802B4978);
        strcat(name, buf);
        r = fn_801A388C(chan, name, 0);
        if (r == 0) {
            done = 1;
            found = 1;
        } else if (r != -4) {
            done = 1;
        }
    }
    return found;
}

s32 fn_801A388C(s32 chan, const char *name, s32* out) {
    s32 i;
    s32 ret;
    s32 cont;
    i = 0;
    cont = 1;
    ret = -4;
    for (; i < 0x7f && cont; i++) {
        s32 r;
        do {
            fn_801DC214();
            r = CARDGetStatus(chan, i, &lbl_803080F8);
        } while (r == -1);
        switch (r) {
        case -4:
        case -10:
            break;
        case 0:
            if (lbl_803080F8.gameName != 0x47454145) break;
            if (lbl_803080F8.company != 0x3850) break;
            if (strstr(lbl_803080F8.fileName, name) == NULL) break;
            if (out != NULL) {
                *out = (lbl_803080F8.iconAddr == -1 || lbl_803080F8.commentAddr == -1) != 0;
            }
            ret = 0;
            cont = 0;
            break;
        default:
            ret = r;
            cont = 0;
            break;
        }
    }
    return ret;
}

void fn_801A39B4(u16 id, void *obj) {
    char buf[0x8];

    sprintf(buf, ".%03d", id);
    strcpy(obj, "SA_LEGENDS");
    strcat(obj, buf);
}

void fn_801A4060(SaveTask* t) {
    t->w->w268 = 0;
}

void fn_801A41C0(CardRec* rec) {
    CardImage* p = rec->buf;
    if (p != 0) {
        fn_801E17E0(p);
    }
}

CardRec *fn_801A41EC(CardSaveData *p, s32 chan, const char *name) {
    CardRec *rec = &lbl_803081A4;
    u32 sum;
    s32 i;

    rec->stamp.year = lbl_80308198.stamp.year;
    rec->stamp.month = lbl_80308198.stamp.month;
    rec->stamp.day = lbl_80308198.stamp.day;
    rec->stamp.hour = lbl_80308198.stamp.hour;
    rec->stamp.min = lbl_80308198.stamp.min;
    rec->stamp.sec = lbl_80308198.stamp.sec;
    rec->stamp.wday = lbl_80308198.stamp.wday;
    strcpy(rec->name, name);
    lbl_803081A4.chan = chan;
    lbl_803081A4.w1c = 0;
    memcpy(p->stamp, &lbl_80308198, 10);
    if (p == NULL) {
        sum = 0;
    } else {
        u32 *q = (u32 *)p;
        sum = 0;
        for (i = 3199; i != 0; i--) {
            sum ^= *q++;
        }
    }
    p->sum = sum;
    rec->w14 = 3;
    rec->buf = fn_801E1C7C(0x6000);
    if (rec->buf == NULL) {
        return NULL;
    }
    memset(rec->buf, 0, 0x6000);
    memcpy(&rec->buf->save, p, 0x3200);
    return rec;
}

void* fn_801A456C(void) {
    CardSaveData* s = fn_801E1A74(1, 0x3200);
    MemCopy(s, lbl_802EBDD0, 0x10);
    s->x31ea = lbl_80310A1C[0x32];
    MemCopy(&s->data, &lbl_8030B7F4, 0x16a0);
    s->x16b0 = lbl_80311AC0.x4;
    s->x16b4 = lbl_80311AC0.x8;
    s->pos[0].f[0] = lbl_8030A794.pos[0].f[0];
    s->pos[0].f[1] = lbl_8030A794.pos[0].f[1];
    s->pos[0].f[2] = lbl_8030A794.pos[0].f[2];
    s->pos[0].w[0] = lbl_8030A794.pos[0].w[0];
    s->pos[0].w[1] = lbl_8030A794.pos[0].w[1];
    s->pos[0].w[2] = lbl_8030A794.pos[0].w[2];
    s->pos[1].f[0] = lbl_8030A794.pos[1].f[0];
    s->pos[1].f[1] = lbl_8030A794.pos[1].f[1];
    s->pos[1].f[2] = lbl_8030A794.pos[1].f[2];
    s->pos[1].w[0] = lbl_8030A794.pos[1].w[0];
    s->pos[1].w[1] = lbl_8030A794.pos[1].w[1];
    s->pos[1].w[2] = lbl_8030A794.pos[1].w[2];
    MemCopy(s->blk2370, lbl_80310B3C, 0xd58);
    MemCopy(s->blk30c8, lbl_80310A1C, 0x120);
    return s;
}

u32 fn_801A4684(void *buf, u32 size)
{
    u32 *p = buf;
    u32 sum;
    u32 i;

    if (p == NULL) {
        return 0;
    }
    size >>= 2;
    sum = 0;
    for (i = 0; i < size; i++) {
        sum ^= *p++;
    }
    return sum;
}

void fn_801A471C(s32 idx) {
    CardXfer* p = &lbl_803081CC[idx];
    p->done = 0;
    p->total = 0;
}

void fn_801A473C(void)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        if (lbl_8034718C[i]) {
            fn_801E17E0(lbl_8034718C[i]);
            lbl_8034718C[i] = 0;
        }
    }
    if (lbl_8034716C) {
        TPLReleasePalette(&lbl_8034716C);
        lbl_8034716C = 0;
    }
    if (lbl_80347168) {
        TPLReleasePalette(&lbl_80347168);
        lbl_80347168 = 0;
    }
}
void fn_801A49B8(void *p) {
    fn_80005AD8(lbl_80346720, p);
}

void fn_801A49E0(Hdr_801A49E0* h) {
    u16 i;
    if (h->magic != 0x20AF30) {
        OSPanic(lbl_802B49C4, 0x161, lbl_802B49D0);
    }
    h->table = (Pair_801A49E0*)((u32)h->table + (u32)h);
    for (i = 0; i < h->count; i++) {
        if (h->table[i].a != 0) {
            h->table[i].a = (Ent*)((u32)h + (u32)h->table[i].a);
            if (h->table[i].a->flag23 == 0) {
                h->table[i].a->x8 = (u32)h + h->table[i].a->x8;
                h->table[i].a->flag23 = 1;
            }
        }
        if (h->table[i].b != 0) {
            h->table[i].b = (Ent*)((u32)h + (u32)h->table[i].b);
            if (h->table[i].b->flag2 == 0) {
                h->table[i].b->x8 = (u32)h + h->table[i].b->x8;
                h->table[i].b->flag2 = 1;
            }
        }
    }
}

void *fn_801A4AF4(void *obj) {
    u8 *r31 = fn_80226670(obj, fn_801A4B40);
    *(void **)(r31 + 0x24) = fn_801E1A74(1, 6);
    return r31;
}
