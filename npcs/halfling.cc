#include "halfling.h"

using namespace std;

Halfling::Halfling(int x, int y):
    NPC{x, y, 'H', 100, 15, 20} {}


Halfling::~Halfling() {}

int Halfling::attack(AbstractCharacter* receiver) {
    // handles 50% of npc missing attack
    srand((unsigned) time(NULL));
    int random = rand() % 2;

    if (random == 1) {
        return MISSED_ATTACK;
    }

    int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
    receiver->getHP() -= damage;
    return damage;
}


string Halfling::getRace() {
    return "halfling";
}


