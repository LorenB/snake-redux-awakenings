#include "enemy.h"
#include <cmath>
#include <iostream>

void Enemy::Debug() {
  std::cout << "debugging enemy..." << std::endl;
}

void Enemy::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)
  };  // We first capture the head's cell before updating.
  UpdateHead();
  // SDL_Point current_cell{
  //     static_cast<int>(head_x),
  //     static_cast<int>(head_y)
  // };  // Capture the head's cell after updating.

}


