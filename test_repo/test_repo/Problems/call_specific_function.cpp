#include "test_problems_if.h"
#include<vector>

void foo1()
{
	cout << "called foo1" << endl;
}

void foo2()
{
	cout << "called foo2" << endl;
}

void fooo1(int a_var)
{
	void (*my_array[2])() = {foo1, foo2};

	my_array[a_var - 1]();
}

void fooo2(void(*a_pVar)())
{
	if (a_pVar)
	{
		a_pVar();
	}
}

void testCallSpecificFunction()
{
	cout << "\n===============testCallSpecificFunction===============" << endl;

	fooo1(1);
	fooo1(2);
	fooo2(foo1);
	fooo2(foo2);
	fooo2(nullptr);
}