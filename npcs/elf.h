#ifndef ELF_H
#define ELF_H

#include "NPC.h"

using namespace std;

class Elf : public NPC
{
    public:
        Elf(int x, int y);
        void attack(AbstractCharacter* receiver) override;
        void receiveAttack(AbstractCharacter* attacker) override;
        string getRace() override;
};


#endif

