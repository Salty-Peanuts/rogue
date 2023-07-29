#ifndef POTION_H
#define POTION_H

#include "item.h"

using namespace std;


class Potion : public Item
{
    string potion_type;
    
 public:
    Potion(int value);
    ~Potion();
    bool isTraversible() override;
    string identify;

};

#endif
