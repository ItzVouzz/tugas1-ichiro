#include "Robot.hpp"

void Robot::setPosition(Vector2D newPosition) {
  if(newPosition.x >= -4.5 && newPosition.x <= 4.5 && newPosition.y >= -3.0 && newPosition.y <= 3.0) {
    position.x = newPosition.x;
    position.y = newPosition.y;
  }
}