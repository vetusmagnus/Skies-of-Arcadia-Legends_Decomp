#include "types.h"

/* Table-of-entries accessors and the story-flag bitset (fn_801E48A8 .. fn_801E4BF4). */

/* A packed table: an 8-byte header with the entry count, then 0x20-byte entries, each giving
 * the offset (from the table start) and size of its data. */
typedef struct {
    s32 unk0[5];
    s32 offset; /* 0x14 data offset from the table start */
    s32 size;   /* 0x18 data size */
    s32 unk1C;
} TableEntry;

typedef struct {
    s32 unk0;
    s16 count; /* 0x04 */
    s16 unk6;
    TableEntry entries[1]; /* 0x08, count entries */
} Table;

extern u32 lbl_80310B3C[]; /* story-flag bitset */

extern void fn_801CC1A4(void);
extern void fn_801CC1B4(void);
extern void fn_801CC3C4(void);
extern s32 fn_8021A0BC(s32 n);
extern void fn_8021B2B4(void);

/* Total size of the table: header, entries and all entry data. Near miss: the compiler's
 * unrolled loop differs from the original. */
s32 fn_801E48A8(Table* t) {
    s32 sum = 0;
    s32 i = 0;
    s32 n = t->count;
    for (; i < n; i++) {
        sum += t->entries[i].size;
    }
    return n * 32 + sum + 8;
}

s32 fn_801E4974(Table* t, s32 i) {
    return t->entries[i].size;
}

u8* fn_801E4984(Table* t, s32 i) {
    s32 off = t->entries[i].offset;
    return (u8*)(off + (s32)t);
}

void fn_801E4998(void) {
    fn_801CC1A4();
}

void fn_801E49B8(void) {
    fn_801CC1B4();
}

void fn_801E49D8(void) {
    fn_801CC3C4();
}

/* Clears story flag 0x425 + n. */
void fn_801E49F8(s32 n) {
    if (fn_8021A0BC(n)) {
        u32 b = n + 0x425;
        lbl_80310B3C[b >> 5] &= ~(1 << (b & 31));
    }
}

/* Sets story flag 0x425 + n. */
void fn_801E4A54(s32 n) {
    if (fn_8021A0BC(n)) {
        u32 b = n + 0x425;
        lbl_80310B3C[b >> 5] |= 1 << (b & 31);
    }
}

static inline s32 FlagTest425(s8 n) {
    u32 b = n + 0x425;
    return (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
}

/* Sets story flag 0x40F + n, and flag 0x425 + n unless flag 0x425 + (n ^ 1) is set.
 * Near miss. */
void fn_801E4AB0(s32 n) {
    if (fn_8021A0BC(n)) {
        u32 b = n + 0x40f;
        lbl_80310B3C[b >> 5] |= 1 << (b & 31);
        if (fn_8021A0BC(n)) {
            s32 ok = 0;
            if (fn_8021A0BC(n)) {
                if (FlagTest425(n ^ 1) == 0) {
                    ok = 1;
                }
            }
            if (ok) {
                if (fn_8021A0BC(n)) {
                    u32 d = n + 0x425;
                    lbl_80310B3C[d >> 5] |= 1 << (d & 31);
                }
            }
            fn_8021B2B4();
        }
    }
}

/* Tests story flag 0x425 + n. */
s32 fn_801E4BBC(s8 n) {
    u32 b = n + 0x425;
    return (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
}

/* Tests story flag 0x40F + n. */
s32 fn_801E4BF4(s8 n) {
    u32 b = n + 0x40f;
    return (lbl_80310B3C[b >> 5] & (1 << (b & 31))) != 0;
}
