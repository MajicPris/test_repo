#include "two_pointer_problems_if.h"


/* 
* ( ) - current value
* [ ] - changed value
*								0 0 1 1 1 2 2 3 3 4
* l = 0; r = 0; 0 == 0; 
* l = 0; r = 1; 1 != 0; l++;	0 ([1]) 1 1 1 2 2 3 3 4
* l = 1; r = 2; 1 == 1;
* l = 1; r = 3; 1 == 1;
* l = 1; r = 4; 1 == 1;
* l = 1; r = 5; 2 != 1; l++;	0 1 [2] 1 1 (2) 2 3 3 4
* l = 2; r = 6; 2 == 2;
* l = 2; r = 7; 3 != 1; l++;    0 1 2 [3] 1 2 2 (3) 3 4
* l = 3; r = 8; 3 == 3;
* l = 3; r = 9; 4 != 3; l++;	0 1 2 3 [4] 2 2 3 3 (4)
* 
* resize array with l+1
* 0 1 2 3 4
*/
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
	cout << endl;
}