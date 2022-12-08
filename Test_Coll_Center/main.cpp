#include "Map.h"
#include <iostream>


int main()
{
	Map map;
	map.GameOver();
	std::cout << '\n';
	map.player.GameOver();
	std::cout << '\n';
	map.room1.GameOver();


	return 0;
}
