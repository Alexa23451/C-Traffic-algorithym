#pragma once
#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include "Node.h"
#include "Map.h"

using namespace std;

	int Node:: getVertex() {
		return this->vertex;
	}

	void Node:: setVertex(int v) {
		this->vertex = v;
	}

	void Node::push_edge(int x, float f) {
		pair <int, float> p;
		p.first = x;
		p.second = f;
		connectedNode.push_back(p);
	}

	void Node:: showConnectedNode() {
		int n = connectedNode.size();
		for (int i = 0; i < n; i++) {
			if (getVertex() == i + 1 ) {
				for (int i = 0; i < 8; i++) cout << " ";
				cout << 0 ;
				for (int i = 0; i < 8; i++) cout << " ";
				cout << "|";
			}

			string s = to_string(connectedNode[i].second);

			int range = 0;
			if ((int)connectedNode[i].second == connectedNode[i].second) {
				range = 7;
			}
			else range = 5;

			int temp = (17 - (s.length() - range)) / 2;       
			for (int j = 0; j < temp; j++) cout << " ";
			cout << connectedNode[i].second;

			temp += (s.length() - range) % 2 == 0 ? 1 : 0;
			for (int j = 0; j < temp; j++) cout << " ";

			cout << "|";

			if (i == n - 1 && Map::getInstance()->getNumsVertex() == getVertex()) {
				for (int i = 0; i < 8; i++) cout << " ";
				cout << 0;
				for (int i = 0; i < 8; i++) cout << " ";
				cout << "|";
			}
		}
	}

	vector<pair<int, float> > Node::getConnectedNode() {
		return connectedNode;
	}

	string Node::getName() {
		return this->name;
	}

	void Node::setName(string s) {
		this->name = s;
	}
