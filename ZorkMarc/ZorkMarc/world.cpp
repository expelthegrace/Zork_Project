#include "stdafx.h"
#include "world.h"


template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

vector<string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

world::world()
{
}

void world::torn() {

	string inp;
	getline(std::cin, inp); //get the input line

	vector<string> tokens = split(inp, ' '); // split the input into words

	//for (int i = 0; i < tokens.size(); ++i) cout << i << " : " << tokens[i] << endl;
}