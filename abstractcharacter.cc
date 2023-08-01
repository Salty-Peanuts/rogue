#include "abstractcharacter.h"
#include "constants.h"

using namespace std;

AbstractCharacter::AbstractCharacter(int x, int y, char token, int hp, int atk, int def):
    AbstractObject{x, y, token}, hp{hp}, atk{atk}, def{def}, traversible{false} {}


void AbstractCharacter::move(int dir) {
    int x = getX();
    int y = getY();

    if (dir == m_dir["no"]) {
        setX(x);
        setY(y - 1);
    }
    if (dir == m_dir["so"]) {
        setX(x);
        setY(y + 1);
    }
    if (dir == m_dir["ea"]) {
        setX(x + 1);
        setY(y);
    }
    if (dir == m_dir["we"]) {
        setX(x - 1);
        setY(y);
    }
    if (dir == m_dir["ne"]) {
        setX(x + 1);
        setY(y - 1);
    }
    if (dir == m_dir["nw"]) {
        setX(x - 1);
        setY(y - 1);
    }
    if (dir == m_dir["se"]) {
        setX(x + 1);
        setY(y + 1);
    }
    if (dir == m_dir["sw"]) {
        setX(x - 1);
        setY(y + 1);
    }
}


int & AbstractCharacter::getHP() {
    return hp;
}


int & AbstractCharacter::getAtk() {
    return atk;
}


int & AbstractCharacter::getDef() {
    return def;
}



bool AbstractCharacter::isTraversible(AbstractObject *traveler) {
    return false;
}


