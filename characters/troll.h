#ifndef TROLL
#define TROLL

#include "playercharacter.h"
#include "abstractcharacter.h"

class Troll : public PlayerCharacter
{
    int hp = 125;
    int attack = 25;
    int defense = 25;

    public:
        Troll();
        ~Troll();
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
};

#endif

