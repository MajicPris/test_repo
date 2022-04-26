/*
 * work_with_class.cpp
 *
 *  Created on: Apr 6, 2022
 *      Author: SEkoSh
 */
#include "work_with_class.h"

bool Date::m_sIsGregorian = false;

void Date::setType(bool a_isGregorian)
{
	m_sIsGregorian = a_isGregorian;
}

bool Date::getIsType()
{
	return m_isType;
}


void testClassStaticFunc()
{
	std::cout << "\ntestClassStaticFunc" << std::endl;
	Date obj1;
	std::cout << "obj1 getIsType: " << obj1.getIsType() << std::endl;

	Date::setType(true);
	Date obj2;
	std::cout << "obj2 getIsType: " << obj2.getIsType() << std::endl;
	std::cout << "obj1 getIsType: " << obj1.getIsType() << std::endl;
}

int TestConstructor::getValue()
{
	return m_Value;
}
void testClassConstructorFunc()
{
	std::cout << "\ntestClassConstructorFunc" << std::endl;
	//TestConstructor obj1; //illegal operation. There is constructor with  parameters, not possible to call default nondefined constructor
	TestConstructor obj2(2);
	std::cout << "obj1 getValue: " << obj2.getValue() << std::endl;
}



void ChildPrivateInh::testChildPrivateInh()
{
	//a1 = 5; //illegal operation.
	a2 = 10;
	a3 = 15;
}
void SecondChildPrivateInh::testSecondChildPrivateInh()
{
	//a1 = 20; //illegal operation.
	//a2 = 25; //illegal operation.
	//a3 = 30; //illegal operation.
}
void TestPrivateInh()
{
	ChildPrivateInh obj1;
	obj1.testChildPrivateInh();
	//obj1.a1 = 5; //illegal operation.
	//obj1.a2 = 10; //illegal operation.
	//obj1.a3 = 15; //illegal operation.
}



void ChildProtectedInh::testChildProtectedInh()
{
	//a1 = 5; //illegal operation.
	a2 = 10;
	a3 = 15;
}
void SecondChildProtectedInh::testSecondChildProtectedInh()
{
	//a1 = 20; //illegal operation.
	a2 = 25;
	a3 = 30;
}
void TestProtectedInh()
{
	ChildProtectedInh obj1;
	obj1.testChildProtectedInh();
	//obj1.a1 = 5; //illegal operation.
	//obj1.a2 = 10; //illegal operation.
	//obj1.a3 = 15; //illegal operation.
}



void ChildPublicInh::testChildPublicInh()
{
	//a1 = 5; //illegal operation.
	a2 = 10;
	a3 = 15;
}
void SecondChildPublicInh::testSecondChildPublicInh()
{
	//a1 = 20; //illegal operation.
	a2 = 25;
	a3 = 30;
}
void TestPublicInh()
{
	ChildPublicInh obj1;
	obj1.testChildPublicInh();
	//obj1.a1 = 5; //illegal operation.
	//obj1.a2 = 10; //illegal operation.
	obj1.a3 = 15;
}



void setAVar(BaseClass & obj)
{
	obj.a = 10;
}

void TestFriendFunction()
{
	std::cout << "\nTestFriendFunction" << std::endl;
	BaseClass obj1;
	setAVar(obj1);
	obj1.printAVar();
}
