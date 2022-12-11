#include "Player.h"
#include "Global.h"
#include "Item.h"

Player::Player(Coordinates coord, Global* global)
{
	this->global = global;
	HP = 20;
	coordinates = coord;
}

Player::~Player()
{
	for (Item* i : Bag)
	{
		delete i;
	}
}

Coordinates Player::GetCoordinates()
{
	return coordinates;
}


void Player::Move(const std::string str)
{
	if (str == "UP")
	{
		coordinates.y += 1;
	}
	else if (str == "DOWN")
	{
		coordinates.y -= 1;
	}
	else if (str == "LEFT")
	{
		coordinates.x -= 1;
	}
	else if (str == "RIGHT")
	{
		coordinates.x += 1;
	}
}

void Player::TakeItem(Item* item)
{
	Bag.push_back(item);
}

void Player::Use(int namber)
{
	if (namber >= 0 && namber < Bag.size())
	{
		Bag[namber]->Use();
		Bag.erase(Bag.begin() + namber);
	}
}

void Player::PrintInfo()
{
	std::cout << "HP: " << HP << std::endl;
	
	std::cout << "In the Bag:"<< std::endl;

	for (int i = 0; i < Bag.size(); ++i)
	{
		std::cout << i<<": "<< Bag[i]->name << std::endl;
	}
}

void Player::TakeDamage(int damage)
{
	if (damage > 0)
	{
		if (HP > damage)
		{
			HP -= damage;
		}
		else
		{
			Die();
		}
	}
}

void Player::Heal(int heal)
{
	if (heal > 0)
	{
		HP += heal;
	}
}

void Player::Die()
{
	HP = 0;
	global->PlayerDie();
}
