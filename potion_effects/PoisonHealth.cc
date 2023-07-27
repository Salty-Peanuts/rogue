#include "PoisonHealth.h"

PoisonHealth::PoisonHealth():
    PotionEffect(true), health_decrease{10} {}


void PoisonHealth::usePotion(int &hp, int &atk, int &def, int max_hp) {
    if (hp - health_decrease < 0) {
        hp = 0;
    }
    else {
        hp -= health_decrease;
    }
}


void PoisonHealth::removePotion(int &hp, int &atk, int &def) {
    return;
}


