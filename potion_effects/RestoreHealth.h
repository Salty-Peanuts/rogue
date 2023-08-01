#ifndef RESTORE_HEALTH
#define RESTORE_HEALTH

#include "PotionEffect.h"
#include <string>

using namespace std;

class RestoreHealth : public PotionEffect 
{
    int health_increase;
    public:
        RestoreHealth(string race);
        ~RestoreHealth();
        void usePotion(int &hp, int &atk, int &def, int max_hp) override;
        void removePotion(int &hp, int &atk, int &def) override;
        int potionStrength() override;
};


#endif


