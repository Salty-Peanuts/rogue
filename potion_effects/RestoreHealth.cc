#include "RestoreHealth.h"

RestoreHealth::RestoreHealth():
    PotionEffect(true), health_increase{10} {}


void RestoreHealth::usePotion(int &hp, int &atk, int &def, int max_hp) {
    if (hp + health_increase > max_hp) {
        hp = max_hp;
    }
    else {
        hp += health_increase;
    }
}


void RestoreHealth::removePotion(int &hp, int &atk, int &def) {
    return;
}


int RestoreHealth::potionStrength() {
    return health_increase;
}

