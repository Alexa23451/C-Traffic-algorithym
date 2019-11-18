#pragma once
#include <Node.h>
#include "Product.h"

	int Product:: getValue() {
		return this->value;
	}

	void Product::setValue(float v) {
		this->value = v;
	}

	int Product::getWeight() {
		return this->weight;
	}

	void Product::setWeight(float w) {
		this->weight = w;
	}
