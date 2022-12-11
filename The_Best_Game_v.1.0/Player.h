#pragma once
#include "Coordinates.h"
#include <string>
#include <vector>

class Item;
class Map;
class Global;


class Player
{
private:
	Coordinates coordinates;
	std::vector <Item*> Bag;
	bool live = true;
	int HP;
	Global* global;
public:
	Player(Coordinates coord, Global* global);
	~Player();
	Coordinates GetCoordinates();
	void Move(const std::string str);
	void TakeItem(Item* item);
	void Use(int namber);
	void PrintInfo();
	void TakeDamage(int damage);
	void Heal(int heal);
	void Die();
};

