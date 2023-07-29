#ifndef HUMAN_H
#define HUMAN_H

#include "NPC.h"

using namespace std;

class Human : public NPC
{
    public:
        Human(int x, int y);
        int attack(AbstractCharacter* receiver) override;
        string getRace() override;
};


#endif

