#include "Field.hpp"
#include <cmath>
using namespace std;

int Field::toGridX(float x) {
  return static_cast<int>(std::round((x + 4.5) * 2.0));
}

int Field::toGridY(float y) {
  return static_cast<int>(std::round((y + 3.0) * 2.0));
}

void Field::render(Robot& robot, Vector2D ballPosition) {
  int rX = toGridX(robot.getPosition().x);
  int rY = toGridY(robot.getPosition().y);
  int bX = toGridX(ballPosition.x);
  int bY = toGridY(ballPosition.y);
  float orientation = robot.getOrientation();

  for(int y = 0; y < 12; y++) {
    for(int x = 0; x < 18; x++) {
      int dx = x - rX;
      int dy = y - rY;

      if(x == rX && y == rY) {
        cout << "R ";
      } else if(x == bX && y == bY) {
        cout << "O ";
      } else if(x == 17 && y >= 3 && y <= 8) {
        cout << "# ";
      } else if(orientation == 0.0 && dx > 0 && dx <= 3 && abs(dy) <= dx) {
        cout << "@ ";
      } else if(orientation == 180.0 && dx < 0 && dx >= -3 && abs(dy) <= abs(dx)) {
        cout << "@ ";
      } else if(orientation == 90.0 && dy < 0 && dy >= -3 && abs(dx) <= abs(dy)) {
        cout << "@ ";
      } else if(orientation == 270.0 && dy > 0 && dy <= 3 && abs(dx) <= dy) {
        cout << "@ ";
      } else {
        cout << ". ";
      }
    }
    cout << "\n";
  }
}