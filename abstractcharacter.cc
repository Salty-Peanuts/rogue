#include "abstractcharacter.h"

using namespace std;

void AbstractCharacter::move(int dir) {
    int x = getX();
    int y = getY();

    if (dir == 0) {
        setX(x - 1);
        setY(y + 1);
    }
    if (dir == 1) {
        setX(x);
        setY(y + 1);
    }
    if (dir == 2) {
        setX(x + 1);
        setY(y + 1);
    }
    if (dir == 3) {
        setX(x - 1);
        setY(y);
    }
    if (dir == 4) {
        setX(x + 1);
        setY(y);
    }
    if (dir == 5) {
        setX(x - 1);
        setY(y - 1);
    }
    if (dir == 6) {
        setX(x);
        setY(y - 1);
    }
    if (dir == 6) {
        setX(x + 1);
        setY(y - 1);
    }
}


