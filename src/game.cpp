#include "SDL.h"
#include <vector>

#include "game.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, std::vector<GridObstacle> map)
    : snake(grid_width, grid_height, map),
      enemy(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      _map(map) {
  PlaceFood();
  Debug();
}

void Game::Debug() {
  std::cout << "debugging game..." << std::endl;
  // snake.Debug();
  enemy.Debug();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, enemy, food, _map);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);

    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y) && !Map::IsObstacle(x, y, _map)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;
  
  snake.Update();
  enemy.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  int enemy_new_x = static_cast<int>(enemy.head_x);
  int enemy_new_y = static_cast<int>(enemy.head_y);

  SDL_Point new_head;
  new_head.x = static_cast<int>(snake.head_x);
  new_head.y = static_cast<int>(snake.head_y);

  GridObstacle new_enemy;
  new_enemy.cell_x = static_cast<int>(enemy.head_x);
  new_enemy.cell_y = static_cast<int>(enemy.head_y);
  new_enemy.cell_width = 1;
  new_enemy.cell_hieght = 1;
  std::vector<GridObstacle> new_enemies;
  new_enemies.emplace_back(new_enemy);

  std::vector<SDL_Point> whole_snake = snake.body;
  whole_snake.emplace_back(new_head);
  // std::cout << "checking if snake collided with enemy" << std::endl;
  snake.alive = !Map::IsCollision(whole_snake, new_enemies);


  // Check if snake collided with enemy
  if(enemy_new_x== new_x && enemy_new_y == new_y) {
    snake.alive = false;
  }

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }