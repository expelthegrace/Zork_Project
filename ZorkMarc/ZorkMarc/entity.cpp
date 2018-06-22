#include "stdafx.h"
#include "entity.h"


entity::entity(type t, string name, string desc, list<entity *>& contains)
{
	this->tipus = t;
	this->name = name;
	this->description = desc;
	this->contains = contains;
}



