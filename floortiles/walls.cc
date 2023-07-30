#include "./walls.h"
using namespace std;

Walls::Walls(int x, int y) : FloorTiles{x, y, '|'} {}

Walls::~Walls() {}

bool Walls::isTraversible(AbstractObject* object) {
    return false;
}
