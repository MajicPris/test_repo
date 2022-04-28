#include <iostream>

template <class T>
class testCopyConstructor
{
	T* m_ptr;
public:
	testCopyConstructor(T* a_ptr = nullptr) :m_ptr(a_ptr) { }

	testCopyConstructor(const testCopyConstructor& a_ref);

	~testCopyConstructor();

	testCopyConstructor& operator=(const testCopyConstructor& a_ref);

	T& operator*() const;

	T* operator->() const;
};

template <class T>
testCopyConstructor<T>::testCopyConstructor(const testCopyConstructor& a_ref)
{
	m_ptr = new T;
	*m_ptr = *a_ref.m_ptr;
}

template <class T>
testCopyConstructor<T>::~testCopyConstructor()
{
	delete m_ptr;
}

template <class T>
testCopyConstructor<T>& testCopyConstructor<T>::operator=(const testCopyConstructor& a_ref)
{
	if (&a_ref == this)
		return *this;

	delete m_ptr;

	m_ptr = new T;
	*m_ptr = *a_ref.m_ptr;

	return *this;
}

template <class T>
T& testCopyConstructor<T>::operator*() const
{
	return *m_ptr;
}

template <class T>
T* testCopyConstructor<T>::operator->() const
{
	return m_ptr;
}


class my_Item
{
public:
	my_Item()
	{
		std::cout << "Item created" << std::endl;
	}

	~my_Item()
	{
		std::cout << "Item destroyed" << std::endl;
	}
};

void testCopyConstr();

template <class T>
testCopyConstructor<T> generateItem()
{
	testCopyConstructor<my_Item> item(new my_Item); //call constructor
	return item; //call copy constructor (create new temp object) and destructor for item
}