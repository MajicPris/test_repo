#include"test_threads_if.h"
#include<mutex>
#include<array>
#include<vector>

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

/*----------------------------------------------------------------*/
std::mutex m;
std::array<int, 1000> accounts;

void transfer(size_t to, size_t from, int amount) {
	m.lock();
	if (accounts[from] < amount) {
		m.unlock();
		throw std::runtime_error("insufficient funds");
	}
	accounts[from] -= amount;
	accounts[to] += amount;
	m.unlock();
}

/*----------------------------------------------------------------*/
//DeadLock
struct account {
	std::mutex m;
	int32_t balance;
};

std::array<account, 1000> accounts1;

void transfer1(size_t to, size_t from, int amount) {
	std::lock_guard<std::mutex> lg_from(accounts1[from].m);
	std::lock_guard<std::mutex> lg_to(accounts1[to].m);
	if (accounts1[from].balance < amount) {
		throw std::runtime_error("insufficient funds");
	}
	accounts1[from].balance -= amount;
	accounts1[to].balance += amount;
}




void testThreadMutex()
{
	std::cout << "\n testThreadMutex" << std::endl;

	thread th1(PrintChar, '*');
	thread th2(PrintChar, '#');

	th1.join();
	th2.join();
}


/*----------------------------------------------------------------*/
//DEADLOCK
//We need two mutexes to protect two resources from using them by two threads time by time
mutex m1;
mutex m2;

void Print11()
{
	m2.lock();

	cout << "Print11-first resource" << endl;
	this_thread::sleep_for(chrono::milliseconds(20));

	m1.lock();

	/* need to change sequence of mutex call to process deadlock
		m1.lock();

		this_thread::sleep_for(chrono::milliseconds(20));

		m2.lock();
	*/

	cout << "Print11-second resource" << endl;

	m1.unlock();

	m2.unlock();
}

void Print22()
{
	m1.lock();

	cout << "Print22-first resource" << endl;
	this_thread::sleep_for(chrono::milliseconds(20));

	m2.lock();

	cout << "Print22-second resource" << endl;

	m1.unlock();

	m2.unlock();
}

void testDeadLock()
{
	thread t1(Print11);
	thread t2(Print22);

	t1.join();
	t2.join();
}

/*----------------------------------------------------------------*/
vector<int> x;
mutex vMtx;

void thread_func1()
{
	vMtx.lock();
	x.push_back(0);
	vMtx.unlock();
}

void thread_func2()
{
	vMtx.lock();
	x.pop_back();
	vMtx.unlock();
}

void testTwoFuncMute()
{
	thread th1(thread_func1);
	thread th2(thread_func2);

	th1.join();
	th2.join();
}