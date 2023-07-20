#include "map.h"

class RenderMap 
{
    Map* map;

 public:
    RenderMap(Map* map);
    ~RenderMap();
    void update() const override;
}
