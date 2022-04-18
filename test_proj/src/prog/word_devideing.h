#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;



int main() {
	char str[80];
	char token[80];
	char *p, *q;
	cout << "Enter text: " << endl;
	gets_s(str);
	p = str;
	cout << p <<" "<<*p<<" "<<&p<<endl;
	while (*p) {
		q = token;
		while (*p != ' ' && *p) {
			*q = *p;
			cout << q << " " << *q << " " << &q << endl;
			q++; p++;
		}
		if (*p) p++;
		*q = '\0';
		cout << "\n"<< token << endl;
	}
	system("pause");
	return 0;
}