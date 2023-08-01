#include "dragonhoard.h"

using namespace std;


DragonHoard::DragonHoard(int x, int y) : 
    Treasure{x, y, 6}, dragon_alive{true} {}


string DragonHoard::identify() { return "DragonHoard"; }


bool DragonHoard::isDragonAlive() { return dragon_alive; }

void DragonHoard::dragonDies() { dragon_alive = false; }

