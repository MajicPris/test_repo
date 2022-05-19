#include "test_problems_if.h"
#include<vector>
#include<algorithm>

int searchInsert(vector<int>& a_vec, int a_target)
{
	int lo = 0;
	int hi = a_vec.size() - 1;
	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		if (a_target == a_vec[mid])
		{
			return mid;
		}
		else if (a_target < a_vec[mid])
		{
			hi = mid-1;
		}
		else
		{
			lo = mid+1;
		}
	}
	return lo;
}

void printVec(vector<int>& v1)
{
	for (const auto& it : v1)
	{
		cout << it << " ";
	}
}

void testSearchInsertPosition()
{
	cout << "\n===============testSearchInsertPosition===============" << endl;
	vector<int> v1{ 2,15,6,9,7,32 };
	sort(v1.begin(), v1.end());

	printVec(v1);
	cout << endl;
	cout << "position=" << searchInsert(v1, 7) <<endl;
	cout << "position=" << searchInsert(v1, 5) << endl;
	printVec(v1);
}
