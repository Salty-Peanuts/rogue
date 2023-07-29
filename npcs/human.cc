#include "human.h"

using namespace std;

Human::Human(int x, int y):
    NPC{x, y, 'H', 140, 20, 20} {}


void Human::attack(AbstractCharacter* receiver) {

}


void Human::receiveAttack(AbstractCharacter* attacker) {

}

string Human::getRace() {
    return "human";
}

