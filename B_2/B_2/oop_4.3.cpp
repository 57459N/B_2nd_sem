#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include "Items.hpp"
#include "ItemsArray.hpp"

struct IFactory {
	virtual Item* createObj(std::istream& stream) { return new Item(); };
};

struct IFactCPU : public IFactory {
	Item* createObj(std::istream& stream) override {
		CPU* result = new CPU();
		stream.read(reinterpret_cast<char*>(&result), sizeof(CPU));
		return result;
	}
};

struct IFactMonitor : public IFactory {
	Item* createObj(std::istream& stream) override {
		Monitor* result = new Monitor();
		stream.read(reinterpret_cast<char*>(&result), sizeof(Monitor));
		return result;
	}
};

struct IFactDrive : public IFactory {
	Item* createObj(std::istream& stream) override {
		Drive* result = new Drive();
		stream.read(reinterpret_cast<char*>(&result), sizeof(Drive));
		return result;
	}
};

struct IFactSSD : public IFactory {
	Item* createObj(std::istream& stream) override {
		SSD* result = new SSD();
		stream.read(reinterpret_cast<char*>(&result), sizeof(SSD));
		return result;
	}
};


class Manager {
private:
	const size_t _type_buffer_size = 8;

	std::unordered_map<std::string, IFactory*> _map;

	void add(std::string type, IFactory* fact) {
		_map.emplace(type, fact);
	}

public:
	Manager() {
		add("CPU", new IFactCPU());
		add("Monitor", new IFactMonitor());
		add("Drive", new IFactDrive());
		add("SSD", new IFactSSD());
	}
	~Manager() {
		for (auto& el : _map) {
			delete el.second;
		}
	}

	Item* createObjBin(std::istream& stream) {
		std::string type;
		stream.read(reinterpret_cast<char*>(&type), _type_buffer_size);
		std::cout << type;
		return _map[type]->createObj(stream);
	}	
};


int oop43() {

	ItemsArray a;

	CPU cpu("Core i20", 100, 20, 2100);
	Monitor* mon = new Monitor(1080, 1920, 24, 60, 2015);



	a.push_back(&cpu);
	a.push_back(mon);



	a.printAll();

	std::ofstream out("oop43_out.bin", std::ios::binary);
	a.saveBin(out);
	out.close();

	ItemsArray b;		
	std::ifstream in("oop43_out.bin", std::ios::binary);

	while (in) {
		Manager m;
		b.push_back(m.createObjBin(in));
	}

	b.printAll();

	return 0;
}