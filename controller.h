#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <gamemap.h>

using namespace std;


const int col = 79;
const int row = 25;


class Controller {
    GameMap *gameMap;

 public:
    Controller(char map_layout[col][row], string race);
    ~Controller();
    string run_game();
    
};

#endif