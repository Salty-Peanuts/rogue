#ifndef DWARF_H
#define DWARF_H

#include "NPC.h"

class Dwarf : public NPC
{
    public:
        Dwarf();
        void attack(AbstractCharacter* receiver);
        void receiveAttack(AbstractCharacter* attacker);
};


#endif

