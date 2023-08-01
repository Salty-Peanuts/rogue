#include "BoostDef.h"

BoostDef::BoostDef(string race):
    def_increase{5} { 
        if (race == "Drow") {
            def_increase *= 1.5;
        }
    }

BoostDef::~BoostDef() {}


void BoostDef::usePotion(int &hp, int &atk, int &def, int max_hp) {
    atk += def_increase;
}


void BoostDef::removePotion(int &hp, int &atk, int &def) {
    def -= def_increase;
}


int BoostDef::potionStrength() {
    return def_increase;
}

