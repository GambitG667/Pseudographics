#include "GameObject.h"
#include "Global.h"

GameObject::GameObject()
{ 
	global = 0;
	coordinates = Coordinates();
	state = new VoidState();
}

GameObject::GameObject(Global* global, Coordinates coord)
{
	coordinates = coord;
	this->global = global;
	SetState(new VoidState());
}

GameObject::~GameObject()
{
	delete state;
}

void GameObject::SetState(StateGameObject* state)
{
	delete this->state;
	this->state = state;
}

void GameObject::SetCoordinates(Coordinates coord)
{
	coordinates = coord;
}

Coordinates GameObject::GetCoordinates()
{
	return coordinates;
}

char GameObject::GetInfo()
{
	return state->GetInfo(this);
}

bool GameObject::Transfer()
{
	return state->Transfer(this);
}

void GameObject::Hide()
{
	SetState(new HideState());
}

bool GameObject::Clear()
{
	state->Clear(this);
	return true;
}


char StateGameObject::GetInfo(GameObject* GO)
{
	return '0';
}

bool StateGameObject::Transfer(GameObject* GO)
{
	return false;
}

bool StateGameObject::Clear(GameObject* GO)
{
	GO->SetState(new VoidState());
	return true;
}


char HideState::GetInfo(GameObject* GO)
{
	return ' ';
}

char VoidState::GetInfo(GameObject* GO)
{
	return ',';
}

bool VoidState::Transfer(GameObject* GO)
{
	GO->SetState(new PlayerState());
	return true;
}

char WallState::GetInfo(GameObject* GO)
{
	return '#';
}

char PlayerState::GetInfo(GameObject* GO)
{
	return '@';
}

bool PlayerState::Clear(GameObject* GO)
{
	GO->SetState(new VoidState());
	return true;
}

char TrapState::GetInfo(GameObject* GO)
{
	return info;
}

bool TrapState::Transfer(GameObject* GO)
{
	info = '@';
	GO->global->TrapPlayer();
	return true;
}

bool TrapState::Clear(GameObject* GO)
{
	info = '.';
	return true;
}


char ItemState::GetInfo(GameObject* GO)
{
	return '$';
}

bool ItemState::Transfer(GameObject* GO)
{
	GO->SetState(new PlayerState());
	GO->global->PlayerTakeHealItem();
	return true;
}

char KeyState::GetInfo(GameObject* GO)
{
	return '%';
}


bool KeyState::Transfer(GameObject* GO)
{
	GO->SetState(new PlayerState());
	GO->global->PlayerTakeKey();
	return true;
}