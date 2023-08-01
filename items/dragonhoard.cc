#include "dragonhoard.h"

using namespace std;


DragonHoard::DragonHoard(int x, int y) : 
    Treasure{x, y, 6} {}


string DragonHoard::identify() { return "DragonHoard"; }

