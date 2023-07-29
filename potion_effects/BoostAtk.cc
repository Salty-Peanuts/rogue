#include "BoostAtk.h"

BoostAtk::BoostAtk():
    PotionEffect(false), atk_increase{5} {}


void BoostAtk::usePotion(int &hp, int &atk, int &def, int max_hp) {
    atk += atk_increase;
}


void BoostAtk::removePotion(int &hp, int &atk, int &def) {
    atk -= atk_increase;
}


int BoostAtk::potionStrength() {
    return atk_increase;
}

