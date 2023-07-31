CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -Werror=vla
EXEC = cc3k+
OBJECTS = main.o gamemap.o constants.o combatmanager.o abstractobject.o abstractcharacter.o spawner/itemspawner.o spawner/npcspawner.o spawner/objectspawner.o spawner/stairspawner.o potion_effects/BoostAtk.o potion_effects/BoostDef.o potion_effects/PoisonHealth.o potion_effects/PotionEffect.o potion_effects/RestoreHealth.o potion_effects/WoundAtk.o potion_effects/WoundDef.o npcs/dragon.o npcs/dwarf.o npcs/elf.o npcs/halfling.o npcs/human.o npcs/merchant.o npcs/NPC.o npcs/orc.o items/dragonhoard.o items/item.o items/merchanthoard.o items/normalpile.o items/potion.o items/smallpile.o items/treasure.o floortiles/floortiles.o floortiles/ceiling.o floortiles/doorway.o floortiles/floor.o floortiles/passage.o floortiles/stair.o floortiles/walls.o characters/drow.o characters/goblin.o characters/playercharacter.o characters/shade.o characters/troll.o characters/vampire.o controller.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC}