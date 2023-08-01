#include "./npcspawner.h"
#include "../npcs/NPC.h"
#include "../npcs/dragon.h"
#include "../npcs/dwarf.h"
#include "../npcs/elf.h"
#include "../npcs/halfling.h"
#include "../npcs/human.h"
#include "../npcs/merchant.h"
#include "../npcs/orc.h"
using namespace std;

NPCSpawner::NPCSpawner(string npc_race): npc_race{npc_race} {}

NPCSpawner::~NPCSpawner() {}

void NPCSpawner::setNPCRace(string npc_race) 
{
    this->npc_race = npc_race;
}
AbstractObject* NPCSpawner::spawn(int x, int y) 
{
    if (npc_race == "Human") { return new Human(x, y); }
    if (npc_race == "Dwarf") { return new Dwarf(x, y); }
    if (npc_race == "Halfling") { return new Halfling(x, y); }
    if (npc_race == "Elf") { return new Elf(x, y); }
    if (npc_race == "Orc") { return new Orc(x, y); }
    if (npc_race == "Merchant") { return new Merchant(x, y); }
    if (npc_race == "Dragon") { return new Dragon(x, y, nullptr); }
    return nullptr; 
}

AbstractObject* NPCSpawner::spawnRandom(int x, int y) 
{
    srand(time(0));
    int npc_index = rand() % npc_probability;
    auto npc_iter = npc_type.begin();
    int total = 0;
    while (total < npc_index) {
        total += npc_iter->second;
        npc_iter++;
    }
    setNPCRace(npc_iter->first);
    return spawn(x, y);
}
