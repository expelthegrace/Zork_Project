#include "stdafx.h"
#include "room.h"


room::room(type t, string name, string desc, entity* father):
	entity(t,name,desc, father)
{

}


room::~room()
{
}
