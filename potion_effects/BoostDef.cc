#include "BoostDef.h"

BoostDef::BoostDef():
    PotionEffect(false), def_increase{5} {}


void BoostDef::usePotion(int &hp, int &atk, int &def, int max_hp) {
    atk += def_increase;
}


void BoostDef::removePotion(int &hp, int &atk, int &def) {
    def -= def_increase;
}


