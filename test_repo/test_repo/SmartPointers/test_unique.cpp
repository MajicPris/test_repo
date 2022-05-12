#include "test_smartPointers_if.h"

void testUnique()
{
	std::cout << "\n testUnique" << std::endl;
	unique_ptr<int> p1(new int(5));

	//unique_ptr<int> p2(p1);  //illegal operation not allowed to copy unique ptr

	unique_ptr<int> p2;
	p2 = move(p1);
	
	//another way to move unique_ptr
	p2.swap(p1);

	int *p = p1.get(); //return simple pointer;
	cout << *p << endl;

	int* p_p2 = new int(13);
	unique_ptr<int> p3(p_p2);
	p3.reset(); //p_p2 data will be removed and p3 will be empty
	cout << *p_p2 << endl;

	int* p_p3 = new int(45);
	unique_ptr<int> p4(p_p3);
	p4.release();//p_p3 data is still alive and p4 will be empty
	cout << *p_p3 << endl;

}