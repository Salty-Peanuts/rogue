#ifndef STAIRSPAWNER_H
#define STAIRSPAWNER_H

#include "objectspawner.h"

class StairSpawner : public ObjectSpawner
{
 public:
    StairSpawner();
    ~StairSpawner();
    AbstractObject* spawn(int x, int y) override;
    AbstractObject* spawnRandom(int x, int y) override;
};

#endif
