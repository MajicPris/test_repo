#include <iostream>

class test_r_value
{
	int aVal;
	int bVal;
public:
	test_r_value(int a_aVal, int a_bVal) : aVal(a_aVal), bVal(a_bVal) { }

	void printValues();
};

void testRValues();
