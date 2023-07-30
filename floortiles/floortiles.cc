#include "./floortiles.h"
using namespace std;

FloorTiles::FloorTiles(int x, int y, char token) : AbstractObject{x, y, token} {}

FloorTiles::~FloorTiles() {}

string FloorTiles::identify() {
    return "Floor";
}
