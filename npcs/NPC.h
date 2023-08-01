#ifndef NPC_H
#define NPC_H

#include "../abstractcharacter.h"

using namespace std;

class NPC : public AbstractCharacter 
{
    bool hasMoved;

    protected:
        bool hostile;
        bool regular_gold_dropper;

    public:
        NPC(int x, int y, char token, int hp, int atk, int def);
        ~NPC();
        bool isHostile();
        bool wasMoved();
        string identify() override;
        void setMoved(bool input);
        virtual bool deathLoot() = 0;
};

#endif

