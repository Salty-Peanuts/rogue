#include "gamemap.h"

class RenderMap 
{
    GameMap* map;

 public:
    RenderMap(GameMap* map);
    ~RenderMap();
    void update() const override;
};
