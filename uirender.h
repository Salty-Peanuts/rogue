#include "gamemap.h"

class UIRender
{
    GameMap* map;
    
 public:
    UIRender(GameMap* map);
    ~UIRender();
    void update() const override;
};
