// ZorkMarc.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "world.h"


int main()
{
	world* w = new world();
	
	while (w->torn());
	while (1);
}

