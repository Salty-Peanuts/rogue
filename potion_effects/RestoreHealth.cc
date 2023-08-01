#include "RestoreHealth.h"

RestoreHealth::RestoreHealth(string race):
    health_increase{10} { 
        if (race == "Drow") {
            health_increase *= 1.5;
        }
    }


RestoreHealth::~RestoreHealth() {}

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

