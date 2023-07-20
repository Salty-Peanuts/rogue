#include "map.h"

class UIRender
{
    Map* map;
    
 public:
    UIRender(Map* map);
    ~UIRender();
    void update() const override;
}
