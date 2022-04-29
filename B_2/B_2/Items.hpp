#include <iostream>

class Item {
	int year = 0;

public:
	Item() = default;
	Item(const int& y) {
		year = y;
	}
	Item(const Item&) = default;
	Item(Item&) = default;
	virtual ~Item() = default;

	virtual void Print(std::ostream& str = std::cout) const {
		str << "Year: " << year << std::endl;
	}

	virtual const char* GetType() {
		return "Item";
	}

	friend std::ostream& operator << (std::ostream& str, const Item& i) {
		i.Print(str);
		return str;
	}
};

class Drive : public Item {
	int volume = 0;
	char* manufacturer = nullptr; //TODO: char*

public:
	Drive() = default;
	Drive(const int& v, const char* p, const int& y) : Item(y) {
		volume = v;
		manufacturer = new char[100];
		strcpy_s(manufacturer, 100, p);
	}
	Drive(const Drive&) = default;
	Drive(Drive&) = default;

	const char* GetType() override {
		return "Drive";
	}

	void Print(std::ostream& str = std::cout) const override {
		Item::Print(str);
		str << "Value: " << volume << " GB" << std::endl
			<< "Producer: " << manufacturer << std::endl;
	}

	~Drive() override {
		delete[] manufacturer;
	};
};

class SSD : public Drive {
	int TBW = 0;
	int smart = 0;

public:
	SSD() = default;
	SSD(const int& v, const char* p, const int& y, const int& tbw, const int& sm) : Drive(v, p, y) {
		TBW = tbw;
		smart = sm;
	}

	SSD(const SSD&) = default;
	SSD(SSD&) = default;

	const char* GetType() override {
		return "SSD";
	}

	void Print(std::ostream& str = std::cout) const override {
		Drive::Print();
		str << "TBW: " << TBW << " Bite" << std::endl
			<< "S.M.A.R.T.: " << smart << " Bite" << std::endl;
	}

	~SSD() override {};
};

class Monitor : public Item {
	float diag = 0;
	int heigth = 0;
	int width = 0;
	float refresh_rate = 0;

public:
	Monitor() = default;
	Monitor(const int& h, const int& w, const float& d, const float& hz, const int& y) : Item(y) {
		diag = d;
		heigth = h;
		width = w;
		refresh_rate = hz;
	}

	Monitor(const Monitor&) = default;
	Monitor(Monitor&) = default;

	const char* GetType() override {
		return "Monitor";
	}

	void Print(std::ostream& str = std::cout) const override {
		Item::Print();
		str << "Diag: " << diag << '"' << std::endl
			<< "Resolution: " << width << "x" << heigth << std::endl
			<< "Display frequancy: " << refresh_rate << " HZ" << std::endl;
	}

	~Monitor() override {};
};

class CPU : public Item {
	char* model = nullptr;
	int cores = 0;
	float frequancy = 0;

public:
	CPU() = default;
	CPU(const char* m, const int& c, const float& f, const int& y) : Item(y) {
		model = new char[100];
		strcpy_s(model, 100, m);
		cores = c;
		frequancy = f;
	}

	CPU(const CPU&) = default;
	CPU(CPU&) = default;

	const char* GetType() override {
		return "CPU";
	}

	void Print(std::ostream& str = std::cout) const override {
		Item::Print();
		str << "Model: " << model << std::endl
			<< "Cores: " << cores << std::endl
			<< "Frequancy: " << frequancy << " GHZ" << std::endl;
	}

	~CPU() override {
		delete[] model;
	};
};