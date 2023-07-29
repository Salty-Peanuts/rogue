#include "WoundDef.h"

WoundDef::WoundDef():
    PotionEffect(false), def_decrease{5} {}


void WoundDef::usePotion(int &hp, int &atk, int &def, int max_hp) {
    if (atk - def_decrease < 0) {
        atk = 0;
    }
    else {
        atk - def_decrease;
    }
}


void WoundDef::removePotion(int &hp, int &atk, int &def) {
    atk += def_decrease;
}

int WoundDef::potionStrength() {
    return def_decrease;
}

