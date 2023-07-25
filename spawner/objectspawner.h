#include "abstractobject.h"

class ObjectSpawner
{
  public:
    virtual ~ObjectSpawner() = default;
    virtual AbstractObject* spawn() const = 0;
};