#include <iostream>
#include "Room.h"
#include "Global.h"

Room::Room()
{
	global = 0;
}

Room::Room(Global* g)
{
	global = g;
}

void Room::GameOver()
{
	std::cout << "Room game over\n";
	global->RoomGameOver();
}

void Room::GlobalGameOver()
{
	std::cout << "Room global game over\n";
}