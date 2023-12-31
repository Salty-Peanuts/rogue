#include "combatmanager.h"
#include "constants.h"
#include "spawner/itemspawner.h"
#include "npcs/NPC.h"
#include "npcs/merchant.h"
#include "npcs/dragon.h"
#include "npcs/human.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
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

void CombatManager::playerAttack(GameMap *game_map, AbstractCharacter* initiator)
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
    if (game_map->objectTilesAt(attack_x, attack_y) == nullptr) {
        game_map->addAction("Your attack whiffed. ");
        return;
    }

    AbstractCharacter* reciever = dynamic_cast<AbstractCharacter*>(game_map->objectTilesAt(attack_x, attack_y));
    
    if (!reciever) {
        game_map->addAction("Your attack whiffed. ");
        return;
    }

    if (reciever->getRace() == "Merchant") {
        Merchant* merchant = dynamic_cast<Merchant*>(reciever);
        merchant->makeAggravated();
    }

    int damage_num = initiator->attack(reciever);
    if (damage_num == MISSED_ATTACK) {
        game_map->addAction("You swing to attack, but the enemy dodges just in time. ");
    } else if (reciever->getHP() <= 0) {
        game_map->addAction("PC deals " + to_string(damage_num) + " damage to the " + reciever->getRace() + " ");
        game_map->addAction("(0 HP). ");
    } else {
        game_map->addAction("PC deals " + to_string(damage_num) + " damage to the " + reciever->getRace() + " ");
        game_map->addAction("(" + to_string(reciever->getHP()) + " HP). ");
    }
    if (reciever->getHP() <= 0) {
        NPC* npc = dynamic_cast<NPC*>(reciever);
        if (!npc) {
            return;
        }
        // update if dragon dies
        Dragon* dragon = dynamic_cast<Dragon*>(reciever);
        if (dragon) {
            dragon->getDragonHoard()->dragonDies();
        }
        int x = reciever->getX();
        int y = reciever->getY();
        game_map->addAction("The " + npc->getRace() + " is slain. ");
        // add drop gold logic here
        if (npc->deathLoot()) {
            game_map->deleteObject(npc);
            ItemSpawner *item_spawner = new ItemSpawner("merchant");
            game_map->addObject(item_spawner->spawn(x, y));
            delete item_spawner;
        } else if (npc->regGoldDropper()) { // I USE RANDOM HERE
            int gold_type = 1 + rand() % 2;
            if (gold_type == 1) {
                game_map->deleteObject(npc);
                game_map->getPlayerCharacter()->updateGold(1);
            } else {
                game_map->deleteObject(npc);
                game_map->getPlayerCharacter()->updateGold(2);
            }
        }
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
