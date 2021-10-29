#include "SDL.h"
#include <vector>

#include "game.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, Map map)
    : snake(grid_width, grid_height),
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
  SDL_Point food_point_guess;
  

  while (true) {
    std::vector<SDL_Point> food_point_guesses;
    food_point_guess.x = random_w(engine);
    food_point_guess.y = random_h(engine);
    food_point_guesses.emplace_back(food_point_guess);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(food_point_guess) && !Map::IsCollision(food_point_guesses, _map.points)) {
      food.x = food_point_guess.x;
      food.y = food_point_guess.y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;
  
  snake.Update();
  enemy.Update();

  SDL_Point new_head;
  new_head.x = static_cast<int>(snake.head_x);
  new_head.y = static_cast<int>(snake.head_y);

  SDL_Point new_enemy;
  std::vector<SDL_Point> new_enemies;
  new_enemy.x = static_cast<int>(enemy.head_x);
  new_enemy.y = static_cast<int>(enemy.head_y);
  new_enemies.emplace_back(new_enemy);


  std::vector<SDL_Point> whole_snake = snake.body;
  whole_snake.emplace_back(new_head);
  snake.alive = !Map::IsCollision(whole_snake, new_enemies);

  if(snake.alive) {
    snake.alive = !Map::IsCollision(whole_snake, _map.points);
  }

  // Check if there's food over here
  if (food.x == new_head.x && food.y == new_head.y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }