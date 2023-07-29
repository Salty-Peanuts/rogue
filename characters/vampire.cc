#include "vampire.h"
#include "constants.h"

using namespace std;

Vampire::Vampire(int x, int y) :
    PlayerCharacter{x, y, 50, 25, 25} { toggleMaxHP(false); }

void Vampire::attack(AbstractCharacter *receiver) {
    // implement attack
}

void Vampire::receiveAttack(AbstractCharacter *attacker) {
    // implement
}


string Vampire::getRace() {
    return "vampire";
}

