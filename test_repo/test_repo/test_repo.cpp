// test_repo.cpp: определяет точку входа для приложения.
//

//#include "iostream"

#include "file2.h"
#include "file3.h"
#include "pointer_to_func.h"
#include "work_with_class.h"
#include "work_with_templates.h"
#include "FirstNRepeatingStream_v3.h"


inline int maX(int a, int b)
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
	namespace Foo = Boo;
	func2();
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
	global_var++;
	func2();
	std::cout << maX(global_var, 5) << std::endl;;
	std::cout << Boo::doOperation(6, 4) << std::endl;
	std::cout << Doo::doOperation(6, 4) << std::endl;
	std::cout << Foo::doOperation(6, 4) << std::endl;

	checkPointerToFunc();

	checkPointersLogic();

	checkConstPointers();

	checkConstMembers();

	testClassStaticFunc();

	testClassConstructorFunc();

	TestFriendFunction();

	testCharacterInputStream("abbcacfg",1);
	testCharacterInputStream("bcfbfcbccfccbb", 2);
	testCharacterInputStream("aaaacbcabac", 2);

	return 0;
}
