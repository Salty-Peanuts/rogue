#include "shade.h"

using namespace std;

Shade::Shade(int x, int y) :
    PlayerCharacter{x, y, 125, 25, 25} {}

void Shade::attack(AbstractCharacter *receiver) {
    // implement attack
}

void Shade::receiveAttack(AbstractCharacter *attacker) {
    // implement
}


