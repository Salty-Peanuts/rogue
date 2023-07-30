#ifndef DRAGON_HOARD_H
#define DRAGON_HOARD_H

#include "treasure.h"

using namespace std;


class DragonHoard : public Treasure
{
    int value;
    
 public:
    DragonHoard();
    ~DragonHoard();
};

#endif

