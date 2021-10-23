#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
// #include "gridobstacle.h"
#include "obstacle.h"

#include "SDL.h"
#include "snake.h"
#include "map.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, std::vector<GridObstacle> map);
  void RenderMap(std::vector<GridObstacle> map);
  Obstacle GetCoordinates(GridObstacle grid_obstacle);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif