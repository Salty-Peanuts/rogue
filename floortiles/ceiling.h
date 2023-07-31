#ifndef CEILING_H
#define CEILING_H
#include <string>
#include "./floortiles.h"
using namespace std;

class Ceiling : public FloorTiles
{
    public:
        Ceiling(int x, int y);
        ~Ceiling();
        bool isTraversible(AbstractObject* object) override;
};

#endif