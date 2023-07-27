#include "playercharacter.h"

using namespace std;

PlayerCharacter::PlayerCharacter():
    AbstractCharacter{}, token{'@'}, gold{0} {}


PlayerCharacter::~PlayerCharacter() {
    removePotions();
}


void PlayerCharacter::usePotion(string pot) {
    // implement usePotion
}

void PlayerCharacter::removePotions() {
    for (auto potion_ptr : potion_effects) {
        delete potion_ptr;
    }
}


void PlayerCharacter::death() {
    // implement death
}


// adds [value] amount to current gold balance
void PlayerCharacter::updateGold(int value) {
    gold += value;
}


