#include "strings_problems_if.h"

int checkSymbol(char a_var)
{
	switch (a_var)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		break;
	}
	return 0;
}

int romanToInt(string s) {

	int sum = 0;
	cout << "Roman string " << s << " = ";
	if (s.empty())
		return sum;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))
		{
			sum += checkSymbol(s[i + 1]) - 1;
			i++;
		}
		else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
		{
			sum += checkSymbol(s[i + 1]) - 10;
			i++;
		}
		else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
		{
			sum += checkSymbol(s[i + 1]) - 100;
			i++;
		}
		else
		{
			sum += checkSymbol(s[i]);
		}
	}
	return sum;
}

void testRomanToInteger()
{
	cout << "\n===============testRomanToInteger===============" << endl;

	cout << romanToInt("III") << " integer number" << endl;
	cout << romanToInt("LVIII") << " integer number" << endl;
	cout << romanToInt("MCMXCIV") << " integer number" << endl;

}