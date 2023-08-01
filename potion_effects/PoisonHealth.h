#ifndef POISON_HEALTH
#define POISON_HEALTH

#include "PotionEffect.h"
#include <string>

using namespace std;

class PoisonHealth : public PotionEffect 
{
    int health_decrease;
    public:
        PoisonHealth(string race);
        ~PoisonHealth();
        void usePotion(int &hp, int &atk, int &def, int max_hp) override;
        void removePotion(int &hp, int &atk, int &def) override;
        int potionStrength() override;
};


#endif


