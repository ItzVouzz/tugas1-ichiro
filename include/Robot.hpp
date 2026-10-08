#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <iostream>
#include "Vector2D.hpp"
#include "Sensor.hpp"
using namespace std;

class Robot {
  protected:
    Vector2D position;
    float orientation;
    float speed;
    Sensor camera;
    bool isBallVisible;
    Vector2D perceivedBallPos;
  
  public:
    void setPosition(Vector2D newPosition);
    virtual void think() = 0;
    Vector2D getPosition();
    float getOrientation();
    float getSpeed();
    void setSpeed(float newSpeed);
    void setOrientation(float newOrientation);
    virtual void sense(Vector2D actualBallPosition);
};

#endif