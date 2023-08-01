#include "human.h"
#include "../spawner/itemspawner.h"

using namespace std;

Human::Human(int x, int y):
    NPC{x, y, 'H', 140, 20, 20} { 
        regular_gold_dropper = false;
    }

Human::~Human() {}


int Human::attack(AbstractCharacter* receiver) {
    // handles 50% of npc missing attack
    int random = rand() % 2;

    if (random == 1) {
        return MISSED_ATTACK;
    }

    float damage_calc = (100 / (100 + receiver->getDef())) * getAtk();
    int damage = ceil(damage_calc);
    receiver->getHP() -= damage;
    return damage;
}


bool Human::deathLoot() { return true; }



string Human::getRace() {
    return "Human";
}

