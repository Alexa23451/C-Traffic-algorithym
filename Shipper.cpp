#include "Shipper.h"
#include "Node.h"
#include "Map.h"

using namespace std;

Shipper::Shipper() {
	currentPos = 0;
}

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

}

void Shipper::updateListProduct() {

}

void Shipper::showPath() {

}

void Shipper::updatePath(Node posAdd) {

}

string Shipper::checkOn() {
	return currentPos == -1 ? "NOT FOUND" : "OK";
}
