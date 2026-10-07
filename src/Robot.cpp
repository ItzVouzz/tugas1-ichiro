#include "Robot.hpp"

float Robot::getOrientation() {
  return orientation;
}

float Robot::getSpeed() {
  return speed;
}

Vector2D Robot::getPosition() {
  return position;
}

void Robot::setPosition(Vector2D newPosition) {
  if(newPosition.x >= -4.5 && newPosition.x <= 4.5 && newPosition.y >= -3.0 && newPosition.y <= 3.0) {
    position.x = newPosition.x;
    position.y = newPosition.y;
  }
}

void Robot::setSpeed(float newSpeed) {
  if(newSpeed >= 0 && newSpeed <= 0.5) {
    speed = newSpeed;
  }
}

void Robot::setOrientation(float newOrientation) {
  orientation = newOrientation;
}