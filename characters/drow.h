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
        int attack(AbstractCharacter *receiver) override;
        string getRace() override;
};

#endif

