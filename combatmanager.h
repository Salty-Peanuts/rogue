#ifndef COMBATMANAGER_H
#define COMBATMANAGER_H

#include "abstractobject.h"
#include "gamemap.h"
using namespace std;

class CombatManager
{
    int direction;

 public:
    CombatManager(int dir);
    ~CombatManager();
    void NPCAttack(GameMap& map, AbstractObject* initiator, AbstractObject* reciever);
    void playerAttack(GameMap& map, AbstractObject* initiator, AbstractObject* reciever);
    bool isValid(GameMap& map, AbstractObject* initiator, AbstractObject* reciever);
    void setDirection(int dir);
};

#endif
