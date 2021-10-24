#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Character::Direction input,
                                 Character::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Character::Direction::kUp,
                          Character::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Character::Direction::kDown,
                          Character::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Character::Direction::kLeft,
                          Character::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Character::Direction::kRight,
                          Character::Direction::kLeft);
          break;
      }
    }
  }
}