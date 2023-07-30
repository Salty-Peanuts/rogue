#ifndef NPCSPAWNER_H
#define NPCSPAWNER_H

#include "objectspawner.h"
#include <map>
#include <string>
#include <vector>
using namespace std;

class NPCSpawner : public ObjectSpawner
{
    string npc_race;
    int npc_probability = 18;
    map<string, int> npc_type {
        {"Human", 4},
        {"Dwarf", 3},
        {"Halfling", 5},
        {"Elf", 2},
        {"Orc", 2},
        {"Merchant", 2}
    };
 public:
    NPCSpawner(string npc_race = "Human");
    ~NPCSpawner();
    AbstractObject* spawn(int x, int y) override;
    AbstractObject* spawnRandom(int x, int y) override;
    void setNPCRace(string race);
};

#endif
