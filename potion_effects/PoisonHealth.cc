#include "PoisonHealth.h"

PoisonHealth::PoisonHealth(string race):
    health_decrease{10} { 
        if (race == "Drow") {
            health_decrease *= 1.5;
        }
    }


PoisonHealth::~PoisonHealth() {}

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


int PoisonHealth::potionStrength() {
    return health_decrease;
}

