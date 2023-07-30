#ifndef SMALL_PILE_H
#define SMALL_PILE_H

#include "treasure.h"

using namespace std;


class SmallPile : public Treasure
{   
    public:
        SmallPile(int x, int y);
        ~SmallPile();
};

#endif

