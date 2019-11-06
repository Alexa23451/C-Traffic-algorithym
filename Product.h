#pragma once
#include <Node.h>
class Product
{
public:
	Product() {

	}
	~Product() {

	}

	int getValue() {
		return this->value;
	}

	void setValue(float v) {
		this->value = v;
	}

	int getWeight() {
		return this->weight;
	}

	void setWeight(float w) {
		this->weight = w;
	}



private:
	float value;
	float weight;
	Node des;
};
