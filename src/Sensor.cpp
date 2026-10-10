#include "Sensor.hpp"
#include <stdexcept>

Vector2D Sensor::scan(Vector2D robotPosition, float robotOrientaion, Vector2D ballPosition) {
  float distance = MathHelper::calculateDistance(robotPosition, ballPosition);
  if(distance > 3.5) {
    throw runtime_error("Bola di luar jangkauan");
  }

  float dx = ballPosition.x - robotPosition.x;
  float dy = ballPosition.y - robotPosition.y;
  bool isFacingBall = false;

  if(robotOrientaion == 0.0 && dx >= 0) {
    isFacingBall = true;
  } else if(robotOrientaion == 90.0 && dy <= 0) {
    isFacingBall = true;
  } else if(robotOrientaion == 180.0 && dx <= 0) {
    isFacingBall = true;
  } else if(robotOrientaion == 270.0 && dy >= 0) {
    isFacingBall = true;
  }

  if(!isFacingBall) {
    throw runtime_error("Bola berada di titik buta");
  }

  return ballPosition;
}