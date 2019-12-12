#include <vector>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <queue>
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

int Shipper::getStoreDeliver() {
	return storeDeliver;
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
		cout << "Weight : " << listProduct[i].getWeight() << "Kg" << endl;
		cout << "Value : " << listProduct[i].getValue() << "Vnd" << endl;
		cout << "Destination : " << "Duong " << v[listProduct[i].getPos()-1].getName() << endl;
	}
}

void Shipper::addProduct() {
	int w, v, d;
	string s;
	Product p;
	vector<Node> vv = Map::getInstance()->getlistOfNode();
	for (int i = 0; i < vv.size(); i++) {
		cout << "\nChoise " << i + 1 << " : " << vv[i].getName() << " !!!";
	}

	cout << "\nType Destination ::: ";
	cin >> d;

	if (d < 1 || d > vv.size() || d == getPosition()) {
		cout << "Wrong request ___Again \n";
		return;
	}
	p.setPos(d);

	fflush(stdin);
	cout << "Type Name :(No space) ";
	cin >> s;

	p.setName(s);
	
	cout << "Type Weight : (1kg - 10kg): "; 
	cin >> w;

	if (w < 1 || w>10) {
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
	for (int i = 0; i < vv.size(); i++) {
		cout << "\nChoise " << i + 1 << " : " << vv[i].getName() << " !!!";
	}
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

	cout << "Type Weight : (1 - 10kg): ";
	cin >> w;

	if (w < 1 || w>10) {
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
	for (int i = 0; i < vv.size(); i++) {
		cout << "\nChoise " << i + 1 << " : " << vv[i].getName() << " !!!";
	}
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
	if (getPosition() == -1) {
		cout << "\nVui long nhap thong tin, vi tri cua Shipper !!!\n\n";
		return;
	}

	// su dung thuat toan dijkstra
	int n = Map::getInstance()->getNumsVertex();
	typedef pair<int, float> ii;
	vector<Node> aa = Map::getInstance()->getlistOfNode();
	
	vector<ii> a[20];

	for (int i = 0; i < aa.size(); i++) {
		a[aa[i].getVertex()] = aa[i].getConnectedNode();
	}
	for (int i = 1; i <= n; i++) a[i].push_back(ii(0, 0)); 
	
	const int oo = 1000111000;
	float d[100];

	priority_queue < ii , vector<ii> , greater<ii> > pq;
	int i, u, v;
	int du, uv;
	
	for (i = 1; i <= n; i++) d[i] = oo;

	d[1] = 0;
	int iii = getPosition();
	pq.push(ii(iii, 0));

	while (pq.size()) {
		u = pq.top().first;
		du = pq.top().second;
		pq.pop();
		if (du != d[u]) continue;

		for (i = 0; v = a[u][i].first; i++)
		{
			uv = a[u][i].second;
			if (d[v] > du + uv) {
				d[v] = du + uv;
				pq.push(ii(v , d[v]));
			}
		}
	}

	for (i = 1; i <= n; i++) {
		if (i == iii) continue;
		cout << "Duong di ngan nhat tu " << aa[iii].getName() << " den " << aa[i-1].getName() << " la " << d[i] << endl;
	}
		
}

void Shipper::showBagbest() {
	int x = listProduct.size();
	int y = storeDeliver;

	int** bagBest = new int* [x+1];
	for (int i = 0; i <= x; i++)
		bagBest[i] = new int[y+1];

	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			bagBest[i][j] = 0;
		}
	}

	int max = 0;
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if (listProduct[i-1].getWeight() <= j) {
				int temp = listProduct[i-1].getWeight();
				bagBest[i][j] = listProduct[i-1].getValue() + bagBest[i - 1][j - temp];
				if (max < bagBest[i][j]) {
					max = bagBest[i][j];
				}
			}
			else {
				bagBest[i][j] = bagBest[i - 1][j];
			}
		}
	}

	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			cout<<bagBest[i][j]<<" " ;
		}
		cout << endl;
	}

	cout << "\nSo tien lon nhat thu duoc la " << max <<" VND " << endl;
	delete bagBest;
}

int Shipper::getNumsProduct() {
	return number;
}

string Shipper::checkOn() {
	return currentPos == -1 ? "NOT FOUND" : "OK";
}
