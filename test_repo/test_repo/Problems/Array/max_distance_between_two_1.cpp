#include "array_problems_if.h"

/*
1 0 0 0 1 0 1 0 0 1   max dist = 4
1 0 0 1 0 1 0 0 1   max dist = 3
1 0 1 0   max dist = 2

Example:
1 0 0 0 1 0 1 0 0 1
store 1 indexes in res vector
vector<int> res {0, 4, 6, 9}

iterate res array (from 1) and check max distance between res[i]-res[i-1]

*/
int maxDistanceBetweenTwo1(vector<int>& nums)
{
	vector<int> res;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 1)
		{
			res.push_back(i);
		}
	}

	int dist = 0;
	for (int i = 1; i < res.size(); ++i)
	{
		dist = max(dist, res[i] - res[i - 1]);
	}

	return dist;
}

void testMaxDistanceBetweenTwo1()
{
	cout << "\n===============testMaxDistanceBetweenTwo1===============" << endl;

	vector<int> v1{ 1,0,0,0,1,0,1,0,0,1 };
	printArrays(v1);
	cout << "max distance between two 1 = " << maxDistanceBetweenTwo1(v1) << endl;

	vector<int> v2{ 1, 0, 0, 1, 0, 1, 0, 0, 1 };
	printArrays(v2);
	cout << "max distance between two 1 = " << maxDistanceBetweenTwo1(v2) << endl;

	vector<int> v3{ 1, 0, 1, 0 };
	printArrays(v3);
	cout << "max distance between two 1 = " << maxDistanceBetweenTwo1(v3) << endl;
}