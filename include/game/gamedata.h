#ifndef GAME_GAMEDATA_H
#define GAME_GAMEDATA_H

#include "types.h"

/*
 * The game's fixed data tables (.rodata, the shop lists in .data). Each record starts with its
 * name where it has one. Item ids are global: weapons from 0, armour from 0x50, accessories
 * from 0xA0, usable items from 0xF0, key items from 0x140, ship cannons from 0x190, ship
 * accessories from 0x1B8, ship items from 0x1E0.
 */

/* A stat bonus: which stat, and by how much. */
typedef struct StatMod {
    s8 stat;
    u8 pad1;
    s16 val;
} StatMod;

/* lbl_802C4860: a party member's starting record, one per character (0x98). */
typedef struct CharParam {
    char name[11];
    s8 age;
    s8 sex;
    u8 width;               /* 0x0D */
    u8 depth;               /* 0x0E */
    s8 mp_cap;              /* 0x0F */
    s8 element;             /* 0x10 */
    u8 pad11;
    s16 weapon;             /* 0x12: starting equipment */
    s16 armor;              /* 0x14 */
    s16 acc;                /* 0x16 */
    s16 moves;              /* 0x18: bit per movement kind */
    s16 hp;                 /* 0x1A */
    s16 hp_max;             /* 0x1C */
    s16 hp_up;              /* 0x1E */
    s16 sp;                 /* 0x20 */
    s16 sp_max;             /* 0x22 */
    s16 counter;            /* 0x24 */
    u8 pad26[2];
    u32 exp;                /* 0x28 */
    f32 mp_up;              /* 0x2C */
    f32 x30;
    s16 elem_def[6];        /* 0x34 */
    s16 status_def[15];     /* 0x40 */
    s16 danger;             /* 0x5E */
    s16 power;              /* 0x60 */
    s16 will;               /* 0x62 */
    s16 vigor;              /* 0x64 */
    s16 agile;              /* 0x66 */
    s16 quick;              /* 0x68 */
    u8 pad6a[2];
    f32 power_up;           /* 0x6C */
    f32 will_up;
    f32 vigor_up;
    f32 agile_up;
    f32 quick_up;
    s32 magic_exp[6];       /* 0x80: per element */
} CharParam;

/* lbl_802C4BF0: party spells (0-35) followed by the special moves (36-61), 0x30 each. */
typedef struct SkillData {
    char name[17];
    s8 element;             /* 0x11 */
    s16 sort;               /* 0x12 */
    u8 use_mask;            /* 0x14: where it can be used */
    s8 effect;              /* 0x15 */
    u8 target;              /* 0x16 */
    s8 kind;                /* 0x17 */
    s8 speed;               /* 0x18 */
    s8 cost;                /* 0x19 */
    u8 pad1a[2];
    s16 power;              /* 0x1C */
    s8 type;                /* 0x1E */
    s8 status;              /* 0x1F */
    s8 status_rate;         /* 0x20 */
    u8 pad21[3];
    s8 ship_use;            /* 0x24 */
    u8 pad25;
    s16 ship_effect;        /* 0x26 */
    s8 ship_cost;           /* 0x28 */
    s8 ship_turns;          /* 0x29 */
    s16 ship_power;         /* 0x2A */
    s8 x2c;
    u8 pad2d[3];
} SkillData;

/* lbl_802C5790: weapons, ids 0-0x4F (0x20). */
typedef struct WeaponData {
    char name[17];
    u8 owner;               /* 0x11 */
    u8 can_sell;            /* 0x12 */
    u8 sort;                /* 0x13 */
    s8 sort2;               /* 0x14 */
    s8 effect;              /* 0x15: lbl_802C7A90 entry */
    u16 price;              /* 0x16 */
    s16 attack;             /* 0x18 */
    s16 accuracy;           /* 0x1A */
    StatMod mod;            /* 0x1C */
} WeaponData;

/* lbl_802C6190 (armour, ids 0x50-0x9F) and lbl_802C6E10 (accessories, 0xA0-0xEF), 0x28 each. */
typedef struct GearData {
    char name[17];
    u8 owners;              /* 0x11: bit per character */
    u8 can_sell;            /* 0x12 */
    u8 sort;                /* 0x13 */
    s8 sort2;               /* 0x14 */
    u8 pad15;
    u16 price;              /* 0x16 */
    StatMod mods[4];        /* 0x18 */
} GearData;

