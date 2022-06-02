#include "test_containers_if.h"
#include <set>

void testSet()
{
	cout << "\n===============testSet===============" << endl;

	set<int> mySet;

	set<int>::iterator it1 = mySet.begin();

	mySet.insert(5);
	mySet.insert(4);
	mySet.insert(7);
	mySet.insert(3);
	mySet.insert(-1);

	for (auto& it : mySet)
	{
		cout << it << " ";
	}
	cout << endl;

	if (mySet.find(5) != mySet.end())
	{
		cout << "value 5 exists" << endl;
	}
	else
	{
		cout << "value 5 doesn't exists" << endl;
	}


	if (mySet.erase(444))
	{
		cout << "value 444 was removed" << endl;
	}
	else
	{
		cout << "value 444 doesn't exists" << endl;
	}
	
}