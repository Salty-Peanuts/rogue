#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <controller.h>
#include <map>


using namespace std;
const int col = 79;
const int row = 25;
const map<string, int> m_dir{{"nw", 1},
                        {"no", 2},
                        {"ne", 3}, 
                        {"we", 4},
                        {"ea", 5},
                        {"sw", 6},
                        {"so", 7},
                        {"se", 8}};


// read map layuout from file
void readFile(string file_name, vector<vector<char>> map_layout) {
    string str;
    ifstream input (file_name);
    for (int i = 0; i < col; i++) {
        getline(input, str);
        for (int j = 0; j < row; j++) {
            map_layout.at(i).push_back(str[j]);
        }
    }
}

// print out the map
void printMap(vector<vector<char>> map_layout) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout << (map_layout.at(i)).at(j);
        }
    }
}

int main() {

    
    vector<vector<char>> map_layout;
    readFile("cc3k-emptySingleFloor.txt", map_layout);
    printMap(map_layout);

    // ask to choose race
    while (true) {
        string cmd;
        do {
            cout << "Welcome to CC3K" << endl << "Please choose a race to start:" << endl
            << "Shade: s" << endl << "Goblin: g" << endl << "Drow: d" << endl << "Vampire: v" << endl << "Troll: t";
            cin >> cmd;
        } while (cmd != "s" || cmd != "g" || cmd != "d" || cmd != "t" || cmd != "v");

        // start game
        Controller c = new Controller(map_layout, cmd);
        string result = c.run_game();

        // check the ending state of the game
        if (result == "restart") {
            continue;
        }
        else if (result == "quit") {
            break;
        }
        else if (result == "won") {

        }
        else if (result == "lost") {

        }

        // ask if the player wants to restart
        do {
            cout << "Do you want to replay (r) or quit (q)?" << endl;
            cin >> cmd;
        } while (cmd != "r" || cmd != "q");

        if (cmd == "r") {
            continue;
        }
        else break;
    }




    /*

    m_dir["nw"] = 0;
    m_dir["no"] = 1;
    m_dir["ne"] = 2;
    m_dir["we"] = 3;
    m_dir["ea"] = 4;
    m_dir["sw"] = 5;
    m_dir["so"] = 6;
    m_dir["se"] = 7;
    // read in map
    string str;
    cin >> str;
    Map map = new Map(str);

    // 1st loop: whole program
    while (cin >> str) {
        // if user types q to quit
        if (str == "q") break;
        // 2nd loop: each game
        while (cin >> str) {
            // if user types r to restart the game
            if (str == "r") {
                continue;
            }
            string command;
            cin >> command;
            PlayerCharacter pc;
            // select race
            if (command == "s") pc = new Shade();
            else if (command == "d") pc = new Drow();
            else if (command == "v") pc = new Vampire();
            else if (command == "g") pc = new Goblin();
            else pc = new Troll();

            // each floor
            for (int i = 0; i < 5; i++) {
                // start spawning and setting the map
                map.start(pc);
                while (cin >> command) {
                    // switch npc moving state
                    if (command == "f") {
                        map.switchState();
                    }
                    if (command == "r") {
                        break;
                    }
                    // check potion and if the player is standing on a treasure (9 instead of 8 boxes)
                    for (int i = 0; i < 9; i++) {
                        map.checkPotion(pc, i);
                    }
                    // move
                    if (command == "nw" || command == "no" || command == "ne" || command == "we" ||
                        command == "ea" || command == "sw" || command == "so" || command == "se" ) {
                        int dir = m_dir[command];
                        if (map.validMove(pc, dir)) {
                            // if reaches stair, reset map and move to the next floor
                            if (map.isStairs(pc, dir)) {
                                if (i == 4) break;
                                map.reset();
                                continue;
                            }
                            pc.move(dir);
                            map.moveCharacter(pc, dir);
                            map.moveNPCs();
                        }
                    }
                    // attack
                    if (command == "a") {
                        cin << command;
                        int dir = m_dir[command];
                        NPC *enemy = map.getEnemy(pc, dir);
                        CombatManager combat_manager = new CombatManger(map, np, enemy);
                        combat_manager.combat();
                        map.moveNPCs();
                    }
                }
            }
        }
    }
    */

}