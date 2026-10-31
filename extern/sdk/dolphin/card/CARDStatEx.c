#include <dolphin/card.h>
#include <dolphin/dsp.h>
#include <dolphin/dvd.h>
#include <dolphin/os.h>

#include <dolphin/CARDPriv.h>

void __CARDSyncCallback(s32 chan, s32 result);

s32 __CARDGetStatusEx(s32 chan, s32 fileNo, CARDDir* dirent) {

    if ((fileNo < 0) || (fileNo >= CARD_MAX_FILE)) {
        return CARD_RESULT_FATAL_ERROR;
    }

    {
        CARDControl* card;
        CARDDir* dir;
        CARDDir* ent;
        s32 result = __CARDGetControlBlock(chan, &card);

        if (result < 0) {
            return result;
        }
    
        dir = __CARDGetDirBlock(card);
        ent = &dir[fileNo];
        result = __CARDAccess(card, ent);
        if (result == CARD_RESULT_NOPERM) {
            result = __CARDIsWritable(ent);
        }
        if (result >= 0) {
            memcpy(dirent, ent, 0x40);
        }
        return __CARDPutControlBlock(card, result);
    }
}

s32 __CARDSetStatusExAsync(s32 chan, s32 fileNo, CARDDir* dirent, CARDCallback callback) {
    CARDControl* card;
    CARDDir* dir;
    CARDDir* ent;
    s32 result;
    u8* p;
    s32 i;

    if ((fileNo < 0) || (fileNo >= CARD_MAX_FILE) || ((u8) dirent->fileName[0] == 0xFF) || ((u8) dirent->fileName[0] == 0)) {
        return CARD_RESULT_FATAL_ERROR;
    }

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }

    dir = __CARDGetDirBlock(card);
    ent = &dir[fileNo];
    result = __CARDAccess(card, ent);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }

    for (p = dirent->fileName; p < (u8*)&dirent->time; p++) {
        if (*p != 0) {
            continue;
        }
        while ((++p) < (u8*)&dirent->time) {
            *p = 0;
        }
        break;
    }

    if ((memcmp(&ent->fileName, &dirent->fileName, 32) != 0) || (memcmp(ent->gameName, dirent->gameName, 4) != 0) || (memcmp(ent->company, dirent->company, 2) != 0)) {
        for(i = 0; i < CARD_MAX_FILE; i++) {
            if (i != fileNo) {
                CARDDir* ent = &dir[i];
                if (((u8) ent->gameName[0] != 0xFF) 
                    && (memcmp(&ent->gameName, &dirent->gameName, 4) == 0) 
                    && (memcmp(&ent->company, &dirent->company, 2) == 0) 
                    && (memcmp(&ent->fileName, &dirent->fileName, 0x20) == 0)) {
                        return __CARDPutControlBlock(card, -7);
                }
            }
        }
        memcpy(&ent->fileName, &dirent->fileName, 0x20);
        memcpy(&ent->gameName, &dirent->gameName, 4);
        memcpy(&ent->company, &dirent->company, 2);
    }

    ent->time = dirent->time;
    ent->bannerFormat = dirent->bannerFormat;
    ent->iconAddr = dirent->iconAddr;
    ent->iconFormat = dirent->iconFormat;
    ent->iconSpeed = dirent->iconSpeed;
    ent->commentAddr = dirent->commentAddr;
    ent->permission = dirent->permission;
    ent->copyTimes = dirent->copyTimes;

    result = __CARDUpdateDir(chan, callback);
    if (result < 0) {
        __CARDPutControlBlock(card, result);
    }
    return result;
}

s32 CARDSetAttributesAsync(s32 chan, s32 fileNo, u8 attr, CARDCallback callback) {
    CARDDir dirent;
    s32 result;

    result = __CARDGetStatusEx(chan, fileNo, &dirent);
    if (result < 0) {
        return result;
    }
    dirent.permission = attr;
    return __CARDSetStatusExAsync(chan, fileNo, &dirent, callback);
}

s32 CARDSetAttributes(s32 chan, s32 fileNo, u8 attr) {
    s32 result = CARDSetAttributesAsync(chan, fileNo, attr, __CARDSyncCallback);

    if (result < 0) {
        return result;
    }
    return __CARDSync(chan);
}
