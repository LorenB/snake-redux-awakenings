#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>

#include "gridobstacle.h"

namespace Map {
  std::vector<GridObstacle> Level1();
  bool IsObstacle(int x, int y, std::vector<GridObstacle> map);
};

#endif