#ifndef __ITEM__
#define __ITEM__

#include <string>
#include "../abstractobject.h"
using namespace std;

class Item : public AbstractObject
{
    string item_type;
    char token;
};


#endif



