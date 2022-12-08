#include "Global.h"
#include "Map.h"
#include "Player.h"


Global::Global()
{
	map = 0;
	player = 0;
}

void Global::MapGameOver()
{
	player->GlobalGameOver();
}

void Global::PlayerGameover()
{
	map->GlobalGameOver();
}

void Global::RoomGameOver()
{
	player->GlobalGameOver();
	map->GlobalGameOver();
}