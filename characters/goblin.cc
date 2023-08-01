#include "goblin.h"

using namespace std;

Goblin::Goblin(int x, int y) :
    PlayerCharacter{x, y, 110, 15, 20} {}


Goblin::~Goblin() {}


int Goblin::attack(AbstractCharacter *receiver) {
    // deals with if receiver is halfling (50% chance of missing attack)
    if (receiver->getRace() == "Halfling") {
        // randomly produces either 0 or 1
        int random = rand() % 2;

        if (random == 1) {
            return MISSED_ATTACK;
        }
    }

    float damage_calc = (100.0 / (100.0 + receiver->getDef())) * getAtk();
    int damage = ceil(damage_calc);
    receiver->getHP() -= damage;
    return damage;
}



string Goblin::getRace() {
    return "Goblin";
}

