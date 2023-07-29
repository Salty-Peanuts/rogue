#ifndef MERCHANT_H
#define MERCHANT_H

#include "NPC.h"

using namespace std;

class Merchant : public NPC
{
    static bool hostile;

    public:
        Merchant(int x, int y);
        void attack(AbstractCharacter* receiver) override;
        void receiveAttack(AbstractCharacter* attacker) override;
        string getRace() override;
        void makeHostile();
};


#endif

