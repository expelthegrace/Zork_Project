#pragma once
#include "entity.h"


class room :
	public entity
{
public:
	room(string name, string desc,  entity* father);
	~room();
};

