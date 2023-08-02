#ifndef ITEMSPAWNER_H
#define ITEMSPAWNER_H

#include "objectspawner.h"
#include <map>
#include <string>
#include <vector>
using namespace std;

class ItemSpawner : public ObjectSpawner
{
    string item_type;
    int potion_probability = 6;
    int treasure_probability = 8;
    map<string, int> potion_type {
        {"RH", 0},
        {"BA", 1},
        {"BD", 2},
        {"PH", 3},
        {"WA", 4},
        {"WD", 5}
    };
    map<string, int> treasure_type {
        {"normal", 5},
        {"small", 1},
        {"dragon", 2}
    };
 public:
    ItemSpawner(string item_type = "RH");
    ~ItemSpawner();
    AbstractObject* spawn(int x, int y) override;
    AbstractObject* spawnRandom(int x, int y) override;
    void setItemType(string item_type);
};

#endif
