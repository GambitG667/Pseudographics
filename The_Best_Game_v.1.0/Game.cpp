#include "Game.h"
#include "Global.h"
#include "Coordinates.h"
#include "Map.h"
#include <iostream>
#include <conio.h>

Game::Game()
{
	global = new Global();
	map = new Map(global);
	global->Subscribe(this);
}

Game::~Game()
{
	delete map;
	delete global;
}

void Game::Restart()
{
	if (restart)
	{
		delete map;
		map = new Map(global);
		map->ToLog("Restart");
		restart = false;
	}
}

void Game::Win()
{
	if (win)
	{
		map->ToLog("You Win!\n R - to restart");
		win = false;
	}
}

void Game::Training()
{
	if (training)
	{
		map->ToLog("w,a,s,d - moving\nu - use item\ne - escape\nr - restart\nt - on/of treaning");
	}
}

void Game::Update()
{
	map->ClearLog();
	Training();
	map->Print();

	char mod = '1';

	while (mod != 'e')
	{
		map->ClearLog();
		mod = _getch();

		switch (mod)
		{
		case 'w':
		{
			map->Up();
			break;
		}
		case 's':
		{
			map->Down();
			break;
		}
		case 'a':
		{
			map->Left();
			break;
		}
		case 'd':
		{
			map->Right();
			break;
		}
		case 'u':
		{
			int index;
			std::cout << "namber of item:";
			std::cin >> index;
			map->Use(index);
			break;
		}
		case 'r':
		{
			restart = true;
			break;
		}
		case 't':
		{
			training ? training = false : training = true;
			break;
		}
		}
		Training();
		Restart();
		Win();
		system("cls");
		map->Print();
	}
}


int main()
{	
	srand(time(NULL));

	Game MyGame;
	MyGame.Update();

	return 0;
}
