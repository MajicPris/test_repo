#include "strings_problems._if.h"
#include <unordered_set>


int lengthOfLongestSubstring(string s) 
{
	cout << "Default string " << s << " contains longest substring =  ";
	unordered_set<char> testSet;
	int i = 0, j = 0, res = 0;
	int size = s.size();

	while (/*i < size && */ j < size)
	{
		if (testSet.find(s[j]) == testSet.end())
		{
			testSet.insert(s[j]);
			j++;
			res = max(res, j - i);
		}
		else
		{
			testSet.erase(s[i]);
			i++;
		}
	}

	return res;
}

/*----------------------------------------------------------------*/
int lengthOfLongestSubstring1(string s)
{
	int r = 0, l = 0, res = 0;
	int size = s.size();
	vector<int> v1{ 0 };

	while (r < size)
	{
		v1[s[r]]++; //increment the count of the character present in the right pointer

		while (v1[s[r]] > 1) //if the occurence become more than 1 means the char is repeated
		{
			v1[s[l]]--; //reduce the occurence of temp as it might be present ahead also in the string
			l++; //contraction of the present window till the occurence of the 't' char becomes 1
		}
		res = max(res, r - l + 1); //As the index starts from 0 , ans will be (right pointer-left pointer + 1)
		r++; // now will increment the right pointer 
	}

	return res;
}


void testLengthOfLongestSubstring()
{
	cout << "\n===============testLengthOfLongestSubstring===============" << endl;
	cout << lengthOfLongestSubstring("abcabcbb")  << endl;
	cout << lengthOfLongestSubstring("bbbbb") << endl;
	cout << lengthOfLongestSubstring("pwwkewertcc") << endl;
}