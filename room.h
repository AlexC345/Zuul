#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <vector>
#include "item.h"
using namespace std;

class room{
	public:
		room(char*,  char*);
		~room();
		char* getName();
		char* getDescription();
		void addExit(char*, room*);
		void addItem(item*);
		void print();
	private:
		char* name;
		char* description;
		vector<char*> exits;
		vector<room*> exitRooms;
		vector<item*> items;
};
#endif
