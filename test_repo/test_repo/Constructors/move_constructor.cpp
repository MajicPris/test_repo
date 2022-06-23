#include "move_constructor.h"
#include <utility>
#include <string>

moveConstructor<Item> generateItem2()
{
	moveConstructor<Item> item(new Item); //call constructor
	return item; ////call move constructor
}

void testMoveConstructor()
{
	std::cout << "\ntestMoveConstructor" << std::endl;
	moveConstructor<Item> obj;
	obj = generateItem2(); //call move operator
}

template<typename T>
void swapFunc(T& x, T& y)
{
	T tmp{ std::move(x) };
	x = std::move(y);
	y = std::move(tmp);
}

void testSwapFunc()
{
	std::cout << "\ntestSwapFunc" << std::endl;
	std::string a1 = "abc";
	std::string a2 = "erf";
	std::cout << "a1 string = " << a1 << " ,a2 string = " << a2 << std::endl;
	swapFunc<std::string>(a1, a2);
	std::cout << "a1 string = " << a1 << " ,a2 string = " << a2 << std::endl;
}