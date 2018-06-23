#pragma once
#include "item.h"
class key :
	public item
{
public:
	key(type t, string name, string desc, entity* father, bool grabable, entity* opens);
	~key();

	
};

