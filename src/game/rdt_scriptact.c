#include "game/scptact.h"

const char lbl_802D46A0[] = "                rdt_scriptact Ver 1.00 Build:Dec 19 2002 18:20:30";

typedef struct Work_801F5468 {
    Ev ev;
    u8 pad14[4];
    u16 n;          /* 0x18 */
    u8 pad1a[2];
    EvBufs* sub;    /* 0x1c */
    u8 pad20[0x24];
} Work_801F5468;


s32 fn_801F5468(u16 f, Scpt* s) {
    Work_801F5468* w;
    EvBufs* sub;
    ScptCur cur;
    void* p;
    s32 v;
    s32 n;
    w = s->work.p;
    if (f & 1) {
        cur.f = s->cur.f + 1;
        w = fn_801E1A2C(1, 0x44);
        if (w == NULL) fn_801DBE1C("Malloc Failed : %s : %d", "rdt_scriptact.c", 0x6d);
        s->work.p = w;
        if (*cur.f == 3.4028235e38f) {
            cur.f++;
            v = 0x7fffffff;
        } else {
            v = (s32)fn_801F6120(&cur.f);
        }
        w->n = v;
        n = w->n;
        if (*cur.f == 3.4028235e38f) {
            cur.f++;
        } else {
            fn_801F6120(&cur.f);
        }
        s->cur.f = cur.f;
        sub = fn_801E1A2C(1, 0x88);
        if (sub == NULL) fn_801DBE1C("Malloc Failed : %s : %d", "rdt_scriptact.c", 0x7c);
        p = fn_801E1A2C(1, lbl_8034A034 * 0x58);
        sub->x20 = p;
        if (p == NULL) fn_801DBE1C("Malloc Failed : %s : %d", "rdt_scriptact.c", 0x7f);
        p = fn_801E1A2C(1, lbl_8034A034 << 6);
        sub->x1c = p;
        if (p == NULL) fn_801DBE1C("Malloc Failed : %s : %d", "rdt_scriptact.c", 0x82);
        w->sub = sub;
        fn_80211058(s, 6, n, 0x28, lbl_8030CEA0.x08, &w->ev);
    }
    if (f & 2) {
        if (s->handle == 0) {
            s->handle = fn_800CD0B8(s->a20, s->a24, s->a28, s->a2c);
            if (s->cnt++ >= 5) fn_801DBE1C("Timeout Error : %d", "rdt_scriptact.c", 0x98);
        } else if (w->ev.hd.kind == 2) {
            sub = w->sub;
            if (sub->x1c != NULL) {
                fn_801E1784(sub->x1c);
                sub->x1c = NULL;
            }
            if (sub->x20 != NULL) {
                fn_801E1784(sub->x20);
                sub->x20 = NULL;
            }
            if (sub != NULL) fn_801E1784(sub);
            return 0;
        }
    }
    if (f & 8) {
        sub = w->sub;
        if (sub->x1c != NULL) {
            fn_801E1784(sub->x1c);
            sub->x1c = NULL;
        }
        if (sub->x20 != NULL) {
            fn_801E1784(sub->x20);
            sub->x20 = NULL;
        }
        if (sub != NULL) fn_801E1784(sub);
        return 1;
    }
    return 1;
}
