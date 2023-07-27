#ifndef COMBATMANAGER_H
#define COMBATMANAGER_H

#include "abstractcharacter.h"
using namespace std;

class CombatManager
{
    int direction;

 public:
    CombatManager(int dir);
    ~CombatManager();
    void NPCAttack(GameMap& map, AbstractCharacter* initiator, AbstractCharacter* reciever);
    void playerAttack(GameMap& map, AbstractCharacter* initiator, AbstractCharacter* reciever);
    bool isValid(GameMap& map, AbstractCharacter* initiator, AbstractCharacter* reciever);
};

#endif
