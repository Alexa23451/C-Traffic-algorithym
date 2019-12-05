#include "Shipper.h"
#include "Node.h"
#include "Map.h"

using namespace std;


void Shipper::setPosition() {
	cout << "\nVi tri hien tai cua ban ?\n";
	Map* map = Map::getInstance();

	
//	map->showMap();
	
	


	
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
