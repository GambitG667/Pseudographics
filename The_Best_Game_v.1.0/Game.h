#include "Map.h"

class Global;

class Game
{
private:
	Global* global;
	Map* map;
public:
	bool training = true;
	bool restart = false;
	bool win = false;
	Game();
	~Game();
	void Update();
	void Restart();
	void Win();
	void Training();
};