#include "stdafx.h"
#include "player.h"


player::player(type t, string name, string desc, vector<entity *>& contains, int life, room* sala) :
	creature(t, name, desc, contains, life, sala)
{
	
}

void player::printStats() {
	cout << endl << "******************************" << endl;
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


