#include "goblin.h"
#include "constants.h"

using namespace std;

Goblin::Goblin(int x, int y) :
    PlayerCharacter{x, y, 110, 15, 20} {}

void Goblin::attack(AbstractCharacter *receiver) {
    // implement attack
}

void Goblin::receiveAttack(AbstractCharacter *attacker) {
    // implement
}


