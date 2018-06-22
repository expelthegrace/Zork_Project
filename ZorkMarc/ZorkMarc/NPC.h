#pragma once
#include "creature.h"
class NPC :
	public creature
{
public:
	NPC(type t, string name, string desc, int life, int damage, entity* father, room* sala);
	~NPC();

	int damage;
};

