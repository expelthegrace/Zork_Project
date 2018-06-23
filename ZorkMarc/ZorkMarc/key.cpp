#include "stdafx.h"
#include "key.h"


key::key(type t, string name, string desc, entity* father, bool grabable, entity* opens) :
	item(t, name, desc, father,grabable)
{

	if (opens != nullptr) this->opens = opens;
}


key::~key()
{
}
