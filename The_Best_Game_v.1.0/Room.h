#pragma once
#include "GameObject.h"
#include "RandPacer.h"
#include "Screen.h"
#include <vector>


class Room
{
private:

	Coordinates minCoord, maxCoord;

	int NamberOfRoom;

	int HEIGHT_ROOM;
	int WIDTH_ROOM;

	Screen screen;

	std::vector <std::vector <GameObject*>> RoomArray;

public:
	Room();
	Room(int number, int HEIGHT_ROOM, int WIDTH_ROOM);
	Room(std::vector <std::vector <GameObject*>>, char* simb_arr, int number, int HEIGHT_ROOM, int WIDTH_ROOM);
	void SetCoordinates(Coordinates minCoord, Coordinates maxCoord);
	Coordinates GetMax();
	Coordinates GetMin();
	void wall(Pacer* pacer, std::vector <std::vector <GameObject*>> arr, int SegmentHeight, int SegmentWidth, int width);
	void BuildRandomRoom1(std::vector <std::vector <GameObject*>> arr, int height, int width);
	bool IsInRoom(Coordinates coord);
	void BuildDoor(int x, int y);
	void PrintRoom();

};