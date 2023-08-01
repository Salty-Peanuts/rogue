#include "treasure.h"

using namespace std;


Treasure::Treasure(int x, int y, int value) : 
    Item{x, y, 'G'}, value{value} {}


bool Treasure::isTraversible(AbstractObject *traveler) {
    return true;
}


int Treasure::getValue() {
    return value;
}

void Treasure::setValue(int value) {
    this->value = value;
}

