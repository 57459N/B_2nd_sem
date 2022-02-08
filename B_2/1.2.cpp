#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Functions.h"


using namespace std;

const int LEN = 1000;
const char separators[] = " .,;:!?-()";


char** get_words(char str[]){

	char* new_str = _strdup(str);
	char* word = strtok(new_str, separators);

	char** words = new char* [LEN/2]{};
	int s = 0;
	while (word != nullptr) {
		words[s++] = word;
		word = strtok(nullptr, separators);
	}
	
	return words;
}

int m12() {


	char str1[LEN];
	cout << "Enter some string 1: ";
	cin.getline(str1, LEN);
	char str2[LEN];
	cout << "Enter some string 2: ";
	cin.getline(str2, LEN);

	char** words1 = get_words(str1);
	char** words2 = get_words(str2);
	
	char** in_both = new char* [LEN / 2]{};
	int s = 0;
	for (int i = 0; words2[i]; i++) {
		for (int j = 0; words1[j]; j++) {
			if (!strcmp(words2[i], words1[j]))  {
				in_both[s++] = words2[i];
				break;
			}
		}
	}

	for (int i = 0; in_both[i]; i++) {
		cout << in_both[i] << " ";
	}

	return 0;
}