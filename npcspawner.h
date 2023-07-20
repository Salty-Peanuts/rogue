#include "objectspawner.h"
#include <map>
#include <string>
#include <vector>
using namespace std;

class NPCSpawner
{
    vector<string> npc_race;
    map<string, int> npc_probability;
 public:
    NPCSpawner(vector<string> npc_race, map<string, int> npc_probability);
    ~NPCSpawner();
    AbstractObject* spawn() const override;
}
