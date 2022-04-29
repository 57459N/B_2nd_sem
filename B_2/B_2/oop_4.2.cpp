#include <iostream> 
#include "Items.hpp"
#include "vector.h"

using namespace std;

class ItemsArray {
private:
	MyVector<Item*> arr{}; //TODO: MyVector<Item*> kekw
	
public:
	ItemsArray() = default;

	ItemsArray(const ItemsArray& other) {
		arr = other.arr;
	}

	ItemsArray(ItemsArray&& other) {
		arr = std::move(other.arr);
	}

	ItemsArray& operator= (const ItemsArray& other) {
		if (this != &other) {
			arr = other.arr;
		}

		return *this;
	}

	ItemsArray& operator = (ItemsArray&& other) {
		if (&other == this) 
			return *this;
		
		arr = other.arr;
		return *this;
	}

	~ItemsArray() = default;
	
	void push_back(Item* el) {
		arr.push_back(el);
	}


	void del(const int& idx) {
		arr.erase(idx);		
	}

	void printAll() {
		for (int i = 0; i < arr.size(); i++) {
			arr[i]->Print();
			cout << endl;
		}
	}

	size_t size() {
		return arr.size();
	}

	void clear() {
		arr.clear();
	}
};


int oop42() {

	ItemsArray a;

	CPU cpu("Core i20", 100, 20, 2100);
	Monitor mon(1080, 1920, 24, 60, 2015);

	a.push_back(&cpu);
	a.push_back(&mon);

	a.printAll();

	a.del(1);
	
	a.printAll();
	
	//cpu.Print();


	return 0;
}