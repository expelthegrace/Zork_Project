#pragma once
#include "entity.h"
class item :
	public entity
{
public:

	item(string name, string desc, entity* father, bool grabable);
	~item();

	
	
};

