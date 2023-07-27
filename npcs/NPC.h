#ifndef NPC_H
#define NPC_H

#include "abstractcharacter.h"

using namespace std;

class NPC : public AbstractCharacter 
{
    bool hostile;
    bool hasMoved;

    public:
        NPC(int x, int y, char token, int hp, int atk, int def);
        void death();
        bool isHostile();
        bool wasMoved();
        virtual void attack(AbstractCharacter* receiver);
        virtual void receiveAttack(AbstractCharacter* attacker);
        string identify();
};

#endif

