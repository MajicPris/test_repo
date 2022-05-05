#include "test_containers_if.h"
#include<map>

void testMap()
{
	std::cout << "\n testMap" << std::endl;

	map<int, string> myMap;

	myMap.emplace(1, "my_phone");
	myMap.insert(make_pair(2, "second"));

	myMap.emplace(4, "third");

	auto it = myMap.find(4); // if element doesn't exists, function will return it.end()

	if (it != myMap.end())
	{
		cout << it->first << " " << it->second << endl;
	}

	myMap[5] = "fourth"; // add element with operator []

	cout << myMap[5] << endl;

	try
	{
		myMap.at(6) = "hello"; //will be checked if element exists
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
		cout << "key doesn't exists" << endl;
	}

	myMap.erase(5); //remove element

	multimap<int, string> myMultiMap;

	myMultiMap.emplace(1, "f1");
	myMultiMap.emplace(1, "f2");

	//how to work with duplicated keys of multimap
	auto it1 = myMultiMap.find(1);

	cout << it1->second << endl;
	it1++;
	cout << it1->second << endl;


	int key = 1;
	auto itr2 = myMultiMap.lower_bound(key);
	auto itr3 = myMultiMap.upper_bound(key);

	while (itr2 != itr3)
	{
		if (itr2->first == key)
			cout << itr2->first << "  "
			<< itr2->second << endl;
		itr2++;
	}


}