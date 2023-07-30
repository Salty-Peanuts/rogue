#include "./floor.h"
using namespace std;

Floor::Floor(int x, int y) : FloorTiles{x, y, '.'} {}

Floor::~Floor() {}

bool Floor::isTraversible(AbstractObject* object) {
    return true;
}
