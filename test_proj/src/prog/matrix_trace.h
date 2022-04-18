#include <iostream>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<iomanip>
using namespace std;


int main(){
	int rows, column, sum = 0;
	cin >> rows;
	cin >> column;
	int **array = new int* [rows];
	for (int i = 0; i < rows; i++)
		array[i] = new int[column];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < column; j++) {
			array[i][j] = rand() % 100;
			cout  <<array[i][j] << " ";
			
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < column; j++) {
			if (i == j)
				sum += array[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
		delete[]array[i];
	cout << "sum = " << sum << endl;
	system("pause");
	getchar();
	return 0;
}

