#pragma once
#include "globals.h"

class entity
{
public:
	entity(type t, string name, string desc, vector<entity *>& contains);


	
	type tipus;
	string name;
	string description;
	vector<entity *> contains;

	virtual void inventari();
	virtual void Update();

};

