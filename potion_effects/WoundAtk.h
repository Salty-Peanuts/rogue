#ifndef WOUND_ATK
#define WOUND_ATK

#include "PotionEffect.h"
#include <string>

using namespace std;

class WoundAtk : public PotionEffect 
{
    int atk_decrease;
    public:
        WoundAtk(string race);
        ~WoundAtk();
        void usePotion(int &hp, int &atk, int &def, int max_hp) override;
        void removePotion(int &hp, int &atk, int &def) override;
        int potionStrength() override;
};


#endif


