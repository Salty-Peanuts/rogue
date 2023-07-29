#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"

using namespace std;

class Treasure : public Item
{
    int value;
    
 public:
    Treasure(int value);
    ~Treasure();
    void setValue(int value);
    bool isTraversible() override;
};

#endif
