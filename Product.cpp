#pragma once
#include "Node.h"
#include "Product.h"
#include "Map.h"

	float Product:: getValue() {
		return this->value;
	}

	void Product::setValue(int v) {
		this->value = v;
	}

	float Product::getWeight() {
		return this->weight;
	}

	void Product::setWeight(int w) {
		this->weight = w;
	}

	int Product::getPos() {
		return this->destinationPos;
	}

	void Product::setPos(int p) {
		this->destinationPos = p;
	}

	void Product::setName(string n) {
		name = n;
	}

	string Product::getName() {
		return name;
	}
