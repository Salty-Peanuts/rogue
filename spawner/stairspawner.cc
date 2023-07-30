#include "./stairspawner.h"
#include "../stair.h"
using namespace std;

StairSpawner::StairSpawner() {}

StairSpawner::~StairSpawner() {}

AbstractObject* StairSpawner::spawn(int x, int y) {
    return new Stair(x, y, tile_type);
}

AbstractObject* StairSpawner::spawnRandom(int x, int y) {
    return spawn(x, y);
}
