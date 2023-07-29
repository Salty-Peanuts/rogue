#ifndef BOOST_ATK
#define BOOST_ATK

#include "PotionEffect.h"

class BoostAtk : public PotionEffect 
{
    int atk_increase;
    public:
        BoostAtk();
        void usePotion(int &hp, int &atk, int &def, int max_hp);
        void removePotion(int &hp, int &atk, int &def);
        int potionStrength() override;
};


#endif


