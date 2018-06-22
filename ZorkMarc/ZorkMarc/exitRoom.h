#pragma once
#include "entity.h"
#include "room.h"

class exitRoom :
	public entity
{
public:
	exitRoom(type t, string name, string desc, direction dir, room* source, room* dest, entity* father, bool locked);

	void inventari();
	string Exit();
	bool locked;
	room* source, *destination;
};

