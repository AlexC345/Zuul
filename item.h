#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>
using namespace std;

class item{
	public:
		item(char*, char*);
		~item();
		char* getName();
		char* getDescription();
		void print();
	private:
		char* name;
		char* description;
};
#endif
