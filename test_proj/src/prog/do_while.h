#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int a, magic;
	magic = rand();
	do {
		cout << "Enter a: " << endl;
		cin >> a;
		if (a == magic) {
			cout << "\nYou're right";
		}
		else if (a > magic) cout << "more"<<endl;
		else if (a < magic) cout << "less"<<endl;
	}
		while (a !=magic);

	system("pause");
	return 0;
}