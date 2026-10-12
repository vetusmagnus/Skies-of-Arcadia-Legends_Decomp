typedef struct { unsigned char buf[0x40]; } Ctx;
extern void fn_8029259C(Ctx*);
extern void fn_80292080(Ctx*, void*, int, int);
extern void fn_80291B84(Ctx*, void*, void*);
void fn_802136A8(void* a, void* b, void* c, int d, int e) {
    Ctx ctx;
    if (a && b) {
        fn_8029259C(&ctx);
        fn_80292080(&ctx, c, d, e);
        fn_80291B84(&ctx, a, b);
    }
}
