#include "strings_problems_if.h"
#include <unordered_set>

vector<string> res;
vector<string> letters_map = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void recursiveComb(string& a_digits, int a_size, string a_combination);

vector<string> letterCombinations(string digits) 
{
	if (digits.empty())
		return res;

	recursiveComb(digits, 0, "");
	return res;
}

void recursiveComb(string& a_digits, int a_size, string a_combination)
{
	if (a_size == a_digits.size()) // base condition - push when we have recursed for all digits
	{
		res.push_back(a_combination); //add combination to the vector
		return;
	}

	// add and recurse for each character (choosen from current digit-character vector)
	for (const auto& it : letters_map[a_digits[a_size] - '2'])
	{
		recursiveComb(a_digits, a_size + 1, a_combination + it);
	}
	//ad ae af bd be bf cd ce cf
}


void testLetterCombinations()
{
	cout << "\n===============testLetterCombinations===============" << endl;


	letterCombinations("23");

	for (const auto& it : res)
	{
		cout << it << " ";
	}
	cout << endl;
}