#include "test_threads.h"
#include <thread>
#include <chrono>


void DoWork(int a)
{
	for (size_t i = 0; i < 5; ++i)
	{
		cout << "thread ID = " << this_thread::get_id() << "\tDoWork" << endl; //id of current thread
		this_thread::sleep_for(chrono::milliseconds(500)); //delay for thread
	}
}

void DoWork1(int &a)
{
	std::cout << "thread ID = " << this_thread::get_id() << "\n DoWork1 start" << std::endl;
	this_thread::sleep_for(chrono::milliseconds(4000)); //delay for thread
	//cout << "a+b=" << a + b << endl;

	a *= 2;

	this_thread::sleep_for(chrono::milliseconds(4000)); //delay for thread
	std::cout << "thread ID = " << this_thread::get_id() << "\n DoWork1 end" << std::endl;

}

int Sum(int a, int b)
{
	std::cout << "thread ID = " << this_thread::get_id() << "\n Sum start" << std::endl;
	this_thread::sleep_for(chrono::milliseconds(2000)); //delay for thread
	std::cout << "thread ID = " << this_thread::get_id() << "\n Sum end" << std::endl;
	return a+b;
}

void testThreads()
{
	std::cout << "\n testThreads" << std::endl;

	int tmp = 5;

	thread th1(DoWork, 5);

	thread th3(DoWork1, std::ref(tmp)); //start thread with pointer to the function and parameters ref

	int result;
	thread th4([&result]() {result = Sum(2, 5); }); //use lambda to return esult from thread function

	//th1.detach(); //the thread will be closed if the main thread has been finished

	for (size_t i = 0; i < 10; ++i)
	{
		cout << "thread ID = " << this_thread::get_id() << "\ttestThreads" << endl; //id of current thread
		this_thread::sleep_for(chrono::milliseconds(500)); //delay for thread
	}


	th1.join(); //waiting for thread end (maybe some data from this thread)
	/*other logic will not be executed till th1 thread end*/

	th4.join();
	cout << "result=" << result << endl;

	th3.join();
	cout << "tmp=" << tmp << endl;
}

class MyClass
{
public:
	void myClassFunc1()
	{
		std::cout << "thread ID = " << this_thread::get_id() << "\n myClassFunc1 start" << std::endl;
		this_thread::sleep_for(chrono::milliseconds(5000)); //delay for thread
		std::cout << "thread ID = " << this_thread::get_id() << "\n myClassFunc1 end" << std::endl;
	}

	void myClassFunc2(int a)
	{
		std::cout << "thread ID = " << this_thread::get_id() << "\n myClassFunc2 start" << std::endl;
		this_thread::sleep_for(chrono::milliseconds(5000)); //delay for thread
		std::cout << "thread ID = " << this_thread::get_id() << "\n myClassFunc2 end" << std::endl;
	}

	int myClassFunc3(int a, int b)
	{
		std::cout << "thread ID = " << this_thread::get_id() << "\n myClassFunc3 start" << std::endl;
		this_thread::sleep_for(chrono::milliseconds(5000)); //delay for thread
		std::cout << "thread ID = " << this_thread::get_id() << "\n myClassFunc3 end" << std::endl;
		return a + b;
	}
};

void testThreadClass()
{
	std::cout << "\n testThreadClass" << std::endl;


	int result;
	MyClass obj1;

	for (size_t i = 0; i < 10; ++i)
	{
		cout << "thread ID = " << this_thread::get_id() << "\ttestThreadClass" << endl; //id of current thread
		this_thread::sleep_for(chrono::milliseconds(500)); //delay for thread
	}

}