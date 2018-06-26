#include "stdafx.h"
#include "room.h"


room::room(string name, string desc, entity* father):
	entity(name,desc, father)
{
	this->tipus = ROOM;
}


room::~room()
{
}
