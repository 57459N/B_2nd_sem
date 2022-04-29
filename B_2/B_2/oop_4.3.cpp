#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Items.hpp"

class IFactory {
	
};


class Manager {
private:
	Item* _item_ptr = nullptr;
	std::string _type = "";

	const std::unordered_map<std::string, int> types = {
		{"Drive", 0},
		{"SSD", 1},
		{"Monitor", 2},
		{"CPU", 3},
	};

public:
	Manager(Item* item) : _item_ptr(item), _type(item->GetType()) {};
	~Manager() = default;

	Manager& operator = (Item& item) {
		_item_ptr = &item;
		_type = item.GetType();
		return *this;
	}

	void save(const std::string& path) {
		
		std::ofstream out(path, std::ios::binary, std::ios_base::app);

		
		
	}

	void Info() {
		std::cout << _item_ptr->GetType() << " : " << _item_ptr << " : " << _type << std::endl;
	}
};


int oop43() {


	CPU cpu("Core i20", 100, 20, 2100);
	Monitor mon(1080, 1920, 24, 60, 2015);

	Manager m1(&cpu);
	Manager m2(&mon);

	m1.Info();
	m2.Info();

	return 0;
}