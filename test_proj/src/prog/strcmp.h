#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

bool password() {
	char pass[80];
	cout << "Enter pass (pass): " << endl;
	gets_s(pass);
	if (strcmp(pass, "pass")) {
		cout << "no" << endl;
		return false;
	}
	return true;
}
int main() {
	if (password()) cout << "Yes" << endl;
	else cout << "nonono" << endl;
	system("pause");
	return 0;
}