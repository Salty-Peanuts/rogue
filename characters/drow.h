#ifndef DROW
#define DROW

#include "playercharacter.h"
#include "abstractcharacter.h"

using namespace std;

class Drow : public PlayerCharacter
{
    public:
        Drow(int x, int y);
        ~Drow();
        void attack(AbstractCharacter *receiver) override;
        void receiveAttack(AbstractCharacter *attacker) override;
        string getRace() override;
};

#endif

