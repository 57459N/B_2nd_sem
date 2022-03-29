#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Date {
private:
	int days = 0;
	static const int months[];
	
public:

	Date() = default;
	Date(const char* d) {
		days = str_to_days(d);
	}
	Date(const Date& d) {
		this->days = get_days();
	}

	~Date() {
		
	}

	static bool is_leap(const int& year)  {
		return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
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
		day += days_amount-2;

		char* str = new char[11]{};

		sprintf_s(str, 11, "%i.%i.%i", day, month, year);
		return str;
	}

	int str_to_days(const char* str) {
		stringstream ss(str);
		string D[] = {"","",""};

		for (int i = 0; i < 3; i++) {
			getline(ss, D[i], '.');
		}

		days += stoi(D[0]);
		for (int i = 0; i < stoi(D[1]); i++) {
			days += months[i];
		}
		days += is_leap(stoi(D[2]));

		for (int i = 0; i < stoi(D[2]); i++) {
			days += 365 + is_leap(i);
		}
		return days;
	}

	friend std::ostream& operator<< (std::ostream& str, const Date& date) {
		int days_amount = date.get_days();
		str << Date::days_to_str(days_amount);
		return str;
	}

	int get_days() const{
		return this->days;
	}
};

const int Date::months[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int oop24() {
	Date date = Date("12.2.2004");

	cout << date;

	return 0;
}