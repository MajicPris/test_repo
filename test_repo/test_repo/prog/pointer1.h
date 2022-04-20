#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;



int main() {
	int balance;
	int *btr;
	int value;
	int *pl;
	cout <<pl<< " "<< &pl << endl;

	int f = 32;
	cout << &f << endl;
	balance = 3200;
	btr = &balance;
	value = *btr;
	cout << value << " " <<&value<<endl;
	pl = &f;
	cout <<*pl<< " "<< pl << endl;
	value = *pl;
	cout << value << " " << &value << endl;

	system("pause");
	return 0;
}