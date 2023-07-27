#ifndef NPC_H
#define NPC_H

#include "abstractcharacter.h"

class NPC : public AbstractCharacter 
{
    bool hostile;
    bool hasMoved;

    public:
        NPC();
        ~NPC();
        void death();
        bool isHostile();
        bool wasMoved();
};

#endif

