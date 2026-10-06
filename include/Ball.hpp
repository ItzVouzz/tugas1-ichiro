#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>
#include "Vector2D.hpp"
using namespace std;

class Ball {
  private:
    Vector2D position;
    Vector2D direction;
    float speed;
  
  public:
    Vector2D getPosition();
    void kick(Vector2D targetDirection);
    void update();
};

#endif