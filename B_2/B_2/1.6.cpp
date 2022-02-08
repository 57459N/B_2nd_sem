#include <iostream>
using namespace std;

int strLessOrEqual(char* str1, char* str2) {
    int n1 = 0;
    int n2 = 0;
    while (str1[n1++]);
    while (str1[n2++]);

    for (int i = 0; i < min(n1, n2); i++) {
        if (str1[i] != str2[i])
            return str1[i] <= str2[i];
    }
    return n1 <= n2;
}

template <typename T>
void merge(T* array, int left, int mid, int right) {
    int lSub = mid - left + 1;
    int rSub = right - mid;

    int* lArray = new int[lSub];
    int* rArray = new int[rSub];

    for (int i = 0; i < lSub; i++)
        lArray[i] = array[left + i];
    for (auto j = 0; j < rSub; j++)
        rArray[j] = array[mid + 1 + j];

    int lIndex = 0;
    int rIndex = 0; 
    int mergedIndex = left;

    while (lIndex < lSub && rIndex < rSub) {
        if (lArray[lIndex] <= rArray[rIndex]) {
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
}

void merge(char** array, int left, int mid, int right) {
    int lSub = mid - left + 1;
    int rSub = right - mid;

    char** lArray = new char*[lSub]{};
    char** rArray = new char*[rSub]{};

    for (int i = 0; i < lSub; i++)
        lArray[i] = array[left + i];
    for (auto j = 0; j < rSub; j++)
        rArray[j] = array[mid + 1 + j];

    int lIndex = 0;
    int rIndex = 0;
    int mergedIndex = left;

    while (lIndex < lSub && rIndex < rSub) {
        if (strLessOrEqual(lArray[lIndex], rArray[rIndex])) {
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
}

template <typename T>
void mergeSort(T* array, int begin, int end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
template <typename T>
void printArray(T A, int size) {
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}


int m16() {
    
    int n = 0;
    cout << "Enter size of array: ";
    cin >> n;

    srand(time(nullptr));
    //int* arr = new int[20];
    char** arr = new char*[n];
  
    cin.clear();
    cin.ignore();
    for (int i = 0; i < n; i++) {
        //arr[i] = rand() % 99 + 1;
        arr[i] = new char[1000];
        cin.getline(arr[i], 1000);
    }
    
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << endl;
    printArray(arr, n);

    return 0;
}