#include <vector>
#include <string>
#include <map>
#include "gamemap.h"
using namespace std;

GameMap::GameMap(vector<vector<char>> game_map,
        vector<AbstractObjects*> object_tiles,
        char player_race,
        PlayerCharacter* player_character,
        CombatManager* attack,
        map<string, int> direction_map,
        vector<Chamber*> chambers,
        bool npc_movement): game_map{game_map}, tiles_NPC{tiles_NPC}
                            player_race{player_race}, player_character{player_character},
                            attack{attack}, direction_map{direction_map},
                            chambers{chambers}, npc_movement{npc_movement} {}
GameMap::~GameMap() 
{
    for (auto i : object_tiles) {
        delete i;
    }
    for (auto i : chambers) {
        delete i;
    }
    delete player_character;
    delete attack;
}

void GameMap::start(PlayerCharacter* pc)
{

}

void GameMap::addObject(AbstractObject* object)
{
    object_tiles.emplace_back(object);
}

void GameMap::deleteObject(AbstractObject* object)
{
    for (int i = 0; i < object_tiles.size(); ++i) {
        if (object_tiles[i] == object) {
            object_tiles.erase(i);
            break;
        }
    }
}

void GameMap::moveCharacter(PlayerCharacter* pc, int dir)
{
    if (validMove(pc, dir)) {

    }
}

bool GameMap::validMove(AbstractObject* object, int dir)
{
    int x = object->getX();
    int y = object->getY();
    switch (dir) {
        case direction_map["no"]:
            return game_map[x][y - 1] == '.' || game_map[x][y - 1] == '+' || game_map[x][y - 1] == '#';
        case direction_map["so"]:
            return game_map[x][y + 1] == '.' || game_map[x][y + 1] == '+' || game_map[x][y + 1] == '#';
        case direction_map["ea"]:
            return game_map[x + 1][y] == '.' || game_map[x + 1][y] == '+' || game_map[x + 1][y] == '#';
        case direction_map["we"]:
            return game_map[x - 1][y] == '.' || game_map[x - 1][y] == '+' || game_map[x - 1][y] == '#';
        case direction_map["ne"]:
            return game_map[x + 1][y - 1] == '.' || game_map[x + 1][y - 1] == '+' || game_map[x + 1][y - 1] == '#';
        case direction_map["nw"]:
            return game_map[x - 1][y - 1] == '.' || game_map[x - 1][y - 1] == '+' || game_map[x - 1][y - 1] == '#';
        case direction_map["se"]:
            return game_map[x + 1][y + 1] == '.' || game_map[x + 1][y + 1] == '+' || game_map[x + 1][y + 1] == '#';
        case direction_map["sw"]:
            return game_map[x - 1][y + 1] == '.' || game_map[x - 1][y + 1] == '+' || game_map[x - 1][y + 1] == '#';
        default:
            return false;
    }
}

void GameMap::usePotion(PlayerCharacter&)
{

}
