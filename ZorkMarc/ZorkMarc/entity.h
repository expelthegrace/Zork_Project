#pragma once
#include "globals.h"

class entity
{
public:
	entity(type t, string name, string desc, entity* father);

	entity* father, *opens;
	type tipus;
	string name;
	string description;
	bool grabable, locked;
	vector<entity *> contains;

	virtual void inventari();
	virtual void Update();
	virtual string Exit();


};

