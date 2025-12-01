#include <iostream>
#include <cstring>
#include "item.h"
using namespace std;

item::item(char* inputName, char* inputDescription){
	name = new char[1000];
	strcpy(name, inputName);
	description = new char[1000];
	strcpy(description, inputDescription);
}

item::~item(){
	delete[] name;
	delete[] description;
}

char* item::getName(){
	return name;
}

char* item::getDescription(){
	return description;
}

void item::print(){
	cout << name << ": " << description << endl;
}
