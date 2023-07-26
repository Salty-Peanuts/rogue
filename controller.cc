#include <controller.h>
#include <string>
#include <gamemap.h>
#include <iostream>
#include <map>


using namespace std;

const int col = 79;
const int row = 25;

Controller::Controller(char map_layout[col][row], string race) {
    gameMap = new GameMap(map_layout, race);
}

Controller::~Controller() {
    delete gameMap;
}

void run_game() {
    gameMap->start();
    cout << "The game starts now: " << endl;
    
    map<string, int> m_dir;
    m_dir["nw"] = 0;
    m_dir["no"] = 1;
    m_dir["ne"] = 2;
    m_dir["we"] = 3;
    m_dir["ea"] = 4;
    m_dir["sw"] = 5;
    m_dir["so"] = 6;
    m_dir["se"] = 7;

    while (true) {
        
    }

}