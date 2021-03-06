#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)
  };  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)
  };  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died by running into itself
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }
}

void Snake::SetInitialPosition(int grid_width, int grid_height) {
  head_x = grid_width / 2;
  head_y = 0;
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
// TODO: delete method
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(SDL_Point cell) {
  if (cell.x == static_cast<int>(head_x) && cell.y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (cell.x == item.x && cell.y == item.y) {
      return true;
    }
  }
  return false;
}