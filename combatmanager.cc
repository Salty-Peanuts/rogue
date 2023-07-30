#include "combatmanager.h"
#include "constants.h"
#include <string>
using namespace std;

CombatManager::CombatManager(int dir) : direction(dir) {}

CombatManager::~CombatManager() {}

void CombatManager::NPCAttack(GameMap& game_map, AbstractCharacter* initiator, AbstractCharacter* reciever)
{
    int damage_num = initiator->attack(reciever);
    if (damage_num == MISSED_ATTACK) {
        game_map.addAction("PC barely dodges the attack from the " + initiator->getRace() + ". ");
    } else {
        game_map.addAction("The " + initiator->getRace() + " deals " + to_string(damage_num) + " damage to PC. ");
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
    AbstractCharacter* reciever = dynamic_cast<AbstractCharacter*>(game_map.objectTilesAt(attack_x, attack_y));
    if (!reciever) { 
        game_map.addAction("Your attack whiffed. ");
        return;
    }
    int damage_num = initiator->attack(reciever);
    if (damage_num == MISSED_ATTACK) {
        game_map.addAction("You swing to attack, but the enemy dodges just in time. ");
    } else {
        game_map.addAction("PC deals " + to_string(damage_num) + " damage to the " + reciever->getRace() + " ");
        game_map.addAction("(" + to_string(reciever->getHP()) + " HP). ");
    }
    if (reciever->getHP() <= 0) {
        game_map.addAction("The " + reciever->getRace() + " is slain. ");
        game_map.deleteObject(reciever);
    }
}

void CombatManager::setDirection(int dir)
{
    direction = dir;
}
