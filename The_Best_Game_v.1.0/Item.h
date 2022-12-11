#pragma once
#include <string>

class Global;

class Item
{
public:
	Global* global;
	std::string name;
	virtual void Use()=0;
};


class HealItem : public Item
{
private:
	std::string namespase[3]{ "Heals bottle",
	"Chees","Bread" };
public:

	HealItem(Global* g);
	virtual void Use();

};

class Key : public Item
{
public:

	Key(Global* g);
	virtual void Use();
};