#pragma once
#include "creature.h"
class NPC :
	public creature
{
public:
	NPC(type t, string name, string desc, vector<entity *>& contains, int life, int damage, room* sala);
	~NPC();

	int damage;
};

