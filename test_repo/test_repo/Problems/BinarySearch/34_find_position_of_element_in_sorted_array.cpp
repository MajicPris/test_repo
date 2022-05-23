#include "binary_search_problems_if.h"

int BinarySearch(vector<int> nums, int num, bool a_isFirst);

vector<int> searchRange(vector<int>& nums, int target) 
{
    return { BinarySearch(nums, target,true), BinarySearch(nums, target, false) };
}

int BinarySearch(vector<int> nums, int num, bool a_isFirst) 
{
    int left = 0, right = nums.size() - 1, mid;
    int result = -1;

    while (left <= right) 
    {
        mid = (left + right) / 2;

        if (nums[mid] == num) 
        {
            result = mid;
            (a_isFirst) ? right = mid - 1 : left = mid + 1;
        }
        else if (nums[mid] > num) 
        {
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }
    }

    return result;
}