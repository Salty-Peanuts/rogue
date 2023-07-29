#include "merchant.h"

using namespace std;



Merchant::Merchant(int x, int y):
    NPC{x, y, 'M', 30, 70, 5} { hostile = aggravated; }

// might have to rewrite for 

void Merchant::attack(AbstractCharacter* receiver) {
    int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
    receiver->getHP() -= damage;
}


void Merchant::receiveAttack(AbstractCharacter* attacker) {

}


string Merchant::getRace() {
    return "merchant";
}

void Merchant::makeAggravated() {
    aggravated = true;
    hostile = true;
}

