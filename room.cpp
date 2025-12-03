#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
using namespace std;

room::room(char* inputName, char* inputDescription){
	name = new char[1000];
	strcpy(name, inputName);
	description = new char[1000];
	strcpy(description, inputDescription);
	vector<char*> exits;
	vector<room*> exitRooms;
	vector<item*> items;
}

room::~room(){
	delete[] name;
	delete[] description;
}

char* room::getName(){
	return name;
}

char* room::getDescription(){
	return description;
}

void room::addExit(char* direction, room* r){
	exits.push_back(direction);
	exitRooms.push_back(r);
}

void room::addItem(item* i){
	items.push_back(i);
}

bool room::validDirection(char* direction){
	for (int i=0; i<exits.size(); i++){
		if (strcmp(direction, exits[i]) == 0){
			return true;
		}
	}
	return false;
}

room* room::enterDirection(char* direction){
	for (int i=0; i<exits.size(); i++){
		if (strcmp(direction, exits[i]) == 0){
			return exitRooms[i];
		}
	}
}

void room::print(){
	cout << "You are in the " << name << ". " << description << endl;
	if (items.size() > 0){
		cout << "You see: " << endl;
		for (int i=0; i<items.size(); i++){
			items[i]->print();
		}
	}
	cout << "Exits: " << endl;
	for (int i=0; i<exits.size(); i++){
		cout << exits[i] << ": " << exitRooms[i]->getName() << endl;
	}
}
