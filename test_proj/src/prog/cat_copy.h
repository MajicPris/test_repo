#include <iostream>
#include<cstring>
using namespace std;

char *copy(char *n,   const char *num) {
	char *d = n;
	while (*d++ = *num++)
		;
	return n;
}

char *cat(char *str2, char *str1) {
	char *begin = str2;
	while (*str2) *str2++;
	while (*str2++ = *str1++)
		;
	*str2 = '\0';
	return begin;
}

int main(){
	char str1[] = "hello";
	char str2[10];
	copy(str2, str1);

	cout << str2 << endl;
	cat(str2, "hi");
	cout << str2 << endl;

	system("pause");
	return 0;
}

