#ifndef WALLS_H
#define WALLS_H
#include <string>
#include "./floortiles.h"
using namespace std;

class Walls : public FloorTiles
{
    public:
        Walls(int x, int y);
        ~Walls();
        bool isTraversible(AbstractObject* object) override;
};

#endif