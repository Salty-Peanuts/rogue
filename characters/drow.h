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
        void attack(AbstractCharacter *receiver);
        void receiveAttack(AbstractCharacter *attacker);
        string getRace();
};

#endif

