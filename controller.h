#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <gamemap.h>

using namespace std;

class Controller {
    GameMap *gameMap;

 public:
    Controller(vector<vector<char>> map_layout, string race);
    ~Controller();
    string run_game();
    
};

#endif