#ifndef HALFLING_H
#define HALFLING_H

#include "NPC.h"

using namespace std;

class Halfling : public NPC
{
    public:
        Halfling(int x, int y);
        void attack(AbstractCharacter* receiver) override;
        void receiveAttack(AbstractCharacter* attacker) override;
        string getRace() override;
};


#endif

