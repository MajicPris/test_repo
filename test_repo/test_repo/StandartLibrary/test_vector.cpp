#include "test_containers_if.h"
#include <vector>

void testVector()
{
	cout << "\n===============testVector===============" << endl;

	vector<int> myVector;

	myVector.push_back(22); //added element to the end
	myVector.push_back(143);
	myVector.push_back(15);

	cout << "vector size = " << myVector.size() << endl;

	for (int i = 0; i < myVector.size(); ++i)
	{
		cout << myVector[i] << " ";
	}
	cout << endl;

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
	for (int i = 0; i < myThirdVector.size(); ++i)
	{
		cout << myThirdVector[i] << " "; 
	}
	cout << endl;


}