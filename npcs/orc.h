#ifndef ORCS_H
#define ORCS_H

#include "NPC.h"

class Orcs : public NPC
{
    public:
        Orcs();
        void attack(AbstractCharacter* receiver);
        void receiveAttack(AbstractCharacter* attacker);
};


#endif

