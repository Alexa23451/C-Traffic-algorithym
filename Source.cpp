#include "Map.h"
#include "Shipper.h"
#include "Node.h"
#include "Product.h"
#include "TimeMap.h"
#include <iostream>
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
void analyzeMenu();
void analyzeMenuProcess();

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
		cout << "Type 3: Product in deliver: " <<Shipper::getInstance()->getNumsProduct() <<endl;
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
			if (Map::getInstance()->checkOn() == "NOT FOUND") {
				cout << "\nNhap thong tin Map truoc !!!\n";
				break;
			}
			mapShipper();
			mapShipperProcess();
			break;
		}
		case '3': {
			clear();
			if (Map::getInstance()->checkOn() == "NOT FOUND") {
				cout << "\nNhap thong tin Map truoc !!!\n";
				break;
			}
			productMenu();
			productMenuProcess();
			break;
		}
		case '4': {
			//if (Map::getInstance()->checkOn() != "OK" || Shipper::getInstance()->checkOn() != "OK"
			//	|| !Shipper::getInstance()->getNumsProduct()) {
			//	cout << "\nNhap du cac thong tin truoc !!!\n";
			//	break;
			//}
			clear();
			analyzeMenu();
			analyzeMenuProcess();
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
	TimeMap::getInstance()->setTime();
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
				Shipper::getInstance()->addProduct();
				pause();
				clear();
				productMenu();
				break;
			}
			case '2': {
				Shipper::getInstance()->editProduct();
				pause();
				clear();
				productMenu();
				break;
			}
			case '3': {
				Shipper::getInstance()->deleteProduct();
				pause();
				clear();
				productMenu();
				break;
			}
			case '4': {
				Shipper::getInstance()->showListProduct();
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

void analyzeMenu() {
	cout << "______________Menu -> Delivery_________________\n\n";

	cout << "\n---------------------------------------------\n";
	cout << "_____________GIAO DIEN Delivery___________\n\n";
	cout << "     NHOM 1: BAI TOAN NGUOI GIAO HANG    \n";
	cout << "_ _ _ _  Xin moi nhap chuc nang _ _ _ _ \n";
	cout << "Type 1: Best Value\n";
	cout << "Type 2: Best Road\n";
	cout << "Type 0: Back\n";
	cout << "---------------------------------------------\n";
}

void analyzeMenuProcess() {
	while (1) {
		char c;
		cout << "\nYour command : ";
		cin >> c;
		switch (c)
		{
		case '1': {
			Shipper::getInstance()->showBagbest();
			pause();
			clear();
			analyzeMenu();
			break;
		}
		case '2': {
			Shipper::getInstance()->showPath();
			pause();
			clear();
			analyzeMenu();
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

