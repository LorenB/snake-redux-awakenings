#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include<gridobstacle.h>
#include "character.h"
#include "SDL.h"

class Snake  : public Character{
 public:
  Snake(int grid_width, int grid_height, std::vector<GridObstacle> map)
      : Character(grid_width, grid_height),
        _map(map) {
            std::cout << "Snake ctor..." << std::endl;
        }

  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);
  int size{1};
  bool alive{true};
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  std::vector<GridObstacle> _map;
};

#endif