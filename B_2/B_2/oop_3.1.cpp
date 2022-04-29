#include <bitset>
#include <iostream>
#include <string>
#include <sstream>
#include "Functions.h"

using namespace std;

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if (from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

void execute_41() {
    string str = "aaadsdsdaaasdsdaaasd";
    int* count = new int[256]{};


    char max_repeat = 0;
    int repeat_count = 0;

    char prev = '\0';
    int cur_count = 1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == prev) {
            cur_count++;
        }
        else {
            if (repeat_count < cur_count) {
                max_repeat = prev;
                repeat_count = cur_count;
            }
            cur_count = 1;
        }
        prev = str[i];
    }
    if (repeat_count < cur_count) {
        max_repeat = prev;
        repeat_count = cur_count;
    }

    string from = "";
    for (int i = 0; i < repeat_count; i++) {
        from += max_repeat;
    }
    string to = "(" + to_string(repeat_count) + ")";
    cout << "from : " << from << endl;
    cout << "to : " << to << endl;
    replaceAll(str, from, to);
    cout << str;
}



void execute_42() {
    int N = 0;
    cout << "Enter the limit N: " << endl;
    cin >> N;

    for (int num = 0; num < N; num++) {
        if (isPrime(num)) {
            string bstr = bitset<8>(num).to_string();
            bool first = true;
            int n1 = 0;
            double q = 0;
            for (int i = bstr.length() - 1; i >= 0; i--) {
                if (bstr[i] == '1') {
                    if (first) {
                        n1 = bstr.length() - i;
                        q = n1;
                        first = false;
                    }
                    else {
                        q = (static_cast<double>(bstr.length()) - i) / n1;
                        break;
                    }
                }
            }
            //cout << bstr << "  " << q <<  endl;
            bool out = true;
            for (int i = bstr.length() - 1; i >= 0; i--) {
                if (bstr[i] == '1' && i!= bstr.length()-1 && ((bstr.length() - i) / q != int((bstr.length() - i) / q))) {
                    out = false;
                    break;
                }
            }
            if (out) {
                cout << num << " : " << bstr << endl;
            }
        }
    }
}

string replace_word(const string& str, const string& from, const string& to,  const string& separators) {
    string res = str;
    for(int i = 0; i < separators.length(); i++){
        for (int j = 0; j < separators.length(); j++) {
            replaceAll(res, separators[i] + from + separators[j], separators[i] + to + separators[j]);
        }
    }
    return res;
}

void execute_43() {

    const string separators = " .,;:!?-()";
    string str;
    cout << "Enter begin string: " << endl;
    cin >> str;

    string a;
    cout << "Enter substrign A: " << endl;
    cin >> a;

    string b;
    cout << "Enter middle symbol: " << endl;
    cin >> b;

    string a_rev = a;
    reverse(a_rev.begin(), a_rev.end());
    
    string pattern = a + b + a_rev;
    cout << pattern << endl;
    //replacing a + b + rev(a)  -->  b

    cout << replace_word(str, pattern, b, separators);
    

}

int oop31() {
    //execute_41();
    //execute_42();
    //execute_43();

    return 0;
}