/* lbl_802C7A90: the extra effect a weapon can carry (0x14). */
typedef struct WeaponFx {
    char name[17];
    s8 effect;              /* 0x11 */
    s8 status;              /* 0x12 */
    s8 status_rate;         /* 0x13 */
} WeaponFx;

/* lbl_802C7C34: usable items, ids 0xF0-0x13F (0x24). */
typedef struct UseItemData {
    char name[17];
    u8 use_mask;            /* 0x11 */
    s8 effect;              /* 0x12 */
    u8 target;              /* 0x13 */
    u8 use_up;              /* 0x14: chance the item is used up */
    u8 can_sell;            /* 0x15 */
    u8 sort;                /* 0x16 */
    s8 sort2;               /* 0x17 */
    u16 price;              /* 0x18 */
    u8 pad1a[2];
    s16 power;              /* 0x1C */
    s8 element;             /* 0x1E */
    s8 type;                /* 0x1F */
    s16 status;             /* 0x20 */
    s16 status_rate;        /* 0x22 */
} UseItemData;

/* lbl_802C8774: key items, ids 0x140-0x18F (0x16). */
typedef struct KeyItemData {
    char name[17];
    u8 can_sell;            /* 0x11 */
    u8 sort;                /* 0x12 */
    s8 sort2;               /* 0x13 */
    u16 price;              /* 0x14 */
} KeyItemData;

/* lbl_802C8E54: the pirate ranks (0x22). */
typedef struct PirateRank {
    char name[25];
    u8 rank;                /* 0x19 */
    s16 attack;             /* 0x1A */
    s16 special;            /* 0x1C */
    s16 dodge;              /* 0x1E */
    s16 flee;               /* 0x20 */
} PirateRank;

/* lbl_802C9184: SP and max SP per level, one table per character. */
typedef struct SpStep {
    s8 sp;
    s8 sp_max;
} SpStep;

typedef struct SpCurve {
    SpStep lv[99];
} SpCurve;

/* lbl_802AD440: enemy spells (0-35) followed by their special moves (36-344), 0x24 each. */
typedef struct EnemySkill {
    char name[17];
    u8 pad11[4];
    u8 kind;                /* 0x15 */
    s8 effect;              /* 0x16 */
    u8 target;              /* 0x17 */
    s16 param;              /* 0x18 */
    u16 power;              /* 0x1A */
    s8 element;             /* 0x1C */
    s8 type;                /* 0x1D */
    s8 inflict;             /* 0x1E */
    s8 resist;              /* 0x1F */
    s8 status;              /* 0x20 */
    s8 status_rate;         /* 0x21 */
    u8 pad22[2];
} EnemySkill;

/* lbl_802D4638: bonus experience rewards (0x1C). */
typedef struct ExpBonus {
    u32 exp;
    u32 magic_exp[6];
} ExpBonus;

/* lbl_802D59E8: a treasure chest's contents, by chest number. Item ids from 0x200 are gold. */
typedef struct ChestData {
    s32 item;
    s32 count;
} ChestData;

/* lbl_802D6740: the player's ships (0x64). */
typedef struct ShipData {
    char name[20];
    u32 hp_max;             /* 0x14 */
    s16 sp_max;             /* 0x18 */
    s16 sp;                 /* 0x1A */
    s16 defense;            /* 0x1C */
    s16 mag_def;            /* 0x1E */
    s16 quick;              /* 0x20 */
    s16 dodge;              /* 0x22 */
    s16 elem_def[6];        /* 0x24 */
    s16 cannon[5];          /* 0x30 */
    s16 acc[3];             /* 0x3A */
    s32 value;              /* 0x40 */
    u8 pad44[4];
    s32 hp_up;              /* 0x48 */
    s16 sp_max_up;          /* 0x4C */
    s16 sp_up;              /* 0x4E */
    s16 defense_up;         /* 0x50 */
    s16 mag_def_up;         /* 0x52 */
    s16 quick_up;           /* 0x54 */
    s16 dodge_up;           /* 0x56 */
    u8 pad58[0xC];
} ShipData;

/* One of an enemy ship's guns. */
typedef struct ShipArm {
    s16 type;
    s16 attack;
    s16 range;
    s16 accuracy;
    s16 element;
} ShipArm;

