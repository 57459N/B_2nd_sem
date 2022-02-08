#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Functions.h"


using namespace std;

char** get_words(char str[]){
	const char separators[] = " .,;:!?-()";

	char* new_str = _strdup(str);
	char* word = strtok(new_str, separators);

	char** words = new char* [100]{};
	int s = 0;
	while (word != nullptr) {
		words[s++] = word;
		word = strtok(nullptr, separators);
	}
	
	return words;
}

int m12() {

	const int LEN = 1000;
	const char separators[] = " .,;:!?-()";

	char str[LEN];
	cout << "Enter some string: ";
	cin.getline(str, LEN);

	char** words1 = get_words(str);
	char** words2 = get_words(str);
	
	for (int i = 0; words1[i]; i++) {
		cout << words1[i] << '\n';
	}
	for (int i = 0; words2[i]; i++) {
		cout << words2[i] << '\n';
	}
	return 0;
}