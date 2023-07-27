#ifndef VAMPIRE
#define VAMPIRE

#include "playercharacter.h"
#include "abstractcharacter.h"

class Vampire : public PlayerCharacter
{
    int hp = 50;
    int attack = 25;
    int defense = 25;

    public:
        Vampire(int x, int y);
        ~Vampire();
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
};

#endif

