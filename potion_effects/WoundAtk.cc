#include "WoundAtk.h"

WoundAtk::WoundAtk():
    PotionEffect(false), atk_decrease{5} {}


void WoundAtk::usePotion(int &hp, int &atk, int &def, int max_hp) {
    if (atk - atk_decrease < 0) {
        atk = 0;
    }
    else {
        atk - atk_decrease;
    }
}


void WoundAtk::removePotion(int &hp, int &atk, int &def) {
    atk += atk_decrease;
}


