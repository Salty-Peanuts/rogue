#include "./itemspawner.h"
#include "../items/potion.h"
#include "../items/treasure.h"
using namespace std;

ItemSpawner::ItemSpawner(char item_type): item_type{item_type} {}

AbstractObject* ItemSpawner::spawn(int x, int y) override {
    if (item_type == 'P') {
        return new Potion(x, y, "RH");
    } else if (item_type == 'G') {
        return new Treasure(x, y, "normal");
    }
}

AbstractObject* ItemSpawner::spawnRandom(int x, int y) override {
    srand(time(0));
    if (item_type == 'P') {
        int potion_type = rand() % potion_probability;
        if (potion_type == 0) {
            return new Potion(x, y, "RH");
        } else if (potion_type == 1) {
            return new Potion(x, y, "BA");
        } else if (potion_type == 2) {
            return new Potion(x, y, "BD");
        } else if (potion_type == 3) {
            return new Potion(x, y, "PH");
        } else if (potion_type == 4) {
            return new Potion(x, y, "WA");
        } else {
            return new Potion(x, y, "WD");
        }
    } else if (item_type == 'G') {
        int treasure_type = rand() % treasure_probability;
        if (treasure_type <= 3 && treasure_type > 1) {
            setItemType('D');
            return new DragonHoard(x, y, "dragon");
        } else if (treasure_type == 1) {
            return new Treasure(x, y, "small");
        } else {
            return new Treasure(x, y, "normal");
        }
    }
}
