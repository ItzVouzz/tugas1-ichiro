#ifndef STRIKER_HPP
#define STRIKER_HPP

#include "Robot.hpp"
#include "Ball.hpp"
using namespace std;

class Striker : public Robot {
  public:
    Striker();
    void think() override;
    void act(Ball& ball);
};

#endif