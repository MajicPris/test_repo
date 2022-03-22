//============================================================================
// Name        : test_proj.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include "file2.h"
#include "file3.h"

//using namespace std;

inline int max(int a, int b)
{
	std::cout << "max_func: " << std::endl;
	return a > b ? a : b;
}

namespace Doo
{
	int doOperation(int a, int b)
	{
		return a-b;
	}

}  // namespace Doo


namespace Boo
{
	int doOperation(int a, int b)
	{
		return a+b;
	}
}  // namespace Boo

int main()
{
	using namespace std;
	namespace Foo = Boo;
	func2();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	global_var++;
	func2();
	cout << max(global_var, 5) << endl;;
	cout << Boo::doOperation(6,4) << endl;
	cout << Doo::doOperation(6,4) << endl;
	cout << Foo::doOperation(6,4) << endl;
	return 0;
}
