#include <iostream>
using namespace std;

template <typename T>
bool el_comp(T a, T b) {
    return a <= b;
}


int el_comp_str(const char* str1, const char* str2) {
    int l1 = strlen(str1);
    int l2 = strlen(str2);

    int n = min(l1, l2);
    for (int i = 0; i < n; i++) {
        if (str1[i] != str2[i])
            return str1[i] <= str2[i];
    }
    return l1 <= l2;
}

template <typename T, typename C>
void merge(T* array, int left, int mid, int right, C comparator) {
    int lSub = mid - left + 1;
    int rSub = right - mid;

    T* lArray = new T[lSub];
    T* rArray = new T[rSub];

    for (int i = 0; i < lSub; i++)
        lArray[i] = array[left + i];
    for (auto j = 0; j < rSub; j++)
        rArray[j] = array[mid + 1 + j];

    int lIndex = 0;
    int rIndex = 0; 
    int mergedIndex = left;

    while (lIndex < lSub && rIndex < rSub) {
        if (comparator(lArray[lIndex], rArray[rIndex])) {
            array[mergedIndex] = lArray[lIndex];
            lIndex++;
        }
        else {
            array[mergedIndex] = rArray[rIndex];
            rIndex++;
        }
        mergedIndex++;
    }
    while (lIndex < lSub) {
        array[mergedIndex] = lArray[lIndex];
        lIndex++;
        mergedIndex++;
    }
    while (rIndex < rSub) {
        array[mergedIndex] = rArray[rIndex];
        rIndex++;
        mergedIndex++;
    }

    delete[] lArray;
    delete[] rArray;
}

template <typename T, typename C>
void mergeSort(T* arr, int begin, int end, C comparator) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid, comparator);
    mergeSort(arr, mid + 1, end, comparator);
    merge(arr, begin, mid, end, comparator);
}

template <typename T>
void mergeSort(T* arr, int begin, int end) {
    return mergeSort(arr, begin, end, el_comp<T>);
}


/*template <typename T>
void mergeSort(T* arr, int begin, int end) {
    mergeSort(arr, begin, end, el_comp);
}
*/


//void merge(char** array, int left, int mid, int right) {
//    int lSub = mid - left + 1;
//    int rSub = right - mid;
//
//    char** lArray = new char*[lSub]{};
//    char** rArray = new char*[rSub]{};
//
//    for (int i = 0; i < lSub; i++)
//        lArray[i] = array[left + i];
//    for (auto j = 0; j < rSub; j++)
//        rArray[j] = array[mid + 1 + j];
//
//    int lIndex = 0;
//    int rIndex = 0;
//    int mergedIndex = left;
//
//    while (lIndex < lSub && rIndex < rSub) {
//        if (strLessOrEqual(lArray[lIndex], rArray[rIndex])) {
//            array[mergedIndex] = lArray[lIndex];
//            lIndex++;
//        }
//        else {
//            array[mergedIndex] = rArray[rIndex];
//            rIndex++;
//        }
//        mergedIndex++;
//    }
//    while (lIndex < lSub) {
//        array[mergedIndex] = lArray[lIndex];
//        lIndex++;
//        mergedIndex++;
//    }
//    while (rIndex < rSub) {
//        array[mergedIndex] = rArray[rIndex];
//        rIndex++;
//        mergedIndex++;
//    }
//    delete[] lArray;
//    delete[] rArray;
//}



template <typename T>
void printArray(T* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void printArray(char* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

template <typename T>
void randArr(T* arr, int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 99 + 1;
    }
}

void randArr(double* arr, int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 9999 + 1) / 100.;
    }
}


void randArr(char* arr, int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        arr[i] = (rand()% 'z' - 'A' + 1) + 'A';
    }
}


void randArr(char** arr, int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        int len = rand() % 5 + 1;
        arr[i] = new char[len + 1];
        for (int j = 0; j < len; j++) {
            arr[i][j] = rand() % ('Z' - 'A' + 1) + 'A';
        }
        arr[i][len] = '\0';
    }
}

template <typename T>
void task(T arr, int n) {
    randArr(arr, n);
    printArray(arr, n);
    mergeSort(arr, 0, n - 1, el_comp<T>);
    cout << endl;
    printArray(arr, n);
}

enum CHOICE {
    DOUBLE = 1,
    CHAR   = 2,
    STR    = 3
};

int m16() {

    int n = 0;
    cout << "Enter size of array: ";
    cin >> n;

    short choice = 0;
    cout << "0 - int (default)" << endl
        << "1 - double" << endl
        << "2 - char" << endl
        << "3 - string" << endl;
    cout << "Choose type of elements: ";
    cin >> choice;


    switch (choice) {
    case(DOUBLE): {
        double* arr = new double[n];
        randArr(arr, n);
        printArray(arr, n);
        mergeSort(arr, 0, n - 1);
        cout << endl;
        printArray(arr, n);
        delete[] arr;
        break;
    }
    case(CHAR): {
        char* arr = new char[n];
        randArr(arr, n);
        printArray(arr, n);
        mergeSort(arr, 0, n - 1);
        cout << endl;
        printArray(arr, n);
        delete[] arr;
        break;
    }
    case(STR): {
        char** arr = new char* [n];
        randArr(arr, n);
        printArray(arr, n);
        mergeSort(arr, 0, n - 1, el_comp_str);
        cout << endl;
        printArray(arr, n);
        delete[] arr;
        break;
    }
    default: {
        int* arr = new int[n];
        randArr(arr, n);
        printArray(arr, n);
        mergeSort(arr, 0, n - 1);
        cout << endl;
        printArray(arr, n);
        delete[] arr;
        break;
    }
    }

    

    return 0;
}