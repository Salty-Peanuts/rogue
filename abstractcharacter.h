#ifndef ABSTRACTCHARACTER_H
#define ABSTRACTCHARACTER_H

#include "abstractobject.h"

using namespace std;

class AbstractCharacter : public AbstractObject
{
    int hp;
    int atk;
    int def;
    bool traversible = false;

    public:
        AbstractCharacter(int x, int y, char token, int hp, int atk, int def);
        virtual int attack(AbstractCharacter *character);
        virtual void recieveAttack(AbstractCharacter *character);
        virtual void death();
        bool isTraversible(AbstractObject *traveler);
        virtual string identify() = 0;
        virtual string getRace();
        void move(int dir);

        int &getHP();
        int &getAtk();
        int &getDef();
};

#endif
