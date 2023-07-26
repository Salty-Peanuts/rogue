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
        virtual void attack(AbstractCharacter *character);
        virtual void recieveAttack(AbstractCharacter *character);
        virtual void death();
        void setX(int x);
        void setY(int y);
        void moveTo(int x, int y);
        virtual bool isTraversible();
};

#endif
