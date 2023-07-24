#include "abstractobject.h"

class ObjectSpawner
{
  public:
    virtual AbstractObject* spawn() const = 0;
}