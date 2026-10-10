#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP
#include <cmath>

struct Vector2D {
  float x;
  float y;
};

class MathHelper {
  public:
    static float calculateDistance(Vector2D a, Vector2D b);
};

#endif