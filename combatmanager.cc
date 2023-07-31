#include "combatmanager.h"
#include "constants.h"
#include <string>
using namespace std;

CombatManager::CombatManager(int dir) : direction(dir) {}

CombatManager::~CombatManager() {}

void CombatManager::NPCAttack(GameMap *game_map, AbstractCharacter* initiator, AbstractCharacter* reciever)
{
    int damage_num = initiator->attack(reciever);
    if (damage_num == MISSED_ATTACK) {
        game_map->addAction("PC barely dodges the attack from the " + initiator->getRace() + ". ");
    } else {
        game_map->addAction("The " + initiator->getRace() + " deals " + to_string(damage_num) + " damage to PC. ");
    }
}

void CombatManager::playerAttack(GameMap *game_map, AbstractCharacter* initiator, AbstractCharacter* reciever)
{
    int damage_num = initiator->attack(reciever);
    if (damage_num == MISSED_ATTACK) {
        game_map->addAction("You swing to attack, but the enemy dodges just in time. ");
    } else {
        game_map->addAction("PC deals " + to_string(damage_num) + " damage to the " + reciever->getRace() + " ");
        game_map->addAction("(" + to_string(reciever->getHP()) + " HP). ");
    }
    if (reciever->getHP() <= 0) {
        game_map->addAction("The " + reciever->getRace() + " is slain. ");
        game_map->deleteObject(reciever);
        // add drop gold logic here
    }
}
/*
bool CombatManager::isValid(GameMap *game_map, AbstractCharacter* initiator, AbstractCharacter* reciever) {

}
*/

void CombatManager::setDirection(int dir)
{
    direction = dir;
}
