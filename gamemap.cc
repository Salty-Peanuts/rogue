#include <vector>
#include <string>
#include <map>
#include "gamemap.h"
using namespace std;

GameMap::GameMap(vector<vector<AbstractObject*>> game_map,
        vector<vector<AbstractObject*>> object_tiles = {},
        PlayerCharacter* player_character,
        CombatManager* attack,
        map<string, int> direction_map,
        vector<Chamber*> chambers,
        bool npc_movement): game_map{game_map}, player_character{player_character},
                            attack{attack}, direction_map{direction_map},
                            chambers{chambers}, npc_movement{npc_movement} 
{
    // if the object_tiles vector is empty, then we need to initialize it to a set size
    if (object_tiles.empty()) {
        // initialize the object_tiles vector to the same size as the game_map
        object_tiles = vector<vector<AbstractObject*>> (game_map.size(), vector<AbstractObject*> (game_map[0].size(), nullptr));
    }
}

GameMap::~GameMap() 
{

}

void GameMap::start()
{

}

void GameMap::addObject(AbstractObject* object)
{

}

void GameMap::deleteObject(AbstractObject* object)
{
    
}

void GameMap::moveCharacter(int dir)
{
    if (validMove(player_character, dir)) {
        int x = player_character->getX();
        int y = player_character->getY();
        switch (dir) {
            case direction_map["no"]:
                player_character->y = player_character->getY() - 1;
                game_map[x][y] = '.';
                break;
            case direction_map["so"]:
                player_character->y = player_character->getY() + 1;
                game_map[x][y] = '.';
                break;
            case direction_map["ea"]:
                player_character->x = player_character->getX() + 1;
                game_map[x][y] = '.';
                break;
            case direction_map["we"]:
                player_character->x = player_character->getX() - 1;
                game_map[x][y] = '.';
                break;
            case direction_map["ne"]:
                player_character->x = player_character->getX() + 1;
                player_character->y = player_character->getY() - 1;
                game_map[x][y] = '.';
                break;
            case direction_map["nw"]:
                player_character->x = player_character->getX() - 1;
                player_character->y = player_character->getY() - 1;
                game_map[x][y] = '.';
                break;
            case direction_map["se"]:
                player_character->x = player_character->getX() + 1;
                player_character->y = player_character->getY() + 1;
                game_map[x][y] = '.';
                break;
            case direction_map["sw"]:
                player_character->x = player_character->getX() - 1;
                player_character->y = player_character->getY() + 1;
                game_map[x][y] = '.';
                break;
        }
    }
}

bool GameMap::validMove(AbstractObject* object, int dir)
{
    int x = object->getX();
    int y = object->getY();
    switch (dir) {
        case direction_map["no"]:
            return game_map[x][y - 1] == '.' || game_map[x][y - 1] == '+' || game_map[x][y - 1] == '#' || game_map[x][y - 1] == 'G';
        case direction_map["so"]:
            return game_map[x][y + 1] == '.' || game_map[x][y + 1] == '+' || game_map[x][y + 1] == '#' || game_map[x][y + 1] == 'G';
        case direction_map["ea"]:
            return game_map[x + 1][y] == '.' || game_map[x + 1][y] == '+' || game_map[x + 1][y] == '#' || game_map[x + 1][y] == 'G';
        case direction_map["we"]:
            return game_map[x - 1][y] == '.' || game_map[x - 1][y] == '+' || game_map[x - 1][y] == '#' || game_map[x - 1][y] == 'G';
        case direction_map["ne"]:
            return game_map[x + 1][y - 1] == '.' || game_map[x + 1][y - 1] == '+' || game_map[x + 1][y - 1] == '#' || game_map[x + 1][y - 1] == 'G';
        case direction_map["nw"]:
            return game_map[x - 1][y - 1] == '.' || game_map[x - 1][y - 1] == '+' || game_map[x - 1][y - 1] == '#' || game_map[x - 1][y - 1] == 'G';
        case direction_map["se"]:
            return game_map[x + 1][y + 1] == '.' || game_map[x + 1][y + 1] == '+' || game_map[x + 1][y + 1] == '#' || game_map[x + 1][y + 1] == 'G';
        case direction_map["sw"]:
            return game_map[x - 1][y + 1] == '.' || game_map[x - 1][y + 1] == '+' || game_map[x - 1][y + 1] == '#' || game_map[x - 1][y + 1] == 'G';
        default:
            return false;
    }
}

void GameMap::usePotion(PlayerCharacter&)
{

}

void GameMap::moveNPC()
{

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
