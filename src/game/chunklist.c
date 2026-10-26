/* Resource chunk lists (0x80035918-0x80036520): freeing, merging and loading the 16-byte chunk
 * headers (ChunkHdr) that task resources are made of, and fn_8003617C, which gives each chunk type
 * its data size. The end is a guess: the .data jump table at 0x802DD0C8 belongs to this file and
 * the next file's .data starts at the task table (0x802DD238). */
#include "types.h"
#include "game/chunklist.h"

extern void fn_801E17E0(void*);
extern void* fn_801E1C7C(u32 size);
extern void* memcpy(void* dst, const void* src, u32 n);
extern void fn_80046BB0(void* obj, s32* key);
extern ChunkHdr* fn_8006DAF8(void* obj);
extern void* fn_801CC69C(void* name);
extern void fn_801CC608(void* h, void* buf, u32 size);
extern void fn_801CC65C(void* h);

int fn_8003617C(ChunkHdr* p);
int fn_800377FC(ChunkHdr* m);

/* Free every chunk's data block (type 1 chunks don't own theirs). */
inline void FreeChunkData(ChunkHdr* list)
{
    int k;

    if (list != NULL) {
        for (k = 0;; k++) {
            s16 id = list[k].id;
            s16 type = list[k].type;
            if (id < 0) {
                break;
            }
            if (type != 1) {
                fn_801E17E0(list[k].data);
                list[k].data = NULL;
            }
        }
    }
}

/* Free a chunk list and the data it owns. */
inline void FreeChunks(ChunkHdr* list)
{
    FreeChunkData(list);
    fn_801E17E0(list);
}

