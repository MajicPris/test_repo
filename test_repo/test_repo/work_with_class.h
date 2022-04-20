/*
 * work_with_class.h
 *
 *  Created on: Apr 6, 2022
 *      Author: SEkoSh
 */

#ifndef WORK_WITH_CLASS_H_
#define WORK_WITH_CLASS_H_
#include <iostream>


class Date
{
private:
	int m_Year, m_Month, m_Day;
	static bool m_sIsGregorian;
	bool m_isType;
public:
	Date() : m_Year(0),m_Month(0),m_Day(0), m_isType(m_sIsGregorian) {}
	static void setType(bool a_isGregorian);
	bool getIsType();
};

void testClassStaticFunc();

class TestConstructor
{
	int m_Value;
public:
	TestConstructor (int a_Value) : m_Value(a_Value) {}
	int getValue();
};

void testClassConstructorFunc();



class BasePrivateInh
{
private:
	int a1;
protected:
	int a2;
public:
	int a3;
};
class ChildPrivateInh : private BasePrivateInh
{
public:
	void testChildPrivateInh();
};

class SecondChildPrivateInh : public ChildPrivateInh
{
public:
	void testSecondChildPrivateInh();
};
void TestPrivateInh();



class BaseProtectedInh
{
private:
	int a1;
protected:
	int a2;
public:
	int a3;
};
class ChildProtectedInh : protected BaseProtectedInh
{
public:
	void testChildProtectedInh();
};

class SecondChildProtectedInh : public ChildProtectedInh
{
public:
	void testSecondChildProtectedInh();
};
void TestProtectedInh();


class BasePublicInh
{
private:
	int a1;
protected:
	int a2;
public:
	int a3;
};
class ChildPublicInh : public BaseProtectedInh
{
public:
	void testChildPublicInh();
};

class SecondChildPublicInh : public ChildPublicInh
{
public:
	void testSecondChildPublicInh();
};
void TestPublicInh();



class BaseClass
{
private:
	int a;
	friend void setAVar(BaseClass & obj);
public:
	void printAVar()
	{
		std::cout<<a<<std::endl;
	}
};
void TestFriendFunction();



#endif /* WORK_WITH_CLASS_H_ */
