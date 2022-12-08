#pragma once
#include "Player.h"
#include "Room.h"
#include "Global.h"

class Global;
class Room;
class Player;


class Map
{
public:

	Global global;
	Global* globalptr;
	Player player;
	Room room1;
	Room room2;


	Map();
	void GameOver();
	void GlobalGameOver();
};

