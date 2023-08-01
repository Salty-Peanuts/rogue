#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include <string>
#include <map>
#include "combatmanager.h"
#include "./characters/playercharacter.h"
#include "abstractobject.h"
#include "chamber.h"
using namespace std;

class CombatManager;

class GameMap
{
    vector<vector<AbstractObject*>> game_map;
    string player_race;
    vector<vector<AbstractObject*>> object_tiles;
    PlayerCharacter* player_character;
    CombatManager* attack;
    bool npc_movement;
    string last_action;
    int floor_level;
    bool given_map;
    string file_name;

 public:
    GameMap(vector<vector<char>> game_map, string race, bool given_map, string file_name);
    ~GameMap();
    void start();
    void addObject(AbstractObject* object);
    void deleteObject(AbstractObject* object);
    bool moveCharacter(int dir);
    bool validMove(AbstractObject* object, int dir);
    bool usePotion(int dir);
    void npcLogic();
    void playerAtk(int dir);
    int playerInRange(AbstractObject* object);
    void reset();
    bool isStair();
    //void update();
    void changeNPCmovement();
    bool isDead();
    void printMap();
    void resetAction();
    void trollSpecialAbility();

    // Getters
    int getLevel() const;
    string getLastAction() const;
    char gameMapAt(int x, int y) const;
    AbstractObject* objectTilesAt(int x, int y) const;
    PlayerCharacter* getPlayerCharacter() const;
    void addAction(string action);
    int getScore() const;
    bool isGivenMap() const;
};

#endif
