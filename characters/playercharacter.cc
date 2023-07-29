#include "playercharacter.h"
#include "BoostAtk.h"
#include "BoostDef.h"
#include "PoisonHealth.h"
#include "RestoreHealth.h"
#include "WoundAtk.h"
#include "WoundDef.h"

using namespace std;

PlayerCharacter::PlayerCharacter(int x, int y, int hp, int atk, int def):
    AbstractCharacter{x, y, '@', hp, atk, def}, gold{0}, max_hp{hp} {}


PlayerCharacter::~PlayerCharacter() {
    removePotions();
}


void PlayerCharacter::usePotion(string pot) {
    PotionEffect *new_pot;
    if (pot == "RH") {
        new_pot = new RestoreHealth();
    }
    if (pot == "BA") {
        new_pot = new BoostAtk();
    }
    if (pot == "BD") {
        new_pot = new BoostDef();
    }
    if (pot == "PH") {
        new_pot = new PoisonHealth();
    }
    if (pot == "WA") {
        new_pot = new WoundAtk();
    }
    if (pot == "WD") {
        new_pot = new WoundDef();
    }

    potion_effects.push_back(new_pot);
    new_pot->usePotion(getHP(), getAtk(), getDef(), getMaxHP());
}

void PlayerCharacter::removePotions() {
    for (auto potion_ptr : potion_effects) {
        potion_ptr->removePotion(getHP(), getAtk(), getDef());
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

int PlayerCharacter::getGold() {
    return gold;
}


string PlayerCharacter::identify() {
    return "PlayerCharacter";
}


int PlayerCharacter::getMaxHP() {
    return max_hp;
}

