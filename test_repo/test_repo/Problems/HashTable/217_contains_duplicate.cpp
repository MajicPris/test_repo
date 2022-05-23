#include "hash_table_problems_if.h"


bool containsDuplicate(vector<int>& nums)
{
	unordered_map<int, int> resMap;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (resMap.find(nums[i]) == resMap.end())
		{
			resMap[nums[i]]++;
		}
		else
		{
			return true;
		}
	}
	return false;
}

void testContainsDuplicate()
{
	cout << "\n===============testContainsDuplicate===============" << endl;
	vector<int> v1{ 1,2,3,1 };
	vector<int> v2{ 1,2,3,4 };
	vector<int> v3{ 1,1,1,3,3,4,3,2,4,2 };

	cout << "array contains value appears at least twice " << containsDuplicate(v1) << endl;
	cout << "array contains value appears at least twice " << containsDuplicate(v2) << endl;
	cout << "array contains value appears at least twice " << containsDuplicate(v3) << endl;

}