#include "orc.h"

using namespace std;

Orc::Orc(int x, int y):
    NPC{x, y, 'O', 180, 30, 25} {}


void Orc::attack(AbstractCharacter* receiver) {
    // Orcs have special interaction with Goblin (50% more damage)
    if (receiver->getRace() == "goblin") {
        int damage = ceil((100 / (100 + receiver->getDef())) * getAtk()) * 1.5;
        receiver->getHP() -= damage;
        return;
    }

    // regular attack against any other race
    int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
    receiver->getHP() -= damage;
}


string Orc::getRace() {
    return "orc";
}

