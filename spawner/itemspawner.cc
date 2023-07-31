#include <cstdlib>
#include <ctime>
#include "./itemspawner.h"
#include "../items/potion.h"
#include "../items/treasure.h"
#include "../items/normalpile.h"
#include "../items/smallpile.h"
#include "../items/dragonhoard.h"
#include "../items/merchanthoard.h"
// may need other includes
using namespace std;

ItemSpawner::ItemSpawner(string item_type): item_type{item_type} {}

ItemSpawner::~ItemSpawner() {}

void ItemSpawner::setItemType(string item_type) 
{
    this->item_type = item_type;
}

AbstractObject* ItemSpawner::spawn(int x, int y) 
{
    if (item_type == "RH") { return new Potion(x, y, "RH"); } 
    else if (item_type == "BA") { return new Potion(x, y, "BA"); } 
    else if (item_type == "BD") { return new Potion(x, y, "BD"); }
    else if (item_type == "PH") { return new Potion(x, y, "PH"); } 
    else if (item_type == "WA") { return new Potion(x, y, "WA"); } 
    else if (item_type == "WD") { return new Potion(x, y, "WD"); } 
    else if (item_type == "normal") { return new NormalPile(x, y); } 
    else if (item_type == "small") { return new SmallPile(x, y); } 
    else if (item_type == "dragon") { return new DragonHoard(x, y); }
    else if (item_type == "merchant") {return new MerchantHoard(x, y); }
    else { return nullptr; }
}

AbstractObject* ItemSpawner::spawnRandom(int x, int y) 
{
    srand(time(0));
    if (item_type == "Potion") {
        int potion_index = rand() % potion_probability;
        auto potion_iter = potion_type.begin();
        while (potion_iter != potion_type.end()) {
            if (potion_iter->second == potion_index) {
                setItemType(potion_iter->first);
                break;
            }
            potion_iter++;
        }
    } else if (item_type == "Treasure") {
        int treasure_index = rand() % treasure_probability;
        auto treasure_iter = treasure_type.begin();
        int total = 0;
        while (total < treasure_index) {
            total += treasure_iter->second;
            treasure_iter++;
        }
        setItemType(treasure_iter->first);
    }
    return spawn(x, y);
}

