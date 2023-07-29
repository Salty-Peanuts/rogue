#include "dragon.h"

using namespace std;

Dragon::Dragon(int x, int y):
    NPC{x, y, 'D', 150, 20, 20} {}


int Dragon::attack(AbstractCharacter* receiver) {
    int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
    receiver->getHP() -= damage;
    return damage;
}


string Dragon::getRace() {
    return "dragon";
}

