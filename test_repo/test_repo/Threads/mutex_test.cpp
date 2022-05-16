#include "test_threads_if.h"
#include <thread>
#include <chrono>
#include <mutex>


mutex mtx;
mutex mtx2;

void PrintChar(char a_var)
{
	unique_lock<mutex> unique(mtx2, std::defer_lock); //create unique object but mtx2.lock() won't be called

	this_thread::sleep_for(chrono::milliseconds(1000));
	{
		unique.lock(); //call mtx2.lock();

		lock_guard<mutex> guard(mtx); //call constructor for guard and mtx.lock();
		//mtx.lock();

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				cout << a_var;
				this_thread::sleep_for(chrono::milliseconds(20));
			}
			cout << endl;
		}
		cout << endl;

		//mtx.unlock();
	} //call destructor for guard and call mtx.unlock();

	unique.unlock(); //call mtx.unlock();

	this_thread::sleep_for(chrono::milliseconds(1000));
}


void testThreadMutex()
{
	std::cout << "\n testThreadMutex" << std::endl;

	thread th1(PrintChar, '*');
	thread th2(PrintChar, '#');

	th1.join();
	th2.join();


}