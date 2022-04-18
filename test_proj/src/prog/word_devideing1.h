#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;



int main() {
	char str[80];
	char token[80];
	int j;
	cout << "enter text: " << endl;
	gets_s(str);
	for (int i = 0; ; i++) {
		for (j = 0; str[i] != ' '&&str[i]; j++, i++)
		{
			token[j] = str[i];
		}
		token[j] = '\0';
		cout << token << endl;
		if (!str[i]) break;
	}
	system("pause");
	return 0;
}