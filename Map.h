#pragma once
#include <vector>
#include <Node.h>
#include <iostream>
#include <fstream>

using namespace std;

class Map
{
public:
	Map() {
		numofVertex = 0;
		numofEdge = 0;
	}
	~Map() {

	}

	void addNode(Node n);

	void deleteNode(int i);

	void editNode(int i);

	void initMap();

	void showMap();

	void resetMap();

	string checkOn();

private:
	int numofVertex;
	int numofEdge;
	vector <Node> listofNode;
};
