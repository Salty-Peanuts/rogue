#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

class AbstractObject
{
    int x, y;
    char token;
 public:
    AbstractObject();
    virtual ~AbstractObject() = 0;
    int getX();
    int getY();
    char getToken();
    virtual bool isTraversible();
    virtual string identify();
};

#endif
