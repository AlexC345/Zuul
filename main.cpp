#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
using namespace std;
//include stuff
int main(){
	//command terms and running bool
	bool running = true;

	char move[] = "MOVE";
	char collect[] = "COLLECT";
	char inventoryCommand[] = "INVENTORY";
	char drop[] = "DROP";
	char quit[] = "QUIT";
	char command[1000];
	//input variables
	char moveDir[5];

	int itemPickupIndex;
	int itemDropIndex;

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

	counselorOffice->addExit("North", gym);
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
	jail->addItem(bronzeKey);
	artRoom->addItem(silverKey);
	mathRoom->addItem(goldKey);
	counselorOffice->addItem(platinumKey);
	gym->addItem(diamondKey);
	
	//set starting room
	currentRoom = entrance;

	while(running){//main while loop
		//winning condition: put all 5 keys in the physics room
		if (physicsRoom->checkWinCondition()){
			cout << "All the 5 keys insert into the massive door, and it slowly opens, making way for the light. Congratulations. You win!" << endl;
			running = false;
			strcpy(command, quit);
		}
		if (running){//get player command
			currentRoom->print();
			cout << "What command do you want to do? (MOVE, COLLECT, INVENTORY, DROP): ";
			cin >> command;
			cin.ignore();
			command[9] = '\0';
		}
		if (strcmp(command, move) == 0){//if you input MOVE
			cout << "Which direction do you want to move in?: ";
			cin >> moveDir;
			cin.ignore();//get move direction
			if (currentRoom->validDirection(moveDir)){//make sure its a valid direction
				currentRoom = currentRoom->enterDirection(moveDir);//set new current room to room in entered direction
			}
			else{
				cout << "Invalid direction." << endl;
			}
		}
		if (strcmp(command, collect) == 0){//if you input COLLECT
			if (currentRoom->validCollect()){//if there are items in the current room:
				cout << "Enter item index you want to pick up: ";//get input item index to pick up (the room prints the item indexes)
				cin >> itemPickupIndex;
				inventory.push_back(currentRoom->removeItem(itemPickupIndex));//add the item to inventory whilst removing it from the room
				cout << "Added item to inventory." << endl;
			}
			else{
				cout << "No items in this room!" << endl;
			}
		}
		if (strcmp(command, inventoryCommand) == 0){//if you input INVENTORY
			if (inventory.size() > 0){//if you have at least 1 thing in your inventory:
				cout << "INVENTORY: " << endl;
				for (int i=0; i<inventory.size(); i++){//print out everything in your inventory
					cout << inventory[i]->getName() << endl;
				}
			}
			else{
				cout << "Yeah your broke on items." << endl;
			}
		}
		if (strcmp(command, drop) == 0){//if you input DROP
			if (inventory.size() == 0){//if you have nothing in your inventory:
				cout << "You got nothing to drop." << endl;
			}
			else{
				for (int i=0; i<inventory.size(); i++){//print out the inventory and each item's index
					cout << i << ". " << inventory[i]->getName() << endl;
				}
				cout << "Enter item index you want to drop: ";//get player input on which item they want to drop
				cin >> itemDropIndex;
				item* itemDropCopy = inventory[itemDropIndex];//save a copy of the item to drop
				inventory.erase(inventory.begin() + itemDropIndex);//delete item from inventory
				currentRoom->addItem(itemDropCopy);//add item to current room
				cout << "Dropped item in current room." << endl;
			}
		}
		if (strcmp(command, quit) == 0){//if you input QUIT
			running = false;//stop the main loop
			cout << "Quit." << endl;
		}
	}
	//prevent memory leaks
	for (room* r : roomList){
		delete r;
	}
	for (item* i : inventory){
		delete i;
	}
	return 0;
}
