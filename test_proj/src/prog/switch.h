#include <iostream>
using namespace std;

int main() {
	double a, b, res;
	char x;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter operand: ";
	cin >> x;

	switch (x) {
	case '+': res = a + b;
		break;
	case '-': res = a - b;
		break;
	case '*': res = a*b;
		break;
	case '/': res = a / b;
		break;
	}
	cout << "Your res: " << res;
	system("pause");
	return 0;
}