#include "BoostAtk.h"

BoostAtk::BoostAtk(string race) :
    atk_increase{5} { 
        if (race == "Drow") {
            atk_increase *= 1.5;
        }
    }


BoostAtk::~BoostAtk() {}

void BoostAtk::usePotion(int &hp, int &atk, int &def, int max_hp) {
    atk += atk_increase;
}


void BoostAtk::removePotion(int &hp, int &atk, int &def) {
    atk -= atk_increase;
}


int BoostAtk::potionStrength() {
    return atk_increase;
}

