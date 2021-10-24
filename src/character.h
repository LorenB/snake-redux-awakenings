#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <iostream>
// #include<gridobstacle.h>
// #include "SDL.h"

class Character {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Character() {
    std::cout << "Character ctor" << std::endl;
  }

  void Debug();
  // void UpdateHead();

  Direction direction = Direction::kUp;
  float speed{0.1f};
  float head_x;
  float head_y;

 private:
  int grid_width;
  int grid_height;
  // std::vector<GridObstacle> _map;
};

#endif