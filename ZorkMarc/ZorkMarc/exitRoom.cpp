#include "stdafx.h"
#include "exitRoom.h"


exitRoom::exitRoom(type t, string name, string desc,  direction dir, room* source, room* dest, entity* father, bool locked) :
	entity(t, name, desc, father)
{
	this->source = source;
	this->destination = dest;
	this->locked = locked;
}


string exitRoom::Exit() {
	if (!locked) {
		
		return destination->name;
	}
	else cout << "The door is locked" << endl;

	return " ";
}

void exitRoom::inventari() {
	cout << name;
	if (locked) cout << " (locked)" << endl;
	else cout << " (unlocked)" << endl;


	cout << "This is a " << description << endl;

	if (contains.size() == 0) cout << "There is nothing in the " << name << "." << endl;
	else {
		for (int i = 0; i < contains.size(); ++i) {
			cout << "There is a " << contains[i]->name << endl;
		}
	}
}