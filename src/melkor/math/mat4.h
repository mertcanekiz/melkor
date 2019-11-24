#include <math.h>
#include <stdlib.h>

typedef struct mat4 {
  float m[16];
} mat4;

mat4* mat4_identity()
{
  mat4* result = malloc(sizeof(mat4));

  for (int i = 0; i < 16; i++) {
    result->m[i] = 0.0f;
  }

  result->m[0 + 0 * 4] = 1.0f;
  result->m[1 + 1 * 4] = 1.0f;
  result->m[2 + 2 * 4] = 1.0f;
  result->m[3 + 3 * 4] = 1.0f;

  return result;
}
