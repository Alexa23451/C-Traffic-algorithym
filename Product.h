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

	void setValue(int);

	float getWeight();

	void setWeight(int);

	int getPos();

	void setPos(int);

	void setName(string);

	string getName();

private:
	int value;
	int weight;
	int destinationPos;
	string name;
};
