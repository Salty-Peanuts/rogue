#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include "gamemap.h"
#include "constants.h"
#include "./npcs/NPC.h"
#include "abstractcharacter.h"
using namespace std;


GameMap::GameMap(vector<vector<char>> game_map, string race): game_map{game_map} {
    PlayerCharacter *pc = new PlayerCharacter(race);
    player_character = pc;
    object_tiles = {};
    attack = nullptr;
    Chamber = {};
    npc_movement = true;
    last_action = "";
    floor_level = 0;
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
    for (int i = 0; i < object_tiles.size(); ++i) {
        for (int j = 0; j < object_tiles[i].size(); ++i) {
            if (object_tiles[i][j] == nullptr) {
                continue;
            } else if (object_tiles[i][j]->identify() == "NPC" && playerInRange(object_tiles[i][j])) {
                // attack
                delete attack;
                attack = new CombatManager(playerInRange(object_tiles[i][j]));
                attack->NPCAttack(*this, object_tiles[i][j], player_character);
            } else if (object_tiles[i][j]->identify() == "NPC" && !playerInRange(object_tiles[i][j])) {
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
                        npc->move(random_dir);
                        success = true;
                    }
                } // need some way to unset all the wasMoved flags
            }
        }
    }
    
}

bool playerAtk(int dir)
{

}

void GameMap::reset() { object_tiles.clear(); }

bool GameMap::isStair()
{
    
}

void GameMap::update() { notifyObservers(); }

void GameMap::changeNPCmovement() {
    if (npc_movement) npc_movement = false;
    else npc_movement = true;
}

// Getters

int GameMap::getLevel() const { return floor_level; }

string getLastAction() const { return last_action; }

int GameMap::getWidth() const { return game_map.size(); }

int GameMap::getHeight() const { return game_map[0].size(); }

char GameMap::gameMapAt(int x, int y) const { return game_map[x][y]; }

PlayerCharacter* GameMap::getPlayerCharacter() const { return player_character; }

AbstractObject* GameMap::objectTilesAt(int x, int y) const { return object_tiles[x][y]; }
