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
    srand((unsigned) time(NULL));
    int random = rand() % 2;

    if (random == 1) {
        return MISSED_ATTACK;
    }

    int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
    receiver->getHP() -= damage;
    return damage;
}


void Human::death() {}



string Human::getRace() {
    return "human";
}

