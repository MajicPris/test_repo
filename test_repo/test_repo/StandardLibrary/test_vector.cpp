#include "test_containers_if.h"
#include <vector>

void print(vector<int>& nums)
{
	for (const auto& it : nums)
	{
		cout << it << " ";
	}
	cout << endl;
}

void testVector()
{
	cout << "\n===============testVector===============" << endl;

	vector<int> myVector;

	myVector.push_back(22); //added element to the end
	myVector.push_back(143);
	myVector.push_back(15);

	cout << "vector size = " << myVector.size() << endl;

	print(myVector);

	try
	{
		cout << myVector.at(10) << endl;
	}
	catch (const out_of_range& ex)
	{
		cout << ex.what() << endl;
	}
	myVector.pop_back();

	vector<int> mySecondVector{ 15, 43, 67, 89 };
	cout << "vector size = " << mySecondVector.size() << endl;
	cout << "vector capacity = " << mySecondVector.capacity() << endl;

	mySecondVector.push_back(71);
	cout << "vector size = " << mySecondVector.size() << endl;
	cout << "vector capacity = " << mySecondVector.capacity() << endl; // added new memory greater then size()

	mySecondVector.reserve(100); //reserve memeory and increase capacity
	cout << "vector size = " << mySecondVector.size() << endl;
	cout << "vector capacity = " << mySecondVector.capacity() << endl;

	mySecondVector.shrink_to_fit(); //decrease capacity so vector size
	cout << "vector size = " << mySecondVector.size() << endl;
	cout << "vector capacity = " << mySecondVector.capacity() << endl;


	vector<int> myThirdVector(5, 13); //created new vector with size 5 and all values are 13
	print(myThirdVector);


	myThirdVector.insert(myThirdVector.begin(), 55);
	print(myThirdVector);


	myThirdVector.insert(myThirdVector.begin()+2, 3, 44);//insert 44 44 44 from index 2
	print(myThirdVector);

	myThirdVector.erase(myThirdVector.begin()); //remove first element
	myThirdVector.erase(myThirdVector.begin()+2, myThirdVector.begin() + 5); //remove elements from 2 to 5
	print(myThirdVector);

}