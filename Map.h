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

	void addNode(Node n) {

	}

	void deleteNode(int i) {

	}

	void editNode(int i) {

	}

	void initMap() {
		string userInput;
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
			if (userInput =="0") {
				cout << "Cam on ban da su dung chuong trinh !!!";
				exit(0);
			}
			else goto hi;
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

		cout << "\nBan do cua ban co " << numofVertex << " vi tri !!!" << endl;
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
