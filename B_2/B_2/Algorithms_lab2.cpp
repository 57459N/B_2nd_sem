#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <utility>


using namespace std;

class MyHashTable {
private:
	vector<vector<pair<string, string>>> arr;
	int _capacity;

	int max_collisions = 10;

	void _init(const int& c) {
		this->_capacity = c;
		arr.resize(_capacity);
		for (int i = 0; i < arr.size(); i++) {
			vector<pair<string, string>> v;
			pair<string, string> p;
			p.first = "0";
			p.second = "0";
			v.push_back(p);
			arr[i] = v;
		}
	}

public:
	
	MyHashTable(const int& c = 100) {
		_init(c);
	}

	int get_hash(const string& number) {
		int sum = 0;
		for (int i = 0; i < number.size(); i++) {
			sum += (number[i] - '0' + 1) * i * (int(M_PI*i) % 10);
		}
		return sum;
	}

	int get_index(const string& number) {
		return get_hash(number) % _capacity;
	}

	void add(const string& number, const string& full_name) {
		int idx = get_index(number);
		pair <string, string> p(number, full_name);

		if (arr[idx][0].first == "0") {
			arr[idx][0] = p;
		}
		else {
			arr[idx].push_back(p);

			if (arr[idx].size() >= max_collisions) {
				rebuild();
			}
		}
	}

	void rebuild() {
		vector<pair<string, string>> temp_v;
		for (int i = 0; i < _capacity; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				temp_v.push_back(arr[i][j]);
			}
		}
		_init(int(_capacity * 1.1));

		for (int i = 0; i < temp_v.size(); i++) {
			add(temp_v[i].first, temp_v[i].second);
		}

	}

	void find(const string& number) {
		int idx = get_index(number);
		
		for (int i = 0; i < arr[idx].size(); i++) {
			if (arr[idx][i].first == numb er) {
				cout << arr[idx][i].first << "  " << arr[idx][i].second << endl;
				break;
			}
		}
	}

	int capacity(){
		return _capacity;
	}

	void show() {
		for (int i = 0; i < _capacity; i++) {
			for (int j = 0; j < arr[i].size(); j++) {
				cout << arr[i][j].first << "  " << arr[i][j].second << "  |  ";
			}
			cout << endl;
		}
	}
};


int alg_lab_2_5() {

	MyHashTable h;
	
	h.add("375297028766", "97");
	h.add("375293638173", "98");
	h.add("375293997801", "99");
	h.add("375291911450", "100");
	h.add("375292918344", "101");
	h.add("375292068249", "102");
	h.add("375293706121", "103");
	h.add("375295307304", "104");
	h.add("375296424099", "105");
	h.add("375297971717", "106");
	h.add("375296088579", "107");
	h.add("375292265902", "108");
	h.add("375291238918", "109");
	h.add("375296666979", "110");
	h.add("375291758377", "111");
	h.add("375296355242", "112");
	h.add("375293450110", "113");
	h.add("375296537342", "114");
	h.add("375297147305", "115");
	h.add("375297530889", "116");
	h.add("375293929049", "97");
	h.add("375295072965", "98");
	h.add("375293761164", "99");
	h.add("375299605626", "100");
	h.add("375291901937", "101");
	h.add("375291257230", "102");
	h.add("375299838461", "103");
	h.add("375297378245", "104");
	h.add("375292148728", "105");
	h.add("375299770629", "106");
	h.add("375297727465", "107");
	h.add("375291540284", "108");
	h.add("375291850375", "109");
	h.add("375295168226", "110");
	h.add("375296658488", "111");
	h.add("375291809047", "112");
	h.add("375293130139", "113");
	h.add("375291454481", "114");
	h.add("375296996929", "115");
	h.add("375292260004", "116");
	h.add("375296552380", "117");
	h.add("375294018014", "118");
	h.add("375299662842", "119");
	h.add("375296557075", "120");
	h.add("375296841617", "121");
	h.add("375291117623", "122");
	h.add("375298242425", "123");
	h.add("375293808228", "124");
	h.add("375295023589", "125");
	h.add("375296388499", "126");
	h.add("375295498938", "127");
	h.add("375292247568", "128");
	h.add("375291920261", "129");
	h.add("375294473958", "130");
	h.add("375296932220", "131");
	h.add("375294712330", "132");
	h.add("375293420018", "133");
	h.add("375295047389", "134");
	h.add("375294589267", "135");
	h.add("375295898769", "136");
	h.add("375299702724", "97");
	h.add("375292338044", "98");
	h.add("375293060480", "99");
	h.add("375291377267", "100");
	h.add("375295765396", "101");
	h.add("375298476156", "102");
	h.add("375294701354", "103");
	h.add("375292067292", "104");
	h.add("375291593301", "105");
	h.add("375299398998", "106");
	h.add("375291930946", "107");
	h.add("375292761494", "108");
	h.add("375299736843", "109");
	h.add("375294865420", "110");
	h.add("375299358910", "111");
	h.add("375291527612", "112");
	h.add("375293289378", "113");
	h.add("375291611472", "114");
	h.add("375295444344", "115");
	h.add("375293231053", "116");
	h.add("375292647313", "117");
	h.add("375293170956", "118");
	h.add("375295502485", "119");
	h.add("375297013255", "120");
	h.add("375294561502", "121");
	h.add("375291338389", "122");
	h.add("375293780883", "123");
	h.add("375293036584", "124");
	h.add("375295080762", "125");
	h.add("375297389071", "126");
	h.add("375293040888", "127");
	h.add("375295863604", "128");
	h.add("375299276327", "129");
	h.add("375296673064", "130");
	h.add("375291254016", "131");
	h.add("375298181416", "132");
	h.add("375295463525", "133");
	h.add("375294069860", "134");
	h.add("375293862263", "135");
	h.add("375298323709", "136");
	h.add("375291231233", "asdasdasddd");
	h.add("375291231234", "hjkhjkjhhjkh");
	

	h.show();
	cout << endl << h.capacity() << endl;
	h.find("375291231233");

	return 0;
}