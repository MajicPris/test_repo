#include "test_problems_if.h"
#include<vector>
#include<string>
#include<assert.h>

/*
ƒана строка, состо€ща€ из букв 'X', 'Y' и 'O'.

Ќеобходимо найти кратчайшее рассто€ние между буквами 'X' и 'Y', либо вывести 0, если 'X' либо 'Y' отсутствуют.

- дистанци€ между двум€ р€дом сто€щими буквами считаетс€ как 1 (одно межбуквенное рассто€ние)
- дистанци€ может считатьс€ в обе стороны
*/

//assert(FindMinDistance("XY") == 1);
//assert(FindMinDistance("YX") == 1);
//assert(FindMinDistance("OOOXOOYOXO") == 2);
//assert(FindMinDistance("OOOXXOY") == 2);

size_t FindMinDistance(const std::string& s) {
	// Your code here
	char cX = 'X';
	char cY = 'Y';

	//vector<int> position;
	int dist = 0;
	int posX, posY = 0;
	bool flag1 = false;
	bool flag2 = false;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == cX)
		{
			posX = i;
			flag1 = true;
		}
		if (s[i] == cY)
		{
			posY = i;
			flag2 = true;
		}
		if (flag1 && flag2)
		{
			dist = abs(posX - posY);
		}
	}

	return dist;
}