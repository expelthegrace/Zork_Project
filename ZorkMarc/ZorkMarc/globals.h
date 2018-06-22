#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <list>
#include <cctype>
#include <stdio.h>
#include <ctype.h>


using namespace std;

enum type {PLAYER = 0, ROOM, ITEM, NPC, EXITDOOR};

enum action { LOOK = 0, PICK, LEAVE, USE, EXIT, HELP, ACTION_END };

enum direction { NORTH = 0, EAST, SOUTH, WEST};

static string actionToString(action act) {
	if (act == LOOK) return "LOOK";
	else if (act == PICK) return "PICK";
	else if (act == LEAVE) return "LEAVE";
	else if (act == HELP) return "HELP";
	else if (act == EXIT) return "EXIT";
	else if (act == USE) return "USE";
}


static string upperCase(string s) 
{
	int i = 0;
	char c;
	while (s[i])
	{
		c = s[i] = toupper(s[i]);
		i++;
	}
	return  s;
}


template<typename Out>
static void split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

static vector<string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

