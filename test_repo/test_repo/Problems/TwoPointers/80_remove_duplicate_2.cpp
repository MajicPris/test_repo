#include "two_pointer_problems_if.h"


int removeDuplicates2(vector<int>& nums) 
{
	int count = 1;
	int j = 1;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i - 1] == nums[i])
		{
			count++;
		}
		else
		{
			count = 1;
		}
		if (count <= 2)
		{
			nums[j] = nums[i];
			j++;
		}
	}
	return j;
}
/*
0 0 1 1 1 2 2 3 3 4

( ) - current element
[ ] - changed element

i = 1	0 (0) 1 1 1 2 2 3 3 4
i = 2	0 0 (1) 1 1 2 2 3 3 4
i = 3	0 0 1 (1) 1 2 2 3 3 4
i = 4	0 0 1 1 (1) 2 2 3 3 4
i = 5	0 0 1 1 [2] (2) 2 3 3 4
i = 6	0 0 1 1 2 2 (2) 3 3 4
i = 7	0 0 1 1 2 2 [3] (3) 3 4
i = 8	0 0 1 1 2 2 3 3 (3) 4
i = 9	0 0 1 1 2 2 3 3 [4] (4)

You should decrease repeated characters up to 2 and shift next element
*/


void testRemoveDuplicates2()
{
	cout << "\n===============testRemoveDuplicates2===============" << endl;

	vector<int> v1{ 0,0,1,1,1,2,2,3,3,4,4,4 };

	cout << "number of non-repeated element = " << removeDuplicates2(v1) << endl;

	for (const auto& it : v1)
	{
		cout << it << " ";
	}
	cout << endl;
}