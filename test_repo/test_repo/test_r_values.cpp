#include "test_r_values.h"

void test_r_value::printValues()
{
	std::cout << aVal << " / " << bVal << std::endl;
}


void testRValues()
{
	std::cout << "\ntestRValues" << std::endl;
	test_r_value&& rref = test_r_value(3, 4);
	rref.printValues();
}