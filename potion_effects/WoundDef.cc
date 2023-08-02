#include "WoundDef.h"

WoundDef::WoundDef(string race):
    def_decrease{5} { 
        if (race == "Drow") {
            def_decrease *= 1.5;
        }
    }

WoundDef::~WoundDef() {}


void WoundDef::usePotion(int &hp, int &atk, int &def, int max_hp) {
    if (def - def_decrease < 0) {
        def = 0;
    }
    else {
        def -= def_decrease;
    }
}


void WoundDef::removePotion(int &hp, int &atk, int &def) {
    def += def_decrease;
}

int WoundDef::potionStrength() {
    return def_decrease;
}

