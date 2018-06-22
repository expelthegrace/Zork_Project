#include "stdafx.h"
#include "world.h"


world::world()
{
	// funcio que defineix el mon

	vector<entity*> coses1, coses2, coses3;
	room* room1, *room2, *room3;

	// primera room
	room1 = new room(ROOM, "lawn", "old lawn full of plants", nullptr);
	room2 = new room(ROOM, "kitchen", "esto es una cosina amigo", nullptr);
	room3 = new room(ROOM, "living room", "el comedorx", nullptr);

	//coses de la room
	new item(ITEM, "book", "an old book, it has drawn a tree on the cover", room1, nullptr);
	entity* tree = new item(ITEM, "tree", "tree with a hole on its trunk", room1, nullptr);
	new item(ITEM, "wooden_key", "key made of wood", tree, false);

	new exitRoom(EXITDOOR, "wooden_door", "door leading to the kitchen of the house", WEST, room1, room2, room1, true);

	
	// guardar room amb les seves coses
	rooms.push_back(room1);
	rooms.push_back(room2);
	rooms.push_back(room3);


	//declarar player
	jugador = new player(PLAYER, "MARCO POLO", "guapo, rico y buen jugador", 100,nullptr, rooms[0]);
	new item(ITEM, "bottle", "a bottle full of water", jugador,nullptr);
	

}

entity* world::findEntity(string nom, bool lookBag) {

	list<entity *>  Q;
	entity* ent;
	
	for (int i = 0; i < jugador->sala->contains.size(); ++i) {
		Q.push_back(jugador->sala->contains[i]);
	}
	if (lookBag) {
		for (int i = 0; i < jugador->contains.size(); ++i) {
			Q.push_back(jugador->contains[i]);
		}
	}
	while (!Q.empty())
	{
		// Dequeue a vertex from queue and print it
		ent = Q.front();
		if (upperCase(ent->name) == upperCase(nom)) return Q.front();
		Q.pop_front();
		for (int i = 0; i < ent->contains.size(); ++i) Q.push_back(ent->contains[i]);
	}

	return nullptr;

}

room* world::findRoom(string nom) {

	for (int i = 0; i < rooms.size(); ++i)if (rooms[i]->name == nom) return rooms[i];	
	return nullptr;
}

void deleteChild(vector<entity *> & contains, string name) {
	for (int i = 0; i < contains.size(); ++i) {
		if (name == contains[i]->name) contains.erase(contains.begin() + i );
	}
}

bool world::parse(vector<string> tokens) {

	action comanda = ACTION_END;

	vector<action> allActions;
	for (int i = 0; i < ACTION_END; i++) {	
		if (actionToString(static_cast<action>(i)) == upperCase(tokens[0])) comanda = static_cast<action>(i);
	}
	if (comanda == ACTION_END) return false;

	entity* target;

	if (comanda == LOOK) {
		if (tokens.size() == 1) {
			jugador->sala->inventari();
		}
		else if (upperCase(tokens[1]) == "ME") {
			cout << jugador->name << endl;
			cout << jugador->description << endl;
		}
		else {
			
			target = findEntity(tokens[1], true);

			if (target != nullptr) target->inventari();
			else {
				cout << "There is not a " << tokens[1] << " on the room" << endl;
				return true;
			}
		}
	}

	else if (comanda == PICK) {
		if (tokens.size() <= 1) {
			cout << "Not enough arguments on the command" << endl;
			return true;
		}
		target = findEntity(tokens[1], false);		
		if (target == nullptr) {
			cout << "There is not a " << tokens[1] << " on the room" << endl;
			return true;
		}
		if (target->tipus != ITEM) {
			cout << "Cannot pick this item" << endl;
			return true;
		}
		deleteChild(target->father->contains, target->name);
		jugador->contains.push_back(target);
		cout << "You have put the " << target->name << " on the bag" << endl;
	}

	else if (comanda == LEAVE) {
		if (tokens.size() <= 1) {
			cout << "Not enough arguments on the command" << endl;
			return true;
		}
		target = nullptr;
		for (int i = 0; i < jugador->contains.size(); ++i)  // trobo l'objecte a la bossa
			if (upperCase(tokens[1]) == upperCase(jugador->contains[i]->name)) target = jugador->contains[i];
		if (target == nullptr) {
			cout << "You don't have this object on your bag";
			return true;
		}

		if (tokens.size() == 2) { // si deixem algo de la bossa en l'habitacio
			deleteChild(jugador->contains, target->name); // el borro de la bossa
			jugador->sala->contains.push_back(target);
			target->father = jugador->sala;
			cout << "You left " << target->name << " on the " << jugador->sala->name << endl;
		}	

		if (tokens.size() == 4) { // si deixem algo en un altre item
			
			entity* target2 = findEntity(tokens[3], true);

			if (target2 == nullptr) {
				cout << "There is not a " << tokens[1] << " on the room" << endl;
				return true;
			}
			deleteChild(jugador->contains, target->name);

			target2->contains.push_back(target);
			target->father = target2;

			cout << "You left " << target->name << " on the " << target2->name << endl;
		}
	}
	else if (comanda == EXIT) {
		target = findEntity(tokens[1], true); // si existeix l'objecte
		if (target == nullptr) {
			cout << "There is not a " << tokens[1] << " on the room" << endl;
			return true;
		}

		if (target->tipus == EXITDOOR) {
			room* roomAux = findRoom(target->Exit());
			if (roomAux != nullptr) jugador->sala = roomAux; // si es una porta
			cout << "You moved to the " << jugador->sala->name << endl;
			return true;
		}
	}

	else if (comanda == USE) {
		if (tokens.size() <= 1) {
			cout << "Not enough arguments on the command" << endl;
			return true;
		}
		target = findEntity(tokens[1], true); // si existeix l'objecte
		if (target == nullptr) { //si no esta a la bossa
			cout << "There is not a " << tokens[1] << " on the room" << endl;
			return true;
		}
		target->Use();		
	}

	else if (comanda == HELP) {
		cout << "Actions you can use" << endl;
		for (int i = 0; i < ACTION_END; i++) cout << actionToString(static_cast<action>(i)) << endl;	
	}
	return true;
}

void world::torn() {

	jugador->printStats();
	cout << endl << ">";

	string inp;
	getline(std::cin, inp); //get the input line
	cout << endl;

	vector<string> tokens = split(inp, ' '); // split the input into words
	
	if (!parse(tokens)) cout << "Action not accepted" << endl;



}