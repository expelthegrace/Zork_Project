#include "stdafx.h"
#include "item.h"


item::item(string name, string desc, entity* father,  bool grabable):
	entity(name,desc,father)
{
	this->grabable = grabable;	
	this->tipus = ITEM;
}


item::~item()
{
}
