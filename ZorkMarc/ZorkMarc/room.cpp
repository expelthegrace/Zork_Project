#include "stdafx.h"
#include "room.h"


room::room(type t, string name, string desc, vector<entity *>& contains):
	entity(t,name,desc,contains)
{

}


room::~room()
{
}
