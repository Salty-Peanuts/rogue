#ifndef TREASURE_H
#define TREASURE_H

#include "./items/item.h"

class Treasure
{
    int value;
    
 public:
    Treasure(int value);
    ~Treasure();
    void setValue(int value);
};

#endif
