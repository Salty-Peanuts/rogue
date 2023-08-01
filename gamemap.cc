#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "gamemap.h"
#include "constants.h"
#include "abstractcharacter.h"
#include "./npcs/NPC.h"
#include "./spawner/itemspawner.h"
#include "./spawner/npcspawner.h"
#include "./spawner/objectspawner.h"
#include "./spawner/stairspawner.h"
#include "./characters/playercharacter.h"
#include "./characters/shade.h"
#include "./characters/goblin.h"
#include "./characters/drow.h"
#include "./characters/vampire.h"
#include "./characters/troll.h"
#include "./items/treasure.h"
#include "./items/potion.h"
#include "./npcs/dragon.h"
#include "./floortiles/floor.h"
#include "./floortiles/walls.h"
#include "./floortiles/stair.h"
#include "./floortiles/ceiling.h"
#include "./floortiles/passage.h"
#include "./floortiles/doorway.h"
#define ESC "\033["
#define BLUE "34"
#define RED "31"
#define YELLOW "33"
#define GREEN "32"
#define RESET "\033[m"
using namespace std;


void translate(vector<vector<AbstractObject *>> &game_map, vector<vector<AbstractObject *>> &object_tiles, PlayerCharacter *player_character, string race, vector<vector<char>> &game_map_in) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (game_map_in[j][i] == '.') {
                game_map[j][i] = new Floor(i, j);
            }
            if (game_map_in[j][i] == '+') {
                game_map[j][i] = new Doorway(i, j);
            }
            if (game_map_in[j][i] == '|') {
                game_map[j][i] = new Walls(i, j);
            }
            if (game_map_in[j][i] == '\\') {
                game_map[j][i] = new Stair(i, j);
            }
            if (game_map_in[j][i] == '-') {
                game_map[j][i] = new Ceiling(i, j);
            }
            if (game_map_in[j][i] == '#') {
                game_map[j][i] = new Passage(i, j);
            }


            // add new stuffs
            if (game_map_in[j][i] == '@') {
                // add new player
                if (race == "s") player_character = new Shade(j, i);
                if (race == "g") player_character = new Goblin(j, i);
                if (race == "d") player_character = new Drow(j, i);
                if (race == "v") player_character = new Vampire(j, i);
                if (race == "t") player_character = new Troll(j, i);
            }
            if (game_map_in[j][i] == '0') {
                ItemSpawner *is = new ItemSpawner("RH");
                object_tiles[j][i] = is->spawn(j, i);
                delete is;
            }
            if (game_map_in[j][i] == '1') {
                ItemSpawner *is = new ItemSpawner("BA");
                object_tiles[j][i] = is->spawn(j, i);
                delete is;
            }
            if (game_map_in[j][i] == '2') {
                ItemSpawner *is = new ItemSpawner("BD");
                object_tiles[j][i] = is->spawn(j, i);
                delete is;
            }
            if (game_map_in[j][i] == '3') {
                ItemSpawner *is = new ItemSpawner("PH");
                object_tiles[j][i] = is->spawn(j, i);
                delete is;
            }
            if (game_map_in[j][i] == '4') {
                ItemSpawner *is = new ItemSpawner("WA");
                object_tiles[j][i] = is->spawn(j, i);
                delete is;
            }
            if (game_map_in[j][i] == '5') {
                ItemSpawner *is = new ItemSpawner("WD");
                object_tiles[j][i] = is->spawn(j, i);
                delete is;
            }
            if (game_map_in[j][i] == '6') {
                ItemSpawner *is = new ItemSpawner("normal");
                object_tiles[j][i] = is->spawn(j, i);
                delete is;
            }
            if (game_map_in[j][i] == '7') {
                ItemSpawner *is = new ItemSpawner("small");
                object_tiles[j][i] = is->spawn(j, i);
                delete is;
            }
            if (game_map_in[j][i] == '8') {
                ItemSpawner *is = new ItemSpawner("merchant");
                object_tiles[j][i] = is->spawn(j, i);
                delete is;
            }
            if (game_map_in[j][i] == '9') {
                ItemSpawner *is = new ItemSpawner("dragon");
                object_tiles[j][i] = is->spawn(j, i);
                delete is;
            }
        }
        
    }
}


