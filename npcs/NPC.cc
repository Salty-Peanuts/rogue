#include "NPC.h"

NPC::NPC():
    AbstractCharacter{}, hostile{true}, hasMoved{false} {}


void NPC::death() {
    // implement death
}

bool NPC::isHostile() {
    return hostile;
}

bool NPC::wasMoved() {
    return hasMoved;
}

