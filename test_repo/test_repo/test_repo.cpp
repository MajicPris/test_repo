// test_repo.cpp: определяет точку входа для приложения.
//

#include "iostream"

#include "file2.h"
#include "file3.h"
#include "pointer_to_func.h"
#include "work_with_class.h"
#include "work_with_templates.h"


inline int max(int a, int b)
{
	std::cout << "max_func: " << std::endl;
	return a > b ? a : b;
}

namespace Doo
{
	int doOperation(int a, int b)
	{
		return a - b;
	}

}  // namespace Doo


namespace Boo
{
	int doOperation(int a, int b)
	{
		return a + b;
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
	cout << Boo::doOperation(6, 4) << endl;
	cout << Doo::doOperation(6, 4) << endl;
	cout << Foo::doOperation(6, 4) << endl;

	checkPointerToFunc();

	checkPointersLogic();

	checkConstPointers();

	checkConstMembers();

	testClassStaticFunc();

	testClassConstructorFunc();

	TestFriendFunction();

	return 0;
}
