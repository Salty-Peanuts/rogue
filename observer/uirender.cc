#include <string>
#include <iostream>
#include "uirender.h"

UIRender::UIRender(GameMap* gameMap): subject{subject} {}

UIRender::~UIRender() 
{
    subject->detach(this);
}

void UIRender::notify()
{
    cout << "Race: " << subject->getPlayerCharacter() << " ";
    cout << "Gold: " << subject->getPlayerCharacter()->getGold() << " ";
    cout << "                                       ";
    cout << "Floor " << subject->getLevel() << endl;
    cout << "HP: " << subject->getPlayerCharacter()->getHP() << endl;
    cout << "Atk: " << subject->getPlayerCharacter()->getAtk() << endl;
    cout << "Def: " << subject->getPlayerCharacter()->getDef() << endl;
    cout << "Action: " << subject->getLastAction() << endl;
}
