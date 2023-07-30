#include "treasure.h"

using namespace std;


Treasure::Treasure(int x, int y, int value) : 
    Item{x, y, 'G'}, value{value} {}


bool Treasure::isTraversible() {
    return true;
}

string Treasure::identify() {
    return "Treasure";
}

