#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Date {
private:
	/*
		Days since 1.1.0001
	*/
	int days = 0;
	static constexpr int months[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
public:

	Date() = default;
	Date(const char* d) {
		this->days = str_to_days(d);
	}
	Date(const Date& d) {
		this->days = get_days();
	}

	Date(const int d) {
		this->days = d;
	}
	Date& operator= (const int d) {
		this->days = d;
		return *this;
	}
	Date& operator= (const char* dstr) {
		int d = Date::str_to_days(dstr);
		this->days = d;
		return *this;
	}

	~Date() {
		
	}

	static bool is_leap(const int& year)  {
		return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	}

	static char* days_to_str(int days_amount) {
		int day = 0;
		int month = 0;
		int year = 0;

		while (days_amount >= 365) {
			days_amount -= 365 + is_leap(year);
			year++;
		}
		while (days_amount >= months[month]) {
			days_amount -= months[month];
			month++;
		}
		days_amount += is_leap(year);
		day += days_amount;

		char* str = new char[11]{};

		sprintf_s(str, 11, "%i.%i.%i", day, month, year);
		return str;
	}

	static int str_to_days(const char* str) {
		int d = 0;
		stringstream ss(str);
		string D[] = {"","",""};

		for (int i = 0; i < 3; i++) {
			getline(ss, D[i], '.');
		}

		d += stoi(D[0]);
		for (int i = 0; i < stoi(D[1]); i++) {
			d += months[i];
		}
		d += is_leap(stoi(D[2]));

		for (int i = 0; i < stoi(D[2]); i++) {
			d += 365 + is_leap(i);
		}
		return d;
	}

	int get_days() const {
		return this->days;
	}

	int days_between(const Date& d) {
		return this->days - d.get_days();
	}

	Date& operator- (const int days_amount) {
		this->days -= days_amount;
		return *this;
	}
	
	Date& operator+ (const int days_amount) {
		this->days += days_amount;
		return *this;
	}

	
	friend std::istream& operator>> (std::istream& str, Date& date) {
		char* d = new char[20];
		str.getline(d, 20);
		int day = date.str_to_days(d);
		date.days = day;
		return str;
	}	

	friend std::ostream& operator<< (std::ostream& str, const Date& date) {
		int days_amount = date.get_days();
		str << Date::days_to_str(days_amount);
		return str;
	}	
};



int oop24() {
	char str[] = "4.1.3020";
	Date date1 = str;
	cout << date1 << endl;

	cout << Date::str_to_days(str) << endl;
	Date date2 = Date::str_to_days(str) + 10;
	cout << date2 << endl;

	Date date3;
	stringstream ss(str);
	ss >> date3;
	cout << date3 << endl;

	cout << date2.days_between(date3);
	return 0;
}