#pragma once
#include "TimeMap.h"
#include <iostream>

using namespace std;


void TimeMap::setHours(int h) {
	this->hours = h;
}

int TimeMap::getHours() {
	return this->hours;
}

void TimeMap::setMinutes(int m) {
	this->minutes = m;
}

int TimeMap::getMinutes() {
	return this->minutes;
}

void TimeMap::setTime() {
mark1: cout << "Nhap thoi gian hien tai (Gio): ";
	try
	{
		int x;
		cin >> x;

		if (x < 1 || x > 24) throw - 1;
		setHours(x);
	}
	catch (int x)
	{
		cout << "Nhap sai cu phap, vui long nhap lai ??? \n";
		goto mark1;
	}

mark2: cout << "Nhap thoi gian hien tai (Phut): ";
	try
	{
		int x;
		cin >> x;

		if (x < 0 || x > 59) throw - 1;
		setMinutes(x);
	}
	catch (int x)
	{
		cout << "Nhap sai cu phap, vui long nhap lai ??? \n";
		goto mark2;
	}
}