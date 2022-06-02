#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;



int main() {
	int t, i;
	char text[10][8];
	for (t = 0; t < 10; t++) {
		cout << t << ": ";
		gets_s(text[t]);
		if (!text[t][0])break;
	}
	for (i = 0; i < t; i++)
		cout << text[i] << endl;
	system("pause");
	return 0;
}