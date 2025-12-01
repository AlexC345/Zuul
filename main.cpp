#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
using namespace std;

int main(){
	bool running = true;

	char move[] = "MOVE";
	char collect[] = "COLLECT";
	char command[1000];

	char moveDir[5];

	vector<room*> roomList;
	//add rooms
	room* entrance = new room("Entrance", " The Big ol gate to the school.");
	roomList.push_back(entrance);
	room* mainOffice = new room("Main Office", "There are lots of windows.");
	roomList.push_back(entrance);

	cout << "Welcome to Zuul! (That one game I made last year!)" << endl;
	room* currentRoom;
	vector<item*> inventory;
	
	//add exits
	entrance->addExit("North", mainOffice);

	mainOffice->addExit("South", entrance);

	currentRoom = entrance;

	while(running){
		currentRoom->print();
		cout << "What command do you want to do? (MOVE, COLLECT)";
		cin >> command;
		cin.ignore();
		command[7] = '\0';
		if (strcmp(command, move) == 0){
			cout << "Which direction do you want to move in?: ";
			cin >> moveDir;
			cin.ignore();


		}

	}
	return 0;
}


