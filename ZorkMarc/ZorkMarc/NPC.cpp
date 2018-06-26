#include "stdafx.h"
#include "NPC.h"


NPC::NPC(string name, string desc, int life, int damage,entity* father, room* sala):
	creature(name,desc,life, sala,father)
{
	this->tipus = NPCCREATURE;
	this->damage = damage;
}


NPC::~NPC()
{
}
