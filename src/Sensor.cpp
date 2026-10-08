#include "Sensor.hpp"
#include <stdexcept>

Vector2D Sensor::scan(Vector2D robotPosition, float robotOrientaion, Vector2D ballPosition) {
  float distance = MathHelper::calculateDistance(robotPosition, ballPosition);
  if(distance > 3.5) {
    throw runtime_error("Bola di luar jangkauan");
  }

  return ballPosition;
}