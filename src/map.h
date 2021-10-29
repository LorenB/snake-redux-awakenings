#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include "SDL.h"

#include "gridobstacle.h"


class Map {
  public:
    Map(std::vector<GridObstacle> obstacle_list);
    
    static std::vector<GridObstacle> Level1();
    static bool IsCollision(std::vector<SDL_Point> points1, std::vector<SDL_Point> points2);
    static std::vector<SDL_Point> GetPoints(std::vector<GridObstacle> map);
    std::vector<GridObstacle> obstacles;
    std::vector<SDL_Point> points;
};


#endif