#include "stdafx.h"
#include "player.h"


player::player(type t, string name, string desc, int life, entity* father,room* sala) :
	creature(t, name, desc, life,sala, father)
{
	
}

void player::printStats() {
	cout << endl << "******************************" << endl;
	cout << "Room: " << upperCase(sala->name) << endl;
	cout << "Life: " << life << "/100" << endl;
	inventari();
}


void player::inventari() {

	if (contains.size() == 0) cout << "Your bag is empty" << endl;
	else {	
		cout << "Bag: ";
		for (int i = 0; i < contains.size(); ++i) {
			cout << contains[i]->name;
			if (i < contains.size() - 1) cout << ", ";
			else cout << endl;
		}
	}
	cout << "******************************" << endl;
}


