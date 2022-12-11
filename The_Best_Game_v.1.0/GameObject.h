#pragma once
#include "Coordinates.h"
#include <String>

class GameObject;
class StateGameObject;
class Global;


class StateGameObject
{
public:
	StateGameObject(){}
	virtual bool Transfer(GameObject* GO);
	virtual bool Clear(GameObject* GO);
	virtual char GetInfo(GameObject* GO) = 0;
};

class HideState : public StateGameObject
{
public:
	HideState() : StateGameObject(){}
	char GetInfo(GameObject* GO);
};

class VoidState : public StateGameObject
{
public:
	virtual char GetInfo(GameObject* GO);
	virtual bool Transfer(GameObject* GO);
	VoidState() : StateGameObject() {}
};

class WallState : public StateGameObject
{
public:
	virtual char GetInfo(GameObject* GO);
	WallState() : StateGameObject() {}
};

class PlayerState : public StateGameObject
{
public:
	virtual char GetInfo(GameObject* GO);
	virtual bool Clear(GameObject* GO);
	PlayerState() : StateGameObject() {}
};

class TrapState : public StateGameObject
{
	char info = '.';
public:
	virtual char GetInfo(GameObject* GO);
	virtual bool Transfer(GameObject* GO);
	virtual bool Clear(GameObject* GO);
	TrapState() : StateGameObject() {}
};

class ItemState :public StateGameObject
{
public:
	virtual char GetInfo(GameObject* GO);
	virtual bool Transfer(GameObject* GO);
	ItemState() : StateGameObject() {}
};

class KeyState :public StateGameObject
{
public:
	virtual char GetInfo(GameObject* GO);
	virtual bool Transfer(GameObject* GO);
	KeyState() : StateGameObject() {}
};
 
class GameObject
{
private:
	Coordinates coordinates;
	StateGameObject* state;

public:
	Global* global;
	GameObject();
	GameObject(Global* global, Coordinates coord);
	~GameObject();
	void SetState(StateGameObject* state);
	void SetCoordinates(Coordinates coord);
	Coordinates GetCoordinates();
	bool Transfer();
	bool Clear();
	char GetInfo();
	void Hide();

};