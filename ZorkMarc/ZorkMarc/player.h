#pragma once
#include "globals.h"
#include "creature.h"

class player:public creature
{
public:
	player(type t, string name, string desc, vector<entity *>& contains, int life, room* sala);

	void inventari();
	void printStats();



};

