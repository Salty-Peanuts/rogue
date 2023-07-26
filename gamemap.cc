#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include "gamemap.h"
#include "./npcs/NPC.h"
using namespace std;

GameMap::GameMap(vector<vector<AbstractObject*>> game_map,
        vector<vector<AbstractObject*>> object_tiles = {},
        PlayerCharacter* player_character,
        CombatManager* attack,
        map<string, int> direction_map,
        vector<Chamber*> chambers,
        bool npc_movement,
        int floor_level): game_map{game_map}, player_character{player_character},
                            attack{attack}, direction_map{direction_map},
                            chambers{chambers}, npc_movement{npc_movement}, floor_level{floor_level}
{
    // if the object_tiles vector is empty, then we need to initialize it to a set size
    if (object_tiles.empty()) {
        // initialize the object_tiles vector to the same size as the game_map
        object_tiles = vector<vector<AbstractObject*>> (game_map.size(), vector<AbstractObject*> (game_map[0].size(), nullptr));
    }
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
    for (auto chamber : chambers) {
        delete chamber;
    }
}

void GameMap::start()
{

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
    object_tiles[x][y] = nullptr;
}

// change this method's return type to bool? true if valid and false otherwise
void GameMap::moveCharacter(int dir)
{
    int x = player_character->getX();
    int y = player_character->getY();
    if (validMove(player_character, dir)) {
        if (dir == direction_map["no"]) {
            player_character->setX(x);
            player_character->setY(y - 1);
        } else if (dir == direction_map["so"]) {
            player_character->setX(x);
            player_character->setY(y + 1);
        } else if (dir == direction_map["ea"]) {
            player_character->setX(x + 1);
            player_character->setY(y);
        } else if (dir == direction_map["we"]) {
            player_character->setX(x - 1);
            player_character->setY(y);
        } else if (dir == direction_map["ne"]) {
            player_character->setX(x + 1);
            player_character->setY(y - 1);
        } else if (dir == direction_map["nw"]) {
            player_character->setX(x - 1);
            player_character->setY(y - 1);
        } else if (dir == direction_map["se"]) {
            player_character->setX(x + 1);
            player_character->setY(y + 1);
        } else if (dir == direction_map["sw"]) {
            player_character->setX(x - 1);
            player_character->setY(y + 1);
        }
    }
}

bool GameMap::validMove(AbstractObject* object, int dir)
{
    int x = object->getX();
    int y = object->getY();
}

void GameMap::usePotion(string potion)
{
    player_character->usePotion(potion);
}

bool GameMap::playerInRange(AbstractObject* npc)
{
    int x = npc->getX();
    int y = npc->getY();
    if (npc->isHostile() && object_tiles[x][y - 1] == player_character) {
        return true;
    } else if (npc->isHostile() && object_tiles[x][y - 1] == player_character) {
        return true;
    } else if (npc->hostile && object_tiles[x][y - 1] == player_character) {
        return true;
    } else if (npc->hostile && object_tiles[x][y - 1] == player_character) {
        return true;
    } else if (npc->hostile && object_tiles[x][y - 1] == player_character) {
        return true;
    } else {
        return false;
    }
}

void GameMap::moveNPC()
{
    srand(time(0));
    if (npc_movement) {

        int random_dir = 1 + (rand() % 8);

    }
}

void GameMap::reset()
{
    object_tiles.clear();
}

bool GameMap::isStair()
{
    
}

void GameMap::update()
{
    notifyObservers();
}

int GameMap::getLevel() 
{
    return floor_level;
}
