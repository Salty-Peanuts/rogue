#include "combatmanager.h"
#include "constants.h"
using namespace std;

CombatManager::CombatManager(int dir = 0) : direction(dir) {}

CombatManager::~CombatManager() {}

void CombatManager::NPCAttack(GameMap& game_map, AbstractCharacter* initiator, AbstractCharacter* reciever)
{
    int damage_num = initiator->attack(reciever);
    if (damage_num == MISSED_ATTACK) {
        game_map.last_action += "PC barely dodges the attack from " + initiator->getToken() + ". ";
    } else {
        game_map.last_action += "The " + initiator->getRace() + " deals " + to_string(damage_num) + " damage to PC. ";
    }
}

void CombatManager::playerAttack(GameMap& game_map, AbstractCharacter* initiator)
{
    int attack_x = initiator->getX();
    int attack_y = initiator->getY();
    if (direction == m_dir["no"]) {
        attack_y -= 1;
    } else if (direction == m_dir["so"]) {
        attack_y += 1;
    } else if (direction == m_dir["ea"]) {
        attack_x += 1;
    } else if (direction == m_dir["we"]) {
        attack_x -= 1;
    } else if (direction == m_dir["nw"]) {
        attack_x -= 1;
        attack_y -= 1;
    } else if (direction == m_dir["ne"]) {
        attack_x += 1;
        attack_y -= 1;
    } else if (direction == m_dir["sw"]) {
        attack_x -= 1;
        attack_y += 1;
    } else if (direction == m_dir["se"]) {
        attack_x += 1;
        attack_y += 1;
    }
    game_map.objectTilesAt(attack_x, attack_y)->attack(initiator);
}
