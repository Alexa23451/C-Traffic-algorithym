#pragma once
#include <vector>
#include <Node.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"

using namespace std;


	void Map:: addNode(Node n) {
		if (!numofEdge) {
			cout << "No map to add Node :((((\n";
			cout << "Go to init Map ? 1 / 0 :";
			char c;
			cin >> c;
			if (c == '1') {
				initMap();
			}
			return;
		}
	}

	void Map:: deleteNode(int i) {
		if (!numofEdge) {
			cout << "No map delete Node :((((\n";
			cout << "Go to init Map ? 1 / 0 :";
			char c;
			cin >> c;
			if (c == '1') {
				initMap();
			}
			return;
		}
	}

	void Map:: editNode(int i) {
		if (!numofEdge) {
			cout << "No map to edit Node :((((\n";
			cout << "Go to init Map ? 1 / 0 :";
			char c;
			cin >> c;
			if (c == '1') {
				initMap();
			}
			return;
		}
	}

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
		for (int i = 1; i <= numofEdge; i++) {
			Node n;
			n.setVertex(i);
			listofNode.push_back(n);
		}

		for (int i = 1; i <= numofEdge; i++) {
			int x, y;
			float value;
			inputMap >> x >> y >> value;

			listofNode[x - 1].push_edge(y, value);
			listofNode[y - 1].push_edge(x, value);
		}

		cout << "Ban do cua ban co " << numofVertex << " vi tri...";
		showMap();

	}

	void Map:: showMap() {
		if (!numofEdge) {
			cout << "No map to show :((((\n";
			return;
		}

		cout << "_ _ _ _ _ _ Ban do cua ban _ _ _ _ _ _ _\n";
		for (int i = 0; i < listofNode.size(); i++) {
			//cout << "Vi tri thu " << i + 1 << endl;
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

	// you have already signed in it
	// you must to assign is correctly
