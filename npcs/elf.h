#ifndef ELF_H
#define ELF_H

#include "NPC.h"

using namespace std;

class Elf : public NPC
{
    public:
        Elf(int x, int y);
        ~Elf();
        int attack(AbstractCharacter* receiver) override;
        string getRace() override;
        void death() override;
};


#endif

