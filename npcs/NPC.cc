#include "NPC.h"

NPC::NPC(int x, int y, char token, int hp, int atk, int def):
    AbstractCharacter{x, y, token, hp, atk, def}, hostile{true}, hasMoved{false} {}


void NPC::death() {
    // implement death
}

bool NPC::isHostile() {
    return hostile;
}

bool NPC::wasMoved() {
    return hasMoved;
}

