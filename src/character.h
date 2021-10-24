#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <iostream>
// #include<gridobstacle.h>
// #include "SDL.h"

class Character {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Character(int grid_width, int grid_height)
    : head_x(grid_width / 2),
      head_y(grid_height / 2),
      grid_width(grid_width),
      grid_height(grid_height)
  {
    std::cout << "Character ctor..." << std::endl;
  }

  void Debug();
  void UpdateHead();

  Direction direction = Direction::kUp;
  float speed{0.1f};
  float head_x;
  float head_y;
  int grid_width;
  int grid_height;

//  private:
//   std::vector<GridObstacle> _map;
};

#endif