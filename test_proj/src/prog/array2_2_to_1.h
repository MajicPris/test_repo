#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>

using namespace std;

int main()
{
	int rows, column;
	cout << "enter rows: " << endl;
	cin >> rows;
	cout << "enter column: " << endl;
	cin >> column;
	int arr[20][20];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = rand() % 200 + 1;
			cout <<setw(4)<< arr[i][j] << " "<<setw(4);
		}
		cout << endl;
	}
	int res = rows*column;
	int *mas = new int[res];
	int count = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < column; j++)
		{
			mas[count] = arr[i][j];
			cout << mas[count] << " ";
			count++;
		}
	}
	delete[] mas;

	return 0;
}