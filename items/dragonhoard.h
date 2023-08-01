#ifndef DRAGON_HOARD_H
#define DRAGON_HOARD_H

#include "treasure.h"

using namespace std;


class DragonHoard : public Treasure
{   
    bool dragon_alive;

    public:
        DragonHoard(int x, int y);
        string identify() override;
        bool isDragonAlive();
        void dragonDies();
};

#endif

