#ifndef SHADE
#define SHADE

#include "playercharacter.h"
#include "abstractcharacter.h"

class Shade : public PlayerCharacter
{
    int hp = 125;
    int attack = 25;
    int defense = 25;

    public:
        Shade();
        ~Shade();
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
};

#endif

