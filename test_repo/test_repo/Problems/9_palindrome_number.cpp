#include "test_problems_if.h"
#include<vector>

void testIsPalindrome(int a_var)
{
	cout << "\n===============testIsPalindrome===============" << endl;

	bool isPalindrome = false;
	if (a_var < 0)
	{
		isPalindrome = false;
		cout << "is palindrome = " << isPalindrome << endl;
		return;
	}
	int tmp = a_var;
	int newVar = 0;

	while (tmp!=0)
	{
		newVar = newVar*10 + tmp % 10;
		tmp = tmp / 10;
	}

	isPalindrome = (newVar == a_var) ? true : false;

	cout << "is palindrome = " << isPalindrome << endl;
}

/*----------------------------------------------------------------*/
string isPalindrome(string S)
{
	// Iterate over the range [0, N/2]
	for (int i = 0; i < S.length() / 2; i++) {

		// If S[i] is not equal to
		// the S[N-i-1]
		if (S[i] != S[S.length() - i - 1]) {
			// Return No
			return "No";
		}
	}
	// Return "Yes"
	return "Yes";
}

/*----------------------------------------------------------------*/
bool IsPalindrome(const string& str)
{
	if (str.empty())
		return false;

	int i = 0;                // first characters
	int j = str.length() - 1; // last character

	while (i < j)
	{
		if (str[i] != str[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

void testIsPalindrome_if()
{
	cout << "\n===============testIsPalindrome_if===============" << endl;

	testIsPalindrome(124210);

}