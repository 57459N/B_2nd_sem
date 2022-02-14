#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include "Functions.h"

using namespace std;

struct Student {

	union {
		char* name = nullptr;
		int value;
	};
	
	char* surname = nullptr;
	char* patronymic = nullptr;

	time_t birthday;
	short grade;
	short score;
};


struct Node {
	Student student;
	Node* next = nullptr;
};

class List {
private:
	Node* head = nullptr;

public:
	List() { head = nullptr; }

	void update(Student student) {
		Node* newNode = new Node;

		newNode->student = student;
		newNode->next = nullptr;

		if (head == nullptr) { head = newNode; }
		else {
			Node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
	}

	void show() {
		Node* current = head;

		cout << "Surname Name Patronymic Birth Grade Score";
		while (current != nullptr) {
			cout << current->student.surname << " " << current->student.name << " " << current->student.patronymic << " " << current->student.birthday << " " << current->student.grade << " " << current->student.score << endl;
			current = current->next;
		}
	}
};



int m22() {

	//List list;
	
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));

	int len = 100;

	char** mNames = new char*[len];
	char** mSurnames = new char*[len];
	char** mPatronymics = new char*[len];
		
	char** fNames = new char*[len];
	char** fSurnames = new char*[len];
	char** fPatronymics = new char*[len];

	Student* students = new Student[len];

	load(mNames, mSurnames, mPatronymics, "male");
	load(fNames, fSurnames, fPatronymics, "female");

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

		cout << time(0);
		
	}

	return 0;
}