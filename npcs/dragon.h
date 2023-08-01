#ifndef DRAGON_H
#define DRAGON_H

#include "NPC.h"
#include "../items/dragonhoard.h"

using namespace std;

class Dragon : public NPC
{
    DragonHoard *dragon_hoard;

    public:
        Dragon(int x, int y, DragonHoard *dragon_hoard);
        ~Dragon();
        int attack(AbstractCharacter* receiver) override;
        string getRace() override;
        void assignDragonHoard(DragonHoard *dragon_hoard);
        bool deathLoot() override;
};




#endif

