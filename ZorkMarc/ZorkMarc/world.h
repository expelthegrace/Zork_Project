#pragma once
#include "entity.h"
#include "globals.h"
#include "player.h"
#include "item.h"
#include "exitRoom.h"


class world
{
public:

	//definicio de tot el mon
	world(); 

	//busca un entity per nom, diem tambe si volem borrar de la llista (per mourel per exemple)
	entity* findEntity(string nom, bool lookBag);

	//cada torn del joc
	void torn();

	//funcio que busca l'habitacio per nom
	room* findRoom(string nom);

	//funcio que identifica la comanda i l'executa
	bool parse(vector<string> v);

private:
	player* jugador;
	vector<entity *> entitats;
	vector<room *> rooms;
	
};

