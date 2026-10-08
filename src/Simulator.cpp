#include "Simulator.hpp"
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <string>

Simulator::Simulator() {
  currentTick = 0;

  Vector2D robotStartPosition = striker.getPosition();
  Vector2D ballStartPosition = ball.getPosition();

  ifstream file("config.txt");

  if(file.is_open()) {
    string key;
    float value;

    while(file >> key >> value) {
      if(key == "RobotX") robotStartPosition.x = value;
      else if(key == "RobotY") robotStartPosition.y = value;
      else if(key == "BallX") ballStartPosition.x = value;
      else if(key == "BallY") ballStartPosition.y = value;
    }
    file.close();
  }

  striker.setPosition(robotStartPosition);
  ball.setPosition(ballStartPosition);

  Sleep(2000);
}

void Simulator::run() {
  while(true) {
    currentTick++;

    system("cls");

    striker.sense(ball.getPosition());
    striker.think();
    striker.act(ball);
    ball.update();

    field.render(striker, ball.getPosition());

    Sleep(1000);
  }
}

