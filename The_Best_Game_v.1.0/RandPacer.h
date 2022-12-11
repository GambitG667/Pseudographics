#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <minmax.h>
#include "Coordinates.h"
#include "GameObject.h"

class Pacer;
class RandPaser;
class StateOfPacer;
class UpStateOfPacer;
class DownStateOfPacer;
class LeftStateOfPacer;
class RightStateOfPacer;

class StateOfPacer
{
private:
	std::string name;
public:
	StateOfPacer(const std::string& name)
		: name(name) {}
	std::string GetName()
	{
		return name;
	}
	virtual void Step(Pacer*) = 0;
	virtual void TurnLeft(Pacer*) = 0;
	virtual void TurnRight(Pacer*) = 0;
	virtual void StepBac(Pacer* paser) = 0;
};

class Pacer
{

private:
	StateOfPacer* state;
public:	
	Coordinates coordinates;
	Coordinates maxCoordinates;
	Coordinates minCoordinates;
	int lengthJamp;


	Pacer(StateOfPacer* st, int x, int y, int maxx, int maxy, int minx, int miny, int lj)
	{
		state = st;
		coordinates = Coordinates(x, y);
		maxCoordinates = Coordinates(maxx, maxy);
		minCoordinates = Coordinates(minx, miny);

		lengthJamp = lj;
	}
	Pacer(StateOfPacer* st, int x, int y, int x2, int y2, int lj)
	{
		state = st;
		coordinates = Coordinates(x, y);
		maxCoordinates = Coordinates(max(x, x2), max(y, y2));
		minCoordinates = Coordinates(min(x, x2), min(y, y2));

		lengthJamp = lj;
	}
	Pacer(StateOfPacer* st)
	{
		state = st;
		coordinates = Coordinates(0, 0);
		maxCoordinates = Coordinates(10, 10);
		minCoordinates = Coordinates(-10, -10);

		lengthJamp = 1;
	}
	~Pacer()
	{
		delete state;
	}
	void SetState(StateOfPacer* s)
	{
		delete state;
		state = s;
	}

	void printSmth()
	{
		std::cout << "x = " << coordinates.x << " y = " << coordinates.y << " State = " << state->GetName() << std::endl;
	}
	void Step()
	{
		state->Step(this);
	}
	void JampOn(int *arr,int width, int length, int Sconst, int* S)
	{
		for (int i = 0; i <length; ++i)
		{
			if (*S + 1 < Sconst)
			{
				Step();
				++*S;
				arr[coordinates.y * width + coordinates.x] = 1;
			}
		}
	}
	void JampOn(std::vector <std::vector <GameObject*>> arr, int width, int length, int Sconst, int* S)
	{
		for (int i = 0; i < length; ++i)
		{
			if (*S + 1 < Sconst)
			{
				Step();
				++* S;
				arr[coordinates.y][coordinates.x]->SetState(new WallState());
			}
		}
	}
	void StepBac()
	{
		state->StepBac(this);
	}
	void TurnLeft() 
	{
		state->TurnLeft(this);
	}
	void TurnRight()
	{
		state->TurnRight(this);
	}
	
};

class UpStateOfPacer : public StateOfPacer
{
public:
	UpStateOfPacer() : StateOfPacer("Up") {}
	virtual void Step(Pacer* pacer)
	{
		if (pacer->maxCoordinates.y > pacer->coordinates.y + pacer->lengthJamp)
			pacer->coordinates.y += pacer->lengthJamp;
	}
	virtual void TurnLeft(Pacer* pacer);
	virtual void TurnRight(Pacer* pacer);
	virtual void StepBac(Pacer* pacer)
	{
		if (pacer->minCoordinates.y < pacer->coordinates.y - pacer->lengthJamp)
			pacer->coordinates.y -= pacer->lengthJamp;
	}

};

class DownStateOfPacer : public StateOfPacer
{
public:
	DownStateOfPacer() : StateOfPacer("Down") {}
	virtual void Step(Pacer* pacer)
	{
		if (pacer->minCoordinates.y < pacer->coordinates.y - pacer->lengthJamp)
			pacer->coordinates.y -= pacer->lengthJamp;
	}
	virtual void TurnLeft(Pacer* pacer);
	virtual void TurnRight(Pacer* pacer);
	virtual void StepBac(Pacer* pacer)
	{
		if (pacer->maxCoordinates.y > pacer->coordinates.y + pacer->lengthJamp)
			pacer->coordinates.y += pacer->lengthJamp;
	}

};

class LeftStateOfPacer : public StateOfPacer
{
public:
	LeftStateOfPacer() : StateOfPacer("Left") {}
	virtual void Step(Pacer* pacer)
	{
		if (pacer->minCoordinates.x < pacer->coordinates.x - pacer->lengthJamp)
			pacer->coordinates.x -= pacer->lengthJamp;
	}
	virtual void TurnLeft(Pacer* pacer);
	virtual void TurnRight(Pacer* pacer);
	virtual void StepBac(Pacer* pacer)
	{
		if (pacer->maxCoordinates.x > pacer->coordinates.x + pacer->lengthJamp)
			pacer->coordinates.x += pacer->lengthJamp;
	}

};

class RightStateOfPacer : public StateOfPacer
{
public:
	RightStateOfPacer() : StateOfPacer("Right") {}
	virtual void Step(Pacer* pacer)
	{
		if (pacer->maxCoordinates.x > pacer->coordinates.x + pacer->lengthJamp)
			pacer->coordinates.x += pacer->lengthJamp;
	}
	virtual void StepBac(Pacer* pacer)
	{
		if (pacer->minCoordinates.x < pacer->coordinates.x - pacer->lengthJamp)
			pacer->coordinates.x -= pacer->lengthJamp;
	}
	virtual void TurnLeft(Pacer*);
	virtual void TurnRight(Pacer*);
	

};





