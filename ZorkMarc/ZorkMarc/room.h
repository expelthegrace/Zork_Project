#pragma once
#include "entity.h"


class room :
	public entity
{
public:
	room(type t, string name, string desc,  entity* father);
	~room();
};

