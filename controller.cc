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
bool readFromFile(string file_name, vector<vector<char>> &map_layout, int floor) {
    bool check = false;
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
            if (str[j] == '@' || str[j] == 'H' || str[j] == 'W' || str[j] == 'O' || str[j] == 'L' || str[j] == 'E' || str[j] == 'M' || str[j] == 'D' || str[j] == '1' ||
                str[j] == '2' || str[j] == '3' || str[j] == '4' || str[j] == '5' || str[j] == '6' || str[j] == '7' || str[j] == 'G' || str[j] == '8' || str[j] == '9') check = true;
            map_layout[j].push_back(str[j]);
        }
    }
    return check;
}

Controller::Controller(string race, bool given_map, string file_name) {
    vector<vector<char>> map_layout;
    bool check = readFromFile(file_name, map_layout, 0);
    GameMap *gm = new GameMap(map_layout, race, check, file_name);
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
        cout << "Enter command: ";
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
                        if (gameMap->isDead()) {
                            cout << "Your HP is below 0, you lost!" << endl;
                            return "lost";
                        }       
                        cout << "You reached a new floor!" << endl;
                        gameMap->reset();
                        if (!gameMap->isGivenMap()) gameMap->start();
                        gameMap->resetAction();
                        gameMap->printMap();
                        continue;
                    }
                }
                gameMap->npcLogic();
                if (gameMap->isDead()) {
                    cout << "Your HP is below 0, you lost!" << endl;
                    return "lost";
                }
                gameMap->printMap();
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
            //cout << "Enter direction: "; 
            cin >> cmd;
            if (m_dir[cmd] != 0) {
                gameMap->playerAtk(m_dir[cmd]);
                gameMap->npcLogic();
                
                if (gameMap->isDead()) {
                    cout << "Your HP is below 0, you lost!" << endl;
                    return "lost";
                }

                gameMap->printMap();
                gameMap->resetAction();
                continue;
            }
            else {
                cout << "Invalid attack, please try again" << endl;
            }
        }
        else if (cmd == "f") {
            gameMap->changeNPCmovement();
            cout << "You just changed the state of the NPCs" << endl;
        }
        else if (cmd == "u") {
            //cout << "Enter direction: "; 
            cin >> cmd;
            if (m_dir[cmd] != 0) {
                if (gameMap->usePotion(m_dir[cmd])) {
                    gameMap->npcLogic();
                    if (gameMap->isDead()) {
                        cout << "Your HP is below 0, you lost!" << endl;
                        return "lost";
                    }
                    gameMap->printMap();
                    gameMap->resetAction();
                }
                else cout << "There is no potion there, try again." << endl;
            }
            else cout << "Please enter a valid direction" << endl;
        }
        else if (cmd == "q") {
            return "lost";
        }
        else {
            cout << "Please enter a valid command. Try again!" << endl;
            continue;
        }
    }
}