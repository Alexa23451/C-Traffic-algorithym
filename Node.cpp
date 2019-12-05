#pragma once
#include<vector>
#include<utility>
#include<string>
#include<iostream>
#include "Node.h"

using namespace std;

	int Node:: getVertex() {
		return this->vertex;
	}
	void Node:: setVertex(int v) {
		this->vertex = v;
	}

	void Node:: push_edge(int connectedVertex, float distance) {
		pair <int, float> p(connectedVertex, distance);
		connectedNode.push_back(p);
	}

	void Node:: showConnectedNode() {
		for (int i = 0; i < connectedNode.size(); i++) {
			if (connectedNode[i].first <= vertex) continue;

			cout << getName() << " <-> " << connectedNode[i].first;
			cout << " __Khoang cach: " << connectedNode[i].second << endl;
		}
	}

	string Node::getName() {
		return this->name;
	}

	void Node::setName(string s) {
		this->name = s;
	}
