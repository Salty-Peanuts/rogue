#ifndef WOUND_DEF
#define WOUND_DEF

#include "PotionEffect.h"
#include <string>

using namespace std;

class WoundDef : public PotionEffect 
{
    int def_decrease;
    public:
        WoundDef(string race);
        ~WoundDef();
        void usePotion(int &hp, int &atk, int &def, int max_hp) override;
        void removePotion(int &hp, int &atk, int &def) override;
        int potionStrength() override;
};


#endif


