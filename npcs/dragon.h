#ifndef DRAGON_H
#define DRAGON_H

#include "NPC.h"

class Dragon : public NPC
{
    public:
        Dragon();
        void attack(AbstractCharacter* receiver);
        void receiveAttack(AbstractCharacter* attacker);
};


#endif

