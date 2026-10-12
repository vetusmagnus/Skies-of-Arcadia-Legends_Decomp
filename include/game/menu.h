#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "game/task.h"
#include "game/uiobj.h"

/* Menu sounds: menu_se_table maps a menu sound id to a sound bank and id for SePlay. */
typedef struct {
    s8 bank;
    u8 id;
} MenuSe;

#define MENU_SE_COUNT 27

extern MenuSe menu_se_table[MENU_SE_COUNT + 1];
s32 SePlay(s32 bank, s8 arg1, s8 id); /* the callee sign-extends arg1 and id itself */
s32 MenuPlaySe(s16 se);

/* A menu part: a task whose first UiObj pointers sit right after the task header. */
typedef struct {
    Task task;
    UiObj* obj;  /* 0x28 */
    UiObj* obj2; /* 0x2C */
} MenuPart;

#define MENU_PART_COUNT 19

/* The work of the save/load and other menu tasks that keep their parts in one table. */
typedef struct {
    u8 pad[0x1F8];
    MenuPart* parts[MENU_PART_COUNT]; /* 0x1F8 */
} MenuWork;

typedef struct {
    u8 pad[0x24];
    MenuWork* work; /* 0x24 */
} MenuTask;

s32 MenuPartsBusy(MenuTask* menu);
void MenuPartsFinish(MenuTask* menu);
void MenuDummy(void);
void MenuPartFree(MenuTask* menu, u16 index);

#endif
