#include "constants.h"
#include <string>
#include <map>

using namespace std;

const int col = 79;
const int row = 25;
map<string, int> m_dir{{"nw", 1},
                        {"no", 2},
                        {"ne", 3}, 
                        {"we", 4},
                        {"ea", 5},
                        {"sw", 6},
                        {"so", 7},
                        {"se", 8}};


const int MISSED_ATTACK = -1;
