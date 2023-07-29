#ifndef TROLL
#define TROLL

#include "playercharacter.h"
#include "abstractcharacter.h"

using namespace std;

class Troll : public PlayerCharacter
{
    public:
        Troll(int x, int y);
        ~Troll();
        void attack(AbstractCharacter *receiver) override;
        void receiveAttack(AbstractCharacter *attacker) override;
        string getRace() override;
};

#endif

