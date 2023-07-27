#ifndef GOBLIN
#define GOBLIN

#include "playercharacter.h"
#include "abstractcharacter.h"

class Goblin : public PlayerCharacter
{
    int hp = 110;
    int attack = 15;
    int defense = 20;

    public:
        Goblin();
        ~Goblin();
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
};

#endif

