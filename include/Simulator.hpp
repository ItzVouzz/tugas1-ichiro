#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <iostream>
#include "Striker.hpp"
#include "Field.hpp"
#include "Ball.hpp"

class Simulator {
  private:
    Field field;
    Ball ball;
    Striker striker;
    int currentTick;

  public:
    Simulator();

    void run();
};

#endif