#ifndef PASSAGE_H
#define PASSAGE_H
#include <string>
#include "./floortiles.h"
#include "../abstractobject.h"
using namespace std;

class Passage : public FloorTiles
{
    public:
        Passage(int x, int y);
        ~Passage();
        bool isTraversible(AbstractObject* object) override;
};

#endif