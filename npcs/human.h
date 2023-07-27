#ifndef HUMAN_H
#define HUMAN_H

#include "NPC.h"

class Human : public NPC
{
    public:
        Human(int x, int y);
        void attack(AbstractCharacter* receiver);
        void receiveAttack(AbstractCharacter* attacker);
};


#endif

