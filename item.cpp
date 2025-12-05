#include <iostream>
#include <cstring>
#include "item.h"
using namespace std;

item::item(char* inputName, char* inputDescription){//constructor
	name = new char[1000];
	strcpy(name, inputName);
	description = new char[1000];
	strcpy(description, inputDescription);
}

item::~item(){//destructor
	delete[] name;
	delete[] description;
}

char* item::getName(){//name getter
	return name;
}

char* item::getDescription(){//description getter
	return description;
}

void item::print(){//print item details
	cout << name << ": " << description << endl;
}
