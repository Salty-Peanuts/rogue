#include "./stairspawner.h"
#include "../stair.h"

AbstractObject* StairSpawner::spawn(int x, int y) {
    return new Stair(x, y, tile_type);
}
