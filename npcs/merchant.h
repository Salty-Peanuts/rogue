#ifndef MERCHANT_H
#define MERCHANT_H

#include "NPC.h"

class Merchant : public NPC
{
    public:
        Merchant(int x, int y);
        void attack(AbstractCharacter* receiver);
        void receiveAttack(AbstractCharacter* attacker);
};


#endif

