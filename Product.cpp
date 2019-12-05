#pragma once
#include "Node.h"
#include "Product.h"

	float Product:: getValue() {
		return this->value;
	}

	void Product::setValue(float v) {
		this->value = v;
	}

	float Product::getWeight() {
		return this->weight;
	}

	void Product::setWeight(float w) {
		this->weight = w;
	}

	int Product::getPos() {
		return this->destinationPos;
	}

	void Product::setPos(int p) {
		this->destinationPos = p;
	}