// read map layuout from file
void readFile(string file_name, vector<vector<char>> &map_layout, int floor) {
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


GameMap::GameMap(vector<vector<char>> game_map_in, string race, bool given_map, string file_name): player_race{race}, given_map{given_map}, file_name{file_name} {
    //vector<vector<AbstractObject*>> game_map(col, std::vector<AbstractObject*>(row, nullptr));
    game_map = vector<vector<AbstractObject*>>(col, std::vector<AbstractObject*>(row, nullptr));
    
    object_tiles = vector<vector<AbstractObject*>>(col, std::vector<AbstractObject*>(row, nullptr));

    translate(game_map, object_tiles, player_character, race, game_map_in);
    
    if (!given_map) {
        PlayerCharacter *pc = nullptr;
        player_character = pc;
    }

    attack = new CombatManager(0);
    npc_movement = true;
    last_action = "";
    floor_level = 0;
}

GameMap::~GameMap() 
{
    for (auto row : game_map) {
        for (auto object : row) {
            delete object;
        }
    }
    for (auto row : object_tiles) {
        for (auto object : row) {
            delete object;
        }
    }
    delete player_character;
    delete attack;
}

void GameMap::start()
{
    struct Coordinates {
        int x;
        int y;
    };
    vector<Coordinates> all_dots;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (game_map[i][j] != nullptr && game_map[i][j]->getToken() == '.') {
                Coordinates dot;
                dot.x = i;
                dot.y = j;
                all_dots.push_back(dot);
            }
        }
    }

    NPCSpawner * npc_spawner = new NPCSpawner("Human");


    // spawn player
    int ran_num_1 = rand() % all_dots.size();
    int x_1 = all_dots.at(ran_num_1).x;
    int y_1 = all_dots.at(ran_num_1).y;
    all_dots.erase(all_dots.begin() + ran_num_1);
    if (player_race == "s") {
        player_character = new Shade(x_1, y_1); 
    }
    if (player_race == "g") {
        player_character = new Goblin(x_1, y_1); 
    }
    if (player_race == "d") {
        player_character = new Drow(x_1, y_1); 
    }
    if (player_race == "v") {
        player_character = new Vampire(x_1, y_1); 
    }
    if (player_race == "t") {
        player_character = new Troll(x_1, y_1); 
    }
    //object_tiles[x_1][y_1] = player_character;
    player_character->setX(x_1);
    player_character->setY(y_1);

    // spawn stairs;
    
    int ran_num_2 = rand() % all_dots.size();
    int x_2 = all_dots.at(ran_num_2).x;
    int y_2 = all_dots.at(ran_num_2).y;
    all_dots.erase(all_dots.begin() + ran_num_2);
    StairSpawner *sspawner = new StairSpawner();
    object_tiles[x_2][y_2] = sspawner->spawnRandom(x_2, y_2); 

    // spawn enemy
    for (int i = 0; i < 20; i++) {
        int ran_num = rand() % all_dots.size();
        int x = all_dots.at(ran_num).x;
        int y = all_dots.at(ran_num).y;
        all_dots.erase(all_dots.begin() + ran_num);
        object_tiles[x][y] = npc_spawner->spawnRandom(x, y);
    }

    // spawn potion and gold
    for (int i = 0; i < 20; i++) {
        int ran_num = rand() % all_dots.size();
        int x = all_dots.at(ran_num).x;
        int y = all_dots.at(ran_num).y;
        all_dots.erase(all_dots.begin() + ran_num);
        ItemSpawner *is;
        if (i < 10) is = new ItemSpawner("Potion");
        else is = new ItemSpawner("Treasure");
        object_tiles[x][y] = is->spawnRandom(x, y);
        // if spawns a treasure
        if (i >= 10) {
            DragonHoard *dragon_hoard = dynamic_cast<DragonHoard *>(object_tiles[x][y]);
            // if spawns a dragon hoard
            if (dragon_hoard) {
                NPCSpawner *npc_spawner = new NPCSpawner("dragon");
                bool exists = true;
                // loop to find a coordinate that is unoccupied
                while (exists)
                {   
                    int x_temp = x;
                    int y_temp = y;
                    int ran_dir = rand() % 8;
                    if (ran_dir == 0) {
                        x_temp--;
                        y_temp--;
                    }
                    else if (ran_dir == 1) y_temp--;
                    else if (ran_dir == 2) {
                        x_temp--;
                        y_temp++;
                    }
                    else if (ran_dir == 3) x_temp--;
                    else if (ran_dir == 4) x_temp++;
                    else if (ran_dir == 5) {
                        x_temp--;
                        y_temp++;
                    }
                    else if (ran_dir == 6) y_temp++;
                    else if (ran_dir == 7) {
                        x_temp++;
                        y_temp++;
                    }
                    // loop through the all_dots to check if that point is valid
                    int all_dots_size = all_dots.size();
                    for (int z = 0; z < all_dots_size; z++) {
                        Coordinates temp = all_dots[z];
                        if (temp.x == x_temp && temp.y == y_temp) {
                            exists = false;
                            x = x_temp;
                            y = y_temp;
                            break;
                        }
                    }
                    break;
                }
                object_tiles[x][y] = npc_spawner->spawn(x, y);
                Dragon *dragon = dynamic_cast<Dragon *>(object_tiles[x][y]);
                dragon->assignDragonHoard(dragon_hoard);
                delete npc_spawner;
            }
            delete dragon_hoard;
        }
        delete is;
    }
    delete npc_spawner;
}

