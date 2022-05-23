#include "two_pointer_problems_if.h"

vector<int> twoSum2(vector<int>& nums, int target)
{
	std::vector<int> resultV;
	int l = 0, r = nums.size()-1;

	while (l < r)
	{
		if (nums[l] + nums[r] == target)
		{
			resultV.push_back(l);
			resultV.push_back(r);
			return resultV;
		}
		else if ((nums[l] + nums[r]) < target)
		{
			l++;
		}
		else
		{
			r--;
		}
	}

	return resultV;
}

void testTwoSum2()
{
	cout << "\n===============testTwoSum2===============" << endl;

	vector<int> testV = { 2, 7, 11, 15 };
	vector<int> outputV = twoSum2(testV, 22);
	for (const auto& it : outputV)
	{
		cout << it << ' ';
	}
	cout << endl;
}