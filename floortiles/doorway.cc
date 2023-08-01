#include "./doorway.h"
using namespace std;

Doorway::Doorway(int x, int y) : FloorTiles{x, y, '+'} {}

Doorway::~Doorway() {}

bool Doorway::isTraversible(AbstractObject* object) {
    if (object->identify() == "PlayerCharacter") {
        return true;
    } else {
        return false;
    }
}
