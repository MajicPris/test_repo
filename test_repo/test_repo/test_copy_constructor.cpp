#include "test_copy_constructor.h"

testCopyConstructor<my_Item> generateItem1()
{
	testCopyConstructor<my_Item> item(new my_Item); //call constructor
	return item; //call copy constructor (create new temp object) and destructor for item
}

void testCopyConstr()
{
	std::cout << "\ntestCopyConstructor" << std::endl;
	testCopyConstructor<my_Item> obj;
	obj = generateItem1(); //call operator = (call constructor for my_Item), copy and call destructor for my_Item
	//call destructor for obj my_Item
}
