#include "map.h"

std::vector<GridObstacle> Map::Level1() {
    std::vector<GridObstacle> ret;
    GridObstacle obstacle1;
    obstacle1.cell_x = 31;
    obstacle1.cell_y = 0;
    obstacle1.cell_width = 1;
    obstacle1.cell_hieght = 8;

    GridObstacle obstacle2;
    obstacle2.cell_x = 31;
    obstacle2.cell_y = 24;
    obstacle2.cell_width = 1;
    obstacle2.cell_hieght = 8;

    GridObstacle obstacle3;
    obstacle3.cell_x = 24;
    obstacle3.cell_y = 31;
    obstacle3.cell_width = 8;
    obstacle3.cell_hieght = 1;

    GridObstacle obstacle4;
    obstacle4.cell_x = 0;
    obstacle4.cell_y = 31;
    obstacle4.cell_width = 8;
    obstacle4.cell_hieght = 1;

    GridObstacle obstacle5;
    obstacle5.cell_x = 0;
    obstacle5.cell_y = 24;
    obstacle5.cell_width = 1;
    obstacle5.cell_hieght = 8;

    GridObstacle obstacle6;
    obstacle6.cell_x = 0;
    obstacle6.cell_y = 0;
    obstacle6.cell_width = 1;
    obstacle6.cell_hieght = 8;

    GridObstacle obstacle7;
    obstacle7.cell_x = 0;
    obstacle7.cell_y = 0;
    obstacle7.cell_width = 8;
    obstacle7.cell_hieght = 1;

    GridObstacle obstacle8;
    obstacle8.cell_x = 24;
    obstacle8.cell_y = 0;
    obstacle8.cell_width = 8;
    obstacle8.cell_hieght = 1;

    ret.push_back(obstacle1);
    ret.push_back(obstacle2);
    ret.push_back(obstacle3);
    ret.push_back(obstacle4);
    ret.push_back(obstacle5);
    ret.push_back(obstacle6);
    ret.push_back(obstacle7);
    ret.push_back(obstacle8);

    return ret;
}
