#ifndef POTION_H
#define POTION_H

#include "item.h"

using namespace std;


class Potion : public Item
{
    string potion_type;
    
 public:
    Potion(int x, int y, string potion_type);
    bool isTraversible(AbstractObject *traveler) override;
    string identify() override;

};

#endif
