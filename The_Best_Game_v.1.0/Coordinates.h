#pragma once
#include <iostream>


class Coordinates
{
public:
	int x, y;

	Coordinates()
	{
		x = 0;
		y = 0;
	}

	Coordinates(int xCoord, int yCoord)
	{
		x = xCoord;
		y = yCoord;
	}

	bool operator < (const Coordinates& other)
	{
		return (this->x < other.x && this->y < other.y);
	}

	bool operator > (const Coordinates& other)
	{
		return (this->x > other.x && this->y > other.y);
	}

	bool operator <= (const Coordinates& other)
	{
		return (this->x <= other.x && this->y <= other.y);
	}

	bool operator >= (const Coordinates& other)
	{
		return (this->x >= other.x && this->y >= other.y);
	}

	bool operator == (const Coordinates& other)
	{
		return (this->x == other.x && this->y == other.y);
	}
	Coordinates operator + (const Coordinates& other)
	{
		return Coordinates(this->x + other.x, this->y + other.y);
	}
	Coordinates operator - (const Coordinates& other)
	{
		return Coordinates(this->x - other.x, this->y - other.y);
	}
	Coordinates plus(int x, int y)
	{
		return Coordinates(this->x + x, this->y + y);
	}
	Coordinates minus(int x, int y)
	{
		return Coordinates(this->x - x, this->y - y);
	}
};
