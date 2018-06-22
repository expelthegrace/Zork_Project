#pragma once
#include "entity.h"
#include "room.h"

class creature :
	public entity
{
public:
	creature(type t, string name, string desc, vector<entity *>& contains, int vida, room* sala);
	~creature();
	int life;
	room* sala;


};

