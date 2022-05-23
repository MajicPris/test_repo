#include "two_pointer_problems_if.h"


vector<int> sortArrayByParity(vector<int>& nums)
{
	int r = nums.size() -1, l = 0;

	while (l < r)
	{
		if (nums[l] % 2 > nums[r] % 2)
		{
			swap(nums[l], nums[r]);
		}

		if (nums[l] % 2 == 0)
			l++;
		if (nums[r] % 2 == 1)
			r--;
	}
	return nums;
}

/*----------------------------------------------------------------*/
vector<int> sortArrayByParity1(vector<int>& A)
{
	int j = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] % 2 == 0)
		{
			swap(A[i], A[j]);
			j++;
		}
	}
	return A;
}

void testSortArrayByParity()
{
	cout << "\n===============testSortArrayByParity===============" << endl;
	vector<int> v1{ 3,2,5,7,4,0,1 };
	sortArrayByParity(v1);

	for (const auto& it : v1)
	{
		cout << it << " ";
	}
	cout << endl;
}