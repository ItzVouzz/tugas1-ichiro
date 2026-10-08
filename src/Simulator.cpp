#include "Simulator.hpp"
#include <windows.h>
#include <cstdlib>

Simulator::Simulator() {
  currentTick = 0;
}

void Simulator::run() {
  while(true) {
    currentTick++;

    system("cls");
    striker.think();
    striker.act(ball);
    ball.update();

    field.render(striker, ball.getPosition());

    Sleep(1000);
  }
}

