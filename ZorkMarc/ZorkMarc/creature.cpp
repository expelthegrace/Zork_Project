#include "stdafx.h"
#include "creature.h"


creature::creature(string name, string desc,int vida, room* sala, entity* father):
	entity(name,desc,father)
{

	life = vida;
	this->sala = sala;
}


creature::~creature()
{
}
