//============================================================================
// Name        : test_proj.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include "file2.h"
#include "file3.h"

using namespace std;

int main()
{
	func2();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	global_var++;
	func2();
	return 0;
}
