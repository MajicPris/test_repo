#include "test_problems_if.h"
#include<vector>

void testStonesAndJewels(vector<char> a_arrayS, vector<char> a_arrayJ)
{
	cout << "\n===============testStonesAndJewels===============" << endl;
	int count = 0;
	for (auto itJ = a_arrayJ.begin(); itJ != a_arrayJ.end(); itJ++)
	{
		for (const auto& itS : a_arrayS)
		{
			if (itS == *itJ)
			{
				count++;
			}
		}	
	}

	cout << "stones contains in jewels = " << count << endl;

}

void testStonesAndJewels_if()
{
	cout << "\n===============testStonesAndJewels_if===============" << endl;
	vector<char> vS{ 'a', 'b' };
	vector<char> vJ{ 'a','a','b','b','c','c','d' };

	testStonesAndJewels(vS, vJ);
}