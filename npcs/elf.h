#ifndef ELF_H
#define ELF_H

#include "NPC.h"

class Elf : public NPC
{
    public:
        Elf();
        void attack(AbstractCharacter* receiver);
        void receiveAttack(AbstractCharacter* attacker);
};


#endif

