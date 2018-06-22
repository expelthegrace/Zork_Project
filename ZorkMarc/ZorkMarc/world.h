#pragma once
#include "entity.h"
#include "globals.h"



class world
{
public:
	world();

	void torn();

private:

	vector<entity *> entitats;

};

