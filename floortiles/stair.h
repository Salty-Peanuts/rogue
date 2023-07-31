#ifndef STAIR_H
#define STAIR_H
#include <string>
#include "./floortiles.h"
using namespace std;

class Stair : public FloorTiles
{
    public:
        Stair(int x, int y);
        ~Stair();
        bool isTraversible(AbstractObject* object) override;
};

#endif
