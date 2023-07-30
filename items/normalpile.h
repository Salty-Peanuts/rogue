#ifndef NORMAL_PILE_H
#define NORMAL_PILE_H

#include "treasure.h"

using namespace std;


class NormalPile : public Treasure
{   
    public:
        NormalPile(int x, int y);
        ~NormalPile();
};

#endif

