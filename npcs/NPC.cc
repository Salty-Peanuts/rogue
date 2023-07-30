#include "NPC.h"

using namespace std;

NPC::NPC(int x, int y, char token, int hp, int atk, int def):
    AbstractCharacter{x, y, token, hp, atk, def}, hostile{true}, hasMoved{false} {}


void NPC::death() {
    // implement death
}

bool NPC::wasMoved() {
    return hasMoved;
}

string NPC::identify() {
    return "NPC";
}

