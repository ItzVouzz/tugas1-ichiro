#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include "Vector2D.hpp"
using namespace std;

class Sensor {
  public:
    Vector2D scan(Vector2D robotPosition, float robotOrientaion, Vector2D ballPosition);
};

#endif