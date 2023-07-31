#include "vampire.h"

using namespace std;

Vampire::Vampire(int x, int y) :
    PlayerCharacter{x, y, 50, 25, 25} { toggleMaxHP(false); }

Vampire::~Vampire() {}


int Vampire::attack(AbstractCharacter *receiver) {
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


    // handles vampire special attack interactions ----
    // vampires gain 5 hp with every successfull attack
        // except when attacking dwarf

    if (receiver->getRace() == "dwarf") {
        getHP() -= 5;
    }
    else {
        getHP() += 5;
    }

    return damage;
}


string Vampire::getRace() {
    return "vampire";
}

