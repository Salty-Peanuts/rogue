#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <vector>
#include <string>
#include <math.h>

// for random number generation
#include <cstdlib>
#include <ctime>

#include "../abstractcharacter.h"
#include "../potion_effects/PoisonHealth.h"

using namespace std;


class PlayerCharacter : public AbstractCharacter 
{
    vector<PotionEffect *> potion_effects;
    int gold;
    int max_hp;
    bool has_max_hp = true;

    public:
        PlayerCharacter(int x, int y, int hp, int atk, int def);
        ~PlayerCharacter();
        void activatePotion(string pot);
        void removePotions();
        void updateGold(int value);
        string identify() override;
        int &getMaxHP();
        void toggleMaxHP(bool has_max);
        int getGold();
        virtual string getRace() = 0;
        
};

#endif

