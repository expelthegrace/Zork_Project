#pragma once
#include "globals.h"

class entity
{
public:
	entity(type t, string name, string desc, entity* father);

	entity* father;
	type tipus;
	string name;
	string description;
	vector<entity *> contains;

	virtual void inventari();
	virtual void Update();
	virtual string Exit();
	virtual entity* Use();

};

