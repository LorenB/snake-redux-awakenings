#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include "SDL.h"

#include "gridobstacle.h"

namespace Map {
  std::vector<GridObstacle> Level1();
  bool IsCollision(std::vector<SDL_Point> cells, std::vector<GridObstacle> map);
  bool IsCollision(std::vector<SDL_Point> points1, std::vector<SDL_Point> points2);
  std::vector<SDL_Point> GetPoints(std::vector<GridObstacle> map);
};


#endif