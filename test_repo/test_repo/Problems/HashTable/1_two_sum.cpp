#include "hash_table_problems_if.h"

vector<int> twoSum(std::vector<int>& nums, int target)
{
	std::vector<int> resultV;
	std::unordered_map<int, int> tmpMap;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (tmpMap.count(target - nums[i]))
		{
			//pair found, add current value index and tmpMap[target - nums[i] index
			resultV.push_back(tmpMap[target - nums[i]]);
			resultV.push_back(i);
			return resultV;
		}
		else //pair not found, add value and index to the map
		{
			tmpMap[nums[i]] = i;
		}
	}

	return resultV;
}


void testTwoSum()
{
	cout << "\n===============ntestTwoSum===============" << endl;

	std::vector<int> testV = { 2, 7, 11, 15 };
	std::vector<int> outputV = twoSum(testV, 13);
	for (auto i = outputV.begin(); i != outputV.end(); ++i)
	{
		std::cout << *i << ' ';
	}
	std::cout << std::endl;
}