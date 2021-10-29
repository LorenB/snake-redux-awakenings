#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

#include "character.h"
#include "map.h"
#include "gridobstacle.h"


class Snake : public Character {
 public:
  Snake(int grid_width, int grid_height)
      : Character(grid_width, grid_height) {
            SetInitialPosition(grid_width, grid_height);
            direction = Direction::kUp;
        }
  void Update();

  void GrowBody();
  void SetInitialPosition(int grid_width, int grid_height);
  bool SnakeCell(int x, int y);
  bool SnakeCell(SDL_Point cell);
  int size{1};
  bool alive{true};
  std::vector<SDL_Point> body;

 private:
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
};

#endif