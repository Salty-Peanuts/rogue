#ifndef ORC_H
#define ORC_H

#include "NPC.h"

using namespace std;

class Orc : public NPC
{
    public:
        Orc(int x, int y);
        ~Orc();
        int attack(AbstractCharacter* receiver) override;
        string getRace() override;
        bool deathLoot() override;
};


#endif

