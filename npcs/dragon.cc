#include "dragon.h"

using namespace std;

Dragon::Dragon(int x, int y):
    NPC{x, y, 'D', 150, 20, 20} {}


void Dragon::attack(AbstractCharacter* receiver) {

}


void Dragon::receiveAttack(AbstractCharacter* attacker) {

}


string Dragon::getRace() {
    return "dragon";
}

