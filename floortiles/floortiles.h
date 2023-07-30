#ifndef FLOORTILES_H
#define FLOORTILES_H
#include "../abstractobject.h"
#include <string>
using namespace std;

class FloorTiles : public AbstractObject
{
    public:
        FloorTiles(int x, int y, char token);
        ~FloorTiles();
        string identify() override;
};

#endif
