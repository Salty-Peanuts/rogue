#include "./stairspawner.h"
#include "../floortiles/stair.h"
using namespace std;

StairSpawner::StairSpawner() {}

StairSpawner::~StairSpawner() {}

AbstractObject* StairSpawner::spawn(int x, int y) {
    return new Stair(x, y);
}

AbstractObject* StairSpawner::spawnRandom(int x, int y) {
    return spawn(x, y);
}
