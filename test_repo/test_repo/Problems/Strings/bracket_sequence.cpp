#include "strings_problems_if.h"
#include <stack>

bool isBracketSequenceCorrect(string a_str)
{
	stack<char> chrArray;

	for (int i = 0; i < a_str.size(); ++i)
	{
		if (chrArray.empty())
		{
			chrArray.push(a_str[i]);
		}
		else if ((chrArray.top() == '(' && a_str[i] == ')') ||
			(chrArray.top() == '[' && a_str[i] == ']') ||
			(chrArray.top() == '{' && a_str[i] == '}'))
		{
			chrArray.pop();
		}
		else
		{
			chrArray.push(a_str[i]);
		}
	}

	return chrArray.empty() ? true : false;
}

void testBracketSequence()
{
	cout << "\n===============testBracketSequence===============" << endl;

	cout << "correct bracket sequence = " << isBracketSequenceCorrect("[[[{{}}]]]") << endl;;
}