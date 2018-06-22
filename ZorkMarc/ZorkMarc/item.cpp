#include "stdafx.h"
#include "item.h"


item::item(type t, string name, string desc, vector<entity *>& contains):
	entity(t,name,desc,contains)
{
}


item::~item()
{
}
