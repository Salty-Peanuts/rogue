#include "controller.h"
#include <string>
#include "gamemap.h"
#include <iostream>
#include <map>
#include "combatmanager.h"

using namespace std;

extern const int col;
extern const int row;
extern map<string, int> m_dir;


Controller::Controller(vector<vector<char>> map_layout, string race) {

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

        // if attack
        else if (cmd == "a") {
            cin >> cmd;
            if (m_dir[cmd] != 0) {
                gameMap->playerAtk(m_dir[cmd]);
                gameMap->render();
                continue;
            }
            else {
                cout << "Invalid attack, please try again" << endl;
            }
        }

        // if use potion
        else if (cmd == "u") {
            
        }
    }

}