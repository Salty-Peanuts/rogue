#ifndef FLOOR_H
#define FLOOR_H
#include <string>
#include "./floortiles.h"
#include "../abstractobject.h"
using namespace std;

class Floor : public FloorTiles
{
    public:
        Floor(int x, int y);
        ~Floor();
        bool isTraversible(AbstractObject* object) override;
};

#endif