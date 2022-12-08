#pragma once

class Global;

class Room
{
public:
	Global* global;

	Room();
	Room(Global* g);
	void GameOver();
	void GlobalGameOver();
};

