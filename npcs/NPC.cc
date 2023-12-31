#include "NPC.h"

using namespace std;

NPC::NPC(int x, int y, char token, int hp, int atk, int def):
    AbstractCharacter{x, y, token, hp, atk, def}, 
    hasMoved{false}, hostile{true}, regular_gold_dropper{true} {}

/*
void NPC::death() {
    // implement death
}
*/

NPC::~NPC() {}


bool NPC::wasMoved() {
    return hasMoved;
}

bool NPC::isHostile() {
    return hostile;
}


string NPC::identify() {
    return "NPC";
}

void NPC::setMoved(bool input) {
    hasMoved = input;
}


bool NPC::regGoldDropper() {
    return regular_gold_dropper;
}

