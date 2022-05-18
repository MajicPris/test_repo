#include "test_problems_if.h"
#include<vector>

void testMax1Sequence(vector<int> a_array)
{
	cout << "\n===============testMax1Sequence===============" << endl;

	int count = 0;
	int max_elem = 0;

	for (const auto & it : a_array)
	{
		if (it > 0)
		{
			count++;
			if (count > max_elem)
			{
				max_elem++;
			}
		}
		else
		{
			count = 0;
		}
	}

	cout << "max 1 sequence = " << max_elem << endl;
}

void testMax1Sequence_if()
{
	cout << "\n===============testMax1Sequence_if===============" << endl;
	vector<int> v1{ 1,1,0,0,1,1,1,0 };
	vector<int> v2{ 1,1,0,1,1,1,1 };
	vector<int> v3{ 1,1,1,1,1 };
	vector<int> v4{ 0,0,0 };
	vector<int> v5{ 1,0,0,0 };

	testMax1Sequence(v1);
	testMax1Sequence(v2);
	testMax1Sequence(v3);
	testMax1Sequence(v4);
	testMax1Sequence(v5);
}