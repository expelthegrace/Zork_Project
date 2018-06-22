#include "stdafx.h"
#include "entity.h"


entity::entity(type t, string name, string desc, entity* father)
{
	this->tipus = t;
	this->name = name;
	this->description = desc;

	if (father != nullptr) {
		this->father = father;
		father->contains.push_back(this);
	}
}

entity* entity::Use() {
	cout << "Oak's words echoed... \"There's a time and place for everything but not now!" << endl;
	return nullptr;
}

string entity::Exit() {
	cout << "It makes no sense" << endl;
	return NULL;
}

void entity::Update() {

}

void entity::inventari() {
	cout << name << endl;
	cout << "This is a " << description << endl;

	if (contains.size() == 0) cout << "There is nothing in the " << name << "." << endl;
	else {	
		for (int i = 0; i < contains.size(); ++i) {
			cout << "There is a " << contains[i]->name << endl;
		}
	}
}


