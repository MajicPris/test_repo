#include "two_pointer_problems_if.h"

vector <string> v1;
int countSubstrings(string s) 
{
	int count = 0;
	if (s.empty())
		return count;

	int r = 0, l = 0;
	int size = s.size();

	for (int i = 0; i < size; i++)
	{
		r = i + 1;
		l = i - 1;
		count++;
		while (l >= 0 && r < size && s[l] == s[r])
		{
			l--;
			r++;
			count++;
		}
		r = i + 1;
		l = i;
		//for even cases and pairs
		while (l >= 0 && r < size && s[l] == s[r])
		{
			l--;
			r++;
			count++;
		}
	}

	return count;
}

void testCountSubstrings()
{
	cout << "\n===============testCountSubstrings===============" << endl;

}