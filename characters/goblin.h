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
        int attack(AbstractCharacter *receiver) override;
        string getRace() override;
};

#endif

