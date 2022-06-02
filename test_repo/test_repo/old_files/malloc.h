#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;



int main() {
	
	int *i;
	int *j;
	i = (int*)malloc(sizeof(int));
	j = (int*)malloc(sizeof(int));
	*i = 10;
	*j = 20;
	cout << *i << " " << *j << endl;
	free(i);
	free(j);
	system("pause");
	return 0;
}