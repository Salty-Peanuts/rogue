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
        void attack(AbstractCharacter *character);
        void recieveAttack(AbstractCharacter *character);
        void move(int dir);
        void death();
        void moveTo(int x, int y);
        void setX(int x);
        void setY(int y);
        bool isTraversible();
};

#endif
