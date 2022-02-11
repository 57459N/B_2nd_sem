#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Functions.h"


using namespace std;

const int LEN = 1000;
const char separators[] = " .,;:!?-()";

bool isSeparator(char ch) {
	for (int i = 0; i < separators[i]; i++) {
		if (ch == separators[i]) return true;
	}
	return false;
}

int wordsInSentence(char str[]) {
	int len = !isSeparator(str[0]);
	bool prev_sep = isSeparator(str[0]);

	for (int i = 1; str[i]; i++) {
		bool cur_sep = isSeparator(str[i]);
		if(!cur_sep && prev_sep){
			len++;
		}
		prev_sep = cur_sep;
	}	
	return len;
}

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

bool strInArray(char* str, char** arr) {
	for (int i = 0; arr[i]; i++) {
		if (!strcmp(arr[i], str)) {
			return true;
		}
	}
	return false;
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
	
	char** in_both = new char* [min(wordsInSentence(str1), wordsInSentence(str2))]{};

	int s = 0;
	for (int i = 0; words2[i]; i++) {
		if (strInArray(words2[i], words1) && !strInArray(words2[i], in_both)) {
			in_both[s++] = words2[i];
		}
	}
	
	for (int i = 0; in_both[i]; i++) {
		cout << in_both[i] << " ";
	}
	

	return 0;
}