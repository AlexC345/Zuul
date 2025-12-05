#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>
using namespace std;
//header guard and imports
class item{
	//public constructor, destructors, and functions
	public:
		item(char*, char*);
		~item();
		char* getName();
		char* getDescription();
		void print();
	//private variables
	private:
		char* name;
		char* description;
};
//header guard end
#endif
