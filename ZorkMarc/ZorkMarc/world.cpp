#include "stdafx.h"
#include "world.h"



vector<entity *> buit;


world::world()
{
	// funcio que defineix el mon

	vector<entity*> coses;
	vector<room *> rooms;

	// primera room

	//coses de la room
	coses.push_back(new item(ITEM, "book", "an old book that draws a tree", buit));
	coses.push_back(new item(ITEM, "chair", "broken chair", buit));

	// guardar room amb les seves coses
	rooms.push_back(new room(ROOM, "lawn", "old lawn full of plants", coses));


	//declarar player
	vector<entity *> bag;
	bag.push_back(new item(ITEM, "bottle", "a Bezoya bottle", buit));
	jugador = new player(PLAYER, "MARCO POLO", "guapo, rico y buen jugador", bag, 100, rooms[0]);

}

entity* world::findEntity(string nom) {

	list<vector<entity *> > Q;
	vector<entity*> ent;
	/*
	for (int i = 0; i < jugador->sala->contains.size(); ++i) {
		Q.push_back(jugador->sala->contains[i]);
	}
	for (int i = 0; i < jugador->contains.size(); ++i) {
		Q.push_back(jugador->contains[i]);
	}

	while (!Q.empty())
	{
		// Dequeue a vertex from queue and print it
		ent = Q.front();
		if (upperCase(ent->name) == upperCase(nom)) return Q.front();
		Q.pop_front();
		for (int i = 0; i < ent->contains.size(); ++i) Q.push_back(ent->contains[i]);
	}*/

	Q.push_back(jugador->sala->contains);

	Q.push_back(jugador->contains);


	while (!Q.empty())
	{
		// Dequeue a vertex from queue and print it
		ent = Q.front();
		Q.pop_front();

		for (int i = 0; i < ent.size(); ++i) {
			if (upperCase(ent[i]->name) == upperCase(nom)) return ent[i];
			else Q.push_back(ent[i]->contains);
		}

		return nullptr;
	}
}


bool world::parse(vector<string> tokens) {

	action comanda = ACTION_END;

	vector<action> allActions;
	for (int i = 0; i < ACTION_END; i++) {
		for (int j = 0; j < tokens.size(); ++j) { // bucle que troba el verb
			if (actionToString(static_cast<action>(i)) == upperCase(tokens[j])) comanda = static_cast<action>(i);
		}	
	}
	if (comanda == ACTION_END) return false;

	entity* target;

	if (comanda == LOOK) {
		if (tokens.size() == 1) {
			jugador->sala->inventari();
		}
		else {
			
			target = findEntity(tokens[1]);

			cout << target->name << endl;
			if (target != nullptr) target->inventari();
			else cout << "There is not a " << tokens[1] << " on the room" << endl;
		}
	}

	if (comanda == PICK) {
		target = findEntity(tokens[1]);
		delete target;
	}


	return true;
}

void world::torn() {

	cout << endl << ">";

	string inp;
	getline(std::cin, inp); //get the input line

	vector<string> tokens = split(inp, ' '); // split the input into words
	jugador->printStats();

	//jugador->sala->inventari();

	
	if (!parse(tokens)) cout << "Action not accepted" << endl;
	
	
	//for (int i = 0; i < tokens.size(); ++i) cout << i << " : " << tokens[i] << endl;


}