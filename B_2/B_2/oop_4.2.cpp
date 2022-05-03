#include <iostream> 
#include "Items.hpp"
#include "ItemsArray.hpp"
#include "vector.h"

using namespace std;



int oop42() {

	ItemsArray a;

	CPU cpu("Core i20", 100, 20, 2100);
	Monitor mon(1080, 1920, 24, 60, 2015);

	a.push_back(&cpu);
	a.push_back(&mon);

	a.printAll();

	a.printAll();
		


	return 0;
}