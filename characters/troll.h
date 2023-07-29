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
        int attack(AbstractCharacter *receiver) override;
        string getRace() override;
};

#endif