void fn_80035918(ChunkHdr* p)
{
    FreeChunkData(p);
}
inline s16 CountChunks(ChunkHdr* p)
{
    int i;
    for (i = 0;; i++) {
        if (p[i].id < 0) {
            return i + 1;
        }
    }
}
ChunkHdr* fn_8003598C(ChunkHdr* a, ChunkHdr* b)
{
    ChunkHdr* buf;
    ChunkHdr* dst;
    s16 i;
    s16 j;
    s16 na;
    s16 nb;
    int ok;

    nb = CountChunks(b);
    na = CountChunks(a);
    buf = fn_801E1C7C((nb + na - 1) << 4);
    for (i = 0; i < na - 1; i++) {
        buf[i] = a[i];
    }
    fn_801E17E0(a);
    dst = &buf[i];
    for (j = 0; j < nb; j++, dst++) {
        *dst = b[j];
        ok = fn_8003617C(dst);
        if (ok == 0) {
            ok = fn_800377FC(dst);
        }
        if (ok) {
            memcpy(dst->data, (u8*)b + (u32)b[j].data, dst->size);
        }
    }
    return buf;
}
ChunkHdr* fn_80035C38(ChunkHdr* p)
{
    u8 hdr[0x10];
    ChunkHdr* cur;
    ChunkHdr* out;
    s16 i;
    ChunkHdr* dst;
    ChunkHdr* src;
    ChunkHdr* head;
    s16 n;
    int r;

    head = p;
    memcpy(hdr, p, 0x10);
    p = (ChunkHdr*)((u8*)p + 0x10);
    src = p;
    n = CountChunks(p);
    out = fn_801E1C7C((n + 1) << 4);
    dst = out;
    for (i = 0; i < n; i++) {
        dst[1] = *src;
        cur = &out[i + 1];
        r = fn_8003617C(cur);
        if (r == 0) r = fn_800377FC(cur);
        if (r != 0) memcpy(dst[1].data, (u8*)p + (s32)src->data, dst[1].size);
        src++;
        dst++;
    }
    fn_801E17E0(head);
    return out;
}
inline ChunkHdr* MergeChunks(ChunkHdr* old, ChunkHdr* chunks)
{
    s16 n;
    ChunkHdr* list;
    ChunkHdr* p;
    s16 j;
    int ok;

    n = CountChunks(chunks);
    list = fn_801E1C7C((n + 1) << 4);
    list[0] = *old;
    FreeChunks(old);
    for (j = 0; j < n; j++) {
        list[j + 1] = chunks[j];
        p = &list[j + 1];
        ok = fn_8003617C(p);
        if (ok == 0) {
            ok = fn_800377FC(p);
        }
        if (ok) {
            memcpy(list[j + 1].data, (u8*)chunks + (u32)chunks[j].data, list[j + 1].size);
        }
    }
    return list;
}
void fn_80035D4C(void* obj, ChunkHdr** pp)
{
    s32 key;
    ChunkHdr hdr;
    ChunkHdr* chunks;
    ChunkHdr* old;
    ChunkHdr* cached;
    s16 i;
    u8* raw;

    fn_80046BB0(obj, &key);
    for (i = 0; i < 12; i++) {
        if (lbl_8030A10C.cacheKey[i] == key) {
            old = *pp;
            cached = lbl_8030A10C.cache[i];
            *cached = *old;
            FreeChunks(old);
            *pp = cached;
            return;
        }
    }
    old = *pp;
    if (lbl_8030A10C.pending != NULL) {
        obj = lbl_8030A10C.pending;
        lbl_8030A10C.pending = NULL;
    } else {
        obj = fn_8006DAF8(obj);
    }
    raw = obj;
    memcpy(&hdr, obj, sizeof(hdr));
    chunks = (ChunkHdr*)((u8*)obj + sizeof(hdr));
    *pp = MergeChunks(old, chunks);
    fn_801E17E0(raw);
}
void fn_80035FC0(void* name, ChunkHdr** pp, int flag)
{
    ChunkHdr* old;
    void* h;
    ChunkHdr hdr;
    ChunkHdr* buf;

    old = *pp;
    h = fn_801CC69C(name);
    fn_801CC608(h, &hdr, sizeof(hdr));
    buf = fn_801E1C7C((u32)hdr.data);
    fn_801CC608(h, buf, (u32)hdr.data);
    fn_801CC65C(h);
    if (flag & 1) {
        *pp = MergeChunks(old, buf);
    } else {
        *pp = fn_8003598C(old, buf);
    }
    fn_801E17E0(buf);
}
int fn_8003617C(ChunkHdr* p)
{
    int size;
    switch ((p->type << 16) | p->id) {
    case 0x30000:
        size = 0x4C;
        break;
    case 0x30001:
        size = 0x44;
        break;
    case 0x30011:
        size = 0x58;
        break;
    case 0x30002:
    case 0x30046:
        size = 0x164;
        break;
    case 0x30003:
    case 0x30048:
        size = 0x194;
        break;
    case 0x30004:
        size = 0x1C;
        break;
    case 0x30005:
        size = 0x1A8;
        break;
    case 0x30006:
        size = 0x30;
        break;
    case 0x30007:
        size = 0x14;
        break;
    case 0x30008:
        size = 0x16C;
        break;
    case 0x30009:
        size = 0x50;
        break;
    case 0x3000A:
        size = 0x18;
        break;
    case 0x3000B:
        size = 0x38;
        break;
    case 0x3000C:
        size = 0x1A0;
        break;
    case 0x3000D:
        size = 0x174;
        break;
    case 0x3000E:
        size = 0x11C;
        break;
    case 0x3000F:
        size = 0x28;
        break;
    case 0x30010:
        size = 0x28;
        break;
    case 0x30012:
        size = 0x90;
        break;
    case 0x30013:
        size = 0x7C;
        break;
    case 0x30014:
        size = 0x14C;
        break;
    case 0x30015:
        size = 0x174;
        break;
    case 0x30016:
        size = 0x2C;
        break;
    case 0x30017:
        size = 0x84;
        break;
    case 0x30018:
        size = 0x2C;
        break;
    case 0x30019:
        size = 0x58;
        break;
    case 0x3001A:
        size = 0x15C;
        break;
    case 0x3001B:
        size = 0x128;
        break;
    case 0x3001C:
        size = 0x174;
        break;
    case 0x3001D:
        size = 0x70;
        break;
    case 0x3001E:
        size = 0x70;
        break;
    case 0x3001F:
        size = 0x1C;
        break;
    case 0x30020:
        size = 0x20;
        break;
    case 0x30021:
        size = 0x34;
        break;
    case 0x30022:
        size = 0x1C;
        break;
    case 0x30023:
        size = 0x1C;
        break;
    case 0x30024:
        size = 0x20;
        break;
    case 0x30025:
        size = 0x58;
        break;
    case 0x30026:
        size = 0x34;
        break;
    case 0x30027:
        size = 0x3C;
        break;
    case 0x30028:
        size = 0x54;
        break;
    case 0x30029:
        size = 0x28;
        break;
    case 0x3002A:
        size = 0x24;
        break;
    case 0x3002B:
        size = 0x2C;
        break;
    case 0x3002C:
        size = 0x44;
        break;
    case 0x3002D:
        size = 0x2C;
        break;
    case 0x3002E:
        size = 0x20;
        break;
    case 0x3002F:
        size = 0x178;
        break;
    case 0x30030:
        size = 0x30;
        break;
    case 0x30031:
        size = 0x34;
        break;
    case 0x30032:
        size = 0x14;
        break;
    case 0x30033:
        size = 0x15C;
        break;
    case 0x30034:
        size = 0x38;
        break;
    case 0x30035:
        size = 0x18;
        break;
    case 0x30036:
        size = 0x2C;
        break;
    case 0x30037:
        size = 0x28;
        break;
    case 0x30038:
        size = 0x30;
        break;
    case 0x30039:
        size = 0x12C;
        break;
    case 0x3003A:
    case 0x3004F:
        size = 0x28;
        break;
    case 0x3003B:
        size = 0x24;
        break;
    case 0x3003C:
        size = 0x54;
        break;
    case 0x3003D:
        size = 0x18;
        break;
    case 0x3003E:
        size = 0x30;
        break;
    case 0x3003F:
        size = 0x2C;
        break;
    case 0x30040:
        size = 0x18;
        break;
    case 0x30041:
        size = 0x18;
        break;
    case 0x30042:
        size = 0x3C;
        break;
    case 0x30043:
        size = 0x58;
        break;
    case 0x30044:
        size = 0x20;
        break;
    case 0x30045:
        size = 0x3C;
        break;
    case 0x30047:
        size = 0x20;
        break;
    case 0x30049:
        size = 0x1C;
        break;
    case 0x3004A:
        size = 0x188;
        break;
    case 0x3004B:
        size = 0x68;
        break;
    case 0x3004C:
        size = 0x1C;
        break;
    case 0x3004D:
        size = 0x38;
        break;
    case 0x3004E:
        size = 0x14;
        break;
    case 0x30050:
        size = 0x50;
        break;
    case 0x30051:
        size = 0x9C;
        break;
    case 0x30052:
        size = 0x1C;
        break;
    case 0x30053:
        size = 0x90;
        break;
    case 0x30054:
        size = 0xA8;
        break;
    case 0x30055:
        size = 0x3C;
        break;
    case 0x30056:
        size = 0x44;
        break;
    case 0x30057:
        size = 0x2C;
        break;
    case 0x30058:
        size = 0x7C;
        break;
    case 0x30059:
    case 0x3005A:
        size = 0x18;
        break;
    default:
        return 0;
    }
    fn_80061F58(&p->data, size, 0);
    p->size = size;
    return 1;
}
void fn_800364B8(void* p)
{
    if (fn_8003617C(p) == 0) fn_800377FC(p);
}
s16 fn_800364F4(ChunkHdr* e)
{
    return CountChunks(e);
}
