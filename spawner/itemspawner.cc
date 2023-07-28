#include "./itemspawner.h"
#include "../items/potion.h"
#include "../items/treasure.h"
using namespace std;

ItemSpawner::ItemSpawner(char item_type): item_type{item_type} {}

AbstractObject* ItemSpawner::spawn(int x, int y) override {
    
}

AbstractObject* ItemSpawner::spawnRandom(int x, int y) override {

}
