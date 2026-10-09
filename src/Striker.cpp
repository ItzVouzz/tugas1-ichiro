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
    Vector2D idealPosition;
    idealPosition.x = perceivedBallPos.x - 0.5;
    idealPosition.y = perceivedBallPos.y;
    float distance = MathHelper::calculateDistance(position, idealPosition);

    if(distance <= 0.1) {
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
    case SEARCH_BALL: {
      Vector2D nextPosition = position;
      float currentOrientation = getOrientation();

      if(currentOrientation == 0.0) {
        nextPosition.x += getSpeed();
      } else if(currentOrientation == 90.0) {
        nextPosition.y -= getSpeed();
      } else if(currentOrientation == 180.0) {
        nextPosition.x -= getSpeed();
      } else if(currentOrientation == 270.0) {
        nextPosition.y += getSpeed();
      }

      bool isOutField = (nextPosition.x > 4.0 || nextPosition.x < -4.5 || nextPosition.y > 2.5 || nextPosition.y < -3.0);
      bool isHittingGoal = (nextPosition.x >= 4.0 && nextPosition.y >= -1.5 && nextPosition.y <= 1.5);

      if(isOutField || isHittingGoal) {
        setOrientation(currentOrientation + 90.0);
      } else {
        setPosition(nextPosition);
      }

      break;
    }
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
      Vector2D idealPosition;
      idealPosition.x = perceivedBallPos.x - 0.5;
      idealPosition.y = perceivedBallPos.y;
      float dx = idealPosition.x - position.x;
      float dy = idealPosition.y - position.y;
      float distance = MathHelper::calculateDistance(position, idealPosition);

      if(distance > 0) {
        Vector2D newPosition = position;

        float moveStep = (distance < getSpeed()) ? distance : getSpeed();

        newPosition.x = newPosition.x + (dx/distance) * moveStep;
        newPosition.y = newPosition.y + (dy/distance) * moveStep;
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