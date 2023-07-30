#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <string>
#include "constants.h"

using namespace std;

class AbstractObject
{
    int x, y;
    char token;
 public:
    AbstractObject(int x, int y, char token);
    virtual ~AbstractObject() = 0;
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    char getToken();
    virtual bool isTraversible(AbstractObject* object)  = 0;
    virtual string identify() = 0;
};

#endif
