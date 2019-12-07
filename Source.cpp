#include <iostream>
#include "Map.h"
#include "Shipper.h"
#include "Node.h"
#include "Product.h"
#include "TimeMap.h"
#include <windows.h>
#include <stdlib.h>

using namespace std;

void menu();
void mapMenu();
void mapMenuProcess();
void mapShipper();
void mapShipperProcess();
void productMenu();
void productMenuProcess();

TimeMap time;
Product product;

void clear() {
	system("CLS");
}

void pause() {
	system("PAUSE");
}

void menu() {

	while (1) {
		cout << "____________Menu______________________ \n\n";
		cout << "\n---------------------------------------------\n";
		cout << "_____________GIAO DIEN CONSOLE___________\n\n";
		cout << "     NHOM 1: BAI TOAN NGUOI GIAO HANG    \n";
		cout << "_ _ _ _  Xin moi nhap chuc nang _ _ _ _ \n";
		cout << "Type 1: Map ---" << Map::getInstance()->checkOn() << endl;
		cout << "Type 2: Shipper ---" << Shipper::getInstance()->checkOn() << endl;
		cout << "Type 3: Product in deliver: " <<product.getNumsProduct() <<endl;
		cout << "Type 4: Start DELIVERY !\n";
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
			productMenu();
			productMenuProcess();
			break;
		}
		case '4': {
			clear();
			break;
		}
		case '0': {
			clear();
			cout << "Thanks you for using this program ^^";
			exit(0);
		}
		default: {
			cout << "\n Wrong command: Type again\n";
		}
		}
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

	while (1) {
		char c;
		cout << "\nYour command : ";
		cin >> c;
		switch (c)
		{
			case '1': {
				Map::getInstance()->initMap();
				pause();
				clear();
				mapMenu();
				break;
			}
			case '2': {
				Map::getInstance()->resetMap();
				pause();
				clear();
				mapMenu();
				break;
			}
			case '3': {
				Map::getInstance()->showMap();
				pause();
				clear();
				mapMenu();
				break;
			}
			case '4': {
				Node add;
				Map::getInstance()->addNode(add);
				pause();
				clear();
				mapMenu();
				break;
			}
			case '5': {
				int nn;
				cout << "\nType number of node u want to delete: ";
				cin >> nn;

				Map::getInstance()->deleteNode(nn);
				pause();
				clear();
				mapMenu();
				break;
			}
			case '6': {
				int nn;
				cout << "\nType number of node u want to edit: ";
				cin >> nn;

				Map::getInstance()->editNode(nn);
				pause();
				clear();
				mapMenu();
				break;
			}
			case '0': {
				clear();
				cout << "\nBack....\n";
				menu();
				return;
			}
			default:
				cout << "\n Wrong command: Type again\n";
		}
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
	time.setTime();
	Shipper::getInstance()->setPosition();
	pause();
	clear();
}

void productMenu() {
	cout << "______________Menu -> Product_________________\n\n";

	cout << "\n---------------------------------------------\n";
	cout << "_____________GIAO DIEN PRODUCT_________________\n\n";
	cout << "     NHOM 1: BAI TOAN NGUOI GIAO HANG    \n";
	cout << "---------------------------------------------\n";
	cout << "_ _ _ _  Xin moi nhap chuc nang _ _ _ _ \n";
	cout << "Type 1: Add Product\n";
	cout << "Type 2: Edit Product\n";
	cout << "Type 3: Delete Product\n";
	cout << "Type 4: Show all Product\n";
	cout << "Type 0: Back\n";
	cout << "---------------------------------------------\n";
}

void productMenuProcess() {

	while (1) {
		char c;
		cout << "\nYour command : ";
		cin >> c;
		switch (c)
		{
			case '1': {
				product.addProduct();
				pause();
				clear();
				productMenu();
				break;
			}
			case '2': {
				product.editProduct();
				pause();
				clear();
				productMenu();
				break;
			}
			case '3': {
				product.deleteProduct();
				pause();
				clear();
				productMenu();
				break;
			}
			case '4': {
				product.showProduct();
				pause();
				clear();
				productMenu();
				break;
			}
			case '0': {
				clear();
				cout << "\nBack....\n";
				menu();
				break;
			}
			default: {
				cout << "\n Wrong command: Type again\n";
			}				
		}
	}
}

int main() {
	menu();
	
}

