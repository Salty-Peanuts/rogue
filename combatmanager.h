#include "map.h"
#include "abstractcharacter.h"
using namespace std;

class CombatManager
{
    int direction;

 public:
    CombatManager(int dir);
    ~CombatManager();
    void NPCAttack(Map& map, AbstractCharacter* initiator, AbstractCharacter* reciever);
    void playerAttack(Map& map, AbstractCharacter* initiator, AbstractCharacter* reciever);
    bool isValid(Map& map, AbstractCharacter* initiator, AbstractCharacter* reciever);
}
