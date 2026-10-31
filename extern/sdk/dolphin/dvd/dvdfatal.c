#include "dolphin/DVDPriv.h"
#include "dolphin/os.h"

/* Skies' dvdfatal.c revision: no built-in fatal message screen (no ShowMessage, no message
 * tables), only the hook that __DVDPrintFatalMessage calls. */

void __DVDPrintFatalMessage(void);

static void (*FatalFunc)(void) = NULL;

void __DVDPrintFatalMessage(void) {
  if (!FatalFunc) {
    return;
  }
  FatalFunc();
}
