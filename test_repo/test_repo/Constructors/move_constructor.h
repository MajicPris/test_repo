#include <iostream>


template<typename T>
class moveConstructor
{
private:
	T* m_ptr;

public:
	moveConstructor(T* a_ptr = nullptr) : m_ptr(a_ptr)
	{
	}

	/* copy constructor */
	moveConstructor(const moveConstructor& a_ref)
	{
		m_ptr = new T;
		*m_ptr = *a_ref.m_ptr;
	}

	/* move constructor */
	moveConstructor(moveConstructor&& a_ref)
	{
		m_ptr = a_ref.m_ptr;
		a_ref.m_ptr = nullptr;
	}

	~moveConstructor()
	{
		delete m_ptr;
	}

	/* copy operator */
	moveConstructor& operator=(const moveConstructor& a_ref)
	{
		if (&a_ref == this)
			return *this;

		delete m_ptr;

		m_ptr = new T;
		*m_ptr = *a_ref.m_ptr;

		return *this;
	}

	/* move operator */
	moveConstructor& operator=(moveConstructor&& a_ref)
	{
		if (&a_ref == this)
			return *this;

		delete m_ptr;

		m_ptr = a_ref.m_ptr;
		a_ref.m_ptr = nullptr;

		return *this;
	}
};

class Item
{
public:
	Item()
	{
		std::cout << "Item created" << std::endl;
	}

	~Item()
	{
		std::cout << "Item destroyed" << std::endl;
	}
};

moveConstructor<Item> generateItem2();

void testMoveConstructor();

template<typename T>
void swapFunc(T& x, T& y);

void testSwapFunc();
