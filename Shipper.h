#pragma once
#include "Node.h"
#include "Product.h"
#include "TimeMap.h"
#include <vector>

using namespace std;

class Shipper
{
public:
	Shipper() {
		currentPos = -1;
	}
	~Shipper() {

	}
	
	void setPosition();
	int getPosition();
	void showListProduct();
	void updateListProduct();
	void showPath();
	void updatePath(Node);
	string checkOn();

private:
	int currentPos;
	vector <Node> listPos;
	vector <Product> listProduct;
	TimeMap startTime;
	TimeMap endTime;
};