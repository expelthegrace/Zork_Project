#pragma once
#include "entity.h"
#include "room.h"

class exitRoom :
	public entity
{
public:
	exitRoom(string name, string desc, direction dir, room* source, room* dest, entity* father, bool locked);

	void inventari();
	string Exit();

	room* source, *destination;
};

