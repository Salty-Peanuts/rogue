#include "./ceiling.h"
using namespace std;

Ceiling::Ceiling(int x, int y) : FloorTiles{x, y, '-'} {}

Ceiling::~Ceiling() {}

bool Ceiling::isTraversible(AbstractObject* object) {
    return false;
}
