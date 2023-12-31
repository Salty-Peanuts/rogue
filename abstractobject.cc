#include "abstractobject.h"
#include "constants.h"


AbstractObject::AbstractObject(int x, int y, char token) :
    x{x}, y{y}, token{token} {}

AbstractObject::~AbstractObject() {}

int AbstractObject::getX()
{
    return x;
}

int AbstractObject::getY()
{
    return y;
}

char AbstractObject::getToken()
{
    return token;
}


void AbstractObject::setX(int x) 
{
    this->x = x;
}

void AbstractObject::setY(int y) 
{
    this->y = y;
}

