#include "merchanthoard.h"

using namespace std;


MerchantHoard::MerchantHoard(int x, int y) : 
    Treasure{x, y, 4} {}

string MerchantHoard::identify() { return "MerchantHoard"; }
