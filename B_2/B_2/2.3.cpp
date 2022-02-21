#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <ctime>

using namespace std;

template <typename T>
void printArray(T* arr, int size);

struct Student {

	char name[100]{};
	char surname[100]{};
	char patronymic[100]{};

	time_t birthday = 0;
	short grade = 1;
	double  score = 0;
};


struct Node {
public:
	Student student;
	Node* next = nullptr;
};

class List {
private:
	Node* head = nullptr;
	int items_amount;
	double avg_score;

public:
	List() { 
		head = nullptr;
		items_amount = 0;
		avg_score = 0;
	}

	double get_avg() {
		return avg_score;
	}

	void update(Student student) {
		Node* newNode = new Node;

		newNode->student = student;
		newNode->next = nullptr;

		if (head == nullptr) {
			head = newNode;
			avg_score = newNode->student.score;
			items_amount = 1;
		}
		else {
			Node* current = head;
			while (current->next != nullptr && strcmp(current->next->student.surname, student.surname) < 0 ) {
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;
			avg_score = (avg_score * items_amount + student.score) / (items_amount + 1);
			items_amount++;
		}
	}

	void show() {
		Node* current = head;

		cout << "     Surname       Name      Patronymic     Birth    Grade  Score\n\n";
		while (current != nullptr) {
			if (current->student.score > avg_score) {
				char str_date[32]{};
				tm* ptm = localtime(&current->student.birthday);
				strftime(str_date, 32, "%d.%m.%Y", ptm);
				cout << setw(12) <<current->student.surname << setw(11) << current->student.name << setw(16) << current->student.patronymic << "  " << str_date << "    " << current->student.grade << setw(8) << current->student.score << endl;
			}
			current = current->next;
		}
	}
	/*void show() {
		show([](const Student& s) {return true; });
	}*/
};

void load(char** arr, const char path[], int len) {
	ifstream file(path);

	if (file.is_open()) {
		char* line = new char[100];
		int i = 0;
		while (i < len && file.getline(line, 100)) {
			arr[i] = new char[100]{};
			strcpy(arr[i], line);
			//cout << i << " " << arr[i] << endl;
			i++;
		}
		delete[] line;
	}
	file.close();
}

int m23 () {

	List Students_list;
	
	setlocale(LC_ALL, "ru");
	srand(time(nullptr));

	int len = 100;

	char** mNames = new char*[len];
	char** mSurnames = new char*[len];
	char** mPatronymics = new char*[len];
		
	char** fNames = new char*[len];
	char** fSurnames = new char*[len];
	char** fPatronymics = new char*[len];

	load(mNames, "male_names.txt", len);
	load(mSurnames, "male_surnames.txt", len);
	load(mPatronymics,"male_patronymics.txt", len);
	load(fNames, "female_names.txt", len);
	load(fSurnames, "female_surnames.txt", len);
	load(fPatronymics, "female_patronymics.txt", len);

	for (int i = 0; i < len; i++)
	{
		Student student = {};

		if (rand() % 2) {
			strcpy( student.name, mNames[rand() % 100]);
			strcpy(student.surname, mSurnames[rand() % 100]);
			strcpy(student.patronymic, mPatronymics[rand() % 100]);
		}
		else {
			strcpy(student.name, fNames[rand() % 100]);
			strcpy(student.surname, fSurnames[rand() % 100]); 
			strcpy(student.patronymic, fPatronymics[rand() % 100]);
		}


		student.birthday = time(nullptr) - (((rand() << 16) | rand()) % 126144000 + 536112000);
		student.grade = rand() % 3 + 1;
		student.score = (rand() % 100) / 10.0;


		Students_list.update(student);
	}
	Students_list.show();
	//Students_list.show([](const Student& s) {return s.score > Students_list.get_avg(); });
	

	return 0;
}