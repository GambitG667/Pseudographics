#pragma once

class Global;

class Player
{
public:
	Global* global;

	Player();
	Player(Global* g);
	void GameOver();
	void GlobalGameOver();

};

