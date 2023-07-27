#include "troll.h"

using namespace std;

Troll::Troll(int x, int y) :
    PlayerCharacter{x, y, 120, 25, 15} {}

void Troll::attack(AbstractCharacter *receiver) {
    // implement attack
}

void Troll::receiveAttack(AbstractCharacter *attacker) {
    // implement
}


