#pragma once

class Map;
class Room;
class Player;

class Global
{
public:

	Map* map;
	Player* player;

	Global();
	void RoomGameOver();
	void MapGameOver();
	void PlayerGameover();

};

