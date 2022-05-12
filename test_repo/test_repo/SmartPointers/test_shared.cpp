#include "test_smartPointers_if.h"

void testShared()
{
	std::cout << "\n testShared" << std::endl;
	shared_ptr<int> p1(new int(5));

	shared_ptr<int> p2(p1); //legal operation, copy constructor is available

	shared_ptr<int[]> ptr(new int[5]{ 1, 6, 44, 9 });

	for (int i = 0; i < 5; ++i)
	{
		cout << ptr[i] << endl;
	}

	int* item = new int;
	std::shared_ptr<int> ptr1(item);
	{
		//std::shared_ptr<int> ptr2(item); // illegal operation, ptr2 will destroy item

		std::cout << "Killing one shared pointer\n";
	}
	std::cout << "Killing another shared pointer\n";
	//ptr1 will try to destroy item (there will be an error if ptr2 always destroyed item)
}