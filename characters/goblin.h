#ifndef GOBLIN
#define GOBLIN

#include "playercharacter.h"
#include "abstractcharacter.h"

using namespace std;

class Goblin : public PlayerCharacter
{
    public:
        Goblin(int x, int y);
        ~Goblin();
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
        string getRace();
};

#endif

