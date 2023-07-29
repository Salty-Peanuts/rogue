#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include "gamemap.h"
#include "constants.h"
#include "./npcs/NPC.h"
#include "abstractcharacter.h"
#include "shade.h"
#include "drow.h"
#include "goblin.h"
#include "troll.h"
#include "vampire.h"
using namespace std;


GameMap::GameMap(vector<vector<char>> game_map, string race): game_map{game_map} {
    PlayerCharacter *pc;
    if (race == "s") {
        pc = new Shade(0, 0);
    }
    if (race == "d") {
        pc = new Drow(0, 0);
    }
    if (race == "v") {
        pc = new Vampire(0, 0);
    }
    if (race == "g") {
        pc = new Goblin(0, 0);
    }
    if (race == "t") {
        pc = new Troll(0, 0);
    }

    player_character = pc;
    object_tiles = {};
    attack = new CombatManager(0);
    Chamber = {};
    npc_movement = true;
    last_action = "";
    floor_level = 0;
    width = game_map.size();
    height = game_map[0].size();
}

/*
GameMap::GameMap(vector<vector<char>> game_map,
                 string race): game_map{game_map} {
    // if the object_tiles vector is empty, then we need to initialize it to a set size
    if (object_tiles.empty()) {
        // initialize the object_tiles vector to the same size as the game_map
        object_tiles = vector<vector<AbstractObject*>> (game_map.size(), vector<AbstractObject*> (game_map[0].size(), nullptr));
    }
}
*/

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
    for (auto chamber : chambers) {
        delete chamber;
    }
}

void GameMap::start()
{
    // spawn stuff in map
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
    int x = player_character->getX();
    int y = player_character->getY();
    if (validMove(player_character, dir)) {
        player_character->move(dir);
        return true;
    } else {
        return false;
    }
}

bool GameMap::validMove(AbstractObject* object, int dir)
{
    int x = object->getX();
    int y = object->getY();
    PlayerCharacter* player = dynamic_cast<PlayerCharacter*>(object);
    NPC* npc = dynamic_cast<NPC*>(object);
    if (player) {
        // check collision for player
        switch (dir) {
             
        }
    } else if (npc) {
        // check collision for NPC
    } else {
        return false;
    }
}

void GameMap::usePotion(string potion)
{
    player_character->usePotion(potion);
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

/*
void GameMap::moveNPC()
{
    srand(time(0));
    if (npc_movement) {

        int random_dir = 1 + (rand() % 8);

    }
}
*/

void GameMap::npcLogic() {
    // first look for NPC objects in the object_tiles vector
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++i) {
            if (object_tiles[i][j] == nullptr) {
                continue;
            } else if (object_tiles[i][j]->identify() == "NPC" && playerInRange(object_tiles[i][j])) {
                // attack
                attack->setDirection(playerInRange(object_tiles[i][j]));
                attack->NPCAttack(*this, object_tiles[i][j], player_character);
            } else if (object_tiles[i][j]->identify() == "NPC" && !playerInRange(object_tiles[i][j]) && npc_movement) {
                NPC* npc = dynamic_cast<NPC*>(object_tiles[i][j]);
                // check if npc was moved
                if (npc->wasMoved()) {
                    continue;
                }
                // move in a random direction
                bool success = false;
                while (!success) {
                    srand(time(0));
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
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++i) {
            if (object_tiles[i][j] == nullptr) {
                continue;
            } else if (object_tiles[i][j]->identify() == "NPC") {
                NPC* npc = dynamic_cast<NPC*>(object_tiles[i][j]);
                npc->setMoved(false);
            }
        }
    }
}

bool playerAtk(int dir)
{
    attack->setDirection(dir);
    attack->playerAttack(*this, player_character);
}

void GameMap::reset() { 
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++i) {
            if (object_tiles[i][j] == nullptr) {
                continue;
            } else if (object_tiles[i][j]->identify() == "NPC") {
                delete object_tiles[i][j];
                object_tiles[i][j] = nullptr;
            }
        }
    }
    attack->setDirection(0);
}

bool GameMap::isStair()
{
    
}

void GameMap::update() { notifyObservers(); }

void GameMap::changeNPCmovement() {
    if (npc_movement) npc_movement = false;
    else npc_movement = true;
}

// move the object to the x, y coordinate
void GameMap::quickMove(AbstractObject *abObj, int x, int y) {
    abObj->setX(x);
    abObj->setY(y);
}

// Getters

int GameMap::getLevel() const { return floor_level; }

string getLastAction() const { return last_action; }

int GameMap::getWidth() const { return game_map.size(); }

int GameMap::getHeight() const { return game_map[0].size(); }

char GameMap::gameMapAt(int x, int y) const { return game_map[x][y]; }

PlayerCharacter* GameMap::getPlayerCharacter() const { return player_character; }

AbstractObject* GameMap::objectTilesAt(int x, int y) const { return object_tiles[x][y]; }
