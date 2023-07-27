#ifndef DROW
#define DROW

#include "playercharacter.h"
#include "abstractcharacter.h"

class Drow : public PlayerCharacter
{
    int hp = 150;
    int attack = 25;
    int defense = 15;

    public:
        Drow();
        ~Drow();
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
};

#endif

