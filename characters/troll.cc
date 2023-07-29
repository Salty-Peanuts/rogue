#include "troll.h"
#include "constants.h"

using namespace std;

Troll::Troll(int x, int y) :
    PlayerCharacter{x, y, 120, 25, 15} {}

void Troll::attack(AbstractCharacter *receiver) {
    // deals with if receiver is halfling (50% chance of missing attack)
    if (receiver->getRace() == "halfling") {
        // randomly produces either 0 or 1
        srand((unsigned) time(NULL));
        int random = rand() % 2;

        if (random == 1) {
            return;
        }
    }

    int damage = ceil((100 / (100 + receiver->getDef())) * getAtk());
    receiver->getHP() -= damage;

    if (receiver->getHP() <= 0) {
        receiver->death();
    }
}

void Troll::receiveAttack(AbstractCharacter *attacker) {
    // implement
}

string Troll::getRace() {
    return "troll";
}

