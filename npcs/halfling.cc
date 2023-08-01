#include "halfling.h"

using namespace std;

Halfling::Halfling(int x, int y):
    NPC{x, y, 'H', 100, 15, 20} {}


Halfling::~Halfling() {}

int Halfling::attack(AbstractCharacter* receiver) {
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


string Halfling::getRace() {
    return "Halfling";
}


bool Halfling::deathLoot() { return false; }