/* lbl_802D6934: enemy ships (0x78). */
typedef struct EnemyShipData {
    char name[20];
    s32 hp_max;             /* 0x14 */
    s16 will;               /* 0x18 */
    s16 defense;            /* 0x1A */
    s16 mag_def;            /* 0x1C */
    s16 quick;              /* 0x1E */
    s16 agile;              /* 0x20 */
    s16 dodge;              /* 0x22 */
    s16 elem_def[6];        /* 0x24 */
    ShipArm arm[4];         /* 0x30 */
    u8 pad58[0xC];
    s32 exp;                /* 0x64 */
    s32 gold;               /* 0x68 */
    struct {
        s16 rate;
        s16 item;
    } drop[3];              /* 0x6C */
} EnemyShipData;

/* lbl_802D7E4C: ship cannons, ids 0x190-0x1B7 (0x24). */
typedef struct CannonData {
    char name[17];
    u8 ships;               /* 0x11: bit per ship */
    s8 type;                /* 0x12 */
    s8 element;             /* 0x13 */
    s16 attack;             /* 0x14 */
    s16 accuracy;           /* 0x16 */
    u8 limit;               /* 0x18 */
    u8 cost;                /* 0x19 */
    StatMod mod[1];         /* 0x1A */
    u16 price;              /* 0x1E */
    u8 can_sell;            /* 0x20 */
    u8 sort;                /* 0x21 */
    s8 sort2;               /* 0x22 */
    u8 x23;
} CannonData;

/* lbl_802D83EC: ship accessories, ids 0x1B8-0x1DF (0x28). */
typedef struct ShipGearData {
    char name[17];
    u8 ships;               /* 0x11 */
    StatMod mods[4];        /* 0x12 */
    u16 price;              /* 0x22 */
    u8 can_sell;            /* 0x24 */
    u8 sort;                /* 0x25 */
    s8 sort2;               /* 0x26 */
    u8 pad27;
} ShipGearData;

/* lbl_802D8A2C: ship items, ids 0x1E0-0x1FD (0x24). The fields at 0x11-0x14 and 0x1C are where
   the usable items have theirs. */
typedef struct ShipItemData {
    char name[17];
    u8 use_mask;            /* 0x11 */
    s8 effect;              /* 0x12 */
    u8 turns;               /* 0x13 */
    u8 use_up;              /* 0x14 */
    u8 pad15;
    u16 price;              /* 0x16 */
    u8 can_sell;            /* 0x18 */
    u8 sort;                /* 0x19 */
    s8 sort2;               /* 0x1A */
    u8 pad1b;
    s16 power;              /* 0x1C */
    s8 element;             /* 0x1E */
    s8 x1f;
    s16 x20;
    s16 accuracy;           /* 0x22 */
} ShipItemData;

/* lbl_802D8E64: crew members (0x24). */
typedef struct CrewData {
    char name[17];
    u8 post;                /* 0x11: the crew position */
    StatMod mod;            /* 0x12 */
    s8 effect;              /* 0x16: in ship battle */
    s8 cost;                /* 0x17 */
    s8 turns;               /* 0x18 */
    u8 pad19[3];
    s16 power;              /* 0x1C */
    s16 x1e;
    u8 pad20[4];
} CrewData;

/* lbl_802EC0A0: shop stock lists (.data, 0x68). */
typedef struct ShopData {
    u16 id;
    u8 pad2[2];
    const char *label;      /* 0x04 */
    s16 item[48];           /* 0x08: -1 ends the list */
} ShopData;

extern CharParam lbl_802C4860[6];
extern EnemySkill lbl_802AD440[345];
extern SkillData lbl_802C4BF0[62];
extern WeaponData lbl_802C5790[80];
extern GearData lbl_802C6190[80];
extern GearData lbl_802C6E10[80];
extern WeaponFx lbl_802C7A90[21];
extern UseItemData lbl_802C7C34[80];
extern KeyItemData lbl_802C8774[80];
extern PirateRank lbl_802C8E54[24];
extern SpCurve lbl_802C9184[6];
extern ExpBonus lbl_802D4638[3];
extern const ChestData lbl_802D59E8[119];
extern ShipData lbl_802D6740[5];
extern EnemyShipData lbl_802D6934[45];
extern CannonData lbl_802D7E4C[40];
extern ShipGearData lbl_802D83EC[40];
extern ShipItemData lbl_802D8A2C[30];
extern CrewData lbl_802D8E64[22];
extern ShopData lbl_802EC0A0[43];

#endif
