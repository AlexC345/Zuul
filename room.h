#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <vector>
#include "item.h"
using namespace std;
//imports and header guard

class room{
	//public constructor, destructor, and functions
	public:
		room(char*,  char*);
		~room();
		char* getName();
		char* getDescription();
		void addExit(char*, room*);
		void addItem(item*);
		void print();
		bool validDirection(char* direction);
		room* enterDirection(char* direction);
		bool validCollect();
		item* removeItem(int removeItemIndex);
		bool checkWinCondition();
	//private variables and vectors
	private:
		char* name;
		char* description;
		vector<char*> exits;
		vector<room*> exitRooms;
		vector<item*> items;
};
//header guard end
#endif
