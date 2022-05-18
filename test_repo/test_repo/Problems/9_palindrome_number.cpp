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

void testIsPalindrome_if()
{
	cout << "\n===============testIsPalindrome_if===============" << endl;

	testIsPalindrome(124210);

}