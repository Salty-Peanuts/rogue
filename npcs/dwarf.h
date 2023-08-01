#ifndef DWARF_H
#define DWARF_H

#include "NPC.h"

using namespace std;

class Dwarf : public NPC
{
    public:
        Dwarf(int x, int y);
        ~Dwarf();
        int attack(AbstractCharacter* receiver) override;
        string getRace() override;
        bool deathLoot() override;
};


#endif

