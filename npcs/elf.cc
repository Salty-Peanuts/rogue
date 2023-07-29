#include "elf.h"

using namespace std;

Elf::Elf(int x, int y):
    NPC{x, y, 'E', 140, 30, 10} {}


int Elf::attack(AbstractCharacter* receiver) {
    // handles 50% of npc missing attack
    srand((unsigned) time(NULL));
    int random = rand() % 2;

    if (random == 1) {
        return MISSED_ATTACK;
    }

    // Elfs have special interaction where they attack twice 
        // (Except against Drow)

    int damage = 0;

    // attacks Drow once
    if (receiver->getRace() == "drow") {
        damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
        receiver->getHP() -= damage;
        return damage;
    }

    // attacks twice otherwise
    for (int i = 0; i < 2; i++) {
        damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
        receiver->getHP() -= damage;
    }
    return damage * 2;
    
}



string Elf::getRace() {
    return "elf";
}

