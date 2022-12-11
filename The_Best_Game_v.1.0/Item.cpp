#include "Item.h"
#include "Global.h"


HealItem::HealItem(Global* g)
{
	global = g;
	name = namespase[rand() % 3];
}

void HealItem:: Use()
{
	global->UseHealItem();
}

Key::Key(Global* g)
{
	global = g;
	name = "Key";
}

void Key::Use()
{
	global->UseKey();
}
