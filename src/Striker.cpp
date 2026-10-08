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
  switch(currentState) {
    case SEARCH_BALL:
      setOrientation(getOrientation() + 90.0);
      break;
    case ALIGN_TO_GOAL:
      setOrientation(0.0);
      break;
    case KICK:
      Vector2D kickDirection;
      kickDirection.x = 1.0;

      if(position.y < -1.5) {
        kickDirection.y = 1.0;
      } else if(position.y > 1.5) {
        kickDirection.y = -1.0;
      } else {
        kickDirection.y = 0.0;
      }

      ball.kick(kickDirection);
      break;
    case APPROACH_BALL:
      float dx = perceivedBallPos.x - position.x;
      float dy = perceivedBallPos.y - position.y;
      float distance = MathHelper::calculateDistance(position, perceivedBallPos);

      if(distance > 0) {
        Vector2D newPosition = position;
        newPosition.x = newPosition.x + (dx/distance) * getSpeed();
        newPosition.y = newPosition.y + (dy/distance) * getSpeed();
        setPosition(newPosition);

        if(abs(dx) > abs(dy)) {
          setOrientation((dx > 0) ? 0.0 : 180.0);
        } else {
          setOrientation((dy > 0) ? 270.0 : 90.0);
        }
      }

      break;
    }
  }

void Robot::sense(Vector2D actualBallPosition) {
  try {
    perceivedBallPos = camera.scan(position, orientation, actualBallPosition);
    isBallVisible = true;
  } catch(runtime_error) {
    isBallVisible = false;
  }
}