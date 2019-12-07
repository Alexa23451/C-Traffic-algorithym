#pragma once
#include "Node.h"
#include "Product.h"
#include "TimeMap.h"
#include <vector>

using namespace std;

class Shipper
{
public:
	~Shipper() {

	}
	void setPosition();
	int getPosition();

	
	void showListProduct();
	void editProduct();
	void deleteProduct();
	void addProduct();

	void showPath();
	void updatePath(Node);
	string checkOn();
	static Shipper* getInstance();
	static int getNumsProduct();

private:
	static Shipper* instance;
	int currentPos;
	static int number;
	vector <Node> listPos;
	vector <Product> listProduct;
	Shipper();
};