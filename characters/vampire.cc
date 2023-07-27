#include "vampire.h"

using namespace std;

Vampire::Vampire(int x, int y) :
    PlayerCharacter{x, y, 50, 25, 25} {}

void Vampire::attack(AbstractCharacter *receiver) {
    // implement attack
}

void Vampire::receiveAttack(AbstractCharacter *attacker) {
    // implement
}


