#include "normalpile.h"

using namespace std;


NormalPile::NormalPile(int x, int y) : 
    Treasure{x, y, 2} {}

string NormalPile::identify() { return "NormalPile"; }

