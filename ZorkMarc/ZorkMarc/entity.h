#pragma once
#include "globals.h"



class entity
{
public:
	entity(type t, string name, string desc, list<entity *>& contains);
	
	type tipus;
	string name;
	string description;
	list<entity *> contains;

	virtual void Update();

};

