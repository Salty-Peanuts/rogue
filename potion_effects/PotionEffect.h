#ifndef POT_EFFECT_H
#define POT_EFFECT_H

class PotionEffect 
{
    public:
        PotionEffect();
        virtual void usePotion(int &hp, int &atk, int &def, int max_hp) = 0;
        virtual void removePotion(int &hp, int &atk, int &def) = 0;
        virtual int potionStrength() = 0;
};


#endif


