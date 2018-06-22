#include "stdafx.h"
#include "NPC.h"


NPC::NPC(type t, string name, string desc, vector<entity *>& contains,int life, int damage, room* sala):
	creature(t,name,desc,contains,life, sala)
{

	this->damage = damage;
}


NPC::~NPC()
{
}
