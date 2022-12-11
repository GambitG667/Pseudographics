#pragma once

class Player;
class Game;

class Global
{
private:

	Player* player;
	Game* game;
public:
	Global(){}
	void Subscribe(Game* map);
	void Subscribe(Player* player);
	void PlayerDie();
	void UseKey();
	void UseHealItem();
	void TrapPlayer();
	void PlayerTakeHealItem();
	void PlayerTakeKey();

};

