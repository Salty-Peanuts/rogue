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
        int attack(AbstractCharacter *receiver) override;
        string getRace() override;
};

#endif

