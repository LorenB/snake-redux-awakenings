#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
// #include <vector>
// #include "gridobstacle.h"
// #include "SDL.h"

class Enemy {
  public:    
    Enemy(int grid_width, int grid_height)
        : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}
    void Debug();
    float head_x;
    float head_y;
  private:
    int grid_width;
    int grid_height;
    // std::vector<GridObstacle> _map;
};

#endif