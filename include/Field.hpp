#ifndef FIELD_HPP
#define FIELD_HPP

#include <iostream>
#include "Vector2D.hpp"
#include "Robot.hpp"
using namespace std;

class Field {
  private:
    const int WIDTH = 18;
    const int LENGTH = 12;

    int toGridX(float x);
    int toGridY(float y);

  public:
    void render(Robot& robot, Vector2D ballPosition);
};

#endif