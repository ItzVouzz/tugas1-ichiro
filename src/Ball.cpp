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
  while(speed > 0) {
    position.x = position.x + direction.x * speed;
    position.y = position.y + direction.y + speed;
    speed--;
  }
}