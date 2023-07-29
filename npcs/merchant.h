#ifndef MERCHANT_H
#define MERCHANT_H

#include "NPC.h"

using namespace std;

class Merchant : public NPC
{
    public:
        Merchant(int x, int y);
        void attack(AbstractCharacter* receiver);
        void receiveAttack(AbstractCharacter* attacker);
        string getRace();
        void makeHostile();
};


#endif

