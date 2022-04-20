#include <iostream>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<iomanip>
using namespace std;


int main(){
	/*int rows, column, sum = 0;
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
	cout << "sum = " << sum << endl;*/
	int matrix[100][100];
	int column, rows;
	cin >> rows;
	cin >> column;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < column; j++) {
			matrix[i][j] = rand() % 100 + 1;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	int vect[100];
	cout << "Vect" << endl;
	for (int i = 0; i < column; i++)
	{
		vect[i] = rand() % 100 + 1;
		cout << vect[i] << endl;
	}
	int new_vect[100];
	for (int i = 0; i < rows; i++) {
		new_vect[i] = 0;
		for (int j = 0; j < column; j++) {
			new_vect[i] += matrix[i][j] * vect[j];
		}
	}
	cout << "Res" << endl;
	for (int i = 0; i < rows; i++)
		cout << new_vect[i] << endl;
	int max=new_vect[0];
	for (int i = 0; i < rows; i++) {
		if (max < new_vect[i])
			max = new_vect[i];
	}
	cout << "Max: " << max << endl;
	system("pause");
	getchar();
	return 0;
}

