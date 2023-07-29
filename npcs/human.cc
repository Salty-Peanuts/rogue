#include "human.h"

using namespace std;

Human::Human(int x, int y):
    NPC{x, y, 'H', 140, 20, 20} {}


int Human::attack(AbstractCharacter* receiver) {
    int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
    receiver->getHP() -= damage;
    return damage;
}


string Human::getRace() {
    return "human";
}

