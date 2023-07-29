#include "orc.h"

using namespace std;

Orc::Orc(int x, int y):
    NPC{x, y, 'O', 180, 30, 25} {}


void Orc::attack(AbstractCharacter* receiver) {

}


void Orc::receiveAttack(AbstractCharacter* attacker) {

}


string Orc::getRace() {
    return "orc";
}

