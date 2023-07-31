#ifndef DOORWAY_H
#define DOORWAY_H
#include <string>
#include "./floortiles.h"
using namespace std;

class Doorway : public FloorTiles
{
    public:
        Doorway(int x, int y);
        ~Doorway();
        bool isTraversible(AbstractObject* object) override;
};

#endif