#include "controller.h"
#include <string>
#include "gamemap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "combatmanager.h"
#include "constants.h"

using namespace std;


// read map layuout from file
void readFromFile(string file_name, vector<vector<char>> &map_layout, int floor) {
    string str;
    ifstream input (file_name);
    for (int i = 0; i < col; i++) {
        map_layout.push_back({});
    }
    for (int i = 0; i < row * floor; i++) {
        getline(input, str);
    }
    for (int i = 0; i < row; i++) {
        getline(input, str);
        for (int j = 0; j < col; j++) {
            // crashes here ====================================
            //map_layout[j][i] = str[j];

            map_layout[j].push_back(str[j]);
        }
    }
}

Controller::Controller(string race, bool given_map, string file_name) {
    vector<vector<char>> map_layout;
    readFromFile(file_name, map_layout, 0);
    GameMap *gm = new GameMap(map_layout, race, given_map, file_name);
    gameMap = gm;
}

Controller::~Controller() {
    delete gameMap;
}

// run games and return the ending state of the game as a string
string Controller::run_game() {
    if (!gameMap->isGivenMap()) gameMap->start();
    cout << "The game starts now: " << endl;
    gameMap->printMap();

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
                    if (gameMap->getLevel() == 5) {
                        cout << "Congratulations, you won! Your score is: " << gameMap->getScore() << endl;
                        return "won";
                    }
                    else {
                        cout << "You reached a new floor!" << endl;
                        gameMap->reset();
                        if (!gameMap->isGivenMap()) gameMap->start();
                        gameMap->resetAction();
                        gameMap->printMap();
                        continue;
                    }
                }
                gameMap->printMap();
                gameMap->npcLogic();
                gameMap->resetAction();
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
                gameMap->printMap();
                gameMap->npcLogic();
                gameMap->resetAction();
                continue;
            }
            else {
                cout << "Invalid attack, please try again" << endl;
            }
        }
        else if (cmd == "f") {
            gameMap->changeNPCmovement();
        }
        else {
            cout << "Please enter a valid command. Try again!" << endl;
            continue;
        }
        if (gameMap->isDead()) {
            cout << "Your HP is below 0, you lost!" << endl;
            return "lost";
        }
    }
}