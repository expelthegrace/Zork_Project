#pragma once
#include "entity.h"
class item :
	public entity
{
public:
	item(type t, string name, string desc, vector<entity *>& contains);
	~item();
};

