#pragma once
#include "globals.h"
#include "creature.h"

class player:public creature
{
public:
	player(string name, string desc, int life, entity* father, room* sala);

	void inventari();
	void printStats();

};

