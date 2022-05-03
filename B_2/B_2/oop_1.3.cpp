#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    char name[100] = "";
    char surname[100] = "";
    char patronymic[100] = "";
    char sex[10] = "male";

    unsigned short grade = 1;
    float score = -1;

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
        std::memcpy(this, &st, sizeof(Student));
    }

    float get_score() {
        return this->score;
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
            file.getline(arr[i], 100);
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
    out.close();

    for(int i = 0; i< len;i++){
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

void read_students(Student* arr, size_t amount, const char* file_path) {
    ifstream file(file_path, ios::binary);

    if (file.is_open()) {
        int i = 0;
        while (file && i < amount) {
            file.read(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
            i++;
        }
    }
    else {
        cout << "Error while reading students!" << endl;
    }
}

void write_students(Student* arr, size_t amount, const char* file_path) {
    ofstream file(file_path, ios::binary);

    if (file) {
        int i = 0;
        while (i < amount) {
            file.write(reinterpret_cast<char*>(&arr[i]), sizeof(Student));
            i++;
        }
    }
    else {
        cout << "Error while writing students" << endl;
    }
}

void print_base(const char* file_path) {
    ifstream file(file_path, ios::binary);

    while (file) {
        Student st;
        file.read(reinterpret_cast<char*>(&st), sizeof(Student));
        cout << st;
    }
}

float get_avg(Student* arr, size_t amount) {
    float sum = 0;
    for (int i = 0; i < amount; i++) {
        sum += arr[i].get_score();
    }
    return sum / amount;
}

void execute_13() {
    ofstream out("out_13.bin", ios::binary);

    int st_amount = 100;
    Student* St = new Student[st_amount];

    read_students(St, st_amount, "students_13.bin");

    float avg = get_avg(St, st_amount);

    for (int i = 0; i < st_amount; i++) {
        if (St[i].get_score() < avg) {
            out.write(reinterpret_cast<char*>(&St[i]), sizeof(Student));
        }
    }
    out.close();

    print_base("students_13.bin");
    cout << "\n\n\n";
    print_base("out_13.bin");

    delete[] St;
}

int oop13() {

    //create_students();
    execute_13();

    return 0;
}

