#ifndef BOOST_DEF
#define BOOST_DEF

#include "PotionEffect.h"

class BoostDef : public PotionEffect 
{
    int def_increase;
    public:
        BoostDef();
        void usePotion(int &hp, int &atk, int &def, int max_hp);
        void removePotion(int &hp, int &atk, int &def);
};


#endif


