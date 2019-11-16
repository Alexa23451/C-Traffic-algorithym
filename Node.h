#pragma once
#include<vector>
#include<utility>
#include<string>
#include<iostream>

using namespace std;

class Node
{
public:
	Node(){
		vertex = 0;
	}
	~Node(){}

	int getVertex() {
		return this->vertex;
	}
	void setVertex(int v) {
		this->vertex = v;
	}

	void push_edge(int connectedVertex , float distance) {
		pair <int, float> p(connectedVertex, distance);
		connectedNode.push_back(p);
	}

	void showConnectedNode() {
		for (int i = 0; i < connectedNode.size(); i++) {
			if (connectedNode[i].first <= vertex) continue;

			cout <<vertex<<" <-> " <<connectedNode[i].first ;
			cout << " __Khoang cach: " << connectedNode[i].second <<endl;
		}
	}

	string getName() {
		return this->name;
	}

	void setName(string s) {
		this->name = s;
	}

private:
	int vertex;
	string name;
	vector <pair <int,float> > connectedNode;

};
