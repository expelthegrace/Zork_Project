#include "stdafx.h"
#include "item.h"


item::item(type t, string name, string desc, entity* father, entity* usableOn):
	entity(t,name,desc,father)
{
	if (usableOn != nullptr) this->usableOn = usableOn;
}


item::~item()
{
}
