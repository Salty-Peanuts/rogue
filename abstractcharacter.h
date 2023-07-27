#ifndef ABSTRACTCHARACTER_H
#define ABSTRACTCHARACTER_H

#include "abstractobject.h"

class AbstractCharacter : public AbstractObject
{
    int hp;
    int atk;
    int def;
    bool traversible;

    public:
        AbstractCharacter(int x, int y, char token, int hp, int atk, int def);
        virtual void attack(AbstractCharacter *character);
        virtual void recieveAttack(AbstractCharacter *character);
        virtual void death();
        virtual bool isTraversible();
        void move(int dir);
};

#endif
