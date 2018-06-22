#include "stdafx.h"
#include "NPC.h"


NPC::NPC(type t, string name, string desc, int life, int damage,entity* father, room* sala):
	creature(t,name,desc,life, sala,father)
{

	this->damage = damage;
}


NPC::~NPC()
{
}
