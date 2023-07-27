#ifndef ORCS_H
#define ORCS_H

#include "NPC.h"

class Orcs : public NPC
{
    public:
        Orcs(int x, int y);
        void attack(AbstractCharacter* receiver);
        void receiveAttack(AbstractCharacter* attacker);
};


#endif

