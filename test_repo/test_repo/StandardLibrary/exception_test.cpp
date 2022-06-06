#include "test_containers_if.h"
#include <fstream>



void testException()
{
	cout << "\n===============testException===============" << endl;

	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);

	string path = "myFile.txt";
	//string path2 = "set_test.cpp";

	try
	{
		cout << "Try to open file" << endl;

		fin.open(path);

		cout << "File is opened" << endl;
	}
	/*catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		cout << "base exception generated" << endl;
	}*/
	catch (const ifstream::failure& ex) //ifstream::failure is inhiriated from base std::exception class
	{
		cout << ex.what() << endl;
		cout << ex.code() << endl;
		cout << "ifstream exception generated" << endl;
	}

}

/*----------------------------------------------------------------*/
void Foo(int a_val)
{
	if (a_val < 0)
	{
		throw "value lower then null";
	}
	if (a_val==0)
	{
		throw exception("value is equal to null");
	}
	cout << " value = " << a_val << endl;
}

void testThrow()
{
	cout << "\n===============testThrow===============" << endl;

	try
	{
		//Foo(-55);
		Foo(0);
	}
	catch (const char* ex) //we generate with throw char* value and should process in exception char* value
	{
		cout << "int value cought = " <<ex  << endl;
	}
	catch (const std::exception &ex)
	{
		cout << "int value cought = " << ex.what() << endl;
	}
	catch (...) //process any exception. Should always be at the end!!!
	{
		cout << "process any exception" << endl;
	}
}

/*----------------------------------------------------------------*/
class myException : public exception
{
public:
	myException(char* msg, int a_data_state) 
	: exception(msg)
	{
		data_state = a_data_state;
	}
	int getDataState() 
	{ 
		return data_state;  
	}
private:
	int data_state;
};

void Foo2(int a_val)
{
	if (a_val < 0)
	{
		throw exception("value lower then null");
	}
	if (a_val == 0)
	{
		throw myException("value is equal to null", a_val);
	}
	cout << " value = " << a_val << endl;
}

void testCustomException()
{
	cout << "\n===============testCustomException===============" << endl;

	try
	{
		Foo2(-2);
	}
	catch (myException& ex)
	{
		cout << ex.what() << endl;
		cout << "int value cought = " << ex.getDataState() << endl;
	}
	catch (const exception& ex)
	{
		cout << "int value cought = " << ex.what() << endl;
	}
}
