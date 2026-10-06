#include "Ball.hpp"
using namespace std;

Vector2D Ball::getPosition() {
  return position;
}

void Ball::kick(Vector2D targetDirection) {
  speed = 3;
}

void Ball::update() {
  while(speed > 0) {
    position = direction;
    speed--;
  }
}