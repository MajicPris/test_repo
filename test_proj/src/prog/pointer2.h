#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;



int main() {
	int x;
	
	
	int *i, j[10];
	cout << i <<" " << &i << endl << endl;

	for(x=0;x<10;x++)
		cout << &j[x] << endl;
	double *f, g[10];
	cout << f << " " << &f << endl << endl;

	for (x = 0; x<10; x++)
		cout << &g[x] << endl;
	cout << &g << endl;

	i = j;
	cout << i << " " << *i << " " << &i << endl;
	f = g;
	cout << f << " " << *f << " " << &f << endl;
	for (x = 0; x < 10; x++) {
		cout << i + x << " " << f + x << endl;
	}

	system("pause");
	return 0;
}