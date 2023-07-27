#ifndef DROW
#define DROW

#include "playercharacter.h"
#include "abstractcharacter.h"

class Drow : public PlayerCharacter
{
    public:
        Drow(int x, int y);
        ~Drow();
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
};

#endif

