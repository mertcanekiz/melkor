#include <math.h>

typedef struct vec3 {
  float x, y, z;
} vec3;

void vec3_add(vec3 *v1, vec3 *v2, vec3 *result)
{
  result->x = v1->x + v2->x;
  result->y = v1->y + v2->y;
  result->z = v1->z + v2->z;
}

void vec3_sub(vec3 *v1, vec3 *v2, vec3 *result)
{
  result->x = v1->x - v2->x;
  result->y = v1->y - v2->y;
  result->z = v1->z - v2->z;
}

void vec3_mul(vec3 *v1, float k, vec3 *result)
{
  result->x = k * v1->x;
  result->y = k * v1->y;
  result->z = k * v1->z;
}

float vec3_dot(vec3 *v1, vec3 *v2)
{
  return v1->x * v2->x + v1->y + v2->y + v1->z * v2->z;
}

float vec3_lensq(vec3 *v1)
{
  return vec3_dot(v1, v1);
}

float vec3_len(vec3 *v1)
{
  return (float)sqrt(vec3_lensq(v1));
}