void GameMap::addObject(AbstractObject* object)
{
    int x = object->getX();
    int y = object->getY();
    object_tiles[x][y] = object;
}

void GameMap::deleteObject(AbstractObject* object)
{
    int x = object->getX();
    int y = object->getY();
    delete object_tiles[x][y];
    object_tiles[x][y] = nullptr;
}

bool GameMap::moveCharacter(int dir)
{

    if (validMove(player_character, dir)) {
        //int old_x = player_character->getX();
        //int old_y = player_character->getY();
        player_character->move(dir);
        string obj = "";
        if (object_tiles[player_character->getX()][player_character->getY()] != nullptr) {
            obj = object_tiles[player_character->getX()][player_character->getY()]->identify();
        }
        if (obj == "NormalPile" || obj == "SmallPile" || obj == "MerchantHoard") {
            Treasure *treasure = dynamic_cast<Treasure *>(object_tiles[player_character->getX()][player_character->getY()]);
            if (!treasure) {
                return false;
            }
            last_action += "You picked up" + to_string(treasure->getValue()) + " gold. ";
            player_character->updateGold(treasure->getValue());
            deleteObject(object_tiles[player_character->getX()][player_character->getY()]);
        } else if (obj == "DragonHoard") {
            DragonHoard *dragonhoard = dynamic_cast<DragonHoard *>(object_tiles[player_character->getX()][player_character->getY()]);
            if (!dragonhoard) {
                return false;
            }
            if (!dragonhoard->isDragonAlive()) {
                last_action += "You picked up" + to_string(dragonhoard->getValue()) + " gold. ";
                player_character->updateGold(dragonhoard->getValue());
                deleteObject(object_tiles[player_character->getX()][player_character->getY()]);
            } else {
                last_action += "You cannot pick up the dragon hoard. ";
            }
        }
        //deleteObject(object_tiles[old_x][old_y]);
        //object_tiles[player_character->getX()][player_character->getY()] = player_character; // moving on object_tiles
        auto dir_iter = m_dir.begin();
        while (dir_iter != m_dir.end()) {
            if (dir_iter->second == dir) {
                last_action += "The player has moved ";
                last_action += dir_iter->first;
                break;
            }
            dir_iter++;
        }
        return true;
    } else {
        return false;
    }
}

