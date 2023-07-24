#include "objectspawner.h"
#include <map>
#include <string>
using namespace std;

class ItemSpawner
{
    vector<string> item_type;
    map<string, int> item_probability;
 public:
    ItemSpawner(vector<string> item_type, map<string, int> item_probability);
    ~ItemSpawner();
    AbstractObject* spawn() const override;
}
