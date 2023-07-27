#ifndef GOBLIN
#define GOBLIN

#include "playercharacter.h"
#include "abstractcharacter.h"

class Goblin : public PlayerCharacter
{
    public:
        Goblin(int x, int y);
        ~Goblin();
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
};

#endif

