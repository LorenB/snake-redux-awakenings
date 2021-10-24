#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
// #include <vector>
#include "SDL.h"

#include "character.h"
// #include "gridobstacle.h"

class Enemy : public Character {
  public:    
    Enemy(int grid_width, int grid_height)
        : Character(grid_width, grid_height) {
          std::cout << "Enemy ctor..." << std::endl;
          SetInitialPosition(grid_width, grid_height);
          direction = Direction::kDown;
        }
    
    void Debug();
    void Update();
    void SetInitialPosition(int grid_width, int grid_height);

  private:
    int grid_width;
    int grid_height;
    // std::vector<GridObstacle> _map;
};

#endif