bool GameMap::validMove(AbstractObject* object, int dir)
{
    int x = object->getX();
    int y = object->getY();
    
    if (dir == m_dir["no"]) y--;
    else if (dir == m_dir["so"]) y++;
    else if (dir == m_dir["ea"]) x++;
    else if (dir == m_dir["we"]) x--;
    else if (dir == m_dir["nw"]) {
        x--;
        y--;
    }
    else if (dir == m_dir["ne"]) {
        y--;
        x++;
    }
    else if (dir == m_dir["sw"]) {
        y++;
        x--;
    }
    else if (dir == m_dir["se"]) {
        x++;
        y++;
    }

    if (object->identify() != "PlayerCharacter") {
        if (x == player_character->getX() && y == player_character->getY()) return false;
    }


    if ((object_tiles[x][y] == nullptr || object_tiles[x][y]->isTraversible(object)) && 
                (game_map[x][y] != nullptr && game_map[x][y]->isTraversible(object)))return true;
    else return false;

    /*
    if (dir == m_dir["no"]) {
        if ((object_tiles[x][y - 1] != nullptr && object_tiles[x][y - 1]->isTraversible(object)) || 
                (game_map[x][y - 1] != nullptr && game_map[x][y - 1]->isTraversible(object)) ||
                (x != player_character->getX() && (y - 1) != player_character->getY())) return true;
        else return false;
    } else if (dir == m_dir["so"]) {
        if ((object_tiles[x][y + 1] != nullptr && object_tiles[x][y + 1]->isTraversible(object)) || 
            (game_map[x][y + 1] != nullptr && game_map[x][y + 1]->isTraversible(object)) ||
            (x != player_character->getX() && (y + 1) != player_character->getY())) return true;
        else return false;
    } else if (dir == m_dir["we"]) {
        if ((object_tiles[x - 1][y] != nullptr && object_tiles[x - 1][y]->isTraversible(object)) || 
            (game_map[x - 1][y] != nullptr && game_map[x - 1][y]->isTraversible(object)) ||
            ((x - 1) != player_character->getX() && y != player_character->getY())) return true;
        else return false;
    } else if (dir == m_dir["ea"]) {
        if ((object_tiles[x + 1][y] != nullptr && object_tiles[x + 1][y]->isTraversible(object)) || 
            (game_map[x + 1][y] != nullptr && game_map[x + 1][y]->isTraversible(object)) ||
            ((x + 1) != player_character->getX() && y != player_character->getY())) return true;
        else return false;
    } else if (dir == m_dir["ne"]) {
        if ((object_tiles[x + 1][y - 1] != nullptr && object_tiles[x + 1][y - 1]->isTraversible(object)) || 
            (game_map[x + 1][y - 1] != nullptr && game_map[x + 1][y - 1]->isTraversible(object)) ||
            ((x + 1) != player_character->getX() && (y - 1) != player_character->getY())) return true;
        else return false;
    } else if (dir == m_dir["nw"]) {
        if ((object_tiles[x - 1][y - 1] != nullptr && object_tiles[x - 1][y - 1]->isTraversible(object)) || 
            (game_map[x - 1][y - 1] != nullptr && game_map[x - 1][y - 1]->isTraversible(object)) ||
            ((x - 1) != player_character->getX() && (y - 1) != player_character->getY())) return true;
        else return false;
    } else if (dir == m_dir["se"]) {
        if ((object_tiles[x + 1][y + 1] != nullptr && object_tiles[x + 1][y + 1]->isTraversible(object)) || 
            (game_map[x + 1][y + 1] != nullptr && game_map[x + 1][y + 1]->isTraversible(object)) || 
            ((x + 1) != player_character->getX() && (y + 1) != player_character->getY())) return true;
        else return false;
    } else if (dir == m_dir["sw"]) {
        if ((object_tiles[x - 1][y + 1] != nullptr && object_tiles[x - 1][y + 1]->isTraversible(object)) || 
            (game_map[x - 1][y + 1] != nullptr && game_map[x - 1][y + 1]->isTraversible(object)) ||
            ((x - 1) != player_character->getX() && (y + 1) != player_character->getY())) return true;
        else return false;
    } else {
        return false;
    }
    */
}

void GameMap::usePotion(string potion)
{
    player_character->activatePotion(potion);
}


int GameMap::playerInRange(AbstractObject* npc)
{
    int x = npc->getX();
    int y = npc->getY();
    int p_x = player_character->getX();
    int p_y = player_character->getY();
    if (p_x == x && p_y == y - 1) {
        return m_dir["no"];
    } else if (p_x == x && p_y == y + 1) {
        return m_dir["so"];
    } else if (p_x == x - 1 && p_y == y) {
        return m_dir["we"];
    } else if (p_x == x + 1 && p_y == y) {
        return m_dir["ea"];
    } else if (p_x == x + 1 && p_y == y + 1) {
        return m_dir["se"];
    } else if (p_x == x + 1 && p_y == y - 1) {
        return m_dir["ne"];
    } else if (p_x == x - 1 && p_y == y + 1) {
        return m_dir["sw"];
    } else if (p_x == x - 1 && p_y == y - 1) {
        return m_dir["nw"];
    } else {
        return 0;
    }
}

void GameMap::npcLogic() {
    // first look for NPC objects in the object_tiles vector
    for (int y = 0; y < row; ++y) {
        for (int x = 0; x < col; ++x) {
            NPC* npc;
            if (object_tiles[x][y]) npc = dynamic_cast<NPC*>(object_tiles[x][y]);
            else continue;
            if (npc && playerInRange(object_tiles[x][y])) {
                // attack
                if (npc->isHostile()) {
                    attack->setDirection(playerInRange(object_tiles[x][y]));
                    attack->NPCAttack(this, npc, player_character);
                }
            } else if (npc && !playerInRange(object_tiles[x][y]) && npc_movement) {
                // check if npc was moved
                if (npc->wasMoved()) {
                    continue;
                }
                // move in a random direction
                bool success = false;
                while (!success) {
                    int random_dir = 1 + (rand() % 8);
                    if (!npc->wasMoved() && validMove(npc, random_dir)) {
                        int old_x = npc->getX();
                        int old_y = npc->getY();
                        npc->move(random_dir);
                        npc->setMoved(true);
                        object_tiles[old_x][old_y] = nullptr;
                        object_tiles[npc->getX()][npc->getY()] = npc; // moving on object_tiles
                        success = true;
                    }
                } 
            }
        }
    }

    
    // need some way to unset all the wasMoved flags
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {

            if (object_tiles[j][i] == nullptr) continue; 

            
            NPC* npc = dynamic_cast<NPC*>(object_tiles[j][i]);
            if (npc) {
                npc->setMoved(false);
            }
        }
    }


}

