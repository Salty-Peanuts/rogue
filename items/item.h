#ifndef ITEM
#define ITEM

#include <string>
#include "../abstractobject.h"

using namespace std;

class Item : public AbstractObject
{
    public:
        Item(int x, int y, char token);
        virtual string identify() = 0;
};


#endif



