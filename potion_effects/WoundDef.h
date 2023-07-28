#ifndef WOUND_DEF
#define WOUND_DEF

#include "PotionEffect.h"

class WoundDef : public PotionEffect 
{
    int def_decrease;
    public:
        WoundDef();
        void usePotion(int &hp, int &atk, int &def, int max_hp);
        void removePotion(int &hp, int &atk, int &def);
};


#endif


