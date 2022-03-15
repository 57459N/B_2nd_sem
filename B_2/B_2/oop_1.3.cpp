#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

class Student {
private:
	char name[100] = "";
	char surname[100] = "";
	char patronymic[100] = "";
	char sex[10] = "male";

	unsigned short grade = 1;
	float score = 0;

public:
	Student() = default;

	Student(const char* na, const char* su, const char* pa, const char* se, const unsigned short& gr, const float& sc) {
		strcpy(this->name, na);
		strcpy(this->surname, su);
		strcpy(this->patronymic, pa);
		strcpy(this->sex, se);
		this->grade = gr;
		this->score = sc;
	}

	Student(const Student& st) {
		*this = st;
	}
	
	friend std::ostream& operator<< (std::ostream& str, const Student& o);
};

std::ostream& operator<< (std::ostream& str, const Student& o) {
	str << setw(12) << o.surname << setw(11) << o.name << setw(16) << o.patronymic << "  " << o.grade << setw(8) << o.score << endl;
	return str;
}

void load_(char** arr, const char path[], int len) {
	ifstream file(path);

	if (file.is_open()) {
		for (int i = 0; i < len; i++) {
			arr[i] = new char[100]{};
			file >> arr[i];
		};
	}
	file.close();
}

void create_students() {
	char file_stud[] = "students_13.bin";
	ofstream out(file_stud, ios::binary);

	setlocale(LC_ALL, "ru");
	srand(time(nullptr));

	int len = 100;

	char** mNames = new char* [len];
	char** mSurnames = new char* [len];
	char** mPatronymics = new char* [len];

	char** fNames = new char* [len];
	char** fSurnames = new char* [len];
	char** fPatronymics = new char* [len];

	load_(mNames, "male_names.txt", len);
	load_(mSurnames, "male_surnames.txt", len);
	load_(mPatronymics, "male_patronymics.txt", len);
	load_(fNames, "female_names.txt", len);
	load_(fSurnames, "female_surnames.txt", len);
	load_(fPatronymics, "female_patronymics.txt", len);

	for (int i = 0; i < len; i++)
	{
		Student student;

		if (rand() % 2) {
			student = Student(mNames[rand() % 100], mSurnames[rand() % 100], mPatronymics[rand() % 100], "male", rand() % 3 + 1, (rand() % 100) / 10.0);
		}
		else {
			student = Student(fNames[rand() % 100], fSurnames[rand() % 100], fPatronymics[rand() % 100], "female", rand() % 3 + 1, (rand() % 100) / 10.0);
		}
		out.write(reinterpret_cast<char*>(&student), sizeof(Student));
	}
}



int oop13() {

	create_students();

	return 0;
}