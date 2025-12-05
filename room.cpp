#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
using namespace std;

room::room(char* inputName, char* inputDescription){//room constructor
	name = new char[1000];
	strcpy(name, inputName);
	description = new char[1000];
	strcpy(description, inputDescription);
	vector<char*> exits;
	vector<room*> exitRooms;
	vector<item*> items;
}

room::~room(){//room destructor
	for (int i=0; i<items.size(); i++){
		delete items[i];
	}
	for (int i=0; i<exits.size(); i++){
		delete exits[i];
		delete exitRooms[i];
	}
	delete[] name;
	delete[] description;
}

char* room::getName(){//room name getter
	return name;
}

char* room::getDescription(){//room description getter
	return description;
}

void room::addExit(char* direction, room* r){//add an exit to the room to another room
	exits.push_back(direction);
	exitRooms.push_back(r);
}

void room::addItem(item* i){//add an item to the room
	items.push_back(i);
}

bool room::validDirection(char* direction){//check if there is a connection to another room in the given direction
	for (int i=0; i<exits.size(); i++){
		if (strcmp(direction, exits[i]) == 0){
			return true;
		}
	}
	return false;
}

room* room::enterDirection(char* direction){//returns the room in the given direction of this room
	for (int i=0; i<exits.size(); i++){
		if (strcmp(direction, exits[i]) == 0){
			return exitRooms[i];
		}
	}
}

bool room::validCollect(){//checks if this room has items
	return (items.size() > 0);
}

item* room::removeItem(int removeItemIndex){//removes an item from the room
	item* copyItem = items[removeItemIndex];
	items.erase(items.begin() + removeItemIndex);
	return copyItem;
}

bool room::checkWinCondition(){//only run by the physics room, if all 5 items are in the room the player wins
	return (items.size() >= 5);
}

void room::print(){//prints out room details, items in the room, and the exits of the room
	cout << "You are in the " << name << ". " << description << endl;
	if (items.size() > 0){
	cout << "You see: " << endl;
		for (int i=0; i<items.size(); i++){
			cout << i << ". ";
			items[i]->print();
		}
	}
	cout << "Exits: " << endl;
	for (int i=0; i<exits.size(); i++){
		cout << exits[i] << ": " << exitRooms[i]->getName() << endl;
	}
}
