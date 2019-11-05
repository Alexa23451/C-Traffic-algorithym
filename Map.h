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

	}
	~Map() {

	}

	void addNode(Node n) {

	}

	void deleteNode(int i) {

	}

	void editNode(int i) {

	}

	void initMap() {
		int userInput;
		hi:cout << "1: Tao ban do:\n";
		cout << "Nhap ten file (.IN): ";
		string fileName;
		cin >> fileName;
		fileName += ".IN";

		fstream inputMap(fileName);

		if (inputMap.fail()) {
			cout << "File khong ton tai ??? \n";
			cout << "1 : Nhap lai ?"<<endl;
			cout << "0 : Thoat chuong trinh ?" << endl;
			cin >> userInput;
			if (userInput) {
				goto hi;
			}
			else exit(0);
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

		showMap();

	}

	void showMap() {
		cout << "_ _ _ _ _ _ Ban do cua ban _ _ _ _ _ _ _\n";
		for (int i = 0; i < listofNode.size(); i++) {
			//cout << "Vi tri thu " << i + 1 << endl;
			listofNode[i].showConnectedNode();
		}
	}

	void resetMap() {

	}

private:
	int numofVertex;
	int numofEdge;
	vector <Node> listofNode;
};
