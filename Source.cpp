#include <iostream>
#include <Map.h>

using namespace std;

void menu() {
	cout  << "_____________GIAO DIEN CONSOLE___________\n\n";
	cout  <<"     NHOM 1: BAI TOAN NGUOI GIAO HANG    \n";
	cout  <<"_ _ _ _  Xin moi nhap thong tin _ _ _ _ \n";
}

int main() {
	menu();
	Map map;
	map.initMap();
	
}