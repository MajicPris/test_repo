#include <iostream>
using namespace std;

int main() {
	int x, y, temp, kol;
	cout << "Enter x: ";
	cin >> x;
	cout << "\nEnter y: ";
	cin >> y;
	temp = x*x + y*y;
	kol = 0;
	if (temp < 1) kol = 2;
	else if (temp < 4) kol = 1;
	cout << "Your score: " << kol << endl;
	system("pause");
	return 0;
}