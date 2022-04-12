#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Student_14 {
public:
    char name[100] = "";
    char surname[100] = "";
    char patronymic[100] = "";

    unsigned short grade = 1;
    float score = -1;

public:
    Student_14() = default;

    Student_14(const char* na, const char* su, const char* pa, const unsigned short& gr, const float& sc) {
        strcpy(this->name, na);
        strcpy(this->surname, su);
        strcpy(this->patronymic, pa);
        this->grade = gr;
        this->score = sc;
    }

    Student_14(const Student_14& st) {
        std::memcpy(this, &st, sizeof(Student_14));
    }

    float get_score() {
        return this->score;
    }

    friend std::ostream& operator<< (std::ostream& str, const Student_14& o);
};

std::ostream& operator<< (std::ostream& str, const Student_14& o) {
    if (o.score >= 0) {
        str << setw(12) << o.surname << setw(11) << o.name << setw(16) << o.patronymic << "  " << o.grade << setw(8) << o.score << endl;
    }
    return str;
}

void load_14(char** arr, const char path[], int len) {
    ifstream file(path);

    if (file.is_open()) {
        for (int i = 0; i < len; i++) {
            arr[i] = new char[100]{};
            file.getline(arr[i], 100);
        };
    }
    file.close();
}

void create_students_14() {
    char file_stud[] = "students_14.txt";
    ofstream out(file_stud);

    setlocale(LC_ALL, "ru");
    srand(time(nullptr));

    int len = 100;

    char** mNames = new char* [len];
    char** mSurnames = new char* [len];
    char** mPatronymics = new char* [len];

    char** fNames = new char* [len];
    char** fSurnames = new char* [len];
    char** fPatronymics = new char* [len];

    load_14(mNames, "male_names.txt", len);
    load_14(mSurnames, "male_surnames.txt", len);
    load_14(mPatronymics, "male_patronymics.txt", len);
    load_14(fNames, "female_names.txt", len);
    load_14(fSurnames, "female_surnames.txt", len);
    load_14(fPatronymics, "female_patronymics.txt", len);

    for (int i = 0; i < len; i++)
    {
        Student_14 student;


        if (rand() % 2) {
            student = Student_14(mNames[rand() % 100], mSurnames[rand() % 100], mPatronymics[rand() % 100], rand() % 3 + 1, (rand() % 100) / 10.0);
        }
        else {
            student = Student_14(fNames[rand() % 100], fSurnames[rand() % 100], fPatronymics[rand() % 100], rand() % 3 + 1, (rand() % 100) / 10.0);
        }
        out << student;
    }
    out.close();

    for (int i = 0; i < len; i++) {
        delete[] mNames[i];
        delete[] mSurnames[i];
        delete[] mPatronymics[i];

        delete[] fNames[i];
        delete[] fSurnames[i];
        delete[] fPatronymics[i];
    }
    delete[] mNames;
    delete[] mSurnames;
    delete[] mPatronymics;

    delete[] fNames;
    delete[] fSurnames;
    delete[] fPatronymics;
}

void read_students_14(Student_14* arr, size_t amount, const char* file_path) {
    ifstream file(file_path);

    if (file.is_open()) {
        int i = 0;
        char* buffer = new char[320]; //max possible size
        while (file && i < amount) {
            file.getline(buffer,320, '\n');
            stringstream line(buffer);
            line >> arr[i].surname;
            line >> arr[i].name;
            line >> arr[i].patronymic;
            line >> arr[i].grade;
            line >> arr[i].score;
            i++;
        }
    }
    else {
        cout << "Error while reading students!" << endl;
    }
}

void write_students_14(Student_14* arr, size_t amount, const char* file_path) {
    ofstream file(file_path);

    if (file) {
        int i = 0;
        while (i < amount) {
            file << arr[i];
            i++;
        }
    }
    else {
        cout << "Error while writing students" << endl;
    }
}

void print_base_14(const char* file_path) {
    ifstream file(file_path);

    char* buffer = new char[320]; //max possible size
    while (file) {
        Student_14 st;
        file.getline(buffer, 320, '\n');
        stringstream line(buffer);
        line >> st.name;
        line >> st.surname;
        line >> st.patronymic;
        line >> st.grade;
        line >> st.score;
        cout << st;
    }
}

float get_avg_14(Student_14* arr, size_t amount) {
    float sum = 0;
    for (int i = 0; i < amount; i++) {
        sum += arr[i].get_score();
    }
    return sum / amount;
}

void execute_14() {
    ofstream out("out_14.txt");

    int st_amount = 100;
    Student_14* St = new Student_14[st_amount];

    read_students_14(St, st_amount, "students_14.txt");
    print_base_14("students_14.txt");

    float avg = get_avg_14(St, st_amount);
    for (int i = 0; i < st_amount; i++) {
        if (St[i].get_score() < avg) {
            out << St[i];
        }
    }
    out.close();
    delete[] St;
}

int oop14() {

    setlocale(LC_ALL, "ru");
    //create_students_14();
    execute_14();

    return 0;
}