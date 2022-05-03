
#include <iostream>
#include <string>

using namespace std;

int number_left(const string& str, int pos) {
	int result = 0;
	int i = pos - 1;
	int power = 0;
	while (i >= 0 && (str[i] >= '0') && (str[i] <= '9')) {
		result += (str[i--]-'0') * pow(10,power++);
	}
	return result;
}

int number_right(const string& str, int pos) {
	int result = 0;
	int i = pos + 1;
	while (i < str.size() && (str[i] >= '0') && (str[i] <= '9')) {
		result *= 10;
		result += str[i++] - '0';
	}
	return result;
}

string calculate(string str) {
	
	int pos = str.find_first_of("*/");
	while (pos < str.size()) {
		int a = number_left(str, pos);
		int b = number_right(str, pos);
		int c = 0;
		
		switch (str[pos]) {
			case '*':
				c = a * b;
				break;
			case '/':
				c = a / (float)b;
				break;
		}

		int start = str.find_last_of("*/+-", pos-1)+1;
		int end = str.find_first_of("*/+-", pos+1);
		
		if (end == -1)
			end = str.size();

		str.replace(start, end - start, to_string(c));

		pos = str.find_first_of("*/");
	}

	 pos = str.find_first_of("+-");
	while (pos < str.size()) {
		int a = number_left(str, pos);
		int b = number_right(str, pos);
		int c = 0;

		switch (str[pos]) {
		case '+':
			c = a + b;
			break;
		case '-':
			c = a - b;
			break;
		}

		int start = str.find_last_of("*/+-", pos - 1);
		int end = str.find_first_of("*/+-", pos + 1);

		if (start == -1)
			start = 0;
		if (end == -1)
			end = str.size();

		str.replace(start, end - start, to_string(c));

		pos = str.find_first_of("+-");
	}

	return str;
}

string brackets(string str, int start = 0, int end = 0) {

	if (start == end)
		return "";

	start = str.find_first_of("()", start);
	if (start > str.size()) {
		return calculate(str);
	}
	
	int open = 0;
	int close = 0;
	int sub_len = 0;

	for (int i = start; i <= end; i++) {
		if (str[i] == '(') open++;
		if (str[i] == ')') close++;
		if (open == close && open != 0) {
			sub_len = i - start - 1;
			break;
		}
	}

	string sub = str.substr(start+1, sub_len);
	sub = brackets(sub, 0, sub.size() - 1);
	str.replace(start, sub_len + 2, sub);

	return brackets(str, 0, str.size()-1);
}

int oop34() {

	string a = "(2+2)*2*(2+2)+(2*(2+2))";
	cout << brackets(a, 0, a.size()-1);
	//cout << calculate(a);
	
	//cout << brackets(a);

	return 0;
}