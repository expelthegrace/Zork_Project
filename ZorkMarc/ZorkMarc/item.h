#pragma once
#include "entity.h"
class item :
	public entity
{
public:

	item(type t, string name, string desc, entity* father, entity* usableOn);
	~item();

	entity* usableOn;
};

