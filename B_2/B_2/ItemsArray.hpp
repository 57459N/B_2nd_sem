#pragma once

#include "Items.hpp"
#include "vector.h"

class ItemsArray {
private:
	MyVector<Item*> arr{}; 

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
	//asd
	bool saveBin(std::ostream& stream) {
		for (int i = 0; i < arr.size(); i++) {
			
			stream.write(reinterpret_cast<const char*>(arr[i]->GetType()), 8);
			stream.write(reinterpret_cast<char*>(&arr[i]), sizeof(arr[i]));
		}
		return 0;
	}

	/*void del(const int& idx) {
		arr.erase(idx);
	}*/

	void printAll() {
		for (int i = 0; i < arr.size(); i++) {
			arr[i]->Print();
			std::cout << std::endl;
		}
	}

	size_t size() {
		return arr.size();
	}

	void clear() {
		arr.clear();
	}
};
