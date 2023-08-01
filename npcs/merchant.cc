#include "merchant.h"

using namespace std;

bool Merchant::aggravated = false;

Merchant::Merchant(int x, int y):
    NPC{x, y, 'M', 30, 70, 5} { 
        hostile = aggravated; 
        regular_gold_dropper = false;
    }

Merchant::~Merchant() {}


int Merchant::attack(AbstractCharacter* receiver) {
    // handles 50% of npc missing attack
    int random = rand() % 2;

    if (random == 1) {
        return MISSED_ATTACK;
    }

    float damage_calc = (100.0 / (100.0 + receiver->getDef())) * getAtk();
    int damage = ceil(damage_calc);
    receiver->getHP() -= damage;
    return damage;
}



string Merchant::getRace() {
    return "Merchant";
}

void Merchant::makeAggravated() {
    aggravated = true;
    hostile = true;
}



bool Merchant::deathLoot() { return true; }


