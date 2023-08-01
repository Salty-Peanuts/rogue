#include "smallpile.h"

using namespace std;


SmallPile::SmallPile(int x, int y) : 
    Treasure{x, y, 1} {}


string SmallPile::identify() { return "SmallPile"; }

