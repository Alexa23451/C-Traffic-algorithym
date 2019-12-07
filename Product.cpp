#pragma once
#include "Node.h"
#include "Product.h"
#include "Map.h"

	int Product::number = 0;

	int Product::getNumsProduct() {
		return number;
	}

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

	void Product::addProduct() {
		//Map m;
		//Map* map = m.getInstance();
		//int w, v, d;
		//Product p;

		//cout << "Type Weight : (100gr - 10000gr)"; 
		//cin >> w; 
		//if (w < 100 || w>10000) {
		//	cout << "Wrong type ___ Back to menu";
		//	return;
		//}
		//p.setWeight(w);

		//cout << "Type Value : (10000 - 1000000vnd)";
		//cin >> v;
		//if (v < 10000 || v>1000000) {
		//	cout << "Wrong type ___ Back to menu";
		//	return;
		//}
		//p.setValue(v);

		//vector<Node> vv = map->getlistOfNode();
		//cout << "Type Destination :::\n";
		//for (int i = 0; vv.size(); i++) {
		//	cout << "Choise " << i + 1 << " : " << vv[i].getName() <<endl;
		//}
		//cin >> d;

		//if (d < 1 || d >= vv.size()) {
		//	cout << "Wrong type ___ Back to menu";
		//	return;
		//}
		//p.setPos(d);

		//listofProduct.push_back(p);
		//cout << "\nAdding Product Succesfully\n";
	}

	void Product::editProduct() {

	}

	void Product::deleteProduct() {

	}

	void Product::showProduct() {
		//if (!listofProduct.size()) {
		//	cout << "\n Have no Product !! \n";
		//	return;
		//}

		//for (int i = 0; i < listofProduct.size(); i++) {
		//	cout << "\nProduct " <<i <<endl;
		//	cout << "Weight : " << listofProduct[i].getWeight() << endl;
		//	cout << "Value : " << listofProduct[i].getValue() << endl;
		//	cout << "Destination : " << listofProduct[i].getPos() << endl;
		//}
	}
