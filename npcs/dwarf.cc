#include "dwarf.h"

using namespace std;

Dwarf::Dwarf(int x, int y):
    NPC{x, y, 'W', 100, 20, 30} {}


Dwarf::~Dwarf() {}

int Dwarf::attack(AbstractCharacter* receiver) {
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


string Dwarf::getRace() {
    return "Dwarf";
}


bool Dwarf::deathLoot() { return false; }

