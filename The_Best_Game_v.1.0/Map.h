#pragma once
#include "GameObject.h"
#include "Room.h"
#include "Player.h"
#include <vector>
#include <string>

class Global;


class Map
{
private:

	int HEIGHT = 60;
	int WIDTH = 60;

	int HEIGHT_ROOM = 20;
	int WIDTH_ROOM = 60;

	char* simbol_array;

	Room* ActivRoom;
	Player* player;
	Global* global;

	std::string log;

	std::vector <std::vector <GameObject*>> MapArr;
	std::vector <Room*> Rooms;

public:

	Map(Global* global);
	~Map();
	std::vector <std::vector <GameObject*>> FromToCoordinate(Coordinates begin_coord, Coordinates end_coord);
	GameObject* OnCoordinate(Coordinates coord);
	
	void Print();
	void PrintPlayerInfo();
	void PrintLog();
	void ToLog(const std::string);
	void ClearLog();

	void LoocActivRoom();
	void Up();
	void Down();
	void Right();
	void Left();
	void Use(int index);

};