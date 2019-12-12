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

	int getVertex();
	void setVertex(int v);
	void showConnectedNode();
	string getName();
	void setName(string s);
	void push_edge(int,float);
	vector<pair<int, float> > getConnectedNode();

private:
	int vertex;
	string name;
	vector <pair <int,float> > connectedNode;
};
