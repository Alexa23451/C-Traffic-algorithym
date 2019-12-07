#pragma once
#include <vector>
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"

using namespace std;

	void Map:: initMap() {
		if (numofVertex) {
			cout << "Map has alreaddy inited ! Reset map first to init\n";
			return;
		}

		char userInput;
	 hi:cout << "1: Tao ban do:\n";
		cout << "Nhap ten file (.IN): ";
		string fileName;
		cin >> fileName;
		fileName += ".IN";

		fstream inputMap(fileName);

		if (inputMap.fail()) {
			cout << "File khong ton tai ??? \n";
			cout << "1 : Retype ?" << endl;
			cout << "Type anykey to Back ?" << endl;
			cin >> userInput;
			if (userInput == '1') {
				goto hi;
			}
			else return;
		}
		else {
			cout << "Nhap file thanh cong !!!\n";
		}

		inputMap >> numofVertex >> numofEdge;

		for (int i = 1; i <= numofVertex; i++) {
			string s;
			inputMap >> s;
			Node n;
			n.setVertex(i);
			n.setName(s);
			listofNode.push_back(n);
		}

		for (int i = 1; i <= numofEdge; i++) {
			int x, y;
			float value;
			inputMap >> x >> y >> value;

			listofNode[x - 1].push_edge(y, value);
			listofNode[y - 1].push_edge(x, value);
		}
		

		cout << "\nBan do cua ban co " << numofVertex << " vi tri...\n";
		showMap();

		inputMap.close();
	}

	void Map:: showMap() {
		if (!numofEdge) {
			cout << "No map to show :((((\n";
			return;
		}

		cout << "_ _ _ _ _ _ Ban do cua ban _ _ _ _ _ _ _\n";
		for (int i = 0; i < listofNode.size(); i++) {
			cout << "\nVi tri thu " << i + 1 <<" : " << listofNode[i].getName() <<endl;
			listofNode[i].showConnectedNode();
		}
	}

	void Map:: resetMap() {
		if (!numofEdge) {
			cout << "No map to reset :((((\n";
			return;
		}
		else {
			numofVertex = 0;
			numofEdge = 0;
			listofNode.clear();
			cout << "Reset successfully\n";
		}
	}

	string Map:: checkOn() {
		return numofVertex > 0 ? "OK" : "NOT FOUND";		
	}

	Map* Map::instance = NULL;

	Map::Map()
	{
		numofEdge = 0;
		numofVertex = 0;
	}

	Map* Map::getInstance() {
		if (instance == NULL) {
			instance = new Map();
		}
		return instance; 
	}

	vector<Node> Map::getlistOfNode() {
		return listofNode;
	}
