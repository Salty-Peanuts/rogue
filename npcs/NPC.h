#ifndef NPC_H
#define NPC_H

#include "abstractcharacter.h"

using namespace std;

class NPC : public AbstractCharacter 
{
    bool hasMoved;

    public:
        NPC(int x, int y, char token, int hp, int atk, int def);
        ~NPC();
        void death();
        bool isHostile();
        bool wasMoved();
        string identify();
        void changeHostility(bool hostility);
        virtual void attack(AbstractCharacter* receiver);
        virtual void receiveAttack(AbstractCharacter* attacker);
        virtual string getRace() = 0;
};

#endif

