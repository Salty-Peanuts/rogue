#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include <string>
#include <map>
#include "./observer/subject.h"
#include "combatmanager.h"
#include "./characters/playercharacter.h"
#include "abstractobject.h"
#include "chamber.h"
using namespace std;

class GameMap : public Subject
{
    vector<vector<char>> game_map;
    string player_race;
    vector<vector<AbstractObject*>> object_tiles;
    PlayerCharacter* player_character;
    CombatManager* attack;
    vector<Chamber*> chambers;
    bool npc_movement;
    string last_action;
    int floor_level;

 public:
    GameMap(vector<vector<char>> game_map, string race);
    ~GameMap();
    void start();
    void addObject(AbstractObject* object);
    void deleteObject(AbstractObject* object);
    bool moveCharacter(int dir);
    bool validMove(AbstractObject* object, int dir);
    void usePotion(string potion);
    void npcLogic();
    bool playerAtk(int dir);
    int playerInRange(AbstractObject* object);
    void reset();
    bool isStair();
    void update();
    void changeNPCmovement();
    bool isDead();

    // Getters
    int getLevel() const;
    string getLastAction() const;
    char gameMapAt(int x, int y) const;
    AbstractObject* objectTilesAt(int x, int y) const;
    PlayerCharacter* getPlayerCharacter() const;
};

#endif
