#include <math.h>

typedef struct vec2 {
  float x, y;
} vec2;

void vec2_add(vec2 *v1, vec2 *v2, vec2 *result)
{
  result->x = v1->x + v2->x;
  result->y = v1->y + v2->y;
}

void vec2_sub(vec2 *v1, vec2 *v2, vec2 *result)
{
  result->x = v1->x - v2->x;
  result->y = v1->y - v2->y;
}

void vec2_mul(vec2 *v1, float k, vec2 *result)
{
  result->x = k * v1->x;
  result->y = k * v1->y;
}

float vec2_dot(vec2 *v1, vec2 *v2)
{
  return v1->x * v2->x + v1->y + v2->y;
}

float vec2_lensq(vec2 *v1)
{
  return vec2_dot(v1, v1);
}

float vec2_len(vec2 *v1)
{
  return (float)sqrt(vec2_lensq(v1));
}

