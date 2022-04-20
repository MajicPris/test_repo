/*
 * pointer_to_func.cpp
 *
 *  Created on: Mar 22, 2022
 *      Author: SEkoSh
 */
#include "pointer_to_func.h"


void checkConst::testConstFunction() const
{
	using namespace std;
	cout << "\ntestConstFunction" << endl;
	//m_PrivateVar1++; //illegal operation
	cout << "m_PrivateVar1: " << m_PrivateVar1 << endl;
	m_PrivateVar2++;
	cout << "m_PrivateVar2: " << m_PrivateVar2 << endl;
}

void checkConst::testNonConstFunction()
{
	using namespace std;
	cout << "\ntestNonConstFunction" << endl;
	m_PrivateVar1++;
	cout << "m_PrivateVar1: " << m_PrivateVar1 << endl;
	m_PrivateVar2++;
	cout << "m_PrivateVar2: " << m_PrivateVar2 << endl;
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
	using namespace std;
	cout << "\ncheckPointerToFunc" << endl;
	int a = 5;
	int b = 2;
	int (*operation) (int x, int y);
	int result = 0;

	operation = add;
	result = operation(a, b);
	cout << "first result: " << result << endl;

	operation = subtract;
	result = operation(a, b);
	cout << "second result: " << result << endl;
}

void checkPointersLogic()
{
	using namespace std;
	cout << "\ncheckPointersLogic" << endl;

	int value = 10;
	int tmp_val = 15;

	int *ptr = &value;
	int *tmp_ptr = &tmp_val;
	cout << "address: " << ptr << "\tvalue: " << *ptr <<endl;

	ptr++;
	cout << "address: " << ptr << "\tvalue: " << *ptr <<endl;

	ptr--;
	cout << "address: " << ptr << "\tvalue: " << *ptr <<endl;

	++(*ptr);
	cout << "address: " << ptr << "\tvalue: " << *ptr <<endl;

	(*ptr)++;
	cout << "address: " << ptr << "\tvalue: " << *ptr <<endl;

	int c = ptr - tmp_ptr;
	cout << "Subtract: " << c <<endl;

	int b = *ptr++;
	cout << "b value: " << b <<endl;

	cout << "address tmp_var: " << tmp_ptr << "\tvalue tmp_var: " << *tmp_ptr <<endl;
	int d = *--tmp_ptr;
	cout << "d value: " << d <<endl;
	cout << "address tmp_var: " << tmp_ptr << "\tvalue tmp_var: " << *tmp_ptr <<endl;
}

const char* returnPointerToConst()
{
	return "returnPointerToConst";
}

void checkConstPointers()
{
	using namespace std;
	cout << "\ncheckConstPointers" << endl;
	int a = 10;
	int b = 25;

	const int* ptr_1 = &a;
	cout << "address ptr_1: " << ptr_1 << "\tvalue ptr_1: " << *ptr_1 <<endl;
	//*ptr_1 = 30; //illegal operation
	ptr_1 = &b; //legal operation
	cout << "address ptr_1: " << ptr_1 << "\tvalue ptr_1: " << *ptr_1 <<endl;

	int* const ptr_2 = &b;
	cout << "address ptr_2: " << ptr_2 << "\tvalue ptr_2: " << *ptr_2 <<endl;
	*ptr_2 = 34; //legal operation
	//ptr_2 = &a; //illegal operation
	cout << "address ptr_2: " << ptr_2 << "\tvalue ptr_2: " << *ptr_2 <<endl;

	const int* const ptr_3 = &b;
	cout << "address ptr_3: " << ptr_3 << "\tvalue ptr_3: " << *ptr_3 <<endl;
	//*ptr_3 = 34; //illegal operation
	//ptr_3 = &a; //illegal operation

	cout << returnPointerToConst() << endl;
	//returnPointerToConst()[0] = 'a'; //illegal operation
}

void checkConstMembers()
{
	using namespace std;
	cout << "\ncheckConstMembers" << endl;
	checkConst member1;
	member1.testConstFunction();
	member1.testNonConstFunction();
}
