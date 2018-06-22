#pragma once
#include "entity.h"
#include "globals.h"
#include "player.h"
#include "item.h"




class world
{
public:

	//definicio de tot el mon
	world(); 

	//busca un entity per nom, diem tambe si volem borrar de la llista (per mourel per exemple)
	entity* findEntity(string nom);

	//cada torn del joc
	void torn();

	//funcio que identifica la comanda i l'executa
	bool parse(vector<string> v);

private:
	player* jugador;
	vector<entity *> entitats;
	
};

