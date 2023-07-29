#include "shade.h"
#include "constants.h"

using namespace std;

Shade::Shade(int x, int y) :
    PlayerCharacter{x, y, 125, 25, 25} {}

int Shade::attack(AbstractCharacter *receiver) {
    // deals with if receiver is halfling (50% chance of missing attack)
    if (receiver->getRace() == "halfling") {
        // randomly produces either 0 or 1
        srand((unsigned) time(NULL));
        int random = rand() % 2;

        if (random == 1) {
            return MISSED_ATTACK;
        }
    }

    int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
    receiver->getHP() -= damage;
    return damage;
}



string Shade::getRace() {
    return "shade";
}

