#ifndef POT_EFFECT_H
#define POT_EFFECT_H

class PotionEffect 
{
    bool permanent;
    public:
        PotionEffect();
        virtual void usePotion(int &hp, int &atk, int &def) = 0;
        virtual void removePotion(int &hp, int &atk, int &def) = 0;
};


#endif


