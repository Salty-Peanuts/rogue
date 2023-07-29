#include "drow.h"
#include "constants.h"

using namespace std;

Drow::Drow(int x, int y) :
    PlayerCharacter{x, y, 150, 25, 15} {}


void Drow::attack(AbstractCharacter *receiver) {
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

}


string Drow::getRace() {
    return "drow";
}


