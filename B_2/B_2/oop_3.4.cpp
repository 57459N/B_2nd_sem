#include <iostream>
#include <string>

using namespace std;

string brackets(string str, int st = 0) {

	int open = 0;
	int close = 0;
	string in = "";

	for (int i = st; i < str.size(); i++) {
		if (str[i] == '(') open++;
		if (str[i] == ')') close++;
		if (open != close) {
			in += str[i];
		}
		else {
			in.erase(0,1);
			in.erase(in.size(),1);
			return in;
		}
		
	}	
	return "";
}

int oop34() {

	string a = "(1+1)";

	cout << brackets(a);

	return 0;
}