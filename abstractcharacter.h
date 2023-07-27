#ifndef ABSTRACTCHARACTER_H
#define ABSTRACTCHARACTER_H

#include "abstractobject.h"

class AbstractCharacter : public AbstractObject
{
    int hp;
    int attack;
    int defense;
    bool traversible;

    public:
        AbstractCharacter();
        virtual void attack(AbstractCharacter *character);
        virtual void recieveAttack(AbstractCharacter *character);
        virtual void death();
        virtual bool isTraversible();
        void move(int dir);
};

#endif
