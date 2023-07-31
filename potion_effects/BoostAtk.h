#ifndef BOOST_ATK
#define BOOST_ATK

#include "PotionEffect.h"

class BoostAtk : public PotionEffect 
{
    int atk_increase;
    public:
        BoostAtk();
        ~BoostAtk();
        void usePotion(int &hp, int &atk, int &def, int max_hp) override;
        void removePotion(int &hp, int &atk, int &def) override;
        int potionStrength() override;
};


#endif


