#ifndef ORC_H
#define ORC_H

#include "NPC.h"

using namespace std;

class Orc : public NPC
{
    public:
        Orc(int x, int y);
        void attack(AbstractCharacter* receiver) override;
        string getRace() override;
};


#endif

