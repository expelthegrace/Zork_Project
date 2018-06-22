#include "stdafx.h"
#include "entity.h"


entity::entity(type t, string name, string desc, vector<entity *>& contains)
{
	this->tipus = t;
	this->name = name;
	this->description = desc;
	this->contains = contains;
}

void entity::Update() {

}

void entity::inventari() {
	if (contains.size() == 0) cout << "There is nothing in the " << name << "." << endl;
	else {
		cout <<  name << endl;
		cout << "This is a " << description << endl;
		for (int i = 0; i < contains.size(); ++i) {
			cout << "There is a " << contains[i]->name << endl;
		}
	}
}


