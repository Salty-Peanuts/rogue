#include <iostream>
#include <cstdlib>
#include <ctime>
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
#include "./npcs/dragon.h"
#include "./floortiles/floor.h"
#include "./floortiles/walls.h"
#include "./floortiles/stair.h"
#include "./floortiles/ceiling.h"
#include "./floortiles/passage.h"
#include "./floortiles/doorway.h"

using namespace std;


GameMap::GameMap(vector<vector<char>> game_map_in, string race): player_race{race} {
    //vector<vector<AbstractObject*>> game_map(col, std::vector<AbstractObject*>(row, nullptr));
    game_map = vector<vector<AbstractObject*>>(col, std::vector<AbstractObject*>(row, nullptr));


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
            //else game_map[j][i] = nullptr;
        }
        
    }
    PlayerCharacter *pc = nullptr;
    player_character = pc;

    object_tiles = vector<vector<AbstractObject*>>(col, std::vector<AbstractObject*>(row, nullptr));

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
    object_tiles[x_1][y_1] = player_character;

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
        int old_x = player_character->getX();
        int old_y = player_character->getY();
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
        deleteObject(object_tiles[old_x][old_y]);
        object_tiles[player_character->getX()][player_character->getY()] = player_character; // moving on object_tiles
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
    if (dir == m_dir["no"]) {
        if ((object_tiles[x][y - 1] != nullptr && object_tiles[x][y - 1]->isTraversible(object)) || (game_map[x][y - 1] != nullptr && game_map[x][y - 1]->isTraversible(object))) return true;
        else return false;
    } else if (dir == m_dir["so"]) {
        if ((object_tiles[x][y + 1] != nullptr && object_tiles[x][y + 1]->isTraversible(object)) || (game_map[x][y + 1] != nullptr && game_map[x][y + 1]->isTraversible(object))) return true;
        else return false;
    } else if (dir == m_dir["we"]) {
        if ((object_tiles[x - 1][y] != nullptr && object_tiles[x - 1][y]->isTraversible(object)) || (game_map[x - 1][y] != nullptr && game_map[x - 1][y]->isTraversible(object))) return true;
        else return false;
    } else if (dir == m_dir["ea"]) {
        if ((object_tiles[x + 1][y] != nullptr && object_tiles[x + 1][y]->isTraversible(object)) || (game_map[x + 1][y] != nullptr && game_map[x + 1][y]->isTraversible(object))) return true;
        else return false;
    } else if (dir == m_dir["ne"]) {
        if ((object_tiles[x + 1][y - 1] != nullptr && object_tiles[x + 1][y - 1]->isTraversible(object)) || (game_map[x + 1][y - 1] != nullptr && game_map[x + 1][y - 1]->isTraversible(object))) return true;
        else return false;
    } else if (dir == m_dir["nw"]) {
        if ((object_tiles[x - 1][y - 1] != nullptr && object_tiles[x - 1][y - 1]->isTraversible(object)) || (game_map[x - 1][y - 1] != nullptr && game_map[x - 1][y - 1]->isTraversible(object))) return true;
        else return false;
    } else if (dir == m_dir["se"]) {
        if ((object_tiles[x + 1][y + 1] != nullptr && object_tiles[x + 1][y + 1]->isTraversible(object)) || (game_map[x + 1][y + 1] != nullptr && game_map[x + 1][y + 1]->isTraversible(object))) return true;
        else return false;
    } else if (dir == m_dir["sw"]) {
        if ((object_tiles[x - 1][y + 1] != nullptr && object_tiles[x - 1][y + 1]->isTraversible(object)) || (game_map[x - 1][y + 1] != nullptr && game_map[x - 1][y + 1]->isTraversible(object))) return true;
        else return false;
    } else {
        return false;
    }
}

void GameMap::usePotion(string potion)
{
    player_character->activatePotion(potion);
}


int GameMap::playerInRange(AbstractObject* npc)
{
    int x = npc->getX();
    int y = npc->getY();
    if (object_tiles[x][y - 1] == player_character) {
        return m_dir["no"];
    } else if (object_tiles[x][y + 1] == player_character) {
        return m_dir["so"];
    } else if (object_tiles[x - 1][y] == player_character) {
        return m_dir["we"];
    } else if (object_tiles[x + 1][y] == player_character) {
        return m_dir["ea"];
    } else if (object_tiles[x + 1][y + 1] == player_character) {
        return m_dir["se"];
    } else if (object_tiles[x + 1][y - 1] == player_character) {
        return m_dir["ne"];
    } else if (object_tiles[x - 1][y + 1] == player_character) {
        return m_dir["sw"];
    } else if (object_tiles[x - 1][y - 1] == player_character) {
        return m_dir["nw"];
    } else {
        return 0;
    }
}

void GameMap::npcLogic() {
    // first look for NPC objects in the object_tiles vector
    for (int y = 0; y < row; ++y) {
        for (int x = 0; x < col; ++x) {
            NPC* npc = dynamic_cast<NPC*>(object_tiles[x][y]);
            if (object_tiles[x][y] == nullptr) {
                continue;
            } else if (npc && playerInRange(object_tiles[x][y])) {
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
        for (int j = 0; j < col; ++i) {
            NPC* npc = dynamic_cast<NPC*>(object_tiles[j][i]);
            if (object_tiles[j][i] == nullptr) {
                continue;
            } else if (npc) {
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
}

bool GameMap::isStair()
{
    int x = 0; 
    int y = 0;
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++i) {
            if (game_map[i][j] != nullptr && game_map[i][j]->getToken() == '\\') {
                x = i;
                y = j;
            }
        }
    }
    if (player_character->getX() == x && player_character->getY() == y) return true;
    return false;
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
                cout << player_character->getToken();
            } else if (object_tiles[j][i] != nullptr && object_tiles[j][i] != player_character) {
                cout << object_tiles[j][i]->getToken();
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
    cout << "                                       ";
    cout << "Floor: " << floor_level << endl;
    cout << "HP: " << player_character->getHP() << endl;
    cout << "Atk: " << player_character->getAtk() << endl;
    cout << "Def: " << player_character->getDef() << endl;
    cout << "Action: " << last_action << endl;
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
