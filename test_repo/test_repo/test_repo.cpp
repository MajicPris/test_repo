// test_repo.cpp: определяет точку входа для приложения.
//

//#include "iostream"

#include "file2.h"
#include "file3.h"
#include "pointer_to_func.h"
#include "work_with_class.h"
#include "work_with_templates.h"
#include "FirstNRepeatingStream_v3.h"
#include "test_r_values.h"
#include "test_copy_constructor.h"
#include "move_constructor.h"
#include "test_weak_ptr.h"
#include "Problems\1_two_sum.h"
#include "Problems\2_add_two_numbers.h"
#include "Structures\LinkedList.h"
#include "Structures\Stack.h"
#include "Structures\Queue.h"
#include "Structures\BinaryTree.h"

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

	testRValues();

	testCopyConstr();

	testMoveConstructor();

	testSwapFunc();

	testTwoSum();

	testAddTwoNumbers();

	testLinkedListFunc();

	testStack();

	testQueue();

	testBinaryTree();

	return 0;
}
