#include "Global.h"
#include "Item.h"
#include "Game.h"
#include "Player.h"


void Global::Subscribe(Game* game)
{
	this->game = game;
}
void Global::Subscribe(Player* player)
{
	this->player = player;
}
void Global::PlayerDie()
{
	game->restart = true;
}
void Global::UseKey()
{
	game->win = true;
}
void Global::UseHealItem()
{
	player->Heal(10);
}
void Global::TrapPlayer()
{
	player->TakeDamage(10);
}
void Global::PlayerTakeHealItem()
{
	std::cout << "GTakeHI";
	player->TakeItem(new HealItem(this));

}
void Global::PlayerTakeKey()
{
	player->TakeItem(new Key(this));
	std::cout << "GTakeKey";
}