#ifndef DRAGON_H
#define DRAGON_H

#include "NPC.h"

using namespace std;

class Dragon : public NPC
{
    public:
        Dragon(int x, int y);
        int attack(AbstractCharacter* receiver) override;
        string getRace() override;
};




#endif

