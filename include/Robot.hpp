#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <iostream>
#include "Vector2D.hpp"
using namespace std;

class Robot {
  protected:
    Vector2D position;
    float orientation;
    float speed;
  
  public:
    void setPosition(Vector2D newPosition);
    virtual void think() = 0;
    Vector2D getPosition();
    float getOrientation();
    float getSpeed();
    void setSpeed(float newSpeed);
    void setOrientation(float newOrientation);
};

#endif