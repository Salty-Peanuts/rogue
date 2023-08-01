#include "orc.h"

using namespace std;

Orc::Orc(int x, int y):
    NPC{x, y, 'O', 180, 30, 25} {}

Orc::~Orc() {}


int Orc::attack(AbstractCharacter* receiver) {
    // handles 50% of npc missing attack
    int random = rand() % 2;

    if (random == 1) {
        return MISSED_ATTACK;
    }


    // Orcs have special interaction with Goblin (50% more damage)
    if (receiver->getRace() == "Goblin") {
        float damage_calc = (100 / (100 + receiver->getDef())) * getAtk() * 1.5;
        int damage = ceil(damage_calc);
        receiver->getHP() -= damage;
        return damage;
    }

    // regular attack against any other race
    float damage_calc = (100 / (100 + receiver->getDef())) * getAtk();
    int damage = ceil(damage_calc);
    receiver->getHP() -= damage;
    return damage;
}


string Orc::getRace() {
    return "Orc";
}



bool Orc::deathLoot() { return false; }

