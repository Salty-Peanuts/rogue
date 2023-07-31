#ifndef BOOST_DEF
#define BOOST_DEF

#include "PotionEffect.h"

class BoostDef : public PotionEffect 
{
    int def_increase;
    public:
        BoostDef();
        ~BoostDef();
        void usePotion(int &hp, int &atk, int &def, int max_hp) override;
        void removePotion(int &hp, int &atk, int &def) override;
        int potionStrength() override;
};


#endif


