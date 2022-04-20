#include <iostream>
#include <cstdlib>
using namespace std;

void play(int m) {
	int x;
	for (int i = 0; i <= 50; i++) {
		cout << "Enter number: " << endl;
		cin >> x;
		if (x == m) {
			cout << "right" << endl;
			return;
		}
		else if (x < m) cout << "less" << endl;
		else cout << "more" << endl;
	}
}
int main() {
	int a, magic;
	magic = rand();
	do{
	cout << "1 - random" << endl;
	cout << "2 - play" << endl;
	cout << "3 - exit" << endl;

	do {
		cin >> a;
	} while (a < 1 || a>3);
		switch (a)
		{
		case 1: magic = rand();
			break;
		case 2: play(magic);
			break;
		case 3: cout << "bye" << endl;
			break;
		}
	} while (a != 3);
	
	system("pause");
	return 0;
}