#ifndef POTION_H
#define POTION_H

using namespace std;

#include "item.h"

class Potion : public Item
{
    string potion_type;
    
 public:
    Potion(int value);
    ~Potion();
    bool isTraversible() override;

};

#endif
