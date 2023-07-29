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
        void attack(AbstractCharacter *receiver) override;
        void receiveAttack(AbstractCharacter *attacker) override;
        string getRace() override;
};

#endif

