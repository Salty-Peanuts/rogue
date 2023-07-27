#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <vector>
#include <PotionEffect.h>

class PlayerCharacter : public AbstractObject
{
    char token = '@';
    vector<PotionEffect *> potion_effects;
    int gold;

    public:
        void usePotion(string pot);
        void removePotions();
        void death();
        void updateGold(int value);
};

#endif