#ifndef RENDERMAP_H
#define RENDERMAP_H
#include "../gamemap.h"
#include "./observer.h"

class RenderMap : public Observer
{
    GameMap* map;

 public:
    RenderMap(GameMap* map);
    ~RenderMap();
    void notify() override;
};

#endif
