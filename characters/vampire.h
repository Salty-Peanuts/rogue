#ifndef VAMPIRE
#define VAMPIRE

#include "playercharacter.h"
#include "abstractcharacter.h"

using namespace std;

class Vampire : public PlayerCharacter
{
    public:
        Vampire(int x, int y);
        ~Vampire();
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
        string getRace();
};

#endif

