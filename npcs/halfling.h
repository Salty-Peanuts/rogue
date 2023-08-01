#ifndef HALFLING_H
#define HALFLING_H

#include "NPC.h"

using namespace std;

class Halfling : public NPC
{
    public:
        Halfling(int x, int y);
        ~Halfling();
        int attack(AbstractCharacter* receiver) override;
        string getRace() override;
        bool deathLoot() override;
};


#endif

