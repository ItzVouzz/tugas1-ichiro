#ifndef STRIKER_HPP
#define STRIKER_HPP

#include "Robot.hpp"
#include "Ball.hpp"
#include "Vector2D.hpp"
using namespace std;

class Striker : public Robot {
  private:
    enum State {
      SEARCH_BALL, APPROACH_BALL, ALIGN_TO_GOAL, KICK
    };
    State currentState;

  public:
    Striker();
    void think() override;
    void act(Ball& ball);
};

#endif