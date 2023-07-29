#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <vector>
#include <string>
#include "abstractcharacter.h"
#include "PotionEffect.h"

using namespace std;

class PlayerCharacter : public AbstractCharacter 
{
    vector<PotionEffect *> potion_effects;
    int gold;
    int max_hp;

    public:
        PlayerCharacter(int x, int y, int hp, int atk, int def);
        ~PlayerCharacter();
        void usePotion(string pot);
        void removePotions();
        void death();
        void updateGold(int value);
        string identify();
        int getMaxHP();
        virtual string getRace();
        
};

#endif
