#include <iostream>
#include "Player.h"
#include "Global.h"


Player::Player()
{
	global = 0;
}

Player::Player(Global* g)
{
	global = g;
}

void Player::GameOver()
{
	std::cout << "Player Game Over\n";
	global->PlayerGameover();
}


void Player::GlobalGameOver()
{
	std::cout << "Player Global Game Over\n";
}