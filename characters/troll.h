#ifndef TROLL
#define TROLL

#include "playercharacter.h"
#include "abstractcharacter.h"

class Troll : public PlayerCharacter
{
    public:
        Troll(int x, int y);
        ~Troll();
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
};

#endif

