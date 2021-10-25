#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include "SDL.h"
#include "controller.h"
#include "map.h"
#include "renderer.h"
#include "snake.h"
#include "enemy.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, std::vector<GridObstacle> map);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  void Debug();

 private:
  Snake snake;
  Enemy enemy;
  SDL_Point food;
  std::vector<GridObstacle> _map;
  // Map map;
  // SDL_Point map;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  // bool IsObstacle(int x, int y);
  void Update();
};

#endif