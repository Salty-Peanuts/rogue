#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <string>

using namespace std;

class AbstractObject
{
    int x, y;
    char token;
 public:
    AbstractObject();
    virtual ~AbstractObject() = 0;
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    char getToken();
    virtual bool isTraversible();
    virtual string identify();
};

#endif
