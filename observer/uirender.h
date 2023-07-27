#ifndef UIRENDER_H
#define UIRENDER_H
#include "../gamemap.h"
#include "./observer.h"

class UIRender : public Observer
{
    GameMap* subject;
    
 public:
    UIRender(GameMap* map);
    ~UIRender();
    void notify() override;
};

#endif
