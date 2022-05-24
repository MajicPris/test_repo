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

void testRemoveElement()
{
	cout << "\n===============testRemoveElement===============" << endl;
	vector<int> v1{ 3,2,5,0,7,4,0,1 };
	printArrays(v1);
	cout << v1.size() << endl;

	removeElement(v1, 0);
	printArrays(v1);
	cout << v1.size() << endl;
}