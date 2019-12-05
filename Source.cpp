#include <iostream>
#include "Map.h"
#include "Shipper.h"
#include "Node.h"
#include <windows.h>
#include <stdlib.h>

using namespace std;

void menu();
void mapMenu();
void mapMenuProcess();
void mapShipper();
void mapShipperProcess();

Map map;
Shipper shipper;
TimeMap time;

void clear() {
	system("CLS");
}

void pause() {
	system("PAUSE");
}

void menu() {
	cout << "____________Menu______________________ \n\n";
	cout << "\n---------------------------------------------\n";
	cout << "_____________GIAO DIEN CONSOLE___________\n\n";
	cout  <<"     NHOM 1: BAI TOAN NGUOI GIAO HANG    \n";
	cout  <<"_ _ _ _  Xin moi nhap chuc nang _ _ _ _ \n";
	cout << "Type 1: Map ---" << map.checkOn()  << endl;
	cout << "Type 2: Shipper ---" << shipper.checkOn() <<endl;
	cout << "Type 3: Main menu\n";
	cout << "Type 0: Exit\n";
	cout << "---------------------------------------------\n";
	char c;
	ahu:cout << "\nYour command : ";
	cin >> c;
	switch (c)
	{
	case '1': {
		clear();
		mapMenu();
		mapMenuProcess();
		break;
	}
	case '2': {
		clear();
		mapShipper();
		mapShipperProcess();
		break;
	}
	case '3': {
		clear();
		break;
	}
	case '0': {
		clear();
		cout << "Thanks you for using this program ^^";
		exit(0);
	}
	default:
		cout << "\n Wrong command: Type again\n";
		goto ahu;
	}
}

void mapMenu() {
	cout << "______________Menu -> Map_________________\n\n";

	cout << "\n---------------------------------------------\n";
	cout << "_____________GIAO DIEN MAP___________\n\n";
	cout << "     NHOM 1: BAI TOAN NGUOI GIAO HANG    \n";
	cout << "_ _ _ _  Xin moi nhap chuc nang _ _ _ _ \n";
	cout << "Type 1: Init Map\n";
	cout << "Type 2: Reset Map\n";
	cout << "Type 3: Show Map\n";
	cout << "Type 4: Add Location\n";
	cout << "Type 5: Delete Location\n";
	cout << "Type 6: Edit Location\n";
	cout << "Type 0: Back\n";
	cout << "---------------------------------------------\n";
}

void mapMenuProcess() {

	char c;
	ahu:cout << "\nYour command : ";
	cin >> c;
	switch (c)
	{
	case '1': {
		map.initMap();
		pause();
		clear();
		mapMenu();
		goto ahu;
	}
	case '2': {
		map.resetMap();
		pause();
		clear();
		mapMenu();
		goto ahu;
	}
	case '3': {
		map.showMap();
		pause();
		clear();
		mapMenu();
		goto ahu;
	}
	case '4': {
		Node add;
		map.addNode(add);
		pause();
		clear();
		mapMenu();
		goto ahu;
	}
	case '5': {
		int nn;
		cout << "\nType number of node u want to delete: ";
		cin >> nn;

		map.deleteNode(nn);
		pause();
		clear();
		mapMenu();
		goto ahu;
	}
	case '6': {
		int nn;
		cout << "\nType number of node u want to edit: ";
		cin >> nn;

		map.editNode(nn);
		pause();
		clear();
		mapMenu();
		goto ahu;
	}
	case '0': {
		clear();
		cout << "\nBack....\n";
		menu();
		break;
	}
	default:
		cout << "\n Wrong command: Type again\n";
		goto ahu;
	}
}

void mapShipper(){
	cout << "______________Menu -> Shipper_________________\n\n";

	cout << "\n---------------------------------------------\n";
	cout << "_____________GIAO DIEN SHIPPER_________________\n\n";
	cout << "     NHOM 1: BAI TOAN NGUOI GIAO HANG    \n";
	cout << "---------------------------------------------\n";
}


void mapShipperProcess() {
//	time.setTime();
	shipper.setPosition();
	
}

int main() {
	menu();
	
}