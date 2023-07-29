#include "dwarf.h"

using namespace std;

Dwarf::Dwarf(int x, int y):
    NPC{x, y, 'W', 100, 20, 30} {}


void Dwarf::attack(AbstractCharacter* receiver) {
    int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
    receiver->getHP() -= damage;
}


string Dwarf::getRace() {
    return "dwarf";
}

