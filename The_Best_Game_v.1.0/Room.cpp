#include "Room.h"
#include <vector>

Room::Room()
{
	int NamberOfRoom = 0;

	int HEIGHT_ROOM = 20;
	int WIDTH_ROOM = 40;

	RoomArray.reserve(HEIGHT_ROOM * WIDTH_ROOM);
}

Room :: Room(int number, int HEIGHT_ROOM, int WIDTH_ROOM)
{
	this->NamberOfRoom = number;

	this->HEIGHT_ROOM = HEIGHT_ROOM;
	this->WIDTH_ROOM = WIDTH_ROOM;

	RoomArray.reserve(HEIGHT_ROOM*WIDTH_ROOM);
}

Room::Room(std::vector <std::vector <GameObject*>> RoomArr, char* simb_arr, int number, int HEIGHT_ROOM, int WIDTH_ROOM)
{
	this->NamberOfRoom = number;

	this->HEIGHT_ROOM = HEIGHT_ROOM;
	this->WIDTH_ROOM = WIDTH_ROOM;

	screen = Screen(ScreenArray(RoomArr, WIDTH_ROOM, HEIGHT_ROOM), simb_arr);

	RoomArray = RoomArr;
	BuildRandomRoom1(RoomArray, HEIGHT_ROOM, WIDTH_ROOM);
}

bool Room::IsInRoom(Coordinates coord)
{
	return coord >= minCoord && coord < maxCoord ? true : false;
}

void Room::wall(Pacer* pacer, std::vector <std::vector <GameObject*>> arr , int SegmentHeight, int SegmentWidth, int width)
{
	int Sx = 0;
	int Sy = 0;

	for (int i = 0; i < 4; ++i)
	{
		(*pacer).JampOn(arr, width, (rand()) % (SegmentWidth / 2) + 1, SegmentWidth, &Sx);
		(*pacer).TurnLeft();
		(*pacer).JampOn(arr, width, (rand()) % (SegmentHeight / 2) + 1, SegmentHeight, &Sy);
		(*pacer).TurnRight();
	}
	(*pacer).JampOn(arr, width, SegmentWidth - Sx, SegmentWidth, &Sx);
	(*pacer).TurnLeft();
	(*pacer).JampOn(arr, width, SegmentHeight - Sy, SegmentHeight, &Sy);
	(*pacer).JampOn(arr, width, 2, SegmentHeight + 2, &Sy);
}

void Room::BuildRandomRoom1(std::vector <std::vector <GameObject*>> arr, int height, int width)
{
	Pacer pacer = Pacer(new RightStateOfPacer(), width / 2, 0, width, height, -1, -1, 1);
	arr[pacer.coordinates.y][pacer.coordinates.x]->SetState(new WallState());
	wall(&pacer, arr, height / 2 - 1, width / 2, width);
	wall(&pacer, arr, width / 2 - 1, height / 2, width);
	wall(&pacer, arr, height / 2 - 1, width / 2, width);
	wall(&pacer, arr, width / 2 - 1, height / 2, width);
	for (int i = 0; i < height; ++i)
	{
		int j = 0;
		while (arr[i][j]->GetInfo() != '#' && j < width)
		{
			arr[i][j]->Hide();
			++j;
		}
		j = width - 1;
		while (arr[i][j]->GetInfo() != '#' && 0 < j)
		{
			arr[i][j]->Hide();
			--j;
		}
	}
}

void Room::SetCoordinates(Coordinates minCoord, Coordinates maxCoord)
{
	this->minCoord = minCoord;
	this->maxCoord = maxCoord;
}

Coordinates Room::GetMax()
{
	return maxCoord;
}

Coordinates Room::GetMin()
{
	return minCoord;
}


void Room::BuildDoor(int x, int y)
{
	RoomArray[y][x]->SetState(new VoidState());
}

void Room::PrintRoom()
{
	screen.print();
}