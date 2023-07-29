#include "halfling.h"

using namespace std;

Halfling::Halfling(int x, int y):
    NPC{x, y, 'H', 100, 15, 20} {}


void Halfling::attack(AbstractCharacter* receiver) {
    int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
    receiver->getHP() -= damage;
}


string Halfling::getRace() {
    return "halfling";
}


