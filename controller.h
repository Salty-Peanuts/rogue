#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gamemap.h"

using namespace std;

class Controller {
    GameMap *gameMap;

 public:
    Controller(string race, bool given_map, string file_name);
    ~Controller();
    string run_game();
    
};

#endif