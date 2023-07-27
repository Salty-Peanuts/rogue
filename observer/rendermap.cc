#include <string>
#include <iostream>
#include "uirender.h"

UIRender::UIRender(GameMap* subject): subject{subject} {}

UIRender::~UIRender() 
{
    subject->detach(this);
}

void UIRender::notify()
{
    for (int j = 0; j < subject->getHeight() ; ++j) {
        for (int i = 0; i < subject->getWidth(); ++i) {
            if (subject->objectTilesAt(i, j) != nullptr) {
                cout << subject->objectTilesAt(i, j)->getToken();
            } else if (j == subject->getWidth() - 1) {
                cout << endl;
            } else {
                cout << subject->gameMapAt(i, j);
            }
        }
    }
}
