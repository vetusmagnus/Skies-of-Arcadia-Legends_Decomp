#include "game/scptact.h"

/* The enemy data blob: an index of 0x54 {id, offset} pairs, then the 10-byte enemy groups. */
typedef struct EnemyIndex {
    s32 id;
    s32 offset; /* from the start of the blob */
} EnemyIndex;
typedef struct EnemyGroup {
    u8 unk0[2];
    s8 enemy[8]; /* -1 ends the list */
} EnemyGroup;
typedef struct EnemyData {
    EnemyIndex index[0x54];
    EnemyGroup group[1];
} EnemyData;
typedef struct EnemyEntry {
    u8 unk0[0x15];
    s8 unk15;
} EnemyEntry;
extern void *lbl_803474B8;

static inline void *EnemyFind(EnemyData *data, s32 id)
{
    EnemyIndex *p = data->index;
    u8 *blob = lbl_803474B8;
    int i;
    for (i = 0; i < 0x54; i++, p++) {
        if (p->id == id) {
            return blob + p->offset;
        }
    }
    fn_801DBE1C("Enemy Data Nothing");
    return NULL;
}


void fn_801F5334(s8 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        fn_801EFC88(0x102);
    }
}

void fn_801F5380(void) {
    fn_801F452C(0x102);
}

int fn_801F53A4(int no)
{
    EnemyData *data = lbl_803474B8;
    EnemyGroup *group = &data->group[no];
    int i;

    for (i = 0; i < 8; i++) {
        int id = group->enemy[i];
        EnemyEntry *e;
        if (id == -1) break;
        e = EnemyFind(data, id);
        if (e->unk15 != 1) return 0;
    }
    return 1;
}
