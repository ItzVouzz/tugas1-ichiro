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

    if(position.x > 4.0 && position.y >= -1.5 && position.y <= 1.5) {
      position.x = 4.0;
      speed = 0.0;
    }
    if(position.x < -4.5 || position.x > 4.0 || position.y < -3.0 || position.y > 2.5) {
      position.x = 0.0;
      position.y = 0.0;
      speed = 0.0;
    } else {
      speed--;
    }
  }
}

void Ball::setPosition(Vector2D newPosition) {
  position = newPosition;
}