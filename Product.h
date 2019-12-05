#pragma once
#include "Node.h"
class Product
{
public:
	Product() {
		value = 0;
		weight = 0;
	}
	~Product() {

	}

	float getValue();

	void setValue(float);

	float getWeight();

	void setWeight(float);

	int getPos();

	void setPos(int);

private:
	float value;
	float weight;
	int destinationPos;
};
