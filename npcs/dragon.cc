#include "dragon.h"

using namespace std;

Dragon::Dragon(int x, int y, DragonHoard *dragon_hoard):
    NPC{x, y, 'D', 150, 20, 20}, dragon_hoard{dragon_hoard} {
        regular_gold_dropper = false;
    }

Dragon::~Dragon() {}


int Dragon::attack(AbstractCharacter* receiver) {
    int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
    receiver->getHP() -= damage;
    return damage;
}


string Dragon::getRace() {
    return "dragon";
}


void Dragon::assignDragonHoard(DragonHoard *dragon_hoard) {
    this->dragon_hoard = dragon_hoard;
}


