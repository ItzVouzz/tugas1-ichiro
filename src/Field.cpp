#include "Field.hpp"
#include <cmath>
using namespace std;

int Field::toGridX(float x) {
  return static_cast<int>(std::round((x + 4.5) * 2.0));
}

int Field::toGridY(float y) {
  return static_cast<int>(std::round((y + 3.0) * 2.0));
}

void Field::render(Vector2D RobotPosition, Vector2D ballPosition) {
  int rX = toGridX(RobotPosition.x);
  int rY = toGridY(RobotPosition.y);
  int bX = toGridX(ballPosition.x);
  int bY = toGridY(ballPosition.y);

  for(int y = 0; y < 12; y++) {
    for(int x = 0; x < 18; x++) {
      if(x == rX && y == rY) {
        cout << "R ";
      } else if(x == bX && y == bY) {
        cout << "O";
      } else if(x == 17 && y >= 3 && y <= 8) {
        cout << "# ";
      } else {
        cout << ". ";
      }
    }
    cout << "\n";
  }
}