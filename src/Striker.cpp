#include "Striker.hpp"

Striker::Striker() {
  Vector2D startPosition;
  startPosition.x = -2.0;
  startPosition.y = 0.0;
  setPosition(startPosition);
  setSpeed(0.5);
  setOrientation(0.0);
  currentState = SEARCH_BALL;
}

void Striker::think() {
  if(!isBallVisible) {
    currentState = SEARCH_BALL;
    cout << "Mencari bola\n";
  } else {
    float distance = MathHelper::calculateDistance(position, perceivedBallPos);

    if(distance <= 0.6) {
      if(getOrientation() == 0.0) {
        currentState = KICK;
      } else {
        currentState = ALIGN_TO_GOAL;
      }
    } else {
      currentState = APPROACH_BALL;
    }
  }
}

void Striker::act(Ball& ball) {
  // if(MathHelper::calculateDistance(position, ball.getPosition()) <= 0.5) {
  //   ball.kick(position);
  // }

  Vector2D currentPosition = getPosition();
  currentPosition.x += getSpeed();
  setPosition(currentPosition);
}

void Robot::sense(Vector2D actualBallPosition) {
  try {
    perceivedBallPos = camera.scan(position, orientation, actualBallPosition);
    isBallVisible = true;
  } catch(runtime_error) {
    isBallVisible = false;
  }
}