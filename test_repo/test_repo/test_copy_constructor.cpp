#include "test_copy_constructor.h"

void testCopyConstr()
{
	std::cout << "\ntestCopyConstructor" << std::endl;
	testCopyConstructor<my_Item> obj;
	obj = generateItem<my_Item>(); //call operator = (call constructor for my_Item), copy and call destructor for my_Item
	//call destructor for obj my_Item
}


