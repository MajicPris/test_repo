#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int i = 1;
unsigned long int result;
unsigned long int factorial(unsigned long int f) {
	if (f == 1 || f == 0)
		return 1;
	cout << "step " << i<<endl;
	i++;
	result = f*factorial(f - 1);
	return result;
}

int main() {
	int x;
	cout << "Enter number: " << endl;
	cin >> x;
	cout << x << "!= " << factorial(x) << endl;

	system("pause");
	return 0;
}