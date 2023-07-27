#ifndef ITEM
#define ITEM

#include <string>
#include "../abstractobject.h"
using namespace std;

class Item : public AbstractObject
{
    string item_type;
    char token;
    public: 
        string identify();
};


#endif



