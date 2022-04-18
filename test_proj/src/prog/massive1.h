#include <iostream>
#include <cstdlib>
using namespace std;


int main() {
	int max, min, array[10];	
	for (int i = 0; i < 10; i++) {
		array[i] = rand();
		cout << "array [" << i << "]" << array[i] << endl;
	}
	min = array[0];
	for (int i = 0; i < 10; i++) {
		if (array[i] < min) min = array[i];
	}
	max = array[0];
	for (int i = 0; i < 10; i++) {
		if (array[i] > max) max = array[i];
	}
	cout << "Min: " << min << "Max: " << max << endl;
	system("pause");
	return 0;
}