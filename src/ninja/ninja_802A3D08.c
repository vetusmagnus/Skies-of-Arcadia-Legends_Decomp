/* Sega Ninja library, 0x802A3D08-0x802A3EDC. Strip drawer file: fn_802A3D08 owns the lone 65.0f at
 * 0x8034D390. */

#include "ninja_lib.h"

/* Strip drawer files keep a single-use vertex load in source order where the rest of Ninja lets IRO
 * expression propagation forward it and drop the assignment (docs/ninja.md, "Strip drawer files").
 * `opt_propagation off` fits equally well. */
#pragma opt_dead_assignments off
