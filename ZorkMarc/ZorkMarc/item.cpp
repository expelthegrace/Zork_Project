#include "stdafx.h"
#include "item.h"


item::item(type t, string name, string desc, entity* father,  bool grabable):
	entity(t,name,desc,father)
{
	this->grabable = grabable;	
	
}


item::~item()
{
}
