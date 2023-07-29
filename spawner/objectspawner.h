#ifndef OBJECTSPAWNER_H
#define OBJECTSPAWNER_H

#include "../abstractobject.h"

class ObjectSpawner
{
  public:
    virtual ~ObjectSpawner() = default;
    virtual AbstractObject* spawn(int x, int y) = 0;
    virtual AbstractObject* spawnRandom(int x, int y) = 0;
};

#endif
