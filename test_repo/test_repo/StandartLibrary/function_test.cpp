#include "test_containers_if.h"
#include <functional>
#include<vector>

void Foo()
{
	cout << "Foo function" << endl;
}

void Bar()
{
	cout << "Bar function" << endl;
}

int SumF(int a, int b)
{
	return a + b;
}

/*----------------------------------------------------------------*/
void Foo1(int a)
{
	if (a > 10 && a < 40)
	{
		cout << a << endl;
	}
}

void Bar1(int a)
{
	if (a % 2 == 0)
	{
		cout << a << endl;
	}
}

void DoWork(vector<int> &a_vec, function<void(int)> a_func)
{
	cout << "\n===============DoWork===============" << endl;
	for (const auto& it : a_vec)
	{
		a_func(it);
	}
}

/*----------------------------------------------------------------*/
void DoWork1(vector<int>& a_vec, vector<function<void(int)>> a_funcVec)
{
	cout << "\n===============DoWork1===============" << endl;
	for (const auto& it : a_vec)
	{
		for (const auto& it2 : a_funcVec)
		{
			it2(it);
		}
	}
}

void testStdFunction()
{
	cout << "\n===============testStdFunction===============" << endl;

	function<void()> my_func;
	my_func = Foo;
	my_func();


	function<int(int, int)> pFunc;
	pFunc = SumF;
	cout << "sum=" << pFunc(1,5) << endl;

	/*----------------------------------------------------------------*/
	vector<int> v1 {1, 4, 10, 13, 12, 17, 24, 71};
	DoWork(v1, Foo1);
	DoWork(v1, Bar1);

	/*----------------------------------------------------------------*/
	vector<int> v2{ 1, 4, 10, 13, 12, 17, 24, 71 };
	vector<function<void(int)>> fV;
	fV.push_back(Foo1);
	fV.push_back(Bar1);
	DoWork1(v1, fV);
}