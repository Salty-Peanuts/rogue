#include <controller.h>
#include <string>
#include <gamemap.h>
#include <iostream>
#include <map>


using namespace std;

const int col = 79;
const int row = 25;


Controller::Controller(char map_layout[col][row], string race) {
    // set map layout, race of the player character, and npc movement = true
    GameMap gm = new GameMap(map_layout, race, true);
    gameMap = &gm;
}

Controller::~Controller() {
    delete gameMap;
}

// run games and return the ending state of the game as a string
string Controller::run_game() {
    gameMap->start();
    cout << "The game starts now: " << endl;
    
    map<string, int> m_dir;
    m_dir["nw"] = 1;
    m_dir["no"] = 2;
    m_dir["ne"] = 3;
    m_dir["we"] = 4;
    m_dir["ea"] = 5;
    m_dir["sw"] = 6;
    m_dir["so"] = 7;
    m_dir["se"] = 8;

    while (true) {
        string cmd;
        cin >> cmd;
        if (cmd == "r") {
            return "restart";
        }

        // if a valid move command
        else if (m_dir[cmd] != 0) {
            // if the move is valid
            if (gameMap->moveCharacter(m_dir[cmd])) {
                // if the player reaches the stair
                if (gameMap->isStair()) {
                    if (gameMap->floor_level == 5) {
                        return "won";
                    }
                    else {
                        cout << "You reached a new floor!" << endl;
                        gameMap->reset();
                        gameMap->update();
                        continue;
                    }
                }
                gameMap->render();
                continue;
            }
            // if the move is not valid
            else {
                cout << "Invalid move, please try again." << endl;
                continue;
            }
        }
        else if (cmd == "a") {
            
        }
    }

}