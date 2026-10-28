/* Out-of-line float wrappers of this game's libm: sinf, cosf and acosf are real functions here.
 * Deferred codegen emits them in reverse source order. */
#define SKIES_FLOAT_MATH_EXTERN
#include <math.h>

float acosf(float x) { return (float)acos((double)x); }

float cosf(float x) { return (float)cos((double)x); }

float sinf(float x) { return (float)sin((double)x); }
