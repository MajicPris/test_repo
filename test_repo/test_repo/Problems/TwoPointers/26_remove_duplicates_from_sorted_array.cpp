#include "two_pointer_if.h"

int removeDuplicates(vector<int>& nums) 
{
	if (!nums.size())
		return 0;

	int l = 0;

	for (int r = 1; r< nums.size(); r++)
	{
		if (nums[r] != nums[l])
		{
			l++;
			nums[l] = nums[r];
			//nums.erase(nums.begin() + r);
		}

	}
	return l + 1;
}

/*----------------------------------------------------------------*/
void removeDuplicates1(vector<int>& nums)
{
	if (!nums.size())
		return;

	int l = 0;
	int r = 1;

	while (r < nums.size())
	{
		if (nums[r] == nums[l])
		{
			nums.erase(nums.begin() + r);
		}
		else
		{
			r++;
			l++;
		}
	}
}

void testRemoveDuplicates()
{
	cout << "\n===============testRemoveDuplicates===============" << endl;

	vector<int> v1{ 0,0,1,1,1,2,2,3,3,4 };

	cout << "number of non-repeated element = " << removeDuplicates(v1) << endl;

	for (const auto& it : v1)
	{
		cout << it << " ";
	}
	cout << endl;

	/*----------------------------------------------------------------*/
	vector<int> v2{ 0,0,1,1,1,2,2,3,3,4 };
	removeDuplicates1(v2);
	for (const auto& it : v2)
	{
		cout << it << " ";
	}
}