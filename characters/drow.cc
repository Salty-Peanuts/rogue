#include "drow.h"

using namespace std;

Drow::Drow(int x, int y) :
    PlayerCharacter{x, y, 150, 25, 15} {}

void Drow::attack(AbstractCharacter *receiver) {
    // implement attack
}

void Drow::receiveAttack(AbstractCharacter *attacker) {
    // implement
}


