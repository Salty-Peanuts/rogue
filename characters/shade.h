#ifndef SHADE
#define SHADE

#include "playercharacter.h"
#include "abstractcharacter.h"

using namespace std;

class Shade : public PlayerCharacter
{
    public:
        Shade(int x, int y);
        ~Shade();
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
        string getRace();
};

#endif

