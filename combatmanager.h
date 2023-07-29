#ifndef COMBATMANAGER_H
#define COMBATMANAGER_H

#include "abstractcharacter.h"
#include "gamemap.h"
using namespace std;

class CombatManager
{
    int direction;

 public:
    CombatManager(int dir);
    ~CombatManager();
    void NPCAttack(GameMap& game_map, AbstractCharacter* initiator, AbstractCharacter* reciever);
    void playerAttack(GameMap& game_map, AbstractCharacter* initiator);
    bool isValid(GameMap& game_map, AbstractObject* initiator, AbstractObject* reciever);
    void setDirection(int dir);
};

#endif
