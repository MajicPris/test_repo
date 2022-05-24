#include "array_problems_if.h"

void removeZeroesFromArray(vector<int>& nums)
{
	auto it = remove(nums.begin(), nums.end(), 0); //sort all zeroes at the end of the array and return iterator to the first 0 value

	nums.erase(it, nums.end()); //remove 0 values from iterator to the end
}

/*----------------------------------------------------------------*/
void removeZeroesFromArray2(vector<int>& nums)
{
	int index = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != 0)
		{
			nums[index] = nums[i];
			index++;
		}
	}
	nums.resize(index);
}

void testRemoveZeroesFromArray()
{
	cout << "\n===============testRemoveZeroesFromArray===============" << endl;

	vector<int> v1{ 3,2,5,0,7,4,0,1 };
	printArrays(v1);
	cout << v1.size() << endl;

	removeZeroesFromArray(v1);
	printArrays(v1);
	cout << v1.size() << endl;

	/*----------------------------------------------------------------*/
	vector<int> v2{ 0,3,0,0,2,5,0,7,4,0,1 };
	printArrays(v2);
	cout << v2.size() << endl;

	removeZeroesFromArray2(v2);
	printArrays(v2);
	cout << v2.size() << endl;
}