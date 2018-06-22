#include "stdafx.h"
#include "creature.h"


creature::creature(type t, string name, string desc, vector<entity *>& contains, int vida, room* sala):
	entity(t,name,desc,contains)
{
	life = vida;
	this->sala = sala;
}


creature::~creature()
{
}
