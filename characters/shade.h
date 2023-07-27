#ifndef SHADE
#define SHADE

#include "playercharacter.h"
#include "abstractcharacter.h"

class Shade : public PlayerCharacter
{
    public:
        Shade(int x, int y);
        ~Shade();
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
};

#endif

