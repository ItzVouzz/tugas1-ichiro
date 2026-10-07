#include "Striker.hpp"

Striker::Striker() {
  Vector2D startPosition;
  startPosition.x = -2.0;
  startPosition.y = 0.0;
  setPosition(startPosition);
  setSpeed(0.5);
  setOrientation(0.0);
}

void Striker::think() {
  cout << position.x << " " << position.y << endl;
}

void Striker::act(Ball& ball) {
  // if(MathHelper::calculateDistance(position, ball.getPosition()) <= 0.5) {
  //   ball.kick(position);
  // }

  Vector2D currentPosition = getPosition();
  currentPosition.x += getSpeed();
  setPosition(currentPosition);
}