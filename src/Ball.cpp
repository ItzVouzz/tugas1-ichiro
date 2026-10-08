#include "Ball.hpp"
using namespace std;

Ball::Ball() {
  position.x = 0.0;
  position.y = 0.0;
  direction.x = 0;
  direction.y = 0;
  speed = 0.0;
}

Vector2D Ball::getPosition() {
  return position;
}

void Ball::kick(Vector2D targetDirection) {
  direction = targetDirection;
  speed = 3;
}

void Ball::update() {
  if(speed > 0) {
    position.x = position.x + direction.x * speed;
    position.y = position.y + direction.y * speed;

    if(position.x < -4.5) {
      position.x = -4.5;
    } else if(position.x > 4.5) {
      position.x = 4.5;
    }

    if(position.y < -3.0) {
      position.y = -3.0;
    } else if(position.y > 3.0) {
      position.y = 3.0;
    }

    speed--;
  }
}

void Ball::setPosition(Vector2D newPosition) {
  position = newPosition;
}