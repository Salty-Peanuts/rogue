#include "./stair.h"
using namespace std;

Stair::Stair(int x, int y) : FloorTiles{x, y, '\\'} {}

Stair::~Stair() {}

bool Stair::isTraversible(AbstractObject* object) {
    if (object->identify() == "PlayerCharacter") {
        return true;
    } else {
        return false;
    }
}
