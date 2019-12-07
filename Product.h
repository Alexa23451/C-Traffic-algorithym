#pragma once
#include "Node.h"
#include <vector>
class Product
{
public:
	Product() {
		value = 0;
		weight = 0;
		destinationPos = 0;
	}
	~Product() {

	}

	float getValue();

	void setValue(float);

	float getWeight();

	void setWeight(float);

	int getPos();

	void setPos(int);

	int getNumsProduct();

	void addProduct();

	void editProduct();

	void deleteProduct();

	void showProduct();

private:
	float value;
	float weight;
	int destinationPos;
	static int number;
};
