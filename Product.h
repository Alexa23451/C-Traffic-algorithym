#pragma once
#include <Node.h>
class Product
{
public:
	Product() {
		value = 0;
		weight = 0;
	}
	~Product() {

	}

	int getValue();

	void setValue(float v);

	int getWeight();

	void setWeight(float w);



private:
	float value;
	float weight;
	Node des;
};
