#include <iostream>

using namespace std;

#define BOYS_MIN 150
#define BOYS_MAX 200
#define GIRLS_MIN 150
#define GIRLS_MAX 200

int alg_lab11() {

	int Bamount = 0;
	int Gamount = 0;
	cout << "Enter boys and girls amount: ";
	cin >> Bamount >> Gamount;

	int Blen = BOYS_MAX - BOYS_MIN + 1;
	int Glen = GIRLS_MAX - GIRLS_MIN + 1;
	int* Bheight_all = new int[Blen]{};
	int* Gheight_all = new int[Glen]{};
	int* Bheight = new int[Bamount]{};
	int* Gheight = new int[Gamount]{};

	for (int i = 0; i < Bamount; i++) {
		int h = 0;
		cin >> h;
		Bheight_all[h-BOYS_MIN]++;
	}
	for (int i = 0; i < Gamount; i++) {
		int h = 0;
		cin >> h;
		Gheight_all[h-GIRLS_MIN]++;
	}
		
	for (int i = 0, bh = 0; i < Blen; i++) {
		for (int j = 0; j < Bheight_all[i]; j++) {
			Bheight[bh++] = i + BOYS_MIN;
		}
	}
	for (int i = 0, gh = 0; i < Glen; i++) {
		for (int j = 0; j < Gheight_all[i]; j++) {
			Gheight[gh++] = i + GIRLS_MIN;
		}
	}

	if(Bamount < Gamount) {
		cout << "NO";
		return 0;
	}
	if(Bamount == Gamount && Bheight[0] <= Gheight[0]) {
		cout << "NO";
		return 0;
	}

	int diff = Bamount - Gamount;
	int Bpassed = 0;
	for (int bpos = 0, gpos = 0; bpos < Bamount && gpos < Gamount;) {
		if (Bpassed > diff) {
			cout << "NO";
			return 0;
		}
		if (Bheight[bpos] > Gheight[gpos]) {
			bpos++;
			gpos++;
		}
		else {
			bpos++;
			Bpassed++;
		}
	}

	cout << "YES";

	return 0;
}