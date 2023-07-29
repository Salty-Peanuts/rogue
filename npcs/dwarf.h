#ifndef DWARF_H
#define DWARF_H

#include "NPC.h"

using namespace std;

class Dwarf : public NPC
{
    public:
        Dwarf(int x, int y);
        void attack(AbstractCharacter* receiver);
        void receiveAttack(AbstractCharacter* attacker);
        string getRace();
};


#endif

