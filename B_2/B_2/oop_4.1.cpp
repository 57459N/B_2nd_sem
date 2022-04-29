
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Items.hpp"

using namespace std;


int oop41() {

	Drive flash(1000, "Me", 1999);
	flash.Print();

	cout << endl;

	SSD ssd(1000, "Me to", 2010, 0, 0);
	ssd.Print();

	cout << endl;

	Monitor mon(1080, 1920, 24, 60, 2015);
	mon.Print();

	cout << endl;

	CPU cpu("Core i20", 100, 20, 2100);
	cpu.Print();


	system("pause");
	return 0;
}