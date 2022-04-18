#include <iostream>
#include<string>
#include<cctype>
#include<cstdlib>
#include<iomanip>
using namespace std;


int main()
{

	char mas[50];
	gets_s(mas);
	char tmp = 0;
	for (int i = 1; i < strnlen_s(mas,50); i++) 
	{
		for (int j = 0; j < strnlen_s(mas, 50)-i; j++)
		{
			if (mas[j] > mas[j+1]) 
			{
				tmp = mas[j];
				mas[j] = mas[j+1];
				mas[j+1] = tmp;
			}
		}
	}
	for (int i = 0; i < strnlen_s(mas, 50); i++) 
	{
		cout << mas[i] ;
	}
	int count = 0;
	for (int i = 1; i < strnlen_s(mas, 50); i++) 
	{
		if (mas[i] == mas[i - 1])
			count++;
	}
	cout << "\n" << count<<endl;

	char array[50];
	gets_s(array);
	int tmp1 = 0;
	
	
	for (int i = 0; i < strnlen_s(mas, 50); i++) 
	{
		for (int j = i + 1; j < strnlen_s(mas, 50); j++)
		{
			if (array[j] < array[i]) 
			{
				tmp1 = array[i];
				array[i] = array[j];
				array[j] = tmp1;
			}
		}
	}
	for (int i = 0; i < strnlen_s(mas, 50); i++) 
		cout << array[i];

	char array1[50];
	gets_s(array1);
	int tmp2 = 0;

	system("pause");
	getchar();
	return 0;
}

