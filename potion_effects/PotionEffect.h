#ifndef POT_EFFECT_H
#define POT_EFFECT_H

class PotionEffect 
{
    bool permanent;
    public:
        virtual void usePotion(int &hp, int &atk, int &def);
        virtual void removePotion(int &hp, int &atk, int &def);
};


#endif


