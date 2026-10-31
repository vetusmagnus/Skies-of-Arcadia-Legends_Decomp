#include "dolphin/types.h"
#include "dolphin/os.h"

/* 0x80252E4C-0x8025334C: Skies' TPL.c (demo lib TPLGet / TPLReleasePalette) followed by a
 * named, reference-counted resource cache that TPLReleasePalette goes through when caching is on.
 * Only the functions present in main.dol are written out; names other than TPLGet and
 * TPLReleasePalette are ours. */

typedef struct TPLDescriptor {
  void* textureHeader;
  void* CLUTHeader;
} TPLDescriptor;

typedef struct TPLPalette {
  u32 versionNumber;
  u32 numDescriptors;
  TPLDescriptor* descriptorArray;
} TPLPalette;

typedef struct ResLink {
  void* prev;
  void* next;
} ResLink;

typedef struct ResList {
  u32 offset;
  void* head;
  void* tail;
} ResList;

typedef struct ResNode {
  ResLink link;
  void (*dtor)(void** data);
  char* name;
  void* data;
  u16 refCount;
} ResNode;

typedef struct ResCache {
  u8 locked;
  ResList list;
} ResCache;

#define RES_LINK(list, obj) ((ResLink*)((u8*)(obj) + (list)->offset))

extern void* OSAllocFromHeapClear(int heap, u32 size);

u8 __TPLUseResCache;
ResCache __TPLResCache;

static u8 ResNodeAlloc(ResNode** pnode, const char* name);
static void ResNodeFree(ResNode** pnode);
static void ResCacheRelease(ResCache* cache, void* data);
static void ResListInsert(ResList* list, void* obj, void* newObj);
static void ResListRemove(ResList* list, void* obj);
static void ResStrCopy(char* dst, const char* src);
static s8 ResStrCmp(const char* a, const char* b);
static u32 ResStrLen(const char* s);

TPLDescriptor* TPLGet(TPLPalette* pal, u32 id) {
  return &pal->descriptorArray[id];
}

void TPLReleasePalette(TPLPalette** pal) {
  if (__TPLUseResCache) {
    ResCacheRelease(&__TPLResCache, *pal);
  } else {
    OSFreeToHeap(__OSCurrHeap, *pal);
    *pal = NULL;
  }
}

ResNode* ResCacheAdd(ResCache* cache, const char* name, void* data, void (*dtor)(void**)) {
  ResNode* node = NULL;

  if (!ResNodeAlloc(&node, name)) {
    return NULL;
  }

  ResStrCopy(node->name, name);
  node->data = data;
  node->dtor = dtor;
  node->refCount = 0;
  ResListInsert(&cache->list, NULL, node);
  return node;
}

static u8 ResNodeAlloc(ResNode** pnode, const char* name) {
  if (*pnode != NULL) {
    ResNodeFree(pnode);
  }

  *pnode = OSAllocFromHeapClear(__OSCurrHeap, sizeof(ResNode));
  if (*pnode == NULL) {
    return FALSE;
  }

  (*pnode)->name = OSAllocFromHeapClear(__OSCurrHeap, ResStrLen(name) + 1);
  if ((*pnode)->name == NULL) {
    return FALSE;
  }
  return TRUE;
}

static inline ResNode* ResCacheFindName(ResCache* cache, const char* name) {
  ResNode* node = cache->list.head;

  if (name != NULL) {
    for (; node != NULL; node = node->link.next) {
      if (!ResStrCmp(name, node->name)) {
        return node;
      }
    }
  }
  return NULL;
}

void* ResCacheGet(ResCache* cache, const char* name) {
  ResNode* node = ResCacheFindName(cache, name);

  if (node != NULL) {
    node->refCount++;
    return node->data;
  }
  return NULL;
}

static void ResNodeFree(ResNode** pnode) {
  if (*pnode != NULL) {
    if ((*pnode)->dtor != NULL) {
      (*pnode)->dtor(&(*pnode)->data);
    }
    OSFreeToHeap(__OSCurrHeap, (*pnode)->name);
    OSFreeToHeap(__OSCurrHeap, *pnode);
    *pnode = NULL;
  }
}

static inline ResNode* ResCacheFindData(ResCache* cache, void* data) {
  ResNode* node = cache->list.head;

  if (data != NULL) {
    for (; node != NULL; node = node->link.next) {
      if (data == node->data) {
        return node;
      }
    }
  }
  return NULL;
}

static inline void ResNodeDestroy(ResNode* node) {
  if (node != NULL) {
    if (node->dtor != NULL) {
      node->dtor(&node->data);
    }
    OSFreeToHeap(__OSCurrHeap, node->name);
    OSFreeToHeap(__OSCurrHeap, node);
  }
}

static void ResCacheRelease(ResCache* cache, void* data) {
  ResNode* node = ResCacheFindData(cache, data);

  if (node != NULL) {
    if (node->refCount != 0) {
      node->refCount--;
    }
    if (node->refCount == 0 && !cache->locked) {
      ResListRemove(&cache->list, node);
      ResNodeDestroy(node);
    }
  }
}

static void ResListInsert(ResList* list, void* obj, void* newObj) {
  ResLink* newLink = RES_LINK(list, newObj);

  if (list->head != NULL) {
    if (obj == NULL) {
      RES_LINK(list, list->tail)->next = newObj;
      newLink->prev = list->tail;
      newLink->next = NULL;
      list->tail = newObj;
    } else {
      ResLink* link = RES_LINK(list, obj);

      if (obj == list->head) {
        list->head = newObj;
        newLink->next = obj;
        link->prev = newObj;
      } else {
        ResLink* prevLink = RES_LINK(list, link->prev);

        newLink->next = obj;
        newLink->prev = link->prev;
        link->prev = newObj;
        prevLink->next = newObj;
      }
    }
  } else {
    list->tail = newObj;
    list->head = newObj;
    newLink->prev = NULL;
    newLink->next = NULL;
  }
}

static void ResListRemove(ResList* list, void* obj) {
  ResLink* link = RES_LINK(list, obj);

  if (obj == NULL) {
    return;
  }

  if (link->prev != NULL) {
    RES_LINK(list, link->prev)->next = link->next;
  } else {
    list->head = link->next;
  }

  if (link->next != NULL) {
    RES_LINK(list, link->next)->prev = link->prev;
  } else {
    list->tail = link->prev;
  }

  link->prev = NULL;
  link->next = NULL;
}

static void ResStrCopy(char* dst, const char* src) {
  do {
    *dst++ = *src;
  } while (*++src);
}

static s8 ResStrCmp(const char* a, const char* b) {
  do {
    if (*a < *b) {
      return 1;
    }
    if (*a > *b) {
      return -1;
    }
    b++;
  } while (*++a && *b);
  return 0;
}

static u32 ResStrLen(const char* s) {
  u32 len = 0;

  if (s == NULL) {
    return 0;
  }
  while (*s) {
    s++;
    len++;
  }
  return len;
}
