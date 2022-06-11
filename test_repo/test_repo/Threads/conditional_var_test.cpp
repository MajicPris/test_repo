#include"test_threads_if.h"
#include<mutex>
#include<vector>
#include<condition_variable>

vector<int> vData;
mutex mtx1;
condition_variable cond1;

void t_function1()
{
	unique_lock<mutex> lock(mtx1);
	vData.push_back(10);
	cond1.notify_one();
}

void t_function2()
{
	unique_lock<mutex> lock(mtx1);
	cond1.wait(lock, [] {return !vData.empty(); });
	vData.pop_back();
}

void testConditionalVar()
{
	cout << "\n===============testStdFunction===============" << endl;

	thread th1(t_function1);
	thread th2(t_function2);

	th1.join();
	th2.join();

}