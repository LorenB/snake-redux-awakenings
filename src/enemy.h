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
          SetInitialPosition(grid_width, grid_height);
          direction = Direction::kRight;
        }
    
    void Debug();
    void Update();
    void SetInitialPosition(int grid_width, int grid_height);

  private:
    int grid_width;
    int grid_height;
};

#endif