#include "stdafx.h"
#include "exitRoom.h"


exitRoom::exitRoom(string name, string desc,  direction dir, room* source, room* dest, entity* father, bool locked) :
	entity(name, desc, father)
{
	this->source = source;
	this->destination = dest;
	this->locked = locked;
	this->tipus = EXITDOOR;
}


string exitRoom::Exit() {
	if (!locked) {
		
		return destination->name;
	}
	else cout << "The path is locked." << endl;

	return " ";
}

void exitRoom::inventari() {
	cout << name;
	if (locked) cout << " (locked)." << endl;
	else cout << " (unlocked)." << endl;

	if (contains.size() == 0) cout << "There is nothing in the " << name << "." << endl;
	else {
		for (int i = 0; i < contains.size(); ++i) {
			cout << "There is a " << contains[i]->name << endl;
		}
	}
}