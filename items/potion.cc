#include "potion.h"

using namespace std;


Potion::Potion(int x, int y, string potion_type) : 
    Item{x, y, 'P'}, potion_type{potion_type} {}


bool Potion::isTraversible(AbstractObject *traveler) {
    return false;
}

string Potion::identify() {
    return "Potion";
}

