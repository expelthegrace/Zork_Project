#pragma once
#include "entity.h"
#include "room.h"

class creature :
	public entity
{
public:
	creature(string name, string desc,int vida, room* sala,entity* father);
	~creature();
	int life;
	room* sala;


};

