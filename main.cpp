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
	//define items
	item* bronzeKey = new item("Bronze Key", "A clean, bronze key.");
	item* silverKey = new item("Silver Key", "A step up from bronze.");
	item* goldKey = new item("Gold Key", "I bet this would be worth a lot.");
	item* platinumKey = new item("Platinum Key", "Solid platinum. Not bad.");
	item* diamondKey = new item("Diamond Key", "A key forged from the hottest furnaces in our planet's crust.");
	
	//add rooms
	room* entrance = new room("Entrance", "The Big ol gate to the school.");
	roomList.push_back(entrance);
	room* mainOffice = new room("Main Office", "There are lots of windows.");
	roomList.push_back(entrance);
	room* mathRoom = new room("Math Room", "The symbols man... what do they mean?");
        roomList.push_back(mathRoom);
	room* counselorOffice = new room("Counselor's Office", "Mental Health Matters!!!!");
        roomList.push_back(counselorOffice);
	room* mainHall = new room("Main Hall", "It is like crowded here!");
        roomList.push_back(mainHall);
	room* gym = new room("Gym", "Gotta get that daily workout.");
        roomList.push_back(gym);
	room* cafeteria = new room("Cafeteria", "Yummy food!");
        roomList.push_back(cafeteria);
	room* fishbowl = new room("Fishbowl", "I don't see any fish nor water...");
        roomList.push_back(fishbowl);
	room* jail = new room("Prison Room", "This is literally a jail! Who puts this in a school?");
        roomList.push_back(jail);
	room* healthRoom = new room("Health Room", "How to be healthy 101.");
        roomList.push_back(healthRoom);
	room* principlesOffice = new room("Principle's Office", "Someones in trouble...");
        roomList.push_back(principlesOffice);
	room* artRoom = new room("Art Room", "Is this the next Piccasso?");
        roomList.push_back(artRoom);
	room* nappingRoom = new room("Napping Room", "We should legitimatelly get one of these!");
        roomList.push_back(nappingRoom);
	room* languageArtsRoom = new room("Language Arts Room", "The reading and writing room?");
        roomList.push_back(languageArtsRoom);
	room* physicsRoom = new room("Physics Room", "Woah. Thats a big door with 5 key slots. I bet if I put 5 keys in there I get to escape!");
        roomList.push_back(physicsRoom);

	//welcome player
	cout << "Welcome to Zuul!" << endl;
	room* currentRoom;
	vector<item*> inventory;
	
	//add exits
	entrance->addExit("North", mainOffice);

	mainOffice->addExit("North", mainHall);
	mainOffice->addExit("South", entrance);
	mainOffice->addExit("East", counselorOffice);
	mainOffice->addExit("West", mathRoom);

	mathRoom->addExit("East", mainOffice);

	counselo-rOffice->addExit("North", gym);
        counselorOffice->addExit("West", mainOffice);

	mainHall->addExit("North", cafeteria);
        mainHall->addExit("South", mainOffice);
        mainHall->addExit("East", gym);

	gym->addExit("North", fishbowl);
	gym->addExit("West", mainHall);
	gym->addExit("South", counselorOffice);

	cafeteria->addExit("North", healthRoom);
        cafeteria->addExit("South", mainHall);
        cafeteria->addExit("East", fishbowl);
        cafeteria->addExit("West", jail);

	jail->addExit("East", cafeteria);

	fishbowl->addExit("West", cafeteria);

	healthRoom->addExit("North", principlesOffice);
        healthRoom->addExit("South", cafeteria);

	principlesOffice->addExit("North", nappingRoom);
        principlesOffice->addExit("South", healthRoom);
        principlesOffice->addExit("East", artRoom);
        principlesOffice->addExit("West", languageArtsRoom);

	languageArtsRoom->addExit("East", principlesOffice);

	artRoom->addExit("West", principlesOffice);

	nappingRoom->addExit("North", physicsRoom);
        nappingRoom->addExit("South", principlesOffice);

	physicsRoom->addExit("South", nappingRoom);
	
	//add items
	entrance->addItem(bronzeKey);
	entrance->addItem(silverKey);
	entrance->addItem(goldKey);
	entrance->addItem(platinumKey);
	entrance->addItem(diamondKey);
	
	//set starting room
	currentRoom = entrance;

	while(running){
		currentRoom->print();
		cout << "What command do you want to do? (MOVE, COLLECT): ";
		cin >> command;
		cin.ignore();
		command[7] = '\0';
		if (strcmp(command, move) == 0){
			cout << "Which direction do you want to move in?: ";
			cin >> moveDir;
			cin.ignore();
			if (currentRoom->validDirection(moveDir)){
				currentRoom = currentRoom->enterDirection(moveDir);
			}
			else{
				cout << "Invalid direction." << endl;
			}
		}


	}
	return 0;
}


