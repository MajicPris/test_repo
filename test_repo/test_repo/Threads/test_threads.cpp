#include "test_threads.h"
#include <thread>
#include <chrono>


void DoWork()
{
	for (size_t i = 0; i < 5; ++i)
	{
		cout << "thread ID = " << this_thread::get_id() << "\tDoWork" << endl; //id of current thread
		this_thread::sleep_for(chrono::milliseconds(1000)); //delay for thread
	}
}

void DoWork1(int a, int b)
{
	std::cout << "\n DoWork1 start" << std::endl;
	this_thread::sleep_for(chrono::milliseconds(4000)); //delay for thread
	cout << "a+b=" << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(4000)); //delay for thread
	std::cout << "\n DoWork1 end" << std::endl;

}

void testThreads()
{
	std::cout << "\n testThreads" << std::endl;

	/*cout << "start thread" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000)); //delay for thread

	cout << this_thread::get_id() << endl; //id of current thread

	cout << "end thread" << endl;*/

	thread th1(DoWork);
	thread th2(DoWork);
	thread th3(DoWork1, 4, 6); //start thread with pointer to the function and parameters

	//th1.detach(); //the thread will be closed if the main thread has been finished
	//DoWork();

	for (size_t i = 0; i < 5; ++i)
	{
		cout << "thread ID = " << this_thread::get_id() << "\ttestThreads" << endl; //id of current thread
		this_thread::sleep_for(chrono::milliseconds(500)); //delay for thread
	}

	th1.join(); //waiting for thread end (maybe some data from this thread)
	/*other logic will not be executed till th1 thread end*/
	th2.join();

	th3.join();
}