#ifndef NPC_H
#define NPC_H

#include "abstractcharacter.h"

using namespace std;

class NPC : public AbstractCharacter 
{
    bool hasMoved;

    protected:
        static bool hostile;

    public:
        NPC(int x, int y, char token, int hp, int atk, int def);
        void death();
        bool isHostile();
        bool wasMoved();
        string identify();
        virtual void attack(AbstractCharacter* receiver);
        virtual void receiveAttack(AbstractCharacter* attacker);
        virtual string getRace();
};

#endif

