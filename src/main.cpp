#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  std::vector<GridObstacle> map;
  GridObstacle obstacle1;
  obstacle1.cell_x = 0;
  obstacle1.cell_y = 0;
  obstacle1.cell_width = 1;
  obstacle1.cell_hieght = 32;

  GridObstacle obstacle2;
  obstacle2.cell_x = 15;
  obstacle2.cell_y = 25;
  obstacle2.cell_width = 5;
  obstacle2.cell_hieght = 1;

  map.push_back(obstacle1);
  map.push_back(obstacle2);

  // int num = 1;
  // for (auto const &obstacle : map) {
  //   std::cout << "obstacle #" << num << std::endl;
  //   std::cout << "x, y, w, h: " << obstacle.cell_x * 20 << ", " << obstacle.cell_y * 20 << ", " << obstacle.cell_width * 20 << ", " << obstacle.cell_hieght * 20 << std::endl;
  //   for(int i=0; i <  obstacle.cell_width; i++) {
  //     for(int j=0; j < obstacle.cell_hieght; j++) {
  //       std::cout << "cell x, y: " << obstacle.cell_x * 20  + i * 20 << ", " << obstacle.cell_y * 20 + j * 20 << std::endl; 
  //     }
  //   }
  // }

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, map);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}