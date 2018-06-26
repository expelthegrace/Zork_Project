#include "stdafx.h"
#include "entity.h"


entity::entity(string name, string desc, entity* father)
{
	this->tipus = ENTITY;
	this->name = name;
	this->description = desc;

	opens = nullptr;

	grabable = false;
	if (father != nullptr) {
		this->father = father;
		father->contains.push_back(this);
	}
}


string entity::Exit() {
	cout << "It makes no sense." << endl;
	return NULL;
}

void entity::Update() {

}

void entity::inventari() {
	cout << name << endl;
	cout << description << endl;

	if (contains.size() == 0) cout << "There is nothing in the " << name << "." << endl;
	else {	
		for (int i = 0; i < contains.size(); ++i) {
			cout << "There is a " << contains[i]->name << " inside." << endl;
		}
	}
}


