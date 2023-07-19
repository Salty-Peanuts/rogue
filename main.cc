#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;


int main() {
    map<string, int> m_dir;
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

}