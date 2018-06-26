#include "stdafx.h"
#include "key.h"


key::key(string name, string desc, entity* father, bool grabable, entity* opens) :
	item(name, desc, father,grabable)
{
	this->tipus = KEY;
	if (opens != nullptr) this->opens = opens;
}

