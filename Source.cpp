#include <iostream>
#include "Map.h"
#include <Shipper.h>

using namespace std;

void menu();
void mapMenu();
Map map;
Shipper shipper;

void menu() {
	cout << "\n---------------------------------------------\n";
	cout  << "_____________GIAO DIEN CONSOLE___________\n\n";
	cout  <<"     NHOM 1: BAI TOAN NGUOI GIAO HANG    \n";
	cout  <<"_ _ _ _  Xin moi nhap chuc nang _ _ _ _ \n";
	cout << "Type 1: Map ---" << map.checkOn()  << endl;
	cout << "Type 2: Shipper\n";
	cout << "Type 3: Product\n";
	cout << "Type 4: Main menu\n";
	cout << "Type 0: Exit\n";
	cout << "---------------------------------------------\n";
	char c;
	ahu:cout << "\nYour command : ";
	cin >> c;
	switch (c)
	{
	case '1': {
		mapMenu();
		break;
	}
	case '2': {

		break;
	}
	case '3': {

		break;
	}
	case '4': {

		break;
	}
	case '0': {
		cout << "Thanks you for using this program ^^";
		exit(0);
	}
	default:
		cout << "\n Wrong command: Type again\n";
		goto ahu;
	}
}

void mapMenu() {
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
	char c;
	ahu:cout << "\nYour command : ";
	cin >> c;
	switch (c)
	{
	case '1': {
		map.initMap();
		goto ahu;
		break;
	}
	case '2': {
		map.resetMap();
		goto ahu;
		break;
	}
	case '3': {
		map.showMap();
		goto ahu;
		break;
	}
	case '4': {
		Node add;

		map.addNode(add);
		goto ahu;
		break;
	}
	case '5': {
		int nn;
		cout << "\nType number of node u want to delete: ";
		cin >> nn;

		map.deleteNode(nn);
		goto ahu;
		break;
	}
	case '6': {
		int nn;
		cout << "\nType number of node u want to edit: ";
		cin >> nn;

		map.editNode(nn);
		goto ahu;
		break;
	}
	case '0': {
		cout << "\nBack....\n";
		menu();
		break;
	}
	default:
		cout << "\n Wrong command: Type again\n";
		goto ahu;
	}
}

int main() {
	menu();
	
}