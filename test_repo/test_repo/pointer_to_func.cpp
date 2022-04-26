/*
 * pointer_to_func.cpp
 *
 *  Created on: Mar 22, 2022
 *      Author: SEkoSh
 */
#include "pointer_to_func.h"


void checkConst::testConstFunction() const
{
	std::cout << "\ntestConstFunction" << std::endl;
	//m_PrivateVar1++; //illegal operation
	std::cout << "m_PrivateVar1: " << m_PrivateVar1 << std::endl;
	m_PrivateVar2++;
	std::cout << "m_PrivateVar2: " << m_PrivateVar2 << std::endl;
}

void checkConst::testNonConstFunction()
{
	std::cout << "\ntestNonConstFunction" << std::endl;
	m_PrivateVar1++;
	std::cout << "m_PrivateVar1: " << m_PrivateVar1 << std::endl;
	m_PrivateVar2++;
	std::cout << "m_PrivateVar2: " << m_PrivateVar2 << std::endl;
}

int add(int a, int b)
{
	return a+b;
}

int subtract(int a, int b)
{
	return a-b;
}

void checkPointerToFunc()
{
	std::cout << "\ncheckPointerToFunc" << std::endl;
	int a = 5;
	int b = 2;
	int (*operation) (int x, int y);
	int result = 0;

	operation = add;
	result = operation(a, b);
	std::cout << "first result: " << result << std::endl;

	operation = subtract;
	result = operation(a, b);
	std::cout << "second result: " << result << std::endl;
}

void checkPointersLogic()
{
	std::cout << "\ncheckPointersLogic" << std::endl;

	int value = 10;
	int tmp_val = 15;

	int *ptr = &value;
	int *tmp_ptr = &tmp_val;
	std::cout << "address: " << ptr << "\tvalue: " << *ptr << std::endl;

	ptr++;
	std::cout << "address: " << ptr << "\tvalue: " << *ptr << std::endl;

	ptr--;
	std::cout << "address: " << ptr << "\tvalue: " << *ptr << std::endl;

	++(*ptr);
	std::cout << "address: " << ptr << "\tvalue: " << *ptr << std::endl;

	(*ptr)++;
	std::cout << "address: " << ptr << "\tvalue: " << *ptr << std::endl;

	int c = ptr - tmp_ptr;
	std::cout << "Subtract: " << c << std::endl;

	int b = *ptr++;
	std::cout << "b value: " << b << std::endl;

	std::cout << "address tmp_var: " << tmp_ptr << "\tvalue tmp_var: " << *tmp_ptr << std::endl;
	int d = *--tmp_ptr;
	std::cout << "d value: " << d << std::endl;
	std::cout << "address tmp_var: " << tmp_ptr << "\tvalue tmp_var: " << *tmp_ptr <<std::endl;
}

const char* returnPointerToConst()
{
	return "returnPointerToConst";
}

void checkConstPointers()
{
	std::cout << "\ncheckConstPointers" << std::endl;
	int a = 10;
	int b = 25;

	const int* ptr_1 = &a;
	std::cout << "address ptr_1: " << ptr_1 << "\tvalue ptr_1: " << *ptr_1 << std::endl;
	//*ptr_1 = 30; //illegal operation
	ptr_1 = &b; //legal operation
	std::cout << "address ptr_1: " << ptr_1 << "\tvalue ptr_1: " << *ptr_1 << std::endl;

	int* const ptr_2 = &b;
	std::cout << "address ptr_2: " << ptr_2 << "\tvalue ptr_2: " << *ptr_2 << std::endl;
	*ptr_2 = 34; //legal operation
	//ptr_2 = &a; //illegal operation
	std::cout << "address ptr_2: " << ptr_2 << "\tvalue ptr_2: " << *ptr_2 << std::endl;

	const int* const ptr_3 = &b;
	std::cout << "address ptr_3: " << ptr_3 << "\tvalue ptr_3: " << *ptr_3 << std::endl;
	//*ptr_3 = 34; //illegal operation
	//ptr_3 = &a; //illegal operation

	std::cout << returnPointerToConst() << std::endl;
	//returnPointerToConst()[0] = 'a'; //illegal operation
}

void checkConstMembers()
{
	std::cout << "\ncheckConstMembers" << std::endl;
	checkConst member1;
	member1.testConstFunction();
	member1.testNonConstFunction();
}
