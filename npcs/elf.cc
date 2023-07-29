#include "elf.h"

using namespace std;

Elf::Elf(int x, int y):
    NPC{x, y, 'E', 140, 30, 10} {}


void Elf::attack(AbstractCharacter* receiver) {
    // Elfs have special interaction where they attack twice 
        // (Except against Drow)

    // attacks Drow once
    if (receiver->getRace() == "drow") {
        int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
        receiver->getHP() -= damage;
        return;
    }

    // attacks twice otherwise
    for (int i = 0; i < 2; i++) {
        int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
        receiver->getHP() -= damage;
    }
    
}



string Elf::getRace() {
    return "elf";
}

