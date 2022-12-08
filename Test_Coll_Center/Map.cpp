#include <iostream>
#include "Map.h"
#include "Global.h"
#include "Player.h"
#include "Room.h"

Map::Map()
{
	global = Global();
	globalptr = &global;

	player = Player(globalptr);
	room1 = Room(globalptr);
	room2 = Room(globalptr);

	global.map = this;
	global.player = &player;

}

void Map::GameOver()
{
	std::cout << "Map game over\n";
	global.MapGameOver();
}

void Map::GlobalGameOver()
{
	std::cout << "Map global game over\n";
}