void GameMap::playerAtk(int dir)
{
    attack->setDirection(dir);
    attack->playerAttack(this, player_character);
}

// revise
void GameMap::reset() { 
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++i) {
            if (object_tiles[i][j] == nullptr) {
                continue;
            }
            else { 
                delete object_tiles[i][j];
                object_tiles[i][j] = nullptr;
            }
        }
    }
    attack->setDirection(0);
    last_action = "";
    if (given_map) {
        vector<vector<char>> game_map_in;
        readFile(file_name, game_map_in, floor_level);
        translate(game_map, object_tiles, player_character, player_race, game_map_in);
    }
}

bool GameMap::isStair()
{
    int x = player_character->getX(); 
    int y = player_character->getY();
    if (object_tiles[x][y] != nullptr && object_tiles[x][y]->getToken() == '\\') {
        return true;
    } else {
        return false;
    }
    /*
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++i) {
            // issue here -----------------------------------------------------------------------
            if (object_tiles[i][j] != nullptr && object_tiles[i][j]->getToken() == '\\') {
                x = i;
                y = j;
            }
        }
    }
    if (player_character->getX() == x && player_character->getY() == y) return true;
    return false;
    */
}

// void GameMap::update() { notifyObservers(); }

void GameMap::changeNPCmovement() {
    if (npc_movement) npc_movement = false;
    else npc_movement = true;
}

bool GameMap::isDead() {
    if (player_character->getHP() <= 0) {
        return true;
    }
    return false;
}

void GameMap::printMap() {
     for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (i == player_character->getY() && j == player_character->getX()) {
                cout << ESC << BLUE << "m" << player_character->getToken() << ESC << RESET; // print blue
            } else if (object_tiles[j][i] != nullptr) {
                Treasure* t = dynamic_cast<Treasure*>(object_tiles[j][i]);
                Potion* p = dynamic_cast<Potion*>(object_tiles[j][i]);
                NPC* npc = dynamic_cast<NPC*>(object_tiles[j][i]);
                Stair* s = dynamic_cast<Stair*>(object_tiles[j][i]);
                if (t) {
                    // print yellow
                    cout << ESC << YELLOW << "m" << t->getToken() << ESC << RESET;
                } else if (p) {
                    // print green
                    cout << ESC << GREEN << "m" << p->getToken() << ESC << RESET;
                } else if (npc) {
                    // print red
                    cout << ESC << RED << "m" << npc->getToken() << ESC << RESET;
                } else if (s) {
                    // print blue
                    cout << ESC << BLUE << "m" << s->getToken() << ESC << RESET;
                } else {
                    cout << object_tiles[j][i]->getToken();
                }
            }
            else if (game_map[j][i] == nullptr) {
                cout << " ";
            } else {
                cout << game_map[j][i]->getToken();
            }
        }
        cout << endl;
     }

    cout << "Race: " << player_character->getRace() << " ";
    cout << "Gold: " << player_character->getGold() << " ";
    cout << "                                                  ";
    cout << "Floor: " << floor_level << endl;
    cout << "HP: " << player_character->getHP() << endl;
    cout << "Atk: " << player_character->getAtk() << endl;
    cout << "Def: " << player_character->getDef() << endl;
    cout << "Action: " << last_action << endl;
}

void GameMap::resetAction() {
    last_action = "";
}


// Getters

int GameMap::getLevel() const { return floor_level; }

string GameMap::getLastAction() const { return last_action; }

char GameMap::gameMapAt(int x, int y) const { return game_map[x][y]->getToken(); }

PlayerCharacter* GameMap::getPlayerCharacter() const { return player_character; }

AbstractObject* GameMap::objectTilesAt(int x, int y) const { return object_tiles[x][y]; }

void GameMap::addAction(string action) { last_action += action; }

int GameMap::getScore() const {
    if (player_character->getRace() == "Shade") return player_character->getGold() * 1.5;
    else return player_character->getGold();
}

bool GameMap::isGivenMap() const {return given_map;}
