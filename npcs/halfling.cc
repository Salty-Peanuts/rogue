#include "halfling.h"

using namespace std;

Halfling::Halfling(int x, int y):
    NPC{x, y, 'H', 100, 15, 20} {}


void Halfling::attack(AbstractCharacter* receiver) {

}


void Halfling::receiveAttack(AbstractCharacter* attacker) {

}


string Halfling::getRace() {
    return "halfling";
}


