#include <vector>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include "Shipper.h"
#include "Node.h"
#include "Map.h"
#include "TimeMap.h"

using namespace std;

Shipper::Shipper() {
	currentPos = -1;
}

int Shipper::number = 0;
Shipper* Shipper::getInstance() {
	if (instance == NULL) {
		instance = new Shipper();
	}
	return instance;
}

Shipper *Shipper::instance = NULL; 

void Shipper::setPosition() {
	cout << "\nVi tri hien tai cua ban ?\n";
	Map::getInstance()->showMap();
	
	vector<Node> v = Map::getInstance()->getlistOfNode();
	string cmd;
	mark:cout << "\nBan dang o dau ? (Nhap so hoac chu) ";
	cin >> cmd;
	if (cmd.length() == 1) {
		if (cmd[0] >= 48 && cmd[0] < 58 && cmd[0]-48 <= v.size()) {
			currentPos = cmd[0] - 49;
			cout << "\nBan dang o " << v[currentPos].getName() << " !!!\n";
		}
		else {
			cout << "Nhap sai cu phap...Yeu cau nhap lai !!!";
			goto mark;
		}
	}
	else {
		
		for (int i = 0; i < v.size(); i++) {
			if (cmd == v[i].getName()) {
				currentPos = v[i].getVertex();
				cout << "\nBan dang o " << v[i].getName() <<" !!!\n";
				break;
			}
		}
	}
	

}

int Shipper::getPosition() {
	return this->currentPos;
}

void Shipper::showListProduct() {
	if (!listProduct.size()) {
		cout << "\n Have no Product !! \n";
		return;
	}
	vector <Node> v = Map::getInstance()->getlistOfNode();

	for (int i = 0; i < listProduct.size(); i++) {
		cout << "\nProduct " << i+1 << endl;
		cout << "Name : " << listProduct[i].getName() << endl;
		cout << "Weight : " << listProduct[i].getWeight() << "Gr" << endl;
		cout << "Value : " << listProduct[i].getValue() << "Vnd" << endl;
		cout << "Destination : " << "Duong " << v[listProduct[i].getPos()-1].getName() << endl;
	}
}

void Shipper::addProduct() {
	int w, v, d;
	string s;
	Product p;

	fflush(stdin);
	cout << "Type Name :(No space) ";
	cin >> s;

	p.setName(s);
	
	cout << "Type Weight : (100gr - 10000gr): "; 
	cin >> w;

	if (w < 100 || w>10000) {
		cout << "Wrong request ___Again \n";
		return;
	}
	p.setWeight(w);

	cout << "Type Value : (10000 - 1000000vnd): ";
	cin >> v;
	if (v < 10000 || v>1000000) {
		cout << "Wrong request ___Again \n";
		return;
	}
	p.setValue(v);

	vector<Node> vv = Map::getInstance()->getlistOfNode();

	for (int i = 0; i < vv.size(); i++) {
		cout << "\nChoise " << i+1 << " : " << vv[i].getName() << " !!!";
	}

	cout << "\nType Destination ::: ";
	cin >> d;

	if (d < 1 || d > vv.size()) {
		cout << "Wrong request ___Again \n";
		return;
	}
	p.setPos(d);

	listProduct.push_back(p);
	cout << "\nAdding Product Succesfully\n";
	number++;
}

void Shipper::editProduct() {
	if (listProduct.empty()) {
		cout << "\nNo product to edit\n";
		return;
	}

	vector<Node> vv = Map::getInstance()->getlistOfNode();
	int temp;

	showListProduct();
	cout << "\nType Product index you want to edit:: ";
	cin >> temp;

	if (temp < 1 || temp > listProduct.size()) {
		cout << "\n Its not exist....Back to menu \n";
		return;
	}
	else temp--;

	int w, v, d;
	string s;

	fflush(stdin);
	cout << "Type Name :(No space) ";
	cin >> s;

	cout << "Type Weight : (100gr - 10000gr): ";
	cin >> w;

	if (w < 100 || w>10000) {
		cout << "Wrong request ___Again \n";
		return;
	}

	cout << "Type Value : (10000 - 1000000vnd): ";
	cin >> v;
	if (v < 10000 || v>1000000) {
		cout << "Wrong request ___Again \n";
		return;
	}

	for (int i = 0; i < vv.size(); i++) {
		cout << "\nChoise " << i + 1 << " : " << vv[i].getName() << " !!!";
	}
	cout << "\nType Destination ::: ";
	cin >> d;

	if (d < 1 || d > vv.size()) {
		cout << "Wrong request ___Again \n";
		return;
	}

	listProduct[temp].setWeight(w);
	listProduct[temp].setValue(v);
	listProduct[temp].setPos(d);
	listProduct[temp].setName(s);

	cout << "\Editing Product Succesfully\n";
}

void Shipper::deleteProduct() {
	if (listProduct.empty()) {
		cout << "\nNo product to edit\n";
		return;
	}

	vector<Node> vv = Map::getInstance()->getlistOfNode();
	int temp;

	showListProduct();
	cout << "\nType Product index you want to delete:: ";
	cin >> temp;

	if (temp <= 0 || temp > listProduct.size()) {
		cout << "\n Its not exist....Back to menu \n";
		return;
	}
	else temp--;

	listProduct.erase(listProduct.begin() + temp);
	cout << "\Deleting Product Succesfully\n";
	number--;
}

void Shipper::showPath() {

}

void Shipper::updatePath(Node posAdd) {

}

int Shipper::getNumsProduct() {
	return number;
}

string Shipper::checkOn() {
	return currentPos == -1 ? "NOT FOUND" : "OK";
}
