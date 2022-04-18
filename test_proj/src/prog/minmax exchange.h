#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;



int main() {
	int min, max, i,temp;
	int array[10];
	for (i=0;i<10;i++)
	{
		array[i] = rand();
		cout << "array[" << i << "]" << array[i]<<endl;
	}
	min = 0;
	max = 0;
	for (i = 0; i < 10; i++) {
		if (array[min] > array[i]) min = i;
		if (array[max] < array[i]) max = i;
	}
	temp = array[min];
	array[min] = array[max];
	array[max] = temp;
	cout << "----------" << endl;
	for (i = 0; i<10; i++)
	{
		cout << "array[" << i << "]" << array[i] << endl;
	}
	system("pause");
	return 0;
}