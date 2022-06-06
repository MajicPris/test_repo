#include "test_containers_if.h"
#include<vector>

void testForEach()
{
	cout << "\n===============testForEach===============" << endl;

	vector<int> v1{ 1,3,2,8,3,4 };

	for (auto it : v1) //work with copy of vector
	{
		it = -1;
		cout << it << " ";
	}

	cout << endl;

	for (auto &it : v1) //work directly with vector
	{
		it = -1;
		cout << it << " ";
	}

	cout << endl;

	for (const auto& it : v1) //work directly with vector, not possible to change values
	{
		//it = -1; //illegal operation
		cout << it << " ";
	}

	cout << endl;
}