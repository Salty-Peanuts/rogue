#include <vector>
#include <string>
#include <map>
#include "combatmanager.h"
#include "playercharacter.h"
#include "NPC.h"
#include "item.h"
#include "chamber.h"
using namespace std;


class Map 
{
    vector<vector<char>> game_map;
    vector<NPC*> tiles_NPC;
    vector<Item*> tiles_item;
    char player_race;
    PlayerCharacter* player_character;
    CombatManager* attack;
    map<string, int> direction_map;
    vector<Chamber*> chambers;
    bool npc_movement;

 public:
    Map(vector<vector<char>> game_map, 
        vector<NPC*> tiles_NPC, 
        vector<Item*> tiles_item, 
        char player_race, 
        PlayerCharacter* 
        player_character, 
        CombatManager* attack, 
        map<string, int> direction_map, 
        vector<Chamber*> chambers, 
        bool npc_movement);
    ~Map();
    void start(PlayerCharacter* pc);
    void addObject(AbstractObject* object);
    void deleteObject(AbstractObject* object);
    void moveCharacter(PlayerCharacter* pc, int dir);
    bool validMove(AbstractObject* object, int dir);
    void usePotion(PlayerCharacter&);
    void moveNPC();
    void reset();
    bool isStair(PlayerCharacter* pc, int dir);
    virtual update() const = 0;
};
