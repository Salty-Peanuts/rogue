#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <vector>
#include <string>
#include "abstractcharacter.h"
#include "PotionEffect.h"

using namespace std;

class PlayerCharacter : public AbstractCharacter 
{
    char token = '@';
    vector<PotionEffect *> potion_effects;
    int gold;

    public:
        PlayerCharacter();
        ~PlayerCharacter();
        void usePotion(string pot);
        void removePotions();
        void death();
        void updateGold(int value);
};

#endif
