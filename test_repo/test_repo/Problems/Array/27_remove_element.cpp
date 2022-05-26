#include "array_problems_if.h"


int removeElement(vector<int>& nums, int val) 
{
	int l = 0;
	for (int r = 0; r < nums.size(); ++r)
	{
		if (nums[r] != val)
		{
			nums[l] = nums[r];
			l++;
		}
	}
	nums.resize(l);
	return l;
}

void printa(int v)
{
	cout << "int:" << v << endl;
}
void printa(bool v)
{
	cout << "bool:" << v << endl;
}
void printa(string v)
{
	cout << "string:" << v << endl;
}
void testRemoveElement()
{
	cout << "\n===============testRemoveElement===============" << endl;
	vector<int> v1{ 3,2,5,0,7,4,0,1 };
	printArrays(v1);
	cout << v1.size() << endl;

	removeElement(v1, 0);
	printArrays(v1);
	cout << v1.size() << endl;

	cout << endl;
	int a[] = { 1, 2, 3, 4, 5, 6 };
	cout << (1 + 3)[a] - a[0] + (a + 1)[2];

	cout << endl;
	int count = 0;
	/*for (unsigned char i = 0; i < 2 * 150; ++i)
	{
		count++;
	}
	cout << count;

	printa(1);
	printa(true);
	printa("hello world");*/

	/*unsigned int i;
	for (i = 100; i > 0; --i)
	{
		printf("%d\n", i);
	}*/

	/*char a1[] = "123";
	char b[5] = "123";
	const char* c = "123";

	a1[3] = '3';
	b[4] = '3';*/
	//c[2] = '5';
}
