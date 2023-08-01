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
    srand((unsigned) time(NULL));
    int random = rand() % 2;

    if (random == 1) {
        return MISSED_ATTACK;
    }

    int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
    receiver->getHP() -= damage;
    return damage;
}



string Merchant::getRace() {
    return "merchant";
}

void Merchant::makeAggravated() {
    aggravated = true;
    hostile = true;
}



bool Merchant::deathLoot() { return true; }


