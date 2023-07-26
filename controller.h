#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <gamemap.h>

using namespace std;


const int col = 79;
const int row = 25;


class Controller {
    GameMap *gameMap;

 public:
    Controller(char map_layout[col][row], string race);
    ~Controller();
    void run_game();

};

#endif