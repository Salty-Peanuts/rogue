#ifndef ITEMSPAWNER_H
#define ITEMSPAWNER_H

#include "objectspawner.h"
#include <map>
#include <string>
#include <vector>
using namespace std;

class ItemSpawner : public ObjectSpawner
{
    vector<string> item_type;
    map<string, int> item_probability;
 public:
    ItemSpawner(vector<string> item_type, map<string, int> item_probability);
    ~ItemSpawner();
    AbstractObject* spawn() const override;
};

#endif
