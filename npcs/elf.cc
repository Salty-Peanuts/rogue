#include "elf.h"

using namespace std;

Elf::Elf(int x, int y):
    NPC{x, y, 'E', 140, 30, 10} {}

Elf::~Elf() {}


int Elf::attack(AbstractCharacter* receiver) {
    // handles 50% of npc missing attack
    int random = rand() % 2;

    if (random == 1) {
        return MISSED_ATTACK;
    }

    // Elfs have special interaction where they attack twice 
        // (Except against Drow)

    int damage = 0;

    // attacks Drow once
    if (receiver->getRace() == "Drow") {
        float damage_calc = (100.0 / (100.0 + receiver->getDef())) * getAtk();
        damage = ceil(damage_calc);
        receiver->getHP() -= damage;
        return damage;
    }

    // attacks twice otherwise
    for (int i = 0; i < 2; i++) {
        float damage_calc = (100.0 / (100.0 + receiver->getDef())) * getAtk();
        damage = ceil(damage_calc);
        receiver->getHP() -= damage;
    }
    return damage * 2;
    
}



string Elf::getRace() {
    return "Elf";
}


bool Elf::deathLoot() { return false; }

