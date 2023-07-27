#ifndef UIRENDER_H
#define UIRENDER_H
#include "../gamemap.h"
#include "./observer.h"

class UIRender : public Observer
{
    GameMap* map;
    
 public:
    UIRender(GameMap* map);
    ~UIRender();
    void notify() override;
};

#endif
