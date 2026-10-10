#include "Vector2D.hpp"

float MathHelper::calculateDistance(Vector2D a, Vector2D b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}